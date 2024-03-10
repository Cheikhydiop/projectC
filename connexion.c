#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdbool.h>
#include <unistd.h>
#include<time.h>
#include "header.h"

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

   // puts("reassez : ");
    //puts(nom);
}


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
    disableEcho("");
    //scanf("%s", login);
     controle(login);
     
     enableEcho() ;
    
    strcat(mdp, "|");

    strcpy(final, mdp);
    strcat(final, login);
    // strcat(final,"|web");

    strcpy(final2, final);
    strcat(final2, "|admin");
    printf("%s",final2);

    fp = fopen("password.text", "r");

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
                    lister();
                    break;
                case 3:
                     //  marquerPresences();
                       confirmer();
                    break;
                case 4:
                    printf("Envoyer un message.\n");
                    break;
                case 5:
                    printf("Vous venez de quitter le menu Admin\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez réessayer.\n");
            }

            fclose(fp);
            return;
        } else if (strcmp(motDansFichier, final) == 0) {
              
              char id[40];
               strcpy(id,final);
               printf("%s",id);
               menuUser();
               marquerPresences();
               fclose(fp);
               return;
        }
    }

    printf("Le mot de passe ou le login est incorrect.\n");

    
    fclose(fp);
}
  