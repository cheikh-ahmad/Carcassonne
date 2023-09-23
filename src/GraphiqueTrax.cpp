#include "Trax/GraphiqueTrax.hpp"

GraphiqueTrax::GraphiqueTrax(const std::vector<std::string>& nomsJoueurs) : Graphique<BordTypeTrax>(new JeuTrax(nomsJoueurs)) 
{
    gestionTextures_->ajouteRessource(Textures::TuileTraxRecto, ResConf::TUILE_TRAX_RECTO);
    gestionTextures_->ajouteRessource(Textures::TuileTraxVerso, ResConf::TUILE_TRAX_VERSO);
    gestionTextures_->getRessource(Textures::TuileTraxRecto)->setSmooth(true);
    gestionTextures_->getRessource(Textures::TuileTraxVerso)->setSmooth(true);
    
    plateauGraphique_ = new PlateauTraxGraphique{gestionTextures_, gestionPolices_, static_cast<PlateauTrax*>(jeu_->getPlateau()), GraphConf::TAILLE_PLATEAU};
    panneauGraphique_ = new PanneauTraxGraphique{gestionTextures_, gestionPolices_, static_cast<JeuTrax*>(jeu_), GraphConf::TAILLE_PANNEAU_X, GraphConf::TAILLE_PANNEAU_Y};
    panneauGraphique_->setPosition(GraphConf::TAILLE_PLATEAU, 0);

}

GraphiqueTrax::~GraphiqueTrax()
{

}

void GraphiqueTrax::gererClicDroit(const sf::Vector2f&/* posClic*/)
{
    static_cast<JeuTrax*>(jeu_)->retourne();
}
