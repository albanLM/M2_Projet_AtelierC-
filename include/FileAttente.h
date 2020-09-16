/**
* \file Evenement.h
* \brief Classe pour la file d'attente de clients (FIFO).
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef FILEATTENTE_H
#define FILEATTENTE_H

#include <deque>
#include <ostream>

#include "Client.h"

class Banque;

/**
 * @brief Décrit une file d'attente de clients de type FIFO.
 *
 * Lors d'un événement d'arrivée, si aucun caissier n'est disponible, le client est alors inséré à la fin de la file d'attente. Dès lors qu'un caissier se libère celui-ci sert le premier client client entré dans la file.
 * Certaines statistiques peuvent être demandées à la file d'attente :
 *  - le nombre moyen de client présents dans la file durant la simulation
 *  - le temps d'attente moyen par client
 *  - la longueur maximale de la file d'attente
 *  La file d'attente possède une capacité illimitée de clients.
 */
class FileAttente
{
	private:
		int _longueurMax;
		double _longueurMoy;
		double _tempsMoyenAttente;
		double _attenteClient;

		Banque *const _banque;

		// DeQueue
		std::deque<Client*> _clients;

    public:
        friend std::ostream &operator<<(std::ostream &os, const FileAttente &attente);

        /**
         * @brief Suppression du constructeur par copie.
         */
        FileAttente(const FileAttente&) = delete;

        /**
         * @brief Constructeur de la classe FileAttente.
         * @param banque
         */
		FileAttente(Banque *const banque = nullptr);

		/**
		 * \brief Getter
		 * @return La longueur maximale de la file d'attente.
		 */
		int longueurMax() const;

		/**
		 * \brief Getter
		 * @return La longueur moyenne de la file d'attente.
		 */
		double longueurMoy() const;

		/**
		 * \brief Getter
		 * @return La durée d'attente moyenne par client.
		 */
		double tempsMoyenAttente() const;

		/**
		 * @brief Ajoute un client à la fin de la file d'attente.
		 * @param client
		 */
		void ajouter(Client *client);

		/**
		 * \brief Getter
		 * @return Indique si la file est vide.
		 */
		bool estVide() const;

		/**
		 * @brief Retire de la file le premier client arrivé.
		 * @return Le client sortant de la file.
		 */
		Client* retirer();
};

#endif