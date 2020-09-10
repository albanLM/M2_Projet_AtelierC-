#include "../include/Evenement.h"

Evenement::Evenement(double heureDeclechement)
{
    _heureDeclechement = heureDeclechement;
}

double Evenement::heureDeclechement() {
	return _heureDeclechement;
}