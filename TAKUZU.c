//
// Created by Adrien Pouyat and Luka Radovanovic on 06/04/2022.
//fonctions permettant de créer un tableau et faire les vérifications
//

#include "TAKUZU.h"

// modif
void saisir_valeurs_adrien(int **t, int *coup_du_jouer, int TAILLE) {
    int val = 2, lig = -1, col = -1;
    bool libre = false;
    // on dement de la valeur
    printf("\nQuelle valeur souhaitez vous saisir dans le jeu :\n");
    while (val > 1 || val < 0) {
        printf("La valeur doit etre 0 ou 1 : ");
        scanf("%d", &val);
        printf("\n");
    }
    // on demande la ligne et la colone
    printf("Indiquez la ligne puis la colonne de la valeur a ajouter :\n");
    while (lig > TAILLE || lig < 0 && col > TAILLE || col < 0 || libre == false) {
        printf("Les valeurs doivent etre entre 1 et %d (ligne puis colonne): ", TAILLE);
        scanf("%d %d", &lig, &col);
        if (t[lig][col] == -1) {
            libre = true;
        } else {
            printf("il faut que la case soit vide\n");
        }
        printf("\n");
    }

    // on ajoute les donner dans la liste
    coup_du_jouer[0] = val;
    coup_du_jouer[1] = lig;
    coup_du_jouer[2] = col;
}

void regle_du_jeux() {
    printf("Les regles du Takuzu sont :\n");
    printf("1. Dans une ligne, il doit y avoir autant de 0 que de 1\n");
    printf("2. Dans une colonne, il doit y avoir autant de 0 que de 1\n");
    printf("3. Il ne peut pas y avoir deux lignes identiques dans une grille\n");
    printf("3. Il ne peut pas y avoir deux colonnes identiques dans une grille\n");
    printf("5. Dans une ligne ou une colonne, il ne peut y avoir plus de deux 0 ou deux 1 a la suite (on ne peut pas avoir trois 0 de suite ou trois 1 de suite)\n");
}




//
// Created by Adrie on 26/04/2022.
//

// regle du jeux pour aider le jouer
void tableau_regle_joueur(int **t, int TAILLE) {
    //utilise les fonction pour donner des indice a partire des régle
    int i = 0;
    bool indice = false;
    while (tableau_pas_plain(t, TAILLE) && i < TAILLE * TAILLE && indice == false) {
        printf("%d // %d\n", indice, i);
        indice = fin_tableau_joueur(t, TAILLE);
        if (indice == false) {
            indice = double_triple_tableau_joueur(t, TAILLE);
            if (indice == false) {
                indice = comparer_ligne_colone_joueur(t, TAILLE);
            }
        }
        i++;
    }
    if (indice == false) {
        printf("il n'y a pas d'indice a donner vous pouver placer au hazard dans les case vide 0/1\n");
    }
}

bool double_triple_tableau_joueur(int **t, int TAILLE) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            // pour etre sur que toutes les valeux chercher et sesi existe
            if (j + 1 < TAILLE) {
                //ligne 0110
                if (t[i][j] == 1 && t[i][j + 1] == 1) {
                    printf("Il y a une repetion de 1 dans la ligne %d, il faut donc plasser un 0 a droite ou a gauche\n",
                           i);
                    return true;
                }

                //ligne 1001
                if (t[i][j] == 0 && t[i][j + 1] == 0) {
                    printf("Il y a une repetion de 0 dans la ligne %d, il faut donc plasser un 1 a droite ou a gauche\n",
                           i);
                    return true;
                }

                //colone 0110
                if (t[j][i] == 1 && t[j + 1][i] == 1) {
                    printf("Il y a une repetion de 1 dans la colone %d, il faut donc plasser un 0 en haut ou en bas\n",
                           i);
                    return true;
                }

                //colone 1001
                if (t[j][i] == 0 && t[j + 1][i] == 0) {
                    printf("Il y a une repetion de 0 dans la colone %d, il faut donc plasser un 1 en haut ou en bas\n",
                           i);
                    return true;
                }
            }
            if (j + 2 < TAILLE) {
                //ligne 101
                if (t[i][j] == 1 && t[i][j + 1] == -1 && t[i][j + 2] == 1 && j + 1 < TAILLE) {
                    printf("Il est impossible de placer trois 1 a la suite\n");
                    printf("Regarder la ligne %d\n", i);
                    return true;
                }

                //ligne 010
                if (t[i][j] == 0 && t[i][j + 1] == -1 && t[i][j + 2] == 0 && j + 1 < TAILLE) {
                    printf("Il est impossible de placer trois 0 a la suite\n");
                    printf("Regarder la ligne %d\n", i);
                    return true;
                }

                //colone 101
                if (t[j][i] == 1 && t[j + 1][i] == -1 && t[j + 2][i] == 1 && j + 1 < TAILLE) {
                    printf("Il est impossible de placer trois 1 a la suite\n");
                    printf("Regarder la colone %d\n", i);
                    return true;
                }

                //colone 010
                if (t[j][i] == 0 && t[j + 1][i] == -1 && t[j + 2][i] == 0 && j + 1 < TAILLE) {
                    printf("Il est impossible de placer trois 0 a la suite\n");
                    printf("Regarder la colone %d\n", i);
                    return true;
                }
            }
        }
    }
    return false;
}

