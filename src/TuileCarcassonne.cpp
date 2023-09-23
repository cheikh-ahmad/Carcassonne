#include "Carcassonne/TuileCarcassonne.hpp"

TuileCarcassonne::TuileCarcassonne(TuileCarcassonneId tuileCarcassonneId, BordCarcassonne haut, BordCarcassonne droite,
    BordCarcassonne bas, BordCarcassonne gauche, DecorCarcassonne centre)
: Tuile<BordTypeCarcassonne>{haut, droite, bas, gauche}, 
    tuileCarcassonneId_{tuileCarcassonneId},
    centre_{centre}
{

}

DecorCarcassonne TuileCarcassonne::toDecorCarcassonne(const char& c)
{
    switch(c)
    {
        case 'p':
            return DecorCarcassonne::Pre;
            break;
        case 'v':
            return DecorCarcassonne::Ville;
            break;
        case 'c':
            return DecorCarcassonne::Carrefour;
            break;
        case 'a':
            return DecorCarcassonne::Abbaye;
            break;
        case 'r':
            return DecorCarcassonne::Route;
            break;
        default:
            throw std::runtime_error("Décor de carcassonne invalide : " + c);
            break;
    }
}

BordTypeCarcassonne TuileCarcassonne::fromStringToBordType(const std::string& str)
{
    if(str.length() != 3)
        throw std::runtime_error("Impossible de créer un bord type à partir de la chaine de caractère " + str);

    return std::make_tuple<DecorCarcassonne, DecorCarcassonne, DecorCarcassonne>(
        toDecorCarcassonne(str[0]), toDecorCarcassonne(str[1]), toDecorCarcassonne(str[2]));
    
}

TuileCarcassonneId TuileCarcassonne::getId() const
{
    return tuileCarcassonneId_;
}