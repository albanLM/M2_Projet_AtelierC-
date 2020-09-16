/**
* \file Banque.h
* \brief Classe banque.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/
#ifndef BANQUE_H
#define BANQUE_H

#include <ostream>
#include "FileAttente.h"
#include "Caissier.h"

class Simulation;
/**
 * @brief Décrit une banque accueuillant des clients.
 *
 * La banque est composée de caissiers et d'une file d'attente. Elle est capable de recevoir des clients et d'effectuer des services auprès de ceux-ci.
 */
class Banque
{
	private:
		int _nbCaissiers;				/*!< Nombre de caissier*/
		double* _tempsMoyenServices;	/*!< Temps moyen de service de chaque caissier*/
		FileAttente _fileAttente;		/*!< File d'attente*/
		Caissier *_caissiers;			/*!< Caissiers de la banque*/
		Simulation* _simulation;		/*!< Lien vers la simulation*/

	public:
        friend std::ostream &operator<<(std::ostream &os, const Banque &banque);

        /**
         * @brief Suppression du constructeur par copie.
         */
        Banque(const Banque&) = delete;

		/**
		 * \brief Constructeur par défaut.
		 */
		Banque();

		/**
		 * \fn Banque(double* tempsMoyenService, int nbCaissiers)
		 * \param[in] tempsMoyenServices Temps moyen de service pour chaque caissier
		 * \param[in] nbCaissier Nombre de caissier
		 * \brief Constructeur de la classe Banque.
		 */
		Banque(double* tempsMoyenServices, int nbCaissiers, Simulation& simulation);

		/**
		 * @brief      Destructeur de l'objet Banque.
		 */
		~Banque();

		/**
		 * \fn Caissier* caissierDispo()
		 * \return Caissier ou NULL     Le premier caissier disponible
		 * \brief Retourne le premier caissier disponible, si il existe.
		 */
		Caissier* caissierDispo() const;

		/**
		 * \fn int nbCaissiers() const
		 * \brief Getter
		 * \return Le nombre de caissier dans la banque.
		 */
		int nbCaissiers() const;

		/**
		 * \fn int nbClients() const
		 * \brief Getter
		 * \return Le nombre de client servis.
		 */
		int nbClients() const;

		/**
		 * \fn Simulation* simulation()const
		 * \brief Getter
		 * \return Un pointeur vers la simulation.
		 */
		Simulation* simulation() const;

		/**
		 * \fn FileAttente& fileAttente() const
		 * \brief Getter
		 * \return Une référence vers la file d'attente.
		 */
		FileAttente& fileAttente();
};

#endif