#include "Item.h"

template <class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	this->Info = theInfo;
	this->Next = NULL;
}

template <class InfoType>
void Item<InfoType>::Display()
{
	cout << Info << endl;
}