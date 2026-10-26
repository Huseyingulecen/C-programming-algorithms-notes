---
subtitle: TP 6 – Le crible d’Ératosthène
---

# Crible d'Ératosthène

Le crible d'Ératosthène est une méthode permettant de générer les
nombres premiers de 2 à $N$ à l'aide d'une table de booléens. $N$ est
un nombre entier naturel.

Pour générer les nombres premiers inférieurs à $N$, on alloue un
tableau de $N$ booléens initialisé à `vrai`. Ainsi, l'état initial du
tableau est le suivant pour $N = 10$ (v = vrai, f = faux) :

| indice | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|--------|---|---|---|---|---|---|---|---|---|---|
| valeur | v | v | v | v | v | v | v | v | v | v |

Après exécution de l'algorithme, l'état du tableau est :

| indice | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|--------|---|---|---|---|---|---|---|---|---|---|
| valeur | v | v | v | v | f | v | f | v | f | f |

Le cas de 0 et 1 est particulier : ils ne sont pas premiers, mais on
les conserve dans le tableau par simplicité.

L'algorithme parcourt le tableau à partir de l'indice 2. Dès qu'il
tombe sur une case `vrai`, il parcourt tous les multiples de ce nombre
et les passe à `faux`. À la première itération, la case 2 est `vrai`,
et l'algorithme invalide 4, 6, 8, etc.

Une animation du processus est disponible
[sur Wikipédia](https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne).

Dans ce document, les exemples utilisent $N = 10$ pour que les
tableaux tiennent sur la page. Votre programme peut utiliser la
valeur que vous voulez pour `#define N`.

# Fichiers

* `tp6.c` – votre programme. C'est le seul fichier que vous modifiez.
* `tp6_tests.c` – les tests automatiques. Ne le modifiez pas.
* `Makefile` – pour compiler, lancer et tester.

# Commandes

```
make          compile votre programme
make run      compile puis lance le programme
make test     compile et lance les tests
make clean    supprime les fichiers générés
```

# Exercice 1

On travaille avec des tableaux statiques. La valeur de $N$ est définie
à la compilation avec `#define N 100` au début du programme.

Écrivez et utilisez la fonction suivante, qui écrit dans `tab` le
résultat du crible :

```c
void eratosthene(int n, bool tab[]);
```

Les éléments 0 et 1 sont ignorés, bien que présents dans le tableau.

Les `printf` ne doivent **pas** être dans `eratosthene()`. La fonction
applique l'algorithme mais n'affiche rien.

# Exercice 2

Cette fois, on stocke les nombres premiers comme valeurs d'un tableau
d'entiers. Pour $N = 10$, on veut :

| indice | 0 | 1 | 2 | 3 |
|--------|---|---|---|---|
| valeur | 2 | 3 | 5 | 7 |

Le tableau alloué a toujours $N$ cases, mais seules les `count`
premières sont utilisées. La représentation est plus compacte que
celle de l'exercice 1 : un entier par nombre premier, au lieu d'un
booléen par entier de 0 à $N - 1$.

L'exercice 2 est une transformation de l'exercice 1 : on reprend le
tableau de booléens produit par `eratosthene()` et on en extrait les
indices où la valeur est `vrai`. C'est pour cela que `eratosthene_2()`
doit appeler `eratosthene()` : elle n'a pas à refaire le crible, juste
à changer la représentation du résultat.

Écrivez et utilisez la fonction suivante, qui écrit dans `tab` les
nombres premiers inférieurs à `n` :

```c
int eratosthene_2(int n, int tab[]);
```

Elle renvoie le nombre de premiers trouvés et doit **obligatoirement**
utiliser `eratosthene()`.

Les `printf` ne doivent **pas** être dans `eratosthene_2()`.

# À faire

Ouvrez `tp6.c`. `main()` est déjà écrite : ne la modifiez pas.
Complétez les deux fonctions, repérées par des commentaires `TODO`.

Travaillez une fonction à la fois : écrivez-la, lancez `make test`,
regardez quels tests passent, puis passez à la suivante.

## Pièges à éviter

* `eratosthene_2` reçoit `n` en paramètre. Utilisez `n`, pas `N`,
  dans les boucles. Le tableau fait `n` cases, pas `N`.
* `eratosthene_2` doit appeler `eratosthene`. Ne réécrivez pas le
  crible deux fois.
* Dans `eratosthene`, la boucle externe va de 2 à `n - 1`. Les indices
  0 et 1 restent `vrai`, c'est normal.
* Dans `eratosthene`, on ne marque les multiples que si `tab[i]` est
  encore `vrai`. Sinon on fait du travail inutile.
* Les multiples d'un nombre `i` commencent à `2 * i`, pas à `i`.
* Tant que `eratosthene` n'est pas écrite, `tab` dans `main` n'est
  pas initialisé et le programme affiche des nombres arbitraires.
  C'est normal : ça disparaît dès que la fonction remplit le tableau.

## Points à vérifier

* `make test` affiche tous les tests au vert.
* `make run` affiche les nombres premiers deux fois — une fois par
  exercice. Les deux lignes doivent être identiques. Si elles
  diffèrent, l'une des deux fonctions a un bug.
* Le programme fonctionne si on change `#define N` en 2, 3, ou 20.

# Bonus (facultatif)

## Crible sans tableau auxiliaire

Dans `eratosthene_2`, la solution naturelle alloue un tableau de
booléens temporaire. Peut-on s'en passer ? Réfléchissez à une version
qui n'utilise qu'un seul tableau.

## Taille exacte

Le tableau de résultat dans l'exercice 2 a une taille `N`, mais on
n'utilise que les `count` premières cases. Écrivez une fonction
`shrink(int tab[], int count)` qui copie ces `count` premières valeurs
dans un nouveau tableau de taille exactement `count`. Pourquoi est-ce
plus difficile en C qu'en Python ou en Java ?
