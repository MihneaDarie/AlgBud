#pragma once
#include "Page.h"

class Menu: public Page
{
	sf::Text m_txt;
	sf::Font m_font;

	Button* m_graphs;
	Button* m_algorithms;

public:
	Menu(const char* name, Windows& window, int length,int width, Button* a, Button* b ) : Page(name, window,length,width) 
	{

		m_graphs = a;
		m_algorithms = b;
		
		m_type = pages::menu;

		if (!m_font.loadFromFile("Arial.ttf"))
		{
			std::cout << "Nu exista";
		}

		m_txt.setFont(m_font);
		m_txt.setCharacterSize(30);
		m_txt.setString(name);
		m_txt.setStyle(sf::Text::Regular);
		m_txt.setFillColor(sf::Color::White);
		m_txt.setPosition({ 600 ,200 });

	}
	void HandleEvent() override;
	void DrawPage() override;

};

