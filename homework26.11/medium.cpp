#include <iostream>
#include <list>

using namespace std;

template<class ValueType>
struct Tree {
    ValueType value;
    int size;
    Tree* parent;
    Tree* brother;
    Tree* next;

    Tree(ValueType value) {
        this->value = value;
        this->brother = nullptr;
        this->next = nullptr;
        this->parent = nullptr;
        this->size = -1;
    }

    void insert(int level, ValueType newValue) {
        if (level == 0) {
            if (this->brother == nullptr) {
                this->parent = nullptr;
                this->brother = new Tree(newValue);
                this->size = 0;
            } else {
                Tree* pointer = this->brother;
                while (pointer->next != nullptr) {
                    pointer = pointer->next;
                }

                pointer->next = new Tree(newValue);
            }

            return;
        }

        if (this->size < level) {
            Tree* levelPointer = this;
            while (level != 1) {
                levelPointer = levelPointer->next;
                level--;
            }

            levelPointer->next = new Tree(newValue);
            levelPointer->next->parent = levelPointer;
            this->size++;
        } else {
            Tree* levelPointer = this;
            while (level != 0) {
                levelPointer = levelPointer->next;
                level--;
            }

            if (levelPointer->brother == nullptr) {
                levelPointer->brother = new Tree(newValue);
                this->size = 0;
            } else {
                Tree* pointer = levelPointer->brother;
                while (pointer->next != nullptr) {
                    pointer = pointer->next;
                }

                pointer->next = new Tree(newValue);
            }
        }
    }

    void print() {
        cout << value << " ";
        Tree* pointer = brother;

        while (pointer != nullptr) {
            cout << pointer->value << " ";
            pointer = pointer->next;
        }

        cout << "\n";
        if (next != nullptr) {
            next->print();
        }
    }

    void swapNodes(int firstLevel, int secondLevel) {
        firstLevel = min(firstLevel, secondLevel);
        secondLevel = max(firstLevel, secondLevel);

        if (firstLevel == 0) {
            Tree* firstNode = this;
            Tree* secondNode = this;
            while (secondLevel != 0) {
                secondNode = secondNode->next;
                secondLevel--;
            }

            Tree* parentB = secondNode->parent;
            Tree* nextB = secondNode->next;
            Tree* nextA = this->next;

            secondNode->parent = nullptr;
            secondNode->next = nextA;
            nextA->parent = secondNode;

            firstNode->parent = parentB;
            firstNode->next = nextB;
            parentB->next = firstNode;
            nextB->parent = firstNode;
        }
    }
};


int main() {
    Tree<int> currentTree(1);
    currentTree.insert(0, 2);
    currentTree.insert(0, 3);
    currentTree.insert(0, 4);
    currentTree.insert(1, 5);
    currentTree.insert(1, 6);
    currentTree.insert(2, 7);

    currentTree.print();

    cout << "--------------\n";

    currentTree.swapNodes(0, 1);

    currentTree.print();
    return 0;
}