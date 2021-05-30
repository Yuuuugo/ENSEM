#include <stdio.h>
#include <stdlib.h>

#define TRUE 256
#define FALSE 0

//$$$$$$$$$$$ajouts pour TP socket UDP
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include <unistd.h>
#define LEPORT 5678
struct sockaddr_in *padin; //pointeur adresse internet locale
struct sockaddr_in *p_exp; //pointeur adresse internet de l'expediteur (depuis UDP recu)


//ajouts pour TP socket UDP
int init_serveur();
int init_client();
char * recevoir(int s);
void envoyer(int s, char* adresse, char* message);
