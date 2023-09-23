#include <algorithm>
#include <cstdlib>
#include <ctime>

template<typename BordType>
Jeu<BordType>::Jeu(const std::vector<std::string>& nomsJoueurs, Plateau<BordType>* const plateau) : 
	nbJoueurs_{nomsJoueurs.size()},
	joueurs_{},
	ordreJeu_{}, 
	joueurActuel_{0},
	pioche_{}, 
	ordrePioche_{},
	indiceProchaineTuile_{0},
	tuilePiochee_{nullptr},
	tuilePosee_{false},
	plateau_{plateau}, 
	finDePartie_{false},
	gagnant_{}
{
    for(const std::string& nomJoueur: nomsJoueurs)
        joueurs_.push_back(new Joueur(nomJoueur));
}

template<typename BordType>
std::string Jeu<BordType>::getGagnant() const
{
	return gagnant_;
}

template<typename BordType>
size_t Jeu<BordType>::getNombreJoueurs() const
{
	return nbJoueurs_;
}
template<typename BordType>
std::string Jeu<BordType>::getNomJoueur(size_t indice) const
{
	if(indice >= getNombreJoueurs())
		throw std::runtime_error("Tentative d'accéder à un nom d'un joueur invalide, indice : " + std::to_string(indice));
	return joueurs_[indice]->getNom();
}

template<typename BordType>
int Jeu<BordType>::getScoreJoueur(size_t indice) const
{
	return joueurs_[indice]->getScore();
}

template<typename BordType>
std::string Jeu<BordType>::getNomJoueurActuel() const
{
	return getNomJoueur(joueurActuel_);
}

template<typename BordType>
Jeu<BordType>::~Jeu()
{
	// On delete le plateau
	delete plateau_;

	// On delete toutes les tuiles, qui sont toutes contenues dans pioche_	
	for(size_t i = 0; i < pioche_.size(); ++i)	
		delete pioche_[i];
	

	// On delete les joueurs.
	for(size_t i = 0; i < joueurs_.size(); ++i)
	{
		delete joueurs_[i];
	}
}

template<typename BordType>
void Jeu<BordType>::initPioche()
{
	for(size_t i = 0; i < pioche_.size(); ++i)
		ordrePioche_.push_back(i);
	// Préparer la graine avant d'appliquer un random_shuffle
	std::srand(std::time(0));
	std::random_shuffle(ordrePioche_.begin(), ordrePioche_.end());
}

template<typename BordType>
const Tuile<BordType>* Jeu<BordType>::pioche()
{
	if(indiceProchaineTuile_ >= pioche_.size())
	{
		tuilePiochee_ = nullptr;
		terminePartie();
	}
	else
	{
		tuilePiochee_ = pioche_[ordrePioche_[indiceProchaineTuile_]];
		indiceProchaineTuile_ += 1;
	}

	return tuilePiochee_;
}

template<typename BordType>
const Tuile<BordType>* Jeu<BordType>::getTuilePiochee() const
{
	return tuilePiochee_;
}

template<typename BordType>
void Jeu<BordType>::initOrdre()
{
	ordreJeu_.clear();
	// Génère aléatoirement l'ordre du jeu
	for(size_t i = 0; i < joueurs_.size(); ++i)
	{
		ordreJeu_.push_back(i);
	}
	
	std::random_shuffle(ordreJeu_.begin(), ordreJeu_.end());
}

template<typename BordType>
void Jeu<BordType>::initJeu()
{
	finDePartie_ = false;
	initPioche();
	initOrdre();
	initPlateau();
	pioche();
}

template<typename BordType>
void Jeu<BordType>::initPlateau()
{

}

template<typename BordType>
bool Jeu<BordType>::poserTuile(size_t x, size_t y)
{
	if(!partieEstTerminee() && plateau_->peutPoser(x, y, tuilePiochee_))
	{
		plateau_->poser(x, y, tuilePiochee_);
		tuilePosee_ = true;
		return true;
	}
	
	return false;
}

template<typename BordType>
bool Jeu<BordType>::aCoupForce()
{
	return false;
}

template<typename BordType>
void Jeu<BordType>::terminePartie()
{
	finDePartie_ = true;

	// Déterminer le gagnant
	int maxScore = joueurs_[0]->getScore();
	std::string gagnant = joueurs_[0]->getNom();
	for(size_t i = 1; i < nbJoueurs_; ++i)
	{
		if(joueurs_[i]->getScore() > maxScore)
		{
			maxScore = joueurs_[i]->getScore();
			gagnant = joueurs_[i]->getNom();
		}
	}
}


template<typename BordType>
Plateau<BordType>* Jeu<BordType>::getPlateau() const
{
	return plateau_;
}

template<typename BordType>
void Jeu<BordType>::rotationDroite()
{
	tuilePiochee_->rotationDroite();
}

template<typename BordType>
void Jeu<BordType>::rotationGauche()
{
	tuilePiochee_->rotationGauche();
}

template<typename BordType>
void Jeu<BordType>::compteScoreTour()
{

}

template<typename BordType>
bool Jeu<BordType>::finDeTour()
{
	if(aCoupForce() || partieEstTerminee())
		return false;
	
	// C'est au prochain joueur de jouer.
	joueurActuel_ = (joueurActuel_ + 1) % joueurs_.size();
	return true;
}

template<typename BordType>
void Jeu<BordType>::jouerTuile(size_t x, size_t y)
{
	if(partieEstTerminee())
		return;

	if(poserTuile(x, y))
	{
		compteScoreTour();

		if(!partieEstTerminee())
		{
			// Si on a posé la tuile, on tente de terminer le tour (sauf dans le cas où il y a un coup forcé).
			finDeTour();
		}
		
		pioche();
		
	}
}

template<typename BordType>
bool Jeu<BordType>::partieEstTerminee() const
{
	return finDePartie_;
}
