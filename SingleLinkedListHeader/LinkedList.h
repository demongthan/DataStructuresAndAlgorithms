#pragma once
#ifndef _LinkedList_h_
#define _LinkedList_h_
#include "Item.h"

template <class InfoType>
class LinkedList
{
private:
	Item<InfoType>* Header;
	int count;
public:
	LinkedList();
	bool IsEmpty();
	void InsertFirst(InfoType theInfo);
	void InsertOrder(InfoType theInfo);
	Item<InfoType>* Find(InfoType theInfo);
	Item<InfoType>* FindOrder(InfoType theInfo);
	bool Find(InfoType theInfo);
	bool FindOrder(InfoType theInfo);
	void Remove(InfoType theInfo, bool& error);
	void RemoveOrder(InfoType theInfo, bool& error);
	void Display();
	void Clear();
	~LinkedList();
};

#endif // !_LinkedList_h_
