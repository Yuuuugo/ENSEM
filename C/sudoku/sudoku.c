#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku10.txt",&sudo);
    afficher_plateau(sudo);
    test = convertisseur(sudo);
    afficher_plateau(test);
    printf("%u \n",resolu(sudo));
    return(0);
}