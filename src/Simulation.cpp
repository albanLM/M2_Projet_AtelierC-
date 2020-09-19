#include "../include/Simulation.h"
#include <iostream>
#include "../include/Arrivee.h"

Simulation::Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees)
    : SED(), _dureePrevue(dureePrevue),
    _tempsMoyenArrivees(tempsMoyenArrivees)
{
    ajouter(new Arrivee(0.0, this));
    new (&_banque) Banque(tempsServices, nbCaissier, *this);
}

double Simulation::dureePrevue() const { return _dureePrevue; }
double Simulation::tempsMoyenArrivees() const { return _tempsMoyenArrivees; }

Banque& Simulation::banque() {return _banque;}

std::ostream &operator<<(std::ostream &os, const Simulation &simulation)
{
    os << "Durée réelle de la simulation : " << simulation._tempsCourant << std::endl;
    os << simulation._banque;
    return os;
}
