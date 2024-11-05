//
// page3.xaml.cpp
// 
// Usage
// =====
//		Implémentation de la classe page3.
// 
// @author = Jean-Roland Bryan Ngoupeyou
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//importation outils(fichiers de dossiers)
#include "pch.h"
#include "page3.xaml.h"

using namespace std;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Xaml::Controls;

//Fonctions
template<typename T1>
void charger(T1 x, string & y)
//Fonction convertir Platform::string en string
//
//Returns
//-------
//	Nothing (Charges x dans y)
//
{
	y.clear();
	for (auto i : x) y.push_back(i);
}

//Chargement de l'application
Simulateur_Processus::page3::page3()
{
	InitializeComponent();
}

//Evenements

void Simulateur_Processus::page3::Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'aide via une boite de dialogue
{
	auto dialogue = ref new MessageDialog("Remplissez uniquement avec des entiers.", "Aide");
	dialogue->ShowAsync();
}

void Simulateur_Processus::page3::Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'avant-propos via une boite de dialogue
{
	auto dialogue = ref new MessageDialog("Simulateur de planification de processus.\nVersion 1.0\n© 2024\nTous droits réservés", "Avant-Propos");
	dialogue->ShowAsync();
}

void Simulateur_Processus::page3::Reset_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Chargerment de page
{
	Frame->GoBack();
}

void Simulateur_Processus::page3::Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Fermer l'app
{
	Windows::UI::Xaml::Application::Current->Exit();
}

void Simulateur_Processus::page3::Simuler(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Evenement pour afficher pour les processus suivant la politique Round Robin
{
	//Declaration variable et autre
	string temps_execution1, temps_execution2, temps_execution3, quantum_, Texte;
	charger(E1->Text, temps_execution1); charger(E2->Text, temps_execution2); charger(E3->Text, temps_execution3); charger(Quantum->Text, quantum_);
	int compteur_P1{ stoi(temps_execution1) }, compteur_P2{ stoi(temps_execution2) }, compteur_P3{ stoi(temps_execution3) }, quantum{ stoi(quantum_) }, durée{ 0 };

	//Affichage processus(P) et leur temps d'execution(TE) suivant la politique Round Robin
	P1->Content = ""; TE->Text = "";
	TE->Text += "  0  ";
	while ( (compteur_P1 > 0) || (compteur_P2 > 0) || (compteur_P3 > 0)) {
		if (compteur_P1 > 0) { 
			P1->Content += "  P1  "; compteur_P1 -= quantum; 
			if (compteur_P1 > 0) {
				durée += quantum;
				Texte = to_string(durée);
				wstring texte_{ begin(Texte), end(Texte) };
				TE->Text += "  " + ref new Platform::String(texte_.c_str()) + "  ";
			} else {
				durée += (compteur_P1 + quantum) ;
				Texte = to_string(durée);
				wstring texte{ begin(Texte), end(Texte) };
				TE->Text += "  " + ref new Platform::String(texte.c_str()) + "  ";
			}
		}
		if (compteur_P2 > 0) {
			P1->Content += "  P2  "; compteur_P2 -= quantum;
			if (compteur_P2 > 0) {
				durée += quantum;
				Texte = to_string(durée);
				wstring texte1_{ begin(Texte), end(Texte) };
				TE->Text += "  " + ref new Platform::String(texte1_.c_str()) + "  ";
			} else {
				durée += (compteur_P2 + quantum);
				Texte = to_string(durée);
				wstring texte1{ begin(Texte), end(Texte) };
				TE->Text += "  " + ref new Platform::String(texte1.c_str()) + "  ";
			}
		}
		if (compteur_P3 > 0) {
			P1->Content += "  P3  "; compteur_P3 -= quantum;
			if (compteur_P3 > 0) {
				durée += quantum;
				Texte = to_string(durée);
				wstring texte2_{ begin(Texte), end(Texte) };
				TE->Text += "  " + ref new Platform::String(texte2_.c_str()) + "  ";
			} else {
				durée += (compteur_P3 + quantum);
				Texte = to_string(durée);
				wstring texte2{ begin(Texte), end(Texte) };
				TE->Text += "  " + ref new Platform::String(texte2.c_str()) + "  ";
			}
		}
	}
}

//-----------
