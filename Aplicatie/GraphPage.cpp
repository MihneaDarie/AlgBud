#include "GraphPage.h"

void GraphPage::DrawPage()
{
	m_refresh->draw(m_window->getWindow());
	m_PlayGround->draw(m_window->getWindow());
	m_graph->draw(m_window->getWindow());
}

void GraphPage::HandleEvent()
{

	sf::Event event = {};
	while (m_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window->close();
			break;
		case sf::Event::MouseButtonPressed:
			
			if (OverButton(*m_PlayGround, m_window->getWindow()))
				m_graph->AddNode(m_PlayGround->GetCenter());
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::I:
				m_graph->incSize();
				break;
			case sf::Keyboard::D:
				m_graph->decSize();
				break;
			}
			break;
		}
	}
}