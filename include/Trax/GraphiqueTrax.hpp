#ifndef DEF_GRAPHIQUE_TRAX_HPP
#define DEF_GRAPHIQUE_TRAX_HPP

#include "Graphique.hpp"
#include "Config.hpp"
#include "Trax/JeuTrax.hpp"
#include "Trax/PanneauTraxGraphique.hpp"
#include "Trax/PlateauTraxGraphique.hpp"

class GraphiqueTrax : public Graphique<BordTypeTrax>
{
	private:
		/*
		virtual void gererEvenements();

		virtual void mettreAJour();

		virtual void afficher();
		*/
        
        // Un clic droit retourne la tuile de trax.
        virtual void gererClicDroit(const sf::Vector2f&/* posClic*/);

	public:
		GraphiqueTrax(const std::vector<std::string>& nomsJoueurs);

		virtual ~GraphiqueTrax();
};
#endif // DEF_GRAPHIQUE_TRAX_HPP