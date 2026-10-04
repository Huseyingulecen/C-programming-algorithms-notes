#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantite_de_argent= 0;

    printf("entrez une somme d'argent inférieure à 1 000 CHF \n");
    scanf ("%d",&quantite_de_argent);
    int mes_billets[] = {100, 50, 20, 10, 5, 2 ,1};
    int i = 0;
    do {
      
      if (quantite_de_argent/ mes_billets[i]!= 0){
        
        printf("on a %d biillet(s) de %d\n",quantite_de_argent/mes_billets[i], mes_billets[i]);
        quantite_de_argent = quantite_de_argent%mes_billets[i];
        }

      i++;
    } while(quantite_de_argent>!1000 && 0<quantite_de_argent);

    return EXIT_SUCCESS ;
}
