#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>



	/*

Trier les deux chaînes est simple, mais pas très rapide. Une autre
méthode consiste à compter combien de fois chaque lettre apparaît
dans chaque chaîne, puis à comparer les deux comptages. Écrivez
`is_anagram_count(str1, str2)` avec cette méthode. Pour quels mots
les deux versions se comportent-elles différemment ?

*/

bool is_anagram_count(char str1[], char str2[]){
    
    char alphabet[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z'
};

    if(strlen(str1)== strlen(str2)){
        
        int size =strlen(str1);
        
        int counter_lettre_str1[26];
        int counter_lettre_str2[26];
        
        for(int i=0; i<26; i++){
            
            counter_lettre_str1[i]=0;
            counter_lettre_str2[i]=0;
        }
        
        
        for(int i= 0; i<size; i++){
            
            for(int k=0; k<26; k++){
            
            if(str1[i]==alphabet[k]){
                
                printf("test str1 %c\n",str1[i]);
                counter_lettre_str1[k]++;
            }
            if(str2[i]==alphabet[k]){
                printf("test str2 %c\n",str2[i]);
                counter_lettre_str2[k]++;
            }
            
            }
        }
        for(int i=0; i<26; i++){
            
            if(counter_lettre_str1[i]!=counter_lettre_str2[i]){
                return false ;
            }
        }
    }else{
        return false;
    }
    
    return true;
}

bool is_palindrome_inplace(char str[]){
    
    int size = strlen(str);
    int countdown = size;
    countdown--;
    
    for(int i=0; i<size; i++){
        if(str[i]!=str[countdown]){
            return false;
        }
        countdown--;
    }
    return true;
}
bool is_palindrome_case_normalized(char str[]){
    
    int size = strlen(str);
    for(int i=0; i<size; i++){
        
        str[i]=tolower(str[i]);
    }
    is_palindrome_inplace(str);
}

int main(){
    
    char test1[]="abe";
    char test2[]="acb";
    char test3[]="kayak";
    char test4[]= "Radar";
    
    
    printf("------Bonus 1------\n");
    if(is_anagram_count(test1,test2)){
        printf("yeaahhh\n");
    }else{
        printf("hop hop \n");
    }
    
    printf("------Bonus 2------\n");
    if(is_palindrome_inplace(test3)){
        printf("check is_palindrome_inplace yeaahhh\n");
    }else{
        printf("check is_palindrome_inplace hop hop \n");
    }
    
    printf("------Bonus 3------\n");
    
     if(is_palindrome_case_normalized(test4)){
        printf("check is_palindrome_inplace with case process yeaahhh\n");
    }else{
        printf("check is_palindrome_inplace with case process hop hop \n");
    }
    
    return EXIT_SUCCESS;
}
