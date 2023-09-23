#include "Carcassonne/PanneauCarcassonneGraphique.hpp"

PanneauCarcassonneGraphique::PanneauCarcassonneGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
    const JeuCarcassonne* const jeu, float panneauTailleX, float panneauTailleY) : 
    PanneauGraphique<BordTypeCarcassonne>{gestionTextures, gestionPolices, jeu, panneauTailleX, panneauTailleY}
{
    tuilePiocheeGraphique_ = new TuileCarcassonneGraphique{gestionTextures_, gestionPolices, static_cast<const TuileCarcassonne*>(jeu_->getTuilePiochee()), 
        panneauTailleX_ / 2};

    nomJeu_ = creerTexte("Jeu Carcassonne", sf::Color::Black, 40 );

    float centre = panneauTailleX_ / 2;

    nomJeu_.setPosition(centre, 30);

    texteJoueurActuel_.setPosition(centre, 100);

    texteTuilePiochee_.setPosition(centre, 150);

    tuilePiocheeGraphique_->setPosition(centre / 2, 200);

    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
    {
        textesNomsJoueurs_[i] = creerTexte(jeu_->getNomJoueur(i), sf::Color::Black, false);
        textesPointsJoueurs_[i] = creerTexte("", sf::Color::Black);
    }

    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
        textesNomsJoueurs_[i].setPosition(centre, 200 + tuilePiocheeGraphique_->getTailleTuile() + 50 * (i+1));
    
    messageVictoire_.setPosition(10, panneauTailleY_ - 50);
    
    PanneauCarcassonneGraphique::mettreAJour();
}

void PanneauCarcassonneGraphique::mettreAJour()
{
    PanneauGraphique<BordTypeCarcassonne>::mettreAJour();

    // On met également à jour les scores des joueurs.
    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
    {
        textesPointsJoueurs_[i].setString(std::to_string(jeu_->getScoreJoueur(i)) + " pts");
        centreOrigine(textesPointsJoueurs_[i]);
        textesPointsJoueurs_[i].setPosition(textesNomsJoueurs_[i].getPosition() + sf::Vector2f{40, 0});
    }
}

void PanneauCarcassonneGraphique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    PanneauGraphique<BordTypeCarcassonne>::draw(target, states);
    
    states.transform *= getTransform();
}


