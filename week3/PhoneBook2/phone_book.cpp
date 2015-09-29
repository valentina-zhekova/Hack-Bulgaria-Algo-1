/*
Phone book:
Stores pairs of names and phone numbers and
provides the following operations:
insert [phone_number] [name] - inserts a record in the phone book
                               with a phone number and a name (no white space).
                               If the name already exists, updates
                               the phone number(digit-only str to max 9 chars)
lookup [name] - returns the phone number related to that name.
                If no such name is found, return "NOT FOUND!".
list - prints the records from the phone book sorted alphabetically by the name.
remove [name] (optional) - removes the record for a given name.
                           If the record does not exist, just ignore the command.

Input:
The first line of the input will contain a single integer:
N - the number of commands to execute; 1<=N<=50000
Each of the following N lines will contain
a single command in the format described above.

Output:
After each of the commands that requires output,
print the required output on the console.
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
  Node (Node* parent, string key, string value) {
    this->parent = parent;
    this->LChild = NULL;
    this->RChild = NULL;
    this->name = key;
    this->phoneNumber = value;
  }

  Node* parent;
  Node* LChild;
  Node* RChild;
  string name;
  string phoneNumber;
};

class PhoneBook {
 public:
  PhoneBook() {
    root = NULL;
  }

  void insert(string number, string name) {
    if (!root) {
      root = new Node(NULL, name, number);
    } else {
      Node* current = root;
      bool insertLeft = false;
      bool insertRight = false;
      while (!insertLeft && !insertRight) {
        if (current->name == name) {
          current->phoneNumber = number;
          break;
        } else if (current->name > name) {
          if (!current->LChild) {
            insertLeft = true;
          } else {
            current = current->LChild;
          }
        } else {
          if (!current->RChild) {
            insertRight = true;
          } else {
            current = current->RChild;
          }
        }
      }
      Node* temp = new Node(current, name, number);
      if (insertLeft) {
        current->LChild = temp;
      } else if (insertRight) {
        current->RChild = temp;
      }
    }
  }

  string lookup(string name) {
    string result = "NOT FOUND!";
    Node* target = search(name);
    if (target) {
      result = target->phoneNumber;
    }
    return result;
  }

  void list() {
    print(root);
  }

  void remove(string name) {
    Node* target = search(name);
    if (target) {
      deleteNode(target);
    }
  }

 private:
  void print(Node* current) {
    if (current->LChild) {
      print(current->LChild);
    }
    if (current) {
      cout << current->name << " " << current->phoneNumber << endl;
    }
    if (current->RChild) {
      print(current->RChild);
    }
  }

  Node* search(string name) {
    Node* current = root;
    if (current) {
      bool search = true;
      while(search) {
        if (name == current->name) {
          search = false;
        } else if (name < current->name) {
          if (current->LChild) {
            current = current->LChild;
          } else {
            current = NULL;
            search = false;
          }
        } else if (name > current->name) {
          if (current->RChild) {
            current = current->RChild;
          } else {
            current = NULL;
            search = false;
          }
        }
      }
    }
    return current;
  }

  void deleteNode(Node* target) {
    if (!target->LChild && !target->RChild) {
      if (target->parent) {
        if (target->parent->LChild == target) {
          target->parent->LChild = NULL;
        } else {
          target->parent->RChild = NULL;
        }
      }
      if (target == root) {
        root = NULL;
      }
      delete target;
    } else if (target->LChild && !target->RChild) {
      if (target->parent) {
        if (target->parent->LChild == target) {
          target->parent->LChild = target->LChild;
          target->parent->LChild->parent = target->parent;
        } else {
          target->parent->RChild = target->LChild;
          target->parent->RChild->parent = target->parent;
        }
      } else {
        target->LChild->parent = NULL;
        root = target->LChild;
      }
      delete target;
    } else if (target->RChild && !target->LChild) {
      if (target->parent) {
        if (target->parent->LChild == target) {
          target->parent->LChild = target->RChild;
          target->parent->LChild->parent = target->parent;
        } else {
          target->parent->RChild = target->RChild;
          target->parent->RChild->parent = target->parent;
        }
      } else {
        target->RChild->parent = NULL;
        root = target->RChild;
      }
      delete target;
    } else {
      Node* toSwap = NULL;
      if (target->LChild->RChild) {
        toSwap = target->LChild;
        while(toSwap->RChild) {
          toSwap = toSwap->RChild;
        }
      } else if (target->RChild->LChild) {
        toSwap = target->RChild;
        while(toSwap->LChild) {
          toSwap = toSwap->LChild;
        }
      } else {
        toSwap = target->LChild;
      }
      // swap:
      target->name = toSwap->name;
      target->phoneNumber = toSwap->phoneNumber;
      deleteNode(toSwap);
    }
  }

  Node* root;
};

int main() {
  string data;
  getline(cin, data);
  int N = stoi(data);

  string name;
  string phone_number;
  PhoneBook book;
  while (N > 0) {
    cin >> data;
    if (data == "insert") {
      cin >> phone_number;
      cin >> name;
      book.insert(phone_number, name);
    } else if (data == "lookup") {
      cin >> name;
      cout << book.lookup(name) << endl;
    } else if (data == "list") {
      book.list();
    } else if (data == "remove") {
      cin >> name;
      book.remove(name);
    }
    N --;
  }

  cin.get();
  return 0;
}
