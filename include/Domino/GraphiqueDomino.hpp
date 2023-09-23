#ifndef DEF_GRAPHIQUE_DOMINO_HPP
#define DEF_GRAPHIQUE_DOMINO_HPP

#include "Graphique.hpp"
#include "Config.hpp"
#include "Domino/JeuDomino.hpp"
#include "Domino/PanneauDominoGraphique.hpp"
#include "Domino/PlateauDominoGraphique.hpp"

class GraphiqueDomino : public Graphique<BordTypeDomino>
{
	public:
		GraphiqueDomino(const std::vector<std::string>& nomsJoueurs);

		virtual ~GraphiqueDomino();
};

#endif // DEF_GRAPHIQUE_DOMINO_HPP
