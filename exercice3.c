#include<stdio.h>
#include<stdlib.h>
void trierct(int *t,int n){
    int j,i;
     int tmp;
for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
        if (*(t+i)>*(t+j)){
           tmp= *(t+i);
           *(t+i)=*(t+j);
           *(t+j)=tmp;
          }
       }
   }
   printf("\nles ellements du tableau par ordres croissant est :");
   for (i=0;i<n;i++){
    printf("%d ",*(t+i));
   }
}
void trierdt(int *t,int n){
int j,i;
int tmp;
for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
        if (*(t+i)<*(t+j)){
           tmp= *(t+i);
           *(t+i)=*(t+j);
           *(t+j)=tmp;
          }
       }
   }
   printf("\nles ellements du tableau par ordres decroissant est :");
   for (i=0;i<n;i++){
    printf("%d ",*(t+i));
   }
}
int main(){
    int i,n;
    printf("entre la taille de tableau :");
    scanf("%d",&n);
    float *t=malloc(sizeof(float));
    for (i=0;i<n;i++){
        printf("l'ellement %d ",i+1);
        scanf("%d",t+i);}

     trierct(t,n);
     trierdt(t,n);

  return 0;

}
