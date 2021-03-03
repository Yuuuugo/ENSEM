#include <stdio.h>
#include <stdlib.h>
#define LIGNES 6
#define COLONNES 7

#define TRUE 256
#define FALSE 0

enum jeton {CROIX=1, ROND=2};
typedef struct {
  char pseudo[20];
  enum jeton couleur;
}joueur;

int plateau[LIGNES][COLONNES];
//Prototypes de fonctions
void afficher_plateau(int tableau[LIGNES][COLONNES]);
int combien_dans_colonne(int tableau[LIGNES][COLONNES],int colonne);
void empiler(int tableau[LIGNES][COLONNES],int colonne, int couleur);
int combien_dans_direction(int tableau[LIGNES][COLONNES], int couleur,
                           int colonne,int ligne, int delta_i,int delta_j);
int test_tout(int tableau[LIGNES][COLONNES], int couleur,int colonne ,int ligne);
int tableau_complet(int tableau[LIGNES][COLONNES]);