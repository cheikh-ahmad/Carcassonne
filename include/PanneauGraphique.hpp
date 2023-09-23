#ifndef DEF_PANNEAU_GRAPHIQUE_HPP
#define DEF_PANNEAU_GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include "TuileGraphique.hpp"
#include "Jeu.hpp"

/* Représente un panneau graphique, c'est à dire l'espace graphique à côté du plateau qui contiendra les informations de jeu,
comme par exemple le nom du joueur, le score, la tuile a jouer, etc... */
template<typename BordType>
class PanneauGraphique : public sf::Drawable, public sf::Transformable 
{
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        // Permet de simplifier la création d'un text.
        sf::Text creerTexte(const std::string& str, const sf::Color& couleur, unsigned int taillePolice = 0, bool centre = true);

        // Met l'origine d'un texte au centre.
        void centreOrigine(sf::Text& texte);

        float panneauTailleX_;

        float panneauTailleY_;

        size_t taillePolice_;
        
        const GestionTextures* const gestionTextures_;

        const GestionPolices* const gestionPolices_;

        const Jeu<BordType>* const jeu_;

        sf::Font* police_;

        sf::Text nomJeu_;

        sf::Text texteJoueurActuel_;

        std::vector<sf::Text> textesNomsJoueurs_;

        sf::Text texteTuilePiochee_;

        sf::Text messageVictoire_;

        std::vector<sf::Text> textesPointsJoueurs_;

        TuileGraphique<BordType>* tuilePiocheeGraphique_;

        
    public:
        PanneauGraphique(const GestionTextures* const gestionTextures, const GestionPolices* const gestionPolices, 
            const Jeu<BordType>* const jeu, float panneauTailleX, float panneauTailleY);

        ~PanneauGraphique();

        virtual void mettreAJour();

};

#include "PanneauGraphique.tpp"

#endif // DEF_PANNEAU_GRAPHIQUE_HPP
