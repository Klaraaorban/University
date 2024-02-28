from controller.controller import Controller
from modelle.essen import GekochGericht, Kunde, Bestellung, Getrank

class UI:
    def __init__(self, controller: Controller):
        self.controller = controller

    def menu(self):
        return """
            1 - Represent menu
            2 - Represent Costumers
            3- Represent drinks
            4 - Take order from menu(costumer exist/no)
                    - present total price
            5 - Add order freely(costumer exist/no)
                    -present total price
            6 - Add food to menu
            7 - Clear file
            8 - Exit
            9 - Search in costumer
            10- add costumer
            11  Add a new drink to menu
            12- Bestellung
            13- Update costumer
    """

    def search_choice(self):
        return """
        Search by:
            1 - Name
            2 - Streeet
            3 - ID
        """

    def make_drink_order(self, num):
        drink = self.controller.drinklist[int(num) - 1]
        print("Ordered drink: ", drink)
        price = self.controller.drinkpricelist[int(num) - 1]
        portion = int(input("Portion(l): "))
        alkgehalt = int(input("Alkohol gehalt(%): "))
        id_drink = self.controller.drinkIDlist[int(num) - 1]
        print(f'{drink}({portion}l, {alkgehalt} %, cost: {price})')
        return self.controller.repo.add_order(Getrank(id_drink, price, portion, alkgehalt))

    def invoice_gen(self, filename, x):
        with open(filename, 'rb') as file:
            for line in file:
                if x in line:
                    print(f'$${line}$$')

    def run(self):

        while True:
            print(self.menu())
            full_bestellung = []
            option = int(input("Chosen option: "))

            if option == 1:
                self.controller.repo.read_file_interior()

            if option == 2:
                self.controller.crepo.read_cost_file()

            if option == 3:
                self.controller.drepo.read_file_int()

            if option == 4:
                print("Does the customer already exist?")
                answear = input("y/n:   ")

                if answear == 'y':                              # costumer exists
                    self.controller.crepo.read_cost_file()          #prezent costumers
                    x = input("Which costumer wants to order: ")
                    cost_name = self.controller.costumers[int(x) - 1]
                    cost_id = self.controller.cost_IDs[int(x) - 1]
                    print("Client name: ", cost_name)
                    cost_street = self.controller.cost_streets[int(x) - 1]
                    name = cost_name
                    street = cost_street

                    self.controller.repo.read_file_interior()       #prezent menu
                    y = input("Which food from the menu: ")     # food from menu
                    id_food = y
                    food = self.controller.foodlist[int(y) - 1]
                    print("Ordered food: ", food)
                    price = self.controller.foodpricelist[int(y) - 1]
                    portion_weight = int(input("Portion(g): "))
                    make_time = int(input("Making time(min): "))

                    self.controller.repo.add_order(
                        Kunde(name, street, GekochGericht(id_food, price, portion_weight, make_time)))
                    print(f'{name} order: {food}({portion_weight}g, {make_time} minutes, {price} lei)')

                    self.controller.drepo.read_file_int()           #prezent drinks
                    z = int(input("Which drink from menu: "))                                       #drink from menu
                    drink = self.controller.drinklist[int(z) - 1]
                    drink_price = self.controller.drinkpricelist[int(z) - 1]
                    self.controller.repo.add_order(Kunde(name, street, self.make_drink_order(z)))

                    self.controller.orepo.add_bestellung(Bestellung(x, price))
                    with open('bestellung.data', 'a') as file:
                        file.write(f'{cost_id}: {cost_name}, {food}: {price}, {drink}: {drink_price}\n')

                    full_bestellung.append(int(price))
                    full_bestellung.append(int(drink_price))
                    print('The full price to be payed: ', self.controller.orepo.cost_count(full_bestellung))                            #calculate cost

                if answear == 'n':
                    cost_name = input("Add costumer: ")         # costumer doesn't exist
                    cost_street = input("Add street: ")
                    cost_id = int(input("ID: "))
                    with open('rest_cost.txt', 'a') as file:
                        file.write(f'{cost_id}: {cost_name}, {cost_street}\n')
                    self.controller.crepo.read_cost_file()
                    print("New costumer succesfully added!")

                    self.controller.repo.read_file_interior()
                    x = input('Which order would you like: ')                   # food from menu
                    name = cost_name
                    street = cost_street
                    id_food = x
                    food = self.controller.foodlist[int(x) - 1]
                    print("Ordered food: ", food)
                    price = self.controller.foodpricelist[int(x) - 1]
                    portion_weight = int(input("Portion(g): "))
                    make_time = int(input("Making time(min): "))

                    self.controller.repo.add_order(Kunde(name, street, GekochGericht(id_food, price, portion_weight, make_time)))
                    print(f'{name} order: {food}({portion_weight}g, {make_time} minutes, {price} lei)')

                    self.controller.drepo.read_file_int()           #prezent drinks
                    z = int(input("Which drink from menu: "))                   # drink from menu
                    drink = self.controller.drinklist[int(z) - 1]
                    drink_price = self.controller.drinkpricelist[int(z) - 1]
                    self.controller.repo.add_order(Kunde(name, street, self.make_drink_order(z)))

                    with open('bestellung.data', 'a') as file:
                        file.write(f'{cost_id}: {cost_name}, {food}: {price}, {drink}: {drink_price}\n')

                    full_bestellung.append(int(price))
                    full_bestellung.append(int(drink_price))
                    print('The full price to be payed: ',
                          self.controller.orepo.cost_count(full_bestellung))    # calculate cost

            if option == 5:
                print("Does the customer already exist?")
                answear = input("y/n:   ")

                if answear == 'y':
                    self.controller.crepo.read_cost_file()
                    x = input("Which costumer wants to order: ")
                    cost_name = self.controller.costumers[int(x) - 1]
                    cost_id = self.controller.cost_IDs[int(x) - 1]
                    print("Client: ", cost_name)
                    cost_street = self.controller.cost_streets[int(x) - 1]
                    name = cost_name
                    street = cost_street
                    id_food = input("ID of food: ")
                    food = input("Food: ")
                    price = int(input("Price: "))
                    portion_weight = int(input("Portion: "))
                    make_time = int(input("Making time: "))

                    self.controller.repo.add_order(
                        Kunde(name, street, GekochGericht(id_food, price, portion_weight, make_time)))

                    with open('rest_menu.txt', 'a') as file:
                        file.write(f'{id_food}: {food},{price}\n')

                    drink = input("Drink: ")
                    id_drink = int(input("Give a new ID: "))
                    d_price = int(input("Drink price: "))
                    portion = int(input("Portion(l): "))
                    alkgehalt = int(input("Alkohol gehalt(%): "))
                    self.controller.repo.add_order(Getrank(id_drink, d_price, portion, alkgehalt))

                    with open('rest_drink.txt', 'a') as file:
                        file.write(f'{id_drink}: {drink},{d_price}')

                    with open('bestellung.data', 'a') as file:
                        file.write(f'{cost_id}: {cost_name}, {food}: {price}, {drink}: {d_price}\n')


                    full_bestellung.append(int(price))
                    full_bestellung.append(int(d_price))
                    print('The full price to be payed: ',
                          self.controller.orepo.cost_count(full_bestellung))    # calculate cost

                if answear == 'n':
                    cost_name = input("Add costumer: ")
                    cost_street = input("Add street: ")
                    cost_id = int(input("ID: "))
                    with open('rest_cost.txt', 'a') as file:
                        file.write(f'{cost_id}: {cost_name}, {cost_street}\n')
                    self.controller.crepo.read_cost_file()
                    print("New costumer succesfully added!")
                    name = cost_name
                    street = cost_street
                    id_food = input("ID of food: ")
                    food = input("Food: ")
                    price = int(input("Price: "))
                    portion_weight = int(input("Portion: "))
                    make_time = int(input("Making time: "))

                    self.controller.repo.add_order(
                        Kunde(name, street, GekochGericht(id_food, price, portion_weight, make_time)))

                    with open('rest_menu.txt', 'a') as file:
                        file.write(f'{id_food}: {food},{price}\n')

                    drink = input("Drink: ")
                    id_drink = int(input("Give a new ID: "))
                    d_price = int(input("Drink price: "))
                    portion = int(input("Portion(l): "))
                    alkgehalt = int(input("Alkohol gehalt(%): "))
                    self.controller.repo.add_order(Getrank(id_drink, d_price, portion, alkgehalt))

                    with open('rest_drink.txt', 'a') as file:
                        file.write(f'{id_drink}: {drink},{d_price}')

                    file.write(f'{cost_id}: {cost_name}, {food}: {price}, {drink}: {d_price}\n')

                    full_bestellung.append(int(price))
                    full_bestellung.append(int(d_price))
                    print('The full price to be payed: ',
                          self.controller.orepo.cost_count(full_bestellung))    # calculate cost

            if option == 6:
                x = int(input('Number of food: '))
                food = input("Food: ")
                price = int(input("Price: "))
                with open('rest_menu.txt', 'a') as file:
                    file.write(f'{x}: {food},{price}\n')

            if option == 7:
                self.controller.repo.reset_orders()

            if option == 8:
                break

            if option == 9:
                print(self.search_choice())
                x = int(input("Search: "))
                if x == 1:
                    part_name = input("Search for a name: ")
                    cust_found = self.controller.cost_exists(part_name)
                    self.controller.display_cost(cust_found)

                if x == 2:
                    part_street = input("Search for street: ")
                    street_found = self.controller.street_exists(part_street)
                    self.controller.display_cost(street_found)

                if x == 3:
                    part_ID = int(input("Search for id: "))
                    id_found = self.controller.id_exists(part_ID)
                    self.controller.display_cost(id_found)

            if option == 10:
                cost_name = input("Add costumer: ")
                cost_street = input("Add street: ")
                cost_id = int(input("ID: "))
                with open('rest_cost.txt', 'a') as file:
                    file.write(f'{cost_id}: {cost_name}, {cost_street}\n')
                self.controller.crepo.read_cost_file()
                print("New costumer succesfully added!")

            if option == 11:
                drink = input("Give new drink: ")
                id_drink = int(input("Give a new ID: "))
                d_price = int(input("Drink price: "))
                with open('rest_drink.txt', 'a') as file:
                    file.write(f'{id_drink}: {drink},{d_price}')

            if option == 12:
                x = input('Which costumers invoice? Give ID: ')
                with open('bestellung.data', 'r') as file:
                    for line in file:
                        if x in line:
                            print(f'Entire order: {line}')

            if option == 13:
                cost_id = int(input("Search for ID: "))
                cost_name = input("Update costumer name: ")
                cost_street = input("Update street name: ")
                self.controller.crepo.update_cost_name(cost_id, cost_name, cost_street)
                self.controller.crepo.read_cost_file()
                print("Costumer succesfully updated!")



