/* S.Darlène-B.Aouicha TS2  */
/* Projet de spécialité ISN */
/* Quiz de culture générale */
#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>

  void afficherscore()
//Fonction "affichage du score" avec nom du joueur//
 {
  char nom[20];
  float s;
  FILE *f;
  system("cls");
  f=fopen("score.txt","r");
  fscanf(f,"%s%f",&nom,&s);
  printf("\n\n\t\t ");
  fclose(f);
  getch();
 }

  void regle ()
//Fonction "règle" appartenant à l'onglet "règles du jeu"//
 {
   system("cls");
   printf("\n\n\n\tVoici les regles du jeu, celles-ci sont tres simples.");
   printf("\n\n\n\tIl s'agit de questions de culture generale.");
   printf("\n\n\n\t4 choix de reponses s'offrent a vous, le but est de trouver la bonne.");
   printf("\n\n\n\tAttention votre temps de reponse est compte.");
   printf("\n\n\n\tAu fil de la partie, votre score sera calcule et affiche a la fin du quiz.");
   printf("\n\n\n\tBonne chance a vous (ne trichez pas ;) ) ");
 }

  void ecrirescore (float score, char plnm[20])
//Fonction "ecrire score"//
 {
  float sc;
  char nm[20];
  FILE *f;
  system("cls");
  f=fopen("score.txt","r");
  fscanf(f,"%s%f",&nm,&sc);
  if (score>=sc)
 {  sc=score;
    fclose(f);
    f=fopen("score.txt","w");
    fprintf(f,"%s\n%.2f",plnm,sc);
    fclose(f);
 }
 }

  int main()
//Déclaration des variables()//;
    {
     int countq,countr;
     int r,i;
     int pa;int nq[6];int w;
     float score;
     char choix;
     char nomjoueur[20];
     time_t tpsinitial,tpsfinal;
     system("cls");

// Menu principal et différents onglets//;
     menuprincipal:
     system("cls");
     puts("\n\t\t Bienvenue sur notre quiz! :) \n\n") ;
     puts("\n\t\t Etes-vous prets a relever le defi qui est d'atteindre un score parfait de 100 ?\n\n") ;
     puts("\n\t\t Ceci est impossible! (a part si vous parvenez a acceder au code source du jeu...)\n\n");
     puts("\n\t\t*******************************");
     puts("\n\t\t Appuyez sur la touche 'C' pour commencer le jeu");
     puts("\n\t\t Appuyez sur la touche 'R' pour voir les regles du jeu");
     puts("\n\t\t Appuyez sur la touche 'Q' pour quitter le jeu");
     printf("\n\t\t*******************************\n\n\t\t  ");

//Le joueur doit selectionner une des 4 touches proposées (instructions condtionnelles"//
     choix=toupper(getch());

//Si le joueur choisit 'R', il aura accès aux règles du jeu//
     if (choix=='R')
 {
  regle();
  getch();
  goto menuprincipal;
 }

// Sinon si le joueur choisit 'Q', il aura la possibilité de quitter le jeu//
     else if (choix=='Q')
 exit(1);

//Sinon si le joueur choisit 'C', il aura la possibilité de commencer une partie de jeu//
    else if(choix=='C'){
    system("cls");
    printf("\n\n\n\t\t\tEntrez votre nom");
    printf("\n\n\n\n\tLe but de ce jeu est d'avoir un score parfait, auquel cas il faut continuer a etudier !\n\n\t\t\t");
    gets(nomjoueur);
//Début du jeu et démarrage de la fonction temps//
     home:
     system("cls");
     tpsinitial=time(NULL);
     countq=countr=0;
     i=1;
     start:
     srand ( time(NULL) );
     r=rand()%15+1;
     nq[i]=r;
     for (w=0;w<i;w++)
 if (nq[w]==r) goto start;
     switch(r)
//Question 1//
  {
  case 1:
  printf("\n\nA quelle famille correspond groupe caracteristique associe a la liaison -COOH?");
  printf("\n\nA.Acide Carboxylique\tB.Cetone\n\nC.Amine\tD.Aldehyde\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nBonne reponse!");countr++; break;}
  else
         {printf("\n\n Faux! La bonne reponse etait la A.Acide carboxylique,");break;}

//Question 2//
  case 2:
  printf("\n\n\n Par quoi pouvons nous traduire le mot 'Knowledge' en francais?");
  printf("\n\nA.Connaissances\tB.Cube\n\nC.Etudes\tD.Prisme\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\n Excellent! Il semblerait que vous en ayez beaucoup");countr++; break;}
  else
         printf("\n\n Faux! La bonne reponse etait la A.Connaissances qui sont en effet necessaires pour reussir ce quiz");break;


//Question 3//
  case 3:
  printf("\n\n\n Lequel de ces hommes politiques n'a jamais ete president de la France ?");
  printf("\n\nA.Charles de Gaulle\tB.Vincent Auriol\n\nC.Felix Faure\tD.Lionel Jospin \n\n");
  countq++;
  if (toupper(getch())=='D')
   {printf ("\n\n Gagne!");countr++;break;}
  else
         {printf ("\n\n Faux! La bonne reponse etait la D. Lionel Jospin qui n'a jamais remporte les elections presidentielles en France") ;break;}
//Question 4//
  case 4:
  printf("\n\n\n Quelle est la capitale de l'Australie?");
  printf("\n\nA.Canberra\tB.Sydney\n\nC.Brisbane\tD.Perth\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\n Bien joue! Vous etes un as de la geographie! ");countr++; break;}
  else
         {printf ("\n\n Rate! La bonne reponse etait la A.Canberra, mais les autres propositions sont aussi des villes australiennes!");break;}

