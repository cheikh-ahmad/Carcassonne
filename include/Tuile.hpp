#ifndef DEF_TUILE_HPP
#define DEF_TUILE_HPP

#include "Bord.hpp"

enum class BordEnum
{
    Haut,
    Droite,
    Bas,
    Gauche,
};

BordEnum bordOppose(BordEnum bordE);

template<typename BordType>
class Tuile
{
    protected:
        Bord<BordType> haut_;
        Bord<BordType> droite_;
        Bord<BordType> bas_;
        Bord<BordType> gauche_;

        // Spécifie la rotation de la tuile, modulo 4. Les valeurs possibles : {0, 1, 2, 3}.
        // 0 indiquant aucune rotation, 1 indiquant une rotation vers la droite.
        int rotation_;

        void echange(Bord<BordType>& a, Bord<BordType>& b);


    public:
        Tuile(Bord<BordType> haut, Bord<BordType> droite, Bord<BordType> bas, Bord<BordType> gauche);

        Bord<BordType> getBord(BordEnum bordE) const;

        int getRotation() const;

		void rotationDroite();

		void rotationGauche();

};

#include "Tuile.tpp"

#endif // DEF_TUILE_HPP