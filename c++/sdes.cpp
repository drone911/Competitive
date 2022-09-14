#include <bits/stdc++.h>
using namespace std;

string EP = "30120132";
string P8 = "86071235";
string P10 = "4689720135";
string P4 = "3210";
string IP = "15307264";

string S0[4][4] = {
    {"01", "00", "11", "10"},
    {"11", "10", "01", "00"},
    {"00", "10", "01", "11"},
    {"11", "01", "11", "10"},
};

string S1[4][4] = {
    {"00", "01", "10", "11"},
    {"10", "00", "01", "11"},
    {"11", "00", "01", "00"},
    {"10", "01", "00", "11"},
};

void leftShift(string &toShift, int l, int r, int shifts)
{
    char temp = toShift[l];
    int i = l;
    while (i < r)
    {
        toShift[i] = toShift[i + 1];
        i++;
    }
    toShift[r] = temp;
    if (shifts > 1)
    {
        leftShift(toShift, l, r, shifts - 1);
    }
}
string permute(string toPermute, string permutation)
{
    string afterPermutation = "";
    for (int i = 0; i < permutation.length(); i++)
    {
        afterPermutation += toPermute[stoi(permutation.substr(i, 1))];
    }
    return afterPermutation;
}
void generateKeys(string key, string &key1, string &key2)
{
    // initial P10 permutation
    string afterP10 = permute(key, P10);
    string toGenerateKey1 = afterP10.substr(0, afterP10.length());
    string toGenerateKey2 = afterP10.substr(0, afterP10.length());

    // generate 1st key
    leftShift(toGenerateKey1, 0, 4, 1);
    leftShift(toGenerateKey1, 5, 9, 1);
    key1.clear();
    key1.append(permute(toGenerateKey1, P8));

    // generate 2nd key
    leftShift(toGenerateKey2, 0, 4, 3);
    leftShift(toGenerateKey2, 5, 9, 3);
    key2.clear();
    key2.append(permute(toGenerateKey2, P8));
}

string XOR(string s1, string s2)
{
    string xored = "";
    int i = 0;
    while (i < s1.length())
    {
        if (s1[i] == s2[i])
        {
            xored += '0';
        }
        else
        {
            xored += '1';
        }
        i++;
    }
    return xored;
}
string applySbox(string input, string Sbox[4][4])
{
    int row = input[0] + input[3] - 48 * 2;
    int col = input[1] + input[2] - 48 * 2;
    return Sbox[row][col];
}
string fk(string input, string key)
{
    string expandedInput = permute(input, EP);
    string afterXor = XOR(expandedInput, key);

    string upper = afterXor.substr(0, 4);
    string lower = afterXor.substr(4, 4);
    string afterS1 = applySbox(upper, S0);
    string afterS2 = applySbox(lower, S1);

    string combined = afterS1 + afterS2;
    return permute(combined, P4);
}
string getIPInverse(string IP)
{
    // temp values are assigned
    string inverseIP = "01234567";
    for (int i = 0; i < IP.length(); i++)
    {
        inverseIP[stoi(IP.substr(i, 1))] = (char)(48 + i);
    }
    return inverseIP;
}
string encrypt(string plaintext, string key)
{
    string afterIP = permute(plaintext, IP);
    string key1 = "", key2 = "";
    generateKeys(key, key1, key2);

    string afterFirstRound = XOR(afterIP.substr(4, 4), fk(afterIP.substr(0, 4), key1)) + afterIP.substr(0, 4);
    leftShift(afterFirstRound, 0, afterFirstRound.length() - 1, afterFirstRound.length() / 2);
    string afterSecondRound = XOR(afterFirstRound.substr(4, 4), fk(afterFirstRound.substr(0, 4), key2)) + afterFirstRound.substr(0, 4);

    return permute(afterSecondRound, getIPInverse(IP));
}
string decrypt(string enc, string key)
{
    string afterIP = permute(enc, IP);
    string key1 = "", key2 = "";
    generateKeys(key, key1, key2);

    string afterFirstRound = XOR(afterIP.substr(4, 4), fk(afterIP.substr(0, 4), key2)) + afterIP.substr(0, 4);
    leftShift(afterFirstRound, 0, afterFirstRound.length() - 1, afterFirstRound.length() / 2);
    string afterSecondRound = XOR(afterFirstRound.substr(4, 4), fk(afterFirstRound.substr(0, 4), key1)) + afterFirstRound.substr(0, 4);

    return permute(afterSecondRound, getIPInverse(IP));
}

int main()
{
    string plainText;
    string key;
    cout << "Enter 8 bit plain text: ";
    cin >> plainText;
    cout << "\nEnter 10 bit key: ";
    cin >> key;
    string enc = encrypt(plainText, key);
    cout << "\nEncrypted text: " << enc;
    cout << "\nDecrypted text: " << plainText;

    return 0;
}
