#ifndef FILEATTENTE_H
#define FILEATTENTE_H

#include <deque>

#include "Client.h"

class Banque;
class FileAttente
{
	private:
		int _longueurMax;
		double _longueurMoy;
		double _tempsMoyenAttente;

		Banque * _banque;

		// DeQueue
		std::deque<Client> _clients;

		void majTempsMoyenAttente(Client client);
		void majLongueurMoy();

	public:
		FileAttente();
		~FileAttente();
		
		int longueurMax() const;
		double longueurMoy() const;
		double tempsMoyenAttente() const;	
		void ajouter(Client client);
		bool estVide() const;
		Client retirer();
};

#endif