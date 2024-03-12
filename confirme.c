#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000
#define MAX_MAT_LENGTH 10

void confirmer() {
    char reponse;
    char mat[MAX_MAT_LENGTH];
    char date[30];
    int sortie = 0;
    time_t t;
    struct tm *infoTemps;

    FILE *fichier;
    char ligne[MAX_STRING_LENGTH];

    time(&t);
    infoTemps = localtime(&t);
    strftime(date, sizeof(date), "%Y-%m-%d ", infoTemps);

    // Ouvrir le fichier en mode lecture/écriture
    fichier = fopen("present.text", "a+");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Boucle principale
    do {
        printf("Matricule : ");
        scanf("%s", mat);

        // Réinitialiser la position du curseur dans le fichier
        rewind(fichier);

        int etudiantValide = 0;

        // Lire chaque ligne du fichier et comparer avec le matricule
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char matriculeFichier[MAX_MAT_LENGTH];
            sscanf(ligne, "%s", matriculeFichier);

            if (strcmp(matriculeFichier, mat) == 0) {
                etudiantValide = 1;

                // Rechercher la date dans la ligne actuelle
                char *datePresent = strstr(ligne, date);

                if (datePresent != NULL) {
                    printf("L'étudiant a déjà été marqué présent aujourd'hui.\n");
                } else {
                    printf("Présence marquée avec succès.\n");
                    fprintf(fichier, "%s %s Présent\n", mat, date);
                }

                break;
            }
        }

        if (!etudiantValide) {
            printf("Étudiant invalide.\n");
        }

        printf("Voulez-vous continuer (o/n) : ");
        scanf(" %c", &reponse);

        if (reponse == 'n') {
            int deconnexionReussie = 0;

            do {
                printf("Voulez-vous déconnecter (q) : ");
                scanf(" %c", &reponse);

                if (reponse == 'q') {
                    FILE *fp;
                    char mdp[20];
                    char login[20];
                    char motDansFichier[20];
                    char final[100];
                    char final2[100];

                    printf("Entrez le login: ");
                    scanf("%s", mdp);

                    printf("Entrez le mot de passe : ");
                    scanf("%s", login);

                    strcat(mdp, "|");

                    strcpy(final, mdp);
                    strcat(final, login);

                    strcpy(final2, final);
                    strcat(final2, "|admin");
                    printf("%s", final2);

                    fp = fopen("password.text", "r");

                    if (fp == NULL) {
                        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
                        return;
                    }

                    while (fscanf(fp, "%s", motDansFichier) != EOF) {
                        if (strcmp(motDansFichier, final2) == 0) {
                            printf("Déconnexion réussie.\n");
                            deconnexionReussie = 1;
                            break;
                        }
                    }

                    fclose(fp);

                    if (!deconnexionReussie) {
                        printf("Matricule de déconnexion invalide.\n");
                    }
                }
            } while (reponse == 'q' && !deconnexionReussie);

            sortie = 0; // Reste dans la boucle principale
        }

    } while (sortie != 1);

    // Fermer le fichier
    fclose(fichier);
}
