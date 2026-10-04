#include <stdio.h>
#include <stdlib.h>

/*
Exercice 2
Écrire un programme qui demande à l'utilisateurice deux nombres.
Stocker ces nombres dans des variables.
Affichez ensuite le résultat de la multiplication de ces nombres.
Commencez par faire une version du programme qui fonctionne avec des nombres entiers.
Faites ensuite une seconde version qui fonctionne avec des nombres réels.

*/


int multiplication_entiers (int nomb1, int nomb2){
    int total = nomb1+nomb2;
    return total;

}
float multiplication_reels (float nomb1,float nomb2){

    float total = nomb1+nomb2;
    return total;

}

int main() {
    
    float nombre1 =0;
    float nombre2=0;

    printf("entrez le nombre premier; ");
    scanf("%f", &nombre1);
    printf("entrez le nombre deuxieme; ");
    scanf("%f", &nombre2);
    

    printf("resultat de la calculation entiers %d \n", multiplication_entiers(nombre1 , nombre2));
    printf("resultat de la calculation reels %.4f \n", multiplication_reels(nombre1 , nombre2));

    printf("Hello \n");


    return EXIT_SUCCESS ;
}


