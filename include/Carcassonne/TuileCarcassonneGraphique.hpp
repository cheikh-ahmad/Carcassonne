#ifndef DEF_TUILE_CARCASSONNE_GRAPHIQUE_HPP
#define DEF_TUILE_CARCASSONNE_GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include "Carcassonne/TuileCarcassonne.hpp"
#include "Config.hpp"
#include "TuileGraphique.hpp"

class TuileCarcassonneGraphique : public TuileGraphique<BordTypeCarcassonne>
{
	private:	
		// Redéfinition d'une méthode virtuelle de sf::Drawable, va permettre de dessiner notre TuileCarcassonne à partir d'un sf::RenderWindow.
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		Textures fromIdToTextures(const std::string& id);

        sf::Sprite tuileSprite_;

	public:
		TuileCarcassonneGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const TuileCarcassonne* const Carcassonne, float tailleTuile);

		virtual void mettreAJour();

};

#endif // DEF_TUILE_CARCASSONNE_GRAPHIQUE_HPP