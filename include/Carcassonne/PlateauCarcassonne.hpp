#ifndef PLATEAU_CARCASSONNE_HPP
#define PLATEAU_CARCASSONNE_HPP

#include "Plateau.hpp"
#include "Carcassonne/BordCarcassonne.hpp"

class PlateauCarcassonne : public Plateau<BordTypeCarcassonne>
{
    private:
		
	public:
		PlateauCarcassonne(size_t longueur, size_t hauteur);
};

#endif // PLATEAU_CARCASSONNE_HPP