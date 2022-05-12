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
    printf("Indiquez la ligne puis la colonne de la valeur a ajouter :\n");
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

//verifier un tableau :

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

bool tableau_pas_plain(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL; i++) {
        for (int j = 0; j < TAILLEL; j++) {
            if (t[i][j] == -1) {
                return true;
            }
        }
    }
    return false;
}


//remplire le tableau a partire du masque
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
            // pour etre sur que toutes les valeux chercher et sesi existe
            if (j+1<TAILLEL){
                //ligne 0110
                if (t[i][j] == 1 && t[i][j+1] == 1){
                    if (j != 0 && t[i][j-1] == -1 && j-1 >-1){
                        t[i][j-1] = 0;
                    }
                    if (j+1 != TAILLEL-1 && t[i][j+2] == -1 && j+2 <TAILLEL){
                        t[i][j+2] = 0;
                    }
                }

                //ligne 1001
                if (t[i][j] == 0 && t[i][j+1] == 0){
                    if (j != 0 && t[i][j-1] == -1 && j-1 >-1){
                        t[i][j-1] = 1;
                    }
                    if (j+1 != TAILLEL-1 && t[i][j+2] == -1 && j+2 <TAILLEL){
                        t[i][j+2] = 1;
                    }
                }

                //colone 1001
                if (t[j][i] == 1 && t[j+1][i] == 1){
                    if (j != 0 && t[j-1][i] == -1 && j-1 >-1){
                        t[j-1][i] = 0;
                    }
                    if (j+1 != TAILLEL-1 && t[j+2][i] == -1 && j+2 <TAILLEL){
                        t[j+2][i] = 0;
                    }
                }

                //colone 0110
                if (t[j][i] == 0 && t[j+1][i] == 0){
                    if (j != 0 && t[j-1][i] == -1 && j-1 >-1){
                        t[j-1][i] = 1;
                    }
                    if (j+1 != TAILLEL-1 && t[j+2][i] == -1 && j+2 <TAILLEL){
                        t[j+2][i] = 1;
                    }
                }
            }
            if (j+2<TAILLEL){
                //ligne 101
                if (t[i][j] == 1 && t[i][j+1] == -1 && t[i][j+2] == 1 && j+1 < TAILLEL){
                    t[i][j+1] = 0;
                }

                //ligne 010
                if (t[i][j] == 0 && t[i][j+1] == -1 && t[i][j+2] == 0 && j+1 < TAILLEL){
                    t[i][j+1] = 1;
                }

                //colone 101
                if (t[j][i] == 1 && t[j+1][i] == -1 && t[j+2][i] == 1 && j+1 < TAILLEL){
                    t[j+1][i] = 0;
                }

                //colone 010
                if (t[j][i] == 0 && t[j+1][i] == -1 && t[j+2][i] == 0 && j+1 < TAILLEL){
                    t[j+1][i] = 1;
                }
            }
        }
    }
}

void fin_tableau(int t[TAILLEL][TAILLEL]){
    // on regarde si il y a 3 fois 0 / 1 si oui on coplaite la colone/ligne
    for (int i = 0; i<TAILLEL; i++){
        // init des conteur : ligne 1 / ligne 0 // colone 1 / colone 0
        int nomb_1_l = 0, nomb_0_l = 0, nomb_1_c = 0, nomb_0_c = 0;
        // on regarde si il y a 3 fois 0 / 1
        for (int j = 0; j<TAILLEL; j++){
            // on regarde pour les ligne
            if (t[i][j] == 1){
                nomb_1_l++;
            } else{
                if (t[i][j] == 0){
                    nomb_0_l++;
                }
            }
            // on regarde pour les colone
            if (t[j][i] == 1){
                nomb_1_c++;
            } else{
                if (t[j][i] == 0){
                    nomb_0_c++;
                }
            }
        }

        // si oui on coplaite la ligne
        if (nomb_1_l == TAILLEL/2){
            ajouter_ligne(t, 0, i);
        }
        if (nomb_0_l == TAILLEL/2){
            ajouter_ligne(t, 1, i);
        }
        // si oui on coplaite la ligne
        if (nomb_1_c == TAILLEL/2){
            ajouter_colone(t, 0, i);
        }
        if (nomb_0_c == TAILLEL/2){
            ajouter_colone(t, 1, i);
        }
    }
}

