#include "sudoku.h"




pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

sudo_t sudo;

void *resoudre(void *arg){
    printf ( " Boucle resoudre \n");
    sudo_t sudo = *(sudo_t *)arg;
    printf("nom du sudoku 1: %s \n",sudo.nom);
    sudo = convertisseur(sudo);
    resolution_Backtrack(&sudo);
    pthread_cond_signal (&condition);
}
void *ecrire(void *arg){
    pthread_cond_wait (&condition, &mutex);
    afficher_plateau(sudo);
    ecriture(sudo,sudo.nom);
