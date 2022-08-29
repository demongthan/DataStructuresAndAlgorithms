#pragma once
#ifndef _ITEM_H_
#define _ITEM_H_

#include "Lib.h"

template <class InfoType>
class Item {
public:
	InfoType Info;
	Item<InfoType> Next;
public:
	Item(InfoType theInfo);
	void Display();
};

#endif // !_ITEM_H_
