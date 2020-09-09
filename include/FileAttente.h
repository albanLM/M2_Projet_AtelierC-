#ifndef FILEATTENTE_H
#define FILEATTENTE_H

#include <deque>

#include "Client.h"

class FileAttente
{
	private:
		int _longueurMax;
		double _longueurMoy;
		double _tempsMoyenAttente;

		// DeQueue
		std::deque<Client> _clients;

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