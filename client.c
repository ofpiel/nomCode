#include <stdio.h>
#include "client.h"
#include "date_recharge.h"


/*
* Fonction pour la saisie d'une structure de type client
*/
client saisie_client()
{
     client cl;
     FILE* f; 
     ligne l;
     printf("entrer le nom du client :");
     scanf("%s",cl.nom);
	printf("\nentrer le prenom du client:");
     scanf("%s",cl.prenom);
     cl.dat_naissance=saisie_date();
     cl.adresse=saisie_adresse();
      printf("\nentrer le CIN du client:");
      scanf("%d",&cl.cin);
do{
	printf("entrer numero existant:");
	scanf("%d",&cl.ip.numero);
	l= chercher_ligne(f,cl.ip.numero);
	if(l.etat==0)
	printf("\nDESOLE CETTE LIGNE EST DEJA OCCUPEE..\n");
	 
  }while(l.numero==-1 ||l.etat==0);
  
  modifier_ligne_etat(f,l.numero);
  cl.ip.etat=0;
  cl.solde=0;
     return cl;
     	 
}

   

/*
* Fonction pour la saisie d'adresse d'un client
*/
adr saisie_adresse()
{ 
  adr a;
  printf("entrer la ville du client :");
  scanf("%s",a.ville);
return a; 
} 



/**
**   Fonction pour ajouter un client dans un fichier 
**/
FILE* ajout_client(FILE* f)
{ 
  client cl;
  
/*  time_t timestamp; 
    struct tm * t; 
  
    timestamp = time(NULL); 
    t = localtime(&timestamp); */
         
  int stop;                 
  f=fopen("client.txt","a");        
 
  do{                               
     cl=saisie_client(); 
     
   
     fprintf(f,"%s %s %d/%d/%d %d/%d/%d %d %d %d\n",cl.nom,cl.prenom,cl.dat_naissance.jour,cl.dat_naissance.mois,
    cl.dat_naissance.annee,cl.date_recharge.jour=0,cl.date_recharge.mois=0,cl.date_recharge.annee=0,
    cl.solde,cl.cin,cl.ip.numero);
    do
     {printf("Aimeriez vous ajouter un autre client?\nSi Oui entrer 1 si Non entrer 0: ");
      scanf("%d",&stop);
     }while((stop!=0)&&(stop!=1));  
     
   }while(stop==1); 
   fclose(f);
   return f;
} 



/***
***
***/
client chercher_client(FILE* f,int cinclt)
{
  client clc,cli;       
  
  cli.solde=-1;
  cli.ip.numero=-1;  
  f=fopen("client.txt","r");
  rewind(f);
  while(!feof(f))
  {
   fscanf(f,"%s %s %d/%d/%d %d/%d/%d %d %d %d\n",clc.nom,clc.prenom,&clc.dat_naissance.jour,
   &clc.dat_naissance.mois,&clc.dat_naissance.annee,&clc.date_recharge.jour,&clc.date_recharge.mois,
   &clc.date_recharge.annee,&clc.solde,&clc.cin,&clc.ip.numero);
   
   
   
   if(clc.cin==cinclt)
    {
    cli=clc;
    printf("CLIENT TROUVE: %s| %s| %d| %d|",cli.nom,cli.prenom,cli.ip.numero,cli.cin);
    getch();
   break;
   
    }
    
  } 
   if(feof(f))
   printf("CLIENT NON TROUVE: %d| %d|",cli.ip.numero,cli.cin);
    
  fclose(f);
  return cli;
}



/****
****
***
**/

client* copie_fichier_client(FILE* f)
{
  client* liste=(client*)malloc(sizeof(client));
  liste->suivant=NULL;
  client* lit=liste;
  f=fopen("client.txt","r");
  rewind(f);
  while(!feof(f))
  {
   client* clc=NULL;
   clc=(client*)malloc(sizeof(client));
   clc->suivant=NULL;
   fscanf(f,"%s %s %d/%d/%d %d/%d/%d %d %d %d\n",clc->nom,clc->prenom,&clc->dat_naissance.jour,
   &clc->dat_naissance.mois,&clc->dat_naissance.annee,&clc->date_recharge.jour,&clc->date_recharge.mois,
   &clc->date_recharge.annee,&clc->solde,&clc->cin,&clc->ip.numero);
   //if((clc->ip.etat!=0)&&(clc->ip.etat!=1))
    // break;
   liste->suivant=clc; //printf(" %d ",clc->cin);
   liste=liste->suivant;
  } 
 liste=lit->suivant;
 free(lit);
 fclose(f);
 return liste;  
}


/*
**
**
**/

client* modifier_liste_client(client* ptclient,int cinclt)
{
  client* clc=NULL;
   clc=ptclient;

  while((ptclient!=NULL)&&(ptclient->cin!=cinclt))
  { 
  
   ptclient=ptclient->suivant;
  }
  if((ptclient!=NULL)&&(ptclient->cin==cinclt))
  {
   printf("Entrer nouveau nom:");
   scanf("%s",&ptclient->nom);
   
   printf("\nEntrer nouveau prenom:");
   scanf("%s",&ptclient->prenom);
   
   printf("\nEntrer nouveau cin:");
   scanf("%d",&ptclient->cin);
   
   printf("\nEntrer nouveau numero:");
   scanf("%d",&ptclient->ip.numero);
   
   ptclient->dat_naissance=saisie_date();
   ptclient->adresse=saisie_adresse();
    ptclient->solde=0;
   
  }
  return clc;
  
}



/*
*** Fonction pour modifier un Client dans un fichier
**
*/

void modifier_client(FILE* fichier,int cin)
{ 
   client clm;
   client *ptclient=NULL;
   client *clinterm=NULL;
   client *pt=NULL; 
   
   clm=chercher_client(fichier,cin);
   printf("\nprocessus..\n");
  if(clm.cin!=-1)
  { 
    printf("\nProcessus de modification..\n");
    ptclient=copie_fichier_client(fichier);
        
   if(ptclient!=NULL)
    printf("FIN DE COPIE,lancement de modification..\n");
    ptclient=modifier_liste_client(ptclient,cin);
    fichier=fopen("client.txt","w");
  
  if(fichier!=NULL)   
  { printf("Transfert des donnees..\n");
    while(ptclient!=NULL)
    { 
          clm=(*ptclient);
          ptclient=ptclient->suivant; 
        fprintf(f,"%s %s %d/%d/%d %d/%d/%d %d %d %d\n",clm.nom,clm.prenom,clm.dat_naissance.jour,clm.dat_naissance.mois,
    clm.dat_naissance.annee,clm.date_recharge.jour,clm.date_recharge.mois,clm.date_recharge.annee,
    clm.solde,clm.cin,clm.ip.numero);    
    }
      printf("FIN DU TRAVAIL DEMANDE..\n");
  }
    else printf("Echec d'ouverture..");
  }      
      else  printf("..\n");
       
  fclose(fichier);
}                                    


/***
***
**/
