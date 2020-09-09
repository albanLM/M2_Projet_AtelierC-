#ifndef EVENEMENT_H
#define EVENEMENT_H


class SED;
class Evenement
{
	private:
		double _heureDeclechement;
		SED *_simulation;

	public:
		Evenement(double heureDeclechement);
		~Evenement();

		double heureDeclechement();
		virtual void traiter() = 0;
};

class compareEvenements {
	public:
	  int operator() ( Evenement& e1, Evenement& e2) {
	    return e1.heureDeclechement() < e2.heureDeclechement();
	  }
};

#endif