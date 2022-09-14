#include <bits/stdc++.h>
using namespace std;

int solution(int N)
{
    
        int temp = abs(N);
        if (N < 0)
        {
            string str = to_string(temp);
            string res;
            bool inserted = false;
            for (int i = 0; i < str.length(); i++)
            {
                if (5 < stoi(str.substr(i, 1)) && !inserted)
                {
                    res += '5';
                    inserted = true;
                }
                res += str[i];
            }
            if (!inserted)
            {
                res += 5;
            }
            return (-1*stoi(res));
        }
        else
        {
            string str = to_string(temp);
            string res;
            bool inserted = false;
            for (int i = 0; i < str.length(); i++)
            {
                if (5 > stoi(str.substr(i, 1)) && !inserted)
                {
                    res += '5';
                    inserted = true;
                }
                res += str[i];
            }
            if (!inserted)
            {
                res += 5;
            }
            cout<<res<<endl;
            return stoi(res);
        }
    
}
int main()
{
    int temp;
    while (true)
    {
        cin >> temp;
        cout << endl;
        cout << solution(temp) << endl;
    }
}