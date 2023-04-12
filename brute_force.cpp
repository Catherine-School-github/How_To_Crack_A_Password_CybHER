#include <iostream>

using namespace std;



string brute_forcing (string password);


const string ALPHABET[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main (void)
{
    string password;
    string current_guess;

    cout << "Enter any 7 character or less word (lowercase letters only): ";
    cin >> password;

    current_guess = brute_forcing(password);

    cout << "The password is: " << current_guess << endl;

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
