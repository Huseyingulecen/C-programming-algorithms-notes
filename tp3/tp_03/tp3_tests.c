/*
 * tp3_tests.c – Tests automatiques pour le TP 3.
 *
 * Ne modifiez pas ce fichier.
 *
 * Compile avec tp3.c via :
 *     make test
 */

#include <stdio.h>
#include <stdbool.h>

/* Les fonctions de tp3.c qu'on veut tester. */
int draw_secret_number(int max);
bool is_valid_guess(int guess, int max);

static int total = 0;
static int reussis = 0;

static void verifier(const char* nom, int condition) {
    total++;
    if (condition) {
        printf("  ok   %s\n", nom);
        reussis++;
    } else {
        printf("  FAIL %s\n", nom);
    }
}

static void test_draw(void) {
    int ok = 1;
    for (int i = 0; i < 100; i++) {
        int n = draw_secret_number(10);
        if (n < 0 || n > 10) ok = 0;
    }
    verifier("tirage dans les bornes", ok);

    verifier("max = 0 -> 0", draw_secret_number(0) == 0);

    /* Sur 100 essais entre 0 et 100, ça devrait varier. */
    int first = draw_secret_number(100);
    int varies = 0;
    for (int i = 0; i < 100; i++) {
        if (draw_secret_number(100) != first) varies = 1;
    }
    verifier("tirage varie", varies);
}

static void test_validity(void) {
    verifier("0 valide (max=10)",   is_valid_guess(0, 10)  == 1);
    verifier("10 valide (max=10)",  is_valid_guess(10, 10) == 1);
    verifier("5 valide (max=10)",   is_valid_guess(5, 10)  == 1);
    verifier("-1 invalide",         is_valid_guess(-1, 10) == 0);
    verifier("11 invalide",         is_valid_guess(11, 10) == 0);
    verifier("0 valide (max=0)",    is_valid_guess(0, 0)   == 1);
    verifier("1 invalide (max=0)",  is_valid_guess(1, 0)   == 0);
}

int main(void) {
    printf("Tests de tp3.c\n\n");

    printf("Tirage du nombre secret :\n");
    test_draw();
    printf("\n");

    printf("Validité des propositions :\n");
    test_validity();
    printf("\n");

    printf("%d test(s) réussi(s) sur %d.\n", reussis, total);
    return (reussis == total) ? 0 : 1;
}
