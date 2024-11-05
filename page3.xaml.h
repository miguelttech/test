//
// page3.xaml.h
// 
// Usage
// =====
//		Déclaration de la classe page3.
// 
// @author = Jean-Roland Bryan Ngoupeyou	
// @contact = ngoupeyoubryan9@gmail.com
// @version = 1.0
//

//Declaration en question
#pragma once

#include "page3.g.h"

namespace Simulateur_Processus
{
	public ref class page3 sealed
	{
	public:
		page3();
	private:
		void Aide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Apropos_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Reset_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Fermer(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Simuler(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
