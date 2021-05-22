#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku1.txt",&sudo);
    afficher_plateau(sudo);
    sudo = convertisseur(sudo);
    afficher_plateau(sudo);
    resolution_Backtrack(&sudo);
    afficher_plateau(sudo);
    ecriture(sudo,sudo.nom);
    printf("%u \n",resolu(sudo));
}