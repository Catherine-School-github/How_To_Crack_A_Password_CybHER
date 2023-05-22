#include <iostream> //used for trying into the computer, and displaying results
#include <fstream>  //used for opening the password_list.txt file
#include <cstdlib>  //used for random number generation
#include <ctime>    //used to get time for random number generation

using namespace std;

int rand_or_input(void);
string getting_username(void);
string setting_password(int decision);
string guess_the_password(string password);

int main (void)
{
    //variables needed for password guessing
    int decision;
    string username;
    string password;
    string found_password;

    decision = rand_or_input();

    username = getting_username();

    password = setting_password(decision);

    found_password = guess_the_password(password);

    if (found_password == password)
    {
        cout << "\n\n!!!Password Found!!!\n";
        cout << "Your username is " << username << endl;
        cout << "Your social security number is: 401493105\n";
        cout << "Your phone number is: 605-482-4184\n";
        cout << "Your address is: 1234 Street street, Madison SD\n";
    }
    else
    {
        cout << "\n\nYour password was not found in the dictionary!!\n";
    }

    return 0;
}


//decides if user wants to enter their own password or get a random password
int rand_or_input (void)
{
    int decision;

    cout << "Would you like to enter your own password or get a random password. 1 for your own password, 2 for a random password: ";
    cin >> decision;

    return decision;
}


//gets the username of the person
string getting_username(void)
{
    string username;
    cout << "Enter your username: ";
    cin >> username;

    return username;
}


//sets the password
string setting_password(int decision)
{
    string password;

    //user wanted their own password
    if (decision == 1)
    {
        cout << "Enter a password: ";
        cin >> password;
    }

    //user wanted random password
    else
    {
        int counter = 0;
        int random_time;    //random number to get random password
        srand(time(0)); //uses current time for random seed
        random_time = rand() % 1000 + 1; //stores number between 1 and 1000 into random_time (1,000 is password_list.txt known "clean" password (no curse words))

        //opens file to set_password
        ifstream set_password;
        set_password.open("password_list.txt");

        //while the counter != random number
        while (counter < random_time)
        {
            //sets the password to the current password in the file. (THIS PROBABLY CAN BE DONE BETTER BUT IT WORKS FINE)
            set_password >> password;
            counter++;
        }

        set_password.close();
        cout <<"Your new password is: " << password << endl;
    }

    return password;

}


string guess_the_password(string password)
{
    string current_guess;

    ifstream get_password;
    get_password.open("password_list.txt");

    while (get_password && current_guess != password)
    {
        get_password >> current_guess;
    }

    get_password.close();

    return current_guess;

}
