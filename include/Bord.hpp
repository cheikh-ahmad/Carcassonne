#ifndef DEF_BORD_HPP
#define DEF_BORD_HPP

template<typename BordType>
class Bord;

/* Défini dans le .tpp, pour qu'il fonctionne, il faut rédéfinir (si besoin) l'opérateur == de BordType. */

template<typename BordType>
bool operator==(const Bord<BordType>& bordA, const Bord<BordType>& bordB);

/* Cette classe va représenter ce qu'on appelle un bord d'une tuile. Une tuile aura donc 4 bords : un bord gauche, droit, haut, et bas.
L'idée est de pouvoir simplifier ensuite la programmation d'un jeu en remarquant que les jeux de plateau que l'on souhaite coder ont tous la même particularité :
pour poser une tuile à côté d'une autre, il faut que les bords soient identiques. C'est pourquoi nous allons définir l'opérateur == en spécialisant à travers les templates.
*/
template<typename BordType>
class Bord
{
    private:
        BordType bord_;

        friend bool operator== <BordType>(const Bord<BordType>& bordA, const Bord<BordType>& bordB);
    public:
        Bord(BordType bord);

        BordType get() const;

    
};

#include "Bord.tpp"

#endif // DEF_BORD_HPP