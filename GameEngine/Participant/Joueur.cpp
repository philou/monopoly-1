#include "Joueur.h"
#include "../Case/Case.h"
#include "../Case/Propriété/Propriete.h"

Joueur::Joueur() : Participant()
{
	_position = 0;
}

Joueur::~Joueur()
{
	for(int i = 0; i < _proprietes.size(); i++)
	{
		delete _proprietes[i];
	}

	_proprietes.clear();
}

void Joueur::Avancer(int valeur)
{
	_position += valeur;

	if(_position > 39)
	{
		GagnerArgentCaseDepart();
		_position -= 40;
	}
}

void Joueur::Acheter(Propriete *propriete)
{
	_proprietes.push_back(propriete);
	propriete->Acheter(this);
}

bool Joueur::PeutPayer(int somme)
{
	return _billetManager->PeutPayer(somme);
}

void Joueur::Construire(Propriete *propriete)
{

}

void Joueur::Detruire(Propriete *propriete)
{

}

void Joueur::Hypothequer(Propriete *propriete)
{
	BilletManager* billetManagerValHypotheque = new BilletManager(propriete->Hypothequer());
	_billetManager->Ajouter(billetManagerValHypotheque);
	delete billetManagerValHypotheque;
}

void Joueur::LeverHypotheque(Propriete *propriete, BilletManager* billetManager)
{
	_billetManager->Ajouter(billetManager);
	propriete->LeverHypotheque();
}

void Joueur::Placer(Case *caseAPlacer, bool passerParDepart)
{
	if(caseAPlacer->GetNumero() < _position && passerParDepart)
		GagnerArgentCaseDepart();

	_position = caseAPlacer->GetNumero();
}

void Joueur::InitialiserBillets()
{
	_billetManager->Ajouter(2, BILLET500);
	_billetManager->Ajouter(4, BILLET100);
	_billetManager->Ajouter(1, BILLET50);
	_billetManager->Ajouter(1, BILLET20);
	_billetManager->Ajouter(2, BILLET10);
	_billetManager->Ajouter(1, BILLET5);
	_billetManager->Ajouter(5, BILLET1);
}

int Joueur::GetPosition()
{
	return _position;
}

void Joueur::GagnerArgentCaseDepart()
{
	_billetManager->Ajouter(2, BILLET100);
}