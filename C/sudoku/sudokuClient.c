#include "connexion.h"
#include "sudoku.h"


int main(){
    char tab[12][20];
    char nom[11] = {0};
    char i_str[20];
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
    sprintf(i_str, "%d",i);
    int sock = init_client();
    envoyer(sock,"localhost",i_str);
    sudo_t liste[i];
    for(int t =0;t<i;t++){
        lire_plateau(tab[t],&liste[t]);
    }
    

    return(0);
}