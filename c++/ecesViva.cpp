#include <bits/stdc++.h>
#define ROW 3
#define COL 3
using namespace std;

void printMat(float mat[ROW][COL]){
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void getCofactor(int A[ROW][COL], int temp[ROW][COL], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            if (row != p && col != q) 
            { 
                temp[i][j++] = A[row][col]; 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
int determinant(int A[ROW][COL], int n) 
{ 
    int D = 0;
  
    if (n == 1) 
        return A[0][0]; 
  
    int temp[ROW][COL]; 
  
    int sign = 1;
    for (int f = 0; f < n; f++) 
    { 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
       sign = -sign; 
    } 
  
    return D; 
} 
void adjoint(int A[ROW][COL],int adj[ROW][COL], int N) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 
    int sign = 1, temp[ROW][COL]; 
  
    for (int i=0; i<N; i++) 
    { 
        for (int j=0; j<N; j++) 
        { 
            getCofactor(A, temp, i, j, N); 
            sign = ((i+j)%2==0)? 1: -1; 
            adj[j][i] = (sign)*(determinant(temp, N-1)); 
        } 
    } 
} 
bool inverse(int A[ROW][COL], float inverse[ROW][COL]) 
{ 
    int det = determinant(A, ROW); 
    if (det == 0) 
    { 
        return false; 
    } 
    int adj[ROW][COL]; 
    adjoint(A, adj, ROW); 
  
    for (int i=0; i<ROW; i++) 
        for (int j=0; j<COL; j++) 
            inverse[i][j] = adj[i][j]/float(det); 
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if(adj[i][j] != floor(adj[i][j])){
                return false;
            }
        }   
    }
    return true; 
} 
string encrypt(string plainText, int a, int b, int key[][COL])
{
    string enc = "";
    for (int i = 0; i < text.length(); i++)
    {
        enc += (char)((int)(plainText[i] - 'A')*a + b) % 26;
    }
    
    int toPad = plainText.length()%ROW == 0 ? 0 :ROW - plainText.length()%ROW;
    while (toPad--)
    {
        plainText += rand() % 26 + 'A';
    }
    int sum;
    for (int i = 0; i < plainText.length(); i+=3)
    {
        for (int j = 0; j < ROW; j++)
        {
            sum = 0;
            for (int k = 0; k < COL; k++)
            {
                sum += key[j][k] * (plainText[i+k]);
            }
            sum = sum%26;
            enc[i]=sum+'A';
        }   
    }
    return enc;
}

string decrypt(string enc, int key[][COL]){
    float invertedKey[ROW][COL];
    if(!inverse(key, invertedKey)){
        return string("Non invertable key matrix");
    }
    cout<<"==============inverted key matrix========================"<<endl;
    printMat(invertedKey);
    cout<<"======================================"<<endl;
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
            dec+=sum+'A';
        }   
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
            cout<<"Encrypted Text with filler: "<<encrypt(plainText, a, b, key);
        }else{
            string enc;
            cout<<"Enter encrypted text:";
            cin>>enc;
            cout<<endl;
            cout<<"Enter the values for key matrix:";
            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cin>>key[i][j];
                }
            }
            cout<<"Decrypted Text with filler: "<<decrypt(enc, key);
        }
        cout<<"\nEnter Choice:";
        cin>>choice;
    }
    return 0;
}