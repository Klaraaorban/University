# this is the build of the game, the logik on which everything will be based

from game.rules import user_name
from repository.actions import user_actions, computer_actions

def main():
    user_count = 0
    comp_count = 0
    for i in range(3):
        print(i + 1, 'th round')
        user_round_action = user_actions()
        comp_round_action = computer_actions()
        if user_round_action == comp_round_action:
            print('its a tie')
        elif user_round_action == 'rock':
            if comp_round_action == 'paper':
                comp_count += 1
                print('computer wins')
            else:
                user_count += 1
                print(user_name,' wins')
        elif user_round_action == 'paper':
            if comp_round_action == 'scissors':
                comp_count += 1
                print('computer wins')
            else:
                user_count += 1
                print(user_name, 'wins')
        elif user_round_action == 'scissors':
            if comp_round_action == 'rock':
                comp_count += 1
                print('computer wins')
            else:
                user_count += 1
                print(user_name, 'wins')
        print(user_count, comp_count)
    if comp_count == user_count:
        print('Its a tie! Try again maybe')
    elif comp_count > user_count:
        print('Computer has won! Good luck next time!')
    else:
        print(user_name, 'won! Congrats!')
