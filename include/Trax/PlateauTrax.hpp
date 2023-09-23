#ifndef DEF_PLATEAU_TRAX_HPP
#define DEF_PLATEAU_TRAX_HPP

#include "Plateau.hpp"
#include "Trax/BordTrax.hpp"

class PlateauTrax : public Plateau<BordTypeTrax>
{
    private:
		
	public:
		PlateauTrax(size_t longueur, size_t hauteur);
};

#endif // DEF_PLATEAU_TRAX_HPP