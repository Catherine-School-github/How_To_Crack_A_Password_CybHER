#setting up the valid characters
import string
ALPHABET = list(string.ascii_lowercase) 


#allows random decision if list is chosen (this can be 'from random import choice', but this makes it more readable for beginners)
import random

#allows to see how long it took to password
import time





#function to set the password. Either allows user to choose a password they want to brute force, or allows user to pick a randomly selected password
def setting_password(password_list, decision):

    if(decision == 1): #if user enters 1, allows entering of your own password
        password = input("Enter 7 characters or less, all lowercase: ")
        return password
    
    else:
        password = (random.choice(password_list)) #if user enters anything but 1, randomly chooses from a list of 5 simple passwords
        print("The password going to be cracked is: " + password)
        return password
        



#code to go through every letter possible combination of the alphabet 1 character increase at a time. I.E. first goes through every 1 character, then every combination of 2, then 3, and so on until 7 characters
def brute_forcing(password):

    print("First letter of 1 character")
    for x in range (26):
        current_guess = ALPHABET[x]
        print (current_guess)
        if (current_guess == password):
            return True
    

    print("First letter of 2 characters")
    for x in range (26):
        print(ALPHABET[x])
        for y in range (26):
            current_guess = ALPHABET[x] + ALPHABET[y]
            if (current_guess == password):
                return True
            

    print("First letter of 3 chracters")
    for x in range (26):
        print(ALPHABET[x])
        for y in range (26):
            for (z) in range (26):
                current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z]
                if (current_guess == password):
                    return True
                

    print("First letter of 4 characters")
    for x in range (26):
        print(ALPHABET[x])
        for y in range(26):
            for z in range (26):
                for a in range (26):
                    current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a]
                    if (current_guess == password):
                        return True


    print("First letter of 5 characters")
    for x in range (26):
        print(ALPHABET[x])
        for y in range (26):
            for z in range (26):
                for a in range (26):
                    for b in range (26):
                        current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b]
                        if (current_guess == password):
                            return True
                        
    
    print("First letter of 6 characters")
    for x in range (26):
        print(ALPHABET[x])
        for y in range (26):
            for z in range (26):
                for a in range (26):
                    for b in range (26):
                        for c in range (26):
                            current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b] + ALPHABET[c]
                            if (current_guess == password):
                                return True
                            

    print("First letters of 7 characters")
    for  x in range (26):
        print(ALPHABET[x])
        for y in range (26):
            for z in range (26):
                for a in range (26):
                    for b in range (26):
                        for c in range (26):
                            for alpha in range (26):
                                current_guess = ALPHABET[x] + ALPHABET[y] + ALPHABET[z] + ALPHABET[a] + ALPHABET[b] + ALPHABET[c] + ALPHABET[alpha]
                                if (current_guess == password):
                                    return True




#a password list to allow random password to be choosen
password_list = ["firefly", "apple", "door", "banks", "juice"]

decision = int(input("Would you like to enter your own password or get a random password? 1 for your own, 2 for random: "))

#gets username
username = input("Enter your username: ")

#sets the password with a seperate function
password = setting_password(password_list, decision)

#starts a timer to see how long the password takes to crack
start_cracking = time.time() 
#calls the function to brute force the password and if the password is found puts a 1 in found_password
found_password = brute_forcing(password)
#ends the timer
end_cracking = time.time() 

#finding total time by doing end-start
total_time = end_cracking - start_cracking
#rounds the total time to 10 decimal points
total_time = '%.10f' % total_time


if (found_password):
    print("!!!Password Found!!!")
    print("Your username is: {}".format(username))
    print("Your social security number is: 4195636508")
    print("Your phone number is: 605-496-3181")
    print("Your address is 100 Percent Real Street street, Brookings SD")
    print("") 
    print("It took {} to brute force your password".format(total_time))
else:
    print("Hey. You were only supposed to type in lowecase characters up to 7 characters max.")