#include <stdio.h>
#include <stdlib.h>

/*
L’échange de deux entiers
Écrire un algorithme qui demande deux nombres entiers à l’utilisateurice.
Enregistrez ces nombres dans deux variables nombreA et nombreB.
Échangez ensuite la valeur contenue dans ces variables : la variable nombreA doit contenir ce que contenait nombreB et inversement.

*/

int main() {
    int nombreA=0;
    int nombreB=0;
    int stockage=0; 


    printf("Entres un nombre pour nombreA SVP : \n ");
    scanf("%d", &nombreA);
    printf("Entres un nombre pour nombreB  SVP : \n ");
    scanf("%d", &nombreB);
    
    printf("Avant le changement des valeur nombreA : %d nombreB: %d \n", nombreA, nombreB);

    
    stockage= nombreA;
    nombreA= nombreB;
    nombreB= stockage;

    printf("Apres le changement des valeur nombreA : %d nombreB: %d \n ", nombreA, nombreB);




    return EXIT_SUCCESS ;
}
