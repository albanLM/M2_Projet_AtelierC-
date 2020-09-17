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

void Simulation::afficherInfos() {
    std::cout << "Afficher Infos Simulation" << std::endl;
    int longueurMax = _banque.fileAttente().longueurMax();
    double longueurMoy = _banque.fileAttente().longueurMoy();

    std::cout << "Durée réelle : " << _tempsCourant << std::endl;
    std::cout << "Longueur Max : " << longueurMax << std::endl;
    std::cout << "Longueur Moy : " << longueurMoy << std::endl;
    std::cout << "Clients Servis : " << _banque.nbClients() << std::endl;
    std::cout << "Temps Attente Moyen : " << _banque.fileAttente().tempsMoyenAttente() << std::endl;
    // std::cout << "Clients Servis Par Caisse : " << _nbClientParCaisse << std::endl;
    // std::cout << "Taux Occupation Par Caisse : " << _tauxOccupationParCaisse << std::endl;
}
