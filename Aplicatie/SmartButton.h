#pragma once
#include "Button.h"

class SmartButton
{
protected:

	std::string m_Title;
	sf::Text m_txt;
	sf::Font m_font;
	sf::RectangleShape m_TitleSlot;

	sf::Vector2f m_TopLeftCorner;
	sf::Vector2f m_size;

	sf::RectangleShape m_rangle;
	

public:
	SmartButton() = default;
	SmartButton(const char*, sf::Vector2f, sf::Vector2f);

	sf::Vector2f GetPos();
	sf::Vector2f GetSize();

	sf::Vector2f GetCenter();

	virtual void draw(sf::RenderWindow&)=0;

	void ChangeColor(sf::Color c) { m_rangle.setFillColor(c); }

};

inline bool OverButton(SmartButton& b, sf::RenderWindow& w)
{
	sf::Vector2i w_coords = w.getPosition();
	sf::Vector2i mouse_coords = sf::Mouse::getPosition();

	mouse_coords.x -= 5;
	mouse_coords.y -= 30;
	sf::Vector2f b_coords = b.GetPos();
	sf::Vector2f b_size = b.GetSize();

	return mouse_coords.x >= b_coords.x + (float)w_coords.x && mouse_coords.x <= b_coords.x + b_size.x + (float)w_coords.x &&
		mouse_coords.y >= b_coords.y + (float)w_coords.y && mouse_coords.y <= b_coords.y + b_size.y + (float)w_coords.y;

}