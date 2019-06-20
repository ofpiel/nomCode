#include <stdio.h>
#include <string.h>
#include "line.h"
/*
* Fonction qui supprime une ligne d'un fichier
*/
/*
* Fonction pour modifier l'etat de la ligne dans un fichier 
*/
void modifier_ligne_etat(FILE* fichier,int number)
{ 
   ligne lm;
   ligne* ptligne=NULL,*linterm=NULL,*pt=NULL; 

  if(1)
  { 
    printf("\nprocessus de modification..\n");
    ptligne=copie_fichier(fichier);
   if(ptligne!=NULL)
    
    printf("FIN DE COPIE,lancement de modification..\n");
    ligne* lc=NULL;
  lc=ptligne;
  
  
//recherche de la ligne a attribuer
  while((ptligne!=NULL)&&(ptligne->numero!=number))
  { 
   ptligne=ptligne->suivant;
  }
  if((ptligne!=NULL)&&(ptligne->numero==number))
  {
   
  ptligne->etat = 0;
  }
    ptligne = lc;
    printf("FIN DE la modification..\n");
    fichier=fopen("ligne.txt","w");
  
  if(fichier!=NULL)   
  { printf("Transfert des donnees..\n");
    while(ptligne!=NULL)
    { 
          lm=(*ptligne);
          ptligne=ptligne->suivant; 
        fprintf(f,"%d %d %d\n",lm.numero,lm.puck,lm.etat);     
    }
      printf("FIN DU TRAVAIL DEMANDE..\n");
  }                                   
    else printf("Echec d'ouverture..");
  }      
      else  printf("..\n");
       
  fclose(fichier);
}