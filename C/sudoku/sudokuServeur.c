#include "connexion.h"
#include "sudoku.h"



int main(){
    sudo_t sudoku;
    char fichier[20];
    printf("Initialisation serveur \n");
    int sock = init_serveur();
    printf("J'attend un client \n");
    strcpy(fichier,recevoir(sock));
    printf("Resolution du fichier \n");



    
}