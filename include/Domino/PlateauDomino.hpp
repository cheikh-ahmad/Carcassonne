#ifndef DEF_PLATEAU_DOMINO_HPP
#define DEF_PLATEAU_DOMINO_HPP

#include "Plateau.hpp"
#include "Domino/BordDomino.hpp"

class PlateauDomino : public Plateau<BordTypeDomino>
{
    private:
		
	public:
		PlateauDomino(size_t longueur, size_t hauteur);
};
#endif // DEF_PLATEAU_DOMINO_HPP