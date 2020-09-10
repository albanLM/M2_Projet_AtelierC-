#include "../include/Caissier.h"
#include "../include/Banque.h"
#include <cmath>

Caissier::Caissier( Banque &banque, 
                    double tempsMoyenService)
                    :_banque(&banque),
                    _tempsMoyenService(tempsMoyenService)                    
{
    _dispo = 1;
    _nbClients = 0;
}
double Caissier::tempsMoyenService() const{return _tempsMoyenService;}
double Caissier::tauxOccupation() const
{
    return _tempsMoyenService*exp(-_tempsMoyenService);
}
int Caissier::nbClients() const{return _nbClients;}
bool Caissier::estDispo() const{return _dispo;}

void Caissier::servir(Client client)
{
    _client = &client;
    _nbClients++;
    _dispo = 0;
}
Client Caissier::liberer()
{
    Client c = *_client;
    _client = NULL;
    _dispo = 1;
    return c;
}