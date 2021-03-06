/*
	Cong Tuan Nguyen && Adam Rucker
	3/3/2017
	Lab 7/ RombergIntegration Lab
*/	
#if !defined (QUEUELINKED_H)
#define QUEUELINKED_H

#include "NextNode.h"

template < class T >
class QueueLinked
{

   private:
      NextNode<T>* back;
      int sze;

   public:
	/*destructor & constructor*/
		//pre: takes nothing, initialize back & size
		//post: returns nothing
      QueueLinked();
		
		//pre: takes nothing, delete all
		//post: returns nothing
      ~QueueLinked();
		
	/*methods*/
		//pre: takes nothing, check if size is empty
		//post: returns size
      bool isEmpty();
		
		//pre: takes nothing
		//post: returns size
      int size();
		
      void dequeueAll(); 
		
		//pre: takes nothing
		//post: returns item at start of queue
      T* peek();
		
		//pre: takes nothing
		//post: gets item and remove it from queue
      T* dequeue();
		
		//pre: takes item parameter
		//post: adds item to queue
      void enqueue(T* item);

};

template < class T >
QueueLinked<T>::QueueLinked()
{
   back = NULL;
   sze = 0;
}

template < class T >
QueueLinked<T>::~QueueLinked()
{
   dequeueAll();
}

template < class T >
bool QueueLinked<T>::isEmpty()
{
    return sze == 0;
}

template < class T >
int QueueLinked<T>::size()
{
    return sze;
}

template < class T >
void QueueLinked<T>::dequeueAll()
{
   if (sze == 0) return;

   NextNode<T>* prev = NULL;
   NextNode<T>* curr = back->getNext();  //the head
   back->setNext(NULL);  //break the bridge link

   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      delete prev;
   }

   sze = 0;
}

template < class T >
T* QueueLinked<T>::peek()
{
    T* item = NULL;
    if (!isEmpty()) 
    {  
      // queue is not empty; retrieve front
      NextNode<T>* head = back->getNext();
      item = head->getItem();
    }
    return item;
}

template < class T >
void QueueLinked<T>::enqueue(T* item)
{
    NextNode<T>* node = new NextNode<T>(item);

    //DO THIS (enqueueing the first item is a special case)
	if(isEmpty())
	{
		back = node;
		node->setNext(node);
	}
	else
	{
		NextNode<T>* prev = back;
		back = node;
		node->setNext(prev->getNext());
		prev->setNext(node);
	}
    sze++;
}

template < class T >
T* QueueLinked<T>::dequeue()
{
    T* item = NULL;

    //DO THIS (dequeueing the last item is a special case)
    //also, check that there are items before dequeueing
	
	if (sze == 1)
	{
		NextNode<T>* head = back->getNext();
		back = NULL;
		item = head->getItem();
		head->setNext(NULL);
		delete head;
	}
	
	else if (!isEmpty())
	{
		NextNode<T>* head = back->getNext();
		back->setNext(head->getNext());
		head->setNext(NULL);
		item = head->getItem();
		delete head;
	}
	
	sze--;

    return item;
}

#endif
