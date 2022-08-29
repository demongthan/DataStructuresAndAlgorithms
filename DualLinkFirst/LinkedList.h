#pragma once
#ifndef _LinkedList_h_
#define _LinkedList_h_

#include "LinkedList.h"
#include "Item.h"

template<class InfoType>
class LinkedList
{
private:
	Item<InfoType>* First;
	Item<InfoType>* Last;
	int Count;
public:
	LinkedList();
	bool IsEmpty();
	void InsertFirst(InfoType theInfo);
	void InsertLast(InfoType theInfo);
	void InsertOrder(InfoType theInfo);
	Item<InfoType>* Find(InfoType theInfo);
	Item<InfoType>* FindOrder(InfoType theInfo);
	void Remove(InfoType theInfo, bool& error);
	void RemoveOrder(InfoType theInfo, bool& error);
	void DisplayNext();
	void DisplayPrevious();
	void Clear();
	~LinkedList();
};

#endif // !_LinkedList_h_
