#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("passwords.in");
    ofstream fout("encrypted.data");
    string V[2][3];
    cout << "Enter encryption key: ";
    int key;
    cin >> key;
    string valid = "VALID";
    string VALID;
    for(int i=0; i<5; i++)
    {
        char a = valid[i] + key;
        VALID += a;
    }
    fout << VALID << endl;
    for(int i=0; i<2; i++)
    {
        cout << "Enter site address: ";
        cin >> V[i][0];
        fout << V[i][0] << " ";
        cout << "Enter username: ";
        cin >> V[i][1];
        fout << V[i][1] << " ";
        fin >> V[i][2];
        cout << "Password imported" << endl;
        string password;
        for(int j=0; j<V[i][2].length(); j++)
        {
            char a = V[i][2][j] + key;
            password += a;
        }
        cout << "ENCRYPTED PASSWORD: " << password << " | KEY: " << key << " | REMEMBER IT" << endl;
        fout << password << endl;
    }
    fin.close();
    remove("passwords.in");
    return 0;
}