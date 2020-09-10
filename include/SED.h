/**
* \file SED.h
* \brief Classe de simulation à événements discrets.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef SED_H
#define SED_H

#include <vector>
#include <queue>

#include "Evenement.h"


/**
 * @brief      Cette classe décrit une simulation à événements discrets
 */
class SED
{
	protected:
		double _tempsCourant;
		std::priority_queue<Evenement*, std::vector<Evenement*>, compareEvenements> _echeancier;

	public:
		
		/**
		 * @brief      Construit une nouvelle instance de simulation.
		 */
		SED();
		
		/**
		 * @brief      Point d'entrée de la simulation.
		 * 
		 * Lance la simulation. Celle-ci se termine quand tout les événements de l'échéancier ont été traités.
		 * 
		 */
		void lancer();
		/**
		 * @brief      Ajoute un événement à la simulation.
		 *
		 * @param      e     Événement à ajouter
		 */
		void ajouter(Evenement *e);
		/**
		 * @brief      Retourne le temps courant de la simulation. 
		 */
		double tempsCourant() const;
};

#endif