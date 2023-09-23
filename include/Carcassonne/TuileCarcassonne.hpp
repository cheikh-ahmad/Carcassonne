#ifndef DEF_TUILE_CARCASSONNE_HPP 
#define DEF_TUILE_CARCASSONNE_HPP

#include "Tuile.hpp"
#include "Carcassonne/BordCarcassonne.hpp"

using TuileCarcassonneId = std::string;

class TuileCarcassonne : public Tuile<BordTypeCarcassonne>
{
    private:
        TuileCarcassonneId tuileCarcassonneId_;
        
        // Une tuile de carcassonne possède un centre.
        DecorCarcassonne centre_;

    public:
        TuileCarcassonne(TuileCarcassonneId tuileCarcassonneId, BordCarcassonne haut, BordCarcassonne droite, BordCarcassonne bas, BordCarcassonne gauche,
                        DecorCarcassonne centre);

        static DecorCarcassonne toDecorCarcassonne(const char& c);

        static BordTypeCarcassonne fromStringToBordType(const std::string& str);

        TuileCarcassonneId getId() const;
};

#endif // DEF_TUILE_CARCASSONNE_HPP