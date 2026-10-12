#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Renvoie true si year est bissextile, false sinon.
 *
 * Règle : divisible par 4, mais pas par 100,
 *         sauf si divisible par 400.
 *
 * Exemple : is_leap_year(2000) -> true
 *           is_leap_year(1900) -> false
 *           is_leap_year(2001) -> false
 */
bool is_leap_year(int year) {
    
    if((year%4 == 00 && year%100!=0)|| (year%400 ==0) ){
        return true;
    }else{
        return false;
    }
    
    
}

/*
 * Renvoie true si n est premier, false sinon.
 *
 * Un nombre premier n'a que deux diviseurs : 1 et lui-même.
 * Attention : 1 n'est pas premier, 2 est premier.
 *
 * Exemple : is_prime(2)  -> true
 *           is_prime(4)  -> false
 *           is_prime(17) -> true
 */
bool is_prime(int n) {
    bool check_prime = false;
    if(n== 2 ){
        return true;
    }else if(n==1){
        return false;
    }else{
        //printf("#### n: %d\n",n);
        for(int i=2; i<n; i++){
            if(n%i==0){
                //printf("false numbres %d , i:%d\n",n,i);
                check_prime = false;
                return check_prime;
            }else{
                //printf("true numbres %d , i:%d\n",n,i);
                check_prime = true;
            }
            //printf("i :%d\n",i);
        }
        
    }
    return check_prime;
}
    // TODO
    // Indice : tester les diviseurs de 2 à racine de n.
    //          Pour éviter math.h, on peut tester div * div <= n.


/*
 * Demande une année à l'utilisateurice et affiche la réponse.
 */
void print_leap_year_check(void) {
    int year = 0;
    printf("Ecrivez une annee :");
    scanf("%d",&year);
    
    if(is_leap_year(year)){
        printf("L'année %d donnée est bissextile.",year);
    }else{
        printf("L'année %d donnée n'est pas bissextile.",year);
    }
    
    // TODO :
    //   - demander une année avec printf / scanf
    //   - afficher "N est bissextile." ou "N n'est pas bissextile."
}

/*
 * Affiche tous les nombres premiers strictement entre low et high.
 * Les bornes elles-mêmes ne sont pas affichées.
 */
void print_primes_between(int low, int high) {
    printf("primes number :");
    for(int i=(low+1); i<=(high-1); i++){
        if(is_prime(i)){
            printf(" %d ",i);
        }
    }
    printf("\n");
    
    // TODO :
    //   - boucler de low + 1 à high - 1
    //   - afficher chaque nombre premier suivi d'un espace
    //   - terminer par un retour à la ligne
}

#ifndef TP4_TEST
int main(void) {
    printf("=== Exercice 1 ===\n");
    
    print_leap_year_check();

    printf("\n=== Exercice 2 ===\n");
    int low, high;
    int input_error;
    do {
        input_error = 0;
        printf("Bornes basse et haute ? ");
        // scanf peut lire plusieurs valeurs en un seul appel.
        scanf("%d %d", &low, &high);
        if (low <= 2) {
            printf("La borne basse doit être plus grande que 2.\n");
            input_error = 1;
        }
        if (high <= low) {
            printf("La borne haute doit être plus grande que la borne basse.\n");
            input_error = 1;
        }
    } while (input_error);

    print_primes_between(low, high);

    return EXIT_SUCCESS;
}
#endif
