#include "Menu.h"
#include "AlgBud.h"
#include "GraphPage.h"
#include "AlgorithmPage.h"


void Menu::HandleEvent()
{
	
	if(OverButton(*m_graphs,m_window->getWindow()))  { m_graphs->ChangeColor(sf::Color(212, 212, 212, 212)); }
	else { m_graphs->ChangeColor(sf::Color::White); }
	
	if(OverButton(*m_algorithms,m_window->getWindow()))  { m_algorithms->ChangeColor(sf::Color(212, 212, 212, 212)); }
	else { m_algorithms->ChangeColor(sf::Color::White); }

	sf::Event event = {};
	while (m_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window->close();
			break;
		case sf::Event::MouseButtonPressed:

			if (OverButton(*m_graphs, m_window->getWindow())) { AlgBud::Instance().pushPage(graphs); m_window->close();
			}
			if (OverButton(*m_algorithms, m_window->getWindow())) { AlgBud::Instance().pushPage(algorithms); m_window->close(); }
			
			break;
		}
	}
}

void Menu::DrawPage()
{
	m_graphs->draw(m_window->getWindow());
	m_algorithms->draw(m_window->getWindow());
}
