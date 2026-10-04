#include <stdio.h>
#include <stdlib.h>

/*
Avec les informations vues en cours, écrire, compiler et tester un programme qui calcule la moyenne de trois notes dont la deuxième a un coefficient 2.
Je vous rappelle les fonctions utiles :

printf, permet d’écrire quelque chose dans le terminal ;
scanf, permet de demander à l’utilisateurice d’entrer une valeur.


Note        Coefficient

Note 1          1
Note 2          2
Note 3          1

*/


int main() {
    
    int note1=0, note2=0 , note3=0;
    float note_moyenne = 0; 

    printf("Entrez premiere note : \n" );
    scanf("%d", &note1);
    printf("Entrez deuxieme note : \n" );
    scanf("%d", &note2);
    printf("Entrez troisime note : \n" );
    scanf("%d", &note3);

    note_moyenne = (float)((1*note1)+(2*note2)+ (1*note3))/(1+2+1);

    printf("La moyenne des notes %d , %d , %d est %f \n ", note1,note2,note3,note_moyenne);


    return EXIT_SUCCESS ;
}
