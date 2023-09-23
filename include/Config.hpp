#ifndef DEF_CONFIG_HPP
#define DEF_CONFIG_HPP

#include <vector>
#include <SFML/Graphics.hpp>

// Mettre des tailles impairs, pour avoir un centre. On souhaite que la première tuile posée soit toujours au centre du plateau.
const size_t PLATEAU_TAILLE_DOMINO = 3;
const size_t PLATEAU_TAILLE_TRAX = 11;
const size_t PLATEAU_TAILLE_CARCASSONNE = 15;

namespace GraphConf
{
	// en px.
	const int TAILLE_PLATEAU = 1000;
	const int TAILLE_PANNEAU_X = 500;
	const int TAILLE_PANNEAU_Y = 1000;
}

namespace ResConf
{
	const std::string FONT_ARIAL = "res/font/arial.ttf";
	const std::string TUILE_TRAX_RECTO = "res/textures/TuileTraxRecto.png";
	const std::string TUILE_TRAX_VERSO = "res/textures/TuileTraxVerso.png";
	const std::string TUILE_CARCASSONNE_1 = "res/textures/TuileCarcassonne1.png";
	const std::string TUILE_CARCASSONNE_2 = "res/textures/TuileCarcassonne2.png";
	const std::string TUILE_CARCASSONNE_3 = "res/textures/TuileCarcassonne3.png";
	const std::string TUILE_CARCASSONNE_4 = "res/textures/TuileCarcassonne4.png";
	const std::string TUILE_CARCASSONNE_5 = "res/textures/TuileCarcassonne5.png";
	const std::string TUILE_CARCASSONNE_6 = "res/textures/TuileCarcassonne6.png";
	const std::string TUILE_CARCASSONNE_7 = "res/textures/TuileCarcassonne7.png";
	const std::string TUILE_CARCASSONNE_8 = "res/textures/TuileCarcassonne8.png";
	const std::string TUILE_CARCASSONNE_9 = "res/textures/TuileCarcassonne9.png";
	const std::string TUILE_CARCASSONNE_10 = "res/textures/TuileCarcassonne10.png";
	const std::string TUILE_CARCASSONNE_11 = "res/textures/TuileCarcassonne11.png";
	const std::string TUILE_CARCASSONNE_12 = "res/textures/TuileCarcassonne12.png";
	const std::string TUILE_CARCASSONNE_13 = "res/textures/TuileCarcassonne13.png";
	const std::string TUILE_CARCASSONNE_14 = "res/textures/TuileCarcassonne14.png";
	const std::string TUILE_CARCASSONNE_15 = "res/textures/TuileCarcassonne15.png";
	const std::string TUILE_CARCASSONNE_16 = "res/textures/TuileCarcassonne16.png";
	const std::string TUILE_CARCASSONNE_17 = "res/textures/TuileCarcassonne17.png";
	const std::string TUILE_CARCASSONNE_18 = "res/textures/TuileCarcassonne18.png";
	const std::string TUILE_CARCASSONNE_19 = "res/textures/TuileCarcassonne19.png";
	const std::string TUILE_CARCASSONNE_20 = "res/textures/TuileCarcassonne20.png";
	const std::string TUILE_CARCASSONNE_21 = "res/textures/TuileCarcassonne21.png";
	const std::string TUILE_CARCASSONNE_22 = "res/textures/TuileCarcassonne22.png";
	const std::string TUILE_CARCASSONNE_23 = "res/textures/TuileCarcassonne23.png";
	const std::string TUILE_CARCASSONNE_24 = "res/textures/TuileCarcassonne24.png";
	const std::string TUILE_CARCASSONNE_DATA = "res/TuileCarcassonne.data";



}


#endif // DEF_CONFIG_HPP