---
subtitle: TP 3 – Le nombre secret
---

# Buts

* Introduction au langage C
* Fonctions, boucles, conditions, entrées-sorties
* Nombres pseudo-aléatoires

# Le jeu

L'ordinateur choisit un nombre secret. Vous devez le deviner.

À chaque essai, l'ordinateur vous dit si votre nombre est **trop petit**
ou **trop grand**. Quand vous trouvez, le programme affiche le nombre
de coups qu'il vous a fallu.

Exemple :

```
Nombre maximum ? 100
Votre proposition : 50
Trop petit.
Votre proposition : 75
Trop grand.
Votre proposition : -3
Le nombre doit être supérieur ou égal à 0.
Votre proposition : 62
Trop petit.
Votre proposition : 68
Trouvé en 4 coups !
```

# Fichiers

* `tp3.c` – votre programme. C'est le seul fichier que vous modifiez.
* `tp3_tests.c` – les tests automatiques. Ne le modifiez pas.
* `Makefile` – pour compiler, lancer et tester.

# Commandes

```
make          compile votre programme
make run      compile puis lance le jeu
make test     compile et lance les tests
make clean    supprime les fichiers générés
```

# À faire

Ouvrez `tp3.c`. Il contient quatre fonctions. `main()` est déjà écrite :
ne la modifiez pas. Complétez les trois autres, repérées par des
commentaires `TODO` :

* `draw_secret_number(max)` – tire un nombre entre 0 et `max` inclus.
* `is_valid_guess(guess, max)` – dit si la proposition est dans
  l'intervalle `[0, max]`.
* `play_one_game(max)` – joue une partie complète.

Travaillez une fonction à la fois : écrivez-la, lancez `make test`,
regardez quels tests passent, puis passez à la suivante. Les tests
sont là pour vous guider, pas pour vous piéger.

Vous aurez besoin de ces fonctions :

| Fonction | Rôle |
|---|---|
| `printf` | afficher du texte |
| `scanf`  | lire une valeur au clavier |
| `rand`   | tirer un nombre au hasard |
| `srand`  | initialiser le générateur |
| `time`   | lire l'horloge système |

## Pièges à éviter

* `rand() % max` ne donne pas un nombre entre 0 et `max`. Que manque-t-il ?
* Sans `srand()`, le nombre secret est le même à chaque exécution.
  Vérifiez-le en lançant le jeu deux fois de suite.
* Une proposition hors de l'intervalle `[0, max]` affiche un message
  d'avertissement et **ne compte pas** comme un coup.
* Si `max` vaut 0, le nombre secret est 0. Le jeu doit quand même
  fonctionner.

## Points à vérifier

* Le nombre secret change à chaque exécution.
* Le jeu fonctionne avec `max = 0` et `max = 1`.
* Une proposition négative ou supérieure à `max` affiche un
  avertissement et ne compte pas.
* Le compteur affiché correspond aux propositions valides.
* `make test` affiche tous les tests au vert.

# Bonus (facultatif)

Ces deux exercices sont indépendants. Faites celui qui vous intéresse.

## Nombre de coups optimal

Si on joue de manière optimale, quel est le nombre maximal de coups
nécessaires pour trouver le nombre secret ? Écrivez une fonction
`optimal_attempts(max)` et affichez sa valeur à la fin de la partie.

## L'ordinateur devine

Échangez les rôles. L'utilisateurice pense à un nombre, l'ordinateur
propose, et l'utilisateurice répond avec `<`, `>` ou `=`.

```c
char reponse;
scanf(" %c", &reponse);  // l'espace avant %c est nécessaire
```

Implémentez au moins deux stratégies (dichotomie, recherche
exhaustive, aléatoire) et comparez le nombre de coups moyen.
