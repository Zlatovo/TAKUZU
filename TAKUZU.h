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

#define TAILLEL 6
#include <stdbool.h>

//partie I
bool verifeiller_deux_ligne(int t1[TAILLEL], int t2[TAILLEL]);
bool valider_un_coup(int t[TAILLEL][TAILLEL]);
void afficher_tableau(int t[TAILLEL][TAILLEL]);
bool tableau_plain(int t[TAILLEL][TAILLEL]);
void ajouter_ligne(int t[TAILLEL][TAILLEL], int val, int ligne);
void ajouter_colone(int t[TAILLEL][TAILLEL], int val, int colone);
void double_triple_tableau(int t[TAILLEL][TAILLEL]);
void fin_tableau(int t[TAILLEL][TAILLEL]);
void comparer_ligne_colone(int t[TAILLEL][TAILLEL]);
void identique(int t[TAILLEL][TAILLEL]);
bool remplire_au_hazard(int t[TAILLEL][TAILLEL],int conte, int tab[TAILLEL], int pose);
bool recurence_verifier_tableau(int t[TAILLEL][TAILLEL], int conte, int tab[TAILLEL], int pose);
//partie II
bool comparer_tableau(int tab_parfait[TAILLEL][TAILLEL], int t[TAILLEL][TAILLEL]);
void recurence_cree_tableau_AI(int t[TAILLEL][TAILLEL], int conte, int pose, int tab_t[TAILLEL*TAILLEL][TAILLEL][TAILLEL], int tab_n[TAILLEL*TAILLEL], int *ch, int tab_parfait[TAILLEL*TAILLEL][TAILLEL][TAILLEL]);
//partie III

#endif //TAKUZU_TAKUZU_H