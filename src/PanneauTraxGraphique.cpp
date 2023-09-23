#include "Trax/PanneauTraxGraphique.hpp"

PanneauTraxGraphique::PanneauTraxGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
    const JeuTrax* const jeu, float panneauTailleX, float panneauTailleY) : 
    PanneauGraphique<BordTypeTrax>{gestionTextures, gestionPolices, jeu, panneauTailleX, panneauTailleY}
{
    tuilePiocheeGraphique_ = new TuileTraxGraphique{gestionTextures_, gestionPolices, static_cast<const TuileTrax*>(jeu_->getTuilePiochee()), panneauTailleX_ / 2};

    nomJeu_ = creerTexte("Jeu Trax", sf::Color::Black, 40 );

    float centre = panneauTailleX_ / 2;

    nomJeu_.setPosition(centre, 30);

    texteJoueurActuel_.setPosition(centre, 100);

    texteTuilePiochee_.setPosition(centre, 150);

    tuilePiocheeGraphique_->setPosition(centre / 2, 200);
    
    messageVictoire_.setPosition(10, panneauTailleY_ - 50);
    
    PanneauTraxGraphique::mettreAJour();
}

void PanneauTraxGraphique::mettreAJour()
{
    PanneauGraphique<BordTypeTrax>::mettreAJour();
}

void PanneauTraxGraphique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    PanneauGraphique<BordTypeTrax>::draw(target, states);
    
    states.transform *= getTransform();
}


