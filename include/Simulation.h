/**
* \file Simulation.h
* \brief Classe simulation.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include "SED.h"
#include "Banque.h"

/**
 * @brief Décrit une Simulation.
 */
class Simulation : public SED
{
	private:
		const double _dureePrevue;			/*!< Durée prévu de la simulation*/
		const double _tempsMoyenArrivees;	/*!< Temps moyen entre chaque arrivée*/
		Banque _banque;						/*!< Banque*/

	public:
        /**
         * @brief Suppression du constructeur par copie.
         */
        Simulation(const Simulation&) = delete;

		/**
		 * \fn Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees);
		 * \brief Constructeur de la classe Simulation.
		 */
		Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees);

        /**
         * \fn double dureePrevue() const;
         * \brief Getter
         * \return La durée prévue de la simlation.
         */
		double dureePrevue() const;

		/**
		 * \fn double tempsMoyenArrivees() const;
		 * \brief Getter
		 * \return La durée moyenne entre chaque arrivées.
		 */
		double tempsMoyenArrivees() const;

		/**
		 * \brief Getter
		 * @return Une référence vers la banque.
		 */
		Banque& banque();

		/**
		 * @brief Affiche les informations et les statistiques de la simulation.
		 */
		void afficherInfos();
};

#endif