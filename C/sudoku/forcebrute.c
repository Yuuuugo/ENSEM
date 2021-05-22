#include "sudoku.h"


 int puissance( int x, int n){
    for(int i = 0;i<n-1;i++){
        x = x*x;
    }
    return x;
}

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

int ListCaseVide(sudo_t sudo,int list[]){
    int l[2];
    int k =0;
    for(int i =0;i<sudo.lignes;i++) {
        for(int j=0;j<sudo.colonnes;j++)
        {
            if(sudo.sudoku[i][j]==0){
                l[0] = i;
                l[1] = j;
                list[k] =l;
                k++;
            }
        }
    }
}


void resolution_ForceBrute(sudo_t *sudo){
    int s = nombreCaseVide(*sudo);
    
    int list[s];
    int nombre[s];
    ListCaseVide(*sudo,list);
    for(int i=0;i<s;i++){
        nombre[i] =1;
    }
    while( resolu(*sudo) != 1){
        for(int i)
    }

    }



