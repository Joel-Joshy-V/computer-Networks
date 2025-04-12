#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  int main(){
     int n,nf,i=1,j,tr=0,x,flag;
     srand(time(NULL));
     printf("Enter the Number of frames:"); scanf("%d",&nf);
     printf("Enter the window Size:"); scanf("%d",&n);
     while(i<=nf){
         x=0;
         for(j=i;j<n+i&&j<=nf;j++){
            printf("Frame %d Transmitted\n",j);tr++;
         }
         for(j=i;j<n+i&&j<=nf;j++){
             flag=rand()%2;
             if(!flag){
                 printf("Frame %d ACK\n",j);
                 x++;
             }
	     else{
                 printf("ACK for %d not recived\n",j);
                 printf("Retransnmitting Window \n");
                 break;
             }
         }
         i+=x;printf("\n");
     }  
     printf("Total frames transmitted including lost frame:%d",tr);
  return 0;
 } 