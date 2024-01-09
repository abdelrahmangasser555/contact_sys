#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countLines();
userInfo creatingNewUser(int id, string name, string phoneNumber, string email, string address);
void addingUsertoFile(userInfo user);
void readingAllUsers();
void readingUserById(int id);
void readingUserByName(string name);
void sortUsersByName();

int counter = countLines();
struct userInfo
{
  int id;
  string name;
  string phoneNumber;
  string email;
  string address;
};

struct userAddress
{
  string street;
  string city;
  string state;
  string postalCode;
};

int countLines()
{

  ifstream file("users01.txt");
  string line;
  int lastId = 0;
  if (!file.is_open())
  {
    cout << "error opening the file ";
    return 0;
  }
  while (getline(file, line))
  {
    lastId++;
  }
  file.close();
  return lastId;
}

userInfo readingContactFromConsole()
{
  int id;
  string name, phoneNumber, email, address;

  cout << "Enter the user ID: ";
  cin >> id;

  // Clearing the input buffer to avoid issues with getline after cin
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter the name: ";
  getline(cin, name);

  cout << "Enter the phone number: ";
  getline(cin, phoneNumber);

  cout << "Enter the email: ";
  getline(cin, email);

  cout << "Enter the address: ";
  getline(cin, address);
  creatingNewUser(id, name, phoneNumber, email, address);
}

userInfo creatingNewUser(int id, string name, string phoneNumber, string email, string address)
{
  userInfo tempUser;
  tempUser.id = counter + 1;
  tempUser.name = name;
  tempUser.phoneNumber = phoneNumber;
  tempUser.email = email;
  tempUser.address = address;
  counter++;
  addingUsertoFile(tempUser);
  return tempUser;
}

void addingUsertoFile(userInfo user)
{
  ofstream userFileOutput("users01.txt", ios::app);
  if (!userFileOutput.is_open())
  {
    cout << "the file could not be opened while adding a new user  \n";
    return;
  }
  userFileOutput << user.id << ", " << user.name << ", " << user.phoneNumber << ", " << user.email << ", " << user.address << "\n";
  userFileOutput.close();
}

void readingAllUsers()
{

  ifstream userInputFile("users01.txt");
  if (!userInputFile.is_open())
  {
    cout << "the file could not be opened while reading the users  \n";
    return;
  }
  string line;
  while (getline(userInputFile, line))
  {
    cout << line << "\n";
  }
  userInputFile.close();
}

void readingUserById(int id)
{
  ifstream userInputFile("users01.txt");
  if (!userInputFile.is_open())
  {
    cout << "the file could not be opened while reading the users  \n";
    return;
  }
  string line;
  while (getline(userInputFile, line))
  {
    if (line.find(to_string(id)) != string::npos)
    {
      cout << line << "\n";
    }
  }
  userInputFile.close();
}

void readingUserByName(string name)
{
  ifstream userInputFile("users01.txt");
  if (!userInputFile.is_open())
  {
    cout << "the file could not be opened while reading the users  \n";
    return;
  }
  string line;
  while (getline(userInputFile, line))
  {
    if (line.find(name) != string::npos)
    {
      // output the user id only
      cout << line.substr(0, line.find(",")) << "\n";
    }
  }
  userInputFile.close();
}

void sortUsersByName()
{
  ifstream userInputFile("users01.txt");
  if (!userInputFile.is_open())
  {
    cout << "the file could not be opened while reading the users  \n";
    return;
  }
  string line;
  vector<string> users;
  while (getline(userInputFile, line))
  {
    users.push_back(line);
  }
  sort(users.begin(), users.end());
  for (int i = 0; i < users.size(); i++)
  {
    cout << users[i] << "\n";
  }
  userInputFile.close();
}
int main()
{

  cout << "Enter the number of users you want to add: ";
  int numberOfUsers;
  cin >> numberOfUsers;
  for (int i = 0; i < numberOfUsers; i++)
  {
    readingContactFromConsole();
  }
  cout << "Current users in the system:" << endl;
  readingAllUsers();

  cout << "the number of lines are " << countLines();
  return 0;
}
