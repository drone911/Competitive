#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>

#include<math.h>
#include<string.h>
#define MAXLINESIZE 100
#define SERV_PORT 5000

int listensd,clientsd;
char buffer[MAXLINESIZE+1];
char sendBuffer[MAXLINESIZE+1];
struct sockaddr_in servaddr;

int noBytesRead=0;
//
void processClient(int);

int main()
{
	//create socket
	if((listensd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		fprintf(stderr,"Cannont create socket\n");
		exit(-1);
	}
	
	//Initialize socket address structure
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);	//INADDR_ANY is wildcard returns local address when not connected
	
	//bind socket
	if(bind(listensd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
	{
		fprintf(stderr,"Error in bind\n");
		exit(-1);
	}
	
	//make socket listening socket
	if(listen(listensd,5)<0)
	{
		fprintf(stderr,"Error in listen\n");
		exit(-1);
	}
	
	//wait for client connection
	for(;;)
	{
		clientsd=accept(listensd,(struct sockaddr*)NULL,NULL);
		if(fork()==0)
		{
						//close listening socket in child, so that reference count remains one. child serves the client, it doesn't need listening sockt to do this
			close(listensd);
			
			//server client
			processClient(clientsd);
			
			//close connected socket
			close(clientsd);
			exit(0);
		}
		close(clientsd);
	}
	return 0;
}

void processClient(int clientsd)
{
	
	

	
    int g=7,p=71;  
   
   
    int Xb;
    scanf("%d",&Xb);
    
    int Yb=pow(g,Xb);
    Yb=(int)((int)Yb%(int) p);
    printf("YB=%d\n",Yb);
   
	if((noBytesRead=read(clientsd,buffer,sizeof(buffer)))>0){
		
		
		fprintf(stdout,"%d",buffer[0]);
		printf("\nSENDING\n");
    int Ya=buffer[0];
  printf("YA=%d\n",Ya);
    double k;
    k=pow(Ya,Xb);
    
    k=fmod(k,p);
  printf("SESSION KEY IS =%d",(int)k);
    
		sendBuffer[0]=Yb;
		write(clientsd,sendBuffer,strlen(sendBuffer)+1);
    
   
	     if((noBytesRead=read(clientsd,buffer,sizeof(buffer)))>0)
       {
        int cipher=(int)buffer[0];
        
        printf("cipher=%d\n",cipher);
        
        int dec = (cipher-(int)k)%p; 
        
        printf("Dec data = %d", (int)dec); 
       
        int msg;
        scanf(" %d",&msg);
        
        int c = (msg+(int)k)%p ;
         
        printf("\nEncrypted data = %d", (int)c); 
        sendBuffer[0]=c;
        write(clientsd,sendBuffer,strlen(sendBuffer)+1);
        

	}
}
}