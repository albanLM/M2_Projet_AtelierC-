#include "../include/Banque.h"
#include "../include/FileAttente.h"
#include "../include/Simulation.h"
#include "../include/Caissier.h"

#include <iostream>

Banque::Banque() {}

Banque::Banque(double* tempsMoyenServices, int nbCaissiers, Simulation& simulation)
{
    _tempsMoyenServices = tempsMoyenServices;
    _nbCaissiers = nbCaissiers;
    _simulation = &simulation;

    new (&_fileAttente) FileAttente(this);

    _caissiers = new Caissier[nbCaissiers];

    for (int i = 0; i < nbCaissiers; i++)
    {
        _caissiers[i] = Caissier(*this, tempsMoyenServices[i]);
    }
}

Banque:: ~Banque()
{
    delete[] _caissiers;
}

Caissier* Banque::caissierDispo() const
{
    int index = 0;
    while (index<_nbCaissiers)
    {
        if (_caissiers[index].estDispo())
        {
            return &_caissiers[index];
        }
        index++;
    }
    return nullptr;
}

int Banque::nbCaissiers() const { return _nbCaissiers; }
int Banque::nbClients() const {
    int nbClient = 0;
    for (int i = 0; i < _nbCaissiers; ++i)
    {
        nbClient += _caissiers[i].nbClients();
    }
    return nbClient;
}
Simulation* Banque::simulation() const { return _simulation; }

FileAttente& Banque::fileAttente() { return _fileAttente; }

std::ostream &operator<<(std::ostream &os, const Banque &banque)
{
    os << "Clients servis durant la simulation : " << banque.nbClients() << std::endl;
    os << banque._fileAttente;
    for (int i = 0; i < banque._nbCaissiers; ++i)
    {
        os << "\nCaissier n°" << i << " : " << std::endl;
        os << banque._caissiers[i];
    }
    return os;
}
