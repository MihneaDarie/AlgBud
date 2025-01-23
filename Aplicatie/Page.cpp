#include "Page.h"
#include "AlgBud.h"



Page::Page(): m_PageName(nullptr) {}

const char* Page::getName()
{
	return m_PageName.c_str();
}

Page::Page(const char* name, Windows& window,int length, int width)
{ 
	m_PageName = name;

	m_length = length;
	m_width = width;

	m_window = &window;

}

Windows& Page::GetWindow()
{
	return *m_window;
}

void  Page::run()
{
	///m_window = new Windows("AlgBud",m_length,m_width);
	std::cout << "LOADING!!!!!!!!\n";
	m_window->getWindow().create(sf::VideoMode(m_length,m_width,32),"AlgBud");
	std::cout << "DONE LOADING!!!!!!!!!\n";
	m_Wcoords = m_window->getPosition();
	while (m_window->isOpen())
	{
		HandleEvent();
		m_window->clear(sf::Color::Black);
		DrawPage();
		m_window->display();
	}
}

