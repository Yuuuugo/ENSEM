#include "sudoku.h"



int main(int argc , char * argv[]) {
    if(strcmp(argv[1],"standalone")){
        printf("%s \n",argv[1]);
    }
    else if(strcmp(argv[1],"-multithread") ){
        printf("%s \n",argv[1]);
    }
    else if(strcmp(argv[1],"-server")){
        printf("%s \n",argv[1]);
    }
    else{
        printf("-standalone : lancer le programme en mode basique \n");
        printf("-multithread : lancer le programme en mode multi-thread \n");
        printf("-server : lancer le programme en mode serveur \n");
    }
    
    /*
    sudo_t sudo,test;
    lire_plateau("sudoku1.txt",&sudo);
    afficher_plateau(sudo);
    printf("%s",sudo.nom);
    sudo = convertisseur(sudo);
    afficher_plateau(sudo);
    resolution_Backtrack(&sudo);
    afficher_plateau(sudo);
    ecriture(sudo,sudo.nom);
    printf("%u \n",resolu(sudo));
    */

}