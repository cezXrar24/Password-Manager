#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() 
{
    cout << "WELCOME TO PASSWORD MANAGER" << endl;
    int choice;
    cout << "PRESS 1: OVERWRITE PASSWORDS" << endl;
    cout << "PRESS 2: ADD NEW PASSWORDS (USING PASSKEY)" << endl;
    cout << "PRESS 3: DECRYPT PASSWORDS (REQUIRES PASSKEY)" << endl;
    cin >> choice;
    cin.ignore(); // Ignore the newline after reading choice
    string passLib[10][3];
    if(choice == 1)
    {
        for(int i=0; i<10; i++)
        {
            cout << "Enter site name: ";
            getline(cin, passLib[i][0]);
            cout << "Enter username: ";
            getline(cin, passLib[i][1]);
            cout << "Enter password: ";
            getline(cin, passLib[i][2]);
        }
    }
    int encriptedPass = rand() % 15 + 1;
    for(int i=0; i<10; i++)
    {
        cout << i << ". " << endl;
        cout << " Site name: " << passLib[i][0] << endl;
        cout << " Username: " << passLib[i][1] << endl;
        cout << " Password: " << passLib[i][2] << endl;
        ofstream fout("pass.data");
        for(int j=0; j<passLib[i][2].length(); j++)
        {
            passLib[i][2][j] = passLib[i][2][j] + encriptedPass;
            fout << passLib[i][2] << endl;
        }
    }
    return 0;
}