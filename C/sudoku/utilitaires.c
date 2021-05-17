#include "sudoku.h"
/*
 * Lire le plateau du jeu depuis un fichier et remplir la structure star
 */
void lire_plateau(char *fichier,sudo_t *star) {
	FILE *f;
	char str[100];
	int i,j,k,t;
	char ch,ch1;
    char methode[20];
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
    star->lignes = 9;
    star->colonnes = 19;
	
   star->sudoku = (int **)malloc(star->lignes*sizeof(int *));
	for (i=0; i < star->lignes;i++){
		star->sudoku[i] = (int *)malloc(star->colonnes*sizeof(int));
	}	
	f = fopen(fichier,"r");
	i = 0; j = 0; k = 0,t=0;
	while ((ch = getc(f)) != EOF ) {
        if (ch == '\n'){
            k = k+1;
        }
        if (ch != '\n' & k>=1 & k<13) {
             if( ch ==' '){
                star->sudoku[i][j] =-1;
            }
            if (ch == '_') {
                star->sudoku[i][j] = 0;
            }
            else if (ch == '1'){
                star->sudoku[i][j] = 1;
            }
            else if (ch == '2'){
                star->sudoku[i][j] = 2;
            }
            else if (ch == '3'){
                star->sudoku[i][j] = 3;
            }
            else if (ch == '4'){
                star->sudoku[i][j] = 4;
            }
            else if (ch == '5'){
                star->sudoku[i][j] = 5;
            }
            else if (ch == '6'){
                star->sudoku[i][j] = 6;
            }
            else if (ch == '7'){
                star->sudoku[i][j] = 7;
            }
            else if (ch == '8'){
                star->sudoku[i][j] = 8;
            }
            else if (ch == '9'){
                star->sudoku[i][j] = 9;
            }

            j++;
            if (j == star->colonnes) {
                j = 0;
                i++;
            }
        }
        
        if(k==13){
            if(ch!= '\n')
            {
                methode[t]=ch; 
                t++;               
                }
            }
        
	}
    if(methode[9] =='A'){
        star->METHODE = Backtrack;
        printf("Backtrack");
    }
    else
    {
        star->METHODE=Force_Brute;
        printf("Force_Brute");
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

void resolution_ForceBrute(sudo_t *sudo){

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
int appartenir(int *sudoku,int k){
    int i;
    for(i = 1;i<=9;i++){
        if(sudoku[i] == k){
            return 1;
        }
    }
    return 0;
}

int resolu(sudo_t sudo){
    int i,j,k;
    for(i = 0; i < sudo.lignes;i++)
    {
        for(int k = 1;k < 10;k++)
        {
            int d ;
            d = appartenir(sudo.sudoku[i],k);
            if(d == 0)
            {
                return 0;
            }
        }
    }
    for (int  i = 0; i < 10; i++)
    {
        int h[9];
        for(int j = 0;j<9;j++){
            h[j] = sudo.sudoku[j][i];
        }
        for (k  = 1; k < 10; k++)
        {
            int d;
            d=appartenir(h,k);
            if(d == 0)
            {
                return 0;
            }
        }
        
    return 1;
}
}

sudo_t convertisseur(sudo_t sudo){
    sudo_t star;
    int i,j,k;
    star.lignes = 9;
    star.colonnes = 9;
    star.sudoku = (int **)malloc(star.lignes*sizeof(int *));
    
	for (i=0; i < star.lignes;i++){
		star.sudoku[i] = (int *)malloc(star.colonnes*sizeof(int));
	}
    
    for (i = 0;i<star.lignes;i++){
        j=0;
       for(k=0;k < star.colonnes;k++){
            while(sudo.sudoku[i][j+k] == -1){
                j++;
            }
            star.sudoku[i][k] = sudo.sudoku[i][j+k];
        }
    }
    return(star);
}