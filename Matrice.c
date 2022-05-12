//
// Created by Adrien Pouyat on 12/05/2022.
//
#include "TAKUZU.h"

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

bool recurence_cree_tableau_AI(int t[TAILLEL][TAILLEL], int *pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL]){
    if (tab_n[1] == 36) {
        return true;
    } else {

        //utiliser les regle du TAKUZU pour remplire au maximum le tableau
        tableau_regle(t);
        if (false == tableau_pas_plain(t) && true == valider_un_coup(t) && *pose == 0) {
            return true;
        } else {
            //si le tableau est remple verifier si il est corect
            if (false == tableau_pas_plain(t) && false == valider_un_coup(t)) {
                //si il est faut on recomence
                boucle_zero(t, pose, tab_t, tab_n);
                return recurence_cree_tableau_AI(t, pose, tab_t, tab_n);
            } else {
                if (false == valider_un_coup(t)) {
                    //si il est faut on recomence
                    boucle_zero(t, pose, tab_t, tab_n);
                    return recurence_cree_tableau_AI(t, pose, tab_t, tab_n);
                } else {
                    if (tableau_pas_plain(t)) {
                        remplire_tableau_avec_tab(tab_t[*pose], t);
                        //le tableau copleté avec les regle (mais pas complait), on le continue au hazard
                        int a = remplire_au_hazard(t, tab_n, *pose);
                        if (a == 1) {
                            //il n'y a pas d'ereur on rapele la fonction  et on passe a l'iteration suivente ppur pose
                            *pose = *pose +1;
                            return recurence_cree_tableau_AI(t, pose, tab_t, tab_n);
                        } else {
                            //si il est faut on recomence
                            boucle_zero(t, pose, tab_t, tab_n);
                            return recurence_cree_tableau_AI(t, pose, tab_t, tab_n);
                        }
                    }
                }
                //le tableau est coplais et corecte mais on a pas trouver tous les solution donc on retourne "false"
                return false;
            }
        }
    }
}

void trouver_tous_les_solution(int t[TAILLEL][TAILLEL], int tab_parfait[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int *ch){
    bool valider_la_fin = false;
    int pose = 0, tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL],tab_n[TAILLEL*TAILLEL];
    for (int b = 0; b<TAILLEL*TAILLEL; b++){
        tab_n[b] = 0;
    }
    while (valider_la_fin == false){
        valider_la_fin = recurence_cree_tableau_AI(t, &pose, tab_t, tab_n);
        if (valider_la_fin == false){
            bool passe = true;
            int q = 0;

            // on verifi si la solution donner n'existe pas deja / si le tableau a d'eja une solution
            while (q < *ch && passe == true && *ch != 0) {
                passe = comparer_tableau(tab_parfait[*ch - 1], t);
                q++;
            }

            // si c'est une nouvel solution => ajouter au tableau des solution
            if (passe) {
                remplire_tableau_avec_tab(tab_parfait[*ch], t);
                *ch = *ch + 1;
            }
            //on retourne au tableau pres remplie enregistrer en dernier dans tab_t
            if (pose != 0){
                pose--;
            }
            remplire_tableau_avec_tab(t, tab_t[pose]);

        } else {
            if (pose == 0 && tab_n[pose] == 0){
                    remplire_tableau_avec_tab(tab_parfait[*ch], t);
                    *ch = *ch + 1;
            }
        }
    }




}