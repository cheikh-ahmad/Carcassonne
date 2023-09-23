#ifndef DEF_PLATEAU_CARCASSONNE_GRAPHIQUE_HPP
#define DEF_PLATEAU_CARCASSONNE_GRAPHIQUE_HPP

#include "PlateauGraphique.hpp"
#include "Carcassonne/PlateauCarcassonne.hpp"
#include "Carcassonne/TuileCarcassonneGraphique.hpp"

class PlateauCarcassonneGraphique : public PlateauGraphique<BordTypeCarcassonne>
{
    public:
        PlateauCarcassonneGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const PlateauCarcassonne* const plateau, float taillePlateau);
};

#endif // DEF_PLATEAU_CARCASSONNE_GRAPHIQUE_HPP