#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;

class Activite
{
private:
	string codeActivite;
	string titre;
	string responsable;

public:
	Activite();
	Activite(const string& inCodeActivite, const string& inTitre, const string& inResponsable);

	void setCodeActivite(const string& inCodeActivite);
	string getCodeActivite() const;
	void setTitre(const string& inTitre);
	const string& getTitre() const;
	void setResponsable(const string& inResponsable);
	string getResponsable() const;

	void InitialiserActivite(const string& inCodeActivite, const string& inTitre);
	void AssignerResponsable(const string& inResponsable);
};

#endif