#include <bits/stdc++.h>
using namespace std;

void split(string s)
{
    int len = s.size();
    if (len <= 1)
    {
        cout << "NOT POSSIBLE" << endl;
        return;
    }
    int num1, num2;
    string str1, str2;
    for (int i = 0; i < len / 2; i++)
    {
        cout<<i<<endl;
        str1 = s.substr(0, i + 1);
        num1 = stoi(str1);
        num2 = num1 + 1;
        str2 = to_string(num2);
        if ((s.substr(i + 1, str2.size())).compare(str2) == 0)
        {
            int k = i + 1 + str2.size();
           while (k <= len)
            {
                num2 = num2 + 1;
                str2 = to_string(num2);
                if (k + str2.size() <= len)
                {
                    if ((s.substr(k, str2.size())).compare(str2) == 0)
                    {
                        k+=str2.size();
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
            if(k>=len) {
                cout << "POSSIBLE " <<num1<< endl;
                return;
            }
        }
    }
    cout << "NOT POSSIBLE" << endl;
}
int main()
{
    string s = "121314151617181920";
    split(s);
}