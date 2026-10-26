#include <stdio.h>
#include <stdlib.h>

void binaryNumbers(int numbers){
    
    
    int binarynum[32];
    int i =0;
    int count= -1;
    
    while(numbers>0){
        binarynum[i]= numbers%2;
        numbers = numbers/2;
        i++;
        count++;
    }
    printf("%d\n",count);
    printf("Binary numbre:");
    
    for(int i=count; i>=0 ; i--){
        printf("%d", binarynum[i]);
        
    }
    printf("\n");
}

int main(){
    
    binaryNumbers(247);
    

    return EXIT_SUCCESS ;

}
