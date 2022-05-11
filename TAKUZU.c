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

// ############################################################################################
// Adrien

//
// Created by Adrie on 26/04/2022.
//

bool verifeiller_deux_ligne(int t1[TAILLE], int t2[TAILLE]){
    for (int i = 0; i<TAILLE; i++){
        if (t1[i] != t2[i] || t1[i] == -1) {
            return true;
        }
    }
    return false;
}
bool valider_un_coup(int t[TAILLE][TAILLE]){
    //verifie que il n'y a pas trois fois le meme chifre et N0 = N1 = TAILLE/2
    for (int l = 0; l<TAILLE; l++){
        for (int c = 0; c<TAILLE; c++){
            int conte_l = 0, conte_c = 0, con_c = 0, con_l = 0, val_l = t[l][0], val_c = t[0][c];
            for (int i = 0; i<TAILLE; i++){
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
                if ((conte_l > TAILLE/2) || (conte_c > TAILLE/2) || (con_c == 3) || (con_l == 3)){
                    return false;
                }
            }
            //verifie que les ligne et colone sont diferante
            for (int i = 0; i<TAILLE-1; i++){
                for (int j = i+1; j<TAILLE; j++){
                    int conte= 0;
                    if (verifeiller_deux_ligne(t[i], t[j])){
                        for (int k = 0; k<TAILLE; k++){
                            if (t[k][i] == t[k][j] && t[k][i] != -1){
                                conte ++;
                            }
                            if (conte == TAILLE){
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
bool valider_un_coup_unique(int t[TAILLE][TAILLE], int l, int c){
    int conte_l = 0, conte_c = 0, con_c = 0, con_l = 0, val_l = t[l][0], val_c = t[0][c];
    for (int i = 0; i<TAILLE; i++){
        if (t[l][i] != -1){
            conte_l += t[l][i];
        }
        if (t[i][c] != -1){
            conte_c += t[i][c];
        }
        if (t[i][c] != val_c){
            con_c = 0;
            val_c = t[i][c];
        } else {
            con_c ++;
        }
        if (t[l][i] != val_l){
            con_l = 0;
            val_l = t[l][i];
        } else {
            con_l ++;
        }
        if (conte_l > TAILLE/2 || conte_c > TAILLE/2 || con_c == 3 || con_l == 3){
            return false;
        }
    }

    for (int i = 0; i<TAILLE-1; i++){
        for (int j = i+1; j<TAILLE; j++){
            int conte= 0;
            if (verifeiller_deux_ligne(t[i], t[j])){
                for (int k = 0; k<TAILLE; k++){
                    if (t[k][i] == t[k][j] && t[k][i] != -1){
                        conte ++;
                    }
                    if (conte == TAILLE){
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
    }
    return true;
}
bool tableau_plain(int t[TAILLE][TAILLE]){
    for (int i = 0; i<TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (t[i][j] == -1) {
                return true;
            }
        }
    }
    return false;
}

void afficher_tableau(int t[TAILLE][TAILLE]){
    for (int i = 0; i<TAILLE; i++){
        for (int j = 0; j<TAILLE; j++){
            if (t[i][j] == -1){
                printf(" \t");
            } else {
                printf("%d\t", t[i][j]);
            }
        }
        printf("\n");
    }
}

void ajouter_ligne(int t[TAILLE][TAILLE], int val, int ligne){
    for (int i = 0; i<TAILLE; i++){
        if (t[ligne][i] == -1){
            t[ligne][i] = val;
        }
    }
}
void ajouter_colone(int t[TAILLE][TAILLE], int val, int colone){
    for (int i = 0; i<TAILLE; i++){
        if (t[i][colone] == -1){
            t[i][colone] = val;
        }
    }
}
void double_triple_tableau(int t[TAILLE][TAILLE]){
    for (int i = 0; i<TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            //ligne 0110
            if (t[i][j] == 1 && t[i][j+1] == 1){
                if (j != 0 && t[i][j-1] == -1 ){
                    t[i][j-1] = 0;
                }
                if (j+1 != TAILLE-1&& t[i][j+2] == -1){
                    t[i][j+2] = 0;
                }
            }
            //ligne 1001
            if (t[i][j] == 0 && t[i][j+1] == 0){
                if (j != 0 && t[i][j-1] == -1){
                    t[i][j-1] = 1;
                }
                if (j+1 != TAILLE-1 && t[i][j+2] == -1){
                    t[i][j+2] = 1;
                }
            }
            //ligne 101
            if (t[i][j] == 1 && t[i][j+1] == -1 && t[i][j+2] == 1 && j+2 != TAILLE && j+1 != TAILLE){
                t[i][j+1] = 0;
            }
            //ligne 010
            if (t[i][j] == 0 && t[i][j+1] == -1 && t[i][j+2] == 0 && j+2 != TAILLE && j+1 != TAILLE){
                t[i][j+1] = 1;
            }
            //colone 1001
            if (t[j][i] == 1 && t[j+1][i] == 1){
                if (j != 0 && t[j-1][i] == -1){
                    t[j-1][i] = 0;
                }
                if (j+1 != TAILLE-1 && t[j+2][i] == -1){
                    t[j+2][i] = 0;
                }
            }
            //colone 0110
            if (t[j][i] == 0 && t[j+1][i] == 0){
                if (j != 0 && t[j-1][i] == -1){
                    t[j-1][i] = 1;
                }
                if (j+1 != TAILLE-1 && t[j+2][i] == -1){
                    t[j+2][i] = 1;
                }
            }
            //colone 101
            if (t[j][i] == 1 && t[j+1][i] == -1 && t[j+2][i] == 1 && j+2 != TAILLE && j+1 != TAILLE){
                t[j+1][i] = 0;
            }
            //colone 010
            if (t[j][i] == 0 && t[j+1][i] == -1 && t[j+2][i] == 0 && j+2 != TAILLE && j+1 != TAILLE){
                t[j+1][i] = 1;
            }
        }
    }
}
void fin_tableau(int t[TAILLE][TAILLE]){
    for (int i = 0; i<TAILLE; i++){
        int nomb_1_l = 0, nomb_0_l = 0, nomb_1_c = 0, nomb_0_c = 0;
        for (int j = 0; j<TAILLE; j++){
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
        if (nomb_1_l == TAILLE/2){
            ajouter_ligne(t, 0, i);
        } else {
            if (nomb_0_l == TAILLE/2){
                ajouter_ligne(t, 1, i);
            }
        }
        if (nomb_1_c == TAILLE/2){
            ajouter_colone(t, 0, i);
        } else {
            if (nomb_0_c == TAILLE/2){
                ajouter_colone(t, 1, i);
            }
        }
    }
}
void comparer_ligne_colone(int t[TAILLE][TAILLE]){
    for (int i = 0; i<TAILLE-1; i++){
        for (int j = i+1; j<TAILLE; j++){
            int conte_l_0=0,conte_l_1=0;
            int conte_c_0=0,conte_c_1=0;
            int conte_l_R=0, conte_c_R=0;
            //ligne
            for (int m = 0; m<TAILLE; m++){
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
            if (conte_l_1 == TAILLE/2 -1 && conte_l_R == 2){
                for (int m = 0; m<TAILLE; m++){
                    if (t[i][m] == 1 && t[j][m] == -1) {
                        t[j][m] = 0;
                    }
                    if (t[i][m] == -1 && t[j][m] == 1) {
                        t[i][m] = 0;
                    }
                }
            }
            if (conte_l_0 == TAILLE/2 -1 && conte_l_R == 2) {
                for (int m = 0; m < TAILLE; m++) {
                    if (t[i][m] == 0 && t[j][m] == -1) {
                        t[j][m] = 1;
                    }
                    if (t[i][m] == -1 && t[j][m] == 0) {
                        t[i][m] = 1;
                    }
                }
            }
            //colone
            for (int k = 0; k<TAILLE; k++){
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
            if (conte_c_1 == TAILLE/2 -1 && conte_c_R == 2){
                for (int k = 0; k<TAILLE; k++){
                    if (t[k][i] == 1 && t[k][j] == -1) {
                        t[k][j] = 0;
                    }
                    if (t[k][i] == -1 && t[k][j] == 1) {
                        t[k][i] = 0;
                    }
                }
            }
            if (conte_c_0 == TAILLE/2 -1 && conte_c_R == 2) {
                for (int k = 0; k < TAILLE; k++) {
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
bool remplire_au_hazard(int t[TAILLE][TAILLE], int conte, int tab[TAILLE], int pose){
    int i, j;
    if (conte == 36){
        conte = 0;
        tab[pose] = 0;
    }
    i = conte / TAILLE;
    j = conte - (i*TAILLE);
    while (i <TAILLE && tab[pose] != 36){
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
        if (j == TAILLE){
            i++;
            j = 0;
        }
    }
    return false;
}


void recurence_cree_tableau_AI(int t[TAILLE][TAILLE], int conte, int pose, int tab_t[TAILLE*TAILLE][TAILLE][TAILLE], int tab_n[TAILLE*TAILLE], int ch, int tab_parfait[TAILLE*TAILLE][TAILLE][TAILLE]){
    if (conte<2000 && tableau_plain(t) && pose<TAILLE*TAILLE){
        printf("/%d/, /%d/\n", tab_n[pose-1], pose);        afficher_tableau(t);
        conte++;
        int i = 0;
        while (tableau_plain(t) && i < TAILLE * TAILLE) {
            fin_tableau(t);
            double_triple_tableau(t);
            comparer_ligne_colone(t);
            i++;
        }
        if (false == tableau_plain(t) && false == valider_un_coup(t)){
            printf("++++++++++++++++++++++\n");
            pose--;
            for (int k = 0; k<TAILLE; k++){
                for (int l = 0; l<TAILLE; l++){
                    t[k][l] = tab_t[pose][k][l];
                }
            }
            int x,y;
            x = tab_n[pose] / TAILLE;
            y = tab_n[pose] - (x*TAILLE);
            printf("%d // %d;%d\n", t[x][y], x, y);
            t[x][y] = 0;
            if (false == valider_un_coup(t)){
                t[x][y] = -1;
            }

        } else {
            for (int k = 0; k<TAILLE; k++){
                for (int l = 0; l<TAILLE; l++){
                    tab_t[pose][k][l] = t[k][l];
                }
            }
        }
        if (tableau_plain(t)){
            bool a = remplire_au_hazard(t, tab_n[pose], tab_n, pose);
            if (a == true){
                pose++;
                recurence_cree_tableau_AI(t, conte, pose, tab_t,tab_n, ch, tab_parfait);
            } else {
                pose--;
                for (int k = 0; k<TAILLE; k++){
                    for (int l = 0; l<TAILLE; l++){
                        t[k][l] = tab_t[pose][k][l];
                    }
                }
                int x,y;
                x = tab_n[pose] / TAILLE;
                y = conte - (x*TAILLE);
                t[x][y] = 0;
                if (false == valider_un_coup(t)){
                    t[x][y] = -1;
                }
                recurence_cree_tableau_AI(t, conte, pose, tab_t,tab_n, ch, tab_parfait);
            }
        }
    }
    if (tableau_plain(t) == false){
        afficher_tableau(t);
        printf("\n");
        for (int k = 0; k<TAILLE; k++){
            for (int l = 0; l<TAILLE; l++){
                tab_parfait[ch][k][l] = t[k][l];
            }
        }
        ch ++;
        if (tab_n[0] != 36){
            pose--;
            for (int k = 0; k<TAILLE; k++){
                for (int l = 0; l<TAILLE; l++){
                    t[k][l] = tab_t[pose][k][l];
                }
            }
            int x,y;
            x = tab_n[pose] / TAILLE;
            y = conte - (x*TAILLE);
            t[x][y] = 0;
            if (false == valider_un_coup(t)){
                t[x][y] = -1;
            }
            printf("33333333333333333333333333333333333333333\n");
            afficher_tableau(t);
            printf("33333333333333333333333333333333333333333\n");
            printf("%d, %d\n", conte, tab_n[pose]);
            recurence_cree_tableau_AI(t, conte, pose, tab_t,tab_n, ch, tab_parfait);
        }
    }
}