#define DEFAULT_BAG 40
#include <stdlib.h> 
#include "UnoCard.h"
#pragma once
//bags allow us to remove RANDOM objects from it (that were previously placed inside)
// NOTE: your main should initialize a random number generator (via srand) when using Bag<T> objects
using namespace std;
template <class T>
class Bag 
{
public:
	Bag(unsigned int max_capacity = DEFAULT_BAG); // construct an empty bag of specified "max_capacity"
											  // if no value is provided, DEFAULT_BAG is used
	~Bag();  // destructor (recycles memory allocated by constructor)

	void add(T value); // adds a new T into the bag, 
					   // PRECONDITION: the bag must not be "full"
	T getOne(); // extracts an T from the bag, 
				// PRECONDITION: the bag must not be "empty"
	bool isEmpty() const;
	bool isFull() const;
	unsigned int currentSize() const;   // returns # of Ts now in bag
	unsigned int capacity() const;        // returns bag’s upper capacity

private:
	unsigned int m_size; // number of elements currently stored in the bag
	unsigned int m_max_capacity; // the maximum capacity of the bag 
	T * m_container;   // internal storage array of pointers to Ts 
};


template <class T>
Bag<T> ::Bag(unsigned int max_capacity)
{
	cout<<"Creating bag of cards..."<<endl;
	m_max_capacity = max_capacity;
	m_size = 40;
	m_container = new T[m_max_capacity];

	int a = 0;
	int e;
	for (int i = 0; i < 8; i++)
	{
		e = i % 8;
		if (e < 2)
		{
			for (int j = 1; j <= 5; j++)
			{
				UnoCard t;
				t.colour = RED;
				t.rank = j;
				m_container[a] = t;
				a++;
			}
		}
			else if (e == 2 || e == 3)
			{
				for (int j = 1; j <= 5; j++)
				{
					UnoCard t;
					t.colour = YELLOW;
					t.rank = j;
					m_container[a] = t;
					a++;
				}
			}
			else if (e == 4 || e == 5)
			{
				for (int j = 1; j <= 5; j++)
				{
					UnoCard t;
					t.colour = BLUE;
					t.rank = j;
					m_container[a] = t;
					a++;
				}
			}
			else if (e == 6 || e == 7)
			{
				for (int j = 1; j <= 5; j++)
				{
					UnoCard t;
					t.colour = GREEN;
					t.rank = j;
					m_container[a] = t;
					a++;
				}
			}

	}
}

template <class T>
Bag<T> :: ~Bag() 
{
	delete[] m_container;
}

template <class T>
void Bag<T> ::add(T value) 
{
	// PRECONDITION: the bag must not be "full"
	assert(!isFull() && "Bag is full (in add)");
	m_container[m_size] = value; // store the pointer 
	m_size++;
}

template <class T>
T Bag<T> ::getOne() 
{
	// PRECONDITION: the bag must not be empty when "getOne()" is called
	assert(!isEmpty() && "Bag is empty (in getOne)");
	//generate a random number between 0 and (m_size-1);
	unsigned int index = (unsigned int)(rand() % m_size);
	T value = m_container[index];
	m_container[index] = m_container[m_size - 1];
	m_size--;
	return value;
}

template <class T>
bool Bag<T> ::isEmpty() const 
{
	return (m_size == 0);
}

template <class T>
bool Bag<T> ::isFull() const 
{
	return (m_size == m_max_capacity);
}

template <class T>
unsigned int Bag<T> ::currentSize() const 
{
	return m_size;
}

template <class T>
unsigned int Bag<T> ::capacity() const 
{
	return m_max_capacity;
}