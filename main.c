#include "header.h"
#include<stdio.h>
 int main() {
    int choix;

    do {
        choix = menu();

        switch (choix) {
            case 1:
                connexion();
                break;
            case 2:;
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 7);



return 0;
}
