#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Mettez en commentaire cette ligne si vous êtes sous Windows :
#include <termios.h>
// Inclure #include <windows.h> si vous êtes sous Windows
// Inclure #include <conio.h> si vous êtes sous Windows

#define TRUE 256
#define FALSE 0

// Mettez en commentaire cette ligne si vous êtes sous Windows :
static struct termios origtc, newtc;

enum direction {HAUT,BAS,GAUCHE,DROITE};
typedef struct{
    int **plateau;
    int lignes; // Nombre de lignes de plateau
    int colonnes; // Nobre de colonnes de plateau
    int posl; // ligne actuelle de l'étoile
    int pl; // ligne précédente de l'étoile
    int posc; // colonne actuelle de l'étoile
    int pc; // colonne précédente de l'étoile
    enum direction direction; // direction actuelle de l'étoile
} star_t;

void * lire_clavier(void *arg);
void lire_plateau(char *fichier,star_t *star);
void clearScreen();
void afficher_plateau(star_t star);
void placer_star(star_t *star);

