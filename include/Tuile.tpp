template<typename BordType>
Tuile<BordType>::Tuile(Bord<BordType> haut, Bord<BordType> droite, Bord<BordType> bas, Bord<BordType> gauche) :
    haut_(haut), droite_(droite), bas_(bas), gauche_(gauche), rotation_{0}
{

}

template<typename BordType>
void Tuile<BordType>::echange(Bord<BordType>& a, Bord<BordType>& b)
{
    Bord<BordType> tmp = a;
    a = b;
    b = tmp;
}

template<typename BordType>
Bord<BordType> Tuile<BordType>::getBord(BordEnum bordE) const
{
    switch(bordE)
    {
        case BordEnum::Haut:
            return haut_;
        case BordEnum::Droite:
            return droite_;
        case BordEnum::Bas:
            return bas_;
        case BordEnum::Gauche:
            return gauche_;
    }

    return haut_;
}


template<typename BordType>
int Tuile<BordType>::getRotation() const
{
    return rotation_;
}

template<typename BordType>
void Tuile<BordType>::rotationDroite()
{
    echange(haut_, gauche_);
    echange(gauche_, bas_);
    echange(bas_, droite_);
    rotation_ = (rotation_ + 1) % 4;
}

template<typename BordType>
void Tuile<BordType>::rotationGauche()
{
    echange(haut_, droite_);
    echange(droite_, bas_);
    echange(bas_, gauche_);
    rotation_ -= 1;
    // On gère le cas du modulo négatif.
    if(rotation_ == -1)
        rotation_ = 3;
}