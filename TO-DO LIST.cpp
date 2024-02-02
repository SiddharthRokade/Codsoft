#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
  string description;
  bool completed;
};


class ToDoList {
  private:
    vector<Task> tasks; 
  public:
  
    void addTask(string description) {
      Task newTask; 
      newTask.description = description; 
      newTask.completed = false; 
      tasks.push_back(newTask); 
      cout << "Task added: " << description << endl; 
    }

    
    void viewTasks() {
      cout << "Tasks in the list: " << endl;
      for (int i = 0; i < tasks.size(); i++) { 
        cout << i + 1 << ". " << tasks[i].description; 
        if (tasks[i].completed) { 
          cout << " (completed)" << endl;
        }
        else {
          cout << " (pending)" << endl;
        }
      }
    }

    
    void markTask(int index) {
      if (index >= 1 && index <= tasks.size()) { 
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl; 
      }
      else {
        cout << "Invalid task index." << endl;
      }
    }

    
    void removeTask(int index) {
      if (index >= 1 && index <= tasks.size()) { 
        cout << "Task removed: " << tasks[index - 1].description << endl; 
        tasks.erase(tasks.begin() + index - 1);
      }
      else {
        cout << "Invalid task index." << endl; 
      }
    }
};


void displayMenu() {
  cout << "Choose an option:" << endl;
  cout << "1. Add a task" << endl;
  cout << "2. View tasks" << endl;
  cout << "3. Mark a task as completed" << endl;
  cout << "4. Remove a task" << endl;
  cout << "5. Exit" << endl;
}


int main() {
  ToDoList list; 
  int option; 
  string description; 
  int index; 
  bool exit = false; 
  while (!exit) { 
    displayMenu(); 
    cin >> option; 
    switch (option) { 
      case 1: 
        cout << "Enter the task description: " << endl;
        cin.ignore(); 
        getline(cin, description); 
        list.addTask(description); 
        break;
      case 2: 
        list.viewTasks(); 
        break;
      case 3: 
        cout << "Enter the task index: " << endl;
        cin >> index; 
        list.markTask(index); 
        break;
      case 4: 
        cout << "Enter the task index: " << endl;
        cin >> index; 
        list.removeTask(index); 
        break;
      case 5:
        cout << "Thank you for using the to-do list manager." << endl;
        exit = true; 
        break;
      default: 
        cout << "Invalid option. Please try again." << endl;
        break;
    }
  }
  return 0;
}