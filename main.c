#include "TAKUZU.h"

int main() {

    int tab[TAILLE][TAILLE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
/*
    int matrice[TAILLE][TAILLE];
    creer_tableau_vierge(&matrice[TAILLE][TAILLE], TAILLE);

    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            printf("%d ", matrice[i][j]);
        }
    }*/

    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    saisir_valeurs(&tab);

    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
