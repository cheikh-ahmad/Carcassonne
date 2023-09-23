template<typename Id, typename RessourceType>
GestionRessources<Id, RessourceType>::GestionRessources() : ressources_{}
{

}

template<typename Id, typename RessourceType>
GestionRessources<Id, RessourceType>::~GestionRessources()
{
    for(std::pair<Id, RessourceType*> p: ressources_)
    {
        delete p.second;
    }
}

template<typename Id, typename RessourceType>
RessourceType* GestionRessources<Id, RessourceType>::chargeRessource(const std::string& cheminRessource)
{
    RessourceType* ressource = new RessourceType{};
    if (!ressource->loadFromFile(cheminRessource))
		throw std::runtime_error("Impossible de charger la ressource" + cheminRessource);
    return ressource;
}

template<typename Id, typename RessourceType>
void GestionRessources<Id, RessourceType>::ajouteRessource(Id id, const std::string& cheminRessource)
{
    // D'abord on vérifie si la ressource que l'on souhaite ajouter n'existe pas déjà dans notre gestionnaire de ressource.
    // Note : https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
    typename std::unordered_map<Id, RessourceType*>::iterator it = ressources_.find(id);
    if(it != ressources_.end())
        throw std::runtime_error("Impossible de charger une ressource qui existe déjà. Chemin de la ressource : " + cheminRessource);

    // On essaye de charger la ressource
    RessourceType* ressource = chargeRessource(cheminRessource);

    // Si la ressource a bien été chargée (pas d'exception levée), on l'associe à l'id.
    ressources_.insert(std::make_pair(id, ressource));
}

template<typename Id, typename RessourceType>
RessourceType* GestionRessources<Id, RessourceType>::getRessource(Id id) const
{
    // On déclare un const_iterator car comme la méthode est constante, il faut assurer le compilateur que l'on ne puisse pas modifier le unordered_map 
    // à travers l'itérateur.
    typename std::unordered_map<Id, RessourceType*>::const_iterator it = ressources_.find(id);
    if(it == ressources_.end())
        throw std::runtime_error("Impossible de trouver la ressource " + static_cast<int>(id));
    else
        return it->second;

}