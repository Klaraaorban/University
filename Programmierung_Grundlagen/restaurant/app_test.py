from tests.kunde_search import TestSearch
from controller.controller import Controller
from repository.food_repo import FileFoodRepo
from repository.costumer_repo import CostumerRepo
from repository.drink_repo import FileDrinkRepo
from repository.order_repo import OrderRepo
def main():
    repo = FileFoodRepo('orders.data')
    crepo = CostumerRepo()
    drepo = FileDrinkRepo('orders.data')
    orepo = OrderRepo()

    a = TestSearch(Controller(repo, crepo, drepo, orepo))
    a.test_kunde_search()
    a.test_street_search()
    a.test_bestellung()
    a.test_saved_bestellung()
    # a.test_update_cost()

main()
