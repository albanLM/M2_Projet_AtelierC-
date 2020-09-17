#include "../include/Client.h"
#include <iostream>

Client::Client(double heure)
    :_heureArrivee(heure){}

double Client::heureArrivee() const
{
    return _heureArrivee;

}


std::ostream& operator<<(std::ostream& os, Client c)
		{
			os << "client : heureArrivée = " << c.heureArrivee() << " " << std::endl;
			return os;
		}