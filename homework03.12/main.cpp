#include "BinaryTree.hpp"

using namespace std;

int main() {
    BinaryTree<int, int> bTree = BinaryTree<int, int>();

    bTree.insert(1, 2);
    bTree.insert(2, 2);
    bTree.insert(-1, 2);
    bTree.insert(5, 2);

    bTree.preOrderPrint();

    cout << "\n";

    bTree.remove(2);

    bTree.preOrderPrint();
    return 0;
}
