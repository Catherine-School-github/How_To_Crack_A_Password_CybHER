
#include <iostream>
#include <cstdlib>  //used for random number generation
#include <ctime>    //used to get time for random number generation

using namespace std;



string brute_forcing (string password);

string setting_password(string password_list[5], int choice);

string username_enter(void);

int rand_or_input(void);

//global variable = bad. but idc
const string ALPHABET[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main (void)
{
    string password_list[5] = {"firefly", "apple", "door", "banks", "juice"};
    string password;
    string current_guess;
    string username;

    int time1, time2, total_time;
    int choice;

    //if user wants to enter their own password or get a random password
    choice = rand_or_input();

    username = username_enter();

    password = setting_password(password_list, choice);

    time1 = time(0);    //time before trying to get password
    current_guess = brute_forcing(password);
    time2 = time(0);    //time after trying to get password

    total_time = time2 - time1; //total time to guess the password

    if (current_guess == password)
    {
        cout << "\n\n!!!Password Cracked!!!\n";
        cout << "Welcome in " << username << endl;
        cout << "Your social security number is: 591582017\n";
        cout << "Your phone number is: 605-271-4918\n";
        cout << "Your address is: 0000 Real Place lane, Rapid City SD\n";

        cout << "It took " << total_time << " seconds to crack your password\n";
    }
    else
    {
        cout << "Hey! you were only supposed to enter 7 lowercase letters only!!\n";
    }

    return 0;
}



int rand_or_input(void)
{
    int choice;
    cout << "Do you want to use your own password or a random password? 1 for your own, 2 for a random password: ";
    cin >> choice;

    return choice;
}


string username_enter(void)
{
    string username;
    cout << "\n\n\nPlease enter your username: ";
    cin  >> username;

    return username;
}

string setting_password(string password_list[5], int choice)
{
    string set_password;

    if (choice == 1)    //if user wants to enter their own password
    {
        cout << "Enter any 7 character or less word (lowercase letters only): ";
        cin >> set_password;
    }
    else    //if user wants random password
    {
        int random_pass;
        srand(time(0)); //uses current time for random seed
        random_pass = rand() % 5; //stores number between 1 and 1000 into random_time (1,000 is password_list.txt known "clean" password (no curse words))

        set_password = password_list[random_pass];
        cout << "Your new password is: " << set_password << endl;
    }


    return set_password;

}


string brute_forcing (string password)
{
    //DELETE LATER
    unsigned long int comparisions;
    string current_guess;

    cout << "Current first letter for 1 character:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        current_guess = ALPHABET[x];
        comparisions++;

        if(current_guess == password)
        {
            cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
            return current_guess;
        }
    }


    cout << "Current first letter for 2 characters:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        for (int y = 0; y < 26; y++)
        {
            current_guess = ALPHABET[x] + ALPHABET[y];
            comparisions++;
            if(current_guess == password)
            {
                cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
                return current_guess;
            }
        }
    }

    cout << "Current first letter for 3 characters:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        for (int y = 0; y < 26; y++)
        {
            for (int z = 0; z < 26; z++)
            {
                current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z];
                comparisions++;

                if(current_guess == password)
                {
                    cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
                    return current_guess;
                }
            }
        }
    }


    cout <<"Current first letter for 4 characters:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        for (int y = 0; y < 26; y++)
        {
            for (int z = 0; z < 26; z++)
            {
                for (int a = 0; a < 26; a++)
                {
                    current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a];
                    comparisions++;

                    if(current_guess == password)
                    {
                        cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
                        return current_guess;
                    }
                }
            }
        }
    }


    cout << "Current first letter for 5 characters:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        for (int y = 0; y < 26; y++)
        {
            for (int z = 0; z < 26; z++)
            {
                for (int a = 0; a < 26; a++)
                {
                    for (int b = 0; b < 26; b++)
                    {
                        current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b];
                        comparisions++;

                        if(current_guess == password)
                        {
                            cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
                            return current_guess;
                        }
                    }
                }
            }
        }
    }


    cout << "Current first letter for 6 characters:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        for (int y = 0; y < 26; y++)
        {
            for (int z = 0; z < 26; z++)
            {
                for (int a = 0; a < 26; a++)
                {
                    for (int b = 0; b < 26; b++)
                    {
                        for(int c = 0; c < 26; c++)
                        {
                            current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b] + ALPHABET[c];
                            comparisions++;

                            if(current_guess == password)
                            {
                                cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
                                return current_guess;
                            }
                        }
                    }
                }
            }
        }
    }


    cout << "Current first letter for 7 characters:\n";
    for (int x = 0; x < 26; x++)
    {
        cout << ALPHABET[x] << endl;
        for (int y = 0; y < 26; y++)
        {
            for (int z = 0; z < 26; z++)
            {
                for (int a = 0; a < 26; a++)
                {
                    for (int b = 0; b < 26; b++)
                    {
                        for (int c = 0; c < 26; c++)
                        {
                            for (int d = 0; d < 26; d++)
                            {
                                current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b] + ALPHABET[c] + ALPHABET[d];
                                comparisions++;

                                if(current_guess == password)
                                {
                                    cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
                                    return current_guess;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "There was a total of " << comparisions  << " different combinations checked!! isn't that a lot\n";
    return "oops this is bad";
}
