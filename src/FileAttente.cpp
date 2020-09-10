#include "../include/FileAttente.h"
#include "../include/Client.h"
#include "../include/Banque.h"
#include "../include/SED.h"
#include "../include/Simulation.h"
#include <iostream>

FileAttente::FileAttente()
{
    _longueurMax = _longueurMoy = _tempsMoyenAttente = 0;
}
FileAttente::~FileAttente(){}

int FileAttente::longueurMax()const{return _longueurMax;}
double FileAttente::longueurMoy()const{return _longueurMoy;}
double FileAttente::tempsMoyenAttente()const{return _tempsMoyenAttente;}
bool FileAttente::estVide()const{return _clients.empty();}


void FileAttente::ajouter(Client *client)
{
    _clients.push_back(client);
    if (_longueurMax<(int)_clients.size())
    {
        _longueurMax = _clients.size();
        majLongueurMoy();
        
        
    }
    
}

void FileAttente::majTempsMoyenAttente(Client *client)
{
    double tpsArrivee = client->heureArrivee();
    double tpsCourant = _banque->simulation()->tempsCourant();

    double tpsAttente = tpsCourant-tpsArrivee;

    _tempsMoyenAttente = (_tempsMoyenAttente+tpsAttente)/tpsCourant;
}

void FileAttente::majLongueurMoy(){}