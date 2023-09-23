#ifndef DEF_TUILE_GRAPHIQUE
#define DEF_TUILE_GRAPHIQUE

#include <SFML/Graphics.hpp>
#include "GestionRessources.hpp"
#include "RessourcesId.hpp"
#include "Tuile.hpp"

/* Cette classe template va représenter graphiquement une tuile. L'idée est qu'elle va prendre en paramètre une tuile, et créer une représentation
graphique correspondant à cette tuile. Par exemple dans le cas d'un domino, cette classe va écrire les chiffres au bord du domino.
La particularité de cette classe est qu'elle peut prendre une tuile vide en paramètre, c'est à dire une tuile égale à nullptr. Dans ce cas là, elle représentera
un simple carré vide.
*/
template<typename BordType>
class TuileGraphique : public sf::Drawable, public sf::Transformable
{
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
        // Représente la taille de la tuile en pixel.
        float tailleTuile_;

        const Tuile<BordType>* tuile_;

        sf::RectangleShape tuileVide_;

        const GestionTextures* const gestionTextures_;

		const GestionPolices* const gestionPolices_;
    public:
        TuileGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, const Tuile<BordType>* const tuile, float tailleTuile);

        // Change la tuile associé à la représentation graphique. Utile pour passer de nullptr a une tuile que l'on vient de poser.
        void setTuile(const Tuile<BordType>* const tuile);

        virtual void mettreAJour();

        float getTailleTuile() const;


        
};

#include "TuileGraphique.tpp"

#endif // DEF_TUILE_GRAPHIQUE