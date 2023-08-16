#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
 private:
  Node* root;

  // pointers are basically addresses.

  // -------------------------Insert node----------------------

  void insertToNode(Node** root, int data) {
    if (*root == nullptr) {
      *root = new Node(data);
      return;
    }
    if (data < (*root)->data) {
      insertToNode(&(*root)->left, data);
    } else {
      insertToNode(&(*root)->right, data);
    }
  }

  //-------------------------Inorder Traversal----------------

  void inorderTraversal(Node* root) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
  }

  //-------------------------Horizontal tree Inorder Traversal-----------------
  void showHorizontal(Node* root, int spaces) {
    if (root == nullptr) return;
    showHorizontal(root->left, spaces + 7);
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << "|" << root->data << "|\n";
    showHorizontal(root->right, spaces + 7);
  }

  // -------------------------------Height of a tree-------------------------

  int heightFromNode(Node* root) {
    const int EMPTY_TREE_HEIGHT = 0;
    if (root == nullptr) {
      return EMPTY_TREE_HEIGHT;
    }
    int heightOfLeft = heightFromNode(root->left);
    int heightOfRight = heightFromNode(root->right);
    return max(heightOfLeft, heightOfRight) + 1;
  }

  //-------------------------------Diameter of tree---------------------------

  int diameter(Node* root) {
    const int EMPTY_TREE_DIAMETER = 0;
    if (root == nullptr) {
      return EMPTY_TREE_DIAMETER;
    }
    // diameter = max of diameter in left subtree ,right subtree , longest path
    // passing from this node. longest path passing from this node = height of
    // left subtree , and height of right subtree +1

    int dLeft = diameter(root->left);
    int dRight = diameter(root->right);
    int length = heightFromNode(root->left) + heightFromNode(root->right) + 1;
    return max(dLeft, max(dRight, length));
  }

  //-------Diameter without utilizing separate height function------------

  pair<int, int> diameterWithoutHeight(Node* root) {
    const pair<int, int> EMPTY_TREE_HEIGHT_DIAM = {0, 0};
    if (root == nullptr) return {0, 0};
    pair<int, int> leftInfo = diameterWithoutHeight(root->left);
    pair<int, int> rightInfo = diameterWithoutHeight(root->right);

    int height = max(leftInfo.first, rightInfo.first) + 1;
    int longestPathThroughRoot = leftInfo.first + rightInfo.first + 1;
    int diameter =
        max(longestPathThroughRoot, max(leftInfo.second, rightInfo.second));

    return {height, diameter};
  }

  //----------------------level order----------------------------------------

  void levelOrder() {
    if (this->root == nullptr) {
      cout << "The tree is empty\n";
      return;
    }

    queue<Node*> q;
    int height = this->height();
    q.push(this->root);
    int currLevel = 1;

    while (!q.empty()) {
      int levelSize = q.size();
      cout << "The nodes at level " << currLevel << " are:\n";
      for (int i = 0; i < levelSize; i++) {
        Node* top = q.front();
        q.pop();

        if (top == nullptr)
          cout << " -1 ";
        else
          cout << "|" << top->data << "|  ";

        if (top->left != nullptr) q.push(top->left);

        if (top->right != nullptr) q.push(top->right);
      }
      cout << "\n\n";
      currLevel++;
    }
  }

  //=============PUBLIC==========================

 public:
  Tree() : root(nullptr) {}
  void insert(int data) { this->insertToNode(&this->root, data); }
  void inorder() { this->inorderTraversal(this->root); }
  void showHorizontal() {
    cout << "The horizontal view of this is:\n\n";
    this->showHorizontal(this->root, 10);
    cout << "\n\n";
  }
  void leveOrder() {
    cout << "\n\n ------ The LEVEL ORDER -----> \n\n";
    this->levelOrder();
    cout << "\n\n";
  }
  int height() { return this->heightFromNode(this->root); }
  int diameter() { return this->diameter(this->root); }
  int diameterWithoutHeight() {
    return this->diameterWithoutHeight(this->root).second;
  }
};

int main() {
  Tree t;
  t.insert(5);
  t.insert(12);
  t.insert(2);
  t.insert(3);
  t.insert(1);
  t.insert(7);
  t.insert(13);
  t.inorder();
  cout << "\n";
  t.showHorizontal();
  cout << t.diameter() << '\n';
  cout << t.diameterWithoutHeight() << '\n';
  t.leveOrder();
  return 0;
}
