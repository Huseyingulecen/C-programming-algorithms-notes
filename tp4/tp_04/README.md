---
subtitle: TP 4 – Les structures de contrôle, suite…
---

# Buts

* Écrire des fonctions booléennes
* Combiner des conditions avec `&&`, `||`, `!`
* Utiliser des boucles imbriquées

# Exercice 1 – Années bissextiles

Une année est bissextile si :

* elle est divisible par 4 ;
* mais pas par 100 ;
* sauf si elle est aussi divisible par 400.

Ainsi 2001 n'est pas bissextile, 2000 l'est, 1900 ne l'est pas.

Le programme demande une année à l'utilisateurice et répond si elle
est bissextile ou non.

Exemple :

```
Quelle année ? 1900
1900 n'est pas bissextile.
```

# Exercice 2 – Nombres premiers

Un nombre est premier s'il n'a que deux diviseurs distincts : 1 et
lui-même.

Le programme demande une borne basse et une borne haute, puis affiche
tous les nombres premiers strictement compris entre les deux.

Exemple :

```
Bornes basse et haute ? 59 99
61 67 71 73 79 83 89 97
```

# Fichiers

* `tp4.c` – votre programme. C'est le seul fichier que vous modifiez.
* `tp4_tests.c` – les tests automatiques. Ne le modifiez pas.
* `Makefile` – pour compiler, lancer et tester.

# Commandes

```
make          compile votre programme
make run      compile puis lance le programme
make test     compile et lance les tests
make clean    supprime les fichiers générés
```

# À faire

Ouvrez `tp4.c`. Il contient cinq fonctions. `main()` est déjà écrite :
ne la modifiez pas. Complétez les quatre autres, repérées par des
commentaires `TODO` :

* `is_leap_year(year)` – renvoie 1 si `year` est bissextile, 0 sinon.
* `is_prime(n)` – renvoie 1 si `n` est premier, 0 sinon.
* `print_leap_year_check()` – demande une année et affiche la réponse.
* `print_primes_between(low, high)` – affiche les nombres premiers
  strictement entre `low` et `high`.

Travaillez une fonction à la fois : écrivez-la, lancez `make test`,
regardez quels tests passent, puis passez à la suivante. Les tests
sont là pour vous guider, pas pour vous piéger.

# Pièges à éviter

* Une année divisible par 100 n'est pas bissextile, **sauf** si elle
  est divisible par 400. L'ordre des conditions compte.
* 1 n'est pas premier. 2 est premier. Réfléchissez à ce que votre
  boucle fait pour ces deux cas.
* Dans `is_prime`, `div * div <= n` évite d'appeler `sqrt()`. Les deux
  marchent, mais la première ne demande pas `math.h`.
* L'énoncé dit « strictement entre les bornes ». `low` et `high` ne
  sont pas affichés, même s'ils sont premiers.
* `scanf("%d %d", &low, &high)` attend **deux** nombres sur la même
  ligne, séparés par un espace ou une tabulation, puis Entrée :
  `59 99`. Si vous tapez un seul nombre, une virgule (`59, 99`), ou
  du texte, le programme peut boucler ou lire des valeurs fausses.
  C'est une limite de `scanf`, pas de votre code.

# Avant de rendre

* `make test` affiche tous les tests au vert.
* Le programme fonctionne avec des bornes proches (`59 61`).
* Le programme fonctionne avec un intervalle vide (`10 11`).
* Les bornes invalides (basse ≤ 2, ou haute ≤ basse) affichent un
  message et redemandent.

# Bonus (facultatif)

Ces deux exercices sont indépendants.

## Crible d'Ératosthène

Pour afficher les nombres premiers d'un intervalle, on peut tester
chaque nombre un par un (ce que fait `is_prime`). Il existe une
méthode plus rapide : le crible d'Ératosthène.

Écrivez une fonction `print_primes_sieve(low, high)` qui utilise un
tableau de booléens pour marquer les multiples. Comparez le nombre
d'opérations avec la version naïve sur un grand intervalle
(par exemple 2 à 100000).

Indice : `bool composite[high + 1];` puis marquer les multiples de 2,
de 3, de 5, etc.

## Entrées robustes

`scanf` a un défaut : si l'utilisateurice tape autre chose qu'un
nombre, le programme peut partir en boucle infinie. Écrivez une
fonction `read_int()` qui :

* lit un entier avec `scanf` ;
* si la lecture échoue, vide le tampon (regardez `getchar`) ;
* redemande tant que l'entrée n'est pas valide.

Utilisez-la pour lire les bornes, puis testez en tapant `abc`, `59,99`,
et une ligne vide.
