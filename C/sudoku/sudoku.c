#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku3.txt",&sudo);
    afficher_plateau(sudo);
    sudo = convertisseur(sudo);
    afficher_plateau(sudo);
    printf("%u ",EstValide(sudo,0,1,1));
    /*int p = resolution_Backtrack(&sudo);
    afficher_plateau(sudo);
    printf("%u \n",resolu(sudo));*/
    return(0);

}