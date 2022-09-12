#include<stdio.h>
#include<stdlib.h>
int main(){
    int L;
    int j,k;
    printf("veuillez entrer le nombre des lignes :");
    scanf("%d",&L);
    for(j=1;j<=L;j++){
        for(k=1;k<=L-j;k++){
            printf("  ");
        }
        for (k=1;k<=(2*j-1);k++){
         if (j==L || k==1 ||k== (2*j-1))
            printf(" *");
        else
            printf("  ");}
      printf("\n");
    }


}
