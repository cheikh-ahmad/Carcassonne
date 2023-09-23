#include "Domino/JeuDomino.hpp"

JeuDomino::JeuDomino(const std::vector<std::string>& nomsJoueurs) :  Jeu{nomsJoueurs, new PlateauDomino{PLATEAU_TAILLE_DOMINO, PLATEAU_TAILLE_DOMINO}}
{
    if(nomsJoueurs.size() > 4 || nomsJoueurs.size() < 2)
    {
        throw std::runtime_error("Un jeu de domino se joue entre 2 à 4 joueurs, impossible de créer un jeu avec " + 
            std::to_string(nomsJoueurs.size()) + " joueurs");
    }
    
    /* Génère un tas de tuile (une pioche) */
	pioche_.push_back(new TuileDomino{BordDomino({0, 0, 3}), BordDomino({0, 2, 3}), BordDomino({1,1,4}), BordDomino({2,0,4})});
    pioche_.push_back(new TuileDomino{BordDomino({0, 1, 3}), BordDomino({3,8,9}), BordDomino({9,9,9}), BordDomino({0,0,0})});
    pioche_.push_back(new TuileDomino{BordDomino({0, 2, 3}), BordDomino({0,0,0}), BordDomino({3,8,9}), BordDomino({1,1,4})});
    pioche_.push_back(new TuileDomino{BordDomino({9,9,9}), BordDomino({0,1,3}), BordDomino({0,0,3}), BordDomino({2,0,4})});
    pioche_.push_back(new TuileDomino{BordDomino({0,0,0}), BordDomino({0,0,0}), BordDomino({0,0,0}), BordDomino({0,0,0})});
    pioche_.push_back(new TuileDomino{BordDomino({0,0,0}), BordDomino({0,0,0}), BordDomino({0,0,0}), BordDomino({0,0,0})});
    pioche_.push_back(new TuileDomino{BordDomino({0,0,3}), BordDomino({0,1,3}), BordDomino({3,8,9}), BordDomino({2,0,4})});

}

JeuDomino::~JeuDomino()
{

}

void JeuDomino::initPlateau()
{   
    pioche();
    Jeu::poserTuile(plateau_->getLongueur() / 2, plateau_->getHauteur() / 2);
}

bool JeuDomino::aCoupForce()
{
    if(tuilePosee_)
        return false;
    
    // On teste toutes les possibilités pour poser notre tuile piochée. Si l'une d'entre elle est valide, alors le coup est forcé.
    for(size_t i = 0; i < plateau_->getLongueur(); ++i)
    {
        for(size_t j = 0; j < plateau_->getHauteur(); ++j)
        {
            // Ne pas oublier de regarder toutes les rotations possibles (modulo 4)
            for(size_t rot = 0; rot < 4; ++rot)
            {
                /* Note: Il y a un bug/fonctionnalité ici. On teste toutes les combinaisons possibles, en forçant les rotations, et si on se rend compte que
                pour une rotation donnée on peut poser la tuile piochée sur le plateau, on retourne vrai sans rétablir la rotation.
                On pourrait la rétablir, mais nous avons trouvé intéressant de laisser ce "bug" ici, en se disant que cela servira d'indication pour le joueur
                qui n'a pas vu qu'il pouvait poser une tuile en laissant la rotation de la tuile telle qu'il puisse la poser immédiatement 
                (si il donne un bon emplacement).
                */
                if(plateau_->peutPoser(i, j, tuilePiochee_))
                {
                    return true;
                }
                tuilePiochee_->rotationDroite();
            }
            
        }
    }

    return false;
}
 
void JeuDomino::compteScoreTour()
{

}