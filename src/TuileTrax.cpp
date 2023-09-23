#include "Trax/TuileTrax.hpp"

TuileTrax::TuileTrax(BordTrax hautRecto, BordTrax droiteRecto, BordTrax basRecto, BordTrax gaucheRecto,
    BordTrax hautVerso, BordTrax droiteVerso, BordTrax basVerso, BordTrax gaucheVerso) :
    Tuile<BordTypeTrax>{hautRecto, droiteRecto, basRecto, gaucheRecto},
    recto_{true},
    hautRecto_{hautRecto},
    droiteRecto_{droiteRecto},
    basRecto_{basRecto},
    gaucheRecto_{gaucheRecto},
    hautVerso_{hautVerso},
    droiteVerso_{droiteVerso},
    basVerso_{basVerso},
    gaucheVerso_{gaucheVerso}
{

}

void TuileTrax::retourne()
{
    if(recto_)
    {
        haut_ = hautVerso_;
        droite_ = droiteVerso_;
        bas_ = basVerso_;
        gauche_ = gaucheVerso_;
    }
    else
    {
        haut_ = hautRecto_;
        droite_ = droiteRecto_;
        bas_ = basRecto_;
        gauche_ = gaucheRecto_;
    }

    recto_ = !recto_;

    // Quand on retourne, on perd les rotations, il faut donc les rétablir :
    for(int i = 0; i < rotation_; ++i)
    {        
        // rotation droite 
        echange(haut_, gauche_);
        echange(gauche_, bas_);
        echange(bas_, droite_);
    }

}

bool TuileTrax::estRecto() const
{
    return recto_;
}