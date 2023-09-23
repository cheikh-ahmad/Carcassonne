#ifndef DEF_GESTION_RESSOURCES_HPP
#define DEF_GESTION_RESSOURCES_HPP

#include <unordered_map>

template<typename Id, typename RessourceType>
class GestionRessources
{
    private:
        std::unordered_map<Id, RessourceType*> ressources_;

        // Charge une ressource, avec la SFML.
        RessourceType* chargeRessource(const std::string& cheminRessource);
    public:
        GestionRessources();

        ~GestionRessources();

        // Charge la ressource avec la méthode chargeRessource, et si le chargement est un succès, l'ajoute dans notre mappage.
        void ajouteRessource(Id id, const std::string& cheminRessource);

        RessourceType* getRessource(Id id) const;

};

#include "GestionRessources.tpp"

#endif // DEF_GESTION_RESSOURCES_HPP