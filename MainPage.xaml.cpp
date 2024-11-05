//
// MainPage.xaml.cpp
// 
// Usage
// =====
//		Implémentation de la classe MainPage.
// 
// @author = Jean-Roland Bryan Ngoupeyou
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//Importation outils(fichiers et dossiers)
#include "pch.h"
#include "MainPage.xaml.h"
#include "page1.xaml.h"
#include "page2.xaml.h"
#include "page3.xaml.h"

using namespace Windows::UI::Popups;
using namespace Windows::UI::Xaml::Controls;


//Chargement de l'application
Simulateur_Processus::MainPage::MainPage()
{
	InitializeComponent();
}

//Evenements

void Simulateur_Processus::MainPage::Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'aide
{
	auto dialogue = ref new MessageDialog("Ici c'est l'aide.", "Aide");
	dialogue->ShowAsync();
}

void Simulateur_Processus::MainPage::Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Afficher l'avant-propos
{
	auto dialogue = ref new MessageDialog("Simulateur de planification de processus.\nVersion 1.0\n© 2024\nTous droits réservés", "Avant-Propos");
	dialogue->ShowAsync();
}

void Simulateur_Processus::MainPage::Demarrer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Chargement de page
{
	if ((Check1->IsChecked->Value == false) && (Check2->IsChecked->Value == false) && (Check3->IsChecked->Value == false)) {
		auto dialogue = ref new MessageDialog("Veuillez choisir une option.", "ChoiceNotFoundError");
		dialogue->ShowAsync();
	} else if ((Check1->IsChecked->Value == true) && (Check2->IsChecked->Value == false) && (Check3->IsChecked->Value == false)) {
		Frame->Navigate(page1::typeid);
	} else if ((Check1->IsChecked->Value == false) && (Check2->IsChecked->Value == true) && (Check3->IsChecked->Value == false)) {
		Frame->Navigate(page2::typeid);
	} else if ((Check1->IsChecked->Value == false) && (Check2->IsChecked->Value == false) && (Check3->IsChecked->Value == true)) {
		Frame->Navigate(page3::typeid);
	}
	else {
		auto dialogue = ref new MessageDialog("Veuillez choisir une option.", "ChoiceNotFoundError");
		dialogue->ShowAsync();
	}
}

void Simulateur_Processus::MainPage::Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Fermeture de l'app
{
	Windows::UI::Xaml::Application::Current->Exit();
}

void Simulateur_Processus::MainPage::ResetError(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
//Gestion erreurs
{
	auto dialogue = ref new MessageDialog("Générer un simulateur.", "ResetError");
	dialogue->ShowAsync();
}

//----------








