#include "../include/Depart.h"
#include "../include/Evenement.h"

Depart::Depart(double heureDeclenchement, SED &simulation, Caissier& caissier, Client& client) : Evenement(heureDeclenchement, simulation), _caissier(&caissier), _client(&client) {}

void Depart::traiter() {
	// TODO
}