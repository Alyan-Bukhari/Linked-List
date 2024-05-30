#include <iostream>

class Node{
public:
Node(){
data = 0;
next = NULL;
}
Node(int data){
Node::data = data;
next = NULL;
}

int getData() const {
return data;
}

void setData(int data) {
Node::data = data;
}

Node *getNext() const {
return next;
}

void setNext(Node *next) {
Node::next = next;
}

void display() {
std::cout<<"Address of Node : "<<&(*this)<< " , data: " << data << " , next: " << next<<std::endl;
}
friend std::ostream &operator<<(std::ostream &os, const Node &node) {
os << "data: " << node.data << " next: " << node.next;
return os;
}

private:
int data;
Node * next;
};

class CircularList{
public:
CircularList(){
head = NULL;
size = 0;
}
bool isEmpty(){
return head == NULL;
}
void insertAtEnd(int data){
Node *n = new Node(data);
if(isEmpty()){
head = n;
n->setNext(head);
}
else{
Node *temp = head;
while (temp->getNext() != head){
temp = temp->getNext();
}
temp->setNext(n);
n->setNext(head);
}
size++;

}
void insertAtStart(int data){
Node *n = new Node(data);
if(isEmpty()){
head = n;
n->setNext(head);
}
else{
n->setNext(head);
Node *temp = head;
while (temp->getNext() != head){
temp = temp->getNext();
}
temp->setNext(n);
head = n;
}
size++;

}
void display(){
std::cout<<"Size = "<<size<<std::endl;
Node *temp = head;
std::cout<<"Head = "<<head<<std::endl;
if(!isEmpty()) {
do {
temp->display();
temp = temp->getNext();
} while (temp != head);
}
}
private:
Node *head;
int size;
};
int main() {
CircularList circularList;
circularList.display();
circularList.insertAtEnd(10);
circularList.insertAtEnd(20);
circularList.display();
circularList.insertAtEnd(30);
circularList.insertAtEnd(40);
circularList.display();
circularList.insertAtStart(5);
circularList.display();
return 0;
}