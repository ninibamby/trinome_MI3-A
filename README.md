# Projet FlipTech — Trinôme MI3-A

Projet réalisé en langage C sous Linux.

---

# Règles du jeu

Chaque joueur peut choisir :

- `1` → Piocher une carte
- `2` → Arrêter son tour et conserver ses points

Si un joueur pioche une carte déjà présente dans sa main :

- il perd les points de la manche
- son tour se termine immédiatement

Si un joueur obtient 7 cartes différentes :

- il réalise un Flip 7
- la manche se termine immédiatement

La partie se termine lorsqu’un joueur atteint 200 points ou lorsque la pioche est vide.

---

## Installation et lancement

### Cloner le projet depuis GitHub

```bash
git clone LIEN_DU_GITHUB
```

### Entrer dans le dossier du projet

```bash
cd FlipTech
```

### Compiler le projet

```bash
make
```

### Lancer le jeu

```bash
./FlipTech
```

### Nettoyer les fichiers compilés

```bash
make clean
```

---

## Organisation du projet

```text
FlipTech
 ┣ src
 ┃ ┣ main.c
 ┃ ┣ carte.c
 ┃ ┣ joueur.c
 ┃ ┣ partie.c
 ┃ ┗ affichage.c
 ┃
 ┣ include
 ┃ ┣ carte.h
 ┃ ┣ joueur.h
 ┃ ┣ partie.h
 ┃ ┗ affichage.h
 ┃
 ┣ Makefile
 ┗ README.md
```

---

# Compilation utilisée

- GCC
- Linux
- Options de compilation :

```bash
-Wall -Wextra -Iinclude
```

---

# Fonctionnalités

- Gestion des joueurs
- Gestion des cartes
- Mélange de la pioche
- Détection des doublons
- Calcul des scores
- Sauvegarde des scores dans un fichier texte
- Affichage couleur dans le terminal

---

# Membres du projet

- PAYET Nino
- GIL-THELIER Valentin
- Nom Prénom
