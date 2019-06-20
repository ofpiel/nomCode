typedef struct Date
{ 
 int jour ,mois ,annee;
 int heure,minutes,seconde;
} Date;


typedef struct Recharge
{
  char code[14];
  float valeur;
  int etat;
} Recharge; 


Date saisie_date();
Recharge saisie_code();
FILE* Ajout_code(FILE* f);