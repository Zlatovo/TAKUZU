//
// Created by radol on 06/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#define TAILLEL 6



//PARTIE_I

//void creer_tableau_vierge(int *grille_jeu[TAILLE][TAILLE], int size);
//void creer_tab_dyn(int** *matrice, int size);
//void saisir_valeurs(int tab [TAILLE][TAILLE]);
//PARTIE_II

//PARTIE_III


// Adrien


// modification sur ton project :
void saisir_valeurs_adrien(int **t, int *coup_du_jouer, int TAILLE);
void regle_du_jeux();



//menu / jeux
void star_game_Takuzu();
void menu(int *dif, int *largeur);
void cree_la_matrise_plaine(int **matrice_complaite, int largeur, int TAILLE);
void cree_le_masque(int **masque, int **matrice_complaite, int dif, int TAILLE);
void commencer_a_joux(int **t, int **matrice_complaite, int TAILLE, int *vie_du_joueur);
void game_over(int ***tab_parfait, int ch, int **masque, int TAILLE);

//matrice
bool recurence_cree_tableau_AI(int **t, int *pose, int ***tab_t, int *tab_n, int TAILLE);
void trouver_tous_les_solution(int **t, int ***tab_parfait, int *ch, int TAILLE);

//fonction utile :
void afficher_tableau(int **t, int TAILLE);
void remplire_tableau_avec_tab(int **t1, int **t2, int TAILLE);
bool tableau_pas_plain(int **t, int TAILLE);
bool comparer_tableau(int **t1, int **t2, int TAILLE);

//verifier un tableau :
bool valider_un_tableau(int **t, int TAILLE);
bool valider_un_coup(int **t, int l, int c, int TAILLE);
bool verifeiller_deux_ligne(int *t1, int *t2, int TAILLE);

// permet de metre la "val" dans un espase vide
void ajouter_ligne(int **t, int val, int ligne, int TAILLE);
void ajouter_colone(int **t, int val, int colone, int TAILLE);

// regel utiliser pour remplire le tableau
void tableau_regle(int **t, int TAILLE);
void double_triple_tableau(int **t, int TAILLE);
void fin_tableau(int **t, int TAILLE);
void comparer_ligne_colone(int **t, int TAILLE);
bool verif_ligne(int *t, int TAILLE);

// pose 1 ou 0, si c'est possible, renvoi : 1 (remplie : 1/0), 0 (si deja complet), -1 (pas de sol)
int remplire_au_hazard(int **t, int *tab, int pose, int TAILLE);

//permet de remplacer une valeur mise au hazard (qui na pas fonctionner et remplacer par 0
bool metre_a_zero(int **t, int val, int TAILLE);
void boucle_zero(int **t, int *pose, int ***tab_t, int *tab_n, int TAILLE);

//generation de lignes
bool generer_lignes(int TAILLE);




#endif //TAKUZU_TAKUZU_H