#include "../include/Caissier.h"
#include "../include/Banque.h"
#include "../include/Simulation.h"
#include "../include/Depart.h"

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
    _tempsOccupe = 0;
    _debutService = 0;
}

double Caissier::tempsMoyenService() const { return _tempsMoyenService; }

double Caissier::tauxOccupation() const
{
    return (_tempsOccupe / _banque->simulation()->tempsCourant())*100;
}
int Caissier::nbClients() const { return _nbClients; }
bool Caissier::estDispo() const { return _dispo; }

void Caissier::servir(Client &client)
{
    _client = &client;
    _nbClients++;
    _dispo = false;
    _debutService = _banque->simulation()->tempsCourant();


    std::poisson_distribution<int> distri(_tempsMoyenService);

    double heureDepart = _banque->simulation()->tempsCourant() + distri(Caissier::_generator);
    _banque->simulation()->ajouter(new Depart(heureDepart, _banque->simulation(), this, _client));
}

void Caissier::liberer()
{
    _client = nullptr;
    _dispo = true;

    _tempsOccupe+= _banque->simulation()->tempsCourant() - _debutService;
    _debutService = 0;
}
std::ostream &operator<<(std::ostream &os, const Caissier &caissier)
{
    os << "Taux d'occupation : " << caissier.tauxOccupation() << std::endl;
    os << "Nombre de clients servis : " << caissier.nbClients() << std::endl;
    return os;
}