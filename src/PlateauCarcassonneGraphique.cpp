#include "Carcassonne/PlateauCarcassonneGraphique.hpp"

PlateauCarcassonneGraphique::PlateauCarcassonneGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices,
    const PlateauCarcassonne* const plateau, float taillePlateau) : PlateauGraphique(gestionTextures, gestionPolices, plateau, taillePlateau)
{
    float tailleTuile = taillePlateau / std::min(plateau_->getLongueur(), plateau->getHauteur());
    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            TuileCarcassonne* tuile = static_cast<TuileCarcassonne*>(plateau_->getTuile(i, j));
            tuilesGraphiques_[j][i] = new TuileCarcassonneGraphique{gestionTextures_, gestionPolices_, tuile, tailleTuile};
        }
    }
}