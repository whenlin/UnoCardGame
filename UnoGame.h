#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Bag.h"
#include <iostream>
#include"UnoPlayer.h"


static int NumOfPlayers = 3;



class UnoGame
{
	public:
        Queue<UnoCard> deck;
        Bag<UnoCard> BagofCards;
		Stack<UnoCard> faceupCards;
		
		UnoGame();
        ~UnoGame();
		UnoPlayer * m_container;
		void play();
		
};

UnoGame::~UnoGame()
{
    delete[] m_container;
}

void UnoGame::play()
{
    std::cout << "START!" << std::endl;
    bool result; int a;
    
    while (true)
    {
        UnoCard topCard = this->faceupCards.peek();
        for (int i = 0; i < NumOfPlayers; i++)
        {
            result = m_container[i].isMatch(topCard);
            a = i;
            std::cout << "It is Player " << a + 1 <<"'s turn"<<std::endl;
            
            if (result == true)
            {
                faceupCards.push(m_container[i].hand.remove(i + 1));
                UnoCard temp = faceupCards.peek();
                std::cout << "Player " << a + 1 << " found a match! They played " << temp << std::endl;
                std::cout<<std::endl;
            }
            else
            {
                int j = m_container[i].hand.insert(deck.dequeue());
                std::cout << "Player " << a + 1 << " did not find a match. They drew a card" << std::endl;
                std::cout<<std::endl;
            }
            
            if (deck.size() == 0)
            {
                UnoCard top = faceupCards.pop();
                while (faceupCards.size() != 0)
                {
                    deck.enqueue(faceupCards.pop());
                }
                faceupCards.push(top);
                std::cout << "The deck has been repopulated" << std::endl;
                std::cout<<std::endl;
            }
            
            if (m_container[i].hand.getLength() == 1)
            {
                std::cout << "Player " << a + 1 << " yells UNO!" << std::endl;
                std::cout<<std::endl;
            }
            else if (m_container[i].hand.getLength() == 0)
            {
                std::cout << "Player " << a + 1 << " has no more cards left! Player " << a + 1 << " has won the game!" << std::endl;
                std::cout<<std::endl;
                
                return;
            }
        }
        
    }
    
}

UnoGame::UnoGame()
{
    m_container = new UnoPlayer[3];
    
    while (BagofCards.isEmpty() != true)
    {
        
        deck.enqueue(BagofCards.getOne());
    }
    std::cout<<"The deck is now populated"<<std::endl;
    
    for (int t = 0; t < 7; t++)
    {
        for (int n = 0; n<3; n++)
        {
            m_container[n].hand.insert(deck.dequeue());
        }
    }
    faceupCards.push(deck.dequeue());
    
    std::cout<<"The top card on the faceup deck is "<<faceupCards.peek()<<std::endl;
    
}


