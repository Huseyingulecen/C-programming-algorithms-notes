#include <stdio.h>
#include <stdlib.h>





//Implement factorial function from lecture slides pseudo-code
int factorielle(int n ){
    
    int i = 1;
    int fac =1;
    //printf("test1 :%d i:%d\n",n,i);
    while(i<=n){
    //printf("test2 :%d i:%d\n",n,i);
    
        fac = fac*i;
        i++;
    }
    printf("%d",fac);
    return fac;
}

int plus_petit_commun_multiple(int number1,int number2){
    
    
    int mult_num1 =number1;
    int mult_num2 =number2;
    
    while(mult_num2!=mult_num1){
        if(mult_num2>mult_num1){
            mult_num1=mult_num1+number1;
        }else{
            mult_num2=mult_num2+number2;
        }
    }
    return mult_num2;
}

int plus_grand_commun_diviseur(int number1, int number2){
    int divider =0;
    if(number1>number2){
        divider = number2;
    }else{
        divider=number1;
    }
    while(divider>=1){
        //printf("test1 \n");
        if(number1%divider==0 && number2%divider==0){
            return divider;
            //printf("test2\n");
        }else{
            divider = divider -1;
            //printf("test3\n");
        }
    }
    //printf("test4");
    return divider;
}



int main(){
    
    printf("--- pseudo-code 1 Factorial(N)---\n");
    
    int number=0;
    printf("Entrez un nomber\n");
    scanf("%d",&number);
    
    printf("factorial de %d=%d \n",number,factorielle(number));
    
    printf("--- Les deux nombres saisis seront utilisés pour calculer à la fois le PPCM et  le PGCD. ---\n");
    
    int number1=0;
    int number2=0;
    
    printf("Entrez deux nombers:\n");
    scanf("%d %d",&number1,&number2);
    
    printf("--- pseudo-code 2 PPCM Le Plus Petit Commun Multiple ---\n");
    
    printf("Le plus petit commun multiple de %d et %d est %d \n",number1,number2,plus_petit_commun_multiple(number1,number2));
    
    printf("--- pseudo-code 3 PGCD Le Plus Grand Commun Diviseur ---\n");
    
    printf("Le plus grand commun diviseur de %d et %d est %d \n",number1,number2,plus_grand_commun_diviseur(number1,number2));
    
    return EXIT_SUCCESS;

}


