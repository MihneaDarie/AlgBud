#pragma once
#include "Button.h"
#include <vector>
#include "Windows.h"

enum pages
{
	menu,graphs,algorithms
};

class Page
{
protected:
	std::string m_PageName;
	
	Windows* m_window;

	unsigned int m_length, m_width;

	sf::Vector2i m_Wcoords;

	pages m_type;

public:

	Page();
	Page(const char*, Windows&,int,int);

	Windows& GetWindow();

	const char* getName();

	virtual void HandleEvent()=0;
	void run();
	virtual void DrawPage()=0;

};

