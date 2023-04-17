#include <iostream>
#include <cstdlib>  //used for random number generation
#include <ctime>    //used to get time for random number generation

using namespace std;



string brute_forcing (string password);

string setting_password(string password_list[5]);


const string ALPHABET[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main (void)
{
    string password_list[5] = {"firefly", "apple", "door", "banks", "juice"};
    string password;
    string current_guess;
    int time1, time2, total_time;

    password = setting_password(password_list);

    time1 = time(0);    //time before trying to get password
    current_guess = brute_forcing(password);
    time2 = time(0);    //time after trying to get password

    total_time = time2 - time1; //total time to guess the password

    cout << "The password is: " << current_guess << endl;
    cout << "It took " << total_time << " seconds to guess " << current_guess << endl;

}



string setting_password(string password_list[5])
{
    string set_password;
    int choice;
    cout << "Do you want to use your own password, or use a random password\n1 for your own, 2 for random: ";
    cin >> choice;

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
        cout << "\nTrying to guess the word " << password_list[random_pass] <<". This might take a bit\n\n";
    }


    return set_password;

}


string brute_forcing (string password)
{
    string current_guess;

    for (int x = 0; x < 26; x++)
    {
        current_guess = ALPHABET[x];

        if (current_guess == password)
        {
            return current_guess;
        }

        for (int y = 0; y < 26; y++)
        {
            current_guess = ALPHABET[x] + ALPHABET[y];
            if (current_guess == password)
            {
                return current_guess;
            }


            for (int z = 0; z < 26; z++)
            {
                current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z];
                if (current_guess == password)
                {
                    return current_guess;
                }


                for (int a = 0; a < 26; a++)
                {
                    current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a];
                    if (current_guess == password)
                    {
                        return current_guess;
                    }

                    for (int b = 0; b < 26; b++)
                    {
                        current_guess = current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b];
                        if (current_guess == password)
                        {
                            return current_guess;
                        }


                        for (int c = 0; c < 26; c++)
                        {
                            current_guess = current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b] + ALPHABET[c];
                            if (current_guess == password)
                            {
                                return current_guess;
                            }

                            for (int alpha = 0; alpha < 26; alpha++)
                            {
                                current_guess = current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b] + ALPHABET[c] + ALPHABET[alpha];
                                if (current_guess == password)
                                {
                                    return current_guess;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    return current_guess;
}
