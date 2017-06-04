#pragma once
#include <iostream>
//added enum, makes distribution of suits easier
enum Colour { YELLOW = 1, RED = 2, GREEN = 3, BLUE = 4 };
const char *Colour_str[]={"YELLOW", "RED", "GREEN", "BLUE"};

class UnoCard 
{
	public:
		Colour colour;
		int rank;
		friend std::ostream &operator<<(std::ostream &output, const UnoCard &card);
		friend bool operator< (const UnoCard &b,const UnoCard &c);
		UnoCard();
};

inline bool operator< (const UnoCard &b,const UnoCard &c)
{
	return (b.rank < c.rank);
}

 inline std::ostream &operator<<(std::ostream &output, const UnoCard &card)
{
    switch (card.colour)
    {
        case 1:
            output << " Yellow " << " - " << card.rank;
            break;
            
        case 2:
            output << " Red " << " - " << card.rank;
            break;
            
        case 3:
            output << " Green " << " - " << card.rank;
            break;
            
        case 4:
            output << " Blue " << " - " << card.rank;
            break;
            
        default:
            break;
    }
    return output;
}

inline UnoCard::UnoCard()
{

}
