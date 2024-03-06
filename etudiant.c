#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
int menu() {
    int choix;
  
            printf("|---------------------------|\n");
    printf("|1) Connexion               |\n");
    printf("|5) Quitter                 |\n");
    printf("|---------------------------|\n");

    printf("\n");
   
    
    

    printf("Donnez votre choix : ");
    scanf("%d", &choix);
    return choix;
     
}

int menuAdmin() {
    int choix;
    printf("|--------------ADMIN----------|\n");
    printf("|1) GESTION DES ÉTUDIANTS      |\n");
    printf("|2) GÉNÉRATION DE FICHIERS     |\n");
    printf("|3) MARQUER LES PRÉSENCES      |\n");
    printf("|4) ENVOYER UN MESSAGE         |\n");
    printf("|5) QUITTER                    |\n");
    printf("|-------------------------------|\n");

    printf("\n");
    
    printf("Donnez votre choix : ");
   
    scanf("%d", &choix);
    return choix;
}
int menuListe() {
    int choix;
    printf("|--------Liste  Class----------|\n");
    printf("|1)          DEV WEB           |\n");
    printf("|2)           DATA             |\n");
    printf("|5) QUITTER                    |\n");
    printf("|-------------------------------|\n");

    printf("\n");
    
    printf("selectionner : ");
   
    scanf("%d", &choix);
    return choix;
}

int menuclass(){
    int choix=menuListe();
    switch (choix)
    {
    case 1: printf("bonjour");
        /* code */
        break;
    
    default:
        break;
    }
}
//douvewane85@gmail.com
//niangalytall@
int menuUser() {
    int choix;
    printf("|--------------APPRENANT----------|\n");                                                         
    printf("|1) NOMBRE DE MINUTES D’ABSENCE   |\n");
    printf("|3) MES MESSAGES (0)     |\n");
    printf("|2) MARQUER LES PRÉSENCES      |\n");
    printf("|4) ENVOYER UN MESSAGE         |\n");
    printf("|5) QUITTER                    |\n");
    printf("|-------------------------------|\n");
    printf("\n");  
    printf("selectionner : ");
    scanf("%d", &choix);
    menuListe();
    return choix;
}





void disableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void enableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);}


void controle(char *nom) {
    char nm;
    int i = 0, taille = 0;

    while (1) {
        
        nm = getchar();

        while (nm != '\n') {
            if (nm != ' ') {
                nom[i] = nm;
                i++;
            } else {
                taille++;
            }

            nm = getchar();
        }

     
        nom[i] = '\0';

        if (i != 0) {
            if (taille != strlen(nom)) {
                break;
            }
        }
    }

    puts("reassez : ");
    //puts(nom);
}

// int main() {
//     char nom[100]; // Vous pouvez ajuster la taille selon vos besoins
//     controle(nom);

//     return 0;
// }






void marquerPresences(){
 menuListe();
};





void connexion() {
    FILE *fp;
    char mdp[20];
    char login[20];
    char motDansFichier[20];
    char final[100];
    char final2[100];
        
    printf("Entrez le login: ");
    // printf("Entrez le mot de passe : ");
    // scanf("%s", mdp);
    controle(mdp);
   
    

    printf("Entrez le mot de passe : ");
    disableEcho();
    //scanf("%s", login);
     controle(login);
     enableEcho() ;
    
    strcat(mdp, "|");

    strcpy(final, mdp);
    strcat(final, login);

    strcpy(final2, final);
    strcat(final2, "|admin");

    fp = fopen("monfichier.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        return; 
    }


    while (fscanf(fp, "%s", motDansFichier) != EOF) {
        
        if (strcmp(motDansFichier, final2) == 0) {
            int choixAdmin = menuAdmin();

            switch (choixAdmin) {
                case 1:
                    printf("Opérations de gestion des étudiants.\n");
                    break;
                case 2:
                    printf("Génération de fichiers.\n");
                    break;
                case 31:
                    printf("Marquer les présences.\n");
                    break;
                case 4:
                    printf("Envoyer un message.\n");
                    break;
                case 5:
                    printf("Quitter.\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez réessayer.\n");
            }

            fclose(fp);
            return;
        } else if (strcmp(motDansFichier, final) == 0) {
               menuUser();
            fclose(fp);
            return;
        }
    }

    printf("Le mot de passe ou le login est incorrect.\n");

    
    fclose(fp);
}










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








