#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
    
    int tableau[50][100];
    srand(time(0));
    
    for(int i=0; i<50; i++){
        for(int k=0; k<100;k++){
            
            tableau[i][k]= rand()%256;
        }
    }
    
    for(int i=0; i<50; i++){
        for(int k=0; k<100;k++){
            
            printf("%d ",tableau[i][k]);
            
        }
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}
