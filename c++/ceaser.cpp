#include <bits/stdc++.h>
using namespace std;

class Ceaser
{
    public:
    string encrypt(string text, int k)
    {
        string enc = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (isupper(text[i]))
            {
                enc += (char)((text[i] - 'A' + k) % 26 + 'A');
            }
            else
            {
                enc += (char)((text[i] - 'a' + k) % 26 + 'a');
            }
        }
        return enc;
    }
    string decrypt(string enc, int k){
        string dec = "";
        for (int i = 0; i < enc.length(); i++)
        {
            if (isupper(enc[i]))
            {
                dec += (char)(((enc[i] - 'A' - k)+26)% 26 + 'A');
            }
            else
            {
                dec += (char)(((enc[i] - 'a' - k) +26) % 26 + 'a');
            }
        }
        return dec;
    }
};
int main()
{
    Ceaser cs = Ceaser();
    string text = "abcZ";
    cout<<"Input Text: "<<text<<endl;
    string enc = cs.encrypt(text, 5);
    cout<<"After encyption with 5: "<<enc<<endl;
    cout<<"After decryption with 5: "<<cs.decrypt(enc, 5);
    return 0;
}