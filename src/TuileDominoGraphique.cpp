#include "Domino/TuileDominoGraphique.hpp"

TuileDominoGraphique::TuileDominoGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
	const TuileDomino* const domino, float tailleTuile) : 
	TuileGraphique<BordTypeDomino>{gestionTextures, gestionPolices, domino, tailleTuile},
	rectangles_{}, 
	police_{gestionPolices_->getRessource(Polices::Arial)}, 
	textes_{}
{
	/* Comme la longueur d'une tuile de domino est composé de 2 carrés de longueur dominoTaille, et de 3 rectangles de longueur dominoTaille / 2,
	alors on souhaite que dominoTaille * (2 + 3/2) = tailleTuile_, d'où le calcul :
	*/
	int dominoTaille = (tailleTuile * 2) / 7;
	int taillePolice = dominoTaille / 4;

	sf::Color grisFonce = sf::Color(90, 90, 90);
	sf::Color grisClair = sf::Color(180, 180, 180);

	float delta = dominoTaille / 2;
	// les 4 carrés dans les bords.
	for(size_t i = 0; i < 4; ++i)
	{
		rectangles_.push_back(sf::RectangleShape(sf::Vector2f(dominoTaille, dominoTaille)));
		rectangles_[i].setFillColor(grisFonce);
	}
	rectangles_[1].move(dominoTaille + delta * 3, 0);
	rectangles_[2].move(0, dominoTaille + delta * 3);
	rectangles_[3].move(dominoTaille + delta * 3, dominoTaille + delta * 3);

	// Les 6 rectangles verticaux.
	for(size_t i = 4; i < 10; ++i)
		rectangles_.push_back(sf::RectangleShape(sf::Vector2f(delta, dominoTaille)));

	// Les 6 rectangles horizontaux
	for(size_t i = 10; i < 16; ++i)
		rectangles_.push_back(sf::RectangleShape(sf::Vector2f(dominoTaille, delta)));
	
	// Placement des 6 rectangles verticaux.
	for(size_t i = 4; i < 7; ++i)
	{
		size_t recNumber = i - 4;
		rectangles_[i].move(dominoTaille + delta * recNumber, 0);
		rectangles_[i+3].move(dominoTaille + delta * recNumber, dominoTaille + delta * 3);
	}

	// Placement des 6 rectangles horizontaux.
	for(size_t i = 10; i < 13; ++i)
	{
		size_t recNumber = i - 10;
		rectangles_[i].move(0, dominoTaille + delta * recNumber);
		rectangles_[i+3].move(dominoTaille + delta * 3, dominoTaille + delta * recNumber);
	}

	// Carré central
	rectangles_.push_back(sf::RectangleShape(sf::Vector2f(delta * 3, delta * 3)));
	rectangles_[16].move(dominoTaille, dominoTaille);
	rectangles_[16].setFillColor(grisClair);

	// On réalise les grilles
	for(size_t i = 0; i < rectangles_.size(); ++i)
	{
		rectangles_[i].setOutlineColor(sf::Color::Black);
		rectangles_[i].setOutlineThickness(1);
	}


	// On initialise les textes
	for(size_t i = 0; i < 12; ++i)
	{
		size_t rectangleIndice = 4 + i;
		textes_.push_back(sf::Text());
		textes_[i].setCharacterSize(taillePolice);
		textes_[i].setFont(*police_);
		textes_[i].setFillColor(sf::Color::Black);

		// On change l'origine du texte, pour la mettre à son centre au lieu de son bord haut gauche.
		sf::FloatRect texteRect = textes_[i].getLocalBounds();
		textes_[i].setOrigin(texteRect.left + texteRect.width / 2.0f, texteRect.top + texteRect.height / 2.0f);
		
		// On met le chiffre au centre du rectangle correspondant dans le domino.
		textes_[i].setPosition(rectangles_[rectangleIndice].getPosition() + rectangles_[rectangleIndice].getSize() / 2.0f);
	}

	mettreAJour();
}

void TuileDominoGraphique::mettreAJour()
{
	if(tuile_ == nullptr)
		return;
	// On écrit les bons chiffres dans le domino
	BordDomino haut = tuile_->getBord(BordEnum::Haut);
	BordDomino droite = tuile_->getBord(BordEnum::Droite);
	BordDomino bas = tuile_->getBord(BordEnum::Bas);
	BordDomino gauche = tuile_->getBord(BordEnum::Gauche);
	
	
	for(size_t i = 0; i < 3; ++i)
	{
		textes_[i].setString(std::to_string(haut.get()[i]));
		textes_[i+3].setString(std::to_string(bas.get()[i]));
		textes_[i+6].setString(std::to_string(gauche.get()[i]));
		textes_[i+9].setString(std::to_string(droite.get()[i]));
	}
}

void TuileDominoGraphique::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	
	if(tuile_ == nullptr)
	{
		target.draw(tuileVide_, states);
	}
	else
	{
		// Dessine les rectangles
		for(const sf::RectangleShape& rect: rectangles_)
			target.draw(rect, states);

		for(const sf::Text& texte: textes_)
			target.draw(texte, states);
	}
}
