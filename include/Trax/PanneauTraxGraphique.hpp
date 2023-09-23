#ifndef DEF_PANNEAU_TRAX_GRAPHIQUE_HPP
#define DEF_PANNEAU_TRAX_GRAPHIQUE_HPP

#include "PanneauGraphique.hpp"
#include "Trax/TuileTrax.hpp"
#include "Trax/JeuTrax.hpp"
#include "Trax/TuileTraxGraphique.hpp"

class PanneauTraxGraphique : public PanneauGraphique<BordTypeTrax>
{
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        PanneauTraxGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const JeuTrax* const jeu, float panneauTailleX, float panneauTailleY);

        virtual void mettreAJour();
};

#endif // DEF_PANNEAU_TRAX_GRAPHIQUE_HPP