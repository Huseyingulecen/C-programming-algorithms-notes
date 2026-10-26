#include <stdio.h>
#include <stdlib.h>

typedef struct fraction{
    int num;
    int denom;
}Fraction;

Fraction fraction_add(Fraction f1,Fraction f2){
    Fraction f3;
    
    f3.num = f1.num*f2.denom +f2.num*f1.denom;
    
    f3.denom = f1.denom*f2.denom;
    
    return f3;

}



int main(){
    
    Fraction number1;
    Fraction number2;
    Fraction resultat;
    
    number1.num=3;
    number1.denom=7;
    
    number2.num=11;
    number2.denom=13;
    
    resultat= fraction_add(number1,number2);
    
    
    
	printf("nom: %d denom: %d\n",resultat.num,resultat.denom);

	return EXIT_SUCCESS;

}
