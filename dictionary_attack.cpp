#include <iostream> //used for trying into the computer, and displaying results
#include <fstream>  //used for opening the password_list.txt file
#include <cstdlib>  //used for random number generation
#include <ctime>    //used to get time for random number generation

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

    cout << "Do you want to enter your own password or get a random passowrd from a list?\n1 for entering your own password, 2 for a random password: ";
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
        random_time = rand() % 1000 + 1; //stores number between 1 and 1000 into random_time (1,000 is password_list.txt known "clean" password (no curse words))

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
    int time1, time2, total_time;

    time1 = time(0);
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

        //code to calculate how long it took (this is almost promised to always be 0)
        time2 = time(0);    //set time2 to current time
        total_time = time2 - time1; //set total_time to time2 - time1, therefore getting the time it took to find the password
        cout << "It took " << total_time << " seconds to guess " << current_guess << ". Wow isn't that fast!!\n\n";   //display the result

    }
    else
    {
        cout << "\n\nThe password was not found in the dictionary " << endl;
    }

    return;

}
