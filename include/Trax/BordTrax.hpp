#ifndef DEF_BORD_TRAX_HPP
#define DEF_BORD_TRAX_HPP

#include "Bord.hpp"

enum class BordTypeTrax
{
    Blanc,
    Noir,
};

using BordTrax = Bord<BordTypeTrax>;

#endif // DEF_BORD_TRAX_HPP