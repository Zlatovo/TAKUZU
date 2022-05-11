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

#include <stdbool.h>

//partie I
bool verifeiller_deux_ligne(int t1[TAILLE], int t2[TAILLE]);
bool valider_un_coup(int t[TAILLE][TAILLE]);
bool valider_un_coup_unique(int t[TAILLE][TAILLE], int l, int c);
void afficher_tableau(int t[TAILLE][TAILLE]);
bool tableau_plain(int t[TAILLE][TAILLE]);
void ajouter_ligne(int t[TAILLE][TAILLE], int val, int ligne);
void ajouter_colone(int t[TAILLE][TAILLE], int val, int colone);
void double_triple_tableau(int t[TAILLE][TAILLE]);
void fin_tableau(int t[TAILLE][TAILLE]);
void comparer_ligne_colone(int t[TAILLE][TAILLE]);
void identique(int t[TAILLE][TAILLE]);
bool remplire_au_hazard(int t[TAILLE][TAILLE],int conte, int tab[TAILLE], int pose);
bool recurence_verifier_tableau(int t[TAILLE][TAILLE], int conte, int tab[TAILLE], int pose);
//partie II
void recurence_cree_tableau_AI(int t[TAILLE][TAILLE], int conte, int pose, int tab_t[TAILLE*TAILLE][TAILLE][TAILLE], int tab_n[TAILLE*TAILLE], int ch, int tab_parfait[TAILLE*TAILLE][TAILLE][TAILLE]);
//partie III

#endif //TAKUZU_TAKUZU_H