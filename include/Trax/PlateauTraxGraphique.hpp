#ifndef DEF_PLATEAU_TRAX_GRAPHIQUE_HPP
#define DEF_PLATEAU_TRAX_GRAPHIQUE_HPP

#include "PlateauGraphique.hpp"
#include "Trax/PlateauTrax.hpp"
#include "Trax/TuileTraxGraphique.hpp"

class PlateauTraxGraphique : public PlateauGraphique<BordTypeTrax>
{
    public:
        PlateauTraxGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const PlateauTrax* const plateau, float taillePlateau);
};

#endif // DEF_PLATEAU_TRAX_GRAPHIQUE_HPP