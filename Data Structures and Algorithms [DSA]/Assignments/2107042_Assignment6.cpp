#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

template <typename E>
class BinaryTree {
public:
    E value;
    BinaryTree<E>* left;
    BinaryTree<E>* right;
    BinaryTree<E>* parent;

    // Constructors
    BinaryTree() : value(), left(nullptr), right(nullptr), parent(nullptr) {}
    BinaryTree(E value) : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
    BinaryTree(E value, BinaryTree<E>* left, BinaryTree<E>* right)
        : value(value), left(left), right(right), parent(nullptr) {}

    // Public methods
    int height() const {
        if (!this) {
            return 0;
        }
        int leftHeight = (left) ? left->height() : 0;
        int rightHeight = (right) ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }

    void setLeft(BinaryTree<E>* newLeft) {
        left = newLeft;
        if (newLeft) {
            newLeft->setParent(this);
        }
    }

    void setParent(BinaryTree<E>* newParent) {
        parent = newParent;
    }

    void setRight(BinaryTree<E>* newRight) {
        right = newRight;
        if (newRight) {
            newRight->setParent(this);
        }
    }

    void setValue(E newValue) {
        value = newValue;
    }

    // Inorder Iterator
    class InorderIterator {
    private:
        stack<BinaryTree<E>*> stack;

        void pushLeftChildren(BinaryTree<E>* node) {
            while (node) {
                stack.push(node);
                node = node->left;
            }
        }

    public:
        InorderIterator(BinaryTree<E>* root) {
            pushLeftChildren(root);
        }

        bool hasNext() const {
            return !stack.empty();
        }

        E next() {
            if (!hasNext()) {
                throw out_of_range("No more elements");
            }

            BinaryTree<E>* current = stack.top();
            stack.pop();

            pushLeftChildren(current->right);

            return current->value;
        }
    };

    InorderIterator inorderIterator() {
        return InorderIterator(this);
    }

	// Postorder Iterator
	class PostorderIterator {
	private:
	    stack<pair<BinaryTree<E>*, bool>> stack;
	    vector<E> result;  // Store the result during iteration

	public:
	    PostorderIterator(BinaryTree<E>* root) {
	        if (root) {
	            stack.push({root, false});
	            while (!stack.empty()) {
	                auto current = stack.top().first;
	                bool visited = stack.top().second;
	                stack.pop();

	                if (visited) {
	                    // If the node is visited, add it to the result
	                    result.push_back(current->value);
	                } else {
	                    // If the node is not visited, re-push it with visited as true
	                    stack.push({current, true});
	                    
	                    // Push right child if it exists
	                    if (current->right) {
	                        stack.push({current->right, false});
	                    }

	                    // Push left child if it exists
	                    if (current->left) {
	                        stack.push({current->left, false});
	                    }
	                }
	            }
	        }
	    }

	    bool hasNext() const {
	        return !result.empty();
	    }

	    E next() {
	        if (!hasNext()) {
	            throw out_of_range("No more elements");
	        }

	        E value = result.back();
	        result.pop_back();
	        return value;
	    }
	};

    PostorderIterator postorderIterator() {
        return PostorderIterator(this);
    }

    // Preorder Iterator
    class PreorderIterator {
    private:
        stack<BinaryTree<E>*> stack;

    public:
        PreorderIterator(BinaryTree<E>* root) {
            if (root) {
                stack.push(root);
            }
        }

        bool hasNext() const {
            return !stack.empty();
        }

        E next() {
            if (!hasNext()) {
                throw out_of_range("No more elements");
            }

            BinaryTree<E>* current = stack.top();
            stack.pop();

            if (current->right) {
                stack.push(current->right);
            }
            if (current->left) {
                stack.push(current->left);
            }

            return current->value;
        }
    };

    PreorderIterator preorderIterator() {
        return PreorderIterator(this);
    }

    // Check if the tree is balanced
    bool isBalanced() const {
        if (!this) {
            return true;
        }

        int leftHeight = (left) ? left->height() : 0;
        int rightHeight = (right) ? right->height() : 0;

        return abs(leftHeight - rightHeight) <= 1 &&
               left && right &&
               left->isBalanced() &&
               right->isBalanced();
    }

    // Check if the tree is complete
    bool isComplete() const {
        if (!this) {
            return true;
        }

        queue<const BinaryTree<E>*> q;
        q.push(this);

        bool nonFullNodeFound = false;

        while (!q.empty()) {
            const BinaryTree<E>* current = q.front();
            q.pop();

            if (!current) {
                nonFullNodeFound = true;
            } else {
                if (nonFullNodeFound) {
                    return false; // A non-full node after a full node indicates incompleteness
                }

                q.push(current->left);
                q.push(current->right);
            }
        }

        return true;
    }

    // Check if the tree is full
    bool isFull() const {
        if (!this) {
            return true;
        }

        if ((left && !right) || (!left && right)) {
            return false;
        }

        return left && left->isFull() && right && right->isFull();
    }

    // Check if the tree is a Binary Search Tree
    bool isBinarySearchTree(E min = std::numeric_limits<E>::min(),
                             E max = std::numeric_limits<E>::max()) const {
        if (!this) {
            return true;
        }

        return (value > min && value < max) &&
               left && left->isBinarySearchTree(min, value) &&
               right && right->isBinarySearchTree(value, max);
    }

