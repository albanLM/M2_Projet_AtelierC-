#ifndef BANQUE_H
#define BANQUE_H

#include "FileAttente.h"
#include "Caissier.h"

class Banque
{
	private:
		int _nbCaissiers;
		int _nbClients;
		double _tempsMoyenService;

		FileAttente _fileAttente;
		Caissier *_caissiers;

	public:
		Banque();
		Banque(double tempsMoyenService, int nbCaissiers);
		~Banque();
	
		Caissier& caissierDispo();
		int nbCaissiers() const;
		int nbClients() const;
};

#endif