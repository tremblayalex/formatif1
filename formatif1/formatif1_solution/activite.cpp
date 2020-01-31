#include "activite.h"

Activite::Activite() :
	codeActivite(""),
	titre(""),
	responsable("")
{}

Activite::Activite(const string& inCodeActivite, const string& inTitre, const string& inResponsable) :
	codeActivite(inCodeActivite),
	titre(inTitre),
	responsable(inResponsable)
{}

void Activite::setCodeActivite(const string& inCodeActivite)
{
	codeActivite = inCodeActivite;
}

string Activite::getCodeActivite() const
{
	return codeActivite;
}

void Activite::setTitre(const string& inTitre)
{
	titre = inTitre;
}

const string& Activite::getTitre() const
{
	return titre;
}

void Activite::setResponsable(const string& inResponsable)
{
	responsable = inResponsable;
}

string Activite::getResponsable() const
{
	return responsable;
}

void Activite::InitialiserActivite(const string& inCodeActivite, const string& inTitre)
{
	codeActivite = inCodeActivite;
	titre = inTitre;
}

void Activite::AssignerResponsable(const string& inResponsable)
{
	responsable = inResponsable;
}