#include "../include/Caissier.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/Depart.h"
#include <cmath>

std::default_random_engine Caissier::_generator;

Caissier::Caissier() {}

Caissier::Caissier( Banque &banque, 
                    double tempsMoyenService)
                    :_banque(&banque),
                    _tempsMoyenService(tempsMoyenService)                    
{
    _client = nullptr;
    _dispo = true;
    _nbClients = 0;
    _tauxOccupation = 0.0;
}

double Caissier::tempsMoyenService() const { return _tempsMoyenService; }
double Caissier::tauxOccupation() const { return _tempsMoyenService*exp(-_tempsMoyenService); }
int Caissier::nbClients() const { return _nbClients; }
bool Caissier::estDispo() const { return _dispo; }

void Caissier::servir(Client &client)
{
    _client = &client;
    _nbClients++;
    _dispo = false;

    std::poisson_distribution<int> distri(_tempsMoyenService);

    double heureDepart = _banque->simulation()->tempsCourant() + distri(Caissier::_generator);
    _banque->simulation()->ajouter(new Depart(heureDepart, _banque->simulation(), this, _client));
}

void Caissier::liberer()
{
    _client = nullptr;
    _dispo = true;
}

void Caissier::afficherInfos() const {
    // TODO
}