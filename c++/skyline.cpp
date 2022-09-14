#include <bits/stdc++.h>
using namespace std;
class Building
{
public:
    int left;
    int height;
    int right;
};
class Strip
{
public:
    int left;
    int height;
    Strip() : left(0), height(0) {}
    Strip(int l, int h) : left(l), height(h) {}
};
class SkyLine
{
public:
    Strip *stripArr;
    int maxSize;
    int N;
    SkyLine(int maxSize)
    {
        this->maxSize = maxSize;
        this->stripArr = new Strip[this->maxSize];
        this->N = 0;
    }
    int append(const Strip &strip)
    {
        if (N == maxSize)
        {
            return -1;
        }
        else
        {
            if (N > 0 && stripArr[N - 1].height == strip.height)
            {
                return 0;
            }
            if (N > 0 && stripArr[N - 1].left == strip.left)
            {
                return 0;
            }
            stripArr[N++] = strip;
            return 1;
        }
    }
    SkyLine *merge(SkyLine *toMerge)
    {
        SkyLine *merged = new SkyLine(N + toMerge->N);
        int h1 = 0, h2 = 0, l1, l2;
        int i = 0, j = 0;
        while (i < N && j < toMerge->N)
        {
            if (stripArr[i].left < toMerge->stripArr[j].left)
            {
                l1 = stripArr[i].left;
                h1 = stripArr[i].height;
                merged->append(*(new Strip(l1, max(h1, h2))));
                i++;
            }
            else
            {
                l2 = stripArr[i].left;
                h2 = stripArr[i].height;
                merged->append(*(new Strip(l2, max(h1, h2))));
                j++;
            }
        }
        while (i < N)
        {
            merged->append(stripArr[i]);
            i++;
        }
        while (j < toMerge->N)
        {
            merged->append(toMerge->stripArr[j]);
            j++;
        }
        return merged;
    }
    void print()
    {
        for (int i = 0; i < N; i++)
        {
            cout << "(" << stripArr[i].left << "," << stripArr[i].height << "), ";
        }
        cout << endl;
    }
    ~SkyLine()
    {
        delete[] stripArr;
    }
};

SkyLine *findSkyline(Building arr[], int l, int r)
{
    if (l == r)
    {
        SkyLine *skyline = new SkyLine(2);
        skyline->append(*(new Strip(arr[l].left, arr[l].height)));
        skyline->append(*(new Strip(arr[l].right, 0)));
        return skyline;
    }
    else
    {
        int mid = l + (r - l) / 2;
        SkyLine *leftSkyline = findSkyline(arr, l, mid);
        SkyLine *rightSkyline = findSkyline(arr, mid + 1, r);
        SkyLine *mergedSkyline = leftSkyline->merge(rightSkyline);
        delete leftSkyline;
        delete rightSkyline;
        return mergedSkyline;
    }
}
int main()
{
    Building arr[] = {
        {1, 11, 5}, {2, 6, 7}, {3, 13, 9}, {12, 7, 16}, {14, 3, 25}, {19, 18, 22}, {23, 13, 29}, {24, 4, 28}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find skyline for given buildings
    // and print the skyline
    SkyLine *ptr = findSkyline(arr, 0, n - 1);
    cout << " Skyline for given buildings is \n";
    ptr->print();
    return 0;
}