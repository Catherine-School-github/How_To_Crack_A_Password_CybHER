from hashlib import sha256

#TESTING
#print(sha256("Hello World".encode()).hexdigest()) #making sure this works how the internet told me

#MORE TESTING
#testing = sha256("The quick brown fox jumped over the lazy dog".encode()).hexdigest()
#print(testing)



#opens password_file to read from
password_file = open("ORIGINAL_PASSWORD_FILE.txt", 'r')

#opens hash_file to write to
hash_file = open("hash_file.txt", 'w')


#while there are passwords in password_file, converts that password to a sha256 hash then writes that value into hash_file
for i in password_file: 
    hashing = sha256(i.strip().encode()).hexdigest() #encodes the current password
    hash_file.write(hashing) #writes the hash into hash_file
    hash_file.write("\n") #writes a newline character to seperate the hashes
    print(hashing)
    

#closes the files because done with them
password_file.close()
hash_file.close()