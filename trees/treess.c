#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct node {
    int value;
    struct node* gauche; // Left child
    struct node* droit;  // Right child
};

// Function to create a new node
struct node* creerNoeud(int valeur) {
    struct node* nouveau = (struct node*)malloc(sizeof(struct node));
    nouveau->value = valeur;
    nouveau->gauche = NULL;
    nouveau->droit = NULL;
    return nouveau;
}

// Function to calculate the height of the tree
int hauteur(struct node *noeud) {
    if (noeud == NULL) {
        return -1; // Convention: height of an empty tree is -1
    }

    int hauteur_gauche = hauteur(noeud->gauche);
    int hauteur_droit = hauteur(noeud->droit);

    return 1 + (hauteur_gauche > hauteur_droit ? hauteur_gauche : hauteur_droit);
}

// Function to insert a node in the binary tree
struct node* inserer(struct node* racine, int valeur) {
    if (racine == NULL) {
        return creerNoeud(valeur);
    }

    if (valeur < racine->value) {
        racine->gauche = inserer(racine->gauche, valeur);
    } else {
        racine->droit = inserer(racine->droit, valeur);
    }

    return racine;
}

// Function to print the tree (in-order traversal)
void afficherArbre(struct node* racine) {
    if (racine != NULL) {
        afficherArbre(racine->gauche);
        printf("%d ", racine->value);
        afficherArbre(racine->droit);
    }
}

// Main function
int main() {
    int n, valeur;

    printf("Entrez le nombre de noeuds: ");
    scanf("%d", &n);

    struct node* racine = NULL;

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur du noeud %d: ", i + 1);
        scanf("%d", &valeur);
        racine = inserer(racine, valeur);
    }

    printf("Arbre (parcours in-order): ");
    afficherArbre(racine);
    printf("\n");

    printf("Hauteur de l'arbre: %d\n", hauteur(racine));

    return 0;
}
