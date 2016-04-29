#ifndef _MyLIST_H
#define _MyLIST_H

#include <iostream> 
#include <string.h>
using namespace std;

template <class T> class mNode;

template <class T>
class MyList		                    
{
private:
	mNode<T> *_head;

public:
	MyList() : _head(NULL)	{}				
	MyList(const MyList<T>& list) : _head(NULL)	{ *this = list; }	
	~MyList();														

	MyList<T>& operator=(const MyList<T>& list);				

	void add(const T& data);					
	bool remove(const int& index, T& rtrn);	
	T* find(const int& index);				
};

template <class T>
class mNode		
{
private:
	T* _data;
	mNode<T> *_next;
public:
	mNode(const T& data) : _next(NULL), _data(new T(data))	{}	   
	~mNode()				{ delete _data; }							

	friend class MyList<T>;		
};


template <class T>
MyList<T>::~MyList()
{
	mNode<T> *temp = _head, *next = NULL;
	while (temp != NULL)
	{
		next = temp->_next;
		delete temp;
		temp = next;
	}
}


template <class T>
MyList<T>& MyList<T>::operator=(const MyList<T>& list)
{
	if (this != &list)
	{
		mNode<T> *temp = _head, *next = NULL;
		while (temp != NULL)
		{
			next = temp->_next;
			delete temp;
			temp = next;
		}
		_head = new mNode<T>(*(list._head->_data));
		mNode<T> *dest = _head, *source = list._head;
		while (source)
		{
			dest->_next = new mNode<T>(*(source->_data));
			dest = dest->_next;
			source = source->_next;
		}
	}
	return *this;
}

template <class T>
void MyList<T>::add(const T& data)
{
	mNode<T> *temp = new mNode<T>(data);
	temp->_next = _head;
	_head = temp;
}


template <class T>
bool MyList<T>::remove(const int& index, T& retrn)
{
	mNode<T> *temp = _head, *prev = NULL;
	for (int i = 1; i<index && temp != NULL; i++)
	{
		prev = temp;
		temp = temp->_next;
	}
	if (temp)
	{
		if (!prev)
			_head = temp->_next;
		else
			prev->_next = temp->_next;
		retrn = *(temp->_data);
		delete temp;
		return true;
	}
	return false;
}


template <class T>
T* MyList<T>::find(const int& index)
{
	mNode<T> *temp = _head;
	for (int i = 1; i<index && temp != NULL; i++)
		temp = temp->_next;
	if (temp)
		return temp->_data;
	return NULL;
}

#endif