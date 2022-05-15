//
// Created by radol on 15/05/2022.
//
#include "TAKUZU.h"

int generer_lignes(int TAILLE) {

    int** line = malloc(sizeof(int*)*pow(2, TAILLE));
    for (int i = 0; i < pow(2, TAILLE); ++i) {
        line[i] = malloc(sizeof (int)*TAILLE);
    }

    int tab_sel[TAILLE], i, tab_inv[TAILLE], j, cptr = 0;
    int size = TAILLE;
    for (int nb = 1; nb < pow(2, TAILLE)+1; ++nb) {

        int nbr = nb;
        int tab_sel[10], i;

        for (i = 0; i < TAILLE; i++) {
            tab_sel[i] = nbr % 2;
            nbr = nbr / 2;
        }

        for (i = size - 1, j = 0; i >= 0; i--, j++)
            tab_inv[j] = tab_sel[i];

        for (i = 0; i < size; i++)
            tab_sel[i] = tab_inv[i];

        if (verif_ligne(tab_sel, TAILLE) == true) {
            for (int k = 0; k < TAILLE; ++k) {
                line[cptr][k] = tab_sel[k];
            }
            cptr += 1;
            printf("\nLe nombre binaire est = ");

            for (i = 0; i < TAILLE; i++) {
                printf("%d", tab_sel[i]);
            }
        }
    }
    return cptr;
}