//
// MainPage.xaml.h
// 
// Usage
// =====
//		Déclaration de la classe MainPage.
// 
// @author = Jean-Roland Bryan Ngoupeyou	
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//Declaration en question
#pragma once

//importation fichiers
#include "MainPage.g.h"

namespace Simulateur_Processus
{
	public  ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Demarrer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ResetError(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}