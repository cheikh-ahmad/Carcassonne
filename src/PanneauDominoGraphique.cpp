#include "Domino/PanneauDominoGraphique.hpp"

PanneauDominoGraphique::PanneauDominoGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
    const JeuDomino* const jeu, float panneauTailleX, float panneauTailleY) : 
    PanneauGraphique<BordTypeDomino>{gestionTextures, gestionPolices, jeu, panneauTailleX, panneauTailleY}
    
{
    tuilePiocheeGraphique_ = new TuileDominoGraphique{gestionTextures_, gestionPolices, static_cast<const TuileDomino*>(jeu_->getTuilePiochee()), panneauTailleX_ / 2};

    nomJeu_ = creerTexte("Jeu Domino", sf::Color::Black, 40 );

    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
    {
        textesNomsJoueurs_[i] = creerTexte(jeu_->getNomJoueur(i), sf::Color::Black);
        textesPointsJoueurs_[i] = creerTexte("", sf::Color::Black);
    }

    float centre = panneauTailleX_ / 2;

    nomJeu_.setPosition(centre, 30);

    texteJoueurActuel_.setPosition(centre, 100);

    texteTuilePiochee_.setPosition(centre, 150);

    tuilePiocheeGraphique_->setPosition(centre / 2, 200);

    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
        textesNomsJoueurs_[i].setPosition(centre, 200 + tuilePiocheeGraphique_->getTailleTuile() + 50 * (i+1));
    
    messageVictoire_.setPosition(10, panneauTailleY_ - 50);
    
    PanneauDominoGraphique::mettreAJour();
}
void PanneauDominoGraphique::mettreAJour()
{
    // On met le panneau à jour (tuiles, etc...)
    PanneauGraphique<BordTypeDomino>::mettreAJour();


    // On met également à jour les scores des joueurs.
    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
    {
        textesPointsJoueurs_[i].setString(std::to_string(jeu_->getScoreJoueur(i)) + " pts");
        centreOrigine(textesPointsJoueurs_[i]);
        textesPointsJoueurs_[i].setPosition(textesNomsJoueurs_[i].getPosition() + sf::Vector2f{40, 0});
    }
}

void PanneauDominoGraphique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    PanneauGraphique<BordTypeDomino>::draw(target, states);
    states.transform *= getTransform();
}


