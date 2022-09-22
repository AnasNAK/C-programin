#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//declaration de type:
 typedef struct{
      char nom [50] ;
      float prix;
      int quantite;
      int code;
      }produit;

typedef struct{
    int jj,mm,aa;
}date;

      int taille = 0;
      int tailletmp = 0;
      int fermer=0;
//fonction calculer et souvgarder TTC 
float TTC(float a)
{
    return a + a* 0.15;
}
//fonction d'ajouter plusieurs produits 
void ajouter_produit(produit *medicament)
{

    printf(">>>>>>>>> entrer les informations des produits<<<<<<<<< \n ");
    printf(" entrer nom de produit %d :",taille+1);
    scanf("%s",medicament[taille].nom);
    printf(" entrer le prix de produit %d par DH:",taille+1);
    scanf("%f",&medicament[taille].prix);
    printf(" entrer la quantite de produit %d:",taille+1);
    scanf("%d",&medicament[taille].quantite);
    printf(" entrer le code de produit %d:",taille+1);
    scanf("%d",&medicament[taille].code);
    printf("===l'ajoute est effectuee===\n",taille+1);
    taille++;
}
//fontion d ajiuter plusieurs produits
void ajouter_plusiuers_produits(produit*medicament,int nbr){
    int i ;
    int r = taille;
    for (i=taille;i<nbr+r;i++)
        ajouter_produit(medicament);

}
//fonction d'aficher la liste des medicament
    void la_liste_des_medicaments(produit *medicament){
        for(int i = 0; i < taille ; i++){
            printf("\t========information de produit========\n ");
            printf("Nom de produit :%s\n",medicament[i].nom);
            printf(" Prix de produit:%.2f DH\n",medicament[i].prix);
            printf(" Prix TTC de produit:%.2f DH\n",TTC(medicament[i].prix));
            printf(" La quantite  :%d\n",medicament[i].quantite);
            printf(" Code de produit :%d\n",medicament[i].code);
        }
    }
//fonction d affichage les quantite recherchez
    void la_liste_des_medicaments1(produit *medicament,int conteur){
        for(int i = 0; i < conteur; i++){
            printf("\t========information de produit========\n ");
            printf("Nom de produit :%s\n",medicament[i].nom);
            printf(" Prix de produit:%.2f DH\n",medicament[i].prix);
            printf(" Prix TTC de produit:%.2f DH\n",TTC(medicament[i].prix));
            printf(" La quantite  :%d\n",medicament[i].quantite);
            printf(" Code de produit :%d\n",medicament[i].code);
        }
    }
     //fonction pour aficher la liste des medicament triee
    void sous_menu_de_liste (produit *medicament){
    int choix,i,j;
    printf(">>>>>>>>>La liste des medicaments<<<<<<<<<\n");
    printf("Donner la methode d'affichage \n");
    do{
        printf(" \t1-par une ordre alphabetique croissant du nom: \n \t2-par une ordre decroissant du prix. \n");
        scanf("%d",&choix);
        if(choix != 1 && choix != 2){
            printf("Choix invalide \n");
        }
    }while(choix != 1 && choix != 2);
    switch(choix){
        case 1:{
            for(i = 0; i < taille-1; i++){
                for(j = i+1; j < taille ; j++){
                    if(strcmp(medicament[i].nom, medicament[j].nom) == 1){
                        produit temp = medicament[i];
                        medicament[i] = medicament[j];
                        medicament[j] = temp;
                    }
                }
            }
            la_liste_des_medicaments(medicament);
            break;
            }
        case 2: {
            for(i = 0; i <taille-1; i++){
                for(j = i+1; j < taille; j++){
                    if(medicament[i].prix < medicament[j].prix){
                       produit temp = medicament[i];
                        medicament[i] = medicament[j];
                        medicament[j] = temp;
                    }
                }
            }
            la_liste_des_medicaments(medicament);
                break;
                }

        default :
            printf("cette Choix est non valide. ");
            getch();
            break;
    }
}
//Fonction pour rechercher les produits par quantite
void recherche_par_quantite(produit *medicament){
	int conteur = 0;
        produit existe_produit[taille];
	int i,quantite;
	printf("Donner la quantite => ");
	scanf("%d",&quantite);
	for(i = 0; i < taille ; i++){
		if(quantite == medicament[i].quantite){
			existe_produit[conteur] = medicament[i];
			conteur++;
      }
	}
	if(conteur == 0){
		printf("Aucun produit existe de cette quantite\n");
		return; }
	          
	la_liste_des_medicaments1(existe_produit,conteur);
}


