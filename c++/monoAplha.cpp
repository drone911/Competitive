#include<bits/stdc++.h>
using namespace std;

string encrypt(string text, string key) {
    char mp[26];
    string enc = "";
    for (int i = 0; i < key.length(); i++)
    {
        mp[i] = key[i];
    }
    int j = 0;
    for (int i = key.length(); i < 26; i++)
    {
        if(key.find('A'+j) == string::npos){
            mp[i] = j+'A';
        }
        else{
            i--;
        }
        j++;
    }
    for (int i = 0; i < text.length(); i++)
    {
        enc+=mp[text[i] - 'A'];
    }
    return enc;
}
string decrypt(string enc, string key) {
    
    char mp[26];
    string text = "";
    for (int i = 0; i < key.length(); i++)
    {
        mp[i] = key[i];
    }
    int j = 0;
    for (int i = key.length(); i < 26; i++)
    {
        if(key.find('A'+j) == string::npos){
            mp[i] = j+'A';
        }
        else{
            i--;
        }
        j++;
    }
    for (int i = 0; i < enc.length(); i++)
    {
        int j = 0;
        for ( j = 0; j < 26; j++)
        {
            if(mp[j] == enc[i]){
                break;
            }
        }
        text+='A'+j;
    }
    
    return text;
    
    
}

int main() {
    string text = "HEYY";
    string key = "ZHD";
    string enc = encrypt(text, key);
    cout<<"plain text: "<<text<<endl;
    cout<<"encrypted text with key ZHD: "<<enc<<endl;
    cout<<"decrypted text with key ZHD: "<<decrypt(enc, key);
    return 0;
}