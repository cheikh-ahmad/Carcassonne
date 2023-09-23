#ifndef DEF_TUILE_DOMINO_HPP
#define DEF_TUILE_DOMINO_HPP

#include "Tuile.hpp"
#include "Domino/BordDomino.hpp"

class TuileDomino : public Tuile<BordTypeDomino>
{
    public:
        TuileDomino(BordDomino haut, BordDomino droite, BordDomino bas, BordDomino gauche);
};
#endif // DEF_TUILE_DOMINO_HPP