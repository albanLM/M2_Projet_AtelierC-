/**
* \file Simulation.h
* \brief Classe d'événement pour la simulation.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include "SED.h"
#include "Banque.h"

class Simulation : public SED
{
	private:
		const double _dureePrevue;			/*!< Durée prévu de la simulation*/
		const double _tempsMoyenArrivees;	/*!< Temps moyen entre chaque arrivée*/
		Banque _banque;						/*!< Banque*/

	public:
        Simulation(const Simulation&) = delete;

		/**
		 * \fn Simulation();
		 * \brief Constructeur de Simulation
		 */
		Simulation();

		/**
		 * \fn Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees);
		 * \brief Constructeur de simulation
		 */
		Simulation(double dureePrevue, int nbCaissier, double *tempsServices, double tempsMoyenArrivees);

		/**
		 * \fn double dureePrevue() const;
		 * \return double Durée Prévue
		 */
		double dureePrevue() const;

		/**
		 * \fn double tempsMoyenArrivees() const;
		 * \return double Temps moyen d'arrivées
		 */
		double tempsMoyenArrivees() const;

		Banque& banque();

		void afficherInfos();
};

#endif