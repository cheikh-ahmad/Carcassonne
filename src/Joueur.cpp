#include "Joueur.hpp"

Joueur::Joueur(const std::string& nom) : score_{0}, nom_(nom)
{

}

int Joueur::getScore() const
{
	return score_;
}

std::string Joueur::getNom() const
{
	return nom_;
}