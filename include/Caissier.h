/**
 * \file Caissier.h
 * \brief Classe caissier
 * \author jp pauquet
*/

#ifndef CAISSIER_H
#define CAISSIER_H

#include <random>
#include <ostream>

class Client;
class Banque;

/**
 * @brief Décrit un caissier de la banque.
 */
class Caissier
{
	private:
		Banque *_banque;	/*!< Banque*/
		Client *_client;	/*!< Client*/

		double _tempsMoyenService;	/*!< Temps moyen de service*/
		double _tauxOccupation;		/*!< Taux d'occupation*/
		int _nbClients;				/*!< Nombre de clients servis*/
		bool _dispo;				/*!< Disponibilité du caissier*/
		double _debutService;
		double _tempsOccupe;			/*!< Temps total de service*/

		static std::default_random_engine _generator;

	public:
        /**
         * @brief Suppression du constructeur par copie.
         */
        Caissier(const Caissier&) = delete;

		/**
		 * @brief      Constructeur par défaut.
		 */
		Caissier();

		/**
		 * \fn Caissier(Banque &banque, double tempsMoyenService)
		 * \brief Constructeur de la classe Caissier.
		 * \param[in] Banque 
		 * \param[in] tempsMoyenService 
		 */
		Caissier(Banque &banque, double tempsMoyenService);

		/**
		 * \fn double tempsMoyenService() const
		 * \brief Getter
		 * \return La durée moyenne d'un service.
		 */
		double tempsMoyenService() const;

		/**
		 * \fn double tauxOccupation() const
		 * \brief Getter
		 * \return  Le taux d'occupation du caissier, exprimé en pourcentage.
		 */
		double tauxOccupation() const;

		/**
		 * \fn int nbClients() const
		 * \brief Getter
		 * \return Le nombre de client servis par le caissier.
		 */
		int nbClients() const;

		/**
		 * \fn bool estDispo() const
		 * \brief Getter
		 * \return Indique si le caissier est disponible ou non.
		 */
		bool estDispo() const;

		/**
		 * \fn void servir(Client client)
		 * \brief Sers un client et rend le caissier indisponible.
		 * \param[in] Le client à servir
		 */
		void servir(Client &client);

		/**
		 * \fn         void liberer()
		 * \brief      Libère le client et rend le caissier disponible.
		 */
		void liberer();

        friend std::ostream &operator<<(std::ostream &os, const Caissier &caissier);
};

#endif