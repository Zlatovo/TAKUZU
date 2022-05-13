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

    int TAILLE = 16, **t, ch = 0, ***tab_parfait;

    //int ex[TAILLEL][TAILLEL] = { {0,0,-1,0,-1,-1}, {-1,0,-1,-1,-1,0}, {-1,-1,-1,1,-1,-1}, {1,-1,0,-1,-1,-1}, {-1,-1,-1,-1,-1,1}, {-1,-1,-1,-1,1,-1}};
    //int ex[TAILLEL][TAILLEL] = { {1,-1,-1,-1}, {-1,-1,1,-1}, {0,-1,1,0}, {-1,1,-1,-1} };
    //int ex[TAILLEL][TAILLEL] = {{0,-1,-1,0,-1,-1,0,-1},{-1,-1,-1,-1,1,-1,-1,1},{-1,-1,-1,0,-1,-1,-1,-1},{-1,-1,-1,-1,0,-1,-1,0},{-1,-1,-1,-1,-1,1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1},{0,-1,-1,0,-1,-1,-1,-1},{0,-1,-1,-1,-1,0,0,-1}};
    int ex[TAILLEL][TAILLEL] = {{-1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},{-1, 1, 1, -1, -1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0},{-1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1},{-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1},{-1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1},{-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1},{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 1, -1},{1, -1, 1, -1, -1, -1, -1, -1, 1, -1, -1, 0, -1, -1, -1, -1},{1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1},{-1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, 0, -1, -1},{-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 1},{-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 1},{-1, -1, -1, 0, 0, -1, -1, -1, 0, -1, -1, 1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1},{-1, 0, 0, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 0, 0, -1}};
    // cree espase pour t

    t=(int**)malloc(TAILLE * sizeof(int*));
    for (int i = 0; i<TAILLE; i++){
        /*allocation d'un tableau de tableau*/
        t[i]= (int *) calloc ( TAILLE, sizeof(int) );
    }

    // cree espase pour tab_parfait
    tab_parfait = (int***)malloc(TAILLE*TAILLE * sizeof(int*));
    for (int i = 0; i<TAILLE*TAILLE; i++){
        tab_parfait[i] = (int**)malloc(TAILLE * sizeof(int*));
        for (int j = 0; j<TAILLE; j++){
            tab_parfait[i][j] = (int *) calloc ( TAILLE, sizeof(int));
        }
    }

    //remplire t avec exemple
    for (int i = 0; i<TAILLE; i++){
        for (int j = 0; j<TAILLE; j++){
            t[i][j] = ex[i][j];
        }
    }


    afficher_tableau(t, TAILLE);


    trouver_tous_les_solution(t,tab_parfait, &ch, TAILLE);
    printf("la/les solution(s) est/sont :\n\n");
    for (int i = 0; i <ch; i++){
        afficher_tableau(tab_parfait[i], TAILLE);
        printf("\n");
    }

    return 0;
}