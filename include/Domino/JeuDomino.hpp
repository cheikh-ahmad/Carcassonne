#ifndef DEF_JEU_DOMINO_HPP
#define DEF_JEU_DOMINO_HPP

#include "Jeu.hpp"
#include "Config.hpp"
#include "Domino/TuileDomino.hpp"
#include "Domino/PlateauDomino.hpp"

class JeuDomino : public Jeu<BordTypeDomino>
{
    private:
        // Dans un jeu de domino, on place un premier domino au centre du plateau.
        virtual void initPlateau();

        // Dans un JeuDomino, un coup forcé est lorsqu'un joueur peut poser une tuile quelque part sur le plateau, i.e d'après les règles,
        // si le joueur peut jouer, alors il doit jouer.
        virtual bool aCoupForce();

        virtual void compteScoreTour();
    public:

        JeuDomino(const std::vector<std::string>& nomsJoueurs);

        virtual ~JeuDomino();
};
#endif // DEF_JEU_DOMINO_HPP