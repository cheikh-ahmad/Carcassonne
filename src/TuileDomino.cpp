#include "Domino/TuileDomino.hpp"

TuileDomino::TuileDomino(BordDomino haut, BordDomino droite, BordDomino bas, BordDomino gauche) : Tuile<BordTypeDomino>{haut, droite, bas, gauche}
{

}