#include <iostream>
#include <time.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Remove a value from the BST
    void remove(int value) {
        root = remove(root, value);
    }



    // In-order traversal to print the contents of the BST
    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << endl;
    }

    // Find a node with the specified data
    TreeNode* findNode(int value) {
        return findNode(root, value);
    }
    //jc - moved above private
     // Recursive helper function to find the maximum node in the BST
    //jc removed the parameter as you can use root from the bst
    int  findMax() {
        TreeNode* node = root;
        while (node && node->right) {
            node = node->right;
        }
        return node->data;
    }


private:
    TreeNode* root;

    // Recursive helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Recursive helper function to remove a value from the BST
    TreeNode* remove(TreeNode* node, int value) {
        if (!node) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            // Found the node to be removed
            if (!node->left && !node->right) {

                delete node;
                return nullptr;
            }
            else if (!node->left) {
                // Only right child
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                // Only left child
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            else {
                //Two children
                // Find the in-order successor (smallest in the right subtree)
                TreeNode* successor = findMin(node->right);
                node->data = successor->data;
                // Remove the in-order successor
                node->right = remove(node->right, successor->data);
            }
        }
        return node;
    }

    // Recursive helper function to find the in-order successor
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Recursive helper function to find the maximum node in the BST
    TreeNode* findMax(TreeNode* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    // Recursive helper function to perform in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Recursive helper function to find a node with the specified data
    TreeNode* findNode(TreeNode* node, int value) {
        if (!node) {
            return nullptr;
        }

        if (value < node->data) {
            return findNode(node->left, value);
        }
        else if (value > node->data) {
            return findNode(node->right, value);
        }
        else {
            return node;
        }
    }
};

int main() {
    int random;
    TreeNode* root;

    BinarySearchTree bst;
    clock_t start, end;
    start = clock();

    for (int i = 0; i < 100; i++)
    {

        random = 1 + rand() % 100;

        cout << "inserting" << random << endl;

        bst.insert(random);

    }
    end = clock();
    cout << "time" << (end - start) << endl;

    bst.insert(20);
    bst.insert(15);
    bst.insert(25);
    bst.insert(10);
    bst.insert(5);
    bst.insert(30);


    //jc added these to call max
    start = clock();
    int maxValue = bst.findMax();
    cout << "max value =  " << maxValue<<endl;
    end = clock();
    cout << "time" << (end - start) << endl;

    // In-order traversal of the BST
    start = clock();
   
    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    end = clock();
    cout << "time" << (end - start) << endl;


    // Find a node with a specific value
    start = clock();
   
    int searchValue = 15;
    TreeNode* foundNode = bst.findNode(searchValue);
    if (foundNode) {
        cout << "Node with value " << searchValue << " found in the BST.\n";
    }
    else {
        cout << "Node with value " << searchValue << " not found in the BST.\n";
    }
    end = clock();
    cout << "time" << (end - start) << endl;

   // Remove a value from the BST
    start = clock();
 
    int removeValue = 15;
    bst.remove(removeValue);
    cout << "In-order traversal after removing value " << removeValue << ": ";
    bst.inOrderTraversal();
    end = clock();
    cout << "time" << (end - start) << endl;

    return 0;
}
