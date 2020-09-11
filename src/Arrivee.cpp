#include <random>

#include "../include/Arrivee.h"
#include "../include/Evenement.h"
#include "../include/Simulation.h"

Arrivee::Arrivee(double heureDeclenchement, Simulation *const simulation) 
    :Evenement(heureDeclenchement), _simulation(simulation) {}

void Arrivee::traiter() {
	//** Traitement de l'arrivée d'un client **//

	// Déclaration des variables nécessaire à la distribution de poisson
	std::default_random_engine generator;
	std::poisson_distribution<int> distri(_simulation->tempsMoyenArrivees());

	// Création du client à entrer dans la simulation
	Client *client = new Client(_simulation->tempsCourant());
	// Récupération d'un caissier disponible si il existe
	Caissier *caissier = _simulation->banque().caissierDispo();

	// Si un caissier est disponible
	if (caissier != nullptr) {
		// Servir le client
		caissier->servir(*client);
	}
	// Sinon
	else {
		// Mettre le client en file d'attente
		_simulation->banque().fileAttente().ajouter(client);
	}


	//** Création de la prochaine arrivée de client **//

	// Calcul de l'heure prévue pour la prochaine arrivée d'un client
	double heurePrevue = _simulation->tempsCourant() +  (double) distri(generator);

	// Si la prochaine arrivée survient avant la fin de la simulation
	if(heurePrevue <= _simulation->dureePrevue()) {
		// Ajoute l'événement d'arrivée à l'échéancier de la simulation
		_simulation->ajouter(new Arrivee(heurePrevue, _simulation));
	}	
}