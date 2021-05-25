#include "sudoku.h"


 

int nombreCaseVide(sudo_t sudo) {
    int s = 0;
    for(int i =0;i<sudo.lignes;i++) {
        for(int j=0;j<sudo.colonnes;j++)
        {
            if(sudo.sudoku[i][j]==0){
                s++;
            }
        }
    }
    return s;
}

int ListCaseVide(sudo_t sudo,int list[][2]){
    int l[2];
    int k =0;
    for(int i =0;i<sudo.lignes;i++) {
        for(int j=0;j<sudo.colonnes;j++)
        {
            if(sudo.sudoku[i][j]==0){
                list[k][0]=i;
                list[k][1]=j;
                k++;
            }
        }
    }
}
int resolu(sudo_t sudo){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if (EstValide(sudo,i,j,sudo.sudoku[i][j])==0 || sudo.sudoku[i][j]==0){
                return 0;
            }
        }
    }
    return 1;
}

void resolution_ForceBrute(sudo_t *sudo){
    int s = nombreCaseVide(*sudo);
    int list[s][2];
    int nombre[s];
    int w = 0;
    ListCaseVide(*sudo,list);
    for(int i=0;i<s;i++){
        nombre[i] =1;
    }
    while(resolu(*sudo) != 1){
        for(int k=0;k<s;k++){
            int i = list[k][0];
            int j = list[k][1];
            
            sudo->sudoku[i][j] = nombre[k];

        }
        while(nombre[w] == 9){
                nombre[w] = 1;
                w++;
                
            }
            nombre[w]++;
            w = 0;
    }

}



