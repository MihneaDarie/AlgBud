#include "BuildandVisualize.h"

BuildandVisualize::BuildandVisualize(const char* name, sf::Vector2f LeftCorner, sf::Vector2f size) : SmartButton(name, LeftCorner, size)
{
}

void BuildandVisualize::draw(sf::RenderWindow& w)
{
	w.draw(m_txt); 
	w.draw(m_rangle);
	w.draw(m_TitleSlot);
	w.draw(m_txt);



}