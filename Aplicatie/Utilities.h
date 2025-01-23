#pragma once
#include"stdio.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

namespace Utilities
{

	struct node
	{
		int data;
		node* next;

		node() { data = 0; next = nullptr; }
		node(int value) { data = value; next = nullptr; }

	};

	struct poz
	{
		int x, y;
	};

	class GraphNode
	{	
		unsigned int m_number;
		
		sf::CircleShape m_shape;
		float m_radius;
		sf::Vector2f m_poz;
		
		sf::Text m_text;
		sf::Font m_font;
		sf::Vector2f m_Tpoz;
		float m_Tsize;

		float m_magnitude;
		sf::Vector2f m_normalizedDir;
		sf::Vector2f m_direction;
		sf::Vector2f m_velocity;
		sf::Vector2f m_origin;
		float m_speed;

	public:

		GraphNode(int number,float radius ,float x,float y,sf::Vector2f origin)
		{
			m_number = number;
			m_radius = radius;
			m_poz = {x,y}; 
			
			m_origin.x = origin.x;
			m_origin.y = origin.y;
			m_direction = m_origin - m_poz;
			m_magnitude = std::sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
			m_normalizedDir = m_direction / m_magnitude;
			m_speed = 7.0f;
			m_velocity = m_normalizedDir * m_speed;

			
			m_shape.setFillColor(sf::Color::White);
			m_shape.setPosition(m_poz);
			m_shape.setRadius(m_radius);
			
			m_font.loadFromFile("Arial.ttf");

			char m_nr[10];
			sprintf_s(m_nr, 10, "%d", m_number);
			
			m_Tpoz=(m_number <= 9 ? sf::Vector2f(x + 10.0f, y + 5.0f) : (m_number <= 99 ? sf::Vector2f(x + 5.0f, y + 5.0f) : sf::Vector2f(x + 3.0f, y + 5.0f)));
			m_Tsize = 15.0f;
			m_text.setFont(m_font);
			m_text.setCharacterSize(m_Tsize);
			m_text.setString( m_nr );
			m_text.setStyle(sf::Text::Regular);
			m_text.setFillColor(sf::Color::Black);
			m_text.setPosition(m_Tpoz);

		}

		sf::Vector2f GetPoz() { return m_poz; }

		void incSize()
		{
			m_radius -= 0.3f;

			m_direction = m_origin - m_poz;
			m_magnitude = std::sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
			m_normalizedDir = m_direction / m_magnitude;
			m_velocity = m_normalizedDir * m_speed;

			if(m_poz.x + m_velocity.x >= 20 && m_poz.y + m_velocity.y >= 20) m_poz += m_velocity;
			m_shape.setPosition(m_poz);
			m_shape.setRadius(m_radius);

			m_Tsize += 0.5;
			m_text.setCharacterSize(m_Tsize);
			m_text.setPosition(m_poz);

		}
		
		void decSize()
		{
			
			m_radius += 0.3f;

			m_direction = m_origin - m_poz;
			m_magnitude = std::sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
			m_normalizedDir = m_direction / m_magnitude;
			m_velocity = m_normalizedDir * m_speed;

			if (m_poz.x - m_velocity.x >= 0 && m_poz.y - m_velocity.y >= 0) m_poz -= m_velocity;
			m_shape.setPosition(m_poz);
			m_shape.setRadius(m_radius);

			m_Tsize -= 0.5;
			m_text.setCharacterSize(m_Tsize);
			m_text.setPosition(m_poz);
		}

		void draw(sf::RenderWindow& window)
		{
			window.draw(m_shape);
			window.draw(m_text);
		}

	};

	inline bool inPlayGround(GraphNode& nod, sf::RenderWindow& w )
	{
		sf::Vector2i w_coords = w.getPosition();

		sf::Vector2f n_coords = nod.GetPoz();
		sf::Vector2f p_coords = { 10.0f,50.0f };
		sf::Vector2f p_size = { 1300.0f,700.0f };

		return n_coords.x >= p_coords.x + (float)w_coords.x && n_coords.x <= p_coords.x + p_size.x + (float)w_coords.x &&
			n_coords.y >= p_coords.y + (float)w_coords.y && n_coords.y <= p_coords.y + p_size.y + (float)w_coords.y;

	}
	
	inline void Sort(poz** list,int n)
	{
		bool ok = 0;
		while (!ok)
		{
			ok = 1;
			for(int i=0;i<n;i++)
				if (list[i]->x > list[i + 1]->x ||
					list[i]->x == list[i + 1]->x && list[i]->y > list[i + 1]->y)
				{
					auto aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					ok = 0;
				}
		}
	}

}
