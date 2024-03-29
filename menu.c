//
// Created by Adrien Pouyat and Luka Radovanovic on 12/05/2022.
//Fichier permettant d'y stocker les fonctions excécutées pour jouer
//
#include "TAKUZU.h"

void star_game_Takuzu() {
    // on inisialise tout les parametre d'on on aura besoin
    int TAILLE, **t, ch = 0, ***tab_parfait, dif = 0, **matrice_complaite, **masque, vie_du_joueur = 2;

    // cree espase pour t
    t = (int **) malloc(TAILLE * sizeof(int *));
    for (int i = 0; i < TAILLE; i++) {
        /*allocation d'un tableau de tableau*/
        t[i] = (int *) calloc(TAILLE, sizeof(int));
    }

    // cree espase pour matrice_complaite
    matrice_complaite = (int **) malloc(TAILLE * sizeof(int *));
    for (int i = 0; i < TAILLE; i++) {
        /*allocation d'un tableau de tableau*/
        matrice_complaite[i] = (int *) calloc(TAILLE, sizeof(int));
    }

    // cree espase pour masque
    masque = (int **) malloc(TAILLE * sizeof(int *));
    for (int i = 0; i < TAILLE; i++) {
        /*allocation d'un tableau de tableau*/
        masque[i] = (int *) calloc(TAILLE, sizeof(int));
    }

    // cree espase pour tab_parfait
    tab_parfait = (int ***) malloc(TAILLE * TAILLE * sizeof(int *));
    for (int i = 0; i < TAILLE * TAILLE; i++) {
        tab_parfait[i] = (int **) malloc(TAILLE * sizeof(int *));
        for (int j = 0; j < TAILLE; j++) {
            tab_parfait[i][j] = (int *) calloc(TAILLE, sizeof(int));
        }
    }

    //commencement du jeux
    menu(&dif, &TAILLE);
    //creeation de la partie
    generer_grille(matrice_complaite, TAILLE);
    cree_le_masque(masque, matrice_complaite, dif, TAILLE);

    //remplire t avec le masque
    remplire_tableau_avec_tab(t, masque, TAILLE);
    //le programe lui trouve toutes les solution
    trouver_tous_les_solution(masque, tab_parfait, &ch, TAILLE);
    //on remet le masque a sont etat original
    remplire_tableau_avec_tab(masque, t, TAILLE);


    //// on verifi si l'une des solutions trouver par le programe est bonne :
    //bool corecte = false;
    //int i = 0;
    //while (corecte == false && i<ch){
    //    corecte = comparer_tableau(tab_parfait[i], t, TAILLE);
    //    i++;
    //}
    //if (corecte == false){
    //    // si ce n'est pas le cas on met comme solution unique le tableau de depard
    //    printf(" Il y a eu une erreur\n");
    //    printf("La ou les solution(s) trouver par l'ordinateur n'est pas corecte\n");
    //    printf("Contacter nous au : 345334.... pour plus d'information\n");
    //    remplire_tableau_avec_tab(tab_parfait[0], matrice_complaite, TAILLE);
    //    ch = 1;
    //    sleep(4);
    //}


    //au tour du joueur
    commencer_a_joux(t, matrice_complaite, TAILLE, &vie_du_joueur, masque);
    if (vie_du_joueur == 0) {
        game_over(tab_parfait, ch, masque, TAILLE);
    }
}

void menu(int *dif, int *largeur) {
    char mot = 'o';
    // le menu demande :
    //si l'utilisateur veux voire les regle :
    printf("Voulez vous lire les regles du jeu avant de commencer ? y/n\n ");
    while (mot != 'y' && mot != 'n') {
        scanf("%c", &mot);
    }
    if (mot == 'y') {
        regle_du_jeux();
        printf("\n\n\n");
    }
    //le niveux et la taille de la grille
    printf("Indiquez la difficulte et la taille de la grille :\n");
    while (*dif < 1 || *dif > 4 || (*largeur != 4 && *largeur != 6 && *largeur != 8 && *largeur != 16)) {
        printf("La difficulte doit etre comprise entre 1 et 3 : \n");
        scanf("%d", dif);
        printf("La taille doit etre 4/6/8/16 : \n");
        scanf("%d", largeur);
    }
}

void commencer_a_joux(int **t, int **matrice_complaite, int TAILLE, int *vie_du_joueur, int **masque) {
    //on commentce par cree une liste dans la quel on ecrie se que le jouer veux
    int *coup_du_jouer;
    coup_du_jouer = (int *) malloc(3 * sizeof(int *));
    afficher_tableau(t, TAILLE);
    // tant que le tableau n'est pas completer ou que le joueur est mort on continue
    while (tableau_pas_plain(t, TAILLE) && *vie_du_joueur != 0) {
        bool passer = false;
        while (passer == false && *vie_du_joueur != 0) {
            // on demmande la valeur et la position
            saisir_valeurs_adrien(t, coup_du_jouer, TAILLE);
            t[coup_du_jouer[1]][coup_du_jouer[2]] = coup_du_jouer[0];
            // on regarde si c'est juste ou pas
            passer = valider_un_coup(t, coup_du_jouer[1], coup_du_jouer[2], TAILLE);
            if (passer == false) {
                // si non on retire une vie et on aide si c'est possible
                tableau_regle(t, TAILLE);
                *vie_du_joueur = *vie_du_joueur - 1;
                t[coup_du_jouer[1]][coup_du_jouer[2]] = -1;
                printf("Il ne vous reste plus que %d vie\n", *vie_du_joueur + 1);
                sleep(4);
            } else {
                if (matrice_complaite[coup_du_jouer[1]][coup_du_jouer[2]] != coup_du_jouer[0]) {
                    printf("Coup valide mais incorrect !\n");
                    printf("Il respecte les regle mais n'est pas celui attendu.\n");
                    printf("Vous avez toujours %d vie\n", *vie_du_joueur + 1);
                    t[coup_du_jouer[1]][coup_du_jouer[2]] = -1;
                    sleep(3);
                }
            }
            afficher_tableau(t, TAILLE);
        }
    }
}

void game_over(int ***tab_parfait, int ch, int **masque, int TAILLE) {
    char mot = 'o';
    printf("vous n'avez pas reussi, car vous avez commis 3 erreur\n");
    printf("le tableau de base etait : \n");
    afficher_tableau(masque, TAILLE);
    printf("voulez vous voir la solution y/n : ");
    while (mot != 'y' && mot != 'n') {
        scanf("%c", &mot);
    }
    if (mot == 'y') {
        printf("la/les solution(s) est/sont :\n\n");
        for (int i = 0; i < ch; i++) {
            afficher_tableau(tab_parfait[i], TAILLE);
            printf("\n");
        }
    }
}
