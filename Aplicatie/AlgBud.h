#pragma once
#include "GraphPage.h"
#include "AlgorithmPage.h"
#include "Menu.h"
#include "queue"

class AlgBud
{
	Windows m_window;
	Page* m_current;
	std::queue<Page*> m_PageList;
	pages  m_type;
public:
	
	AlgBud();

	pages GetInstanceType();
	void pushPage(pages);
	void pushPaged(Page*);

	void newWindow();
	
	static AlgBud& Instance();

	void run();

};

