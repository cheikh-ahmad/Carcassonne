#include <iostream>
#include "Domino/GraphiqueDomino.hpp"
#include "Trax/GraphiqueTrax.hpp"
#include "Carcassonne/GraphiqueCarcassonne.hpp"

std::vector<std::string> demandeJoueurs(size_t nbJoueurs)
{
	std::vector<std::string> nomsJoueurs{nbJoueurs, ""};
	std::cout << "Saisissez le nom des joueurs" << std::endl;
	for(size_t i = 0; i < nbJoueurs; ++i)
	{
		std::cout << "Joueur " << i + 1 << " : "; std::cin >> nomsJoueurs[i];
	}

	return nomsJoueurs;
}

int main()
{		
	int choixJeu;
	std::cout << "Menu" << std::endl;
	std::cout << "Selectionner votre jeu (par exemple écrire: 1 pour sélectionner le Domino): " << std::endl;
	std::cout << "1) Dominos" << std::endl;
	std::cout << "2) Trax" << std::endl;
	std::cout << "3) Carcassonne" << std::endl;
	std::cout << "Choix :"; std::cin >> choixJeu;
	
	
	if(choixJeu == 1)
	{
		size_t nbJoueurs;
		std::cout << "Choisissez le nombre de joueur : "; std::cin >> nbJoueurs;
		std::vector<std::string> nomsJoueurs = demandeJoueurs(nbJoueurs);
		try
		{
			GraphiqueDomino graphiqueDomino{nomsJoueurs};
			graphiqueDomino.lancer();
		}
		catch(const std::exception& e)
		{
			std::cout << "Une exception a été levée : " << e.what() << std::endl;
		}
		
	}
	else if(choixJeu == 2)
	{
		std::vector<std::string> nomsJoueurs = demandeJoueurs(2);

		try
		{
			GraphiqueTrax graphiqueTrax{nomsJoueurs};
			graphiqueTrax.lancer();
		}
		catch(const std::exception& e)
		{
			std::cout << "Une exception a été levée : " << e.what() << std::endl;
		}
	}
	else if(choixJeu == 3)
	{
		size_t nbJoueurs;
		std::cout << "Choisissez le nombre de joueur : "; std::cin >> nbJoueurs;
		std::vector<std::string> nomsJoueurs = demandeJoueurs(nbJoueurs);
		try
		{
			GraphiqueCarcassonne graphiqueCarcassonne{nomsJoueurs};
			graphiqueCarcassonne.lancer();
		}
		catch(const std::exception& e)
		{
			std::cout << "Une exception a été levée : " << e.what() << std::endl;
		}
		
	}
	else
		return -1;
	return 0;
}
