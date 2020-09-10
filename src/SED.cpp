/**
* \file SED.cpp
* \author A. Le Moult
* \date 10/09/2020
*/

#include "../include/SED.h"

SED::SED() {
	_tempsCourant = 0.0;
}

void SED::lancer() {
	Evenement *evenementCourant = nullptr;

	// Tant qu'un événement est présent dans l'échéancier
	while (!_echeancier.empty()) {
		// Récupérer le prochain événement
		evenementCourant = _echeancier.top();
		
		// Mettre à jour le temps courant de la simulation avec l'heure de déclenchement de l'événement
		_tempsCourant = evenementCourant->heureDeclechement();

		// Retirer l'événement de l'échéancier 
		_echeancier.pop();

		// Traiter l'événement
		evenementCourant->traiter();

		// Supprimer l'événement
		delete evenementCourant;
	}
}

void SED::ajouter(Evenement *e) {
	_echeancier.push(e);
}

double SED::tempsCourant() const {
	return _tempsCourant;
}