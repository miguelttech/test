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

	try {
		//Creation d'une correspondance entre les processus avec leur temps d'execution et tri des temps d'éxecution à l'aide du dictionnaire
		multimap<int, string> maping{
			{ stoi(temps_execution1), "P1"},
			{ stoi(temps_execution2), "P2"},
			{ stoi(temps_execution3), "P3"},
			{ stoi(temps_execution4), "P4"},
			{ stoi(temps_execution5), "P5"},
		};

		//Affichage des Processus(P)
		auto i = begin(maping);
		wstring texte{ begin(i->second), end(i->second) }; ++i;
		P1->Content = ref new Platform::String(texte.c_str());
		texte = { begin(i->second), end(i->second) }; ++i;
		P2->Content = ref new Platform::String(texte.c_str());
		texte = { begin(i->second), end(i->second) }; ++i;
		P3->Content = ref new Platform::String(texte.c_str());
		texte = { begin(i->second), end(i->second) }; ++i;
		P4->Content = ref new Platform::String(texte.c_str());
		texte = { begin(i->second), end(i->second) };
		P5->Content = ref new Platform::String(texte.c_str());

		//---------

		//Temps d'execution(TP)
		i = begin(maping);
		int durée = i->first, temps_moyen = i->first;
		string Texte = to_string(durée);
		texte = { begin(Texte), end(Texte) }; ++i;
		TP1->Text = ref new Platform::String(texte.c_str());
		durée += i->first; temps_moyen += durée;
		Texte = to_string(durée);
		texte = { begin(Texte), end(Texte) }; ++i;
		TP2->Text = ref new Platform::String(texte.c_str());
		durée += i->first; temps_moyen += durée;
		Texte = to_string(durée);
		texte = { begin(Texte), end(Texte) }; ++i;
		TP3->Text = ref new Platform::String(texte.c_str());
		durée += i->first; temps_moyen += durée;
		Texte = to_string(durée);
		texte = { begin(Texte), end(Texte) }; ++i;
		TP4->Text = ref new Platform::String(texte.c_str());
		durée += i->first;
		Texte = to_string(durée);
		texte = { begin(Texte), end(Texte) };
		TP5->Text = ref new Platform::String(texte.c_str());

		//Temps moyen(temps_moyen)
		Texte = to_string(static_cast<double>(temps_moyen) / 5.0);
		texte = { begin(Texte), end(Texte) };
		TempsMoyen->Text = "Temps moyen d'attente : " + ref new Platform::String(texte.c_str());
	}
	catch (const exception& e) {
		auto dialogue = ref new MessageDialog("Ca ne s'est pas passé comme prévu.\nAppuyez sur Ctrl+H pour voir l'aide.", "Error");
		dialogue->ShowAsync();
	}
}

//-----------