#include "base.h"

#ifndef ERROR_H
#define ERROR_H

void client_error(const int codeErreur)
{
	switch (codeErreur)
	{

		case 1:
		  printf("Usage : ./main hostname port");
		  break;

		case 2:
		  printf("Erreur lors de l'ouverture du socket");
		  break;

		case 3:
		  printf("Impossible de se connecter à l'hôte OU hôte inexistant");
		  break;

		case 4:
		  printf("Erreur lors de la connexion au serveur");
		  break;

		case 5:
		  printf("");
		  break;

		case 6:
		  printf("");
		  break;

		default:
		  printf("Code erreur %d non reconnu", codeErreur);
		  break;

	}
	exit(codeErreur);
}


#endif