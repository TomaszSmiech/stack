#include <iostream>
#include "stack.h"
int main() {

    stack<int> st;

    st.push_back(22);
    st.push_back(30);
    st.push_back(100);;

    std::cout<<st.pop_back()<<" "<<st.pop_back()<<" "<<st.pop_back()<<std::endl;

    return 0;
}
