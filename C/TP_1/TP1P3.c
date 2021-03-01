#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define MAX_TAILLE 100
typedef struct liste
{
    int valeurs[MAX_TAILLE];
    int taille;
}liste;

void afficher_tableau(liste l){
    for (int i = 0 ; i < l.taille ; i++)
    {
        if(i< l.taille-1){
        printf("%d ", l.valeurs[i]);
        }
        else{
            printf("%d \n", l.valeurs[i]);
        }
    }
}

liste generer_tableau(liste l){
    int i;
    srand(time(NULL));
    for(i = 0; i <=l.taille; i++){
        l.valeurs[i] =  rand()%l.taille+50;        
    }

}



liste permuter(liste l,int indice1,int indice2){
    int x = l.valeurs[indice1];
    l.valeurs[indice1] = l.valeurs[indice2];
    l.valeurs[indice2] = x;
}

liste trier(liste l){
    for(int i =0; i<l.taille;i++){
            for(int j =i+1;j<l.taille;j++)
            {
                if(l.valeurs[j] < l.valeurs[i])
                {
                    permuter(l,i,j);
                }
            }
        }
        
}
    


void main(){
    liste tableau ;
    tableau.taille = 3;
    afficher_tableau(tableau);
    generer_tableau(tableau);
    trier(tableau);
    afficher_tableau(tableau);
}