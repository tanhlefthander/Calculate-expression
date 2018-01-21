#pragma once
#include <iostream>
using namespace std;
template <class T>
struct Node
{
	T val;
	Node<T> *next;
};

template <class T>
class MyStack{
private:
	Node<T>* top;
	int sz;
public:
	MyStack(){
		top= NULL;
		sz= 0;
	};
	~MyStack(){};
	void Push(T s){
		if(top == NULL){
			top= new Node<T>;
			top->val =s;
			top->next= NULL;
		}else{
			Node<T> *newNode = new Node<T> ;
			newNode->val = s;
			newNode-> next = top;
			top= newNode;
		}
		sz++;
	}
	T Top (){
		return top->val;
	};
	bool IsEmpty(){
		if(sz ==0 ) return true;
		return false;
	};
	void Pop(){
		if(sz==0) return;
		Node<T> *temp;
		temp = top->next;
		top= NULL;
		delete top;
		top= temp;
		sz--;
	}
	int Size(){ return sz;}
};

