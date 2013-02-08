/* 
 * File:   Plateau.h
 * Author: manu
 *
 * Created on 7 février 2013, 16:34
 */

#ifndef PLATEAU_H
#define	PLATEAU_H

#include <cstdlib>
#include <vector>

class Case;
class Joueur;
class Carte;
class Cagnotte;
class Banque;
class Carte;

class Plateau
{
private :
	std::vector<Case*> _cases;
	std::vector<Joueur*> _joueurs;
	std::vector<Carte*> _cartes;
	Cagnotte *_cagnotte;
	Banque *_banque;
};

#endif	/* PLATEAU_H */
