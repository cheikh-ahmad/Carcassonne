#include "Trax/TuileTraxGraphique.hpp"

TuileTraxGraphique::TuileTraxGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
	const TuileTrax* const Trax, float tailleTuile) : 
	TuileGraphique<BordTypeTrax>{gestionTextures, gestionPolices, Trax, tailleTuile},
    tuileSprite_{}
{
    mettreAJour();
}

void TuileTraxGraphique::mettreAJour()
{
	if(tuile_ == nullptr)
		return;
    
    // On choisi la texture recto ou verso suivant l'état de la tuile
    sf::Texture* texture;
    if(static_cast<const TuileTrax*>(tuile_)->estRecto())
        texture = gestionTextures_->getRessource(Textures::TuileTraxRecto);
    else
        texture = gestionTextures_->getRessource(Textures::TuileTraxVerso);
    
    tuileSprite_.setTexture(*texture);
    sf::Vector2f newScale = sf::Vector2f(tailleTuile_ / texture->getSize().x, tailleTuile_ / texture->getSize().y);
    tuileSprite_.setScale(newScale);

    // On gère la rotation de la tuile :
    tuileSprite_.setOrigin(static_cast<sf::Vector2f>(texture->getSize()) / 2.f);
    tuileSprite_.setPosition(tuileSprite_.getOrigin().x * newScale.x, tuileSprite_.getOrigin().y * newScale.y);
    tuileSprite_.setRotation(90 * tuile_->getRotation());
}

void TuileTraxGraphique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	
	if(tuile_ == nullptr)
	{
		target.draw(tuileVide_, states);
	}
    else
        target.draw(tuileSprite_, states);
}
