#include <stdio.h>
#include <stdlib.h>

/*

Exercice 3
Soit l'extrait de code suivant :
int n = 10;
int p = 4;
long q = 2;
float x = 1.75;
Donner le type et la valeur du résultat des expressions suivantes :

n + q
n + x
n % p + q
n < p
n >= p
n > q
q + 3 * (n > p)
q && n
(q-2) && (n-10)
x * (q==2)
x * (q=5)

Confirmer que vous avez déterminé les bonnes valeurs en écrivant un programme qui affiche le résultat de ces expressions.

*/

int main() {
    
    int n = 10;
    int p = 4;
    long q = 2;
    float x = 1.75;
    
    printf("n + q: %d\n",n+p);
    printf("n + x: %f\n", (float)n+x);
    printf("n %% p + q %f\n", (float)(n%p)+q);
    printf("n < p %d \n", (n<p));



    printf("Hello \n");
    
    return EXIT_SUCCESS ;
}
