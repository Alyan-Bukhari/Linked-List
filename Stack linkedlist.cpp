#include <iostream>

class Node{
public:
Node() = default;
Node(int d){
data = d;
next = NULL;
}

void setData(int data) {
Node::data = data;
}

void setNext(Node *next) {
Node::next = next;
}

int getData() const {
return data;
}

Node *getNext() const {
return next;
}
void display(){
std::cout<<data<<std::endl;
}

private:
int data {0};
Node *next {NULL};
};

class Stack{
public:
Stack() = default;

void push(int data){
Node * temp = new Node(data);
if(top == NULL){
top = temp;
}
else{
temp->setNext(top);
top = temp;
}
size++;
}
void pop(){
if(top != NULL) {
Node *temp = top;
top = top->getNext();
temp->setNext(NULL);
delete temp;
size--;
temp = NULL;
}
else{
std::cout<<"Stack -- Already Empty !!"<<std::endl;
}
}
void display(){
Node * temp = top;
while(temp != NULL){
temp->display();
temp = temp->getNext();
}
}
int getSize(){
return size;
}
int getTopElement(){
return top->getData();
}

bool isEmpty(){
return top == NULL;
}
void setSize(int size) {
Stack::size = size;
}

Node *getTop() const {
return top;
}

void setTop(Node *top) {
Stack::top = top;
}

private:
int size {0};
Node *top {NULL};
};
int main() {
Stack stack;
stack.display();
std::cout<<"Size = "<<stack.getSize()<<std::endl;
stack.push(10);
stack.display();
std::cout<<"Size = "<<stack.getSize()<<std::endl;
stack.push(12);
stack.push(15);
std::cout<<"Size = "<<stack.getSize()<<std::endl;
stack.display();
stack.pop();
std::cout<<"Size = "<<stack.getSize()<<std::endl;
stack.display();
stack.pop();
std::cout<<"Size = "<<stack.getSize()<<std::endl;
stack.display();
return 0;
}