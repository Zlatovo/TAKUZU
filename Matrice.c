//
// Created by Adrien Pouyat on 12/05/2022.
//
#include "TAKUZU.h"

bool recurence_cree_tableau_AI(int **t, int *pose, int ***tab_t, int *tab_n, int TAILLE){
    if (tab_n[1] == 36) {
        return true;
    } else {
        //utiliser les regle du TAKUZU pour remplire au maximum le tableau
        tableau_regle(t, TAILLE);
        if (false == tableau_pas_plain(t, TAILLE) && true == valider_un_tableau(t, TAILLE) && *pose == 0) {
            return true;
        } else {
            //si le tableau est remple verifier si il est corect
            if (false == tableau_pas_plain(t, TAILLE) && false == valider_un_tableau(t, TAILLE)) {
                //si il est faut on recomence
                boucle_zero(t, pose, tab_t, tab_n, TAILLE);
                return recurence_cree_tableau_AI(t, pose, tab_t, tab_n, TAILLE);
            } else {
                if (false == valider_un_tableau(t, TAILLE)) {
                    //si il est faut on recomence
                    boucle_zero(t, pose, tab_t, tab_n, TAILLE);
                    return recurence_cree_tableau_AI(t, pose, tab_t, tab_n, TAILLE);
                } else {
                    if (tableau_pas_plain(t, TAILLE)) {
                        remplire_tableau_avec_tab(tab_t[*pose], t, TAILLE);
                        //le tableau copleté avec les regle (mais pas complait), on le continue au hazard
                        int a = remplire_au_hazard(t, tab_n, *pose, TAILLE);
                        if (a == 1) {
                            //il n'y a pas d'ereur on rapele la fonction  et on passe a l'iteration suivente ppur pose
                            *pose = *pose +1;
                            return recurence_cree_tableau_AI(t, pose, tab_t, tab_n, TAILLE);
                        } else {
                            //si il est faut on recomence
                            boucle_zero(t, pose, tab_t, tab_n, TAILLE);
                            return recurence_cree_tableau_AI(t, pose, tab_t, tab_n, TAILLE);
                        }
                    }
                }
                //le tableau est coplais et corecte mais on a pas trouver tous les solution donc on retourne "false"
                return false;
            }
        }
    }
}

void trouver_tous_les_solution(int **t, int ***tab_parfait, int *ch, int TAILLE){

    bool valider_la_fin = false;
    int pose = 0, ***tab_t,*tab_n;

    tab_n=(int*)malloc(TAILLE*TAILLE * sizeof(int*));
    // cree espase pour tab_t
    tab_t = (int***)malloc(TAILLE*TAILLE * sizeof(int*));
    for (int i = 0; i<TAILLE*TAILLE; i++){
        tab_t[i] = (int**)malloc(TAILLE * sizeof(int*));
        for (int j = 0; j<TAILLE; j++){
            tab_t[i][j] = (int *) calloc ( TAILLE, sizeof(int));
        }
    }

    for (int b = 0; b<TAILLE*TAILLE; b++){
        tab_n[b] = 0;
    }
    while (valider_la_fin == false){
        valider_la_fin = recurence_cree_tableau_AI(t, &pose, tab_t, tab_n, TAILLE);
        if (valider_la_fin == false){
            bool passe = true;
            int q = 0;
            // on verifi si la solution donner n'existe pas deja / si le tableau a d'eja une solution
            while (q < *ch && passe == true && *ch != 0) {
                passe = comparer_tableau(tab_parfait[*ch - 1], t, TAILLE);
                q++;
            }

            // si c'est une nouvel solution => ajouter au tableau des solution
            if (passe) {
                remplire_tableau_avec_tab(tab_parfait[*ch], t, TAILLE);
                *ch = *ch + 1;
            }
            //on retourne au tableau pres remplie enregistrer en dernier dans tab_t
            if (pose != 0){
                pose--;
            }
            remplire_tableau_avec_tab(t, tab_t[pose], TAILLE);

        } else {
            if (pose == 0 && tab_n[pose] == 0){
                    remplire_tableau_avec_tab(tab_parfait[*ch], t, TAILLE);
                    *ch = *ch + 1;
            }
        }
    }
}