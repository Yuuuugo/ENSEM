#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void affichage(int tab[],int taille){
    for (int i = 0 ; i < taille ; i++)
    {
        if(i< taille-1){
        printf("%d ", tab[i]);
        }
        else{
            printf("%d \n", tab[i]);
        }
    }
}
void genere (int tab[],int taille){
    int i;
    int x;
    srand(time(NULL));
    for(i = 0; i <=taille; i++){
        tab[i] =  rand()%taille+1;        
    }
}

void permuter(int tab[],int i, int j){
    int x = tab[i];
    tab[i] = tab[j];
    tab[j] = x;
}

void tri_bulles(int tab[],int taille){
    for(int i =0; i<taille;i++){
        for(int j =i+1;j<taille;j++)
        {
            if(tab[j] < tab[i])
            {
                permuter(tab,i,j);
            }
        }
    }
    
}
void programme(){
    int taille;
    printf("Taille de la liste des valeurs : \n");
    scanf("%d",&taille);
    int tableau[taille];
    genere(tableau,taille);
    printf("Voici un tableau de taille %u avec des valeurs generes aleatoirement entre 1 et %u \n",taille,taille);
    affichage(tableau,taille);
    tri_bulles(tableau,taille);
    printf("Voici le tableau tries en ordre croissant\n"); 
    affichage(tableau,taille);

}
void main()
{
    programme();

}