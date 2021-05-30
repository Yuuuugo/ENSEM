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
        recv(sock,&liste[nombre],sizeof(sudo_t),0);
        afficher_plateau(liste[nombre]);
        printf("nomre = %d \n",nombre);
        nombre--;
        /*strcpy(test,recevoir(sock));
        printf("test = %s \n",test);
        //printf("ligne = %d \n",liste[nombre].lignes);
        printf("Sudoku numero : %d recu \n",nombre); 
        nombre--;*/
    }
}