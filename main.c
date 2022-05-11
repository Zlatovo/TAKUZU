#include "TAKUZU.h"

int main() {

    //int tab[TAILLE][TAILLE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
/*  //
    //int matrice[TAILLEL][TAILLEL];
    //creer_tableau_vierge(&matrice[TAILLEL][TAILLEL], TAILLEL);
    //
    //for (int i = 0; i < TAILLEL; ++i) {
    //    for (int j = 0; j < TAILLEL; ++j) {
    //        printf("%d ", matrice[i][j]);
    //    }
    //}*/
    //
    //for (int i = 0; i < TAILLE; ++i) {
    //    for (int j = 0; j < TAILLE; ++j) {
    //        printf("%d ", tab[i][j]);
    //    }
    //    printf("\n");
    //}
    //
    //saisir_valeurs(&tab);
    //
    //for (int i = 0; i < TAILLE; ++i) {
    //    for (int j = 0; j < TAILLE; ++j) {
    //        printf("%d ", tab[i][j]);
    //    }
    //    printf("\n");
    //}
// Adrien
    //int t[TAILLEL][TAILLEL] = { {1,-1,-1,-1}, {-1,-1,1,-1}, {0,-1,1,0}, {-1,1,-1,-1} };
    // int t[TAILLEL][TAILLEL] = { {-1,0,0,-1,0,-1,-1,1}, {-1,-1,-1,-1,0,0,-1,1}, {-1,-1,0,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1,-1,-1}, {0,0,-1,-1,1,0,-1,-1}, {-1,-1,-1,-1,-1,-1,0,1}, {1,-1,0,0,-1,-1,1,-1}, {-1,1,1,-1,-1,0,-1,-1}};
    int t[TAILLEL][TAILLEL] = { {-1,1,0,-1,-1,-1}, {-1,-1,1,-1,-1,-1}, {-1,-1,-1,-1,0,0}, {1,-1,-1,-1,-1,-1}, {-1,-1,-1,1,-1,0}, {-1,-1,-1,-1,-1,-1}};
    int conte = 0, pose = 0, tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL],tab_n[TAILLEL*TAILLEL], ch = 0, tab_parfait[TAILLEL*TAILLEL][TAILLEL][TAILLEL];
    for (int b = 0; b<TAILLEL*TAILLEL; b++){
        tab_n[b] = 0;
    }
    for (int a = 0; a<TAILLEL*TAILLEL; a++){
        for (int b = 0; b<TAILLEL; b++){
            for (int c = 0; c<TAILLEL; c++){
                tab_t[a][b][c] = 0;
            }
        }
    }
    for (int a = 0; a<TAILLEL*TAILLEL; a++){
        for (int b = 0; b<TAILLEL; b++){
            for (int c = 0; c<TAILLEL; c++){
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
    recurence_cree_tableau_AI(t, conte, pose, tab_t, tab_n, &ch, tab_parfait);
    printf("la/les solution(s) est/sont :\n\n");
    for (int i = 0; i <ch; i++){
        afficher_tableau(tab_parfait[i]);
        printf("\n");
    }
    return 0;
}