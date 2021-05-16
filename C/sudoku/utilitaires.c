#include "sudoku.h"
/*
 * Lire le plateau du jeu depuis un fichier et remplir la structure star
 */
void lire_plateau(char *fichier,sudo_t *star) {
	FILE *f;
	char str[100];
	int i,j,k;
	char ch;
    int ligneActu =1;
    int ligneMax = 12;
    star->lignes = 0;
	f = fopen(fichier,"r");
    if (f == NULL){
        printf("Je ne peux pas ouvrir le fichier %s\n",fichier);
        exit(-1);
    }
    /*
	while (fgets(str,sizeof(str),f) != NULL){
		str[strlen(str)-1] = '\0';
		star->colonnes = strlen(str);
		star->lignes++;
	}
    */
    fclose(f);
    star->lignes = 11;
    star->colonnes = 19;
	
   star->sudoku = (int **)malloc(star->lignes*sizeof(int *));
	for (i=0; i < star->lignes;i++){
		star->sudoku[i] = (int *)malloc(star->colonnes*sizeof(int));
	}	
	f = fopen(fichier,"r");
	i = 0; j = 0; k = 1;
	while ((ch = getc(f)) != EOF & k < 12) {
        if (ch == '\n'){
            k = k+1;
            printf("k = %u \n",k);
            i =i+1;
        }
        if (ch != '\n') {
            if( ch ==' '){
                star->sudoku[i][j] =-1;
                printf("%u",star->sudoku[i][j]);
            }
            else if (ch == '_') {
                star->sudoku[i][j] = 0;
                printf("%u",star->sudoku[i][j]);
            }
            else{
                star->sudoku[i][j] = (int)(ch);
                printf("ch = %c",ch);
            }
            j++;
            if (j == star->colonnes) {
                j = 0;
                i++;
            }
        }
	}
}

void clearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void resolution_Backtrack(sudo_t *sudo){
}

void afficher_plateau(sudo_t sudo){
    clearScreen();
    for(int i=0;i<sudo.lignes;i++)
    {
        for(int j=0;j<sudo.colonnes;j++)
        {
            if (sudo.sudoku[i][j] == 0)
            {
                printf("_");
            } 
            else if (sudo.sudoku[i][j]==-1){
                printf(" ");
            }
            else if (sudo.sudoku[i][j] !=-1){
                printf("%u",sudo.sudoku[i][j]);
            }
            if (j==sudo.colonnes-1)
            {
                printf("\n");
            }
        }
    }
}

void resolu(sudo_t sudo){
}