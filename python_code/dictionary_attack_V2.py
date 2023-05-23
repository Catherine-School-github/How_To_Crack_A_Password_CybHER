#allows random to get random password to crack
import random

#allows to see how long it took to guess the password
import time


def random_or_input():
    password_setting = int(input("Would you like a random password or set your own password? 1 for your own password, 2 for a random password: "))
    print("\n\n\n")
    return password_setting


def setting_username():
    name = input("What is your username: ")
    return name


def setting_password(password_file, decision): 
    
    #if user enters 1, lets them check their own password
    if (decision == 1): 
        password = input("Enter your password: ")
        password = password + "\n"  #adds a newline character to the password the user set to match the passwords in the file (why python requires this? I can only guess it adds its own newline character)
        print("")
        return password
    
    #randomly chooses password
    else:
        max_lines = 1000    #max lines allowed to check
        current_password = password_file.readlines()    #makes 'current_password' a list(?) of the passwords 
        limited_password=current_password[:max_lines]   #makes the 'limited_password' only the first 1,000 lines of the password file
        password = (random.choice(list(limited_password))) #casts the limited_password as a list, then randomly chooses from that list. This chooses form the first 1k words, manually audited and verified

        #password = (random.choice(list(password_file))) #casts the password_file as a list, then randomly chooses from that list THIS CHOOSES FROM THE WHOLE LIST, MAY OR MAY NOT BE APPROPRIATE

        print("Your new password is: " + password)

        return password
    

#guesses the password
def guessing_password(password, password_file):

    for current_guess in password_file: #while there are still passwords to check
        if (current_guess == password): #checks the current guess to the actual password
            return current_guess        #if correct password is found, returns to to where this function was called with the correct answer




#gets the password list
password_file = open("password_list.txt", 'r')

#gets if the user wants a random password or a user generated password
decision = random_or_input()

#gets username
username = setting_username()

#gets a password
password = setting_password(password_file, decision)

#closes and opens the password_list.txt to reset the read pointer
password_file.close()
password_file = open("password_list.txt", 'r')

#guesses the password
starting_time = time.time()
found_password = guessing_password(password, password_file)
ending_time = time.time()

total_time = ending_time - starting_time
total_time = '%.10f' % total_time

if (found_password):
    print("!!!Password Found!!!")
    print("Welcome in " + username)
    print("Your social security number is: 149418269")
    print("Your phone number is: 605-941-3815")
    print("Your address is: Definitely Real Street street, Sioux Falls SD")
    print("")
    print("It only took {} seconds to get your information with that password and this dictionary, maybe you want to change your password and try again?".format(total_time))
else:
    print("The password {} was not found in this dictionary!!".format(password.strip()))


password_file.close()


