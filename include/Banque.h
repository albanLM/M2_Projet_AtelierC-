/**
* \file Banque.h
* \brief Classe d'événement pour la simulation.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/
#ifndef BANQUE_H
#define BANQUE_H

#include "FileAttente.h"
#include "Caissier.h"

class Simulation;
class Banque
{
	private:
		int _nbCaissiers;				/*!< Nombre de caissier*/
		int _nbClients;					/*!< Nombre de Client*/
		double* _tempsMoyenServices;	/*!< Temps moyen de service de chaque caissier*/
		FileAttente _fileAttente;		/*!< File d'attente*/
		Caissier *_caissiers;			/*!< Caissiers de la banque*/
		Simulation* _simulation;		/*!< Lien vers la simulation*/

	public:
		/**
		 * \brief Constructeur par default
		 */
		Banque();

		/**
		 * \fn Banque(double* tempsMoyenService, int nbCaissiers)
		 * \param[in] tempsMoyenServices Temps moyen de service pour chaque caissier
		 * \param[in] nbCaissier Nombre de caissier
		 */
		Banque(double* tempsMoyenServices, int nbCaissiers, Simulation& simulation);
		~Banque();
	
		/**
		 * \fn Caissier* caissierDispo()
		 * \return Caissier ou NULL
		 * \brief Retourne le premier caissier disponible
		 */
		Caissier* caissierDispo() const;

		/**
		 * \fn int nbCaissiers() const
		 * \return Nombre de caissier
		 */
		int nbCaissiers() const;

		/**
		 * \fn int nbClients() const
		 * \return Nombre de client
		 */
		int nbClients() const;

		/**
		 * \fn Simulation* simulation()const
		 * \return Retourne la simulation par référence
		 */
		Simulation* simulation() const;

		/**
		 * \fn FileAttente& fileAttente() const
		 * \return Retourne une référence vers la file d'attente
		 */
		FileAttente& fileAttente();
		
};

#endif