#include <bits/stdc++.h>
using namespace std;

char keyMatrix[5][5];

void buildKeyMatrix(string key)
{
    int k = 0, j = 0;
    while (k < key.length())
    {
        keyMatrix[k / 5][j % 5] = key[k];
        j++;
        k++;
    }
    char curr = 'A';
    while (k < 26)
    {
        if (key.find(curr) == string::npos && curr != 'J')
        {
            keyMatrix[k / 5][j % 5] = curr;
            j++;
            k++;
        }
        curr++;
    }
}
string addFillers(string &text)
{
    string filledText = "";
    int i;
    for (i = 0; i < text.length() - 1; i++)
    {
        filledText += text[i];
        if (text[i] == text[i + 1])
        {
            if (text[i] == 'X')
            {
                filledText += 'Y';
            }
            else
            {
                filledText += 'X';
            }
        }
    }
    filledText += text[i];
    if (filledText.length() & 1)
    {
        filledText += 'X';
    }
    return filledText;
}
void printKeyMatrix()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void findPos(char c1, char c2, int &x1, int &x2, int &y1, int &y2)
{
    if (c1 == 'J')
    {
        c1 = 'I';
    }
    if (c2 == 'J')
    {
        c2 = 'I';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyMatrix[i][j] == c1)
            {
                x1 = i;
                y1 = j;
            }
            if (keyMatrix[i][j] == c2)
            {
                x2 = i;
                y2 = j;
            }
        }
    }
}
string encrypt(string text, string key)
{
    buildKeyMatrix(key);
    printKeyMatrix();
    string toEncrypt = addFillers(text);
    string enc = "";
    int x1, x2, y1, y2;
    for (int i = 0; i < toEncrypt.length(); i += 2)
    {
        findPos(toEncrypt[i], toEncrypt[i + 1], x1, x2, y1, y2);
        if (y1 == y2)
        {
            enc += keyMatrix[(x1 + 1) % 5][y1];
            enc += keyMatrix[(x2 + 1) % 5][y2];
        }
        else if (x1 == x2)
        {
            enc += keyMatrix[x1][(y1 + 1) % 5];
            enc += keyMatrix[x2][(y2 + 1) % 5];
        }
        else
        {
            enc += keyMatrix[x1][y2];
            enc += keyMatrix[x2][y1];
        }
    }
    return enc;
}
string decrypt(string enc, string key)
{
    buildKeyMatrix(key);
    string text = "";
    int x1, x2, y1, y2;
    for (int i = 0; i < enc.length(); i += 2)
    {
        findPos(enc[i], enc[i + 1], x1, x2, y1, y2);
        if (y1 == y2)
        {
            text += keyMatrix[((x1 - 1) + 5) % 5][y1];
            text += keyMatrix[((x2 - 1) + 5) % 5][y2];
        }
        else if (x1 == x2)
        {
            text += keyMatrix[x1][((y1 - 1) + 5) % 5];
            text += keyMatrix[x2][((y2 - 1) + 5) % 5];
        }
        else
        {
            text += keyMatrix[x1][y2];
            text += keyMatrix[x2][y1];
        }
    }
    return text;
}
int main()
{
    string key = "ANSWER";
    string text = "BALLLOONE";
    string enc = encrypt(text, key);
    cout << "encryption of " << text << " with key " << key << " is " << enc << endl;
    cout << "decryption of " << enc << " with key " << key << " is (with fillers) " << decrypt(enc, key) << endl;
    return 0;
}