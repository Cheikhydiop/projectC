#include<stdio.h>

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




int menuUser() {
    int choixU;
    printf("|--------------APPRENANT----------|\n");                                                         
    printf("|1) NOMBRE DE MINUTES D’ABSENCE   |\n");
    printf("|3) MES MESSAGES (0)     |\n");
    printf("|2) MARQUER LES PRÉSENCES      |\n");
    printf("|4) ENVOYER UN MESSAGE         |\n");
    printf("|5) QUITTER                    |\n");
    printf("|-------------------------------|\n");
    printf("\n");  
    printf("selectionner : ");
    scanf("%d", &choixU);
    return choixU;
}

int menuAdmin() {
    int choixA;
    printf("|--------------ADMIN----------|\n");
    printf("|1) GESTION DES ÉTUDIANTS      |\n");
    printf("|2) GÉNÉRATION DE FICHIERS     |\n");
    printf("|3) MARQUER LES PRÉSENCES      |\n");
    printf("|4) ENVOYER UN MESSAGE         |\n");
    printf("|5) QUITTER                    |\n");
    printf("|-------------------------------|\n");

    printf("\n");
    
    printf("Donnez votre choix : ");
   
    scanf("%d", &choixA);
    return choixA;
}