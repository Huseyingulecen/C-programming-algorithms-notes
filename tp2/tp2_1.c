#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

/*Exercice 1
Écrire un programme qui calcule le périmètre et l’aire d’un cercle à partir du rayon introduit au clavier par l’utilisateurice.
Utiliser des floats.
*/

int main() {
    
    float rayon = 0;
    float perimetre=0;
    printf("entrez le rayon:");
    scanf("%f", &rayon);
    perimetre = 2*rayon*M_PI;
    printf("calculation du perimetre : %.3f\n", perimetre);
    
    return EXIT_SUCCESS ;
}
