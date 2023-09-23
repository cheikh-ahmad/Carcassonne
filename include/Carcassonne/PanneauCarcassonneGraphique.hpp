#ifndef DEF_PANNEAU_CARCASSONNE_GRAPHIQUE_HPP
#define DEF_PANNEAU_CARCASSONNE_GRAPHIQUE_HPP

#include "PanneauGraphique.hpp"
#include "Carcassonne/TuileCarcassonne.hpp"
#include "Carcassonne/JeuCarcassonne.hpp"
#include "Carcassonne/TuileCarcassonneGraphique.hpp"

class PanneauCarcassonneGraphique : public PanneauGraphique<BordTypeCarcassonne>
{
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        PanneauCarcassonneGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const JeuCarcassonne* const jeu, float panneauTailleX, float panneauTailleY);

        virtual void mettreAJour();
};

#endif // DEF_PANNEAU_CARCASSONNE_GRAPHIQUE_HPP