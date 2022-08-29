#include "LinkedList.h"

template<class InfoType>
LinkedList<InfoType>::LinkedList()
{
	First = NULL;
	Last = NULL;
	Count = 0;
}

template<class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return First == NULL;
}

template<class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);

	if (First != NULL)
		First->Previous = q;
	else
		Last = q;

	q->Next = First;
	First = q;
	Count++;
}

template<class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);

	if (Last != NULL)
		Last->Next = q;
	else
		First = q;

	q->Previous = Last;
	Last = q;
	Count++;
}

template<class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* p = First;

	while (p != NULL && cont)
		if (p->Info < theInfo)
			p = p->Next;
		else
			cont = false;

	if (p == First)
		InsertFirst(theInfo)
	else
	{
		if (p == NULL)
			InsertLast(theInfo);
		else
		{
			Item<InfoType>* q = new Item<InfoType>(theInfo);
			Item<InfoType>* tp = p->Previous;

			tp->Next = q;
			q->Next = p;

			p->Previous = q;
			q->Previous = tp;
			Count++;
		}
	}
}

template<class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = First;

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
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;
	return p;
}

template<class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;

	if (found)
	{
		Item<InfoType>* tp = p->Previous;
		Item<InfoType>* sp = p->Next;

		if (tp == NULL)
			tp->Next = sp;
		else
			First = sp;

		if (sp != NULL)
			sp->Previous = tp;
		else
			Last = tp;
		delete p;
		Count--;
	}

	error = !found;
}

template<class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;

	if (found)
	{
		Item<InfoType>* tp = p->Previous;
		Item<InfoType>* sp = p->Next;

		if (tp == NULL)
			tp->Next = sp;
		else
			First = sp;

		if (sp != NULL)
			sp->Previous = tp;
		else
			Last = tp;
		delete p;
		Count--;
	}

	error = !found;
}

template<class InfoType>
void LinkedList<InfoType>::DisplayNext()
{
	if (IsEmpty())
		cout << "Danh sach rong\n";
	else
	{
		cout << "Noi dung cua danh sach: \n";
		Item<InfoType>* p = First;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So luong phan tu: " << Count << endl;
	}
}

template<class InfoType>
void LinkedList<InfoType>::DisplayPrevious()
{
	if (IsEmpty())
		cout << "Danh sach rong\n";
	else
	{
		cout << "Noi dung cua danh sach: \n";
		Item<InfoType>* p = Last;
		while (p != NULL)
		{
			p->Display();
			p = p->Previous;
		}
		cout << "So luong phan tu: " << Count << endl;
	}
}

template<class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (First != NULL)
	{
		p = First;
		First = p->Next;
		delete p;
	}
	Last = NULL;
	Count = 0;
}

template<class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}