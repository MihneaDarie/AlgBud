#pragma once
#include <queue>
#include <vector>
#include "Utilities.h"
#include "iostream"

class PriorityQueue
{
	int m_size;
	int m_capacity;
	Utilities::poz** m_list;
public:
	PriorityQueue() { m_size = 0; m_capacity = 4; m_list = new Utilities::poz*[m_capacity]; }
	
	void push(Utilities::poz a) 
	{   
		if (m_size == m_capacity)
		{
			m_capacity *= 2;
			Utilities::poz** list = new Utilities::poz*[m_capacity];

			for (int i = 0; i < m_capacity; i++)
				list[i] = (i < m_size ? m_list[i] : nullptr);

			delete[] m_list;

			m_list = list;

			m_list[m_size++] = &a;

		}
		else
		{
			m_list[m_size++] = &a;
			Utilities::Sort(m_list,m_size);
		}
	}

	void Delete(Utilities::poz a)
	{
		for(int i=0;i<m_size;i++)
			if (m_list[i]->x == a.x && m_list[i]->y == a.y)
			{
				for (int j = i; j < m_size; j++)
					m_list[i] = m_list[i + 1];
			}
			else if (m_list[i]->x == a.y && m_list[i]->y == a.x)
			{
				for (int j = i; j < m_size; j++)
					m_list[i] = m_list[i + 1];
			}
		m_size-=2;
	}

}; 

class LinkedList 
{
    Utilities::node* head;
public:

    LinkedList() : head(nullptr) {}

    void insertAtEnd(int value)
    {
        Utilities::node* newNode = new Utilities::node();
        newNode->data = value;
        newNode->next = nullptr;

    
        if (!head) 
        {
            head = newNode;
            return;
        }

    
        Utilities::node* temp = head;
        while (temp->next) 
        {
            if (temp->data == value) return;
            temp = temp->next;
        }

        temp->next = newNode;
    }
    
    void deleteValue(int value) 
    {
        if (!head){return;}

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        Utilities::node* temp = head;
        while (temp->next->next->data != value)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromBeginning() 
    {
        if (!head) 
        {
            return;
        }

        Utilities::node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!head) 
        {
            return;
        }

        if (!head->next) 
        {
            delete head;
            head = nullptr;
            return;
        }

        
        Utilities::node* temp = head;
        while (temp->next->next) 
        {
            temp = temp->next;
        }

        
        delete temp->next;
        temp->next = nullptr;
    }
   
    void deleteFromPosition(int position) 
    {
        if (position < 1) 
        {
            return;
        }

        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }

        Utilities::node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp || !temp->next)
        {
            return;
        }
       
        Utilities::node* nodeToDelete = temp->next;
        
        temp->next = temp->next->next;
        
        delete nodeToDelete;
    }

};


class Graph
{
	int m_size; 
    int m_capacity;
	int** m_matrix;
    
    std::vector<Utilities::GraphNode*> m_NodeList;
    float m_NodeSize;
	
    PriorityQueue m_EdgeList;
	LinkedList* m_AdjancecyList;

public:
	Graph(int);

	void AddEdge(int row,int column);
    void AddNode(sf::Vector2f center);
    
    void DeleteEdge(int row, int column);

    void incSize();
    void decSize();

	void DeleteNode(int value);

    void draw(sf::RenderWindow& window);
    void print();
};

