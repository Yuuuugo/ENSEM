#include "connexion.h"
#include "sudoku.h"



int init_serveur() {
  int errno;
  int s = socket(AF_INET, SOCK_DGRAM, AF_UNSPEC);
  if(s == -1)
    {
      printf("erreur creation socket %d\n",errno);
      exit(-1);
    }
  printf("le socket est identifie par : %d \n",s);

  int taille = sizeof(struct sockaddr_in);
  struct sockaddr_in *padin;
  padin  = (struct sockaddr_in *) (malloc(taille));
  bzero((char*)padin,taille);

  padin -> sin_family = AF_INET;
  padin -> sin_port   = htons(LEPORT);

  int bd = bind(s, (struct sockaddr *)&padin, taille);
  if(bd == -1)	
    {
      printf("Erreur d'attachement : %d \n",errno);
      exit(-1);
    }
  return s;
}

int init_client() {
  int errno;
  int s = socket(AF_INET, SOCK_DGRAM, AF_UNSPEC);
  if(s == -1)
    {
      printf("erreur creation socket %d\n",errno);
      exit(-1);
    }
  printf("le socket est identifie par : %d \n",s);
  return s;
}

char * recevoir(int s){
  static char msg[20]; //static, une faccon de retourner une varaible local
                       // si non, risque de perdre msg car en stack local!!
                       // une autre facon est de declarer msg en variable globale dans puissance4.h
  //struct sockaddr_in *p_exp;
  p_exp = (struct sockaddr_in *) (malloc(sizeof(struct sockaddr_in)));
  socklen_t p_lgexp = sizeof(struct sockaddr_in);
  int bd = recvfrom(s,msg,20,0,(struct sockaddr *)p_exp, &p_lgexp);
  if(bd == -1)	
      {
	printf("Erreur receive %d\n",bd);
	exit(-1);
      }
  //printf("%s\n",msg);
  //printf("adresse IP du client: %s\n",inet_ntoa(p_exp->sin_addr));
  
  return msg;
}

//pour envoyer un texte vers un serveur dont l'adresse est connue
void envoyer(int s, char* adresse, char* message){
  struct sockaddr_in  padin;  
  struct hostent *host; 

  int taille = sizeof(struct sockaddr_in);
  bzero((char*)&padin,taille);

  if ((host = gethostbyname(adresse))==NULL)
    {
      perror("Nom de machine"); 
      exit(2);
    };
  bcopy(host -> h_addr_list[0], &padin.sin_addr,host -> h_length);

  padin.sin_family = AF_INET;
  padin.sin_port   = htons(LEPORT);
  printf("preparation a un envoi \n");
  int bd = sendto(s,message,20,0,(struct sockaddr *)&padin,sizeof(padin));
    if(bd == -1)
      {
	printf("Erreur send \n");
	exit(-1);
      }
    else printf("Envoi reussi\n");


}

