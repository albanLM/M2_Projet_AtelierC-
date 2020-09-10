#include "../include/Simulation.h"


Simulation::Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees)
    :_dureePrevue(dureePrevue),
    _tempsMoyenArrivees(tempsMoyenArrivees)   
{
    _dureeReelle = 0;
    _longueurMax = 0;
    _longueurMoy = 0;
    _nbClientServis = 0;
    
    _tempsAttenteMoy = 0;
    _tauxOccupationParCaisse = 0;
    
    for (int i = 0; i < nbCaissier; i++)
    {
        _nbClientParCaisse[i] = 0;
    }
    

    _banque = Banque(tempsServices, nbCaissier, *this);
}

double Simulation::dureePrevue()const{return _dureePrevue;}
double Simulation::tempsMoyenArrivees()const{return _tempsMoyenArrivees;}
Banque& Simulation::banque(){return _banque;}
