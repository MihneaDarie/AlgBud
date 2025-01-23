#pragma once
#include "Page.h"
#include "BuildandVisualize.h"
#include "Graph.h"

class GraphPage: public Page
{
	Button* m_refresh;
	Graph *m_graph;
	SmartButton* m_PlayGround;
public:
	GraphPage(const char* name, Windows& window, int length, int width, Button* a) : Page(name, window, length, width)
	{
		m_refresh = a;
		m_type = graphs;

		m_graph = new Graph(50);

		m_PlayGround = new BuildandVisualize("PlayGround", { 10, 50 }, { 1300, 700 });

	}

	void HandleEvent() override;
	void DrawPage() override;

};

