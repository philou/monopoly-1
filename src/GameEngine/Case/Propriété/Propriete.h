/* 
 * File:   Propriété.h
 * Author: manu
 *
 * Created on 7 février 2013, 16:43
 */

#ifndef PROPRIETE_H
#define	PROPRIETE_H

#include "../Case.h"
#include "../../Participant/Joueur.h"
#include "Famille.h"

class Propriete : public Case
{
public:
    Propriete(Plateau *plateau, int numero, std::string libelle, int valeurHypotheque, int prixAchat, std::vector<int> prixLoyer, Famille *famille);
    ~Propriete();
    virtual void Agir(Joueur *joueur, BilletManager *billetManager); //redéfinit Agir de Case mais sera redéfini par Domaine, Gare et Service Publique
    virtual void Hypothequer();
    void LeverHypotheque();
    ACTION DoitPayer(Joueur *joueur);
    virtual int SommeAPayer() = 0;
    Joueur *GetProprietaire();
    virtual int GetValeurHypotheque();
    int GetValeurLeverHypotheque();
    std::string GetMessage();
    int GetPrixMaisons();
    bool PossedeFamilleEntiere(Joueur *joueur);
    bool Achetable();
    virtual bool PeutConstruire();
    bool EstHypotheque();
    
protected:
    Joueur *_proprietaire;
    bool _estHypotheque;
    int _valeurHypotheque;
    int _prixAchat;
    std::vector<int> _prixLoyer;
    Famille *_famille;

};

#endif	/* PROPRIETE_H */

