#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku21.txt",&sudo);
    afficher_plateau(sudo);
    printf("%s",sudo.nom);
    sudo = convertisseur(sudo);
    afficher_plateau(sudo);
    resolution_ForceBrute(&sudo);
    afficher_plateau(sudo);
    ecriture(sudo,sudo.nom);
    printf("%u \n",resolu(sudo));
}