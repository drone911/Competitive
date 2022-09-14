#include<bits/stdc++.h>
using namespace std;

string key,k1,k2;
int p10[10],p8[8],ip[8],ip1[8],ep[8],p4[4];
int s0[4][4],s1[4][4];

void generateKey(string key){
	string p10perm=perm(key,p10,10);
	string ls1Res=ls1(p10perm);
	k1=perm(ls1Res,p8,8);
	string ls2Res=ls2(ls1Res);
	k2=perm(ls2Res,p8,8);
}

string perm(string a,int p[],int n){
	string res="";
	for(int i=0;i<n;i++)	res+=a[p[i]-1];
	return res;	
}

string ls1(string a){
	string res="";
	for(int i=1;i<5;i++)	res+=a[i];
	res+=a[0];
	for(int i=6;i<10;i++)	res+=a[i];
	res+=a[5];
	return res;
}

string ls2(string a){
	string res="";
	for(int i=2;i<5;i++)	res+=a[i];
	res+=a[0];res+=a[1];
	for(int i=7;i<10;i++)	res+=a[i];
	res+=a[5];res+=a[6];
	return res;
}

string sDesEncrypt(string a){
	a=perm(a,ip,8);
	string fk1=fk(a,k1);
	string swappedString=swap(fk1);
	string fk2=fk(swappedString,k2);
	string res=perm(fk2,ip1,8);
	return res;
}

string sDesDecrypt(string a){
	a=perm(a,ip,8);
	string fk2=fk(a,k2);
	string swappedString=swap(fk2);
	string fk1=fk(swappedString,k1);
	string res=perm(fk1,ip1,8);
	return res;
}

string fk(string a,string key){
	string res="";
	string left=a.substr(0,4);
	string right=a.substr(4,8);
	string fRes=f(right,key);
	res+=XOR(left,fRes);
	res+=right;
	return res; 
}

string f(string a,string k){
	string res="";
	a=perm(a,ep,8);
	a=XOR(a,k);
	res=sBox(a);
	res=perm(res,p4,4);
	return res;
}


string sBox(string a){
	string res="";
	string r0="";r0+=a[0];r0+=a[3];
	string c0="";c0+=a[1];c0+=a[2];
	string r1="";r1+=a[4];r1+=a[7];
	string c1="";c1+=a[5];c1+=a[6];
	int s0r=toDec(r0);
	int s0c=toDec(c0);
	int s1r=toDec(r1);
	int s1c=toDec(c1);
	res+=toBin(s0[s0r][s0c]);
	res+=toBin(s1[s1r][s1c]);
	return res;
}

int toDec(string a){
	if(a=="00")	return 0;
	if(a=="01")	return 1;
	if(a=="10")	return 2;
	if(a=="11")	return 3;
}

string toBin(int n){
	if(n==0)	return "00";
	if(n==1)	return "01";
	if(n==2)	return "10";
	if(n==3)	return "11";
}

string swap(string a){
	string res="";
	res+=a.substr(4,8);
	res+=a.substr(0,4);
	return res;
}

void findInversePerm(int ip[],int ip1[],int n){
	for(int i=0;i<n;i++)
		ip1[ip[i]-1]=i+1;
}
int main(){
	string plain_text;
	cout<<"Enter plain_text:"<<endl;
	cin>>plain_text;
	cout<<"Enter 10-bit key:"<<endl;
	cin>>key;
	cout<<"Enter p-10 permutation:"<<endl;
	for(int i=0;i<10;i++)	cin>>p10[i];
	cout<<"Enter p-8 permutation:"<<endl;
	for(int i=0;i<8;i++)	cin>>p8[i];
	cout<<"Enter initial permutation"<<endl;
	for(int i=0;i<8;i++)	cin>>ip[i];
	findInversePerm(ip,ip1,8);
	cout<<"Enter expantion permutation"<<endl;
	for(int i=0;i<8;i++)	cin>>ep[i];
	cout<<"Enter p-4 permutation:"<<endl;
	for(int i=0;i<4;i++)	cin>>p4[i];
	cout<<"Enter s0-block:"<<endl;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)	cin>>s0[i][j];
	cout<<"Enter s1-block:"<<endl;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)	cin>>s1[i][j];
	generateKey(key);
	string encrypted_text=sDesEncrypt(plain_text);
	cout<<"encrypted_text: "<<encrypted_text<<endl;
	string decrypted_text=sDesDecrypt(encrypted_text);
	cout<<"decrypted_text: "<<decrypted_text<<endl;
}