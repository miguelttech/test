//
// page2.xaml.h
// 
// Usage
// =====
//		Déclaration de la classe page2.
// 
// @author = Jean-Roland Bryan Ngoupeyou	
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//Declaration en question
#pragma once

#include "page2.g.h"

namespace Simulateur_Processus
{
	public ref class page2 sealed
	{
	public:
		page2();
	private:
		void Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Reset_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Simuler(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
