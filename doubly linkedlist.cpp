#include <iostream>

template <class Type>
class DNode{
public:
DNode(){
data = 0;
prev = next = NULL;
}
DNode(Type data){
DNode::data = data;
prev = next = NULL;
}

Type getData() const {
return data;
}

void setData(Type data) {
DNode::data = data;
}

DNode<Type> *getPrev() const {
return prev;
}

void setPrev(DNode<Type> *prev) {
DNode::prev = prev;
}

DNode<Type> *getNext() const {
return next;
}

void setNext(DNode<Type> *next) {
DNode::next = next;
}


void display() {
std::cout << "Address of Node : "<<&(*this)<<" , data: " << data << " , prev: " << prev << " , next: " << next<<std::endl;

}
friend std::ostream &operator<<(std::ostream &os, const DNode &node) {
os << "Address of Node :"<<&(node)<< "data: " << node.data << " prev: " << node.prev << " next: " << node.next<<std::endl;
return os;
}

private:
Type data;
DNode<Type> * prev;
DNode<Type> * next;
};

template <class DataType>
class DList{
public:
DList(){
size = 0;
head = NULL;
}
void display(){
std::cout<<"Size = "<<size<<std::endl;
DNode<DataType> * temp = head;
while (temp != NULL){
temp->display();
temp = temp->getNext();
}
}
void insertAtStart(DataType data){
DNode<DataType> *n = new DNode(data);

if(head == NULL){
head = n;
}
else{
n->setNext(head);
head->setPrev(n);
head = n;
}
size++;
}
void insertAtEnd(DataType data){
DNode<DataType> *n = new DNode(data);

if(head == NULL){
head = n;
}
else{
DNode<DataType> * temp = head;
while(temp->getNext() != NULL){
temp = temp->getNext();
}
temp->setNext(n);
n->setPrev(temp);
}
size++;
}
void insertAtMiddle(DataType data,int index) {
if (index <= size) {
DNode<DataType> *n = new DNode<DataType>(data);
if (head == NULL) {
head = n;
} else {
DNode<DataType> * previous = NULL;
DNode<DataType> * current = head;
int i = 1;
while (i < index && current->getNext() != NULL) {
previous = current;
current = current->getNext();
i++;
}
n->setNext(current);
n->setPrev(previous);
previous->setNext(n);
current->setPrev(n);
}
size++;
}
else{
std::cout<<"Doubly Linked List -- Index : "<<index<<" not found "<<std::endl;
}
}
private:
int size;
DNode<DataType> * head;
};

int main() {

DList<int> dList;
dList.insertAtStart(20);
dList.display();
std::cout<<std::endl;
dList.insertAtStart(10);
dList.display();
std::cout<<std::endl;
dList.insertAtStart(5);
dList.display();
std::cout<<std::endl;
dList.insertAtEnd(30);
dList.display();
std::cout<<std::endl;
dList.insertAtMiddle(25,4);
dList.display();
return 0;
}