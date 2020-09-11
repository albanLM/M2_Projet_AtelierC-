#include "../include/Evenement.h"

Evenement::Evenement(double heureDeclechement)
{
    _heureDeclechement = heureDeclechement;
}

Evenement::~Evenement() {}

double Evenement::heureDeclechement() {
	return _heureDeclechement;
}