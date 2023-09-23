#include <stdexcept>

template<typename BordType>
Plateau<BordType>::Plateau(size_t longueur, size_t hauteur) : longueur_{longueur},
    hauteur_{hauteur}, plateau_(hauteur, std::vector<Tuile<BordType>*>(longueur, nullptr))
{

}

template<typename BordType>
Plateau<BordType>::~Plateau()
{
    
}

template<typename BordType>
bool Plateau<BordType>::estVide() const
{
    for(size_t i = 0; i < longueur_; ++i)
    {
        for(size_t j = 0; j < hauteur_; ++j)
        {
            if(plateau_[i][j] != nullptr)
                return false;
        }
    }

    return true;
}

template<typename BordType>
size_t Plateau<BordType>::getHauteur() const
{
	return hauteur_;
}


template<typename BordType>
size_t Plateau<BordType>::getLongueur() const
{
	return longueur_;
}

template<typename BordType>
Tuile<BordType>* Plateau<BordType>::getTuile(size_t x, size_t y) const
{  
    return plateau_[y][x];
}

template<typename BordType>
void Plateau<BordType>::redimensionner()
{
	/* TODO REDIMENSIONNEMENT */
}

template<typename BordType>
bool Plateau<BordType>::peutPoser(size_t x, size_t y, Tuile<BordType>* tuile)
{
    // On ne peut pas poser sur une tuile.
    if(getTuile(x, y) != nullptr)
        return false; 
    
    // Quand le plateau est vide, on peut poser une tuile au milieu du plateau.
    if(estVide() && x == getLongueur() / 2 && y == getHauteur() / 2)
        return true;
    
    std::array<std::pair<std::array<int, 2>, BordEnum>, 4> vecteurs {
        std::make_pair<std::array<int, 2>, BordEnum>({0, 1}, BordEnum::Bas),
        std::make_pair<std::array<int, 2>, BordEnum>({1, 0}, BordEnum::Droite),
        std::make_pair<std::array<int, 2>, BordEnum>({0, -1}, BordEnum::Haut),
        std::make_pair<std::array<int, 2>, BordEnum>({-1, 0}, BordEnum::Gauche)};
    
    int nombreAdjacents = 0;
    for(size_t i = 0; i < vecteurs.size(); ++i)
    {
        int dx = vecteurs[i].first[0];
        int dy = vecteurs[i].first[1];
        BordEnum bordA = vecteurs[i].second;
        BordEnum bordB = bordOppose(bordA);
        
        if(!((x == 0 && dx == -1) || (x == longueur_ - 1 && dx == 1) || 
            (y == 0 && dy == -1) || (y == hauteur_ - 1 && dy == 1)))
        {
            size_t adjX = x + dx;
            size_t adjY = y + dy;
            Tuile<BordType>* tuileAdj = getTuile(adjX, adjY);
            if(tuileAdj != nullptr)
            {
                // Si les bords adjacents sont différents, alors la position est invalide.
                if(tuile->getBord(bordA) != tuileAdj->getBord(bordB))
                    return false;
                nombreAdjacents += 1;
            }
        }
        
    }

    // On essaye de poser une tuile à côté d'aucune tuile.
    if(nombreAdjacents == 0)
        return false;

    return true;
}

template<typename BordType>
void Plateau<BordType>::poser(size_t x, size_t y, Tuile<BordType>* tuile)
{
	if(x > longueur_ || y > hauteur_)
		throw std::invalid_argument("Impossible de poser une tuile sur cette position sur le plateau.");

	// Si on pose sur les bords du plateau, on le redimensionne.
	if(x == longueur_ - 1 || y == hauteur_ - 1)
	{
		redimensionner();
	}

	plateau_[y][x] = tuile;
}