//Question 5//
  case 5:
  printf("\n\n\nLaquelle de ces affirmations a propos de la fonction exponentielle est fausse?");
  printf("\n\nA.e^0=e\tB.e^0=1\n\nC.La fonction exponentielle est strictement positive\tD.La derivee de e^(-x)= -e^(-x)\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\n Super! Esperons que votre score soit exponentiel ");countr++; break;}
  else
         {printf("\n\n Rate! La bonne reponse etait la A.e^0=e en effet, il est preferable d'ecrire e^0= 1 et e^1=e");break;}

//Question 6//
  case 6:
  printf("\n\n\n Que signifie l'abreviation OMC?");
  printf("\n\nA.Organisme Mutant Cancerigene\tB.Organisation Mondiale du Commerce\n\nC.Ouvrage Mondial Collectif\tD.Ordre Mondial Commercial\n\n");
  countq++;
  if (toupper(getch())=='B' )
   {printf("\n\n Bonne reponse! Elle permet le libre-echange, plus de douanes! ");countr++; break;}
  else
         {printf("\n\n Perdu! La bonne reponse etait la B.Organisation Mondiale du Commerce, heritiere des accords du GATT ( accords generaux sur les tarifs douaniers et le commerce)");break;}

//Question 7//
  case 7:
  printf("\n\n\n Lequel de ces insectes produit du miel et participe a la pollinisation?");
  printf("\n\nA.Le frelon \tB.La guepe\n\nC.L'abeille\tD.Le bourdon\n\n");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\n Gagne! Savez-vous que les abeilles jouent un role essentiel dans la formation des fleurs,fruits et legumes?");countr++; break;}
  else
         {printf("\n\n Perdu! La bonne reponse etait la C.L'abeille");break;}

//Question 8//
  case 8:
  printf("\n\n\n Laquelle de ces applications n'est pas un reseau social?");
  printf("\n\nA.Snapchat\tB.Facebook\n\nC.Linkedin\tD.Wikipedia\n\n");
  countq++;
  if (toupper(getch())=='D')
   {printf("\n\nBonne Reponse!");countr++; break;}
  else
         {printf("\n\nFaux! La bonne reponse etait la D.Wikipedia");break;}

//Question 9//
  case 9:
  printf("\n\n\nQui est le fondateur de l'entreprise Apple?");
  printf("\n\nA.Steve Jobs\tB.Mark Zuckerberg\n\nC.Elon Musk\t\tD.Alan Turing\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nBonne Reponse! La societe fut fondee en 1976");countr++; break;}
  else
         {printf("\n\n Rate! La bonne reponse etait la A.Steve Jobs, accompagne de Steve Wozniak et Ronald Wayne");break;}

//Question 10//
  case 10:
  printf("\n\n\n Quelle est la valeur de la celerite du son dans l'air a temperature ambiante?");
  printf("\n\nA.3.00*10^8 m/s\tB.900m/s\n\nC.340m/s\tD.750m/s\n\n");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\n Genial! Vous n'etes pas tombe dans le piege, 3.00*10^8 m/s est la valeur de la celerite de la lumiere dans le vide. ");countr++; break;}
  else
         {printf("\n\n Erreur! La bonne reponse etait la C.340m/s");break;}

