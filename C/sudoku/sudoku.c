#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku1.txt",&sudo);
    afficher_plateau(sudo);
    sudo = convertisseur(sudo);
    afficher_plateau(sudo);
    int p = resolution_Backtrack(&sudo);
    afficher_plateau(sudo);
    ecriture(sudo,"suduoku1_resolue");
    return(0);

}