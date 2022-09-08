#include <stdio.h>
#include <stdlib.h>

int main(){
int date_naissance,X,age;
    printf("donner votre date de naissance ?\n");
    scanf("%d",&date_naissance);
    printf("qulle annee sommes nous maintenant ?\n");
    scanf("%d",&X);
    age = X -date_naissance;
    printf("est voilla vous aurez %d ans cette annee !!  ",age);

}
