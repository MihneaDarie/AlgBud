#include "SmartButton.h"

SmartButton::SmartButton(const char* name, sf::Vector2f LeftCorner, sf::Vector2f size)
{
	m_Title = name;
	m_TopLeftCorner = LeftCorner;
	m_size = size;

	if (!m_font.loadFromFile("Arial.ttf"))
	{
		std::cout << "Nu exista";
	}

	m_rangle.setSize({ size.x, size.y });
	m_rangle.setPosition(LeftCorner.x, LeftCorner.y);
	m_rangle.setFillColor(sf::Color::Color(40,40,50,255));

	m_TitleSlot.setSize({ 1300, 20 });
	m_TitleSlot.setPosition(LeftCorner.x, LeftCorner.y);
	m_TitleSlot.setFillColor(sf::Color::Color(50, 50, 75, 255));

}



sf::Vector2f SmartButton::GetPos() { return m_TopLeftCorner; }
sf::Vector2f SmartButton::GetSize() { return m_size; }

sf::Vector2f SmartButton::GetCenter() { return sf::Vector2f( m_TopLeftCorner + m_size / 2.0f ); }