bool fin_tableau_joueur(int **t, int TAILLE) {
    // on regarde si il y a 3 fois 0 / 1 si oui on coplaite la colone/ligne
    for (int i = 0; i < TAILLE; i++) {
        // init des conteur : ligne 1 / ligne 0 // colone 1 / colone 0
        int nomb_1_l = 0, nomb_0_l = 0, nomb_1_c = 0, nomb_0_c = 0;
        // on regarde si il y a 3 fois 0 / 1
        for (int j = 0; j < TAILLE; j++) {
            // on regarde pour les ligne
            if (t[i][j] == 1) {
                nomb_1_l++;
            } else {
                if (t[i][j] == 0) {
                    nomb_0_l++;
                }
            }
            // on regarde pour les colone
            if (t[j][i] == 1) {
                nomb_1_c++;
            } else {
                if (t[j][i] == 0) {
                    nomb_0_c++;
                }
            }
        }

        // si oui on coplaite la ligne
        if (nomb_1_l == TAILLE / 2) {
            printf("Il n'y a plu de 1 a metre dans la ligne %d\n", i);
            return true;
        }
        if (nomb_0_l == TAILLE / 2) {
            printf("Il n'y a plu de 0 a metre dans la ligne %d\n", i);
            return true;
        }
        // si oui on coplaite la ligne
        if (nomb_1_c == TAILLE / 2) {
            printf("Il n'y a plu de 1 a metre dans la colone %d\n", i);
            return true;
        }
        if (nomb_0_c == TAILLE / 2) {
            printf("Il n'y a plu de 0 a metre dans la colone %d\n", i);
            return true;
        }
    }
    return false;
}

bool comparer_ligne_colone_joueur(int **t, int TAILLE) {
    for (int i = 0; i < TAILLE - 1; i++) {
        for (int j = i + 1; j < TAILLE; j++) {
            // init des conteur :
            // ligne 1 / ligne 0
            int conte_l_0 = 0, conte_l_1 = 0;
            // colone 1 / colone 0
            int conte_c_0 = 0, conte_c_1 = 0;
            // ligne -1 / colone -1
            int conte_l_T = 0, conte_c_T = 0;

            //ligne
            for (int m = 0; m < TAILLE; m++) {
                if (t[i][m] == t[j][m] && t[i][m] == 1) {
                    conte_l_1++;
                }
                if (t[i][m] == t[j][m] && t[i][m] == 0) {
                    conte_l_0++;
                }
                if (t[i][m] == -1 || t[j][m] == -1) {
                    conte_l_T++;
                }
            }
            if (conte_l_1 == TAILLE / 2 - 1 && conte_l_T == 2) {
                printf("Les lignes %d et  %d sont tres similaire\n", i, j);
                return true;
            }
            if (conte_l_0 == TAILLE / 2 - 1 && conte_l_T == 2) {
                printf("Les lignes %d et  %d sont tres similaire\n", i, j);
                return true;
            }

            //colone
            for (int k = 0; k < TAILLE; k++) {
                if (t[k][i] == t[k][j] && t[k][i] == 1) {
                    conte_c_1++;
                }
                if (t[k][i] == t[k][j] && t[k][i] == 0) {
                    conte_c_0++;
                }
                if (t[k][i] == -1 || t[k][j] == -1) {
                    conte_c_T++;
                }
            }
            if (conte_c_1 == TAILLE / 2 - 1 && conte_c_T == 2) {
                printf("Les colones %d et  %d sont tres similaire\n", i, j);
                return true;
            }
            if (conte_c_0 == TAILLE / 2 - 1 && conte_c_T == 2) {
                printf("Les colones %d et  %d sont tres similaire\n", i, j);
                return true;
            }
        }
    }
    return false;
}

