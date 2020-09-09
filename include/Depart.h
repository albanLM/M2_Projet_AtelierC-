#ifndef DEPART_H
#define DEPART_H

#include "Evenement.h"
#include "Caissier.h"
#include "Client.h"

class Depart : public Evenement
{
	private:
		const Caissier *_caissier;
		const Client *_client;

	public:
		Depart(double heureDeclenchement, Caissier& caissier, Client& client);
		~Depart();
	
		void traiter();
};

#endif