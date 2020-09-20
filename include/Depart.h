/**
* \file Depart.h
* \brief Classe dérivée de Evenement. Représente le départ d'un Client. 
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef DEPART_H
#define DEPART_H

#include "Evenement.h"

class Caissier;
class Client;
class Simulation;

/**
 * @brief      Décrit le départ d'un Client de la simulation.
 */
class Depart : public Evenement
{
	private:
		Simulation *const _simulation;
		Caissier *const _caissier;
		Client *const _client;

	public:
        /**
         * @brief Suppression du constructeur par copie.
         */
        Depart(const Depart&) = delete;

		/**
		 * @brief      Constructeur de la classe Depart.
		 *
		 * @param[in]  heureDeclenchement  L'heure de déclenchement de l'événement de départ
		 * @param      simulation          La simulation
		 * @param      caissier            Le caissier qui libère le client
		 * @param      client              Le client qui quitte la simulation
		 */
		Depart(double heureDeclenchement, Simulation *const simulation, Caissier *const caissier, Client *const client);

		/**
		 * @brief      Traite l'événement de départ d'un Client.
		 */
		void traiter();
};

#endif