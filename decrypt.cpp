#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream fin("encrypted.data");
    string V[2][4];
    for(int i=0; i<2; i++)
    {
        fin >> V[i][0] >> V[i][1] >> V[i][2] >> V[i][3];
    }
    fin.close();
    cout << "Your saved passwords:" << endl;
    for(int i=0; i<2; i++)
    {
        cout << i << ". Site Address: " << V[i][0] << " | Username: " << V[i][1] << endl;
    }
    cout << "Enter the order number of password you want to see: ";
    int choice;
    cin >> choice;
    if(choice < 0 || choice >= 2)
    {
        cout << "Invalid choice." << endl;
        return 1;
    }
    cout << "Enter the encryption key: ";
    int userKey;
    cin >> userKey;
    cout << "Are you sure that " << userKey << " is the correct key? (y/n): ";
    char confirm;
    cin >> confirm;
    if(confirm != 'n' && confirm != 'N')
    {
        cout << "Aborted." << endl;
        return 1;
    }
    string valid;
    for(int i=0; i<5; i++)
    {
        char a = V[choice][2][i] - userKey;
        valid += a;
    }
    if(valid != "VALID")
    {
        remove("encrypted.data");
        cout << "Incorrect key. Deleting your data." << endl;
        return 1;
    }
    string password;
    for(int j=0; j<V[choice][3].length(); j++)
    {
        char a = V[choice][3][j] - userKey;
        password += a;
    }
    cout << "Site Address: " << V[choice][0] << " | Username: " << V[choice][1] << " | Password: " << password << endl;
    return 0;
}
