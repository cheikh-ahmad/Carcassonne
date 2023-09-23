#include "Carcassonne/GraphiqueCarcassonne.hpp"

GraphiqueCarcassonne::GraphiqueCarcassonne(const std::vector<std::string>& nomsJoueurs) : Graphique<BordTypeCarcassonne>(new JeuCarcassonne(nomsJoueurs)) 
{
    // On charge les tuiles de Carcassonne.
    std::map<Textures, std::string> correspondanceTuile {
    {Textures::TuileCarcassonne1, ResConf::TUILE_CARCASSONNE_1}, {Textures::TuileCarcassonne2, ResConf::TUILE_CARCASSONNE_2},
    {Textures::TuileCarcassonne3, ResConf::TUILE_CARCASSONNE_3}, {Textures::TuileCarcassonne4, ResConf::TUILE_CARCASSONNE_4},
    {Textures::TuileCarcassonne5, ResConf::TUILE_CARCASSONNE_5}, {Textures::TuileCarcassonne6, ResConf::TUILE_CARCASSONNE_6},
    {Textures::TuileCarcassonne7, ResConf::TUILE_CARCASSONNE_7}, {Textures::TuileCarcassonne8, ResConf::TUILE_CARCASSONNE_8},
    {Textures::TuileCarcassonne9, ResConf::TUILE_CARCASSONNE_9}, {Textures::TuileCarcassonne10, ResConf::TUILE_CARCASSONNE_10},
    {Textures::TuileCarcassonne11, ResConf::TUILE_CARCASSONNE_11}, {Textures::TuileCarcassonne12, ResConf::TUILE_CARCASSONNE_12},
    {Textures::TuileCarcassonne13, ResConf::TUILE_CARCASSONNE_13}, {Textures::TuileCarcassonne14, ResConf::TUILE_CARCASSONNE_14},
    {Textures::TuileCarcassonne15, ResConf::TUILE_CARCASSONNE_15}, {Textures::TuileCarcassonne16, ResConf::TUILE_CARCASSONNE_16},
    {Textures::TuileCarcassonne17, ResConf::TUILE_CARCASSONNE_17}, {Textures::TuileCarcassonne18, ResConf::TUILE_CARCASSONNE_18},
    {Textures::TuileCarcassonne19, ResConf::TUILE_CARCASSONNE_19}, {Textures::TuileCarcassonne20, ResConf::TUILE_CARCASSONNE_20},
    {Textures::TuileCarcassonne21, ResConf::TUILE_CARCASSONNE_21}, {Textures::TuileCarcassonne22, ResConf::TUILE_CARCASSONNE_22},
    {Textures::TuileCarcassonne23, ResConf::TUILE_CARCASSONNE_23}, {Textures::TuileCarcassonne24, ResConf::TUILE_CARCASSONNE_24}};
    
    for(std::pair<Textures, std::string> corr: correspondanceTuile)
    {
        gestionTextures_->ajouteRessource(corr.first, corr.second);
        gestionTextures_->getRessource(corr.first)->setSmooth(true);
    }

    plateauGraphique_ = new PlateauCarcassonneGraphique{gestionTextures_, gestionPolices_, static_cast<PlateauCarcassonne*>(jeu_->getPlateau()), GraphConf::TAILLE_PLATEAU};
    panneauGraphique_ = new PanneauCarcassonneGraphique{gestionTextures_, gestionPolices_, static_cast<JeuCarcassonne*>(jeu_), GraphConf::TAILLE_PANNEAU_X, GraphConf::TAILLE_PANNEAU_Y};
    panneauGraphique_->setPosition(GraphConf::TAILLE_PLATEAU, 0);

}

GraphiqueCarcassonne::~GraphiqueCarcassonne()
{

}

void GraphiqueCarcassonne::gererClicGauche(const sf::Vector2f& posClic)
{
    float posX = posClic.x;
	float posY = posClic.y;
	float posPlateauX = plateauGraphique_->getPosition().x;
	float posPlateauY = plateauGraphique_->getPosition().y;
	if(posX > posPlateauX && posX < posPlateauX + GraphConf::TAILLE_PLATEAU &&
		posY > posPlateauY && posY < posPlateauY + GraphConf::TAILLE_PLATEAU)
	{
		// On soustrait la position de la souris par la position du plateau afin de prendre comme origine (0, 0)
		sf::Vector2<size_t> indice = plateauGraphique_->getIndiceTuile(posClic - plateauGraphique_->getPosition());
		jeu_->jouerTuile(indice.x, indice.y);
	}
}
