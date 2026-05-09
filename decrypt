#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream fin("encrypted.data");
    string VALID;
    string valid;
    string V[2][3];
    fin >> VALID;
    int key = 0;
    while(valid != "VALID")
    {
        for(int i=0; i<5; i++)
        {
            char a = VALID[i] - key;
            valid += a;
        }
        if(valid != "VALID")
        {
            key++;
            valid.clear();
        }
    }
    cout << "Enter the correct encryption key: ";
    int userKey;
    cin >> userKey;
    if(userKey == key)
    {
        cout << "Your key is correct. Here are the decrypted passwords:" << endl;
        for(int i=0; i<2; i++)
        {
            fin >> V[i][0] >> V[i][1] >> V[i][2];
            string password;
            for(int j=0; j<V[i][2].length(); j++)
            {
                char a = V[i][2][j] - key;
                password += a;
            }
            cout << "Site Address: " << V[i][0] << " | Username: " << V[i][1] << " | Decrypted Password: " << password << endl;
            fin.close();
        }
    }
    else{
        fin.close();
        remove("encrypted.data");
        cout << "Incorrect key. Deleting your data." << endl;
    }
    return 0;
}
