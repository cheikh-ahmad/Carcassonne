#include "Trax/JeuTrax.hpp"

JeuTrax::JeuTrax(const std::vector<std::string>& nomsJoueurs) :  Jeu{nomsJoueurs, new PlateauTrax{PLATEAU_TAILLE_TRAX, PLATEAU_TAILLE_TRAX}}
{
    if(nomsJoueurs.size() != 2)
    {
        throw std::runtime_error("Le jeu trax doit avoir 2 joueurs, impossible de créer un jeu avec " + 
            std::to_string(nomsJoueurs.size()) + " joueurs");
    }

    
    // On insère les 64 tuiles de trax.
    for(size_t i = 0; i < 64; ++i)
    {
        pioche_.push_back(new TuileTrax{BordTypeTrax::Noir, BordTypeTrax::Blanc, BordTypeTrax::Noir, BordTypeTrax::Blanc,
            BordTypeTrax::Blanc, BordTypeTrax::Blanc, BordTypeTrax::Noir, BordTypeTrax::Noir});
    }
}

JeuTrax::~JeuTrax()
{

}

void JeuTrax::initPlateau()
{   
    
}

bool JeuTrax::aCoupForce()
{
    return false;
}

void JeuTrax::retourne()
{
    static_cast<TuileTrax*>(tuilePiochee_)->retourne();
}