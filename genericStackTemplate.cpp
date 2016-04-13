#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

template <class T>
class Stack { 
	private: 
    vector<T> element;     // elements 

	public: 
    void push(T const&);  	  // push element 
    void pop();               // pop element 
    T top() const;            // return top element 
    bool empty() const{       // return true if empty.
        return element.empty(); 
    } 
}; 

template <class T>
void Stack<T>::push (T const& item) { 
    element.push_back(item);    
} 

template <class T>
void Stack<T>::pop () { 
    if (element.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    element.pop_back();         
} 

template <class T>
T Stack<T>::top () const 
{ 
    if (element.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    return element.back();      
} 

int main() 
{ 
    try { 
        Stack<int> myIntegerStack;  // stack of ints 
        Stack<string> myStringStack;    // stack of strings 

        myIntegerStack.push(10); 
        cout << myIntegerStack.top() <<endl; 

        myStringStack.push("Messi"); 
        cout << myStringStack.top() << std::endl; 
        myStringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
} 