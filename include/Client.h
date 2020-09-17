/**
 * \file Caissier.h
 * \brief Classe caissier
 * \author J.P. Pauquet & A. Le Moult
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

/**
 * @brief Décrit un client de la banque.
 */
class Client
{
	private:
		double _heureArrivee;

	public:
        /**
         * @brief Suppression du constructeur par copie.
         */
        Client(const Client&) = delete;

        /**
         * @brief Constructeur de la classe Client.
         * @param heureArrivee Heure d'arrivée du client
         */
		Client(double heureArrivee);
		
		/**
		 * @brief Getter
		 * \return L'heure d'arrivée du client.
		 */
		double heureArrivee() const;
		friend std::ostream& operator<<(std::ostream& os, Client c);
};

#endif