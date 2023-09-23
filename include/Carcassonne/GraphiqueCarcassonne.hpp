#ifndef DEF_GRAPHIQUE_CARCASSONNE_HPP
#define DEF_GRAPHIQUE_CARCASSONNE_HPP

#include "Graphique.hpp"
#include "Config.hpp"
#include "Carcassonne/JeuCarcassonne.hpp"
#include "Carcassonne/PanneauCarcassonneGraphique.hpp"
#include "Carcassonne/PlateauCarcassonneGraphique.hpp"

class GraphiqueCarcassonne : public Graphique<BordTypeCarcassonne>
{
	private:
		/*
		virtual void gererEvenements();

		virtual void mettreAJour();

		virtual void afficher();
		*/
        
        /* Le clic gauche va faire une action suivante suivant la phase du tour.
        Par exemple dans le cas où le joueur a déjà posé une tuile, un autre clic gauche sur une tuile posera un partisan.
        */
        virtual void gererClicGauche(const sf::Vector2f& posClic);

	public:
		GraphiqueCarcassonne(const std::vector<std::string>& nomsJoueurs);

		virtual ~GraphiqueCarcassonne();
};

#endif // DEF_GRAPHIQUE_CARCASSONNE_HPP