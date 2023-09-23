#ifndef DEF_JEU_CARCASSONNE_HPP
#define DEF_JEU_CARCASSONNE_HPP

#include "Jeu.hpp"
#include "Config.hpp"
#include "Carcassonne/TuileCarcassonne.hpp"
#include "Carcassonne/PlateauCarcassonne.hpp"

class JeuCarcassonne : public Jeu<BordTypeCarcassonne>
{
    private:
        // Dans un jeu Carcassonne, il n'y a rien à faire lors de l'initialisation du plateau.
        virtual void initPlateau();

        virtual bool aCoupForce();
    public:
        JeuCarcassonne(const std::vector<std::string>& nomsJoueurs);

        virtual ~JeuCarcassonne();
};


#endif // DEF_JEU_CARCASSONNE_HPP