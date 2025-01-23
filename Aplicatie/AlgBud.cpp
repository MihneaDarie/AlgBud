#include "AlgBud.h"
#include <iostream>

AlgBud::AlgBud(): m_type(menu)
{
	m_PageList.push(new Menu("AlgBud", m_window,700,400, new Button(10, 50,300,50, "Graphs"), new Button(10, 150,300,50, "Algotithms")));
}

void AlgBud::pushPage(pages type)
{
	switch (type)
	{
	case pages::menu:
		m_PageList.push(new Menu("AlgBud", m_window,700,400, new Button(10, 50, 300,50, "Graphs"), new Button(10, 150,300,50, "Algotithms")));
		m_type = pages::menu;
		std::cout << "changed to "<<GetInstanceType()<<"\n";
		break;
	case pages::graphs:
		m_PageList.push(new GraphPage("Graphs", m_window,1600,900, new Button(10, 50,300,50, "Refresh")));
		m_type = pages::graphs;
		std::cout << "changed to " << GetInstanceType() << "\n";
		break;
	case pages::algorithms:
		m_PageList.push(new AlgorithmPage("Algorithms", m_window,1600,900, new Button(10, 50,500,60, "Refresh")));
		m_type = pages::algorithms;
		std::cout << "changed to " << GetInstanceType() << "\n";
		break;
	}
}

void AlgBud::pushPaged(Page* a)
{
	m_PageList.push(a);	
	std::cout << "Current page is" << a->getName() << "\n";
}

pages AlgBud::GetInstanceType() { return m_type; }

AlgBud& AlgBud::Instance()
{
	static AlgBud instance;
	return instance;
}

void AlgBud::run()
{
	while (!m_PageList.empty())
	{
		m_current = m_PageList.front();
		m_PageList.pop();
		std::cout << m_current->getName() << "!!!\n";
		m_current->run();
		
	}
	
}

void newWindow()
{

}