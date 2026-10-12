/*
 * tp4_tests.c – Tests automatiques pour le TP 4.
 *
 * Ne modifiez pas ce fichier.
 *
 * Compile avec tp4.c via :
 *     make test
 */

#include <stdio.h>
#include <stdbool.h>

/* Les fonctions de tp4.c qu'on veut tester. */
bool is_leap_year(int year);
bool is_prime(int n);

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

static void test_leap(void) {
    verifier("2000 bissextile",     is_leap_year(2000) == 1);
    verifier("1900 pas bissextile", is_leap_year(1900) == 0);
    verifier("2001 pas bissextile", is_leap_year(2001) == 0);
    verifier("2024 bissextile",     is_leap_year(2024) == 1);
    verifier("2023 pas bissextile", is_leap_year(2023) == 0);
    verifier("1600 bissextile",     is_leap_year(1600) == 1);
    verifier("2100 pas bissextile", is_leap_year(2100) == 0);
    verifier("4 bissextile",        is_leap_year(4)    == 1);
    verifier("100 pas bissextile",  is_leap_year(100)  == 0);
    verifier("400 bissextile",      is_leap_year(400)  == 1);
}

static void test_prime(void) {
    verifier("1 pas premier",  is_prime(1)  == 0);
    verifier("2 premier",      is_prime(2)  == 1);
    verifier("3 premier",      is_prime(3)  == 1);
    verifier("4 pas premier",  is_prime(4)  == 0);
    verifier("5 premier",      is_prime(5)  == 1);
    verifier("9 pas premier",  is_prime(9)  == 0);
    verifier("17 premier",     is_prime(17) == 1);
    verifier("25 pas premier", is_prime(25) == 0);
    verifier("49 pas premier", is_prime(49) == 0);
    verifier("97 premier",     is_prime(97) == 1);
    verifier("0 pas premier",  is_prime(0)  == 0);
    verifier("-7 pas premier", is_prime(-7) == 0);
}

int main(void) {
    printf("Tests de tp4.c\n\n");

    printf("Années bissextiles :\n");
    test_leap();
    printf("\n");

    printf("Nombres premiers :\n");
    test_prime();
    printf("\n");

    printf("%d test(s) réussi(s) sur %d.\n", reussis, total);
    return (reussis == total) ? 0 : 1;
}
