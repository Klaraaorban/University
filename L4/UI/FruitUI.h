#ifndef L4_ORBAN_KLARA_FRUITUI_H
#define L4_ORBAN_KLARA_FRUITUI_H
#include "../Controller/FruitController.h"
#include "../Repository/FruitRepo.h"
#include "../Domain/Fruit.h"
#include <memory>
using namespace Controller;
namespace UI {
    class FruitUI {
    private:
        std::unique_ptr<FruitController> object;
    public:
//    FruitController object;
//    FruitUI();
        FruitUI(std::unique_ptr<FruitController> obj_ptr);

        void initialize();

        void menu();

        void title();

        void interface();

    };
}
#endif //L4_ORBAN_KLARA_FRUITUI_H
