//
// Created by Tomasz S on 03.06.2021.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iostream>
#include <exception>

template<class T>
class element {
public:
    element(const T & o, element<T> * nextobj);
   
    const T obj;
    element<T> *ptrNextObj;

    ~element(){}
} ;



template<class T>
class stack {

	public:
    		stack();
    		stack(const stack & st);
    		stack(const T & item);
  
    		~stack(){}


    		
		T pop_back();
    		bool empty();
    		void push_back(const T & item);
		void clear();	
		unsigned int size();
    
	private:
    		element<T> * top_obj_ptr;
    		unsigned stack_size;
};

template<class T>
element<T>::element(const T & o, element<T> * nextobj):obj(o)
{
    ptrNextObj = nextobj;
}

template<class T>
stack<T>::stack()
{
    stack_size = 0;
}

template<class T>
stack<T>::stack(const T & item)
{
    element<T> * tmp;
    tmp =  new element<T>(item, nullptr);
    top_obj_ptr = tmp;
    stack_size++;
}

template<class T>
bool stack<T>::empty()
{
    if(stack_size == 0)
    {
         return true;
    } 
    else
    {
         return false;
    }
}

template<class T>
void stack<T>::push_back(const T & item)
{
    element<T> * tmp;
    tmp = (stack_size == 0) ? new element<T>(item, nullptr): new element<T>(item, top_obj_ptr);
    top_obj_ptr = tmp;
    stack_size++;
}

template<class T>
T stack<T>::pop_back()
{
    if(stack_size!=0) 
    {
        T tmp_obj = top_obj_ptr->obj;
        element<T>* tmp_ptr = top_obj_ptr->ptrNextObj;

        delete top_obj_ptr;

        top_obj_ptr = tmp_ptr;
        stack_size--;
        return tmp_obj;
     }
     else
     {
        throw std::runtime_error("Stack is empty!");
     }
}

template<class T>
void stack<T>::clear()
{
    element<T> *tmp;
    while(tmp!=nullptr)
    {    
	tmp = top_obj_ptr->ptrNextObj;
    	delete top_obj_ptr;
    	top_obj_ptr = tmp; 
    }
    stack_size =0;    
}

template<class T>
unsigned int stack<T>::size()
{
    return stack_size;
}


#endif //STACK_STACK_H
