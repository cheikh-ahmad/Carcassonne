#ifndef DEF_TUILE_TRAX_HPP
#define DEF_TUILE_TRAX_HPP

#include "Tuile.hpp"
#include "Trax/BordTrax.hpp"

class TuileTrax : public Tuile<BordTypeTrax>
{
    private:
        bool recto_;
        BordTrax hautRecto_;
        BordTrax droiteRecto_;
        BordTrax basRecto_;
        BordTrax gaucheRecto_;
        BordTrax hautVerso_;
        BordTrax droiteVerso_;
        BordTrax basVerso_;
        BordTrax gaucheVerso_;


    public:
        TuileTrax(BordTrax hautRecto, BordTrax droiteRecto, BordTrax basRecto, BordTrax gaucheRecto,
                BordTrax hautVerso, BordTrax droiteVerso, BordTrax basVerso, BordTrax gaucheVerso);

        // Retourne la tuile de trax
        void retourne();

        bool estRecto() const;
};

#endif // DEF_TUILE_TRAX_HPP