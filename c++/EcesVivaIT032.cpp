#include <bits/stdc++.h>
#define ROW 3
#define COL 3
using namespace std;

 
bool inverse(int A[ROW][COL], float inverse[ROW][COL]) 
{ 
    double dete =    +A[0][0]*(A[1][1]*A[2][2]-A[2][1]*A[1][2])
                            -A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
                            +A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    double invdet = 1/dete;
    if(invdet==0){
        return false;
    }
    inverse[0][0] =  (A[1][1]*A[2][2]-A[2][1]*A[1][2])*invdet;
    inverse[1][0] = -(A[0][1]*A[2][2]-A[0][2]*A[2][1])*invdet;
    inverse[2][0] =  (A[0][1]*A[1][2]-A[0][2]*A[1][1])*invdet;
    inverse[0][1] = -(A[1][0]*A[2][2]-A[1][2]*A[2][0])*invdet;
    inverse[1][1] =  (A[0][0]*A[2][2]-A[0][2]*A[2][0])*invdet;
    inverse[2][1] = -(A[0][0]*A[1][2]-A[1][0]*A[0][2])*invdet;
    inverse[0][2] =  (A[1][0]*A[2][1]-A[2][0]*A[1][1])*invdet;
    inverse[1][2] = -(A[0][0]*A[2][1]-A[2][0]*A[0][1])*invdet;
    inverse[2][2] =  (A[0][0]*A[1][1]-A[1][0]*A[0][1])*invdet;
    return true;

} 
string encrypt(string plainText, int a, int b, int key[][COL])
{
    string enc = "";
    cout<<plainText<<endl;
            
    for (int i = 0; i < plainText.length(); i++)
    {
        enc += (char)((int)(plainText[i] - 'A')*a + b) % 26;
    }
    
    int sum;
    for (int i = 0; i < enc.length(); i+=3)
    {
        for (int j = 0; j < ROW; j++)
        {
            sum = 0;
            for (int k = 0; k < COL; k++)
            {
                sum += key[j][k] * (enc[i+k]);
            }
            sum = sum%26;
            enc[i+j]=(char)sum+'A';
        }   
    }
    return enc;
}

string decrypt(string enc,int a, int b,int key[][COL]){
    float invertedKey[ROW][COL];
    if(!inverse(key, invertedKey)){
        return string("Non invertable key matrix");
    }
    int sum;
    int temp;
    string dec="";
    for (int i = 0; i < enc.length(); i+=3)
    {
        for (int j = 0; j < ROW; j++)
        {
            sum = 0;
            for (int k = 0; k < COL; k++)
            {
                temp = ((invertedKey[j][k] * (enc[i+k]-'A')));
                while (temp<0)
                {
                    temp+=26;
                }
                temp = temp%26;
                sum+=temp;
            }
            sum = sum%26;
            dec+=sum;
        }   
    }
    int a_inv=-1;
    for (int i = 0; i < 26; i++) 
    { 
        int mod = (a * i) % 26; 
        if (mod == 1) 
        {  
            a_inv = i; 
        } 
    }
    for (int i = 0; i < dec.length(); i++)
    {
        dec[i] = (char)((((int)a_inv*(dec[i]) - b)) % 26 + 'A');
    }
    
    return dec;
}
int main()
{
    cout<<"1.For Encryption \n2.For Decryption \n3.To Exit"<<endl;
    int choice;
    int key[ROW][COL];
    cout<<"Enter Choice:";
    cin>>choice;
    while (choice!=3)
    {
        if(choice == 1){
            int a,b;
            string plainText;
            cout<<"Enter plaintext:";
            
            cin>>plainText;
            cout<<endl;
            cout<<"Enter two values (a&b)";
            cin>>a>>b;
            cout<<"Enter the values for key matrix:";
            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cin>>key[i][j];
                }
            }
            cout<<"Encrypted Text: "<<encrypt(plainText, a, b, key);
        }else{
            string enc;
            int a, b;
            cout<<"Enter encrypted text:";
            cin>>enc;
            cout<<endl;
            
            cout<<"Enter two values (a&b)";
            cin>>a>>b;
            
            cout<<"Enter the values for key matrix:";
            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cin>>key[i][j];
                }
            }
            cout<<"Decrypted Text: "<<decrypt(enc, a,b,key);
        }
        cout<<"\nEnter Choice:";
        cin>>choice;
    }
    return 0;
}