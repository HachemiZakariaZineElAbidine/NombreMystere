#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//Déclaration de type de tableaux
typedef struct { int score;
                 int difficulte;}resultat;
                 
//Procédure de lecture de résultat
void resultatfinal (resultat T[100] , int d , int nr , int s)
{ T[nr].difficulte = d;
  T[nr].score = s;}
  
//Procédure d affichage de résultat final
void affichage (resultat T[100],int nr)
{int i;
 for ( i = 0 ; i < nr ; i++)
 {printf("Partie numero %d\n",i+1);
  switch(T[i].difficulte)
  { case 1 :
  	printf("Le niveaux de difficulte Facile\n");
  	break;
  	case 2 :
  	printf("Le niveaux de difficulte Moyen\n");
  	break;
  	case 3 :
  	printf("Le niveaux de difficulte Difficile\n");
  	break;}
  printf(" le score : %d\n",T[i].score);
  printf("\n");}}

main()
{ //Déclaration des variables
  int ne,nm,d,c,s = 0;
  int max,min = 1,nr = 0;
  resultat T[100];
  
 do{//Lecture de Menu
 	do{printf("Choisir niveaux de difficulte\n");
 	   printf(" 1 - Facile entre 1 et 100\n");
 	   printf(" 2 - Moyen entre 1 et 1000\n");
 	   printf(" 3 - Difficile entre 1 et 10000\n");
 	   printf("Donner votre choix : ");
 	   scanf("%d",&d);
 	   if( d != 1 && d != 2 && d !=3 )
 	   {printf("\tErreur vous devez choisir entre 1 et 2 et 3");}
 	    printf("\n");}while( d != 1 && d != 2 && d != 3 );
		    
 	//Le traitement de difficulté
 	switch(d)
    {
	case 1 :
 		max = 100;
 		break;
 	case 2 : 
 	    max = 1000;
 	    break;
 	case 3 :
 		max = 10000;
 		break;}
 		
 	//La fonction qui 
 	srand(time(NULL));
    nm = (rand() % (max - min + 1)) + min;
    
 	//Traitement
 	do{printf("Donner un nombre entre 0 et %d :",max);
       scanf("%d",&ne);
       if ( ne > nm)
        {printf("C est moins \n");}
       if(nm > ne)
       {printf("C est plus \n");}
       s++;
    }while( ne != nm );
    printf("\n");
    
    //Affichage de score
    printf("Bravo, vous avez trouver le nombre mystere en %d coups!!!\a\n",s);
 	printf("\n");
 	nr++;
 	resultatfinal(T,d,nr,s);
 	
 	//Menu de sortir
  do{printf("Tapper 1 Si vous vouler reprendre le jeux \n");
     printf("Tapper 2 Si vous vouler quitter le jeux \n");
     printf("Donner votre choix : ");
     scanf("%d",&c);
     if(c !=1 && c !=2)
     {printf("\tErreur vous devez choisir entre 1 et 2");
     printf("\n");}}while(c !=1 && c !=2);
     //printf("\n\n\n\n\n\n\n\n\n\n");
     s=0;
     printf(" c = %d ",c);
     if ( c != 1)
     { //printf("\n");
       goto etiq1; }
   }while( c != 1 );
   etiq1 :
   //affichage de resultat final
   affichage (T,nr);
 getch();
}
