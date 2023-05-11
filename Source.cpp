#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinaryTree {
public:
    Node<T>* root;
    BinaryTree() {
        root = NULL;
    }
    void insert(T data) {
        try {
            Node<T>* node = new Node<T>(data);
            if (root == NULL) {
                root = node;
                return;
            }
            if (typeid(T) == typeid(int) && typeid(data) == typeid(char)) throw invalid_argument("Inpt Type does not match the Tree Type!");
            vector<Node<T>*> queue;
            queue.push_back(root);
            while (!queue.empty()) {
                Node<T>* front = queue.front();
                queue.erase(queue.begin());
                if (front->left == NULL) {
                    front->left = node;
                    break;
                }
                else {
                    queue.push_back(front->left);
                }
                if (front->right == NULL) {
                    front->right = node;
                    break;
                }
                else {
                    queue.push_back(front->right);
                }
            }
        }
        catch (const invalid_argument& e) {
            cerr << e.what() << endl;
        }
        catch (const std::bad_alloc&) {
            cerr << "Error: Memory allocation failed." << endl;
        }
        catch (...) {
            cerr << "We are so Fucked!! I don't Know What the fuck happened!" << endl;
        }
    }
    void preorder(Node<T>* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void inorder(Node<T>* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void postorder(Node<T>* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    void display(Node<T>* node, int level) {
        if (node == NULL) return;
        display(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        cout << "+---" << node->data << endl;
        display(node->left, level + 1);
    }
    template <typename U>
    void sort(vector<U>& v, Node<T>* node) {
        if (node == NULL) return;
        sort(v, node->left);
        v.push_back(node->data);
        sort(v, node->right);
        std::sort(v.begin(), v.end());
    }
    int height(Node<T>*);
    void deleteTree(Node<T>*);
    void deleteTree();
};
template <typename T>
int BinaryTree<T>::height(Node<T>* node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return 1 + max(left_height, right_height);
}
class InvalidTraversalString : public exception {
public:
    const char* what() const throw() {
        return "Invalid traversal string!";
    }
};
template <typename T>
bool checktree(BinaryTree<T>& tree, const string& traversal) {
    Node<T>* node = tree.root;
    for (char c : traversal) {
        if (c == 'L') {
            if (node->left == NULL) {
                throw InvalidTraversalString();
            }
            node = node->left;
        }
        else if (c == 'R') {
            if (node->right == NULL) {
                throw InvalidTraversalString();
            }
            node = node->right;
        }
        else {
            throw InvalidTraversalString();
        }
    }
    return false;
}
template <typename T>
void print_traversal(BinaryTree<T>& tree, const string& traversal) {
    if (checktree(tree, traversal))   return;
    int tree_height = tree.height(tree.root);
    if (traversal.size() > tree_height) {
        throw InvalidTraversalString();
    }
    Node<T>* node = tree.root;
    for (char c : traversal) {
        if (c == 'L') {
            if (node->left == NULL) {
                throw InvalidTraversalString();
            }
            cout << node->data << " ";
            node = node->left;
        }
        else if (c == 'R') {
            if (node->right == NULL) {
                throw InvalidTraversalString();
            }
            cout << node->data << " ";
            node = node->right;
        }
        else {
            throw InvalidTraversalString();
        }
    }
    cout << node->data << endl;
}
template <typename T>
void BinaryTree<T>::deleteTree(Node<T>* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
template <typename T>
void BinaryTree<T>::deleteTree() {
    deleteTree(root);
    root = NULL;
}
int main() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(2);
    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;
    cout << "\nDisplay:\n";
    tree.display(tree.root, 0);
    vector<int> v;
    tree.sort(v, tree.root);
    cout << "\nSorted array: ";
    for (int i : v) cout << i << " ";
    cout << endl;
    try {
        tree.insert('c');
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
    try {
        string traversal = "LLL";
        cout << "Traversal for " << traversal << ": ";
        print_traversal(tree, traversal);
    }
    catch (InvalidTraversalString& e) {
        cout << e.what() << endl;
    }
    BinaryTree<string> tree1;
    tree1.insert("A");
    tree1.insert("B");
    tree1.insert("C");
    tree1.insert("D");
    tree1.insert("E");
    tree1.insert("F");
    tree1.insert("G");
    tree1.insert("H");
    tree1.insert("I");
    cout << "Preorder traversal: ";
    tree1.preorder(tree1.root);
    cout << "\nInorder traversal: ";
    tree1.inorder(tree1.root);
    cout << "\nPostorder traversal: ";
    tree1.postorder(tree1.root);
    cout << "\n\nDisplay:\n";
    tree1.display(tree1.root, 0);
    vector<string> v1;
    tree1.sort(v1, tree1.root);
    cout << "Sorted array: ";
    for (string i : v1) cout << i << " ";
    cout << endl;
    try {
        string traversal = "RR";
        cout << "Traversal for " << traversal << ": ";
        print_traversal(tree1, traversal);
    }
    catch (InvalidTraversalString& e) {
        cout << e.what() << endl;
    }
    return 0;
}
