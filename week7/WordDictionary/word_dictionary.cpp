/*
Word Dictionary:
Implement a word dictionary which
supports the following operations:
insert - O(word_len)
contains - O(word_len); print! true/false
word_len e [1; 10]

Input:
The first line reads:
N - the number of commands that follow; [1; 100000]
Each of the other N lines contains
a command in the form:
insert <word>
contains <word>

Output:
Output the result of the contains command
on separate lines
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
using namespace std;

vector<pair<string, string>> load_commands(const int N) {
  vector<pair<string, string>> commands;
  string command;
  string word;
  for (int i = 0; i < N; i++) {
    getline(cin, command, ' ');
    getline(cin, word);
    commands.push_back(pair<string, string>(command, word));
  }
  return commands;
}

struct Node;

struct Edge {
  Node *target;
  char value;
};

struct Node {
  Edge letters[26];
  bool word = false;
};

class Trie {
public:
  Trie() {
    root = NULL;
  }

  void insert(string word) {
    Node *current = root;
    for (int i = 0; i < word.size(); i++) {
      cout << i << endl;
      int letter_index = word[i] - 'a';
      if (current == NULL && i != word.size() - 1) {
        Node newNode;
        current = &newNode;
        Edge letter;
        letter.value = word[i];
        letter.target = NULL;
        current->letters[letter_index] = letter;
      } else if (current != NULL && current->letters[letter_index].value != word[i]) {
        Edge letter;
        letter.value = word[i];
        letter.target = NULL;
        current->letters[letter_index] = letter;
      }
      //if (i == word.size() - 1) {
        //current->word = true;
      //}
      cout << "is null the current node " << (current == NULL) << endl;
      //cout << "end " << current->word << endl;
      current = current->letters[letter_index].target;
    }
    cout << "HERE" << endl;
    Node newNode;
    current->word = true;
    cout << "end " << current->word << endl;
        cout << "HERE" << endl;
  }

  bool contains(string word) {
    Node *current = root;
    bool contained = true;
    for (int i = 0; i < word.size(); i++) {
      int letter_index = word[i] - 'a';
      cout << (current == NULL) << endl;
      if (current == NULL) {
        contained = false;
          break;
      }
      char lookAt = current->letters[letter_index].value;
        if (lookAt != word[i]) {
          contained = false;
          break;
        }

      cout << "Zoidberg" << endl;
      current = current->letters[letter_index].target;
    }
    if (current->word != true) {
      contained = false;
    }
    return contained;
  }

private:
  Node *root;
};

vector<string> execute(const vector<pair<string, string>>& commands) {
  Trie container;
  vector<string> result;
  string command, word;
  for (int i = 0; i < commands.size(); i++) {
    command = commands[i].first;
    word = commands[i].second;
    if (command == "insert") {
      container.insert(word);
    } else {
      bool successful = container.contains(word);
      string output = (successful) ? "true" : "false";
      result.push_back(output);
    }
  }
  return result;
}

void show(const vector<string>& result) {
  if (result.size() > 0) {
    for (int i = 0; i < result.size() - 1; i++) {
      cout << result[i] << "\n";
    }
    cout << result[result.size() - 1];
  }
}

void view(vector<pair<string, string>>& data) {
    for (int i = 0; i < data.size(); i++) {
        cout << "(" << data[i].first << ", " << data[i].second << ") ";
    }
}

int main() {
  string number;
  getline(cin, number);
  int N = stoi(number);

  vector<pair<string, string>> commands = load_commands(N);
  vector<string> result = execute(commands);
  cout << "here dude";

  show(result);

  cin.get();
  return 0;
}
