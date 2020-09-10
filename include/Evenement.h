/**
* \file Evenement.h
* \brief Classe d'événement pour la simulation.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef EVENEMENT_H
#define EVENEMENT_H


class SED;
class Evenement
{
	protected:
		const SED *_simulation;
		double _heureDeclechement;

	public:
		Evenement(double heureDeclechement, SED &simulation);

		double heureDeclechement();
		virtual void traiter() = 0;
};

class compareEvenements {
	public:
	  int operator() ( Evenement *e1, Evenement *e2) {
	    return e1->heureDeclechement() < e2->heureDeclechement();
	  }
};

#endif