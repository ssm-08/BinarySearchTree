#include <iostream>
#include <cstring>

using namespace std;

struct Node {

  int value;
  Node* left;
  Node* right;
  
};

bool search(Node* r, int n);
void insertion(Node*& r, int n);
void deletion(Node*& r);

int main() {

  Node* root = NULL;

  bool run = false;
  char input[99] = "";

  const char* SEARCH = "SEARCH";
  const char* INS = "INSERT";
  const char* DEL = "DELETE";
  const char* QUIT = "QUIT";
  
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;

    if (strcmp(input, SEARCH) == 0) {

    } else if (strcmp(input, INS) == 0) {

    } else if (strcmp(input, DEL) == 0) {

    } else if (strcmp(input, QUIT) == 0) {
      run = false;
    }
  }
}
