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

int FileAttente::longueurMax()const{return _longueurMax;}
double FileAttente::longueurMoy()const{return _longueurMoy / _banque->simulation()->tempsCourant();}
double FileAttente::tempsMoyenAttente()const{return _tempsMoyenAttente / _banque->nbClients();}
bool FileAttente::estVide()const{return _clients.empty();}


void FileAttente::ajouter(Client *client)
{
    _clients.push_back(client);

    // Mise à jour de la taille maximale de la file d'attente
    if (_longueurMax < (int)_clients.size())
    {
        _longueurMax = _clients.size();   
    }
}

Client* FileAttente::retirer() {
    Client *client = _clients.front();

    // Mise à jour du temps d'attente moyen et de la longueur moyenne dans la file
    double attenteClient = _banque->simulation()->tempsCourant() - client->heureArrivee();
    _tempsMoyenAttente += attenteClient;
    _longueurMoy += attenteClient * _clients.size();

    _clients.pop_front();

    return client;
}