//fonction recherche produit par code
void recherche_par_code(produit * medicament){
	int code;
	printf("Donner le code du produit => ");
	scanf("%d",&code);
	int existe = trouver_par_code(medicament,code);
	if(existe == -1){
		printf("Ce produit n'exist pas dans le stock: \n");
		return;
	}else{
	    printf("\t\t==============================\n");
		printf("Nom => %s\n", medicament[existe].nom);
		printf("Prix => %.2fDH\n", medicament[existe].prix);
		printf("Quantite => %d\n", medicament[existe].quantite);
		printf("code => %d\n", medicament[existe].code);
		printf("\t\t==============================\n");
	}
}
//Sous Menu pour rechercher le produit selon le choix d'utilisateur
void sous_menu_de_recherche(produit * medicament){
	int choix;
	 printf(">>>>>>>>>recherche pour un produit<<<<<<<<<\n");
		printf("Donner la methode de recherche: \n");
	do{
		printf("1- Par code: \t 2- Par quantite: \n");
		scanf("%d",&choix);
		if(choix != 1 && choix != 2){
			printf("cette Choix  invalide \n");
		}
	}while(choix != 1 && choix != 2);

	switch(choix){
		case 1 :
			recherche_par_code(medicament);
			break;
		case 2 :
			recherche_par_quantite(medicament);
			break;
	}
}
//fonction trouver le code et souvgarder
int trouver_par_code(produit * medicament,int code){
	int i = 0;
	for(i = 0; i < taille ; i++){
		if(medicament[i].code == code)
			return i;
	}
	return -1;
	}
