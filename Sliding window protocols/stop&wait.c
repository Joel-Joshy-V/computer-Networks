# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<unistd.h>
int main(){
  int i=1,j,nf;
  printf("Enter the no of frames:"); scanf("%d",&nf);
  srand(time(NULL));
  while(i<=nf){
    printf("Sending frame %d\n",i);
    printf("Waiting for 3 second\n");
    sleep(3);
    int flag=rand()%2;
    if(!flag){
      printf("ACk for %d recived\n",i);
      i++;
    }
    else{
      printf("Frame %d is lost\n",i);
      printf("Resending the frame\n");
    }
  }
  return 0;
}