#include "TAKUZU.h"

int main() {
    srand(time(NULL));
    bool star = true;
    char commentcer = 'a';
    printf("Bienvenue au jeu TAKUZU programme par Adrien et Luka\n");
    while (star == true) {
        //si l'utilisateur veux commencer a jouer :
        printf("Voulez-vous commencer une partie y/n : ");
        while (commentcer != 'y' && commentcer != 'n') {
            scanf("%c", &commentcer);
            printf("\n");
        }
        if (commentcer == 'y') {
            star_game_Takuzu();
            printf("\n\n\n");
        } else {
            star = false;
        }
        commentcer = 'a';
    }
    printf("Merci d'avoir jouer a notre jeu.\n");

}
