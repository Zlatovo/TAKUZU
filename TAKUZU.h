//
// Created by radol on 06/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define TAILLEL 16



//PARTIE_I

//void creer_tableau_vierge(int *grille_jeu[TAILLEL][TAILLEL], int size);
//void creer_tab_dyn(int** *matrice, int size);
//void saisir_valeurs(int tab [TAILLEL][TAILLEL]);
//PARTIE_II

//PARTIE_III


// Adrien


// modification sur ton project :
//void saisir_valeurs_adrien(int tab[TAILLEL]);
//
//
////matrice
//bool recurence_cree_tableau_AI(int t[TAILLEL][TAILLEL], int *pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL]);
//void trouver_tous_les_solution(int t[TAILLEL][TAILLEL], int tab_parfait[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int *ch);
//
//
////fonction utile :
//void afficher_tableau(int t[TAILLEL][TAILLEL]);
//void remplire_tableau_avec_tab(int t1[TAILLEL][TAILLEL], int t2[TAILLEL][TAILLEL]);
//bool tableau_pas_plain(int t[TAILLEL][TAILLEL]);
//bool comparer_tableau(int t1[TAILLEL][TAILLEL], int t2[TAILLEL][TAILLEL]);
//
////verifier un tableau :
//bool valider_un_coup(int t[TAILLEL][TAILLEL]);
//bool verifeiller_deux_ligne(int t1[TAILLEL], int t2[TAILLEL]);
//
//// permet de metre la "val" dans un espase vide
//void ajouter_ligne(int t[TAILLEL][TAILLEL], int val, int ligne);
//void ajouter_colone(int t[TAILLEL][TAILLEL], int val, int colone);
//
//// regel utiliser pour remplire le tableau
//void tableau_regle(int t[TAILLEL][TAILLEL]);
//void double_triple_tableau(int t[TAILLEL][TAILLEL]);
//void fin_tableau(int t[TAILLEL][TAILLEL]);
//void comparer_ligne_colone(int t[TAILLEL][TAILLEL]);
//
//// pose 1 ou 0, si c'est possible, renvoi : 1 (remplie : 1/0), 0 (si deja complet), -1 (pas de sol)
//int remplire_au_hazard(int t[TAILLEL][TAILLEL], int tab[TAILLEL], int pose);
//
////permet de remplacer une valeur mise au hazard (qui na pas fonctionner et remplacer par 0
//bool metre_a_zero(int t[TAILLEL][TAILLEL], int val);
//void boucle_zero(int t[TAILLEL][TAILLEL], int *pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL]);



//matrice
bool recurence_cree_tableau_AI(int **t, int *pose, int ***tab_t, int *tab_n, int TAILLE);
void trouver_tous_les_solution(int **t, int ***tab_parfait, int *ch, int TAILLE);

//fonction utile :
void afficher_tableau(int **t, int TAILLE);
void remplire_tableau_avec_tab(int **t1, int **t2, int TAILLE);
bool tableau_pas_plain(int **t, int TAILLE);
bool comparer_tableau(int **t1, int **t2, int TAILLE);

//verifier un tableau :
bool valider_un_coup(int **t, int TAILLE);
bool verifeiller_deux_ligne(int *t1, int *t2, int TAILLE);

// permet de metre la "val" dans un espase vide
void ajouter_ligne(int **t, int val, int ligne, int TAILLE);
void ajouter_colone(int **t, int val, int colone, int TAILLE);

// regel utiliser pour remplire le tableau
void tableau_regle(int **t, int TAILLE);
void double_triple_tableau(int **t, int TAILLE);
void fin_tableau(int **t, int TAILLE);
void comparer_ligne_colone(int **t, int TAILLE);

// pose 1 ou 0, si c'est possible, renvoi : 1 (remplie : 1/0), 0 (si deja complet), -1 (pas de sol)
int remplire_au_hazard(int **t, int *tab, int pose, int TAILLE);

//permet de remplacer une valeur mise au hazard (qui na pas fonctionner et remplacer par 0
bool metre_a_zero(int **t, int val, int TAILLE);
void boucle_zero(int **t, int *pose, int ***tab_t, int *tab_n, int TAILLE);




#endif //TAKUZU_TAKUZU_H