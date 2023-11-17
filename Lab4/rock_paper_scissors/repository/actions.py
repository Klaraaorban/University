import random
# user and computer actions decided here
possible_actions = ['rock', 'paper', 'scissors']

def user_actions():
    user_action = input('Enter your weapon: ')
    return user_action
# user enters preferred decision

def computer_actions():
    computer_action = random.choice(possible_actions)
    print('computer chose: ', computer_action)
    return computer_action
# computer gives a randomized decision
