#include "TAKUZU.h"

int main() {
    bool star = true;
    char commentcer = 'a';
    printf("Bienvenu au jeux TAKUZU progrmer par Adrien et Luka\n");
    while (star == true){
        //si l'utilisateur veux commencer a jouer :
        while (commentcer != 'y' && commentcer != 'n'){
            printf("Voulez-vous commencer une partie y/n : ");
            scanf("%c", &commentcer);
            printf("\n");
        }
        if (commentcer == 'y'){
            star_game_Takuzu();
            printf("\n\n\n");
        } else {
            star = false;
        }
    }
    printf("Merci d'avoir jouer a notre jeux.\n");

    //generer_lignes(TAILLEL);
}