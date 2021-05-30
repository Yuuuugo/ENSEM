#include "connexion.h"
#include "sudoku.h"



int main(){
    char fichier[20];
    int nombre;
    
    printf("Initialisation serveur \n");
    int sock = init_serveur();
    printf("J'attend un utilisateur \n");
    nombre = atoi(recevoir(sock));
    printf("Resolution de %d fichiers sudoku\n",nombre);
    sudo_t liste[nombre];
    char test[sizeof(sudo_t)*nombre];
    while(nombre !=0){
        strcpy(test,recevoir(sock));
        liste[nombre] = *(sudo_t *) test;
        printf("ligne = %d \n",liste[nombre].lignes);
        printf("Sudoku numero : %d recu \n",nombre); 
        nombre--;
    }
}