    // Balance the tree
    BinaryTree<E>* balanceTree() {
        vector<E> sortedValues;
        inorderTraversal(this, sortedValues);

        return balanceTreeHelper(sortedValues, 0, sortedValues.size() - 1);
    }

private:
    // Helper method for inorder traversal
    void inorderTraversal(const BinaryTree<E>* root, vector<E>& values) const {
        if (root) {
            inorderTraversal(root->left, values);
            values.push_back(root->value);
            inorderTraversal(root->right, values);
        }
    }

    // Helper method for balancing the tree
    BinaryTree<E>* balanceTreeHelper(const vector<E>& sortedValues, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        BinaryTree<E>* newNode = new BinaryTree<E>(sortedValues[mid]);

        newNode->left = balanceTreeHelper(sortedValues, start, mid - 1);
        if (newNode->left) {
            newNode->left->parent = newNode;
        }

        newNode->right = balanceTreeHelper(sortedValues, mid + 1, end);
        if (newNode->right) {
            newNode->right->parent = newNode;
        }

        return newNode;
    }
};

int main() 
{
    BinaryTree<int> tree(1);

    // Adding nodes to the tree
    tree.setLeft(new BinaryTree<int>(2));
    tree.setRight(new BinaryTree<int>(3));
    tree.left->setLeft(new BinaryTree<int>(4)); 
	tree.left->setRight(new BinaryTree<int>(5));    
	tree.right->setLeft(new BinaryTree<int>(6));    
	tree.right->setRight(new BinaryTree<int>(7));

    // Inorder traversal
    cout << "Inorder Traversal: ";
    BinaryTree<int>::InorderIterator inorderIterator = tree.inorderIterator();
    while (inorderIterator.hasNext()) {
        cout << inorderIterator.next() << " ";
    }
    cout << endl;

    // Preorder traversal
    cout << "Preorder Traversal: ";
    BinaryTree<int>::PreorderIterator preorderIterator = tree.preorderIterator();
    while (preorderIterator.hasNext()) {
        cout << preorderIterator.next() << " ";
    }
    cout << endl;

    // Postorder traversal
    cout << "Postorder Traversal: ";
    BinaryTree<int>::PostorderIterator postorderIterator = tree.postorderIterator();
    while (postorderIterator.hasNext()) {
        cout << postorderIterator.next() << " ";
    }
    cout << endl;

    // Height of the tree
    cout << "Height of the Tree: " << tree.height() << endl;

    // Checking if the tree is full
    cout << "Is Full: " << boolalpha << tree.isFull() << endl;

    // Checking if the tree is balanced
    cout << "Is Balanced: " << boolalpha << tree.isBalanced() << endl;

    // Checking if the tree is a Binary Search Tree
    cout << "Is Binary Search Tree: " << boolalpha << tree.isBinarySearchTree() << endl;

    // Checking if the tree is complete
    cout << "Is Complete: " << boolalpha << tree.isComplete() << endl;

    // Balancing the tree
    BinaryTree<int>* balancedTree = tree.balanceTree();

    // Inorder traversal of the balanced tree
    cout << "Inorder Traversal of Balanced Tree: ";
    BinaryTree<int>::InorderIterator balancedIterator = balancedTree->inorderIterator();
    while (balancedIterator.hasNext()) {
        cout << balancedIterator.next() << " ";
    }
    cout << endl;

    // More Testing:

    // Adding more nodes for testing
    tree.left->left->setLeft(new BinaryTree<int>(8)); 
	tree.left->left->setRight(new BinaryTree<int>(9));   
	tree.right->right->setLeft(new BinaryTree<int>(10)); 
	tree.right->right->setRight(new BinaryTree<int>(11));

    // Inorder traversal after adding more nodes
    cout << "Inorder Traversal (After Adding More Nodes): ";
    inorderIterator = tree.inorderIterator();
    while (inorderIterator.hasNext()) {
        cout << inorderIterator.next() << " ";
    }
    cout << endl;

    // Height of the tree after adding more nodes
    cout << "Height of the Tree (After Adding More Nodes): " << tree.height() << endl;

    // Checking if the tree is full after adding more nodes
    cout << "Is Full (After Adding More Nodes): " << boolalpha << tree.isFull() << endl;

    // Checking if the tree is balanced after adding more nodes
    cout << "Is Balanced (After Adding More Nodes): " << boolalpha << tree.isBalanced() << endl;

    // Checking if the tree is a Binary Search Tree after adding more nodes
    cout << "Is Binary Search Tree (After Adding More Nodes): " << boolalpha << tree.isBinarySearchTree() << endl;

    // Checking if the tree is complete after adding more nodes
    cout << "Is Complete (After Adding More Nodes): " << boolalpha << tree.isComplete() << endl;

    // Balancing the tree after adding more nodes
    BinaryTree<int>* balancedTree2 = tree.balanceTree();

    // Inorder traversal of the second balanced tree
    cout << "Inorder Traversal of Second Balanced Tree: ";
    balancedIterator = balancedTree2->inorderIterator();
    while (balancedIterator.hasNext()) {
        cout << balancedIterator.next() << " ";
    }
    cout << endl;

    // Cleanup memory
    delete balancedTree;
    delete balancedTree2;

    return 0;
}
