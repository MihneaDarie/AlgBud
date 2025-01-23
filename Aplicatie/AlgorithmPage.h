#pragma once
#include "Page.h"

class AlgorithmPage: public Page
{
	Button* m_refresh;
public:
	AlgorithmPage(const char* name, Windows& window, int length, int width, Button* a) : Page(name, window, length, width)
	{
		m_refresh = a;
		m_type = algorithms;
	}

	void HandleEvent() override;
	void DrawPage() override;

};


