#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,choix;
    float b,c,e,T;
    printf("entrer votre N compte 7 nombre :\n");
    scanf("%d",&a);
    while(a<1000000){
    printf("numero non valide.resseyez:");
    scanf("%d",&a);
    }
if (a<1000000){
        printf("bonjour sur votre compte.\n");
        printf("ajouter votre montant DH:");
        scanf("%f",&b);
        }
if(b<100)
        printf("le minium c'est 100DH.Merci pour resseyez plus tard.");
    else
        printf("votre solde est %.2f DH\n",b);
    printf("veulliez choisi votre choix :\n 1:le tirrage\n 2:ajoutter une autres montant\n");
    scanf("%d",&choix);
    switch(choix){
case 1:
    printf("qulle argent tu veux tirrez DH ?\n");
    scanf("%f",&c);
    if(c<100)
    printf("le minium c'est 100DH.Merci pour resseyez plus tard.");
    else
        T=b-c;
        printf("tu as tirrez %.2fDH .Et votre total maintenant c'est %.2fDH.",c,T);
    break;
case 2:
    printf("combien d'argent tu veux ajouter ?\n");
    scanf("%f",&e);
    T=e+b;
    printf("votre total maintenat c'est%.2fDH.",T);
    break;
    }
}