//fonction suprimer un produit 
void sup(produit*medicament,int code){
    int i;

    int existe= trouver_par_code(medicament,code);
    if (existe==-1)
        printf(" cette produit n'existe pas");
    else{
            for(i=existe;i<taille-1;i++)
            {
                 medicament[i] = medicament[i+1];
            }
    }
    taille--;
}
//fonction pour souvgarder et acheter les produits 
void achat (produit *medicament,int code,int quantite,produit *tmp){

   int existe = trouver_par_code(medicament,code);

if(existe != -1)
{
    if (medicament[existe].quantite-quantite==0)
    {
        tmp[tailletmp]=medicament[existe];
        sup(medicament, code);
        tailletmp++;
    }

    else if (medicament[existe].quantite-quantite>0)
    {
        tmp[tailletmp].code = medicament[existe].code;
        tmp[tailletmp].prix = medicament[existe].prix;
        strcpy(tmp[tailletmp].nom,medicament[existe].nom);
        tmp[tailletmp].quantite = quantite;
        medicament[existe].quantite = medicament[existe].quantite -quantite;
        tailletmp++;
    }

    else if(medicament[existe].quantite-quantite<0)
        printf("la quantite disponible est %d \n",medicament[existe].quantite);

}else
    printf("cette code est non valide");
}
//fonction etat < 3
void etat (produit* medicament){
    int i;
    printf("Les produits dont la quantite est inferieur de 3 \n");
    for (i=0;i<taille;i++){
        if (medicament[i].quantite<3)
            printf("le code deproduit :%d \n le nom :%s \n le prix:%.2fDH \n prix TTC:%.2fDH \nla quantite :%d \n",medicament[i].code,medicament[i].nom,medicament[i].prix,medicament[i].prix+(medicament[i].prix*0.15),medicament[i].quantite);
    }
}
//fonction d ajoute produits n est pas dans le stock 
void ajoutp(produit *medicament,produit pr)
{
    medicament[taille] = pr;
    taille++;
}
//fonction pour allimenter le stock 
void allem (produit *medicament){
    int quantite,code;
    produit pr;
    printf("entrer code :");
    scanf("%d",&code);
    printf("entrer quantite :");
    scanf("%d",&quantite);
    int existe= trouver_par_code(medicament,code);

if (existe==-1)
{

    pr.code=code;
    pr.quantite=quantite;
    printf("prix=>");
    scanf("%f",&pr.prix);
    printf("nom=>");
    scanf("%s",pr.nom);
    ajoutp(medicament,pr);
}

else{
    medicament[existe].quantite = medicament[existe].quantite + quantite;
}

}
//foction triee T tmp 
void tri(produit *tmp)
{
    int i,j;
    produit temp;
    for(i = 0; i <tailletmp-1; i++){
        for(j = i+1; j < tailletmp; j++){
            if(tmp[i].prix > tmp[j].prix){
             produit temp = tmp[i];
                     tmp[i] = tmp[j];
                     tmp[j] = temp;
                    }
                }
}
}
//fonction aficher un produit 
void affP1(produit pr)
{
    printf("\t========information de produit========\n ");
            printf("Nom de produit:%s\n",pr.nom);
            printf(" Prix de produit:%.2f DH\n",pr.prix);
            printf(" La quantite:%d\n",pr.quantite);
            printf(" Code de produit:%d\n",pr.code);
}
//fonction pour retourner le total
float somme(produit *tmp)
{
    int i;
    float s = 0;
    for(i=0;i<tailletmp;i++)
    {
        s = s + (tmp[i].prix * tmp[i].quantite);
    }
    return s;
}
//fonction pour retourner total Quantite 
int sommeQ(produit *tmp)
{
    int i;
    int s = 0;
    for(i=0;i<tailletmp;i++)
    {
        s = s + tmp[i].quantite;
    }
    return s;
}
//fonction pour aficher les statistique 
void statistique(produit *tmp,date d)
 {
    float sp,moyen;
    int choix;
    int a = sommeQ(tmp);
    sp = somme(tmp);
    tri(tmp);

    while(1){
            printf("\t========Menu statistique de vente========\n");
            printf("1:afficher le total des prix des produits vendus\n");
            printf("2:afficher le Min des prix des produits vendus\n");
            printf("3:afficher le Max des prix des produits vendus\n");
            printf("4:afficher la moyenne des prix des produits vendus\n");
            printf("5:pour retournner dans le Menu pricipal\n");

            do{
               printf(" enetrer votre choix entre 1 et 4 .\n");
               printf(" entrer le nombre 5 pour retourner dans le menu pricipal.\n");
               printf("\t==>votre choix:");
                scanf("%d",&choix);

                if (choix> 5 || choix< 0){
                  printf("netrer votre choix entre 1 et 4 :\n");
                  printf("entrer le nombre 5 pour retournner dans le Menu pricipal.");
                 }
             }while(choix> 5 || choix< 0);

                switch(choix){
        case 1 :
             printf("le total des prix des produits vendus est %.2fDH\n",sp);
             printf("date d'achat est %04d/%02d/%02d \n",d.aa, d.mm, d.jj);
            break;
        case 2 :
            printf("le min des prix des produits vendus\n");
            affP1(tmp[0]);
            printf("date d'achat est %04d/%02d/%02d \n",d.aa, d.mm, d.jj);
            break;
        case 3 :
            printf("le max des prix des produits vendus \n");
            affP1(tmp[tailletmp-1]);
            printf("%04d/%02d/%02d \n",d.aa, d.mm, d.jj);
            break;
        case 4:
            moyen = sp /a;
            printf("la moyenne des prix des produits vendus est %.2fDH\n",moyen);
            break;
        case 5 :
             return;

      }
    }
 }
    int main(){
        time_t timestamp  = time(NULL);
	    struct tm * timeInfos = localtime(&timestamp );
	produit medeicament[100];    
	produit tmp[20];
	date d;
        int s=1,i;
        int nbr,code;
        int choix ;
        int conteur = 0;

        while(fermer==0){
       //le menu
      printf("\t\t\t\t>>>>>>>>>>>>>>>>>>>>MENU PRINCIPALE<<<<<<<<<<<<<<<<<<<<\n\n");
      printf(" 1:Ajouter un nouveau produit.\n");
      printf(" 2:Ajouter plusieurs un nouveaux produits.\n");
      printf(" 3:List des produits.\n");
      printf(" 4:Acheter un produit.\n");
      printf(" 5:Recherche d'un produit.\n");
      printf(" 6:l'etat du stock.\n");
      printf(" 7:Alimenter le stock.\n");
      printf(" 8:Suprimer les produits.\n");
      printf(" 9:Statistique de vente.\n");
      printf(" 10:quitee le programe.\n");
      printf(" \n\t=====================\n");

        do{
       printf(" enetrer votre choix entre 1 et 9 .\n");
       printf(" entrer le nombre 10 pour quitee le programe .\n");
       printf("\t==>votre choix:");

       scanf("%d",&choix);

          if (choix> 10 || choix< 0){
       printf("netrer votre choix entre 1 et 9 :\n");
       printf("entrer le nombre 10 pour quitee le programe ");
    }


    }while(choix> 10 || choix< 0);


            switch(choix){
        case 1 : {
             ajouter_produit(medicament);
               getch();
        }break;

        case 2 : {
             printf("entrer le nobre des produits:");
             scanf("%d",&nbr);
             ajouter_plusiuers_produits(medicament, nbr);
             getch();

        }break;

        case 3 : {
             sous_menu_de_liste (medicament);
             getch();

        }break;

        case 4 : {

        la_liste_des_medicaments(medicament);
        getch();
        int quantite,s = 1;
        printf("entrer code :");
        scanf("%d",&code);
        printf("entrer quantite :");
        scanf("%d",&quantite);
        achat (medicament,code,quantite,tmp);
        printf("la date d'achat est%04d/%02d/%02d \n",timeInfos->tm_year+1900, timeInfos->tm_mon+1, timeInfos->tm_mday);
        for(i=0;i<tailletmp;i++)
        {
            affP1(tmp[i]);
        }
        d.aa = timeInfos->tm_year+1900;
        d.mm = timeInfos->tm_mon+1;
        d.jj = timeInfos->tm_mday;
         getch();
        }break;

        case 5 : {
            sous_menu_de_recherche(medicament);
              getch();

        }break;

        case 6 : {
           etat (medicament);
           getch();
        }break;

        case 7 : {
            allem (medicament);
            la_liste_des_medicaments(medicament);
            getch();
        }break;

        case 8 : {
            printf("entrer le code de produit:");
            scanf("%d",&code);
            sup(medicament,code);
             printf("appuyez entrer pour effectuee la supression\n");
            getch();
        }break;

        case 9 : {

            statistique(tmp,d);
            getch();
        }break;
        case 10 : {
             printf("== tu as quitee le programe ==");
          fermer = 1;
        }break;
    }
  }
  return 0;
}





