#include "TAKUZU.h"

int main() {

    int tab[TAILLE][TAILLE] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
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

    //saisir_valeurs(&tab);

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

    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    int coup_valide = valider_un_coup_unique(tab, lig, col);
    if (coup_valide == 1)
        printf("\nLe coup est bon");
    else
        printf("\nLe coup est faux");

    /*
// Adrien
    //int t[TAILLE][TAILLE] = { {1,-1,-1,-1}, {-1,-1,1,-1}, {0,-1,1,0}, {-1,1,-1,-1} };
    // int t[TAILLE][TAILLE] = { {-1,0,0,-1,0,-1,-1,1}, {-1,-1,-1,-1,0,0,-1,1}, {-1,-1,0,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1,-1,-1}, {0,0,-1,-1,1,0,-1,-1}, {-1,-1,-1,-1,-1,-1,0,1}, {1,-1,0,0,-1,-1,1,-1}, {-1,1,1,-1,-1,0,-1,-1}};
    int t[TAILLE][TAILLE] = { {-1,1,0,-1,-1,-1}, {-1,-1,1,-1,-1,-1}, {-1,-1,-1,-1,0,0}, {1,-1,-1,-1,-1,-1}, {-1,-1,-1,1,-1,0}, {-1,-1,-1,-1,-1,-1}};
    int conte = 0, pose = 0, tab_t[TAILLE*TAILLE][TAILLE][TAILLE],tab_n[TAILLE*TAILLE], ch = 0, tab_parfait[TAILLE*TAILLE][TAILLE][TAILLE];
    for (int b = 0; b<TAILLE*TAILLE; b++){
        tab_n[b] = 0;
    }
    for (int a = 0; a<TAILLE*TAILLE; a++){
        for (int b = 0; b<TAILLE; b++){
            for (int c = 0; c<TAILLE; c++){
                tab_t[a][b][c] = 0;
            }
        }
    }
    for (int a = 0; a<TAILLE*TAILLE; a++){
        for (int b = 0; b<TAILLE; b++){
            for (int c = 0; c<TAILLE; c++){
                tab_parfait[a][b][c] = 0;
            }
        }
    }
    // if (valider_un_coup(t)){
    // printf("juste");
    // } else {
    // printf("faux");
    // }
    afficher_tableau(t);
    recurence_cree_tableau_AI(t, conte, pose, tab_t, tab_n, ch, tab_parfait);
    afficher_tableau(t);
    printf("##########################\n");
    for (int i = 0; i <ch+1; i++){
        afficher_tableau(tab_parfait[i]);
    }
    return 0;*/
}