#include "LinkedList.h"

template <class InfoType>
LinkedList<InfoType>::LinkedList()
{
	Header = new Item<InfoType>();
	Header->Next = Header;
	Count = 0;
}

template<class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return Header->Next == Header;
}

template<class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	q->Next = Header->Next;
	Header->Next = q;
	Count++;
}

template<class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;
	while (p != Header && cont)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else
			cont = true;
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	tp->Next = q;
	q->Next = q;
	Count++;
}

template<class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;
	while (p != Header && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;
	if (!found)
		p = NULL;
	return p;
}

template<class InfoType>
Item<InfoType>* ::LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;
	while (p != Header && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = Header;
	return p;
}

template<class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = Header->Next;
	while (p != Header && !found)
		if (p->Info == theInfo)
			found = true;
		else
		{
			tp = p;
			p = p->Next;
		}

	if (found)
	{
		tp->Next = p->Next;
		delete p;
		Count--;
	}
	error = !found;
}

template<class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = Header->Next;
	while (p != Header && !found)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else if (p->Info == theInfo)
			found = true;
		else
			p = Header;

	if (found)
	{
		tp->Next = p->Next;
		delete p;
		Count--;
	}
	error = !found;
}

template<class InfoType>
void LinkedList<InfoType>::Display()
{
	if (IsEmpty())
		cout << "Danh sach rong\n";
	else
	{
		cout << "Noi dung cua danh sach: \n";
		Item<InfoType>* p = Header->Next;
		while (p!Header)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu cua danh sach: " << Count << endl;
	}
}

template<class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (Header->Next != Header)
	{
		p = Header->Next;
		Header->Next = p->Next;
		delete p;
	}
	Count = 0;
}

template<class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}