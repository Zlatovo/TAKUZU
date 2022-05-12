//
// Created by radol on 06/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 4


//PARTIE_I

void creer_tableau_vierge(int *grille_jeu[TAILLE][TAILLE], int size);
void creer_tab_dyn(int** *matrice, int size);
void saisir_valeurs(int tab [TAILLE][TAILLE]);
//PARTIE_II

//PARTIE_III


// Adrien

#define TAILLEL 16
#include <stdbool.h>

//partie I
bool verifeiller_deux_ligne(int t1[TAILLEL], int t2[TAILLEL]);
bool valider_un_coup(int t[TAILLEL][TAILLEL]);
void afficher_tableau(int t[TAILLEL][TAILLEL]);

bool tableau_pas_plain(int t[TAILLEL][TAILLEL]);

void ajouter_ligne(int t[TAILLEL][TAILLEL], int val, int ligne);
void ajouter_colone(int t[TAILLEL][TAILLEL], int val, int colone);
void double_triple_tableau(int t[TAILLEL][TAILLEL]);
void fin_tableau(int t[TAILLEL][TAILLEL]);
void comparer_ligne_colone(int t[TAILLEL][TAILLEL]);

void tableau_regle(int t[TAILLEL][TAILLEL]);
void remplire_tableau_avec_tab(int t1[TAILLEL][TAILLEL], int t2[TAILLEL][TAILLEL]);

int remplire_au_hazard(int t[TAILLEL][TAILLEL], int tab[TAILLEL], int pose);
//partie II
bool comparer_tableau(int t1[TAILLEL][TAILLEL], int t2[TAILLEL][TAILLEL]);
bool recurence_cree_tableau_AI(int t[TAILLEL][TAILLEL], int *pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL]);
void trouver_tous_les_solution(int t[TAILLEL][TAILLEL], int tab_parfait[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int *ch);
bool metre_a_zero(int t[TAILLEL][TAILLEL], int val);
void boucle_zero(int t[TAILLEL][TAILLEL], int *pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL]);
//partie III

#endif //TAKUZU_TAKUZU_H