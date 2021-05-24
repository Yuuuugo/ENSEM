#include "sudoku.h"


int main(int argc , char * argv[]) {
    if(strcmp(argv[1],"-standalone")==0){
        char nom[11] = {0};
        sudo_t sudo;
        printf("Rentrer le nom du sudoku que vous voulez resoudre:");
        scanf("%s",nom);
        printf("%s \n",nom);
        lire_plateau(nom,&sudo);
        afficher_plateau(sudo);
        sudo = convertisseur(sudo);
        resolution_Backtrack(&sudo);
        afficher_plateau(sudo);
        ecriture(sudo,sudo.nom);
    }
    else if(strcmp(argv[1],"-multithread")==0){
        printf("%s \n",argv[1]);
    }
    else if(strcmp(argv[1],"-server")==0){
        printf("%s \n",argv[1]);
    }
    else{
        printf("-standalone : lancer le programme en mode basique \n");
        printf("-multithread : lancer le programme en mode multi-thread \n");
        printf("-server : lancer le programme en mode serveur \n");
    }


}