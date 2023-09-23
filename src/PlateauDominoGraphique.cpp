#include "Domino/PlateauDominoGraphique.hpp"

PlateauDominoGraphique::PlateauDominoGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices,
    const PlateauDomino* const plateau, float taillePlateau) : PlateauGraphique(gestionTextures, gestionPolices, plateau, taillePlateau)
{
    float tailleTuile = taillePlateau / std::min(plateau_->getLongueur(), plateau->getHauteur());
    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            TuileDomino* tuile = static_cast<TuileDomino*>(plateau_->getTuile(i, j));
            tuilesGraphiques_[j][i] = new TuileDominoGraphique{gestionTextures_, gestionPolices_, tuile, tailleTuile};
        }
    }
}