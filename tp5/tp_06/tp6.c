#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

/*
 * Remplit tab[0..n-1] avec le résultat du crible d'Ératosthène.
 *
 * Après l'appel, tab[i] vaut true si i est premier (ou si i vaut 0
 * ou 1, par convention), false sinon.
 *
 * Exemple avec n = 10 :
 *   tab = { true, true, true, true, false, true,
 *           false, true, false, false }
 */
void eratosthene(int n, bool tab[]) {
    
    for (int i=0; i<n;i++){
        
        tab[i]= true;
        
    }
    
    for(int i=2; i<n; i++){
        for(int k=2*i; k<n; k=k+i){
            if(tab[i]==true){
                tab[k]=false;
            }
        }
    }
    // TODO :
    //   - initialiser tout le tableau à true
    //   - pour i de 2 à n - 1 :
    //       si tab[i] est true, marquer false tous ses multiples
    //       à partir de 2 * i
}

/*
 * Remplit tab avec les nombres premiers inférieurs à n.
 * Renvoie le nombre de premiers trouvés.
 *
 * tab doit avoir au moins n cases. Seules les `count` premières
 * sont utilisées, où count est la valeur de retour.
 *
 * Exemple avec n = 10 : tab commence par { 2, 3, 5, 7 }, et la
 * fonction renvoie 4.
 *
 * Doit utiliser eratosthene().
 */
int eratosthene_2(int n, int tab[]) {
    
    bool premier_tab[n];
    int counter_premier_number= 0;
    eratosthene(n,premier_tab);
    
    for(int i=2; i<n; i++){
        
        if(premier_tab[i]== true){
            
            tab[counter_premier_number]=i;
            counter_premier_number++;
            
        }
    }
    
    // TODO :
    //   - construire le crible booléen avec eratosthene
    //   - parcourir les indices de 2 à n - 1
    //   - copier chaque indice premier dans tab
    //   - renvoyer le nombre de premiers copiés
    return counter_premier_number;
}

#ifndef TP6_TEST
int main(void) {
    // Exercice 1
    printf("Exercice1\n");
    
    bool tab[N];        // non initialisé : tant que eratosthene est
                       // vide, ce tableau contient n'importe quoi
    eratosthene(N, tab);
    printf("Les nombres premiers inférieurs à %d sont : ", N);
    for (int i = 2; i < N; i++) {
        if (tab[i]) {
            printf("%d, ", i);
        }
    }
    printf("\n");

    // Exercice 2
    printf("Exercice2\n");
    int tab_2[N];
    int count = eratosthene_2(N, tab_2);
    printf("Les nombres premiers inférieurs à %d sont : ", N);
    for (int i = 0; i < count; i++) {
        printf("%d, ", tab_2[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
#endif
