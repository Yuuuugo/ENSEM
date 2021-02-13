#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nombremystere(){
    srand(time(NULL));
    int h = rand();
    return h;
}

void devinnette(){
    int difficulte;
    int x = nombremystere();
    printf("Choisissez un niveau de difficulte: 1=Facile(1-16) 2 = Moyen(1-256) 3 = Difficile(1-6553) \n");
    scanf("%d",&difficulte);
    switch (difficulte)
    {
    case 1:
        x = x%16+1;
        break;
    case 2:
        x = x%256+1;
    case 3:
         x = x%6553+1;
    default:
        break;
    } (difficulte);
    int a;
    int i = 1;
    printf("Devinier le nombre mystere \n");
    scanf("%d",&a);
    do{
        if(a<x){
        printf("C'est plus, redevinez le nombre mystere \n");
        scanf("%d",&a);
        i = i+1;
        }
        else
        {
        printf("C'est moins , redevinez le nombre mystere \n");
        scanf("%d",&a);
        i = i+1;
        }
    }while(a != x);
    printf("Bien joue, vous avez reussi en %d essai \n",i);
}



void main()
{
    devinnette();
}