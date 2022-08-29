#include "LinkedList.h"

template<class InfoType>
LinkedList<InfoType>::LinkedList()
{
	Header = new Item<InfoType>();
	Header->Next = NULL;
	count = 0;
}

template<class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return Header->Next == NULL;
}

template<class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	q->Next = Header->Next;
	Header->Next = q;
	count++;
}

template<class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;

	while (p != NULL && cout)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else
			cont = false;

	Item<InfoType>* q = new Item<InfoType>(theInfo);
	tp->Next = q;
	q->Next = p;
	count++;
}

template<class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;

	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;
	return p;
}

template<class InfoType>
Item<InfoType>* LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;
	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;
	return p;
}

template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = Header->Next;

	while (p != NULL && !found)
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
		count--;
	}
	error = !found;
}

template<class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = Header->Next;

	while (p != NULL && !found)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else
			found = true;

	if (found)
	{
		tp->Next = p->Next;
		delete p;
		count--;
	}
	error = !found;
}

template<class InfoType>
void LinkedList<InfoType>::Display()
{
	if (IsEmpty())
		cout << "Danh sach rong!" << endl;
	else
	{
		cout << "Danh sach cac phan tu: " << endl;
		Item<InfoType>* p = Header->Next;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu: " << count << endl;
	}
}

template<class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (Header->Next != NULL)
	{
		p = Header->Next;
		Header->Next = p->Next;
		delete p;
	}
}

template<class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}