#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

/// ---------------------------------------------------------------------------------

class Tree {
 private:
  Node* root;
  Node* insertToNode(Node* node, int data) {
    // check if if belongs to the left subtree or the right subtree , and
    // accordingly call insert again on the corresponding subtree, a tree is
    // basically a node.

    if (node == nullptr) {
      return new Node(data);
    }
    if (data < node->data) {
      node->left = insertToNode(node->left, data);

    } else {
      node->right = insertToNode(node->right, data);
    }
    return node;

    // basically what you are saying is bhai if the node is null then make me
    // the node and return me to the parent.
    // similary now as the parent node has changed return it to its parent.
    // ....... finally reaching the root of tree .
  }

  //---- Print Inorder for Tree----------------

  void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << ",";
    printInorder(root->right);
  }

  //-----Print level order------------------------

  void printLevelOrder() {
    if (!this->root) return;

    queue<Node*> q;

    q.push(this->root);

    while (!q.empty()) {
      int levelSize = q.size();

      for (int i = 0; i < levelSize; ++i) {
        Node* current = q.front();
        q.pop();
        if (current == nullptr) {
          cout << "-1 ";
          continue;
        }
        cout << current->data << " ";

        if (current->left)
          q.push(current->left);
        else
          q.push(nullptr);
        if (current->right)
          q.push(current->right);
        else
          q.push(nullptr);
      }

      cout << endl;  // Print a newline after each level
    }
  }

  //------------Horizontal printing----------------------------

  void printLikeaTreeHorizontal(Node* root, int spaces) {
    if (root == nullptr) {
      // cout << "-1";
      return;
    }
    printLikeaTreeHorizontal(root->left, spaces + 6);
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << "|" << root->data << "|\n";
    printLikeaTreeHorizontal(root->right, spaces + 6);
  }

  //============Calculate Height====================================

  int height(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
  }

  //==========================Diameter===============================

  int diameter(Node* root) {
    if (root == nullptr) return 0;
    int leftSubtreeDiam = diameter(root->left);
    int rightSubtreeDiam = diameter(root->right);
    int diameter = height(root->left) + height(root->right) + 1;
    return max(diameter, max(rightSubtreeDiam, leftSubtreeDiam));
  }

  //=============public decralation of all functions=================

 public:
  Tree() { this->root = nullptr; }
  void insertNode(int data) {
    this->root = this->insertToNode(this->root, data);
  }
  void inorder() { this->printInorder(this->root); }
  void levelOrder() { this->printLevelOrder(); }
  void printLikeTreeHorizontal() {
    this->printLikeaTreeHorizontal(this->root, 1);
  };
  int height() { return this->height(this->root); }
  int diameter() { return this->diameter(this->root); }
};

int main() {
  Tree t;
  vector<int> arr = {35, 2, 235, 2, 6, 2, 6, 7, 1, 34, 11};
  for (auto& x : arr) {
    t.insertNode(x);
  }
  // t.inorder();
  cout << '\n';
  t.levelOrder();
  t.printLikeTreeHorizontal();
  cout << "\n" << t.height();
  cout << "\n" << t.diameter();
}