#ifndef DEF_PLATEAU_HPP
#define DEF_PLATEAU_HPP

#include "Tuile.hpp"
#include <vector>
#include <array>

template<typename BordType>
class Plateau
{
    private:
        size_t longueur_;
        size_t hauteur_;
        std::vector<std::vector<Tuile<BordType>*>> plateau_;

        void redimensionner();

    public:
        Plateau(size_t longueur, size_t hauteur);

		~Plateau();

        bool estVide() const;

        /* Vérifie si on pose une tuile de telle sorte qu'elle soit adjacente à au moins une autre, et que les bords correspondent. */
        bool peutPoser(size_t x, size_t y, Tuile<BordType>* tuile);

		size_t getHauteur() const;

		size_t getLongueur() const;

        Tuile<BordType>* getTuile(size_t x, size_t y) const;

		void poser(size_t x, size_t y, Tuile<BordType>* tuile);
};

#include "Plateau.tpp"

#endif //DEF_PLATEAU_HPP