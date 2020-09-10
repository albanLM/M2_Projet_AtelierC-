#include "../include/SED.h"

SED::SED() {
	_tempsCourant = 0.0;
}

SED::~SED() {
	// TODO
}

void SED::lancer() {

}

void SED::ajouter(Evenement *e) {
	_pEvenements.push(e);
}

double SED::tempsCourant() const {
	return _tempsCourant;
}