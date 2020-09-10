/**
* \file Arrivee.h
* \brief Classe dérivée de Evenement. Représente l'arrivée d'un Client. 
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef ARRIVEE_H
#define ARRIVEE_H

#include "Evenement.h"

class Simulation;

/**
 * @brief      Cette classe décrit une arrivée de Client dans la simulation.
 */
class Arrivee : public Evenement
{
	private:
		Simulation *const _simulation;

	public:
		/**
		 * @brief      Construit une nouvelle instance.
		 *
		 * @param[in]  heureDeclenchement  L'heure de déclenchement de l'événement.
		 * @param      simulation          La simulation.
		 */
		Arrivee(double heureDeclenchement, Simulation *const simulation);

		/**
		 * @brief      Traite l'événement d'arrivée d'un Client.
		 */
		void traiter();
};

#endif