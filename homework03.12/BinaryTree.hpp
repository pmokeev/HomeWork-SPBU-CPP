#include <iostream>

using namespace std;

template<class TKey, class TValue>
class BinaryTree  {
private:
    struct BinaryNode {
        TKey key;
        TValue value;
        BinaryNode *leftNode;
        BinaryNode *rightNode;

        BinaryNode(TKey key, TValue value)
                : key(key), value(value), leftNode(nullptr), rightNode(nullptr) {};
    };

    BinaryNode *root;
    void insert(TKey key, TValue value, BinaryNode *&temp);
    void remove(TKey key, BinaryNode *&temp);
    void preOrderPrint(BinaryNode *node);
    BinaryNode * findMin(BinaryNode *node);
    TValue findValue(TKey key, BinaryNode *node);
    int getSize(BinaryNode *node);
public:
    BinaryTree();
    void Init();

    void insert(TKey key, TValue value);
    void remove(TKey key);
    void preOrderPrint();
    TValue findValue(TKey key);
    int getSize();
};

template<class TKey, class TValue>
BinaryTree<TKey, TValue>::BinaryTree() {
    root = nullptr;
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::insert(TKey key, TValue value, BinaryTree::BinaryNode *&temp) {
    if (temp == nullptr) {
        temp = new BinaryNode(key, value);
    } else if (key < temp->key ) {
        insert(key, value, temp->leftNode);
    } else if (key > temp->key) {
        insert(key, value, temp->rightNode);
    }
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::remove(TKey key, BinaryTree::BinaryNode *&temp) {
    if(temp == nullptr) {
        return;
    }
    if (key < temp->key) {
        remove(key, temp->leftNode);
    } else if (key > temp->key) {
        remove(key, temp->rightNode);
    } else if (nullptr != temp->leftNode && nullptr != temp->rightNode) {
        temp->key = findMin(temp->rightNode)->key;
        remove(temp->key, temp->rightNode);
    } else {
        BinaryNode *oldNode = temp;
        temp = (temp->leftNode != nullptr) ? temp->leftNode : temp->rightNode;
        delete oldNode;
    }
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::insert(TKey key, TValue value) {
    insert(key, value, root);
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::remove(TKey key) {
    remove(key, root);
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::preOrderPrint() {
    preOrderPrint(root);
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::preOrderPrint(BinaryNode *node){
    if(node != nullptr) {
        std::cout << node->key << " " ;
        preOrderPrint(node->leftNode);
        preOrderPrint(node->rightNode);
    }
}

template<class TKey, class TValue>
typename BinaryTree<TKey, TValue>::BinaryNode *BinaryTree<TKey, TValue>::findMin(BinaryTree::BinaryNode *node) {
    if (node != nullptr) {
        while(node->leftNode != nullptr) {
            node = node->leftNode;
        }
    }

    return node;
}

template<class TKey, class TValue>
TValue BinaryTree<TKey, TValue>::findValue(TKey key) {
    return findValue(key, root);
}

template<class TKey, class TValue>
TValue BinaryTree<TKey, TValue>::findValue(TKey key, BinaryTree::BinaryNode *node) {
    if (node == nullptr) {
        return nullptr;
    } else if (key < node->key) {
        return isFind(key, node->leftNode);
    } else if (key > node->key) {
        return isFind (key, node->rightNode );
    } else {
        return node->value;
    }
}

template<class TKey, class TValue>
int BinaryTree<TKey, TValue>::getSize(BinaryTree::BinaryNode *node) {
    if (node == nullptr) {
        return 0;
    }

    return max(getSize(node->leftNode), getSize(node->rightNode)) + 1;
}

template<class TKey, class TValue>
int BinaryTree<TKey, TValue>::getSize() {
    return getSize(root);
}

template<class TKey, class TValue>
void BinaryTree<TKey, TValue>::Init() {
    TKey key;
    TValue value;
    while (cin >> key >> value) {
        insert(key, value, root);
    }
}
