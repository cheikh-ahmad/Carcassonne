#include "Tuile.hpp"

BordEnum bordOppose(BordEnum bordE)
{
    switch(bordE)
    {
        case BordEnum::Haut:
            return BordEnum::Bas;
        case BordEnum::Droite:
            return BordEnum::Gauche;
        case BordEnum::Bas:
            return BordEnum::Haut;
        case BordEnum::Gauche:
            return BordEnum::Droite;
        default:
            return BordEnum::Bas;
    }
}