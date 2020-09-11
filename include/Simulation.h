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

		double _dureeReelle;				/*!< Durée réel de la sumulation*/
		int _longueurMax;					/*!< Longueur maximum de la queue*/
		int _longueurMoy;					/*!< Longueur moyenne de la queue*/
		int _nbClientServis;				/*!< Nombre de CLient servis*/
		int * _nbClientParCaisse;			/*!< Nombre de client servis dans chaque caisse*/
		double _tempsAttenteMoy;			/*!< Temps d'attente moyen dans la file d'attente*/
		double* _tauxOccupationParCaisse;	/*!< Taux d'occupation de chaque caissier*/

	public:

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
		 * \fn ~Simulation();
		 * \brief Destructeur de simulation
		 */
		~Simulation();
		
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
};

#endif