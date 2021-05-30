#include "connexion.h"
#include "sudoku.h"



int main(){
    /*char tab[12][20];
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
    
    for(int t =0;t<i;t++){
        printf("Envoie du sudoku numero %d \n",t+1);
        lire_plateau(tab[t],&liste[t]);
        envoyer_sudo(sock,"localhost",(void *)&liste[t]);
    
    }*/
    int sockid;
    struct sockaddr_in server;

    sockid = socket(AF_INET,SOCK_STREAM,0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = 8080;

    int connect_status = connect(sockid, (struct sockaddr *)&server, sizeof(server));
    char tab[12][20];
    char nom[11] = {0};
    char i_str[20];
    sudo_t sudo;
    
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
    for(int t = 0;t<i;t++){ 
        lire_plateau(tab[t],&liste[t]);
        int send_status = send(sockid, (void *)&liste[t], sizeof(sudo), 0);
        printf("Sudoku numero : %d envoye \n",t);
    }

    return(0);
}
