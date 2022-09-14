#include <bits/stdc++.h>
using namespace std;

void printEgyptianFraction(int nr, int dr)
{
    if(nr <= 0 || dr <= 0){
        return;
    }
    if(dr % nr == 0){
        cout<<"1/"<<dr/nr;
        return;
    }
    if(nr>dr){
        cout<<nr/dr<<" + ";
        printEgyptianFraction(nr%dr, dr);
        return;
    }
    int ceiled = ceil(dr/(float)nr);
    cout<<"1/"<<ceiled<<" + ";
    printEgyptianFraction(nr*ceiled - dr, dr*ceiled);
}
int main()
{
    int nr = 6, dr = 14;
    cout << "Egyptian Fraction Representation of "
         << nr << "/" << dr << " is ";
         printEgyptianFraction(nr, dr);
    return 0;
}