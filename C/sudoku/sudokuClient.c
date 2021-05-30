#include "connexion.h"
#include "sudoku.h"


int main(){
    char tab[12][20];
    char nom[11] = {0};
    printf("Rentrer les noms des differents sudoku que vous voulez resoudre: ");
    scanf("%s",nom);
    int i=0;
    while(strcmp(nom,"termine")!=0){
        strcat(nom,".txt");
        strcpy(tab[i],nom);
        i = i+1;
        printf("Rentrer un autre nom ou 'termine' : ");
        scanf("%s",nom);
        }
    int sock = init_client();
    envoyer(sock,"localhost",tab[0]);
    

    return(0);
}