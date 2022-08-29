#include "LinkedList.h"

template<class InfoType>
LinkedList<InfoType>::LinkedList()
{
	First = NULL;
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
	Item<InfoType> q = new Item<InfoType>(theInfo);

	q->Next == First;
	First = q;
	Count++;
}

template<class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cout = true;
	Item<InfoType>* tp;
	Item<InfoType>* p = First;
	bool cont = true;
	while (p != NULL && cont)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else
			cont = false;

	Item<InfoType>* q = new Item<InfoType>(theInfo);
	if (p == First)
		First = q;
	else
		tp->Next = q;
	q->Next = p;
	Count++;
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
bool LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = First;
	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;
	return found;
}

template<class InfoType>
bool LinkedList<InfoType>::FindOrder(InfoType theInfo)
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
	return found;
}

template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
		{
			tp = p;
			p = p->Next;
		}

	if (!found)
	{
		if (p == First)
			First = p->Next;
		else
			tp->Next = p->Next;
		delete p;
		Count--;
	}
	error = !found;
}

template <class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp;
	Item<InfoType>* p;

	while (p != NULL !found)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;

	if (!found)
	{
		if (p == First)
			First = p->Next;
		else
			tp->Next = p->Next;
		delete p;
		Count--;
	}

	error = !found;
}

template <class InfoType>
void LinkedList<InfoType>::Swap(InfoType& a, InfoType& b)
{
	InfoType temp = x;
	x = y;
	y = temp;
}

template <class InfoType>
void LinkedList<InfoType>::BubbleSort()
{
	Item<InfoType>* end = NULL;
	Item<InfoType>* last = NULL;
	bool flag = true;
	while (flag)
	{
		flag = false;
		Item<InfoType>* p = First;
		while (p != end)
		{
			Item<InfoType>* q = p->Next;
			if (q != end)
			{
				if (p->Info > q->Info)
				{
					flag = true;
					Swap(p->Info, q->Info);
					last = q;
				}
			}
			p = q;
		}
		end = last;
	}
}

template <class InfoType>
void LinkedList<InfoType>::Display()
{
	if (IsEmpty())
		cout << "Danh sach rong!"<<endl;
	else
	{
		cout << "Noi dung cua danh sach: " << endl;
		Item<InfoType>* p;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu: " << Count << endl;
	}
}

template <class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (First != NULL)
	{
		p = First;
		First = p->Next;
		delete p;
	}
	Count = 0;
}

template <class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}