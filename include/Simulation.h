#ifndef SIMULATION_H
#define SIMULATION_H

#include "SED.h"
#include "Banque.h"

class Simulation : public SED
{
	private:
		const double _dureePrevue;
		const double _tempsMoyenArrivees;
		Banque _banque;

		double _dureeReelle;
		int _longueurMax;
		int _longueurMoy;
		int _nbClientServis;
		int * _nbClientParCaisse;
		double _tempsAttenteMoy;
		double _tauxOccupationParCaisse;

	public:
		Simulation();
		Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees);
		~Simulation();
		
		double dureePrevue() const;
		double tempsMoyenArrivees() const;

		Banque& banque();
};

#endif