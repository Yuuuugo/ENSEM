#include "sudoku.h"



int main() {
    sudo_t sudo,test;
    lire_plateau("sudoku1.txt",&sudo);
    afficher_plateau(sudo);
    /*test = convertisseur(sudo);
    afficher_plateau(test);*/
    return(0);
}