#include "sudoku.h"



int main() {
    sudo_t sudo;
    lire_plateau("sudoku1.txt",&sudo);
    printf("%u",sudo.colonnes);
    return(0);
}