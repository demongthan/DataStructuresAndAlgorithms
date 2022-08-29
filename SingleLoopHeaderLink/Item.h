#pragma once
#ifndef _Item_h_
#define _Item_h_

#include "Lib.h"

template<class InfoType>
class Item
{
public:
	InfoType Info;
	Item<InfoType>* Next;
public:
	Item(InfoType theInfo);
	Item();
	void Display();
};

#endif // !_Item_h_
