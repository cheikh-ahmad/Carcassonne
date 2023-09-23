#ifndef DEF_GRAPHIQUE_HPP
#define DEF_GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include "PanneauGraphique.hpp"
#include "PlateauGraphique.hpp"
#include "Jeu.hpp"
#include "RessourcesId.hpp"

template<typename BordType>
class Graphique
{

	protected:
		Jeu<BordType>* jeu_;

		sf::RenderWindow window_;

		/* Gestionnaires de ressources */
		GestionTextures* gestionTextures_;

		GestionPolices* gestionPolices_;

		PlateauGraphique<BordType>* plateauGraphique_;

		PanneauGraphique<BordType>* panneauGraphique_;

		virtual void gererEvenements();

		virtual void mettreAJour();

		virtual void afficher();

		/* Méthodes événements */
		virtual void gererClicDroit(const sf::Vector2f&/* posClic*/);

		virtual void gererClicGauche(const sf::Vector2f& posClic);

		virtual void gererFlecheGauche();

		virtual void gererFlecheDroite();

		virtual void gererEspace();

		
	public:
		Graphique(Jeu<BordType>* const jeu);

		void lancer();

		virtual ~Graphique();
	
};

#include "Graphique.tpp"

#endif // DEF_GRAPHIQUE_HPP
