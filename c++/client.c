#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define MAXLINESIZE 100
#define SERV_PORT 5000


int main(int argc, char** argv)
{
	int connectsd;
	char sendBuffer[MAXLINESIZE+1];
	char recvBuffer[MAXLINESIZE+1];
	struct sockaddr_in servaddr;
	int noBytesRead=0;
	if(argc!=2)
	{
		fprintf(stderr,"Usage : %s IP-Address\n",argv[0]);
		exit(-1);
	}
//create socket
	if((connectsd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		fprintf(stderr,"Cannot create socket\n");
		exit(-1);
	}
	//Initialize socket address structure
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	if(inet_pton(PF_INET,argv[1],&servaddr.sin_addr)<=0)
	{
		fprintf(stderr,"Error in inet_pton");
		exit(-1);
	}
	// Connecting to server
	if(connect(connectsd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
	{
		fprintf(stderr,"Error in connect");
		exit(-1);
	}
	
  
    
    int g=7,p=71;  
   
    
    int Xa;
    scanf("%d",&Xa);
	  
    
    int Ya=pow(g,Xa);
    Ya=(int)((int)Ya%(int) p);
    printf("Ya=%d\n",Ya);
    sendBuffer[0]=Ya;
   
    write(connectsd,sendBuffer,strlen(sendBuffer)+1);
    if((noBytesRead=read(connectsd,recvBuffer,sizeof(recvBuffer)))<0)
		exit(0);
	   
	   
	   fprintf(stdout,"%d",recvBuffer[0]);
    int k;
    int Yb=recvBuffer[0];
    printf("Yb=%d\n",Yb);
	  
    
    k=pow(Yb,Xa);
    k=(int)(k%p);
    printf("SESSION KEY IS =%d",k);
	   int msg;
  
	   scanf("%d",&msg);
		
    int c=(msg+k)%p;
	    printf("\nEncrypted data = %d", c); 
	    
    sendBuffer[0]=c;
	    write(connectsd,sendBuffer,strlen(sendBuffer)+1);
	
    if((noBytesRead=read(connectsd,recvBuffer,sizeof(recvBuffer)))>0)
    {
	
     	  int cipher=(int)recvBuffer[0];
		  printf("cipher=%d\n",cipher);
		
               int dec = (cipher-k)%p;
               printf("Dec data = %d", dec);
    }

	return 0;

}