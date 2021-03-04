#include <stdlib.h>
#include <stdio.h>
#include "puissance4.h"



void main(){
    char Joueur1[12],Joueur2[12];
    printf("Nom du Joueur1 :");
    gets(Joueur1);

    int ligne = 0;
    int colonne = 0;
    int couleur = 2;
    afficher_plateau(plateau);
    while(tableau_complet(plateau) == 0 & test_tout(plateau,couleur,colonne,ligne) == 0){
        couleur = couleur%2+1;
        if(couleur == 1){
            printf("%s A vous de jouer \n",Joueur1);
        do{
        printf("Dans quelle colonne voulez vous jouer : \n");
        scanf("%d",&colonne);
        }while(
            colonne >6 || colonne < 0 || combien_dans_colonne(plateau,colonne) >= 6
        );
        }
        else{
            colonne = IA(plateau);
            printf("colonne = %d \n",colonne);
        }        
        
        empiler(plateau,colonne,couleur);
        ligne = LIGNES - combien_dans_colonne(plateau,colonne);
        afficher_plateau(plateau);
    }


    if(tableau_complet(plateau) == 0){
        int k = test_tout(plateau,couleur,colonne,ligne);
        if(couleur == 1){
            printf("%s a gagné \n",Joueur1);
        }
        else{
            printf("%s a gagné \n",Joueur2);
        }
    }
    else{
        printf("Egalite \n");
    }
}