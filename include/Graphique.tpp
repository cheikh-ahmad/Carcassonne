template<typename BordType>
Graphique<BordType>::Graphique(Jeu<BordType>* const jeu) : jeu_{jeu}, 
	window_{sf::VideoMode(GraphConf::TAILLE_PLATEAU + GraphConf::TAILLE_PANNEAU_X, GraphConf::TAILLE_PLATEAU),
		"Projet Carcassonne"}, 
	gestionTextures_{new GestionRessources<Textures, sf::Texture>{}}, 
	gestionPolices_{new GestionRessources<Polices, sf::Font>{}}
{
	gestionPolices_->ajouteRessource(Polices::Arial, ResConf::FONT_ARIAL);
    jeu_->initJeu();
}

template<typename BordType>
Graphique<BordType>::~Graphique()
{
	delete gestionPolices_;
	delete gestionTextures_;
	delete plateauGraphique_;
	delete panneauGraphique_;
    delete jeu_;
}

template<typename BordType>
void Graphique<BordType>::lancer()
{
	while(window_.isOpen())
	{
		gererEvenements();
		mettreAJour();
		afficher();
	}
}

template<typename BordType>
void Graphique<BordType>::gererEvenements()
{
	sf::Event evenement;
	while(window_.pollEvent(evenement))
	{
		switch(evenement.type)
		{
			case sf::Event::Closed:
			{
				window_.close();
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				float posClicX = evenement.mouseButton.x;
				float posClicY = evenement.mouseButton.y;
				if(evenement.mouseButton.button == sf::Mouse::Left)
					gererClicGauche(sf::Vector2f{posClicX, posClicY});
				else if(evenement.mouseButton.button == sf::Mouse::Right)
					gererClicDroit(sf::Vector2f{posClicX, posClicY});
				break;
			}
			case sf::Event::KeyReleased:
			{
				if(evenement.key.code == sf::Keyboard::Left)
					gererFlecheGauche();
				else if(evenement.key.code == sf::Keyboard::Right)
					gererFlecheDroite();
				else if(evenement.key.code == sf::Keyboard::Space)
					gererEspace();
				break;
			}
			default:
				break;
		}
	}
}

template<typename BordType>
void Graphique<BordType>::mettreAJour()
{
	plateauGraphique_->mettreAJour();
	panneauGraphique_->mettreAJour();
}

template<typename BordType>
void Graphique<BordType>::afficher()
{
	window_.clear(sf::Color::White);
	window_.draw(*plateauGraphique_);
	window_.draw(*panneauGraphique_);
	window_.display();
}

template<typename BordType>
void Graphique<BordType>::gererClicDroit(const sf::Vector2f&/* posClic)*/)
{

}

template<typename BordType>
void Graphique<BordType>::gererClicGauche(const sf::Vector2f& posClic)
{
	float posX = posClic.x;
	float posY = posClic.y;
	float posPlateauX = plateauGraphique_->getPosition().x;
	float posPlateauY = plateauGraphique_->getPosition().y;
	if(posX > posPlateauX && posX < posPlateauX + GraphConf::TAILLE_PLATEAU &&
		posY > posPlateauY && posY < posPlateauY + GraphConf::TAILLE_PLATEAU)
	{
		// On soustrait la position de la souris par la position du plateau afin de prendre comme origine (0, 0)
		sf::Vector2<size_t> indice = plateauGraphique_->getIndiceTuile(posClic - plateauGraphique_->getPosition());
		jeu_->jouerTuile(indice.x, indice.y);
	}
}

template<typename BordType>
void Graphique<BordType>::gererFlecheGauche()
{
	jeu_->rotationGauche();
}

template<typename BordType>
void Graphique<BordType>::gererFlecheDroite()
{
	jeu_->rotationDroite();
}

template<typename BordType>
void Graphique<BordType>::gererEspace()
{
	// Si la fin de tour a été possible, on pioche une nouvelle carte et on se prépare au prochain tour.
	if(jeu_->finDeTour())
		jeu_->pioche();
}