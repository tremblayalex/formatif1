#ifndef EleveH 
#define EleveH

#include <string>
#include <iostream>
#include "activite.h"
using namespace std;

class Eleve
{
private:
	string codeEleve;
	string nom;
	string prenom;
	Activite* activiteInscrite;

public:
	Eleve();
	Eleve(const string& inCodeEleve, const string& inNom, const string& inPrenom);
	
	string getCodeEleve() const;
	string getNom() const;
	string getPrenom() const;
	Activite* getActivite() const;

	void InscrireEleve(const string& inCodeEleve, const string& inNom, const string& inPrenom);
	void InscrireAUneActivite(Activite* inActivite);
};

#endif

