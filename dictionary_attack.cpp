#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;



string setting_password(void);
void guess_the_password(string password);

int main (void)
{
    //variables needed for password guessing
    string password;
    string current_guess;


    password = setting_password();

    guess_the_password(password);


    return 0;
}




//sets the password to a random word in the wordlist
string setting_password(void)
{
    int option = 0;
    string password;

    cout << "do you want to enter your own password or get a random passowrd from a list.\n1 for entering your own password, 2 for a random password: ";
    cin >> option;

    if (option == 1)
    {
        cout << "Enter a password: ";
        cin >> password;
    }

    else
    {
        int counter = 0;
        //random number to get random password
        int random_time;
        srand(time(0)); //uses current time for random seed
        random_time = rand() % 999998 + 1; //stores number between 1 and 999,998 into random_time (999,998 is amount of password is password_list.txt)

        //cout << random_time; //DEBUGING/MAKES SURE IT WORKS


        ifstream set_password;
        set_password.open("password_list.txt");

        while (counter < random_time)
        {
            set_password >> password;
            counter++;
        }
        set_password.close();
    }

    return password;

}


void guess_the_password(string password)
{

    string current_guess;

    ifstream get_password;
    get_password.open("password_list.txt");

    while (get_password && current_guess != password)
    {
        get_password >> current_guess;
    }

    get_password.close();

    if (get_password)
    {
        cout <<"\n\nThe password " << current_guess << " was found in the dictionary" << endl;
    }
    else
    {
        cout << "\n\nThe password was not found in the dictionary " << endl;
    }

    return;

}
