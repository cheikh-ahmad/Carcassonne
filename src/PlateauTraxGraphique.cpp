#include "Trax/PlateauTraxGraphique.hpp"

PlateauTraxGraphique::PlateauTraxGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices,
    const PlateauTrax* const plateau, float taillePlateau) : PlateauGraphique(gestionTextures, gestionPolices, plateau, taillePlateau)
{
    float tailleTuile = taillePlateau / std::min(plateau_->getLongueur(), plateau->getHauteur());
    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            TuileTrax* tuile = static_cast<TuileTrax*>(plateau_->getTuile(i, j));
            tuilesGraphiques_[j][i] = new TuileTraxGraphique{gestionTextures_, gestionPolices_, tuile, tailleTuile};
        }
    }
}