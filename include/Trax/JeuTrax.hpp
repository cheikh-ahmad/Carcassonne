#ifndef DEF_JEU_TRAX_HPP
#define DEF_JEU_TRAX_HPP

#include "Jeu.hpp"
#include "Config.hpp"
#include "Trax/TuileTrax.hpp"
#include "Trax/PlateauTrax.hpp"

class JeuTrax : public Jeu<BordTypeTrax>
{
    private:
        // Dans un jeu Trax, il n'y a rien à faire lors de l'initialisation du plateau.
        virtual void initPlateau();

        virtual bool aCoupForce();
    public:
        JeuTrax(const std::vector<std::string>& nomsJoueurs);

        virtual ~JeuTrax();
        
        // Retourne la tuile de trax piochée
        void retourne(); 
};

#endif // DEF_JEU_TRAX_HPP