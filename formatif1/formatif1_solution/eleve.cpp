#include "eleve.h"
#include <conio.h>

Eleve::Eleve() :
	codeEleve(""),
	nom(""),
	prenom(""),
	activiteInscrite(NULL)
{}

Eleve::Eleve(const string& inCodeEleve, const string& inNom, const string& inPrenom):
	codeEleve(inCodeEleve),
	nom(inNom),
	prenom(inPrenom),
	activiteInscrite(NULL)
{
}

string Eleve::getCodeEleve() const
{
	return codeEleve;
}

string Eleve::getNom() const
{
	return nom;
}

string Eleve::getPrenom() const
{
	return prenom;
}

Activite* Eleve::getActivite() const
{
	return activiteInscrite;
}

void Eleve::InscrireEleve(const string& inCodeEleve, const string& inNom, const string& inPrenom)
{
	codeEleve = inCodeEleve;
	nom = inNom;
	prenom = inPrenom;
}

void Eleve::InscrireAUneActivite(Activite* inActivite)
{
	activiteInscrite = inActivite;
}
