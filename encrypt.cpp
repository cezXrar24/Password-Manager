#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    ifstream fin("passwords.in");
    ofstream fout("encrypted.data");
    string V[2][4];
    if(fin.fail())
    {
        cout << "Error opening password save file." << endl;
        return 1;
    }
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
        int key;
        cout << "Enter encryption key: ";
        cin >> key;
        string valid = "VALID";
        for(int k=0; k<5; k++)
        {
            char a = valid[k] + key;
            V[i][3] += a;
        }
        string password;
        for(int j=0; j<V[i][2].length(); j++)
        {
            char a = V[i][2][j] + key;
            password += a;
        }
        cout << "ENCRYPTED PASSWORD: " << password << " | KEY: " << key << " | REMEMBER IT" << endl;
        fout << V[i][3] << " ";
        fout << password << endl;
    }
    fin.close();
    remove("passwords.in");
    return 0;
}