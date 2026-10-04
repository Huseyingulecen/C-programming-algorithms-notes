#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool est_premier (int nombre){
    int i = 2 ;
    while (i< nombre){
        if(nombre % i == 0){
           //printf("Le nombre  n`est pas premier %d \n ",nombre);
           return false;
        }
        i = i +1;

    }
    //printf("Le nombre est premier %d \n ",nombre);
    return true;
}


bool eratosthene (int nombre){

    int n = nombre+1;
//int *array = (int *)malloc(n * sizeof(int));
    
    bool *tableau_boolens = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++){
        tableau_boolens[i]= true;
    }
    tableau_boolens[0]= false ;
    tableau_boolens[1]= false; 
    

    for (int i=2; i<n; i++ ){
        if(tableau_boolens[i] == true){
            
            for(int j=i*i ; j<n ; j= j+i){
                 
                tableau_boolens[j]= false;
                //return false ;
            
            }
         }
     }


    for (int i=2; i<n; i++){
        if(tableau_boolens[i]){
            printf("%d   ",i);
        }
    }
    free(tableau_boolens);
    
}
int main(){


    int nombre = 0; 
    printf("Entrez un nombre : \n");
    scanf("%d", &nombre);

/*
    if (est_premier(nombre)){
     printf("%d n`est pas premier  \n ",nombre);
    }
    else {
     printf("%d n`est pas premier  \n ",nombre);
    }
*/

    eratosthene(nombre);




   return EXIT_SUCCESS;


}
