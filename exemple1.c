#include<stdio.h>

int main (){
    int a;
     float b;

     printf("entrer votre N compte de 6 nombre :");
     scanf("%d",&a);
     if(!(a>=100000&&a<=999999))
     printf("numero non valide ");
   else
    printf("bnjour de votre compte\n");
    printf("ajouter votre montant DH :");
scanf("%f",&b);
   if (!(b>100&&b<100))
    printf("e minium c est 100DH.Merci pour resseyez pus tard");

}
