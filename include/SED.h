#ifndef SED_H
#define SED_H

#include <vector>
#include <queue>

#include "Evenement.h"

class SED
{
	protected:
		double _tempsCourant;
		std::priority_queue<Evenement, std::vector<Evenement*>, compareEvenements> _pEvenements;

	public:
		SED();
		~SED();
		
		void lancer();
		void ajouter(Evenement *e);
		double tempsCourant() const;
};

#endif