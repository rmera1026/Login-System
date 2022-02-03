#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn(){
  string username, password, un, pw;

  cout << "Enter username: "; cin >> username;
  cout << "Enter password: "; cin >> password;

  ifstream read("data\\" + username + ".txt");
  getline(read, un);
  getline(read, pw);

  if(un == username && pw == password) {
    return true;
  } else return false;
}

int main() {
  int choice;
  string username, password;


  cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;

  if(choice == 1) {
    string username, password, confirmation;

    cout << "Enter your new username: "; cin >> username;
    cout << "Enter your new password: "; cin >> password;
    cout << "Confirm password: "; cin >> confirmation;

    if(password != confirmation) {
      cout << "Passwords do not match!";
      return 0;
    }

    ofstream file;

    file.open("data\\" + username + ".txt");
    file << username << endl << password;
    file.close();

    main();
  } else if(choice == 2) {
    bool status = IsLoggedIn();

    if (!status) {
      cout << "False Login!" << endl;
      system("PAUSE");
      return 0;
    } else {
        cout << "Successfully logged in";
        system("PAUSE");
        return 1;
    }
  }
}