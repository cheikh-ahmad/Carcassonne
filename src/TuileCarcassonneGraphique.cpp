#include "Carcassonne/TuileCarcassonneGraphique.hpp"

TuileCarcassonneGraphique::TuileCarcassonneGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
	const TuileCarcassonne* const Carcassonne, float tailleTuile) : 
	TuileGraphique<BordTypeCarcassonne>{gestionTextures, gestionPolices, Carcassonne, tailleTuile},
    tuileSprite_{}
{
    mettreAJour();
}

Textures TuileCarcassonneGraphique::fromIdToTextures(const std::string& id)
{
	if(id == "TuileCarcassonne1") return Textures::TuileCarcassonne1;
	else if(id == "TuileCarcassonne2") return Textures::TuileCarcassonne2;
	else if(id == "TuileCarcassonne3") return Textures::TuileCarcassonne3;
	else if(id == "TuileCarcassonne4") return Textures::TuileCarcassonne4;
	else if(id == "TuileCarcassonne5") return Textures::TuileCarcassonne5;
	else if(id == "TuileCarcassonne6") return Textures::TuileCarcassonne6;
	else if(id == "TuileCarcassonne7") return Textures::TuileCarcassonne7;
	else if(id == "TuileCarcassonne8") return Textures::TuileCarcassonne8;
	else if(id == "TuileCarcassonne9") return Textures::TuileCarcassonne9;
	else if(id == "TuileCarcassonne10") return Textures::TuileCarcassonne10;
	else if(id == "TuileCarcassonne11") return Textures::TuileCarcassonne11;
	else if(id == "TuileCarcassonne12") return Textures::TuileCarcassonne12;
	else if(id == "TuileCarcassonne13") return Textures::TuileCarcassonne13;
	else if(id == "TuileCarcassonne14") return Textures::TuileCarcassonne14;
	else if(id == "TuileCarcassonne15") return Textures::TuileCarcassonne15;
	else if(id == "TuileCarcassonne16") return Textures::TuileCarcassonne16;
	else if(id == "TuileCarcassonne17") return Textures::TuileCarcassonne17;
	else if(id == "TuileCarcassonne18") return Textures::TuileCarcassonne18;
	else if(id == "TuileCarcassonne19") return Textures::TuileCarcassonne19;
	else if(id == "TuileCarcassonne20") return Textures::TuileCarcassonne20;
	else if(id == "TuileCarcassonne21") return Textures::TuileCarcassonne21;
	else if(id == "TuileCarcassonne22") return Textures::TuileCarcassonne22;
	else if(id == "TuileCarcassonne23") return Textures::TuileCarcassonne23;
	else if(id == "TuileCarcassonne24") return Textures::TuileCarcassonne24;
	else throw std::runtime_error("Mauvais id " + id + " pour une tentative de récupérer une ressource dans le carcassonne");
	
}

void TuileCarcassonneGraphique::mettreAJour()
{
	if(tuile_ == nullptr)
		return;
	std::string id = static_cast<const TuileCarcassonne*>(tuile_)->getId();
	sf::Texture* texture = gestionTextures_->getRessource(fromIdToTextures(id));
    tuileSprite_.setTexture(*texture);

	sf::Vector2f newScale = sf::Vector2f(tailleTuile_ / texture->getSize().x, tailleTuile_ / texture->getSize().y);
	tuileSprite_.setScale(newScale);

    // On gère la rotation de la tuile :
    tuileSprite_.setOrigin(static_cast<sf::Vector2f>(texture->getSize()) / 2.f);
    tuileSprite_.setPosition(tuileSprite_.getOrigin().x * newScale.x, tuileSprite_.getOrigin().y * newScale.y);
    tuileSprite_.setRotation(90 * tuile_->getRotation());
}

void TuileCarcassonneGraphique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	
	if(tuile_ == nullptr)
	{
		target.draw(tuileVide_, states);
	}
    else
        target.draw(tuileSprite_, states);
}
