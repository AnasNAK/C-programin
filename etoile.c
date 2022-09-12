#include<stdio.h>
#include<stdlib.h>
    int j,k;
    char C;
    /*anas*/
void etoile (int h, int x){

    for(j=0;j<h;j++){
        for(k=h-j+x;k>0;k--){
            printf(" ");
        }
        for (k=1;k<=(2*j+1);k++){
            printf("*");
       }
    printf("\n");
        }
}
int main(){
    int R ;
    int L;

    do{
      printf("veuillez entrer le nombre des lignes :");
        scanf("%d",&L);
    printf("nombre de repitition ");
    scanf("%d",&R);
    int R1 = R ;
    for(int m = 1; m<= R1 ; m++){
        etoile (L++,R--);
    }
    for(int ii = 0;ii<3;ii++){
        for( int jj = 0; jj < L; jj++)
            printf(" ");
        printf("*\n");
    }


    printf("tu veux resseyez oui=o non=n :");
    scanf(" %c",&C);

    }while(C != 'n' && C!= 'N');

    return 0 ;
    }
