#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// is_present qui vérifie si un nombre est présent dans un tableau trié par ordre croissant.

bool is_present(int n, int tab[], int element){
    for(int i=0; i<n; i++){
        if(tab[i]==element){
            //printf("test1\n");
            return true;
        }else if (element<tab[i]){
            //printf("test2\n");
            return false;
        }
    }
    //printf("test3\n");
    return false;
}


//La recherche dichotomique, binary search


bool is_present_binary_search(int n,int tab[], int element){
    
    int left=0;
    int right = n-1;
    
    while(left<=right){
        
        int mid = (right+left)/2;
        
        if(tab[mid]<element){
            left=mid+1;
        }else if(tab[mid]>element){
            right = mid-1;
        }else{
            return true;
        }
    }
    return false;
}

//En étudiant les tableaux, j’ai vu que la fonction de tri provenait du fichier slide_tableaux.c.

void sorted_list(int tab[], int taille){
    
    int valeur_min=0;
    
    for(int i=0; i<taille; i++){
        valeur_min = tab[i];
        for(int h=i; h<taille; h++){
            if(tab[i]>tab[h]){
                valeur_min = tab[h];
                tab[h]=tab[i];
                tab[i]=valeur_min;
                
            }
        }
    }
}

int main(){
	printf("hello \n");
    
    int nombres[9]= {13,12,11,10,1,2,3,5,8};
    int taille = sizeof(nombres)/sizeof(nombres[0]);
    
    sorted_list(nombres,taille);
    //printf("nombres[4]=%d\n",nombres[4]);
    
    printf("Utilisation de la fonction is_present:\n");
    printf("Résultat de la vérification de la présence du nombre %d \n",is_present(taille,nombres,5));
    
    printf("Utilisation de la fonction is_present_binary_search:\n");
    printf("Résultat de la vérification de la présence du nombre %d \n",is_present(taille,nombres,15));

	return EXIT_SUCCESS;

}


