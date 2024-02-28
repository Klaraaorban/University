
def gericht_added():
    x = int(input('Number of food: '))
    food = input("Food: ")
    price = int(input("Price: "))
    with open('test_menu.txt', 'a') as file:
        file.write(f'{x}: {food},{price}\n')
    with open('test_menu.txt', 'r') as file:
        for line in file:
            if str(x) and food and str(price) in line:
                return True

def test_gericht_added():
    assert gericht_added() == True

test_gericht_added()
