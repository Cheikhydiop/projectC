#include "header.h"
#include<string.h>
#include<stdio.h>

#define ROWS 3
#define COLS 3
#define MAX_STRING_LENGTH 1000
#include<string.h>

// void lister(){




// FILE *fichier;
//     char matrice[ROWS][COLS][MAX_STRING_LENGTH];

//     // Ouvrir le fichier en mode lecture
//     fichier = fopen("present.text", "r");

//     if (fichier == NULL) {
//         perror("Erreur lors de l'ouverture du fichier");
//        // return 1; // Quitter le programme en cas d'erreur
//     }

//     // Lire la matrice à partir du fichier
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             fscanf(fichier, "%s", matrice[i][j]);
//         }
//     }

//     // Fermer le fichier
//     fclose(fichier);

//     // Afficher la matrice lue
//     printf("Matrice lue depuis le fichier :\n");
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {

//             if (strcmp(matrice[i][j],"Présent")==0)
//             {
//                printf("%s  %s  ", matrice[i][0],matrice[i][j]);
//             }
           
//         }
//         printf("\n");
//     }




// }
#include "header.h"
#include<string.h>
#include<stdio.h>

#define ROWS 3
#define COLS 3
#define MAX_STRING_LENGTH 1000
#include<string.h>

void lister(){

 char reponse = 'o';
    int i = 0, a;
    char mat[10];
    int conf;
   int pass;
   int sorti;


FILE *fichier;
    char matrice[ROWS][COLS][MAX_STRING_LENGTH];

    // Ouvrir le fichier en mode lecture
    fichier = fopen("password.text", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
       // return 1; // Quitter le programme en cas d'erreur
    }

    // Lire la matrice à partir du fichier
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(fichier, "%s", matrice[i][j]);
        }
    }

    // Fermer le fichier
    fclose(fichier);

    // Afficher la matrice lue

     printf("date");
     scanf("%s",mat);
     
     
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
              
                    if (strcmp(matrice[i][0],mat)!=0)
                    {
                        printf("%s",matrice[i][j]);
                        
                    }else {
                         printf("%s",matrice[i][j]);
                          
                    }
     
        }
     
    }
 
   

     
                                   
}