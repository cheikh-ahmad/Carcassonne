#ifndef DEF_TUILE_DOMINO_GRAPHIQUE_HPP
#define DEF_TUILE_DOMINO_GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include "Domino/TuileDomino.hpp"
#include "Config.hpp"
#include "TuileGraphique.hpp"

class TuileDominoGraphique : public TuileGraphique<BordTypeDomino>
{
	private:
		/* Une tuile de domino est constitué de 17 rectangles (4 carrés sur les bords, 1 carré au centre, et 12 rectangles).
		 * Pour essayer de simplifier les choses, on représente la tuile comme un vecteur de 17 rectangles.
		 */
		std::vector<sf::RectangleShape> rectangles_;
		
		sf::Font* police_;
		
		/* Ce sont les chiffres présents sur les bords des dominos */
		std::vector<sf::Text> textes_;
		
		// Redéfinition d'une méthode virtuelle de sf::Drawable, va permettre de dessiner notre TuileDominos à partir d'un sf::RenderWindow.
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		TuileDominoGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
			const TuileDomino* const domino, float tailleTuile);

		virtual void mettreAJour();

};


#endif // DEF_TUILE_DOMINO_GRAPHIQUE_HPP