from ui.ui import UI
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

    c = UI(Controller(repo, crepo, drepo, orepo))
    c.run()

main()
