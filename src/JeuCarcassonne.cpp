#include "Carcassonne/JeuCarcassonne.hpp"
#include <fstream>
#include <tuple>

JeuCarcassonne::JeuCarcassonne(const std::vector<std::string>& nomsJoueurs) :  Jeu{nomsJoueurs, new PlateauCarcassonne{PLATEAU_TAILLE_CARCASSONNE, PLATEAU_TAILLE_CARCASSONNE}}
{
    if(nomsJoueurs.size() < 2 or nomsJoueurs.size() > 4)
    {
        throw std::runtime_error("Le jeu Carcassonne doit avoir entre 2 et 4 joueurs, impossible de créer un jeu avec " + 
            std::to_string(nomsJoueurs.size()) + " joueurs");
    }

    // On insère les tuiles de carcassonne (qui sont stockés dans TuileCarcassonne.data)
    // Exemple de la syntaxe : ppp:ppp:prp:prp:r:9 (les 4 bords: haut, droite, bas, gauche, puis la multiplicité de la tuile).
    // Les décors étant indiqués dans l'ordre des aiguilles d'une montre.
    std::ifstream fichier(ResConf::TUILE_CARCASSONNE_DATA, std::ios::in);
    if(!fichier.is_open())
        throw std::runtime_error("Impossible d'ouvrir le fichier de données " + ResConf::TUILE_CARCASSONNE_DATA);
    std::string ligne;
    std::string separateur = ":";

    int numeroTuile = 1;
    while(std::getline(fichier, ligne))
    {
        size_t pos = 0;
        std::string sousChaine;
        std::array<BordTypeCarcassonne, 4> bords;
        // On lit les 4 bords.
        for(size_t i = 0; i < 4; ++i)
        {
            pos = ligne.find(separateur);
            // Si on a pas trouvé de séparateur, il y a un problème dans le fichier de données.
            if(pos == std::string::npos)
                throw std::runtime_error("Ligne invalide dans le fichier de données " + ResConf::TUILE_CARCASSONNE_DATA + ", ligne : " + ligne);
            sousChaine = ligne.substr(0, pos);
            bords[i] = TuileCarcassonne::fromStringToBordType(sousChaine);
            ligne.erase(0, pos + separateur.length());
        }

        // On récupère le centre
        pos = ligne.find(separateur);
        if(pos == std::string::npos)
                throw std::runtime_error("Ligne invalide dans le fichier de données " + ResConf::TUILE_CARCASSONNE_DATA + ", ligne : " + ligne);
        sousChaine = ligne.substr(0, pos);
        if(sousChaine.length() != 1)
            throw std::runtime_error("Ligne invalide dans le fichier de données " + ResConf::TUILE_CARCASSONNE_DATA + ", ligne : " + ligne);
        DecorCarcassonne centre = TuileCarcassonne::toDecorCarcassonne(sousChaine[0]);
        ligne.erase(0, pos + separateur.length());

        int multiplicite = std::stoi(ligne);

        for(int i = 0; i < multiplicite; ++i)
        {
            pioche_.push_back(new TuileCarcassonne
                    ("TuileCarcassonne" + std::to_string(numeroTuile), bords[0], bords[1], bords[2], bords[3], centre));
        }

        ++numeroTuile;
    }
}
JeuCarcassonne::~JeuCarcassonne()
{

}


void JeuCarcassonne::initPlateau()
{   
    
}

bool JeuCarcassonne::aCoupForce()
{
    return false;
}