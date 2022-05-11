//
// Created by radol on 06/04/2022.
//

#include "TAKUZU.h"

void creer_tableau_vierge(int *grille_jeu[TAILLE][TAILLE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            *grille_jeu[i][j] = -1;
        }
    }
/*
    srand(time(NULL));
    for (int i = 0 ; i < 6 ; i++)
    {
        int pos1, pos2;
        pos1 = rand() % (TAILLE + 1);
        pos2 = rand() % (TAILLE + 1);
        grille_jeu[pos1][pos2] = tab[pos1][pos2];
    }
*/

}

void saisir_valeurs(int tab[TAILLE][TAILLE]) {
    int val = 2;
    int lig, col;
    printf("Quelle valeur souhaitez vous saisir dans le jeu :\n");
    scanf("%d", &val);
    while (val > 1 || val < 0) {
        printf("La valeur doit etre 0 ou 1 :\n");
        scanf("%d", &val);
    }
    printf("Indiquez le ligne puis la colonne de la valeur a ajouter :\n");
    scanf("%d %d", &lig, &col);

    tab[lig][col] = val;
}


/*void creer_tab_dyn(int** *matrice, int size)
{
    *matrice = (int**) malloc(size*sizeof(int*));
    for (int i = 0; i < size ; ++i)
    {
        *(*matrice + i) = (int*) malloc(size*sizeof(int*));
    }

    for (int i = 0; i < TAILLE; ++i)
    {
        for (int j = 0; j < TAILLE; ++j)
        {
            *matrice[i][j] = -1;
        }
    }
*/

