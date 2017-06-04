#pragma once
#include "OrderedList.h"
#include"UnoCard.h"

class UnoPlayer
{
public:
	OrderedList<UnoCard> hand;
	bool isMatch(UnoCard k);
    ~UnoPlayer() {     };
};


inline bool UnoPlayer::isMatch(UnoCard k)
{
	bool result = false;
	for (unsigned int i = 1; i <= hand.getLength(); i++)
	{
		UnoCard temp = hand.retrieve(i);
		if (temp.rank == k.rank)
		{
			result = true;
		}
		else if (temp.colour == k.colour)
		{
			result = true;
		}
	}
	return result;
}