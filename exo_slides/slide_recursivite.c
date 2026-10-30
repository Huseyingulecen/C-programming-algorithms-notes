#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n<=1){
        return 1;
        
    }
    printf("n:%d\n",n);
    return n*factorial(n-1);
}

int length(char str[], int i){
    if(str[i]=='\0'){
        return i;
    }
    printf("i: %d\n",i);
    return length(str,i+1);
}

int lenght2(char str[]){
    if(str[0]=='\0'){
        return 0;
    }
    
    return 1+lenght2(str+1);
}

void nombre_decimal (int n){
    if(n/2!=0){
        printf("Test if valeur n :%d\n",n);
        nombre_decimal(n/2);
    }
    printf("test valeur n: %d\n",n);
    
    printf(" %d ",n%2);
    
    // buradda sayi 10 dan 2 ye gitmesini beklerken neden 2 den 10 a gidiyor ????
}

int fibonacci(int n){
    int fib0=0;
    int fib1=1;
    
    int fib = (n==0)? fib0:fib1;
    
    for(int i= 2; i<=n; i++){
        
        fib= fib0+fib1;
        fib0=fib1;
        fib1=fib;
    }
    return fib;
}

int fibonacci_recursif(int n){
    if(n<=1){
        return n ;
    }
    printf("Valeur n : %d\n",n);
    return fibonacci_recursif(n-1)+fibonacci_recursif(n-2);
}

int main(){
    
    //Appel de la fonction factorial
    //int fac = factorial(5);
    //printf("fac valuer:%d",fac);
    
    ////Appel de la fonction lenght
    //char hello[] = "Hello World!";
    
    //int size = length(hello,11);
    //printf("Length: %d\n",size);
    
    ////Appel de la fonction lenght2
    //char name[]= "William";
    
    //int size2 = lenght2(name);
    //printf("Length: %d\n",size2);
    
    ////Appel de la fonction nombre_decimal
    // burada bir soru var 
    nombre_decimal(10);
    
    ////Appel de la fonction fibonacci
    
    //int valeur_fib = fibonacci(7);
    //printf("Valeur de la fonction: %d",valeur_fib);
    
    ////Appel de la fonction fibonacci_recursif
    
    int valeur_fib = fibonacci_recursif(7);
    printf("Valeur de la fonction: %d",valeur_fib);
    
    
    
    return EXIT_SUCCESS;
}


