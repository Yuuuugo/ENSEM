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
    afficher_plateau(sudo);
    pthread_cond_signal (&condition);
}
void *ecrire(void *arg){
    pthread_cond_wait (&condition, &mutex);
    ecriture(sudo,sudo.nom);
}

int main(int argc , char * argv[]) {
    if(argv[1]== NULL){
        printf("-standalone : lancer le programme en mode basique \n");
        printf("-multithread : lancer le programme en mode multi-thread \n");
        printf("-server : lancer le programme en mode serveur \n");
    }
    else if(strcmp(argv[1],"-standalone")==0){
        char nom[12] = {0};
        sudo_t sudo;
        printf("Rentrer le nom du sudoku que vous voulez resoudre: ");
        scanf("%s",nom);
        strcat(nom,".txt");
        printf("%s \n",nom);
        lire_plateau(nom,&sudo);
        afficher_plateau(sudo);
        sudo = convertisseur(sudo);
        resolution_Backtrack(&sudo);
        afficher_plateau(sudo);
        ecriture(sudo,sudo.nom);
    }
    else if(strcmp(argv[1],"-multithread")==0){
        
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
        sudo_t sudo;
        pthread_t Ecriture;
        pthread_create(&Ecriture,NULL,ecrire,&sudo);
        for(int t =0;t<i;t++){
            lire_plateau(tab[t],&sudo);
            pthread_t Resolution;
            pthread_create(&Resolution, NULL,resoudre, &sudo);
            pthread_join(Resolution,NULL);
            pthread_join(Ecriture,NULL);
        }
}
    else if(strcmp(argv[1],"-server")==0){
        printf("%s \n",argv[1]);
    }
}



