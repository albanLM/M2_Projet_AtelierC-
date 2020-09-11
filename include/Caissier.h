/**
 * \file Caissier.h
 * \brief Classe caissier
 * \author jp pauquet
 * 
*/

#ifndef CAISSIER_H
#define CAISSIER_H
#include "Client.h"

class Banque;

class Caissier
{
	private:
		Banque *_banque;	/*!< Banque*/
		Client *_client;	/*!< Client*/

		double _tempsMoyenService;	/*!< Temps moyen de service*/
		double _tauxOccupation;		/*!< Taux d'occupation*/
		int _nbClients;				/*!< Nombre de clients servis*/
		bool _dispo;				/*!< Disponibilité du caissier*/

	public:
		/**
		 * \fn Caissier(Banque &banque, double tempsMoyenService)
		 * \brief Constructeur de Caissier
		 * \param[in] Banque 
		 * \param[in] tempsMoyenService 
		 */
		Caissier(Banque &banque, double tempsMoyenService);

		/**
		 * \fn double tempsMoyenService() const
		 * \return Retourne le temps moyen par service
		 */
		double tempsMoyenService() const;

		/**
		 * \fn double tauxOccupation() const
		 * \return  Retourne de taux d'occupation par une loi de Poisson
		 */
		double tauxOccupation() const;

		/**
		 * \fn int nbClients() const
		 * \return Retourne le nombre de client servi par le caissier
		 */
		int nbClients() const;

		/**
		 * \fn bool estDispo() const
		 * \return Indique si le caissier est libre ou non
		 */
		bool estDispo() const;

		/**
		 * \fn void servir(Client client)
		 * \brief Sers un client, se met indisponible
		 * \param[in] Le client à servir
		 */
		void servir(Client &client);

		/**
		 * \fn         void liberer()
		 * \brief      Libère le caissier et le rend disponible
		 */
		void liberer();
};

#endif