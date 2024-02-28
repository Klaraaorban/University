import os
import pickle
class DrinkRepo:
    def __init__(self):
        self.drink_list = []
        self.drinkdic = {}
        self.myDrink = []
        self.myPriceDrink = []
        self.myIDDrink = []

    def add_drink(self, drink):
        self.drink_list.append(drink)

    def read_file_int(self):
        with open('rest_drink.txt', 'r') as file:
            for line in file:
                key, value = line.strip("\n").split(": ")
                self.drinkdic[key] = value

        print(self.drinkdic)

    def create_drink_list(self):
        dictionary = {}
        sor = []
        ital = []
        with open('rest_drink.txt', "r") as file:
            for line in file:
                key, value = line.strip(" ").split(": ")
                dictionary[key] = value
                sor.append(key)
                ital.append(value)

        self.myDrink = [i.split(',')[0] for i in ital]

        return self.myDrink

    def create_drink_pricelist(self):
        dictionary = {}
        sor = []
        ital = []
        with open('rest_drink.txt', "r") as file:
            for line in file:
                key, value = line.strip("\n").split(": ")
                dictionary[key] = value
                sor.append(key)
                ital.append(value)

        self.myPriceDrink = [i.split(',')[1] for i in ital]

        return self.myPriceDrink

    def create_drinkID_list(self):
        dictionary = {}
        with open('rest_drink.txt', "r") as file:
            for line in file:
                key, value = line.strip(" ").split(": ")
                dictionary[key] = value
                self.myIDDrink.append(key)

        return self.myIDDrink
class FileDrinkRepo(DrinkRepo):
    def __init__(self, filename):
        DrinkRepo.__init__(self)
        self.filename = filename
        if os.path.exists(self.filename):
            self.load_drink()

    def save_order_drink(self):
        f = open(self.filename, 'wb')
        pickle.dump(self.drink_list, f)
        f.close()

    def add_drink(self, drink):
        super().add_drink(drink)
        self.save_order_drink()

    def load_drink(self):
        f = open(self.filename, 'rb')
        self.drink_list = pickle.load(f)
        f.close()
