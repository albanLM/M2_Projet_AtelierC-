#include "include/Simulation.h"

int main(int argc, char const *argv[])
{
	const int nbCaissier = 3;
	double tempsMoyServices[nbCaissier];
	tempsMoyServices[0] = 20.0;
	tempsMoyServices[1] = 30.0;
	tempsMoyServices[2] = 15.0;
	double dureePrevue = 100.0;
	double tempsMoyenArrivees = 8.0;

	Simulation simulation(dureePrevue, nbCaissier, tempsMoyServices, tempsMoyenArrivees);
	simulation.lancer();

	simulation.afficherInfos();

	return 0;
}