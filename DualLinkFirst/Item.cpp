#include "Item.h"

template<class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	Info = theInfo;
	Next = NULL;
	Previous = NULL;
}

template<class InfoType>
void Item<InfoType>::Display()
{
	cout << Info << endl;
}