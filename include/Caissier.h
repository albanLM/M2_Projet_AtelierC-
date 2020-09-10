#ifndef CAISSIER_H
#define CAISSIER_H
#include "Client.h"

class Banque;
class Caissier
{
	private:
		Banque *_banque;
		Client *_client;

		double _tempsMoyenService;
		double _tauxOccupation;
		int _nbClients;
		bool _dispo;

	public:
		Caissier(Banque &banque, double tempsMoyenService);
		~Caissier();
	
		double tempsMoyenService() const;
		double tauxOccupation() const;
		int nbClients() const;
		bool estDispo() const;

		void servir(Client client);
		Client liberer();
};

#endif