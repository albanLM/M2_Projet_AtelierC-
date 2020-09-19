#include "../include/FileAttente.h"
#include "../include/Client.h"
#include "../include/Banque.h"
#include "../include/SED.h"
#include "../include/Simulation.h"
#include <iostream>

FileAttente::FileAttente(Banque *const banque) : _banque(banque)
{
    _longueurMax = 0;
    _longueurMoy = _tempsMoyenAttente = _attenteClient = 0.0;
}

int FileAttente::longueurMax() const { 
    return _longueurMax;
}

double FileAttente::longueurMoy() const {
    if(_longueurMoy == 0 || _attenteClient == 0) return 0;
    return _banque->simulation()->tempsCourant() != 0 ? _longueurMoy / _attenteClient : 0;
}

double FileAttente::tempsMoyenAttente() const {
    return _banque->nbClients() != 0 ? _tempsMoyenAttente / _banque->nbClients() : 0;
}

bool FileAttente::estVide() const {
    return _clients.empty();
}

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
    _attenteClient += attenteClient;

    _clients.pop_front();

    return client;
}
std::ostream &operator<<(std::ostream &os, const FileAttente &attente)
{
    os << "Taille max de la file d'attente : " << attente.longueurMax() << std::endl;
    os << "Taille moyenne de la file d'attente : " << attente.longueurMoy() << std::endl;
    os << "Temps d'attente moyen dans la file d'attente : " << attente.tempsMoyenAttente() << std::endl;
    return os;
}
