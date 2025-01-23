#include "Graph.h"

Graph::Graph(int size)
{
	m_capacity = size;
	m_NodeSize = 15.0f;

	m_matrix = new int* [m_capacity];
	for (int i = 0; i < m_capacity; i++)
		m_matrix[i] = new int[m_capacity];

	m_AdjancecyList = new LinkedList[m_capacity];
}

void Graph::AddEdge(int row, int column)
{
	if (row < m_size || column < m_size) return;

	m_matrix[row][column] = m_matrix[column][row] = 1;

	m_EdgeList.push({ row,column });
	m_EdgeList.push({column,row});

	m_AdjancecyList[row].insertAtEnd(column);

}

void Graph::AddNode( sf::Vector2f center )
{
	
	sf::Vector2i poz = sf::Mouse::getPosition();
	m_NodeList.push_back(new Utilities::GraphNode(m_size++, m_NodeSize, poz.x , poz.y ,center ));
}

void Graph::DeleteEdge(int row, int column)
{
	m_matrix[row][column] = m_matrix[column][row] = 0;

	m_EdgeList.Delete({ row,column });
	m_EdgeList.Delete({ column,row });

	m_AdjancecyList[row].deleteValue(column);
	m_AdjancecyList[column].deleteValue(row);

}

void Graph::incSize()
{	
	if (m_NodeSize - 0.3f > 0)
	{
		m_NodeSize -= 0.3f;
		for (auto i : m_NodeList)
			i->incSize();
	}
}

void Graph::decSize()
{
	m_NodeSize += 0.3f;
	for (auto i : m_NodeList)
		i->decSize();
}

void Graph::draw(sf::RenderWindow& window)
{
	if(!m_NodeList.empty())
		for (auto i : m_NodeList)
		{
			if(Utilities::inPlayGround(*i,window))
				i->draw(window);
		}
}

void Graph::print()
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++) std::cout << m_matrix[i][j] << " ";
		std::cout << "\n";
	}
}