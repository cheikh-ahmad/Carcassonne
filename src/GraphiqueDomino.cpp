#include "Domino/GraphiqueDomino.hpp"

GraphiqueDomino::GraphiqueDomino(const std::vector<std::string>& nomsJoueurs) : Graphique<BordTypeDomino>(new JeuDomino(nomsJoueurs)) 
{
    plateauGraphique_ = new PlateauDominoGraphique{gestionTextures_, gestionPolices_, static_cast<PlateauDomino*>(jeu_->getPlateau()), GraphConf::TAILLE_PLATEAU};
    panneauGraphique_ = new PanneauDominoGraphique{gestionTextures_, gestionPolices_, static_cast<JeuDomino*>(jeu_), GraphConf::TAILLE_PANNEAU_X, GraphConf::TAILLE_PANNEAU_Y};
    panneauGraphique_->setPosition(GraphConf::TAILLE_PLATEAU, 0);
}

GraphiqueDomino::~GraphiqueDomino()
{

}
