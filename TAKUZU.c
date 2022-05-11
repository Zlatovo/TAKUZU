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
        pos1 = rand() % (TAILLEL + 1);
        pos2 = rand() % (TAILLEL + 1);
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

    for (int i = 0; i < TAILLEL; ++i)
    {
        for (int j = 0; j < TAILLEL; ++j)
        {
            *matrice[i][j] = -1;
        }
    }
*/

// ############################################################################################
// Adrien

//
// Created by Adrie on 26/04/2022.
//

bool verifeiller_deux_ligne(int t1[TAILLEL], int t2[TAILLEL]){
    for (int i = 0; i<TAILLEL; i++){
        if (t1[i] != t2[i] || t1[i] == -1) {
            return true;
        }
    }
    return false;
}
bool valider_un_coup(int t[TAILLEL][TAILLEL]){
    //verifie que il n'y a pas trois fois le meme chifre et N0 = N1 = TAILLEL/2
    for (int l = 0; l<TAILLEL; l++){
        for (int c = 0; c<TAILLEL; c++){
            int conte_l = 0, conte_c = 0, con_c = 0, con_l = 0, val_l = t[l][0], val_c = t[0][c];
            for (int i = 0; i<TAILLEL; i++){
                //ligne
                if (t[l][i] == 1){
                    conte_l += 1;
                }
                if (t[l][i] != val_l || t[l][i] == -1){
                    con_l = 1; val_l = t[l][i];
                } else {
                    con_l ++;
                }
                //colone
                if (t[i][c] != -1){
                    conte_c += t[i][c];
                }
                if (t[i][c] != val_c || t[i][c] == -1){
                    con_c = 1; val_c = t[i][c];
                } else {
                    con_c ++;
                }

                //verifier
                if ((conte_l > TAILLEL/2) || (conte_c > TAILLEL/2) || (con_c == 3) || (con_l == 3)){
                    return false;
                }
            }
            //verifie que les ligne et colone sont diferante
            for (int i = 0; i<TAILLEL-1; i++){
                for (int j = i+1; j<TAILLEL; j++){
                    int conte= 0;
                    if (verifeiller_deux_ligne(t[i], t[j])){
                        for (int k = 0; k<TAILLEL; k++){
                            if (t[k][i] == t[k][j] && t[k][i] != -1){
                                conte ++;
                            }
                            if (conte == TAILLEL){
                                return false;
                            }
                        }
                    }else {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool tableau_plain(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL; i++) {
        for (int j = 0; j < TAILLEL; j++) {
            if (t[i][j] == -1) {
                return true;
            }
        }
    }
    return false;
}

void afficher_tableau(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL; i++){
        for (int j = 0; j<TAILLEL; j++){
            if (t[i][j] == -1){
                printf(" \t");
            } else {
                printf("%d\t", t[i][j]);
            }
        }
        printf("\n");
    }
}

void ajouter_ligne(int t[TAILLEL][TAILLEL], int val, int ligne){
    for (int i = 0; i<TAILLEL; i++){
        if (t[ligne][i] == -1){
            t[ligne][i] = val;
        }
    }
}
void ajouter_colone(int t[TAILLEL][TAILLEL], int val, int colone){
    for (int i = 0; i<TAILLEL; i++){
        if (t[i][colone] == -1){
            t[i][colone] = val;
        }
    }
}
void double_triple_tableau(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL; i++) {
        for (int j = 0; j < TAILLEL; j++) {
            //ligne 0110
            if (t[i][j] == 1 && t[i][j+1] == 1){
                if (j != 0 && t[i][j-1] == -1 ){
                    t[i][j-1] = 0;
                }
                if (j+1 != TAILLEL-1&& t[i][j+2] == -1){
                    t[i][j+2] = 0;
                }
            }
            //ligne 1001
            if (t[i][j] == 0 && t[i][j+1] == 0){
                if (j != 0 && t[i][j-1] == -1){
                    t[i][j-1] = 1;
                }
                if (j+1 != TAILLEL-1 && t[i][j+2] == -1){
                    t[i][j+2] = 1;
                }
            }
            //ligne 101
            if (t[i][j] == 1 && t[i][j+1] == -1 && t[i][j+2] == 1 && j+2 != TAILLEL && j+1 != TAILLEL){
                t[i][j+1] = 0;
            }
            //ligne 010
            if (t[i][j] == 0 && t[i][j+1] == -1 && t[i][j+2] == 0 && j+2 != TAILLEL && j+1 != TAILLEL){
                t[i][j+1] = 1;
            }
            //colone 1001
            if (t[j][i] == 1 && t[j+1][i] == 1){
                if (j != 0 && t[j-1][i] == -1){
                    t[j-1][i] = 0;
                }
                if (j+1 != TAILLEL-1 && t[j+2][i] == -1){
                    t[j+2][i] = 0;
                }
            }
            //colone 0110
            if (t[j][i] == 0 && t[j+1][i] == 0){
                if (j != 0 && t[j-1][i] == -1){
                    t[j-1][i] = 1;
                }
                if (j+1 != TAILLEL-1 && t[j+2][i] == -1){
                    t[j+2][i] = 1;
                }
            }
            //colone 101
            if (t[j][i] == 1 && t[j+1][i] == -1 && t[j+2][i] == 1 && j+2 != TAILLEL && j+1 != TAILLEL){
                t[j+1][i] = 0;
            }
            //colone 010
            if (t[j][i] == 0 && t[j+1][i] == -1 && t[j+2][i] == 0 && j+2 != TAILLEL && j+1 != TAILLEL){
                t[j+1][i] = 1;
            }
        }
    }
}
void fin_tableau(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL; i++){
        int nomb_1_l = 0, nomb_0_l = 0, nomb_1_c = 0, nomb_0_c = 0;
        for (int j = 0; j<TAILLEL; j++){
            if (t[i][j] == 1){
                nomb_1_l++;
            } else{
                if (t[i][j] == 0){ nomb_0_l++;
                }
            }
            if (t[j][i] == 1){
                nomb_1_c++;
            } else{
                if (t[j][i] == 0){
                    nomb_0_c++;
                }
            }
        }
        if (nomb_1_l == TAILLEL/2){
            ajouter_ligne(t, 0, i);
        } else {
            if (nomb_0_l == TAILLEL/2){
                ajouter_ligne(t, 1, i);
            }
        }
        if (nomb_1_c == TAILLEL/2){
            ajouter_colone(t, 0, i);
        } else {
            if (nomb_0_c == TAILLEL/2){
                ajouter_colone(t, 1, i);
            }
        }
    }
}
void comparer_ligne_colone(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL-1; i++){
        for (int j = i+1; j<TAILLEL; j++){
            int conte_l_0=0,conte_l_1=0;
            int conte_c_0=0,conte_c_1=0;
            int conte_l_R=0, conte_c_R=0;
            //ligne
            for (int m = 0; m<TAILLEL; m++){
                if (t[i][m] == t[j][m] && t[i][m] == 1) {
                    conte_l_1 ++;
                }
                if (t[i][m] == t[j][m] && t[i][m] == 0) {
                    conte_l_0 ++;
                }
                if (t[i][m] == -1 || t[j][m] ==-1){
                    conte_l_R ++;
                }
            }
            if (conte_l_1 == TAILLEL/2 -1 && conte_l_R == 2){
                for (int m = 0; m<TAILLEL; m++){
                    if (t[i][m] == 1 && t[j][m] == -1) {
                        t[j][m] = 0;
                    }
                    if (t[i][m] == -1 && t[j][m] == 1) {
                        t[i][m] = 0;
                    }
                }
            }
            if (conte_l_0 == TAILLEL/2 -1 && conte_l_R == 2) {
                for (int m = 0; m < TAILLEL; m++) {
                    if (t[i][m] == 0 && t[j][m] == -1) {
                        t[j][m] = 1;
                    }
                    if (t[i][m] == -1 && t[j][m] == 0) {
                        t[i][m] = 1;
                    }
                }
            }
            //colone
            for (int k = 0; k<TAILLEL; k++){
                if (t[k][i] == t[k][j] && t[k][i] == 1) {
                    conte_c_1 ++;
                }
                if (t[k][i] == t[k][j] && t[k][i] == 0) {
                    conte_c_0 ++;
                }
                if (t[k][i] == -1 || t[k][j] ==-1){
                    conte_c_R ++;
                }
            }
            if (conte_c_1 == TAILLEL/2 -1 && conte_c_R == 2){
                for (int k = 0; k<TAILLEL; k++){
                    if (t[k][i] == 1 && t[k][j] == -1) {
                        t[k][j] = 0;
                    }
                    if (t[k][i] == -1 && t[k][j] == 1) {
                        t[k][i] = 0;
                    }
                }
            }
            if (conte_c_0 == TAILLEL/2 -1 && conte_c_R == 2) {
                for (int k = 0; k < TAILLEL; k++) {
                    if (t[k][i] == 0 && t[k][j] == -1) {
                        t[k][j] = 1;
                    }
                    if (t[k][i] == -1 && t[k][j] == 0) {
                        t[k][i] = 1;
                    }
                }
            }
        }
    }
}
bool remplire_au_hazard(int t[TAILLEL][TAILLEL], int conte, int tab[TAILLEL], int pose){
    int i, j;
    if (conte == 36){
        conte = 0;
        tab[pose] = 0;
    }
    i = conte / TAILLEL;
    j = conte - (i*TAILLEL);
    while (i <TAILLEL && tab[pose] != 36){
        tab[pose]++;
        if (t[i][j] == -1){
            t[i][j] = 1;
            if (false == valider_un_coup(t)){
                t[i][j] = 0;
            } else {
                return true;
            }
            if (false == valider_un_coup(t)) {
                t[i][j] = -1;
            } else {
                return true;
            }
        }
        j++;
        if (j == TAILLEL){
            i++;
            j = 0;
        }
    }
    return false;
}
bool comparer_tableau(int tab_parfait[TAILLEL][TAILLEL], int t[TAILLEL][TAILLEL]){
    bool passe = false;
    int i = 0, j =0;
    while (i<TAILLEL && passe == false){
        if (tab_parfait[i][j] != t[i][j]){
            passe = true;
        }
        j++;
        if (j == TAILLEL){
            i++;
            j = 0;
        }
    }
    return passe;
}


void recurence_cree_tableau_AI(int t[TAILLEL][TAILLEL], int conte, int pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL], int *ch, int tab_parfait[TAILLEL*TAILLEL][TAILLEL][TAILLEL]){
    if (tab_n[0] != 36) {
        if (conte < 2000 && tableau_plain(t) && pose < TAILLEL * TAILLEL) {
            conte++;
            int i = 0;
            while (tableau_plain(t) && i < TAILLEL * TAILLEL) {
                fin_tableau(t);
                double_triple_tableau(t);
                comparer_ligne_colone(t);
                i++;
            }
            if (false == tableau_plain(t) && false == valider_un_coup(t)) {
                pose--;
                for (int k = 0; k < TAILLEL; k++) {
                    for (int l = 0; l < TAILLEL; l++) {
                        t[k][l] = tab_t[pose][k][l];
                    }
                }
                int x, y;
                x = (tab_n[pose] - 1) / TAILLEL;
                y = (tab_n[pose] - 1) - (x * TAILLEL);
                t[x][y] = 0;
                if (false == valider_un_coup(t)) {
                    t[x][y] = -1;
                }
            } else {
                for (int k = 0; k < TAILLEL; k++) {
                    for (int l = 0; l < TAILLEL; l++) {
                        tab_t[pose][k][l] = t[k][l];
                    }
                }
            }
            if (tableau_plain(t)) {
                bool a = remplire_au_hazard(t, tab_n[pose], tab_n, pose);
                if (a == true) {
                    pose++;
                    recurence_cree_tableau_AI(t, conte, pose, tab_t, tab_n, ch, tab_parfait);
                } else {
                    pose--;
                    for (int k = 0; k < TAILLEL; k++) {
                        for (int l = 0; l < TAILLEL; l++) {
                            t[k][l] = tab_t[pose][k][l];
                        }
                    }
                    int x, y;
                    x = (tab_n[pose] - 1) / TAILLEL;
                    y = (tab_n[pose] - 1) - (x * TAILLEL);
                    t[x][y] = 0;
                    if (false == valider_un_coup(t)) {
                        t[x][y] = -1;
                    }
                    recurence_cree_tableau_AI(t, conte, pose, tab_t, tab_n, ch, tab_parfait);
                }
            }
        }
        if (tableau_plain(t) == false && tab_n[0] != 36) {
            int q = 0;
            bool passe = true;
            while (q<*ch && passe == true && *ch != 0){
                passe = comparer_tableau(tab_parfait[*ch-1], t);
                q++;
            }
            if (passe) {
                for (int k = 0; k < TAILLEL; k++) {
                    for (int l = 0; l < TAILLEL; l++) {
                        tab_parfait[*ch][k][l] = t[k][l];
                    }
                }
                *ch = *ch + 1;
            }

            if (tab_n[1] != 36) {
                pose--;
                for (int k = 0; k < TAILLEL; k++) {
                    for (int l = 0; l < TAILLEL; l++) {
                        t[k][l] = tab_t[pose][k][l];
                    }
                }
                int x, y;
                x = (tab_n[pose] - 1) / TAILLEL;
                y = (tab_n[pose] - 1) - (x * TAILLEL);
                t[x][y] = 0;
                if (false == valider_un_coup(t)) {
                    t[x][y] = -1;
                }
                recurence_cree_tableau_AI(t, conte, pose, tab_t, tab_n, ch, tab_parfait);
            }
        }
    }
}