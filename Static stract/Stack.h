#pragma once
#include <iostream>
#include<new>
using namespace std;
template <typename T>

class Queue {
	T* V;
	int* P;
	int count;
public:
	Queue() = default;
	Queue(const Queue& obj);
	void push(T item,int pririty);
	T Max();
	T pop();
	void print();
	bool isEmpty();
	~Queue() {
		if (count >0) {
			delete[]V;
			delete[]P;
		}
	}
};

template<typename T>
inline Queue<T>::Queue(const Queue& obj)
{
	
	
	V= new T[obj.count];
	P = new int[obj.count];
	
	count = obj.count;
	for (size_t i = 0; i < count; i++)
	{
		V[i] = obj.V[i];

	}
	for (size_t i = 0; i < count; i++)
	{
		P[i] = obj.P[i];

	}
}

template<typename T>
inline void Queue<T>::push(T item, int priority)
{
	T* V2;
	int* P2;
	V2 = (T*)new T[count + 1];
	P2 = new int[count + 1];
	int pos;
	if (count == 0) {
		pos = 0;
	}
	else {
		pos = 0;
		while (pos < count) {
			if (P[pos] < priority)
				break;
			pos++;
		}
	}
	for (size_t i = 0; i < pos; i++)
	{
		V2[i] = V[i];
		P2[i] = P[i];
	}
	V2[pos] = item;
	P2[pos] = priority;
	for (size_t i = pos+1; i <count+1 ; i++)
	{
		V2[i] = V[i - 1];
		P2[i] = P[i - 1];
	}
	if (count > 0) {
		delete[]V;
		delete[]P;
	}
	V = V2;
	P = P2;
	count++;
}

template<typename T>
inline T Queue<T>::Max()
{
	T max =P[0];
	for (size_t i = 0; i < count; i++)
	{
		if (max < P[i]) {
			max = P[i];
		}
		
    }
	return max;
}

template<typename T>
inline T Queue<T>::pop()
{
	if (count == 0) {
		return 0;
	}
	T* V2;
	int* P2;
	V2 = new T[count - 1];
	P2 = new int[count - 1];
	T item =Queue::Max();
	
	for (size_t i = 0; i < count-1; i++)
	{
		V2[i] = V[i + 1];
		P2[i] = P[i + 1];
	}
	if (count > 0) {
		delete[]V;
		delete[]P;
	}
	V = V2;
	P = P2;

	count--;
	cout << "Deleted item with priority->";
	return item;
}

template<typename T>
inline void Queue<T>::print()
{
	for (size_t i = 0; i < count; i++)
	{
		cout << V[i] << ":" << P[i] << endl;
	}
	cout << endl;
	cout << "_________________________________" << endl;
	
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	return count!=0;
}
