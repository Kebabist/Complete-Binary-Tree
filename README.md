# Complete-Binary-Tree

A generic, template-based implementation of a complete binary tree in C++. This project provides essential binary tree operations, such as insertion, traversals (preorder, inorder, postorder), display, sorting, height calculation, and custom traversal paths.

## Features

- **Template-Based:** Supports any data type (e.g., int, string).
- **Complete Binary Tree Insertion:** Maintains completeness during insertion.
- **Traversals:** Preorder, inorder, postorder, and custom path traversals (via strings like "LLR").
- **Display:** Visualizes the tree structure in the console.
- **Sorting:** Extracts and sorts all tree elements.
- **Height Calculation:** Computes the height of the tree.
- **Memory Management:** Clean deletion of the tree and its nodes.
- **Type Safety:** Throws exceptions if inserted types do not match the tree type.

## Usage Example

```cpp
#include "Source.cpp"

int main() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(2);

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);

    cout << "\nInorder traversal: ";
    tree.inorder(tree.root);

    cout << "\nPostorder traversal: ";
    tree.postorder(tree.root);

    cout << "\n\nDisplay:\n";
    tree.display(tree.root, 0);

    vector<int> v;
    tree.sort(v, tree.root);
    cout << "\nSorted array: ";
    for (int i : v) cout << i << " ";
    cout << endl;

    // String binary tree example
    BinaryTree<string> tree1;
    tree1.insert("A");
    tree1.insert("B");
    // ... add more elements as needed
}
```

## Custom Traversal

You can traverse the tree using a custom path string (e.g., "LLR" for left-left-right):

```cpp
print_traversal(tree, "LLR");
```

## Building

No external dependencies are required. Compile using any modern C++ compiler:

```sh
g++ -std=c++11 Source.cpp -o binary_tree
./binary_tree
```

## Error Handling

- Inserting an element of the wrong type throws an exception.
- Invalid traversal strings are caught and reported.

## License

This project is provided without a license. Add your own license as needed.
