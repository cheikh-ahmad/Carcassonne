#ifndef DEF_RESSOURCES_ID_HPP
#define DEF_RESSOURCES_ID_HPP


enum class Textures
{
    TuileTraxRecto,
    TuileTraxVerso,
    TuileCarcassonne1,
    TuileCarcassonne2,
    TuileCarcassonne3,
    TuileCarcassonne4,
    TuileCarcassonne5,
    TuileCarcassonne6,
    TuileCarcassonne7,
    TuileCarcassonne8,
    TuileCarcassonne9,
    TuileCarcassonne10,
    TuileCarcassonne11,
    TuileCarcassonne12,
    TuileCarcassonne13,
    TuileCarcassonne14,
    TuileCarcassonne15,
    TuileCarcassonne16,
    TuileCarcassonne17,
    TuileCarcassonne18,
    TuileCarcassonne19,
    TuileCarcassonne20,
    TuileCarcassonne21,
    TuileCarcassonne22,
    TuileCarcassonne23,
    TuileCarcassonne24,
};

enum class Polices
{
    Arial
};

using GestionTextures = GestionRessources<Textures, sf::Texture>;
using GestionPolices = GestionRessources<Polices, sf::Font>;

#endif // DEF_RESSOURCES_ID_HPP