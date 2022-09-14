#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

struct PCF {
    int p, c, f;
};
int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    PCF maxPCF;
    PCF totalPCF;
    string maxStr;
    PCF temp;
    getline(cin, maxStr);
    int j = 0;
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    for (int i = 0; i < maxStr.length(); i++)
    {
        if (maxStr[i]== ' ' || i == maxStr.length()-1) {
            if (!flag1) {
                maxPCF.p = stoi(maxStr.substr(j, i));
                flag1 = true;
            }
            else if (!flag2) {
                maxPCF.c = stoi(maxStr.substr(j, i));
                flag2 = true;
            }
            else {
                maxPCF.f = stoi(maxStr.substr(j, i));
                flag3 = true;
            }
            j = i+1;
        }
    }
    getline(cin, maxStr);
    flag1 = false;
    flag2 = false;
    flag3 = false;
    vector<PCF> givenPCF;

    int p, c, f;
    for (int i = 0; i < maxStr.length(); i++)
    {
        if (maxStr[i]== ' ' || maxStr[i] == '|' || i == maxStr.length()-1) {
            if (!flag1) {
                temp.p = stoi(maxStr.substr(j, i));
                flag1 = true;
            }
            else if (!flag2) {
                temp.c = stoi(maxStr.substr(j, i));
                flag2 = true;
            }
            else {
                temp.f = stoi(maxStr.substr(j, i));
                flag3 = true;
            }
            j = i+1;
        }
        if (maxStr[i] == '|' || i==maxStr.length()-1) {
            givenPCF.push_back(temp);
            flag1 = false;
            flag2 = false;
            flag3 = false;
        }
    }
    
    

    totalPCF.p = 0;
    totalPCF.c = 0;
    totalPCF.f = 0;

    for (int i = 0; i < givenPCF.size(); i++)
    {
        totalPCF.p += givenPCF[i].p;
        totalPCF.c += givenPCF[i].c;
        totalPCF.f += givenPCF[i].f;
    }
    int minAmount = INT_MAX;
    minAmount = min(maxPCF.p / totalPCF.p, minAmount);
    minAmount = min(maxPCF.c / totalPCF.c, minAmount);
    minAmount = min(maxPCF.f / totalPCF.f, minAmount);
    maxPCF.p -= minAmount*totalPCF.p;
    maxPCF.c -= minAmount*totalPCF.c;
    maxPCF.f -= minAmount*totalPCF.f;
    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        int ubP = INT_MIN, ubC = INT_MIN, ubF = INT_MIN, ubPI = -1, ubCI = -1, ubFI = -1;
        for (int i = 0; i < givenPCF.size()-1; i++)
        {
            if (maxPCF.p >= givenPCF[i].p && givenPCF[i].p > ubP) {
                ubP = givenPCF[i].p;
                ubPI = i;
            }
            if (maxPCF.c >= givenPCF[i].c && givenPCF[i].c > ubC) {
                ubC = givenPCF[i].c;
                ubCI = i;
            }
            if (maxPCF.f >= givenPCF[i].f && givenPCF[i].f > ubF) {
                ubF = givenPCF[i].f;
                ubFI = i;
            }
        }

        if (ubPI==-1 && ubFI == -1 && ubCI == -1) {
            break;
        }
        if (ubPI != -1 && maxPCF.p - ubP >=0 && maxPCF.c - givenPCF[ubPI].c>=0 && maxPCF.f - givenPCF[ubPI].f>=0) {
            maxPCF.p -= ubP;
            maxPCF.c -= givenPCF[ubPI].c;
            maxPCF.f -= givenPCF[ubPI].f;
        }
        else {
            flag1 = true;
        }
        if (ubCI != -1 && maxPCF.c - ubC >=0 && maxPCF.p - givenPCF[ubCI].p>=0 && maxPCF.f - givenPCF[ubCI].f>=0) {
            maxPCF.c -= ubC;
            maxPCF.p -= givenPCF[ubCI].p;
            maxPCF.f -= givenPCF[ubCI].f;
        }
        else {
            flag2 = true;
        }
        if (ubFI != -1 &&maxPCF.f - ubF >=0 && maxPCF.c - givenPCF[ubFI].c>=0 && maxPCF.p - givenPCF[ubFI].p>=0) {
            maxPCF.f -= ubF;
            maxPCF.c -= givenPCF[ubFI].c;
            maxPCF.p -= givenPCF[ubFI].p;
        }
        else {

            flag3 = true;
        }

        if (!(flag1 && flag2 && flag3)) {
            break;
        }
    }
    cout<<maxPCF.p<<" "<<maxPCF.c<<" "<<maxPCF.f;

}