//Question 11//
  case 11:
  printf("\n\n\n Laquelle de ces propositions ne designe pas un systeme d'exploitation?");
  printf("\n\nA.Linux\tB.Microsoft\n\nC.Google\tD.Mac OSX\n\n");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\n Bien! Google est en effet un navigateur web et non un systeme d'exploitation");countr++; break;}
  else
         {printf("\n\nFaux! La bonne reponse etait la C. Google");break;}

//Question 12//
  case 12:
  printf("\n\n\n Laquelle de ces propositions ne designe pas une condition pour appliquer le corollaire du TVI sur un intervalle I?");
  printf("\n\nA.f doit etre strictement monotone sur I\tB.f(x) doit etre strictement positif sur I\n\nC.f doit etre continue sur I\tD.f doit etre derivable sur I\n\n");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\n Bien Joue, on appelle aussi ce theoreme, theoreme de la bijection!");countr++; break;}
  else
         {printf("\n\n Mauvaise reponse! La bonne etait la B.f(x) doit etre strictement positif sur I ");break;}

//Question 13//
  case 13:
  printf("\n\n\n Lesquelles de ces cellules ne sont pas des cellules de l'immunite innee?");
  printf("\n\nA.Les Lactobacilles\tB.Les Mastocytes\n\nC.Les Phagocytes\tD.Les Lymphocytes T\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nBien Joue! Les lactobacilles sont des bacteries servant a la fermentation d'aliments, notamment les yaourts");countr++; break;}
  else
         {printf("\n\n Dommage! La bonne reponse etait la A.Les Lactobacilles ");break;}

//Question 14//
  case 14:
  printf("\n\n\nPar quoi peut se traduire l'abreviation Wi-Fi?");
  printf("\n\nA.Wireless Fidelity\tB.Wind and Fire\n\nC.Window Fiber\tD.Wizard Fireballs\n\n");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nCorrect! Cest un ensemble de normes concernant les reseaux sans fil");countr++; break;}
  else
         {printf("\n\nFaux! La bonne reponse etait la A.Wireless Fidelity");break;}

//Question 15//
  case 15:
  printf("\n\n\n Qui a predit l'existance de l'antimatiere ?");
  printf("\n\nA.Jean-Antoine Chaptal\tB.Erwin Schrodinger\n\nC.Louis de Broglie\tD.Paul Dirac\n\n");
  countq++;
  if (toupper(getch())=='D')
   {printf("\n\n Super! Celle-ci etait plutot difficile! L'antimatiere est l'objet de nombreuses etudes a l'institut du CERN a Geneve.");countr++; break;}
  else
         {printf("\n\n Rate! La bonne reponse etait la D.Paul Dirac ");break;}
  }

//Temps final de jeu et calcul du score final//
 i++;
 if (i<=5) goto start;
 tpsfinal=time(NULL);
 score=(float)countr/countq*100-difftime(tpsfinal,tpsinitial)/3;

//Affichage du score et des résultats//
 if (score<0) score=0;
 printf("\n\n\nVotre score est de: %.2f",score);
 if (score==100) printf("\n\n   Parfait!! Vous etes le meilleur joueur quelle vivacité d'esprit!");
 else if (score>=80 && score<100) printf("\n\n Bien joue, mais vous pouvez mieux faire, ne seriez-vous pas un peu lent?");
 else if (score>=60 &&score<80) printf("\n\n Bon score, mais vous devez vous cultiver davantage ou repondre plus vite.");
 else if (score>=40 && score<60) printf("\n\n Resultat moyen, ne vous contentez pas du strict minimum!");
 else printf("\n\n Dommage, Il semble que vous avez bien ete cuisine :0 ");

//Proposition de nouvelle partie//
 puts("\n\n Une nouvelle partie?(O/N)");

//Si le joueur appuie sur 'O', recommencer une nouvelle partie//
 if (toupper(getch())=='O')
  goto home;

//Sinon retourner au menu principal//
 else
  {
  afficherscore(score,nomjoueur);
  goto menuprincipal;
  }
 }
     else
//Si le joueur appuie sur une touche autre que celles proposées, lui indiquer qu'elle n'est pas utilisable dans le jeu//
 {
 printf("\n\n\t\t Cette touche n'est pas disponible\n\n\t\t  ");
 Sleep(700);
 goto menuprincipal;
 }
 return 0;
}
