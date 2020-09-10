/**
* \file Arrivee.h
* \brief Classe dérivée de Evenement. Représente l'arrivée d'un Client. 
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef ARRIVEE_H
#define ARRIVEE_H

#include "Evenement.h"

class Arrivee : public Evenement
{
	public:
		Arrivee(double heureDeclenchement, SED &simulation);

		void traiter();
};

#endif