#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
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

struct profiles{
    string profileName ;
    vector<int> contactIds ;
    int filledSize ;
};

int countLines();
userInfo creatingNewUser( string name, string phoneNumber, string email, string address);
void addingUsertoFile(userInfo user);
void readingAllUsers();
void readingUserById(int id);
void readingUserByName(string name);
void sortUsersByName();

int counter = countLines();




int countLines()
{

  ifstream file("users01.txt");
  string line;
  int lastId = 0;
  if (!file.is_open())
  {
    lastId =0 ;
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
  string name, phoneNumber, email, address;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter the name: ";
  getline(cin, name);

  cout << "Enter the phone number: ";
  getline(cin, phoneNumber);

  cout << "Enter the email: ";
  getline(cin, email);

  cout << "Enter the address: ";
  getline(cin, address);

  return creatingNewUser(name, phoneNumber, email, address);
}


userInfo creatingNewUser( string name, string phoneNumber, string email, string address)
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
    string lineStart = line.substr(0, 10);

    if (lineStart.find(to_string(id)) != string::npos)
    {
      cout << line << "\n";
      return;
    }
  }
  cout << "User with ID " << id << " not found.\n";
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

void creatingNewProfile(string profileName)
{
  ofstream profileFileOutput(profileName + ".txt", ios::app);
  if (!profileFileOutput.is_open())
  {
    cout << "the file could not be opened while adding a new profile  \n";
    return;
  }
  profileFileOutput << profileName << "\n";
  profileFileOutput.close();
}
void addingContactToProfile(string profileName, int contactId)
{
  ofstream profileFileOutput(profileName + ".txt", ios::app);
  if (!profileFileOutput.is_open())
  {
    cout << "the file could not be opened while adding a new profile  \n";
    return;
  }
  profileFileOutput << contactId << "\n";
  profileFileOutput.close();
}

void readingProfile(string profileName)
{
  ifstream profileInputFile(profileName + ".txt");
  if (!profileInputFile.is_open())
  {
    cout << "the file could not be opened while reading the profile  \n";
    return;
  }
  string line;
  while (getline(profileInputFile, line))
  {
    cout << line << "\n";
  }
  profileInputFile.close();
}
void readingAllProfiles()
{
  ifstream profileInputFile("profiles.txt");
  if (!profileInputFile.is_open())
  {
    cout << "the file could not be opened while reading the profiles  \n";
    return;
  }
  string line;
  while (getline(profileInputFile, line))
  {
    cout << line << "\n";
  }
  profileInputFile.close();
}
int main()
{
    int choice;
    bool running = true;

    while (running)
    {
        cout << "\nUser Management System\n";
        cout << "1. Add User\n";
        cout << "2. Display All Users\n";
        cout << "3. Find User by ID\n";
        cout << "4. Find User by Name\n";
        cout << "5. Sort Users by Name\n";
        cout << "6. Create New Profile\n";
        cout << "7. Add Contact to Profile\n";
        cout << "8. Display Profile\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            {
                userInfo newUser = readingContactFromConsole();
                cout << "User Added: " << newUser.name << endl;
                break;
            }
        case 2:
            {
                cout << "Displaying All Users:" << endl;
                readingAllUsers();
                break;
            }
        case 3:
            {
                cout << "Enter User ID to find: ";
                int id;
                cin >> id;
                readingUserById(id);
                break;
            }
        case 4:
            {
                cout << "Enter User Name to find: ";
                string name;
                cin.ignore();
                getline(cin, name);
                readingUserByName(name);
                break;
            }
        case 5:
            {
                cout << "Sorting and Displaying Users by Name:" << endl;
                sortUsersByName();
                break;
            }
        case 6:
            {
                cout << "Enter Profile Name: ";
                string profileName;
                cin.ignore();
                getline(cin, profileName);
                creatingNewProfile(profileName);
                cout << "Profile Created: " << profileName << endl;
                break;
            }
        case 7:
            {
                cout << "Enter Profile Name: ";
                string profileName;
                cin.ignore();
                getline(cin, profileName);
                cout << "Enter Contact ID: ";
                int contactId;
                cin >> contactId;
                addingContactToProfile(profileName, contactId);
                cout << "Contact Added to Profile: " << profileName << endl;
                break;
            }
        case 8:
            {
                cout << "Enter Profile Name to Display: ";
                string profileName;
                cin.ignore();
                getline(cin, profileName);
                readingProfile(profileName);
                break;
            }
        case 9:
            {
                running = false;
                break;
            }
        default:
            {
                cout << "Invalid Choice. Please try again.\n";
                break;
            }
        }
    }

    cout << "Program terminated.\n";
    return 0;
}

