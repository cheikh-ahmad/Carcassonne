#ifndef DEF_TUILE_TRAX_GRAPHIQUE_HPP
#define DEF_TUILE_TRAX_GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include "Trax/TuileTrax.hpp"
#include "Config.hpp"
#include "TuileGraphique.hpp"

class TuileTraxGraphique : public TuileGraphique<BordTypeTrax>
{
	private:	
		// Redéfinition d'une méthode virtuelle de sf::Drawable, va permettre de dessiner notre TuileTrax à partir d'un sf::RenderWindow.
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Sprite tuileSprite_;

	public:
		TuileTraxGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const TuileTrax* const Trax, float tailleTuile);

		virtual void mettreAJour();

};

#endif // DEF_TUILE_TRAX_GRAPHIQUE_HPP