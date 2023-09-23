template<typename BordType>
Bord<BordType>::Bord(BordType bord) : bord_{bord}
{

}

template<typename BordType>
BordType Bord<BordType>::get() const
{
    return bord_;
}

template<typename BordType>
bool operator==(const Bord<BordType>& bordA, const Bord<BordType>& bordB)
{
    return bordA.bord_== bordB.bord_;
}


template<typename BordType>
bool operator!=(const Bord<BordType>& bordA, const Bord<BordType>& bordB)
{
    return !(bordA == bordB);
}