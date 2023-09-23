template<typename BordType>
TuileGraphique<BordType>::TuileGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
    const Tuile<BordType>* const tuile, float tailleTuile) : tailleTuile_{tailleTuile}, tuile_{tuile}, 
    tuileVide_{sf::Vector2f{tailleTuile_, tailleTuile_}}, gestionTextures_{gestionTextures}, gestionPolices_{gestionPolices}
{
    tuileVide_.setOutlineThickness(1.f);
    tuileVide_.setOutlineColor(sf::Color::Black);
}


template<typename BordType>
void TuileGraphique<BordType>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(tuileVide_, states);
}

template<typename BordType>
void TuileGraphique<BordType>::mettreAJour()
{

}

template<typename BordType>
float TuileGraphique<BordType>::getTailleTuile() const
{
    return tailleTuile_;
}

template<typename BordType>
void TuileGraphique<BordType>::setTuile(const Tuile<BordType>* const tuile)
{
    tuile_ = tuile; 
}