#ifndef DEF_PLATEAU_DOMINO_GRAPHIQUE_HPP
#define DEF_PLATEAU_DOMINO_GRAPHIQUE_HPP

#include "PlateauGraphique.hpp"
#include "Domino/PlateauDomino.hpp"
#include "Domino/TuileDominoGraphique.hpp"

class PlateauDominoGraphique : public PlateauGraphique<BordTypeDomino>
{
    public:
        PlateauDominoGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const PlateauDomino* const plateau, float taillePlateau);
};
#endif // DEF_PLATEAU_DOMINO_GRAPHIQUE_HPP
