#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <initializer_list>
#include <string>


class Button
{
	sf::RectangleShape m_rangle;
	sf::Text m_txt;
	sf::Font m_font;
	sf::Vector2f pos;
	///char* m_purpose;
	std::string m_purpose;
public:

	Button() : m_purpose(nullptr) {}

	Button(float x_coord, float y_coord, float length, float width, const char* name)
	{
		if (!m_font.loadFromFile("Arial.ttf"))
		{
			std::cout << "Nu exista";
		}

		m_txt.setFont(m_font);
		m_txt.setCharacterSize(30);
		m_txt.setString(name);
		m_txt.setStyle(sf::Text::Regular);
		m_txt.setFillColor(sf::Color::Black);
		m_txt.setPosition({ x_coord + 5.0f,y_coord + 5.0f });

		/*uint16_t sz = 0;
		while (name[sz++] != '\0') {}
		m_purpose = new char[sz];
		for (int i = 0; i < sz; i++)
			m_purpose[i] = name[i];
		m_purpose[sz] = '\0';
		*/
		m_purpose = name;

		m_rangle.setSize({ length, width });
		m_rangle.setPosition(x_coord, y_coord);
		m_rangle.setFillColor(sf::Color::White);

		pos.x = x_coord;
		pos.y = y_coord;
	}

	void ChangeName(const char* name)
	{
		/*uint16_t sz = 0;
		while (name[sz++] != '\0') {}
		m_purpose = new char[sz];
		for (int i = 0; i < sz; i++)
			m_purpose[i] = name[i];
		m_purpose[sz] = '\0';*/

		m_purpose = name;

		m_txt.setString(m_purpose);
	}

	void ChangeColor(sf::Color c) { m_rangle.setFillColor(c); }

	void ChangeEdgeThickness() {}

	const char* GetName() { return m_purpose.c_str(); }

	sf::Vector2f GetPos() { return pos; }

	void SetPos(float x_coord, float y_coord) { pos.x = x_coord; pos.y = y_coord; }

	sf::Vector2f GetSize() { return m_rangle.getSize(); }

	void draw(sf::RenderWindow& w) { w.draw(m_rangle); w.draw(m_txt); }

	~Button() = default;

};


inline bool OverButton(Button& b, sf::RenderWindow& w)
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


