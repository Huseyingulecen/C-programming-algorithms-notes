#include <stdio.h>

int main() {

    int nombre_fac= 0;

    printf("entrez un nombre entre 1 et 5 \n");
    scanf("%d", &nombre_fac);

    switch (nombre_fac){
        case 1:
            printf("factorile : 1\n");

            break;
        case 2:
            printf("factorile : 2\n");

            break;
        case 3:
            printf("factorile : 6\n");

            break;
        case 4:
            printf("factorile : 24\n");

            break;
        case 5:
            printf("factorile : 120\n");

            break;
        default:
            printf("Le programme ne peut pas calculer la factorielle de %d \n", nombre_fac);

    }
}

