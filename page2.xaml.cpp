//
// page2.xaml.cpp
// 
// Usage
// =====
//		Implémentation de la classe page2.
// 
// @author = Jean-Roland Bryan Ngoupeyou
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//importation outils(fichiers de dossiers)
#include "pch.h"
#include "page2.xaml.h"

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
Simulateur_Processus::page2::page2()
{
	InitializeComponent();
}

//Evenements

void Simulateur_Processus::page2::Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'aide via une boite de dialogue
{
	auto dialogue = ref new MessageDialog("Remplissez uniquement avec des entiers.", "Aide");
	dialogue->ShowAsync();
}

void Simulateur_Processus::page2::Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'avant-propos via une boite de dialogue
{
	auto dialogue = ref new MessageDialog("Simulateur de planification de processus.\nVersion 1.0\n© 2024\nTous droits réservés", "Avant-Propos");
	dialogue->ShowAsync();
}

void Simulateur_Processus::page2::Reset_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Chargerment de page
{
	Frame->GoBack();
}

void Simulateur_Processus::page2::Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Fermer l'app
{
	Windows::UI::Xaml::Application::Current->Exit();
}

void Simulateur_Processus::page2::Simuler(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Evenements pour afficher pour les processus suivant la politique SJF
{
	//Processus(P) suivant la politique SJF

	string temps_execution1, temps_execution2, temps_execution3, temps_execution4, temps_execution5;
	charger(E1->Text, temps_execution1); charger(E2->Text, temps_execution2); charger(E3->Text, temps_execution3); charger(E4->Text, temps_execution4); charger(E5->Text, temps_execution5);
	vector<string> table_des_temps_dexecution{ temps_execution1, temps_execution2, temps_execution3, temps_execution4, temps_execution5 };
	sort(begin(table_des_temps_dexecution), end(table_des_temps_dexecution));		//Temps d'éxecution trié

	//Creation d'une correspondance entre les processus avec leur temps d'execution
	unordered_map<string, string> maping{
		{ temps_execution1, "P1"},
		{ temps_execution2, "P2"},
		{ temps_execution3, "P3"},
		{ temps_execution4, "P4"},
		{ temps_execution5, "P5"},
	};

	//Affichage des Processus(P)
	wstring texte{ begin(maping[table_des_temps_dexecution[0]]), end(maping[table_des_temps_dexecution[0]]) };
	P1->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_dexecution[1]]), end(maping[table_des_temps_dexecution[1]]) };
	P2->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_dexecution[2]]), end(maping[table_des_temps_dexecution[2]]) };
	P3->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_dexecution[3]]), end(maping[table_des_temps_dexecution[3]]) };
	P4->Content = ref new Platform::String(texte.c_str());
	texte = { begin(maping[table_des_temps_dexecution[4]]), end(maping[table_des_temps_dexecution[4]]) };
	P5->Content = ref new Platform::String(texte.c_str());

	//---------

	//Temps d'execution(TP)
	texte = { begin(table_des_temps_dexecution[0]), end(table_des_temps_dexecution[0]) };
	TP1->Text = ref new Platform::String(texte.c_str());
	int durée{ stoi(table_des_temps_dexecution[0]) + stoi(table_des_temps_dexecution[1]) }, temps_moyen{ stoi(table_des_temps_dexecution[0]) };
	temps_moyen += durée;
	string Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP2->Text = ref new Platform::String(texte.c_str());
	durée += stoi(table_des_temps_dexecution[2]); temps_moyen += durée;
	Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP3->Text = ref new Platform::String(texte.c_str());
	durée += stoi(table_des_temps_dexecution[3]); temps_moyen += durée;
	Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP4->Text = ref new Platform::String(texte.c_str());
	durée += stoi(table_des_temps_dexecution[4]);
	Texte = to_string(durée);
	texte = { begin(Texte), end(Texte) };
	TP5->Text = ref new Platform::String(texte.c_str());

	//Temps moyen(temps_moyen)
	Texte = to_string(static_cast<double>(temps_moyen / 5));
	texte = { begin(Texte), end(Texte) };
	TempsMoyen->Text = "Temps moyen d'attente : " + ref new Platform::String(texte.c_str());
}

//-----------