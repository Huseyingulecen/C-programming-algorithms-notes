/*
 * tp6_tests.c – Tests automatiques pour le TP 6.
 *
 * Ne modifiez pas ce fichier.
 *
 * Compile avec tp6.c via :
 *     make test
 */

#include <stdio.h>
#include <stdbool.h>

/* Les fonctions de tp6.c qu'on veut tester. */
void eratosthene(int n, bool tab[]);
int eratosthene_2(int n, int tab[]);

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

/*
 * Vérifie que tab[0..n-1] contient exactement les valeurs attendues.
 */
static void verifier_tableau_bool(const char* nom, bool tab[], int n,
                                  const bool attendu[]) {
    total++;
    for (int i = 0; i < n; i++) {
        if (tab[i] != attendu[i]) {
            printf("  FAIL %s (indice %d : attendu %d, obtenu %d)\n",
                   nom, i, attendu[i], tab[i]);
            return;
        }
    }
    printf("  ok   %s\n", nom);
    reussis++;
}

/*
 * Vérifie que tab[0..count-1] contient exactement les valeurs attendues.
 */
static void verifier_tableau_int(const char* nom, int tab[], int count,
                                 const int attendu[], int attendu_count) {
    total++;
    if (count != attendu_count) {
        printf("  FAIL %s (count attendu %d, obtenu %d)\n",
               nom, attendu_count, count);
        return;
    }
    for (int i = 0; i < count; i++) {
        if (tab[i] != attendu[i]) {
            printf("  FAIL %s (indice %d : attendu %d, obtenu %d)\n",
                   nom, i, attendu[i], tab[i]);
            return;
        }
    }
    printf("  ok   %s\n", nom);
    reussis++;
}

static void test_eratosthene(void) {
    /* n = 10 : les seuls premiers sont 2, 3, 5, 7. */
    bool tab[10] = { false };
    const bool attendu[10] = {
        true, true, true, true, false, true,
        false, true, false, false
    };
    eratosthene(10, tab);
    verifier_tableau_bool("crible pour n = 10", tab, 10, attendu);

    /* n = 2 : tableau de 2 cases, 0 et 1 restent true. */
    bool tab2[2] = { false };
    const bool attendu2[2] = { true, true };
    eratosthene(2, tab2);
    verifier_tableau_bool("crible pour n = 2", tab2, 2, attendu2);

    /* n = 3 : 2 est premier. */
    bool tab3[3] = { false };
    const bool attendu3[3] = { true, true, true };
    eratosthene(3, tab3);
    verifier_tableau_bool("crible pour n = 3", tab3, 3, attendu3);

    /* n = 4 : 4 est marqué. */
    bool tab4[4] = { false };
    const bool attendu4[4] = { true, true, true, true };
    eratosthene(4, tab4);
    verifier_tableau_bool("crible pour n = 4", tab4, 4, attendu4);

    /* n = 5 : 4 est marqué. */
    bool tab5[5] = { false };
    const bool attendu5[5] = { true, true, true, true, false };
    eratosthene(5, tab5);
    verifier_tableau_bool("crible pour n = 5", tab5, 5, attendu5);

    /* n = 30 : vérification ciblée sur quelques indices. */
    bool tab30[30] = { false };
    eratosthene(30, tab30);
    verifier("29 premier dans le crible n = 30",     tab30[29] == true);
    verifier("28 pas premier dans le crible n = 30", tab30[28] == false);
    verifier("25 pas premier dans le crible n = 30", tab30[25] == false);
    verifier("23 premier dans le crible n = 30",     tab30[23] == true);
}

static void test_eratosthene_2(void) {
    /* n = 10 : attendu { 2, 3, 5, 7 }, count = 4. */
    int tab[10] = { 0 };
    const int attendu[4] = { 2, 3, 5, 7 };
    int count = eratosthene_2(10, tab);
    verifier_tableau_int("premiers pour n = 10", tab, count, attendu, 4);

    /* n = 2 : aucun premier strictement inférieur à 2. */
    int tab2[2] = { 0 };
    int count2 = eratosthene_2(2, tab2);
    verifier("count = 0 pour n = 2", count2 == 0);

    /* n = 3 : seul 2 est premier. */
    int tab3[3] = { 0 };
    const int attendu3[1] = { 2 };
    int count3 = eratosthene_2(3, tab3);
    verifier_tableau_int("premiers pour n = 3", tab3, count3, attendu3, 1);

    /* n = 30 : 10 premiers entre 2 et 29. */
    int tab30[30] = { 0 };
    int count30 = eratosthene_2(30, tab30);
    verifier("count = 10 pour n = 30", count30 == 10);
    verifier("premier de n = 30 est 2",  tab30[0] == 2);
    verifier("dernier de n = 30 est 29", tab30[9] == 29);

    /* n = 100 : 25 premiers entre 2 et 99. */
    int tab100[100] = { 0 };
    int count100 = eratosthene_2(100, tab100);
    verifier("count = 25 pour n = 100", count100 == 25);
    verifier("dernier premier < 100 est 97", tab100[24] == 97);
}

int main(void) {
    printf("Tests de tp6.c\n\n");

    printf("Exercice 1 – eratosthene :\n");
    test_eratosthene();
    printf("\n");

    printf("Exercice 2 – eratosthene_2 :\n");
    test_eratosthene_2();
    printf("\n");

    printf("%d test(s) réussi(s) sur %d.\n", reussis, total);
    return (reussis == total) ? 0 : 1;
}
