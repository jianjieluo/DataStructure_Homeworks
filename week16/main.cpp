#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "dataHelper.hpp"
using namespace std;
#define MAX 29

struct Node {
  string name;
  string sex;
  string id;
  string phone;

  Node(string _n = "", string _s = "", string _i = "", string _p = "")
      : name(_n), sex(_s), id(_i), phone(_p) {}
  void showInfo() {
    cout << "-------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Sex: " << sex << endl;
    cout << "Id: " << id << endl;
    cout << "Phone: " << phone << endl;
    cout << "-------------------" << endl;
  }
};

list<Node> hash_table[MAX];

int hash_fun(string t_name) {
  int key = 0;
  for (unsigned int i = 0; i < t_name.size(); ++i) {
    if (t_name[i] > 'a' && t_name[i] < 'z') {
      key += (t_name[i] - 'a');
    } else if (t_name[i] > 'A' && t_name[i] < 'Z') {
      key += (t_name[i] - 'A');
    }
  }
  return key % MAX;
}

void insertPerson(const Node& person) {
  try {
    auto key = hash_fun(person.name);
    int flag = true;
    for (auto iter = hash_table[key].begin(); iter != hash_table[key].end();
         ++iter) {
      if (person.name == iter->name) {
        flag = false;
        break;
      }
    }
    if (flag) {
      hash_table[key].push_back(person);
      cout << "insert successfully" << endl;
    } else {
      cout << "name conflict" << endl;
    }
  } catch (...) {
    cout << "insert error" << endl;
  }
}

void createHashTable() {
  auto helper = new dataHelper("./info.csv");
  auto persons = helper->getData();
  for (auto& person : persons) {
    auto info = helper->splitEachInfo(person);
    try {
      //   Node node = {info[0], info[1], info[2], info[3]};
      //   insertPerson(node);
      insertPerson(Node{info[0], info[1], info[2], info[3]});
    } catch (...) {
      cout << "initialize wrong" << endl;
    }
  }
  cout << "finish create hash table from the data file" << endl;
  delete helper;
}

void clearHashTable() {
  auto helper = new dataHelper("./info.csv");
  vector<string> table;
  vector<string> v_personInfo;
  for (int i = 0; i < MAX; ++i) {
    for (auto iter = hash_table[i].begin(); iter != hash_table[i].end();
         ++iter) {
      v_personInfo.clear();
      v_personInfo.push_back(iter->name);
      v_personInfo.push_back(iter->sex);
      v_personInfo.push_back(iter->id);
      v_personInfo.push_back(iter->phone);
      auto s_personInfo = helper->joinEachInfo(v_personInfo);
      table.push_back(s_personInfo);
    }
  }
  helper->writeData(table);
  delete helper;
  cout << "clear the Hash Table" << endl;
}

void displayHashTable() {
  for (int i = 0; i < MAX; ++i) {
    cout << i << "#";
    if (hash_table[i].empty()) {
      cout << "NULL" << endl;
    } else {
      for (auto iter = hash_table[i].begin(); iter != hash_table[i].end();
           ++iter) {
        if (iter != hash_table[i].begin()) {
          cout << " -> ";
        }
        cout << iter->name;
      }
      cout << endl;
    }
  }
}

void searchPerson(const string t_name) {
  int key = hash_fun(t_name);
  for (auto iter = hash_table[key].begin(); iter != hash_table[key].end();
       ++iter) {
    if (t_name == iter->name) {
      iter->showInfo();
      return;
    }
  }
  cout << "no such a person" << endl;
}

void removePerson(const string t_name) {
  auto key = hash_fun(t_name);
  hash_table[key].remove_if(
      [t_name](const Node& person) -> bool { return t_name == person.name; });
}

void help() {
  cout << "---------------------" << endl;
  cout << "h -> help" << endl;
  cout << "d -> display the hash table" << endl;
  cout << "s -> search a person" << endl;
  cout << "i -> insert a person" << endl;
  cout << "r -> remove a person" << endl;
  cout << "EOF -> quit the system" << endl;
  cout << "---------------------" << endl;
}

int main() {
  createHashTable();
  help();
  char ch;
  string t_name;
  Node node;
  cout << "input a command" << endl;
  while (cin >> ch) {
    switch (ch) {
      case 'h':
        system("clear");
        help();
        break;
      case 'd':
        displayHashTable();
        break;
      case 's':
        cout << "input the name" << endl;
        cin >> t_name;
        searchPerson(t_name);
        break;
      case 'r':
        cout << "input the name" << endl;
        cin >> t_name;
        removePerson(t_name);
        break;
      case 'i':
        cout << "input name,sex,id,phone" << endl;
        cin >> node.name >> node.sex >> node.id >> node.phone;
        insertPerson(node);
        break;
      default:
        cout << "Invalid input" << endl;
        break;
    }
    cout << "input a command" << endl;
  }
  clearHashTable();
  return 0;
}
