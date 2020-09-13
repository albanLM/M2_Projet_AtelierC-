#include "../include/Depart.h"
#include "../include/Evenement.h"
#include "../include/Simulation.h"

Depart::Depart(double heureDeclenchement, Simulation *const simulation, Caissier *const caissier, Client *const client) : Evenement(heureDeclenchement), _simulation(simulation), _caissier(caissier), _client(client) {}

void Depart::traiter() {
	Client *clientSuivant;
	FileAttente *fileAttente = &_simulation->banque().fileAttente();

	if (!fileAttente->estVide())
	{
		clientSuivant = fileAttente->retirer();
		_caissier->servir(*clientSuivant);
	}
	else
	{
		_caissier->liberer();
	}

	delete _client;
}