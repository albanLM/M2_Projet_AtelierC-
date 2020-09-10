#include "../include/Banque.h"
#include "../include/FileAttente.h"
#include "../include/Simulation.h"
#include "../include/Caissier.h"
#include <cstddef>

Banque::Banque(){}
Banque::Banque(double* tempsMoyenServices, int nbCaissiers, Simulation& simulation)
{
    _tempsMoyenServices = tempsMoyenServices;
    _nbCaissiers = nbCaissiers;
    _nbClients = 0;
    _simulation = &simulation;

    _fileAttente = FileAttente();

    for (int i = 0; i < nbCaissiers; i++)
    {
        _caissiers[i] = Caissier(*this, tempsMoyenServices[i]);
    }
    
}
Banque:: ~Banque()
{
    delete[] _caissiers;
}

Caissier* Banque::caissierDispo()
{
    int index = 0;
    while (index<_nbCaissiers)
    {
        if (_caissiers[index].estDispo())
        {
            return &_caissiers[index];
        }
    }
    return NULL;
}

int Banque::nbCaissiers()const{return _nbCaissiers;}
int Banque::nbClients()const{return _nbClients;}
Simulation* Banque::simulation()const{return _simulation;}