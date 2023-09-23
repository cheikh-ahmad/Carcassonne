#ifndef DEF_JOUEUR_HPP
#define DEF_JOUEUR_HPP

#include <string>

class Joueur
{
	private:
		int score_;
		std::string nom_;
	public:
		Joueur(const std::string& nom);

		int getScore() const;

		std::string getNom() const;
};
#endif // DEF_JOUEUR_HPP
