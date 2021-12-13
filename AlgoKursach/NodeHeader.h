#pragma once
#include <string>

struct Node
{
	// Номер самолета
	int aircraftNumber;
	// Аэропорт назначения
	std::string destinationAirport;
	// время вылета
	std::string  departureTime;
	// ориентировочное время прибытия
	std::string  arrivalTime;
	// общее число мест
	int numberOfPlaces;
	// Количество проданных билетов
	int occupiedPlaces;

	Node* next;
};

void AddFirst(Node*& Head, Node* NewNode)
{
	NewNode->next = Head;
	Head = NewNode;
}

void AddAfter(Node* p, Node* NewNode)
{
	NewNode->next = p->next;
	p->next = NewNode;
}

void AddLast(Node*& Head, Node* NewNode) 
{
	Node* q = Head;
	if (Head == NULL) {
		AddFirst(Head, NewNode);
		return;
	}
	while (q->next) q = q->next;
	AddAfter(q, NewNode);
}

void FindByAirNumber(Node* Head, int airNum, Node*& FindedNodes)
{
	Node* temp = Head;
	FindedNodes = NULL;

	while (temp!=NULL)
	{
		if (airNum == temp->aircraftNumber) 
		{
			Node* nNode = new Node();
			nNode->aircraftNumber = temp->aircraftNumber;
			nNode->destinationAirport = temp->destinationAirport;
			nNode->departureTime = temp->departureTime;
			nNode->arrivalTime = temp->arrivalTime;
			nNode->numberOfPlaces = temp->numberOfPlaces;
			nNode->occupiedPlaces = temp->occupiedPlaces;
			AddFirst(FindedNodes, nNode);
		}
		temp = temp->next;
	}
}

void FindByNameAirpot(Node* Head, std::string destAir, Node*& FindedNodes) 
{
	Node* temp = Head;

	while (temp != NULL)
	{
		if (destAir == temp->destinationAirport)
		{
			Node* nNode = new Node();
			nNode->aircraftNumber = temp->aircraftNumber;
			nNode->destinationAirport = temp->destinationAirport;
			nNode->departureTime = temp->departureTime;
			nNode->arrivalTime = temp->arrivalTime;
			nNode->numberOfPlaces = temp->numberOfPlaces;

			AddFirst(FindedNodes, nNode);
		}
		temp = temp->next;
	}
}
void deletelem(Node*& root, Node* lst)
{
	struct Node* temp;
	temp = root;
	if (temp == lst)
	{
		root = root->next;
		return;
	}
	while (temp->next != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->next;
	}
	temp->next = lst->next; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла	
}