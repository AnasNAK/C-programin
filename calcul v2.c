#include<stdio.h>
#include<math.h>
int main(){
    int op,choix,n,modu;
    float n1,n2;
    double a,result;
    double v, f, i;
    char C;
do{
printf("------------------calculatrice seantifique:menu------------------\n");
printf(" 1: addition\n 2: soustraction\n 3: multiplication\n 4: division\n 5:puissance \n 6:sinus \n 7:cosinus \n 8: tangente \n 9:La valeur absolue\n 10: modulo\n 11 : log \n 12:factoriel \n");
scanf("%d",&choix);
printf("                             ******************\n");


   switch(choix){
   case 1:
        printf("entrer premier nombre\n");
        scanf("%f",&n1);
        printf("entrer deuxieme nombre\n");
        scanf("%f",&n2);
       printf(" la somme est %.2f",n1+n2);
       break;
    case 2:
        printf("entrer premier nombre\n");
        scanf("%f",&n1);
        printf("entrer deuxieme nombre\n");
        scanf("%f",&n2);
       printf(" la soustraction est %.2f",n1-n2);
       break;
    case 3:
        printf("entrer premier nombre\n");
        scanf("%f",&n1);
        printf("entrer deuxieme nombre\n");
        scanf("%f",&n2);
       printf(" la multiplication est%.2f",n1*n2);
       break;
     case 4:
         printf("entrer premier nombre\n");
        scanf("%f",&n1);
        printf("entrer deuxieme nombre\n");
        scanf("%f",&n2);
         if(n2!=0){
       printf(" la division est%.2f",n1/n2);}
       else
            printf("la division par 0 est impossible ");
       break;

     case 5:
        printf("entrer premier nombre\n");
        scanf("%f",&n1);
        printf("entrer la puissance \n");
        scanf("%f",&n2);
        printf(" la valeur de puissance est %.2f",pow(n1,n2));

     break;
     case 6:

        printf("Enter angle in radians: ");
        scanf("%lf", &a);
        result = sin(a);
        printf("\nResultat = %lf", result);
    break;
    case 7:
        printf("Enter angle in radians: ");
        scanf("%lf", &a);
        result = cos(a);
        printf("\nResult = %lf", result);
    break;
    case 8:
        printf("Enter angle in radians: ");
        scanf("%lf", &a);
        result = tan(a);
        printf("\nResult = %lf", result);
    break;
    case 9 :

    printf("\nEnter a number: ");
    scanf("%lld",&n);
    result = abs(n);
    printf("\nResult = %lld", result);
    break;

    case 10:
     printf("entrer premier nombre\n");
        scanf("%d",&n1);
        printf("entrer premier nombre\n");
        scanf("%d",&n2);
       printf(" la division est %d \n",(int)n1%(int)n2);
    case 11 :
        printf("entrer une valeur ");
        scanf("%lf", &a);
        result = log(a);
        printf("\nResult = %lf", result);
        break;
    case 12 :

    printf("\nEnter a number: ");
    scanf("%lf", &n1);
    printf("%lf ",n1);
    int temp;
    f = n1;
    printf("%lf ",f);
    for(int i =1; i <n1; i++)
    {
        f *= i;
    }
    result = f;
    printf("\nResult = %lf", result);
    break;
       default:
                printf("Votre choix est invalide, ressayez.");


}
   printf("\ntu veux resseyez un autre calcul oui=o et non=n\n");
   scanf(" %c",&C);
   }while (C!= 'n');

return 0;
}


