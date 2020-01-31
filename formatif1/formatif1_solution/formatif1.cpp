#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "activite.h" 
#include "eleve.h" 

const int maxActivites = 10;
const int maxEleves = 25;

Activite lesActivites[maxActivites];
Eleve lesEleves[maxEleves];

int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void AfficherLesActivites();
void Afficher(const Activite& inActivite);
void AfficherValeurAvecEspaceAjuste(const string& inValeur, const int& inEspaceTotal);

//partie 2
void AjouterLesEleves();
void Afficher(Eleve inEleve);
void AfficherLesEleves();
void InscrireUnEleve(string inCode, string inNom, string inPrenom);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();


int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher toutes les activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter des eleves";
	Gotoxy(15, 10);
	cout << "4- Afficher les eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une activite";
	Gotoxy(15, 14);
	cout << "6- Afficher les inscriptions d'une activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau

	Activite nouvelleActivite;
	nouvelleActivite.InitialiserActivite(code, titre);
	nouvelleActivite.AssignerResponsable(responsable);

	lesActivites[nombreActivitesReelles] = nouvelleActivite;

	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------
void Afficher(const Activite& inActivite)
{
	cout << "Code activite: ";
	AfficherValeurAvecEspaceAjuste(inActivite.getCodeActivite(), 10);
	cout << "Titre: ";
	AfficherValeurAvecEspaceAjuste(inActivite.getTitre(), 20);
	cout << "Responsable: ";
	cout << inActivite.getResponsable();
}

void AfficherValeurAvecEspaceAjuste(const string& inValeur, const int& inEspaceTotal)
{
	int nombreCaractereValeur = inValeur.length();
	int nombreEspacesAfficherApresValeur = inEspaceTotal - nombreCaractereValeur;

	cout << inValeur;

	for (int i = 1; i <= nombreEspacesAfficherApresValeur; i++)
	{
		cout << " ";
	}
}

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();

	if (nombreActivitesReelles == 0)
	{
		cout << "Il n'y a aucune activite en memoire.";
	}
	else
	{
		for (int index = 0; index < nombreActivitesReelles; index++)
		{
			cout << "Activite #" << index << "   ---   ";
			Afficher(lesActivites[index]);
			cout << endl;
		}
	}

	_getch();
}

//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	ClrScr();
	cout << "Inscription des eleves...\n\n";

	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");

	cout << "Inscription reussie!";

	_getch();
}

//----------------------------------------------------------------------------------------

void Afficher(Eleve inEleve)
{
	cout << "Code eleve: ";
	AfficherValeurAvecEspaceAjuste(inEleve.getCodeEleve(), 10);
	cout << "Nom: ";
	AfficherValeurAvecEspaceAjuste(inEleve.getNom(), 20);
	cout << "Prenom: ";
	cout << inEleve.getPrenom();
}

void AfficherLesEleves()
{
	ClrScr();

	if (nombreElevesReels == 0)
	{
		cout << "Il n'y a aucun eleve en memoire.";
	}
	else
	{
		for (int index = 0; index < nombreElevesReels; index++)
		{
			cout << "Eleve #" << index << "   ---   ";
			Afficher(lesEleves[index]);
			cout << endl;
		}
	}

	_getch();
}
//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	Eleve nouvelEleve(inCode, inPrenom, inNom);

	lesEleves[nombreElevesReels] = nouvelEleve;

	nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);

	if (cptEleve == -1)
	{
		cout << "[Erreur] Le code de l'eleve est invalide.\n";
	}
	else if (cptActivite == -1)
	{
		cout << "[Erreur] Le code de l'activite est invalide.\n";
	}
	else
	{
		Eleve* eleveAInscrire = &lesEleves[cptEleve];
		Activite* activiteAInscrire = &lesActivites[cptActivite];

		cout << "Inscription de l'eleve: \n";
		Afficher(*eleveAInscrire);
		cout << "Inscription a l'activite: \n";
		Afficher(*activiteAInscrire);

		eleveAInscrire->InscrireAUneActivite(activiteAInscrire);
	}

	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int indexEleveRecherche = -1;

	int cptEleve = 0;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{
		if (lesEleves[cptEleve].getCodeEleve() == inCodeVoulu)
		{
			indexEleveRecherche = cptEleve;
			trouve = true;
		}
		
		cptEleve++;
	}
	return indexEleveRecherche;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	int indexActiviteRecherche = -1;

	bool trouve = false;
	int cptActivite = 0;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{
		if (lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue)
		{
			indexActiviteRecherche = cptActivite;
			trouve = true;
		}

		cptActivite++;
	}
	return indexActiviteRecherche;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;

	int indexActiviteVoulue = RechercherActivite(activite);

	if (indexActiviteVoulue == -1)
	{
		cout << "[Erreur] Le code de l'activite est inexistant\n";
	}
	else
	{
		Activite* activiteVoulue = &lesActivites[indexActiviteVoulue];

		cout << "Voici les eleves qui participe a l'activite: \n";
		Afficher(*activiteVoulue);

		for (int index = 0; index < maxActivites; index++)
		{
			Eleve* unEleve = &lesEleves[index];
			Activite* activiteInscrite = unEleve->getActivite();

			if (activiteInscrite != NULL)
			{
				if (activiteInscrite->getCodeActivite() == activite)
				{
					Afficher(*unEleve);
				}
			}		
		}
	}

	_getch();
}







