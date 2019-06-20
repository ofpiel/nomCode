#include "date_recharge.h"

typedef struct client
{
 char nom[20],prenom[20];
 Date dat_naissance,date_recharge;
 adr adresse;
 int cin;
 ligne ip;
 int solde;
 struct client* suivant;
 
}client;


typedef struct adr
{
 char ville[20];
 int telephone;
}adr;


adr saisie_adresse();
client saisie_client();
FILE* ajout_client(FILE* fichier);
client chercher_client(FILE* f,int cinClient);
client* copie_fichier_client(FILE* fichier);
client* modifier_liste_client(client* ptclient,int cinClient);
void modifier_client(FILE* fichier,int cinClient);








