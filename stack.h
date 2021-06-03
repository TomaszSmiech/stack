//
// Created by tomek on 03.06.2021.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iostream>
#include <exception>

template<class T>
class element {
public:
    element(const T & o, element<T> * nextobj):obj(o)
    {
        ptrNextObj = nextobj;
    }
    const T obj;
    element<T> *ptrNextObj;

    ~element(){}


} ;



template<class T>
class stack {

public:

    stack()
    {
        size_stack = 0;
    }

    stack(const stack & st);
    stack(const T & item)
    {
        element<T> * tmp;
        size_stack == 0 ? tmp = new element<T>(item, nullptr): tmp = new element<T>(item, top_obj_ptr);
        top_obj_ptr = tmp;
        size_stack++;
    }


    ~stack(){}


    T & top();

    bool empty()
    {
        if(size_stack == 0)
        {
            return true;
        } else{
            return false;
        }
    }

    void push_back(const T & item)
    {
        element<T> * tmp;
        size_stack == 0 ? tmp = new element<T>(item, nullptr): tmp = new element<T>(item, top_obj_ptr);
        top_obj_ptr = tmp;
        size_stack++;
    }


    T pop_back()
    {
        if(size_stack!=0) {
            T tmp_obj = top_obj_ptr->obj;
            element<T>* tmp_ptr = top_obj_ptr->ptrNextObj;

            delete top_obj_ptr;

            top_obj_ptr = tmp_ptr;
            size_stack--;
            return tmp_obj;
        }
        else
        {
            throw std::runtime_error("Stack is empty!");
        }
    }



private:

    element<T> * top_obj_ptr;
    unsigned size_stack;
};


#endif //STACK_STACK_H
