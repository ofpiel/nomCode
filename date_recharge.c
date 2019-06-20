#include <stdio.h>
#include <time.h>
#include "date_recharge.h"

/***
*** Fonction de saisie de date 
**/

Date saisie_date()
{
 Date d;
 printf("entrer la date de naissance du client :");
  do
  {printf("\nannee de naissance: ");
   scanf("%d",&d.annee);
   if(d.annee>2014)
    printf("\nmdr...le client n'est meme pas encore ne on dirait..!?lol");
    if(d.annee<1900)
    printf("\ndesole , client trop age..!");
  }while((d.annee<1900)||(d.annee>2014));

 do 
  {printf("\nmois de naissance: ");
   scanf("%d",&d.mois);
   
  }while((d.mois<1)||(d.mois>12));
  
  switch(d.mois)
  {
    case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:do
	  { printf("\njour de naissance :");
  	    scanf("%d",&d.jour);
	  }while((d.jour<1)||(d.jour>31));
	  break;
    case 4:
	case 6:
	case 9:
	case 11:do
	 { printf("\njour de naissance :");
  	   scanf("%d",&d.jour);
	 }while((d.jour<1)||(d.jour>30));
	 break;
	case 2:
	if((d.annee%4==0)&&(d.annee%100!=0)&&(d.annee%400==0))
	{
	   do
	   { printf("\njour de naissance :");
  	     scanf("%d",&d.jour);
	   }while((d.jour<1)||(d.jour>29));
		break;
      }else
	  { do
	     { printf("\njour de naissance :");
  	       scanf("%d",&d.jour);
	     }while((d.jour<1)||(d.jour>28));
		 break;
      }   	
  }
return d;
}


/***
**	Fonction de saisie de code
*/
Recharge saisie_code()
{ 
  Recharge r;

  printf("entrer le code a ajouter:");
  scanf("%s",r.code);
  
  printf("entrer la valeur du code :");
  scanf("%f",&r.valeur);
  r.etat=1;
	
return r;	
}


/**
***	 Fonction d'ajout de code dans un fichier 'code_recharge.txt'
**/
FILE* Ajout_code(FILE* f)
{ 
 Recharge re;
  int stop;
 f=fopen("code_recharge.txt","a");
   do
   {re=saisie_code();
    fprintf(f,"%s %f\n",re.code,re.valeur);
    do
    {printf("Aimeriez vous ajouter un autre code?\nSi Oui entrer 1 si Non entrer 0: ");
     scanf("%d",&stop);
    }while((stop!=0)&&(stop!=1));	
   }while(stop==1); 
   fclose(f);
   return f;	
}
