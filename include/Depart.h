/**
* \file Depart.h
* \brief Classe dérivée de Evenement. Représente le départ d'un Client. 
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

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
		Depart(double heureDeclenchement, SED &simulation, Caissier& caissier, Client& client);

		void traiter();
};

#endif