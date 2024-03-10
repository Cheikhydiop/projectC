#include "header.h"
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#define ROWS 10
#define COLS 10
#define MAX_STRING_LENGTH 100
#include<string.h>

void marquerPresences() {
    char final[20];
    char line[100];
    char token2[100];
    char tem[40];

    
    FILE *fp;
    FILE *p;

    printf("Matricule: ");
    scanf("%s", final);

    strcpy(tem,final);
    strcat(tem," ");

    fp = fopen("password.text", "a+");
   // p = fopen("present.text", "a+");

    if (fp == NULL ) {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        return;
    }

    char date[30];
    time_t t;
    struct tm *infoTemps;

    time(&t);
    infoTemps = localtime(&t);
    strftime(date, sizeof(date), "%Y-%m-%d", infoTemps);
    //strcpy(final,strcat(" ",date));
   // printf("%s",final);
         printf(" final%s\n",final);
    // Vérifier si l'étudiant est déjà présent pour la date actuelle
    while (fscanf(fp, "%s", line) != EOF) {
        if (strcmp(line, final) == 0) {
             printf(" final%s\n",final);
          
            fseek(fp, -strlen(line), SEEK_CUR);
        
            // Vérifier si l'étudiant est déjà marqué présent aujourd'hui
            while (fgets(line, sizeof(line), fp) != NULL) {
                char *token = strtok(line, " ");
                token = strtok(NULL, " ");
                
                           strcat(tem,date);
                           printf(" ftoken %s\n",date);








                  
                  
                   char matrice[ROWS][COLS][MAX_STRING_LENGTH];
             

                    // Lire la matrice à partir du fichier
                    for (int i = 0; i < ROWS; i++) {
                        for (int j = 0; j < COLS; j++) {
                            fscanf(fp, "%s", matrice[i][j]);
                        }
                    }
        

                 for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLS; j++) {
                        
                    if ( strcmp(matrice[i][0],final )==0 )
                    {
                          
                           printf("code %s\n",matrice[i][0]);
                              printf("code %s\n",matrice[i][1]);
                        
                         if ( strcmp(matrice[i][1],date )!=0 )
                         {
                          printf("Présence marquée avec succès.\n");
                         fprintf(fp, "%s %s Présent\n", final, date);
                         break;
                            
                         }else{
                            printf("deja marquer");
                         }
                   
                   
                    }
                    fseek(fp, i, SEEK_CUR);
                    // else{`
                    //       fprintf(fp, "%s %s Présent\n", final, date);
                    //       printf("Présence marqu`ée avec succès.\n");
                  
                    //      fclose(fp);
                    //      return;
                    // }
                          
                        }
                    
                    }
 





















                
                // if (token != NULL && strcmp(tem,final) != 0) {
                 
                  
                //      fprintf(fp, "%s %s Présent\n", final, date);
                //       printf("Présence marquée avec succès.\n");
                  
                //     fclose(fp);
                   
                //     return;
                // }
                        //       fprintf(fp, "%s %s Présent\n", final, date);
                        //    printf("Présence marquée avec succès.\n");
                  
                      fclose(fp);
                      return;
            }
           

            // Si l'étudiant n'est pas présent aujourd'hui, ajouter l'entrée
            
         
            
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("Étudiant non trouvé.\n");
}
