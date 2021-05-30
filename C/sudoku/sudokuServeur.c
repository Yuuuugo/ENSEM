#include "connexion.h"
#include "sudoku.h"



int main(){
    sudo_t sudoku;
    char fichier[20];
    int nombre;
    printf("Initialisation serveur \n");
    int sock = init_serveur();
    printf("J'attend un client \n");
    nombre = atoi(recevoir(sock));
    printf("Resolution de %d fichiers sudoku\n",nombre);
    while(nombre !=0){
        
    }

    
}