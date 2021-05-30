#include "connexion.h"
#include "sudoku.h"





pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t condition1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


int w =0;
int s=0;
int q = 0;
sudo_t sudo_resolue;

void *resoudre(void *arg){
    sudo_t sudo = *(sudo_t *)arg;
    afficher_plateau(sudo);
    if (sudo.METHODE == Backtrack){
        resolution_Backtrack(&sudo);
    }
    else if(sudo.METHODE == Force_Brute){
        resolution_ForceBrute(&sudo);
    }
    if(resolu(sudo)==1){
        q = 1;
        sudo_resolue = sudo;
    }
}
void *ecrire(void *arg){
    while(w !=0){
        if (q == 1){
    //pthread_cond_wait (&condition, &mutex);
        sudo_t sudo = *(sudo_t *)arg;
        afficher_plateau(sudo);
        printf("Thread");
        ecriture(sudo,sudo.nom);
        w = w-1;
        q=0;
            }
    }
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
        printf("Rentrer le nom du sudoku que vous voulez resoudre (exemple: 'sudoku1'): ");
        scanf("%s",nom);
        strcat(nom,".txt");
        printf("%s \n",nom);
        lire_plateau(nom,&sudo);
        afficher_plateau(sudo);
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
        w= i;
        sudo_t liste[i];
        pthread_t Ecriture;
        pthread_t thread[i];
        pthread_create(&Ecriture,NULL,ecrire,&sudo_resolue);
        for(int t =0;t<i;t++){
            lire_plateau(tab[t],&liste[t]);
            pthread_create(&thread[t], NULL,resoudre, &liste[t]);
            /*pthread_join(thread[t],NULL);*/
            //sleep(2);
        }
        /*
        for(int t =0;t<i;t++){
            pthread_join(thread[t],NULL);
        }
*/
        pthread_join(Ecriture,NULL); 
}
    else if(strcmp(argv[1],"-server")==0){
        main1();
    }
}



