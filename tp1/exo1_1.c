#include <stdio.h>

int main() {
    
    int nombre = 0;
    int somme = 0;


    printf("Entrez un nombre entier:  \n");
    scanf("%d",&nombre);

    somme = (nombre*(nombre+1))/2;
    
    printf("La Somme %d des nombres naturels de 1 à jusqu'a %d \n", somme, nombre);


    printf("Hello!\n");
    return 0;
}
