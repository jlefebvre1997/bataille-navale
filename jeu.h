
#include "server.h"

#ifndef JEU_H
#define JEU_H

/*
Fonctionnalité à faire :
- Récupérer une saisie clavier
- Recevoir la réponse serveur afin d'écrire touché ou non touché
- Faire un update des valeur stocker
- client_error
*/


int *positionbateau1;
int *positionbateau2;

int positiondesbateaux[2];

int positionBateau()
{
	// Static datas, change it when including this function in main :)
	int sockfd = connexion("localhost", 82);

	printf("Saisir la position du premier bateau");
	positiondesbateaux[0] = scanf("%d",positionbateau1);
	
	printf("Saisir la position du deuxième bateau");
	positiondesbateaux[1] = scanf("%d",positionbateau2);

	struct Strike positions;

	positions.x = positiondesbateaux[0];
	positions.y = positiondesbateaux[1];		
	
	void* buffer = communiquer(sockfd, (void *)&positions)
// le type message définit ce qu'il faut lire dans la struct envoyé
// typeMessage | description            | [ type ] |
// 0 :         | En attente connection  | [ char genericMessage[255]; ] ( "En attente de connection n joueurs" )
// 1 :         | Connection établie     | [ Player player ] ( Confirme la connexion, envoie de la position des bateaux )
// 2 :         | Début de partie        | [ void ] ( Tous les joueurs sont prêts )
// 3 :         | Début de tour          | [ void ] ( Notification du début du tour )
// 4 :         | Message succès tir     | [ char nickname[255] ] ( Le nickname du joueur touché )
// 5 :         | Message échec tir      | [ void ]
// 6 :         | Notification tir       | [ char nickname[255];  ( Le nickname du joueur qui a joué)
// 7 :         | Bilan tour             | [ SucccessfullStrike strikes[n], Player eliminatedPlayers[n] ] (une liste des tirs réussis + une liste des joueurs éliminés)
// 8 :         | Fin de partie          | [ char nickname[255]; ] ( Le nickname du vainqueur )
	
	switch (buffer.typeMessage)
	{

		case 0:
		  return ;
		  break;

		case 1:
		  return ;
		  break;

		case 2:
		  return ;
		  break;

		case 3:
		  return ;
		  break;

		case 4:
		  return ;
		  break;

		case 5:
		  return ;
		  break;
			
		case 6:
		  return ;
		  break;
		
		case 7:
		  return ;
		  break;
			
		case 8:
		  return ;
		  break;
			
		default:
		  printf("Non géré", codeErreur);
		  break;

	}
	
	
	return 0;

}

void EnregistrerPositionTab(int positionX, int positionY, int touche, int(*tab)[17])
{
	tab[positionX][positionY] = touche;
} 

void AfficherTab(int(*tab)[17])
{
	char ligne[255];
	char *valeurAff;

	for (int i = 0 ; i < 17 ; i++)
	{
		strcpy(ligne, "");
		for (int j = 0 ; j < 17 ; j++)
        	{
			if(tab[i][j] == 1)
			{
				valeurAff = "x";
			}
			else
			{
				valeurAff=" ";
			}

			strcat(ligne, valeurAff);
			strcat(ligne, "|");
		}

		printf("%s\n", ligne);
	}
}

#endif
