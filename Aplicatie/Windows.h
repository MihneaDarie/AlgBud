#pragma once
#include "SFML/Graphics.hpp"
#include <queue>


class Windows
{
	sf::RenderWindow m_main;
	std::queue<sf::RenderWindow*> m_SmartButtons;
public:
	
	Windows() = default; ///{ m_main = new sf::RenderWindow({ 500,300 }, "AlgBud"); m_main.setFramerateLimit(60); m_SmartButtons = nullptr; }
	bool isOpen() { return m_main.isOpen(); }
	sf::Vector2i getPosition() { return m_main.getPosition(); }
	bool pollEvent(sf::Event& e) { return m_main.pollEvent(e); }
	void clear(sf::Color c) { m_main.clear(c); }
	void display() { m_main.display(); }
	void close() { m_main.close(); }

	sf::RenderWindow& getWindow() { return m_main; }



	Windows& getObject()
	{
		return *this;
	}

};
