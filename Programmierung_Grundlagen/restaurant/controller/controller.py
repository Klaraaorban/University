from repository.food_repo import FoodRepo
from repository.costumer_repo import CostumerRepo
from repository.drink_repo import DrinkRepo
from repository.order_repo import OrderRepo

class Controller:
    def __init__(self, repo: FoodRepo, crepo: CostumerRepo, drepo: DrinkRepo, orepo: OrderRepo):
        self.repo = repo
        self.crepo = crepo
        self.drepo = drepo
        self.costumers = self.crepo.create_cost_list()      #list of costumers
        self.cost_streets = self.crepo.create_street_list()
        self.cost_IDs = self.crepo.create_id_list()
        self.foodlist = self.repo.create_food_list()
        self.foodpricelist = self.repo.create_food_pricelist()
        self.drinklist = self.drepo.create_drink_list()
        self.drinkpricelist = self.drepo.create_drink_pricelist()
        self.drinkIDlist = self.drepo.create_drinkID_list()
        self.orepo = orepo

    def sort_food(self):
        return self.repo.food_list

    def cost_exists(self, name):
        return list(filter(lambda c: name.lower() in c.lower(), self.costumers))

    def street_exists(self, street):
        return list(filter(lambda s: street.lower() in s.lower(), self.cost_streets))

    def id_exists(self, id):
        return list(filter(lambda i: str(id) in i.lower(), self.cost_IDs))

    def display_cost(self, costumer):
        if costumer:
            for part in costumer:
                with open('rest_cost.txt', 'r') as file:
                    for line in file:
                        if part in line:
                            print("Found client: ", line)

        else:
            print("not found client")