//fonction utile :
void afficher_tableau(int **t, int TAILLE) {

    printf("\n     ");
    for (int i = 0; i < TAILLE; ++i)
        printf("%d  ", i);

    printf("\n    ");

    for (int i = 0; i < TAILLE; ++i)
        printf("___");

    printf("\n");

    for (int i = 0; i < TAILLE; ++i) {
        printf("%d ", i);
        if (i < 9)
            printf(" ");

        printf("| ");

        for (int j = 0; j < TAILLE; ++j) {
            if (t[i][j] == -1)
                printf(".  ");
            else
                printf("%d  ", t[i][j]);
        }


        printf("\n");
    }
}

void remplire_tableau_avec_tab(int **t1, int **t2, int TAILLE) {
    //copier t2 dans t1
    for (int k = 0; k < TAILLE; k++) {
        for (int l = 0; l < TAILLE; l++) {
            t1[k][l] = t2[k][l];
        }
    }
}

bool tableau_pas_plain(int **t, int TAILLE) {
    //parcoure le tableau pour trouver une case vide
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (t[i][j] == -1) {
                return true;
            }
        }
    }
    return false;
}

bool comparer_tableau(int **t1, int **t2, int TAILLE) {
    // voire si deux tableau sont identique :
    bool passe = false;
    int i = 0, j = 0;
    while (i < TAILLE && passe == false) {
        if (t1[i][j] != t2[i][j]) {
            passe = true;
        }
        j++;
        if (j == TAILLE) {
            i++;
            j = 0;
        }
    }
    return passe;
}

