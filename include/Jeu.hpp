#ifndef DEF_JEU_HPP
#define DEF_JEU_HPP

#include "Joueur.hpp"
#include <stack>
#include "Plateau.hpp"
#include "Tuile.hpp"
#include <vector>

template<typename BordType>
class Jeu
{
	protected:
		size_t nbJoueurs_;
		std::vector<Joueur*> joueurs_;
		// Donne l'ordre des joueurs pour chaque tour. Sera généré aléatoirement. Contient une permutation de 0 à joueurs.size() - 1
		std::vector<size_t> ordreJeu_;
		// L'indice du joueur qui joue actuellement
		size_t joueurActuel_;

		// Ces deux membres représentent le paquet de tuile (pioche_), et l'ordre dans lequel on pioche les tuiles (ordrePioche_).
		// Ainsi ordrePioche_ est une permutation de 0 à pioche_.size()
		std::vector<Tuile<BordType>*> pioche_;
		std::vector<int> ordrePioche_;

		// Représente l'indice de la prochaine tuile à piochée.
		size_t indiceProchaineTuile_;

		// Variable contenant la dernière tuile piochée (avec la méthode pioche).
		Tuile<BordType>* tuilePiochee_;
		// Flag indiquant si la tuile piochée a été posé.
		bool tuilePosee_;

		Plateau<BordType>* plateau_;

		// Indique si la partie est terminée.
		bool finDePartie_;

		// Le nom du joueur gagnant.
		std::string gagnant_;

		void initPioche();

		bool poserTuile(size_t x, size_t y);

		// Initialise l'ordre des tours des joueurs
		void initOrdre();

		virtual void initPlateau();


		// Cette méthode vérifie si le joueur a un coup forcé, qui l'empêche de passer son tour.
		virtual bool aCoupForce();

		virtual void terminePartie();

	public:
		Jeu(const std::vector<std::string>& nomsJoueurs, Plateau<BordType>* const plateau);

		std::string getGagnant() const;

		size_t getNombreJoueurs() const;

		std::string getNomJoueur(size_t indice) const;

		int getScoreJoueur(size_t indice) const;

		std::string getNomJoueurActuel() const;

		// Méthode qui initialise l'ordre des joueurs, initialise le plateau s'il y a besoin, etc... Pose les fondations du jeu.
		void initJeu();

		// Méthode avec effet de bord. L'idée est que seul un Jeu peut modifier une tuile, ainsi on renvoie une constante, mais on indique à la classe
		// Jeu la dernière tuile piochée à l'aide du membre tuilePioche_. En piochant, on défausse l'ancienne tuile piochée (sauf si elle a été utilisée).
		const Tuile<BordType>* pioche();

		const Tuile<BordType>* getTuilePiochee() const;

		Plateau<BordType>* getPlateau() const;

		/* Méthodes qui agissent sur la tuile piochée. */
		void rotationDroite();

		void rotationGauche();

		// Compte les points après un tour de jeu.
		virtual void compteScoreTour();

		// Permet de terminer le tour du joueur, à condition qu'il n'y a pas de coup forcé.
		// Renvoie vrai si la fin de tour a été possible.
		bool finDeTour();

		// Joue (si c'est possible) la tuile piochée, passe le tour automatiquement s'il n'y a pas de coup forcé, et pioche.
		virtual void jouerTuile(size_t x, size_t y);

		bool partieEstTerminee() const;

		virtual ~Jeu();
};

#include "Jeu.tpp"

#endif // DEF_JEU_HPP