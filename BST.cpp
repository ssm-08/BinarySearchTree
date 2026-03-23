#include <iostream>
#include <cstring>

using namespace std;

struct Node {

  int value;
  Node* left;
  Node* right;
  
};

bool search(Node* c, int n);
void print(Node* c, int depth);
void insertion(Node*& r, Node* c, Node* p, Node* n, bool isLeft);
void deletion(Node*& r, Node* p, int n);

int main() {

  Node* root = NULL;

  bool run = true;
  char input[99] = "";
  int num = 0;
  
  const char* SEARCH = "SEARCH";
  const char* INS = "INSERT";
  const char* DEL = "DELETE";
  const char* PRINT = "PRINT";
  const char* QUIT = "QUIT";
  
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, SEARCH) == 0) {
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      if (search(root, num)) {
	cout << "In tree" << endl;
      } else {
	cout << "Not in tree" << endl;
      }
    } else if (strcmp(input, INS) == 0) {
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      Node* data = new Node{num, NULL, NULL};
      insertion(root, root, root, data, true);
      
    } else if (strcmp(input, DEL) == 0) {

    } else if (strcmp(input, PRINT) == 0) {
      print(root, 0);
    } else if (strcmp(input, QUIT) == 0) {
      run = false;
    }
  }
}

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

void insertion(Node*& r, Node* c, Node* p, Node* n, bool isLeft) {

  if (r == NULL) { // No root
    r = n;
  } else if (c == NULL) { // End of branch

    // Check the correct end
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
