#ifndef DEF_PANNEAU_DOMINO_GRAPHIQUE_HPP
#define DEF_PANNEAU_DOMINO_GRAPHIQUE_HPP

#include "PanneauGraphique.hpp"
#include "Domino/TuileDomino.hpp"
#include "Domino/JeuDomino.hpp"
#include "Domino/TuileDominoGraphique.hpp"

class PanneauDominoGraphique : public PanneauGraphique<BordTypeDomino>
{
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        PanneauDominoGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const JeuDomino* const jeu, float panneauTailleX, float panneauTailleY);

        virtual void mettreAJour();
};
#endif // DEF_PANNEAU_DOMINO_GRAPHIQUE_HPP