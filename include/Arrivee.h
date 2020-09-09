#ifndef ARRIVEE_H
#define ARRIVEE_H

#include "Evenement.h"
#include "../include/Evenement.h"

class Arrivee : public Evenement
{
	public:
		Arrivee(double heureDeclenchement);
		~Arrivee();
	
		void traiter();
};

#endif