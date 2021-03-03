#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "puissance4.h"


void afficher_plateau(int tableau[LIGNES][COLONNES]){
    for(int i = 0; i<LIGNES;i++){
        printf(" |");
        for(int j = 0; j<COLONNES;j++)
        {
            if(tableau[i][j] == CROIX)
            {
            printf("X|");
            }
            else if (tableau[i][j] == ROND)
            {
                printf("O|");
            }
            else if(tableau[i][j] == 0){
                printf(" |");
            }
        
        }
        printf("\n");
    }
    printf("------------------- \n");
    printf("  0 1 2 3 4 5 6\n");

}

int combien_dans_colonne(int tableau[LIGNES][COLONNES],int colonne){
    int s = 0;
    for(int i = 0;i<LIGNES;i++){
        if(tableau[i][colonne]!=0){
            s = s+1;
        }
    }
    return s;
}

void empiler(int tableau[LIGNES][COLONNES],int colonne, int couleur){
    int s = combien_dans_colonne(plateau,colonne);
    if(s<LIGNES){
        plateau[LIGNES-s-1][colonne] =couleur;
        }
    }
    
int combien_dans_direction(int tableau[LIGNES][COLONNES], int couleur, int colonne, int ligne, int delta_i,int delta_j){
        int k = 0;
        while((ligne+(k+1)*delta_i <= LIGNES) && (colonne+(k+1)*delta_j <= COLONNES) && (tableau[ligne+(k+1)*delta_i][colonne+(k+1)*delta_j] == couleur))
            {
            k++;
        }
        return k;
}

int test_tout(int tableau[LIGNES][COLONNES],int couleur, int colonne, int ligne){
    int s = 0;
    int w = 0;
    for(int delta_i = -1;delta_i<2;delta_i++){
        for(int delta_j = -1;delta_j<2;delta_j++){
            if(delta_i != 0 || delta_j != 0 ){
                int w = combien_dans_direction(tableau,couleur,colonne,ligne, delta_i, delta_j)+
                        combien_dans_direction(tableau,couleur,colonne,ligne, -delta_i, -delta_j);        
                if(w >= 3){
                    return(couleur);
                } 
            }
        }
    }
    return s;
}

int tableau_complet(int tableau[LIGNES][COLONNES]){
    for(int i = 0; i < LIGNES; i++){
        for(int j = 0; j < COLONNES; j++){
            if(tableau[i][j] == 0 ){
                return 0;
            }
        }
    } 
    return 1;
}