#include "sudoku.h"



int main() {
    sudo_t sudo;
    lire_plateau("sudoku1.txt",&sudo);
    afficher_plateau(sudo);
    return(0);

}