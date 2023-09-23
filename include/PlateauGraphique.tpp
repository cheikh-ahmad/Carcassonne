template<typename BordType>
PlateauGraphique<BordType>::PlateauGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
    const Plateau<BordType>* const plateau, size_t taillePlateau) : 
    rectangleMilieu_{},
    taillePlateau_{taillePlateau}, 
    plateau_{plateau},
    tuilesGraphiques_{plateau_->getHauteur(), std::vector<TuileGraphique<BordType>*>(plateau_->getLongueur(), nullptr)},
    gestionTextures_{gestionTextures}, gestionPolices_{gestionPolices}
{
    rectangleMilieu_.setOutlineColor(sf::Color::Red);
    rectangleMilieu_.setOutlineThickness(1);
}

template<typename BordType>
float PlateauGraphique<BordType>::getTailleTuile() const
{
    return taillePlateau_ / std::min(plateau_->getLongueur(), plateau_->getHauteur());
}

template<typename BordType>
sf::Vector2<size_t> PlateauGraphique<BordType>::getIndiceTuile(const sf::Vector2f posGraphique) const
{
    float tailleTuile = getTailleTuile();
    return sf::Vector2<size_t>(posGraphique.x / tailleTuile, posGraphique.y / tailleTuile);
}

template<typename BordType>
void PlateauGraphique<BordType>::mettreAJour()
{
    /* TODO : Redimensionnement.
    */
    
    // On calcule la taille de la tuile, qui va dépendre de la taille en pixel du plateau, et de sa hauteur/longueur.
    float tailleTuile = getTailleTuile();

    /*On met à jour toutes les tuiles, et on met à jour également le plateau, dans le cas où de nouvelle tuile on était ajoutée*/
    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            tuilesGraphiques_[j][i]->setTuile(plateau_->getTuile(i, j));

            tuilesGraphiques_[j][i]->mettreAJour();

            // Placement et gestion de la taille de la tuile sur le plateau.
            tuilesGraphiques_[j][i]->setPosition(i * tailleTuile, j * tailleTuile);
        }
    }

    rectangleMilieu_.setSize(sf::Vector2f(getTailleTuile(), getTailleTuile()));
    size_t posX = plateau_->getLongueur() / 2;
    size_t posY = plateau_->getHauteur() / 2;
    rectangleMilieu_.setPosition(posX * getTailleTuile(), posY * getTailleTuile());
    
}

template<typename BordType>
void PlateauGraphique<BordType>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            target.draw(*(tuilesGraphiques_[j][i]), states);
        }
    }

    size_t posX = plateau_->getLongueur() / 2;
    size_t posY = plateau_->getHauteur() / 2;
    // Si on a pas posé de tuile au milieu, on met un halo rouge autour de cette tuile, pour indiquer que la première tuile doit se poser là.
    if(plateau_->getTuile(posX, posY) == nullptr)
        target.draw(rectangleMilieu_, states);
}


template<typename BordType>
PlateauGraphique<BordType>::~PlateauGraphique()
{
    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            delete tuilesGraphiques_[j][i];
        }
    }


}