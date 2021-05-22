#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku3.txt",&sudo);
    afficher_plateau(sudo);
    sudo = convertisseur(sudo);
    afficher_plateau(sudo);
    int p = resolution_Backtrack(&sudo);
    afficher_plateau(sudo);
    ecriture(sudo,sudo.nom);
    return(0);
}