#include<iostream>
#include<string>
using namespace std;

string username;
namespace Authenticate
{
    int isValid();
    void inputUserName()
    {
        do
        {
            cout << "Enter your username (8 letters only)" << endl;
            cin >> username;
        } while (!Authenticate::isValid());
    }

    string getUserName()
    {
        return username;
    }

    int isValid() {
        if (username.size() != 8) {
            return 0;
        }
        for (int i = 0; i < username.size(); i++) {
            if ((username[i] >= 'A' && username[i] <= 'Z') || (username[i] >= 'a' && username[i] <= 'z')) {
                continue;
            }
            else {
                return 0;
            }
        }
        return 1;
    }
}


namespace
{
    string password;
    int isValid();
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }

    string getPassword()
    {
        return password;
    }

    int isValid() {
        int countNoletter = 0;
        if (username.size() < 8) {
            return 0;
        }
        for (int i = 0; i < password.length(); i++) {
            if (password[i] >= '0' && password[i] <= '9')
                return 1;
        }
        return 0;
    }
}

//using namespace Authenticate;
int main()
{
    Authenticate::inputUserName();
    inputPassword();
    cout << "Your username is " << Authenticate::getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}
