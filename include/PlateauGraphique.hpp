#ifndef DEF_PLATEAU_GRAPHIQUE_HPP
#define DEF_PLATEAU_GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include "Plateau.hpp"
#include "Config.hpp"
#include "TuileGraphique.hpp"

/* Cette classe template va gérer l'affichage graphique d'un plateau sur une fenêtre. On va utiliser pour cela
la classe template de Tuile. 
*/
template<typename BordType>
class PlateauGraphique : public sf::Drawable, public sf::Transformable
{
    private:
        sf::RectangleShape rectangleMilieu_;
        
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
        size_t taillePlateau_;
        const Plateau<BordType>* const plateau_;
        std::vector<std::vector<TuileGraphique<BordType>*>> tuilesGraphiques_;

        const GestionTextures* const gestionTextures_;

		const GestionPolices* const gestionPolices_;

        float getTailleTuile() const;
    public:
        PlateauGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const Plateau<BordType>* const plateau, size_t plateauTaille);

        // Converti une position en px en une position en indice. 
        sf::Vector2<size_t> getIndiceTuile(const sf::Vector2f posGraphique) const;

        virtual void mettreAJour();

        virtual ~PlateauGraphique();
};

#include "PlateauGraphique.tpp"

#endif // DEF_PLATEAU_GRAPHIQUE_HPP