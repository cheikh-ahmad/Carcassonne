template<typename BordType>
PanneauGraphique<BordType>::PanneauGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
    const Jeu<BordType>* const jeu, float panneauTailleX, float panneauTailleY) : 
    panneauTailleX_{panneauTailleX},
    panneauTailleY_{panneauTailleY},
    taillePolice_{20},
    gestionTextures_{gestionTextures},
    gestionPolices_{gestionPolices}, 
    jeu_{jeu},
    police_{gestionPolices_->getRessource(Polices::Arial)},
    nomJeu_{},
    texteJoueurActuel_{},
    textesNomsJoueurs_{jeu_->getNombreJoueurs(), sf::Text{}},
    texteTuilePiochee_{},
    messageVictoire_{},
    textesPointsJoueurs_{jeu_->getNombreJoueurs(), sf::Text{}}
{
    texteTuilePiochee_ = creerTexte("Tuile piochee", sf::Color::Black);
    texteJoueurActuel_ = creerTexte("", sf::Color::Black);
}
template<typename BordType>
PanneauGraphique<BordType>::~PanneauGraphique()
{
    delete tuilePiocheeGraphique_;
}

template<typename BordType>
sf::Text PanneauGraphique<BordType>::creerTexte(const std::string& str, const sf::Color& couleur, unsigned int taillePolice /* = 0*/, bool centre /* = true*/)
{
    if(taillePolice == 0)
        taillePolice = taillePolice_;
    sf::Text text;
    text.setString(str);
    text.setFont(*police_);
    text.setFillColor(couleur);
    text.setCharacterSize(taillePolice);
    if(centre)
        centreOrigine(text);
    return text;
}

template<typename BordType>
void PanneauGraphique<BordType>::centreOrigine(sf::Text& texte)
{
    sf::FloatRect texteRect = texte.getLocalBounds();
    texte.setOrigin(texteRect.left + texteRect.width / 2.0f, texteRect.top + texteRect.height / 2.0f);
}

template<typename BordType>
void PanneauGraphique<BordType>::mettreAJour()
{
    tuilePiocheeGraphique_->setTuile(jeu_->getTuilePiochee());
    tuilePiocheeGraphique_->mettreAJour();

    texteJoueurActuel_.setString("Au tour de " + jeu_->getNomJoueurActuel());
    centreOrigine(texteJoueurActuel_);

    if(jeu_->partieEstTerminee())
        messageVictoire_ = creerTexte("Le gagnant est " + jeu_->getGagnant(), sf::Color::Red, 30, false);
}

template<typename BordType>
void PanneauGraphique<BordType>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(nomJeu_, states);
    target.draw(texteJoueurActuel_, states);
    target.draw(messageVictoire_, states);
    target.draw(texteTuilePiochee_, states);
    target.draw(*tuilePiocheeGraphique_, states);
    for(size_t i = 0; i < jeu_->getNombreJoueurs(); ++i)
    {
        target.draw(textesNomsJoueurs_[i], states);
        target.draw(textesPointsJoueurs_[i], states);
    }   
}


