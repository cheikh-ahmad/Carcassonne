#ifndef DEF_BORD_CARCASSONNE_HPP
#define DEF_BORD_CARCASSONNE_HPP

#include <tuple>

enum class DecorCarcassonne
{
    Route,
    Carrefour,
    Ville,
    Abbaye, 
    Pre,
};

using BordTypeCarcassonne = std::tuple<DecorCarcassonne, DecorCarcassonne, DecorCarcassonne>;

using BordCarcassonne = Bord<BordTypeCarcassonne>;

#endif // DEF_BORD_CARCASSONNE_HPP