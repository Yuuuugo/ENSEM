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
    char res[12] ="_resolue.txt";
    int p = 0;
    while(fichier[p] !='.' ){
        star->nom[p] = fichier[p];
        p++;
    }
    
    for(int i =0;i<12;i++){
        star->nom[p+i] = res[i];
    }
    star->nom[p+13]=0;
    star->nom[p+12]=0;
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
    }
    else
    {
        star->METHODE=Force_Brute;
    }
}

void clearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
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
    for(int i = 1;i<10;i++){
        if(sudoku[i] == k){
            return 1;
        }
    }
    return 0;
}



sudo_t convertisseur(sudo_t sudo){
    sudo_t star;
    int i,j,k;
    star.lignes = 9;
    star.colonnes = 9;
    star.sudoku = (int **)malloc(star.lignes*sizeof(int *));
    strcpy(star.nom,sudo.nom);
	for (i=0; i < star.lignes;i++){
		star.sudoku[i] = (int *)malloc(star.colonnes*sizeof(int));
	}
    star.METHODE = sudo.METHODE;
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

int EstValide(sudo_t sudo,int i , int j, int chiffre){
    int w = -i;
    while(i+w <9){
        if(w!=0){
        if(sudo.sudoku[i+w][j] == chiffre){
            return 0;
        }
    }

        w++;
    }
    w = -j;
    while(j+w <9){
        if (w!=0){
            if(sudo.sudoku[i][j+w] == chiffre){
                return 0;
            }
        }
        w++;
    
} 
    int x = i/3;
    int y = j/3;
    x = 3*x+1;
    y = 3*y+1;
    for(int u = -1;u<2;u++){
        for(int v =-1;v<2;v++){
            if( x+u >=0 && x+u<9 && y+v >=0 && y+v<9 ){
                if( (x+u)!=i  || (y+v)!=j){
                    if(sudo.sudoku[x+u][y+v] == chiffre){
                        return 0;
            }

            }
        }
    }
}
        return 1;
}

int TrouverCaseVide(sudo_t sudo,int l[]){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(sudo.sudoku[i][j]==0){
                l[0] = i;
                l[1] = j;
                return 0;
            }
        }
    }
}


int resolution_Backtrack(sudo_t *sudo){
    int ligne;
    int colonne;
    int l[2];
    l[0] = -1;
    l[1]= -1;
    TrouverCaseVide(*sudo,l);
    if( (l[0] == -1) && (l[1] ==-1)){
        return 1;
    }
    else{
        ligne = l[0];
        colonne = l[1];
    }
    for(int chiffre = 1;chiffre<10;chiffre++){
        if (EstValide(*sudo,ligne,colonne,chiffre)==1){
            sudo->sudoku[ligne][colonne] = chiffre;
        if(resolution_Backtrack(sudo) == 1){
                return 1;
        }
       sudo->sudoku[ligne][colonne] =0;
    }
     
    }   
    return 0; 
}




void ecriture(sudo_t sudo,char nom[]){
    FILE *test;

    test = fopen(nom,"a");
    for(int i =0;i<9;i++){
        for(int j=0;j<9;j++){
            if(j%3 ==0){
                fprintf(test," ");
            }
            fprintf(test,"%u ",sudo.sudoku[i][j]);
            if(j==8){
            fprintf(test,"\n");
        }
        }
        
    }

    fclose(test);
}