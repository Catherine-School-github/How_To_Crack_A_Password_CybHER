#hashes password to sha256
from hashlib import sha256

#allows random choice from hash_file.txt
import random


#if user wants to set their own password, or for whatever reason wants to get a random hash
def rand_or_input():

    decision = int(input(("Would you like to set your own password or have a hash assigned to you. 1 for your own, 2 for random hash: ")))
    return decision


def getting_username():

    username = input("Please enter your username: ")
    return username


def getting_hash(decision):

    if(decision == 1):
        password = input("Please enter your password: ")
        hashed_password = sha256(password.encode()).hexdigest() + "\n"
        print("Your password hashed is: {}".format(hashed_password))
        return hashed_password
    
    else:
        hash_file = open("hash_file.txt", 'r')
        hashed_password = (random.choice(list(hash_file.readlines())))
        print("Your hashed password is: {}".format(hashed_password))
        hash_file.close()
        return hashed_password



def cracking_hash(hashed_password):
    
    hash_file = open("hash_file.txt", 'r')
    
    for i in hash_file:
        if (i == hashed_password):
            return True
        
    return False



decision = rand_or_input()

username = getting_username()

hashed_password = getting_hash(decision)

found_hash = cracking_hash(hashed_password)

if (found_hash):
    print("!!! Hash Found !!!")
    print("Welcome in {}".format(username))
    print("Your social security number is: 429815083")
    print("Your phone number is: 605-191-4816")
    print("Your address is: Legit Address rd, Brandon SD")
    
else:
    print("Password not found in hash database!!")