void comparer_ligne_colone(int t[TAILLEL][TAILLEL]){
    for (int i = 0; i<TAILLEL-1; i++){
        for (int j = i+1; j<TAILLEL; j++){
            // init des conteur :
            // ligne 1 / ligne 0
            int conte_l_0 = 0,conte_l_1 = 0;
            // colone 1 / colone 0
            int conte_c_0 = 0,conte_c_1 = 0;
            // ligne -1 / colone -1
            int conte_l_T = 0, conte_c_T = 0;

            //ligne
            for (int m = 0; m<TAILLEL; m++){
                if (t[i][m] == t[j][m] && t[i][m] == 1) {
                    conte_l_1 ++;
                }
                if (t[i][m] == t[j][m] && t[i][m] == 0) {
                    conte_l_0 ++;
                }
                if (t[i][m] == -1 || t[j][m] ==-1){
                    conte_l_T ++;
                }
            }
            if (conte_l_1 == TAILLEL/2 -1 && conte_l_T == 2){
                for (int m = 0; m<TAILLEL; m++){
                    if (t[i][m] == 1 && t[j][m] == -1) {
                        t[j][m] = 0;
                    }
                    if (t[i][m] == -1 && t[j][m] == 1) {
                        t[i][m] = 0;
                    }
                }
            }
            if (conte_l_0 == TAILLEL/2 -1 && conte_l_T == 2) {
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
                    conte_c_T ++;
                }
            }
            if (conte_c_1 == TAILLEL/2 -1 && conte_c_T == 2){
                for (int k = 0; k<TAILLEL; k++){
                    if (t[k][i] == 1 && t[k][j] == -1) {
                        t[k][j] = 0;
                    }
                    if (t[k][i] == -1 && t[k][j] == 1) {
                        t[k][i] = 0;
                    }
                }
            }
            if (conte_c_0 == TAILLEL/2 -1 && conte_c_T == 2) {
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

int remplire_au_hazard(int t[TAILLEL][TAILLEL], int tab[TAILLEL], int pose){
    int conte = tab[pose], i, j, remplie = 0;
    if (conte > 36){
        conte = 0;
        tab[pose] = 0;
    }
    i = conte / TAILLEL;
    j = conte - (i*TAILLEL);
    while (i <TAILLEL && tab[pose] < 37 && remplie == 0){
        tab[pose]++;
        //on regarde si la case est vide
        if (t[i][j] == -1){
            //on repli par 1
            t[i][j] = 1;
            if (false == valider_un_coup(t)){
                //si ce n'est pas possible on repli par 0
                t[i][j] = 0;
                if (false == valider_un_coup(t)) {
                    t[i][j] = -1;
                    //si ça non plus n'est pas possible alors on arrete
                    remplie -1;
                } else {
                    remplie = 1;
                }
            } else {
                remplie = 1;
            }
        }
        j++;
        if (j >= TAILLEL){
            i++;
            j = 0;
        }
    }
    return remplie;
}

//utilise les fonction pour remplire le tableau a partire des régle
void tableau_regle(int t[TAILLEL][TAILLEL]){
    int i = 0;
    while (tableau_pas_plain(t) && i < TAILLEL * TAILLEL) {
        fin_tableau(t);
        double_triple_tableau(t);
        comparer_ligne_colone(t);
        i++;
    }
}

void remplire_tableau_avec_tab(int t1[TAILLEL][TAILLEL], int t2[TAILLEL][TAILLEL]){
    for (int k = 0; k < TAILLEL; k++) {
        for (int l = 0; l < TAILLEL; l++) {
            t1[k][l] = t2[k][l];
        }
    }
}

//verifier si on ne peut pas replacer le 1 (mi au hazard) a 0
bool metre_a_zero(int t[TAILLEL][TAILLEL], int val){
    int x,y;
    x = val / TAILLEL;
    y = val - (x * TAILLEL);
    t[x][y] = 0;
    return valider_un_coup(t);
}
// on remplie par zero et on teste juscaseque sa marche
void boucle_zero(int t[TAILLEL][TAILLEL], int *pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL]){
    bool toujour_faux = false;
    if (*pose != 0){
        *pose = *pose -1;
    }
    remplire_tableau_avec_tab(t, tab_t[*pose]);
    //printf("*************\n");
    //afficher_tableau(t);
    //printf("________%d\n", tab_n[*pose]);
    //afficher_tableau(tab_t[*pose]);
    //on sais que 1 ne marche pas donc on essaille 0, si sa ne marche pas on retourne au tableau pres enregistrer
    toujour_faux = metre_a_zero(t, tab_n[*pose] - 1);

    //tan que c'est faux on continue
    while (toujour_faux == false && *pose != 0){
        *pose = *pose -1;
        remplire_tableau_avec_tab(t, tab_t[*pose]);
        toujour_faux = metre_a_zero(t, tab_n[*pose] - 1);
    }
}


// voire si deux tableau sont identique :
bool comparer_tableau(int t1[TAILLEL][TAILLEL], int t2[TAILLEL][TAILLEL]){
    bool passe = false;
    int i = 0, j =0;
    while (i<TAILLEL && passe == false){
        if (t1[i][j] != t2[i][j]){
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