//verifier un tableau :
bool valider_un_tableau(int **t, int TAILLE) {
    //verifie que il n'y a pas trois fois le meme chifre et N0 = N1 = TAILLE/2
    for (int l = 0; l < TAILLE; l++) {
        for (int c = 0; c < TAILLE; c++) {
            int conte_l_1 = 0, conte_l_0 = 0, conte_c_0 = 0, conte_c_1 = 0, con_c = 0, con_l = 0, val_l = t[l][0], val_c = t[0][c];
            for (int i = 0; i < TAILLE; i++) {
                //ligne
                if (t[l][i] == 1) {
                    conte_l_1 += 1;
                }
                if (t[l][i] == 0) {
                    conte_l_0 += 1;
                }
                if (t[l][i] != val_l || t[l][i] == -1) {
                    con_l = 1;
                    val_l = t[l][i];
                } else {
                    con_l++;
                }
                //colone
                if (t[i][c] == 1) {
                    conte_c_1 += 1;
                }
                if (t[i][c] == 0) {
                    conte_c_0 += 1;
                }
                if (t[i][c] != val_c || t[i][c] == -1) {
                    con_c = 1;
                    val_c = t[i][c];
                } else {
                    con_c++;
                }

                //verifier
                if ((conte_l_1 > TAILLE / 2) || (conte_l_0 > TAILLE / 2) || (conte_c_0 > TAILLE / 2) ||
                    (conte_c_1 > TAILLE / 2) || (con_c == 3) || (con_l == 3)) {
                    return false;
                }
            }
            //verifie que les ligne et colone sont diferante
            for (int i = 0; i < TAILLE - 1; i++) {
                for (int j = i + 1; j < TAILLE; j++) {
                    int conte = 0;
                    if (verifeiller_deux_ligne(t[i], t[j], TAILLE)) {
                        for (int k = 0; k < TAILLE; k++) {
                            if (t[k][i] == t[k][j] && t[k][i] != -1) {
                                conte++;
                            }
                            if (conte == TAILLE) {
                                return false;
                            }
                        }
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool valider_un_coup(int **t, int l, int c, int TAILLE) {
    int conte_l_1 = 0, conte_l_0 = 0, conte_c_1 = 0, conte_c_0 = 0, con_c = 0, con_l = 0, val_l = t[l][0], val_c = t[0][c];
    for (int i = 0; i < TAILLE; i++) {
        //ligne
        if (t[l][i] == 1) {
            conte_l_1 += 1;
        } else {
            if (t[l][i] == 0) {
                conte_l_0 += 1;
            }
        }
        if (t[l][i] != val_l || t[l][i] == -1) {
            con_l = 1;
            val_l = t[l][i];
        } else {
            con_l++;
        }
        //colone
        if (t[l][i] == 1) {
            conte_c_1 += 1;
        } else {
            if (t[l][i] == 0) {
                conte_c_0 += 1;
            }
        }
        if (t[i][c] != val_c || t[i][c] == -1) {
            con_c = 1;
            val_c = t[i][c];
        } else {
            con_c++;
        }

        //verifier
        if (conte_l_1 > TAILLE / 2) {
            printf("Une des regle du TAKUZU a ete briser\n");
            printf("il y a trop de 1 dans la colone\n");
            return false;
        } else {
            if (conte_l_0 > TAILLE / 2) {
                printf("Une des regle du TAKUZU a ete briser\n");
                printf("il y a trop de 0 dans la colone\n");
                return false;
            } else {
                if (conte_c_1 > TAILLE / 2) {
                    printf("Une des regle du TAKUZU a ete briser\n");
                    printf("il y a trop de 1 dans la colone\n");
                    return false;
                } else {
                    if (conte_c_0 > TAILLE / 2) {
                        printf("Une des regle du TAKUZU a ete briser\n");
                        printf("il y a trop de 0 dans la colone\n");
                        return false;
                    } else {
                        if (con_c == 3) {
                            printf("Une des regle du TAKUZU a ete briser\n");
                            printf("Il y a trois chifre identique a la suite dans la colone\n");
                            return false;
                        } else {
                            if (con_l == 3) {
                                printf("Une des regle du TAKUZU a ete briser\n");
                                printf("Il y a trois chifre identique a la suite dans la ligne\n");
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    //verifie que les ligne et colone sont diferante
    for (int i = 0; i < TAILLE - 1; i++) {
        for (int j = i + 1; j < TAILLE; j++) {
            int conte = 0;
            if (verifeiller_deux_ligne(t[i], t[j], TAILLE)) {
                for (int k = 0; k < TAILLE; k++) {
                    if (t[k][i] == t[k][j] && t[k][i] != -1) {
                        conte++;
                    }
                    if (conte == TAILLE) {
                        printf("Une des regle du TAKUZU a ete briser\n");
                        printf("Il y a deux colone identique\n");
                        return false;
                    }
                }
            } else {
                printf("Une des regle du TAKUZU a ete briser\n");
                printf("Il y a deux ligne identique\n");
                return false;
            }
        }
    }

    return true;
}

bool verifeiller_deux_ligne(int *t1, int *t2, int TAILLE) {
    for (int i = 0; i < TAILLE; i++) {
        if (t1[i] != t2[i] || t1[i] == -1) {
            return true;
        }
    }
    return false;
}

// permet de metre la "val" dans un espase vide
void ajouter_ligne(int **t, int val, int ligne, int TAILLE) {
    for (int i = 0; i < TAILLE; i++) {
        if (t[ligne][i] == -1) {
            t[ligne][i] = val;
        }
    }
}

void ajouter_colone(int **t, int val, int colone, int TAILLE) {
    for (int i = 0; i < TAILLE; i++) {
        if (t[i][colone] == -1) {
            t[i][colone] = val;
        }
    }
}

// regel utiliser pour remplire le tableau
void tableau_regle(int **t, int TAILLE) {
    //utilise les fonction pour remplire le tableau a partire des régle
    int i = 0;
    while (tableau_pas_plain(t, TAILLE) && i < TAILLE * TAILLE) {
        fin_tableau(t, TAILLE);
        double_triple_tableau(t, TAILLE);
        comparer_ligne_colone(t, TAILLE);
        i++;
    }
}

void double_triple_tableau(int **t, int TAILLE) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            // pour etre sur que toutes les valeux chercher et sesi existe
            if (j + 1 < TAILLE) {
                //ligne 0110
                if (t[i][j] == 1 && t[i][j + 1] == 1) {
                    if (j != 0 && t[i][j - 1] == -1 && j - 1 > -1) {
                        t[i][j - 1] = 0;
                    }
                    if (j + 1 != TAILLE - 1 && t[i][j + 2] == -1 && j + 2 < TAILLE) {
                        t[i][j + 2] = 0;
                    }
                }

                //ligne 1001
                if (t[i][j] == 0 && t[i][j + 1] == 0) {
                    if (j != 0 && t[i][j - 1] == -1 && j - 1 > -1) {
                        t[i][j - 1] = 1;
                    }
                    if (j + 1 != TAILLE - 1 && t[i][j + 2] == -1 && j + 2 < TAILLE) {
                        t[i][j + 2] = 1;
                    }
                }

                //colone 1001
                if (t[j][i] == 1 && t[j + 1][i] == 1) {
                    if (j != 0 && t[j - 1][i] == -1 && j - 1 > -1) {
                        t[j - 1][i] = 0;
                    }
                    if (j + 1 != TAILLE - 1 && t[j + 2][i] == -1 && j + 2 < TAILLE) {
                        t[j + 2][i] = 0;
                    }
                }

                //colone 0110
                if (t[j][i] == 0 && t[j + 1][i] == 0) {
                    if (j != 0 && t[j - 1][i] == -1 && j - 1 > -1) {
                        t[j - 1][i] = 1;
                    }
                    if (j + 1 != TAILLE - 1 && t[j + 2][i] == -1 && j + 2 < TAILLE) {
                        t[j + 2][i] = 1;
                    }
                }
            }
            if (j + 2 < TAILLE) {
                //ligne 101
                if (t[i][j] == 1 && t[i][j + 1] == -1 && t[i][j + 2] == 1 && j + 1 < TAILLE) {
                    t[i][j + 1] = 0;
                }

                //ligne 010
                if (t[i][j] == 0 && t[i][j + 1] == -1 && t[i][j + 2] == 0 && j + 1 < TAILLE) {
                    t[i][j + 1] = 1;
                }

                //colone 101
                if (t[j][i] == 1 && t[j + 1][i] == -1 && t[j + 2][i] == 1 && j + 1 < TAILLE) {
                    t[j + 1][i] = 0;
                }

                //colone 010
                if (t[j][i] == 0 && t[j + 1][i] == -1 && t[j + 2][i] == 0 && j + 1 < TAILLE) {
                    t[j + 1][i] = 1;
                }
            }
        }
    }
}

void fin_tableau(int **t, int TAILLE) {
    // on regarde si il y a 3 fois 0 / 1 si oui on coplaite la colone/ligne
    for (int i = 0; i < TAILLE; i++) {
        // init des conteur : ligne 1 / ligne 0 // colone 1 / colone 0
        int nomb_1_l = 0, nomb_0_l = 0, nomb_1_c = 0, nomb_0_c = 0;
        // on regarde si il y a 3 fois 0 / 1
        for (int j = 0; j < TAILLE; j++) {
            // on regarde pour les ligne
            if (t[i][j] == 1) {
                nomb_1_l++;
            } else {
                if (t[i][j] == 0) {
                    nomb_0_l++;
                }
            }
            // on regarde pour les colone
            if (t[j][i] == 1) {
                nomb_1_c++;
            } else {
                if (t[j][i] == 0) {
                    nomb_0_c++;
                }
            }
        }

        // si oui on coplaite la ligne
        if (nomb_1_l == TAILLE / 2) {
            ajouter_ligne(t, 0, i, TAILLE);
        }
        if (nomb_0_l == TAILLE / 2) {
            ajouter_ligne(t, 1, i, TAILLE);
        }
        // si oui on coplaite la ligne
        if (nomb_1_c == TAILLE / 2) {
            ajouter_colone(t, 0, i, TAILLE);
        }
        if (nomb_0_c == TAILLE / 2) {
            ajouter_colone(t, 1, i, TAILLE);
        }
    }
}

void comparer_ligne_colone(int **t, int TAILLE) {
    for (int i = 0; i < TAILLE - 1; i++) {
        for (int j = i + 1; j < TAILLE; j++) {
            // init des conteur :
            // ligne 1 / ligne 0
            int conte_l_0 = 0, conte_l_1 = 0;
            // colone 1 / colone 0
            int conte_c_0 = 0, conte_c_1 = 0;
            // ligne -1 / colone -1
            int conte_l_T = 0, conte_c_T = 0;

            //ligne
            for (int m = 0; m < TAILLE; m++) {
                if (t[i][m] == t[j][m] && t[i][m] == 1) {
                    conte_l_1++;
                }
                if (t[i][m] == t[j][m] && t[i][m] == 0) {
                    conte_l_0++;
                }
                if (t[i][m] == -1 || t[j][m] == -1) {
                    conte_l_T++;
                }
            }
            if (conte_l_1 == TAILLE / 2 - 1 && conte_l_T == 2) {
                for (int m = 0; m < TAILLE; m++) {
                    if (t[i][m] == 1 && t[j][m] == -1) {
                        t[j][m] = 0;
                    }
                    if (t[i][m] == -1 && t[j][m] == 1) {
                        t[i][m] = 0;
                    }
                }
            }
            if (conte_l_0 == TAILLE / 2 - 1 && conte_l_T == 2) {
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
            for (int k = 0; k < TAILLE; k++) {
                if (t[k][i] == t[k][j] && t[k][i] == 1) {
                    conte_c_1++;
                }
                if (t[k][i] == t[k][j] && t[k][i] == 0) {
                    conte_c_0++;
                }
                if (t[k][i] == -1 || t[k][j] == -1) {
                    conte_c_T++;
                }
            }
            if (conte_c_1 == TAILLE / 2 - 1 && conte_c_T == 2) {
                for (int k = 0; k < TAILLE; k++) {
                    if (t[k][i] == 1 && t[k][j] == -1) {
                        t[k][j] = 0;
                    }
                    if (t[k][i] == -1 && t[k][j] == 1) {
                        t[k][i] = 0;
                    }
                }
            }
            if (conte_c_0 == TAILLE / 2 - 1 && conte_c_T == 2) {
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

bool verif_ligne(int *t, int TAILLE) {
    // permet de vérifier si la ligne est valide en comptant le nombre de 0 et de 1
    int cpt1 = 0, cpt0 = 0;
    for (int i = 0; i < TAILLE; ++i) {

        if (t[i] == 1)
            cpt1 += 1;
        else if (t[i] == 0)
            cpt0 += 1;

        if (t[i] == t[i + 1] && t[i + 1] == t[i + 2])
            return false;
    }
    if (cpt1 == cpt0)
        return true;
    else
        return false;
}

// pose 1 ou 0, si c'est possible, renvoi : 1 (remplie : 1/0), 0 (si deja complet), -1 (pas de sol)
int remplire_au_hazard(int **t, int *tab, int pose, int TAILLE) {
    int conte = tab[pose], i, j, remplie = 0;
    //si le conte est deja au max -> on le passe a 0
    if (conte > 36) {
        conte = 0;
        tab[pose] = 0;
    }
    i = conte / TAILLE;
    j = conte - (i * TAILLE);
    //utiliser le conte pour optenir la dernier possition teste(x,y du tableau)
    while (i < TAILLE && tab[pose] < 37 && remplie == 0) {
        tab[pose]++;
        //on regarde si la case est vide
        if (t[i][j] == -1) {
            //on repli par 1
            t[i][j] = 1;
            if (false == valider_un_coup(t, i, j, TAILLE)) {
                //si ce n'est pas possible on repli par 0
                t[i][j] = 0;
                if (false == valider_un_coup(t, i, j, TAILLE)) {
                    t[i][j] = -1;
                    //si ça non plus n'est pas possible alors on arrete
                    remplie - 1;
                } else {
                    remplie = 1;
                }
            } else {
                remplie = 1;
            }
        }
        j++;
        if (j >= TAILLE) {
            i++;
            j = 0;
        }
    }
    return remplie;
}

//permet de remplacer une valeur mise au hazard (qui na pas fonctionner et remplacer par 0
bool metre_a_zero(int **t, int val, int TAILLE) {
    //verifier si on ne peut pas replacer le 1 (mi au hazard) a 0
    int x, y;
    x = val / TAILLE;
    y = val - (x * TAILLE);
    t[x][y] = 0;
    return valider_un_tableau(t, TAILLE);
}

void boucle_zero(int **t, int *pose, int ***tab_t, int *tab_n, int TAILLE) {
    // on remplie par zero
    // si ce n'est pas possible, il n'y a pas de solution, donc on revien en arier
    // on teste juscaseque sa marche, ou qu'on retorune au debu
    bool toujour_faux = false;
    if (*pose != 0) {
        *pose = *pose - 1;
    }
    remplire_tableau_avec_tab(t, tab_t[*pose], TAILLE);
    toujour_faux = metre_a_zero(t, tab_n[*pose] - 1, TAILLE);

    //tan que c'est faux on continue
    while (toujour_faux == false && *pose != 0) {
        *pose = *pose - 1;
        remplire_tableau_avec_tab(t, tab_t[*pose], TAILLE);
        toujour_faux = metre_a_zero(t, tab_n[*pose] - 1, TAILLE);
    }
}

//genereration de grille
int generer_lignes(int **line, int TAILLE) {

    //permet de générer toutes les lignes valides possibles et de les stocker dans un tableau dynamique
    int tab_sel[TAILLE], i, tab_inv[TAILLE], j, cptr = 0;
    int size = TAILLE;
    for (int nb = 1; nb < pow(2, TAILLE) + 1; ++nb) {

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
        }
    }
    return cptr;
}

void generer_grille(int **t, int TAILLE) {

    srand(time(NULL));
    //permet de générer une grille de manière aléatoire
    int **line;
    int line_nb;
    line = (int **) malloc(sizeof(int *) * pow(2, TAILLE));
    for (int i = 0; i < pow(2, TAILLE); ++i) {
        line[i] = (int *) malloc(sizeof(int) * TAILLE);
    }

    int cptr = generer_lignes(line, TAILLE);

    while (valider_un_tableau(t, TAILLE) == false) {
        for (int i = 0; i < TAILLE; ++i) {
            for (int j = 0; j < TAILLE; ++j) {
                line_nb = rand() % cptr;
                t[i][j] = line[line_nb][j];
            }
        }
    }
}

void afficher_lignes(int TAILLE) {

    int tab_sel[TAILLE], i, tab_inv[TAILLE], j;
    int size = TAILLE;
    for (int nb = 1; nb < pow(2, TAILLE) + 1; ++nb) {

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
            printf("\nLe nombre binaire est = ");

            for (i = 0; i < TAILLE; i++) {
                printf("%d", tab_sel[i]);
            }
        }
    }
}

void cree_le_masque(int **masque, int **matrice_complaite, int dif, int TAILLE) {
    //creation du masque vide :
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            masque[i][j] = -1;
        }
    }
    int repeter;
    if (TAILLE == 4) {
        repeter = (4 - dif) * (TAILLE / 2);
    } else {
        if (TAILLE == 6) {
            repeter = (4 - dif) * (TAILLE);
        } else {
            repeter = (9 - dif) * (TAILLE);
        }
    }

    // on prend au hazard des chifre de la matrice_complaite
    while (repeter != 0) {
        int i = rand() % TAILLE, j = rand() % TAILLE;
        if (masque[i][j] == -1) {
            masque[i][j] = matrice_complaite[i][j];
            repeter--;
        }
    }
}