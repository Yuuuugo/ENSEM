#include "connexion.h"
#include "sudoku.h"

int w =0;
int s=0;
int q = 0;
sudo_t sudo_resolue;

void *resoudre(void *arg){
    sudo_t sudo = *(sudo_t *)arg;
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
void *afficher(void *arg){
    while(w !=0){
        if (q == 1){
    //pthread_cond_wait (&condition, &mutex);
        sudo_t sudo = *(sudo_t *)arg;
        afficher_plateau(sudo);
        w = w-1;
        q=0;
            }
    }
}
   

int main(){
    /*
    char fichier[20];
    int nombre;
    
    printf("Initialisation serveur \n");
    int sock = init_serveur();
    printf("J'attend un utilisateur \n");
    nombre = atoi(recevoir(sock));
    printf("Resolution de %d fichiers sudoku\n",nombre);
    sudo_t liste[nombre];
    char test[sizeof(sudo_t)*nombre];
    while(nombre !=0){
        liste[nombre] = recevoir_sudo(sock);
        afficher_plateau(liste[nombre]);
        printf("nombre = %d \n",nombre);
        nombre--;
        /*strcpy(test,recevoir(sock));
        printf("test = %s \n",test);
        //printf("ligne = %d \n",liste[nombre].lignes);
        printf("Sudoku numero : %d recu \n",nombre); 
        nombre--;}*/
    struct sockaddr client_addr;
    int sockid;
    sockid = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = 8080;

    int bind_status = bind(sockid, (struct sockaddr *)&server, sizeof(server));
    
    int queue_limit = 50;
    listen(sockid, queue_limit);

    socklen_t addr_size = sizeof client_addr;
    int client_sockid = accept(sockid, (struct sockaddr *)&client_addr, &addr_size);

    int sock = init_serveur();
    printf("J'attend un utilisateur \n");
    int nombre = atoi(recevoir(sock));
    printf("Resolution de %d fichiers sudoku\n",nombre);
    w= nombre;
    sudo_t liste[nombre];
    pthread_t thread[nombre];
    pthread_t Afficher;
    pthread_create(&Afficher,NULL,afficher,&sudo_resolue);
    for(int i =0;i<nombre;i++){
        int recv_status = recv(client_sockid, (sudo_t *)&liste[i], sizeof(liste[i]), 0);
        pthread_create(&thread[i], NULL,resoudre, &liste[i]);
    }
    pthread_join(Afficher,NULL); 

}