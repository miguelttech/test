//
// page1.xaml.cpp
// 
// Usage
// =====
//		Implémentation de la classe page1.
// 
// @author = Jean-Roland Bryan Ngoupeyou
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//Importation outils(fichiers et dossiers)
#include <vector>
#include <unordered_map>
#include <string>

#include "pch.h"
#include "page1.xaml.h"

using namespace std;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Xaml::Controls;


//Fonctions
template<typename T1>
void charger(T1 x, string& y) 
//Fonction convertir Platform::string en string
//
//Returns
//-------
//	Nothing (Charges x dans y)
//
{
	for (auto i : x) y.push_back(i);
}

//Chargement de l'application
Simulateur_Processus::page1::page1()
{
	InitializeComponent();
}

//Evenements

void Simulateur_Processus::page1::Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'aide via une boite de dialogue
{
	auto dialogue = ref new MessageDialog("Remplissez uniquement avec des entiers.\nEviter de mettre les même temps d'arrivée.", "Aide");
	dialogue->ShowAsync();
}

void Simulateur_Processus::page1::Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'avant-propos via une boite de dialogue
{
	auto dialogue = ref new MessageDialog("Simulateur de planification de processus.\nVersion 1.0\n© 2024\nTous droits réservés", "Avant-Propos");
	dialogue->ShowAsync();
}

void Simulateur_Processus::page1::Reset_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Chargerment de page
{
		Frame->GoBack();
}

void Simulateur_Processus::page1::Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Fermer l'app
{
	Windows::UI::Xaml::Application::Current->Exit();
}

void Simulateur_Processus::page1::Simuler(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Evenements pour afficher pour les processus suivant la politique FCFS
{
	//Processus(P) suivant le politique FCFS

	string temps_arrive1, temps_arrive2, temps_arrive3, temps_arrive4, temps_arrive5;
	charger(A1->Text, temps_arrive1); charger(A2->Text, temps_arrive2); charger(A3->Text, temps_arrive3); charger(A4->Text, temps_arrive4); charger(A5->Text, temps_arrive5);
	vector<string> table_des_temps_darrive{ temps_arrive1, temps_arrive2, temps_arrive3, temps_arrive4, temps_arrive5 };
	sort(begin(table_des_temps_darrive), end(table_des_temps_darrive));		//Temps d'arrivé trié
	
	//Creation d'une correspondance entre les processus avec leurs temps d'arrivé
	unordered_map<string, string> maping{
		{ temps_arrive1, "P1"},
		{ temps_arrive2, "P2"},
		{ temps_arrive3, "P3"},
		{ temps_arrive4, "P4"},
		{ temps_arrive5, "P5"},
	};

	wstring texte{ begin(maping[table_des_temps_darrive[0]]), end(maping[table_des_temps_darrive[0]]) };
	P1->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_darrive[1]]), end(maping[table_des_temps_darrive[1]]) };
	P2->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_darrive[2]]), end(maping[table_des_temps_darrive[2]]) };
	P3->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_darrive[3]]), end(maping[table_des_temps_darrive[3]]) };
	P4->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_darrive[4]]), end(maping[table_des_temps_darrive[4]]) };
	P5->Content = ref new Platform::String(texte.c_str());

	//-----------

	//Temps d'execution et moyen

	//Temps d'éxecution(TP)
	string temps_execution1, temps_execution2, temps_execution3, temps_execution4, temps_execution5;
	charger(E1->Text, temps_execution1); charger(E2->Text, temps_execution2); charger(E3->Text, temps_execution3); charger(E4->Text, temps_execution4); charger(E5->Text, temps_execution5);

	//Creation d'une correspondance entre les processus avec leur temps d'execution à l'aide de leur temps d'arrivé
	maping = {
		{ temps_arrive1, temps_execution1 },
		{ temps_arrive2, temps_execution2 },
		{ temps_arrive3, temps_execution3 },
		{ temps_arrive4, temps_execution4 },
		{ temps_arrive5, temps_execution5 },
	};

	texte = { begin(maping[table_des_temps_darrive[0]]), end(maping[table_des_temps_darrive[0]]) };
	TP1->Text = ref new Platform::String(texte.c_str());
	int durée{ stoi(maping[table_des_temps_darrive[0]]) + stoi(maping[table_des_temps_darrive[1]]) }, temps_moyen{ stoi(maping[table_des_temps_darrive[0]]) };
	temps_moyen += durée;
	string Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP2->Text = ref new Platform::String(texte.c_str());
	durée += stoi(maping[table_des_temps_darrive[2]]); temps_moyen += durée;
	Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP3->Text = ref new Platform::String(texte.c_str());
	durée += stoi(maping[table_des_temps_darrive[3]]); temps_moyen += durée;
	Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP4->Text = ref new Platform::String(texte.c_str());
	durée += stoi(maping[table_des_temps_darrive[4]]); 
	Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP5->Text = ref new Platform::String(texte.c_str());

	//Temps moyen(temps_moyen)
	Texte = to_string(static_cast<double>(temps_moyen / 5));
	texte = { begin(Texte), end(Texte) };
	TempsMoyen->Text = "Temps moyen d'attente : " + ref new Platform::String(texte.c_str());

	//------------------------
}

//----------


