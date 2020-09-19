#include <boost/program_options.hpp>
#include <iostream>
#include "include/Simulation.h"

namespace po = boost::program_options;

bool traiterArguments(int argc, char const *argv[], int &nbCaissier, double &dureePrevue, double &tempsMoyenArrivees, std::vector<double> &tempsMoyServices) {
    try {
        // Déclare les options supportées
        po::options_description description("Options autorisées");
        description.add_options()
                ("help, h", "Affiche un message d'aide")
                ("nc", po::value<int>(&nbCaissier)->required(), "Défini le nombre de caissier de la simulation")
                ("st", po::value<std::vector<double>>(&tempsMoyServices)->multitoken()->required(),
                 "Défini le temps moyen de service par caissier")
                ("dp", po::value<double>(&dureePrevue)->required(),
                 "Défini la durée prévue de la simulation (défaut = 100.0)")
                ("tm", po::value<double>(&tempsMoyenArrivees)->required(),
                 "Défini le temps moyen d'arrivée (défaut = 5.0");

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(description).style(
                po::command_line_style::unix_style | po::command_line_style::allow_long_disguise).run(), vm);
        // Si l'argument d'aide à été indiqué, affiche le message d'aide
        if (vm.count("help"))
        {
            std::cout << description << std::endl;
            return false;
        }

        po::notify(vm);

        // Vérifie que le nombre de temps de services correspond au nombre de caissier
        if(vm.count("st") && tempsMoyServices.size() != nbCaissier) {
            std::cerr << "Le nombre de temps de services ne correspond pas au nombre de caissier !\nNombre de caissier = " << nbCaissier << " / Nombre de temps = " << tempsMoyServices.size() << std::endl;
            return false;
        }
    }
    catch(std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << "\n";
        return false;
    }
    catch(...)
    {
        std::cerr << "Erreur inconnue !" << "\n";
        return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int nbCaissier;
    double dureePrevue;
    double tempsMoyenArrivees;
    std::vector<double> tempsMoyServices;

    if (!traiterArguments(argc, argv, nbCaissier, dureePrevue, tempsMoyenArrivees, tempsMoyServices)) {
        return 1;
    }

    std::cout << "### Paramètres de la simulation ###" << std::endl;
    std::cout << "Durée de la simulation : " << dureePrevue << std::endl;
    std::cout << "Temps moyen entre chaque arrivée : " << tempsMoyenArrivees << std::endl;
    std::cout << "Nombre de caissier : " << nbCaissier << std::endl;
    std::cout << "Temps moyen de services : ";
    // Transforme le vector en tableau pour le passer à la simulation
    double tempsMoyServicesTableau[nbCaissier];
    for (int i = 0; i < nbCaissier; ++i)
    {
        std::cout << tempsMoyServices[i] << ", ";
        tempsMoyServicesTableau[i] = tempsMoyServices[i];
    }
    std::cout << "\b\b\n" << std::endl;

    // Crée et lance la simulation
    Simulation simulation(dureePrevue, nbCaissier, tempsMoyServicesTableau, tempsMoyenArrivees);
	simulation.lancer();

	// Affiche les informations et statistiques de la simulation
	std::cout << "### Résultats de la simulation ###\n" << simulation << std::endl;
	return 0;
}