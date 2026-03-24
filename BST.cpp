#include <iostream>
#include <cstring>

using namespace std;

// Tree node
struct Node {

  int value;
  Node* left;
  Node* right;
  
};

// Program functions
bool search(Node* c, int n);
void print(Node* c, int depth);
void insertion(Node*& r, Node* c, Node* p, Node* n, bool isLeft);
void deletion(Node*& r, Node* c, Node* p, int n, bool isLeft);

int main() {

  // Program variables
  Node* root = NULL;

  bool run = true;
  char input[99] = "";
  int num = 0;
  
  const char* SEARCH = "SEARCH";
  const char* INS = "INSERT";
  const char* DEL = "DELETE";
  const char* PRINT = "PRINT";
  const char* QUIT = "QUIT";

  // Command loop
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, SEARCH) == 0) { // Search value
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      if (search(root, num)) {
	cout << "In tree" << endl;
      } else {
	cout << "Not in tree" << endl;
      }
    } else if (strcmp(input, INS) == 0) { // Insert value
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      if (!search(root, num)) {
	Node* data = new Node{num, NULL, NULL};
	insertion(root, root, root, data, true);
      }
	  
    } else if (strcmp(input, DEL) == 0) { // Delete value
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      if (search(root, num)) {
	deletion(root, root, root, num, true);
      }
      
    } else if (strcmp(input, PRINT) == 0) { // Print tree
      if (root) {
	print(root, 0);
      }
    } else if (strcmp(input, QUIT) == 0) { // Quit
      run = false;
    }
  }
}

// Print values recursively
void print(Node* c, int depth) {

  Node* left = c->left;
  Node* right = c->right;

  if (right != NULL) {
    print(right, depth + 1);
  }
  
  for (int i = 0; i < depth; i++) {
    cout << "\t";
  }
  
  cout << c->value << endl;

  if (left != NULL) {
    print(left, depth + 1);
  }
}

// Search for value recursively
bool search(Node* c, int n) {

  if (c == NULL) {
    return false;
  } else {
    if (n < c->value) {
      return search(c->left, n);
    } else if (n > c->value) {
      return search(c->right, n);
    } else {
      return true;
    }
  }
}

// Insert node recursively
void insertion(Node*& r, Node* c, Node* p, Node* n, bool isLeft) {

  if (r == NULL) { // No root
    r = n;
  } else if (c == NULL) { // End of branch

    // Check the correct side
    if (isLeft) {
      p->left = n;
    } else {
      p->right = n;
    }
  } else if (n->value < c->value) { // Sorting
    insertion(r, c->left, c, n, true);
  } else if (n->value > c->value) { // Sorting
    insertion(r, c->right, c, n, false);
  }
}

// Delete node recursively for all cases
void deletion(Node*& r, Node* c, Node* p, int n, bool isLeft) {

  // Find node
  if (n < c->value) {
    deletion(r, c->left, c, n, true);
  } else if (n > c->value) {
    deletion(r, c->right, c, n, false);
  } else {

    Node* child = NULL;
    Node* parent = NULL;
    
    if (c->left != NULL && c->right != NULL) { // Two children

      // Find successor
      child = c->right;

      while (child->left != NULL) {
	parent = child;
	child = child->left;
      }

      // Swap and link subsequent nodes
      if (parent) {
	parent->left = child->right;
      }

      child->left = c->left;
      if (child != c->right) {
	child->right = c->right;
      }
      
    } else { // No child or one child
      
      if (c->left) {
	child = c->left;
      } else if (c->right) {
	child = c->right;
      }
    }

    // Link child in tree and delete given node
    
    if (c == r) {
      r = child;
    } else if (isLeft) {
      p->left = child;
    } else {
      p->right = child;
    }
      delete c;
  }
}
