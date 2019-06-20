typedef struct ligne
{    
     int numero;
     int puck;
     int etat;
	struct ligne* suivant;
}ligne;

ligne saisie_ligne();
void affichage_ligne(ligne ls);
FILE *ajout_ligne(FILE* fichier);
void supprimer_ligne(FILE* fichier,int number);
ligne chercher_ligne(FILE* fichier, int numero);
ligne *copie_fichier(FILE* fichier);
ligne* modifier_liste(ligne* ptligne,int number);
void modifier_ligne(FILE* fichier,int number);
ligne* supprimer_liste(ligne* ptligne,int number);
void modifier_ligne_etat(FILE* fichier,int number);