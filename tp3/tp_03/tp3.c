#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


/*
 * Tire un nombre au hasard entre 0 et max inclus.
 *
 * Exemple : draw_secret_number(10) peut renvoyer 0, 3, 10, ...
 */
int draw_secret_number(int max) {
    
    int secret_number = rand()%(max+1); 
    printf("Numbre max: %d\n", max);
    
    
    //test
    printf("Numbre secret:%d\n",secret_number);
    
    // Indice : rand() renvoie un grand nombre au hasard.
    //          Comment le ramener entre 0 et max ?
    return secret_number;
}

/*
 * Vérifie qu'une proposition est bien entre 0 et max inclus.
 * Renvoie 1 si elle est valide, 0 sinon.
 *
 * Exemple : is_valid_guess(5, 10)  -> 1
 *           is_valid_guess(-1, 10) -> 0
 *           is_valid_guess(11, 10) -> 0
 */
bool is_valid_guess(int guess, int max) {
    if (guess>=0 && guess<= max){
        printf("parfais");
        return true;
    }else{
        printf("il y a de soucis");
        return false;
    }
    
}

/*
 * Joue une partie complète avec un nombre secret entre 0 et max.
 * Affiche les réponses et, à la fin, le nombre de coups.
 */
void play_one_game(int max) {
    
    int nombre_secret = draw_secret_number(max);
    int nombre_propose=0;
    int number_tries = 0;
    printf("essay\n");
    do{
        printf("Votre proposition:");
        scanf("%d",&nombre_propose);
        
        if (nombre_propose >max ){
            printf("Le nombre est supérieur à la valeur maximale indiquée\n");
        }else if(nombre_propose < 0){
            printf("Le nombre doit être supérieur ou égal à 0\n");
        }
        else if(nombre_propose > nombre_secret){
            printf("Trop grand!\n");
            number_tries++;
        }else if(nombre_propose < nombre_secret){
            printf("Trop petit!\n");
            number_tries++;
        }else{
            printf("Trouvé en %d coups !",number_tries);
        }
    }while(nombre_propose != nombre_secret);
    // TODO :
    //   - tirer le nombre secret
    //   - boucler jusqu'à ce qu'il soit trouvé
    //   - ignorer les propositions hors bornes, sans les compter
    //   - afficher le nombre de coups à la fin
}


int optimal_attempts(int max) {
    
    int log_result = 1;
    int attempts_count=0;
    
    log_result =(int)log2((double)max+1);
    attempts_count = log_result+1;
    
    
    return attempts_count;
}

int ordinateur_devine(int max){
    //int trie = rand()%(max+1); 
    
    char reponse ;
    int number_start = 0;
    int number_end  =0;
    bool check = true;
    int number_propose= 0;
    if(max%2 == 1){
        number_propose= (max +1)/2;
    }else{
        number_propose = max/2;
            }
     
            
    printf("Numbres dans ton tete : %d\n", number_propose);
    //// The space before %c skips the newline ('\n') character from the Enter key.
    scanf(" %c",&reponse);
    printf("klavyeden girilen deger %c",reponse);
    do{
        printf("test1\n");
        switch(reponse){
        case '<':
            printf("kucuktur\n");
            number_start = number_propose;
            
            number_propose = number_end -number_start;
            if(number_propose%2 == 1){
                number_propose= number_propose +1;
                number_propose = number_propose/2+number_start;
            }else{
                number_propose = number_propose/2+number_start;
            }
             printf("onerilen sayi %d, sayinin sonu %d, sayinin basi %d",number_propose,number_end,number_start);
            printf("Numbres dans ton tete : %d\n", number_propose);
            scanf(" %c",&reponse);
            break;
        case '>':
            printf("buyuktur\n");
            number_end = number_propose;
            number_propose = number_end -number_start;
            if(number_propose%2 == 1){
                number_propose= number_propose +1;
                number_propose = number_propose/2+number_start;
            }else{
                number_propose = number_propose/2+number_start;
            }
            printf("onerilen sayi %d, sayinin sonu %d, sayinin basi %d",number_propose,number_end,number_start);
            printf("Numbres dans ton tete : %d\n", number_propose);
            scanf(" %c",&reponse);
            break;
        case '=':
            
            printf("Felicitations\n");
            check = false;
            break;
        }
        
    }while(check);
    return number_propose;
}


#ifndef TP3_TEST
int main(void) {

    int max;
    
    printf("Vous voulez générer des nombres jusqu’à combien ? \n");
    scanf("%d",&max);
    
    
    is_valid_guess(draw_secret_number(max),max);
    
    printf("Le nombre choisi est %d\n", ordinateur_devine(max));
    
    
	// - demander le nombre maximum 

    mak//play_one_game(max);
    printf("test: %d",optimal_attempts(max));

    return EXIT_SUCCESS;
}
#endif
