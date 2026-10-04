#include <stdio.h>
#include <stdlib.h>




/*
Rédigez un algorithme pour calculer la moyenne d’un tableau de notes --> moyenne_tableau 

Trouver la valeur minimale contenue dans un tableau et l'indice de l'élément le plus petit.--> valeur_minimal_et_indice

Trier un tableau par ordre croissant. --> 
*/

// moyenne tableau 
float moyenne_tableau(float notes[], int taille ){
    
    float somme = 0;
    
    for(int i=0 ; i<taille ;i++){
        
        somme = somme +notes[i];
        
    }
    
    printf("La resultat de notes moyenne &&&: %f\n",somme/taille);
    return somme/taille;
}

// valeur minimal et indice 
struct Result {
    float min;
    int index;
};

struct Result valeur_minimal_et_indice(float tableau[], int taille ){
    
    struct Result result ;
    result.index = 0;
    result.min = tableau[0];
    
    for (int i= 1 ; i<taille ; i++){
        
        if(result.min> tableau[i]){
            result.min = tableau[i];
            result.index = i;
        }
    }
    return result;
}
// Tableau par ordre croissant 

void trier_croissant (int tableau[], int taille){
    
    int valuer_min= tableau[0];
    int referans_min = 0 ; 
    
    
    for (int i = 0 ; i<taille; i++){
        
        for (int k=i; k< taille ;k++){
            
            valuer_min = tableau[i];
            
            if(valuer_min>tableau[k]){
            
            valuer_min = tableau[k];
            referans_min = k;
            //printf("valeur_min &&&&&&: %d\n", valuer_min);
            
            //printf("tableux in indexi : %d\n", i);
            tableau[k]= tableau[i];
            tableau[i]= valuer_min;
            //printf("degiismden sonra kucuk sayi numeros[k]:%d\n", tableau[k]);
            //printf("degiisimden sonra buyuk sayi numeros[i]:%d\n",tableau[i]);
            
            }
        
        //printf("%d est inférieur à %d\n", tableau[i], tableau[k]);
        //printf("%d doit être placé avant \n", tableau[i]);
        //printf("%d doit etre place apres\n ", tableau[k]);
        
        }
    
    }
    for(int i = 0 ;i <taille; i++){
        
        printf("La valeur dans l’indice n[%d]: %d \n",i,tableau[i]);
        
    }
}
int main(){

    float notes_mat[]= {4.5, 5, 3.5, 4, 5.5, 6, 4.5, 3, 5, 4};
    int notes[]= {4, 5, 3, 4, 5, 6, 4, 3, 5, 4};
    int numeros []= {7,3,9,2,5,-1,-9,23,45,-2,45,3};
     
    int taille_notes_mat = sizeof(notes_mat)/sizeof(notes_mat[0]); 
    int taille_numeros = sizeof(numeros)/sizeof(numeros[0]);
    
    printf("fonction calculer la moyenne d’un tableau de notes\n");
    printf("La resultat de notes moyenne : %f\n", moyenne_tableau(notes_mat,taille_notes_mat));
    
    printf("fonction la valeur minimale contenue dans un tableau et l'indice\n");
    struct Result consequence = valeur_minimal_et_indice(notes_mat,taille_notes_mat);
    printf("La valeur minimal %f et indice de ce valeur %d \n",consequence.min, consequence.index);
    
    
    trier_croissant(numeros,taille_numeros);
    
    
    
    return EXIT_SUCCESS ;

}





