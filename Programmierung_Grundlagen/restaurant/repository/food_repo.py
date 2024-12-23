import os
import pickle

class FoodRepo:
    def __init__(self):
        self.food_list = []
        self.dictionary = {}
        self.myFood = []
        self.myPrice = []
        self.myFoodID = []

    def add_order(self, essen):
        self.food_list.append(essen)

    def reset_orders(self):
        pass

    def read_file_interior(self):
        with open('rest_menu.txt', "r") as file:
            for line in file:
                key, value = line.strip("\n").split(": ")
                self.dictionary[key] = value

        print(self.dictionary)

    def create_food_list(self):
        dictionary = {}
        sor = []
        kaja = []
        with open('rest_menu.txt', "r") as file:
            for line in file:
                key, value = line.strip(" ").split(": ")
                dictionary[key] = value
                sor.append(key)
                kaja.append(value)

        self.myFood = [i.split(',')[0] for i in kaja]

        return self.myFood

    def create_food_pricelist(self):
        dictionary = {}
        sor = []
        kaja = []
        with open('rest_menu.txt', "r") as file:
            for line in file:
                key, value = line.strip("\n").split(": ")
                dictionary[key] = value
                sor.append(key)
                kaja.append(value)

        self.myPrice = [i.split(',')[1] for i in kaja]

        return self.myPrice

class FileFoodRepo(FoodRepo):
    def __init__(self, filename):
        FoodRepo.__init__(self)
        self.filename = filename
        if os.path.exists(self.filename):
            self.load()

    def save_order(self):
        f = open(self.filename, 'wb')
        pickle.dump(self.food_list, f)
        f.close()

    def add_order(self, essen):
        super().add_order(essen)
        self.save_order()

    def load(self):
        f = open(self.filename, 'rb')
        self.food_list = pickle.load(f)
        f.close()

    def reset_orders(self):
        self.food_list.clear()
        f = open(self.filename, 'wb')
        pickle.dump(self.food_list, f)
        f.close()

