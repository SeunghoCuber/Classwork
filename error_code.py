import os, random
os.system('clear')
''' This is a program to create a worg guessing game
all variables will be declared at the beginning of the program
Menu Function will create Menu'''
##Lists
HardestWords=["craziest", "Phenomenon", "Worcestershire","Sixth", "Mischievous","Draconian","Homogeneous","Laconic","Corroborate","Pragmatic"]
InterWords=["aggressive","futuristic","imagine","religion","produce","fraudulent","Japanese","diverse","entrepreneur","acknowledgement"]
EasyWords=["bananas", "grapes", "pharmacy", 'post office', 'apples', "cafeteria",
    "papaya", 'oranges', 'towers', 'mangos', 'kiwis','house' ]
#Variables
word=""
guess=""
#Function to select the word to guess
def selectWord(choice):
    global word        #it is global so the change will be accepted everywhere we use word
                        # global var do not need to be returned
    if '2' in choice:
        word=random.choice(EasyWords)
    elif '3' in choice:
        word=random.choice(InterWords)
    elif '4' in choice:
        word=random.choice(HardestWords)
    word=word.lower()

def Menu():
    os.system('clear')
    print("####################################")
    print("#     Word Game for you            #")
    print("#       1 Instructions             #")
    print("#       2 Easy Words               #")
    print("#       3 Medium                   #")
    print("#       4 Difficult                #")
    print("#       5 Exit                     #")
    print("########################################")
    choice = input("Enter your choice ")
    os.system('clear')
    if '1' in choice:
        print("my instruction are not here but they will be soon :) !!!")
        input(" Press return to go back to main menu" )
        Menu()
    elif '5' in choice:
        print ("good Bye")
        exit()
    elif '3' in choice or '2' in choice or '4' in choice:
        selectWord(choice)
    else:
        print("Please enter a valid option")
        Menu()

    #Bug 1: it should call playing() every single time Menu is called
    print(word)
    playing()

#Function to control your user input
def getLetter():
    global guess
    check=True
    while check:
        try:
            guess=input("\nenter a letter to guess the word ")
            if guess.isalpha() and len(guess)==1:
                guess=guess.lower()
                check=False
            else:
                print("only one letter please")
        except ValueError:
            print("only one letter please")

#Function to control the game( in the AP will be your main function to tal about it
def playing():
    turns=len(word)+2
    guess_len = 0
    guesses=''
    count=0
    while (turns>0 and guess_len < len(word)): #break out of the loop when the length of the current guess is equal to the word
        for letter in word:
            if letter in guesses:
                print(letter, end=" " )
            else:
                print ("_", end=" ")
        getLetter()
        if guess in word:
            if guess not in guesses:
                guesses += guess
                print(" Good guess ")
            else:
                print("You have used that letter before")
        else:
            turns -=1
            print("sorry guess again")

        #Bug 2: Count all letters so that overlapping letters get counted
        guess_len = 0
        for letter in word:
            if letter in guesses:
                #count all letters
                guess_len += 1

        print(guesses)
    if(guess_len == len(word)):
        print("you guessed correctly, your score was...")
    else:
        print("Sorry you did not guess correctly...")
    input("Press enter to countinue")
    Menu()

#just call Menu() because it will call playing() inside it
Menu()
