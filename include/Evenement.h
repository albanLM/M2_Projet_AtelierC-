/**
* \file Evenement.h
* \brief Classe d'événement pour la simulation.
* \author J.P. Pauquet & A. Le Moult
* \date 09/09/2020
*/

#ifndef EVENEMENT_H
#define EVENEMENT_H


class SED;
/**
 * @brief      Décrit un événement utilisable dans une Simulation à Événements Discrets (SED).
 */
class Evenement
{
	protected:
		double _heureDeclechement;

	public:
		/**
		 * @brief      Constructeur de la classe Evenement.
		 *
		 * @param[in]  heureDeclechement  L'heure de déclenchement de
		 *                                l'événement
		 */
		Evenement(double heureDeclechement);


		/**
		 * @brief      Destructeur virtuel pour les événements.
		 */
		virtual ~Evenement();

		/**
		 * \brief Getter
		 * \return     L'heure de déclenchement de l'événement.
		 */
		double heureDeclechement();

		/**
		 * @brief      Traite l'événement.
		 */
		virtual void traiter() = 0;
};

/**
 * @brief      Décrit la comparaison d'événements.
 * 
 * La comparaison d'événements est nécessaire pour l'utilisation d'une PriorityQueue
 * 
 */
class compareEvenements {
	public:
	  /**
	   * @brief      Opérateur d'appel de fonction.
	   *
	   * @param      e1    L'événement n°1
	   * @param      e2    L'événement n°2
	   *
	   * @return     Le résultat de la comparaison de l'heure de déclenchement des deux événements.
	   */
	  int operator() ( Evenement *e1, Evenement *e2) {
	    return e1->heureDeclechement() > e2->heureDeclechement();
	  }
};

#endif