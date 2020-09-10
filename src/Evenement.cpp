#include "../include/Evenement.h"

Evenement::Evenement(double heureDeclechement, SED &simulation) : _simulation(&simulation)
{
    _heureDeclechement = heureDeclechement;
}

double Evenement::heureDeclechement() {
	return _heureDeclechement;
}