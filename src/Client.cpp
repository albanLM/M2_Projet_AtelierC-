#include "../include/Client.h"

Client::Client(double heure)
    :_heureArrivee(heure){}

double Client::heureArrivee() const
{
    return _heureArrivee;

}
