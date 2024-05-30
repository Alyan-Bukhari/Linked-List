#include <iostream>
#include <cstring>

class MNode {
public:
    MNode() = default;

    MNode(int id, char *name) {
        MNode::id = id;
        MNode::name = name;
        MNode::prevId = nullptr;
        MNode::nextId = nullptr;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        MNode::id = id;
    }

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        MNode::name = name;
    }

    MNode *getPrevId() const {
        return prevId;
    }

    void setPrevId(MNode *prevId) {
        MNode::prevId = prevId;
    }

    MNode *getNextId() const {
        return nextId;
    }

    void setNextId(MNode *nextId) {
        MNode::nextId = nextId;
    }

    void display() {
        std::cout << "id: " << id << " , name: " << name << std::endl;
    }

private:
    int id{0};
    char *name{""};
    MNode *prevId{nullptr};
    MNode *nextId{nullptr};
};

class MultipleOrderedList {
public:
    MultipleOrderedList() = default;

    bool isEmpty() {
        return headId == nullptr;
    }

    void displayById() {
        MNode *temp = tailId;
        while (temp != nullptr) {
            temp->display();
            temp = temp->getPrevId();
        }
    }

    void insert(int id, char *name) {
        MNode *newNode = new MNode(id, name);
        if (isEmpty()) {
            headId = newNode;
            tailId = newNode;
        } else {
            insertById(newNode);
        }
        size++;
    }

    void deleteById(int id) {
        if (isEmpty()) {
            std::cerr << "List is empty\n";
            return;
        }

        MNode *curr = headId;

        while (curr != nullptr && curr->getId() != id) {
            curr = curr->getNextId();
        }

        if (curr == nullptr) {
            std::cerr << "Node with id " << id << " not found\n";
            return;
        }

        if (curr == headId && curr == tailId) {
            headId = tailId = nullptr;
        } else if (curr == headId) {
            headId = curr->getNextId();
            headId->setPrevId(nullptr);
        } else if (curr == tailId) {
            tailId = curr->getPrevId();
            tailId->setNextId(nullptr);
        } else {
            curr->getPrevId()->setNextId(curr->getNextId());
            curr->getNextId()->setPrevId(curr->getPrevId());
        }

        delete curr;
        size--;
    }

    void traverse() {
        std::cout << "Traversing the list:\n";
        MNode *temp = headId;
        while (temp != nullptr) {
            temp->display();
            temp = temp->getNextId();
        }
    }

private:
    int size{0};
    MNode *headId{nullptr};
    MNode *tailId{nullptr};

    void insertById(MNode *newNode) {
        MNode *curr = headId;

        while (curr != nullptr && curr->getId() > newNode->getId()) {
            curr = curr->getNextId();
        }

        if (curr == nullptr) { // Insert at tail
            newNode->setPrevId(tailId);
            tailId->setNextId(newNode);
            tailId = newNode;
        } else if (curr == headId) { // Insert at head
            newNode->setNextId(headId);
            headId->setPrevId(newNode);
            headId = newNode;
        } else { // Insert in between
            newNode->setPrevId(curr->getPrevId());
            newNode->setNextId(curr);
            curr->getPrevId()->setNextId(newNode);
            curr->setPrevId(newNode);
        }
    }
};

int main() {
    MultipleOrderedList multipleOrderedList;
    multipleOrderedList.insert(1537, "alyan");
    multipleOrderedList.insert(1197, "zain");
    multipleOrderedList.insert(1932, "suffy");
    multipleOrderedList.insert(2570, "ali");

    // Displaying the list by traversing
    multipleOrderedList.traverse();
    
    std::cout<<"Deleting ID 1932 "<< std::endl;
    // Deleting a node by ID
    multipleOrderedList.deleteById(1932);

    // Displaying the list again after deletion
    multipleOrderedList.traverse();

    return 0;
}
