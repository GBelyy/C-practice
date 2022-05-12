#include <iostream>
#include <memory>

class BankCell 
{

public:
    BankCell()
    { 
        std::cout << "BankCell generated" << "\n";
    };
    ~BankCell()
    { 
        std::cout << "BankCell deleted" << "\n";
    };
};

class Human 
{
public:
    std :: shared_ptr<BankCell> pointer_bankCell;

    Human()
    { 
        std::cout << "Human generated" << "\n";
    };
    ~Human()
    {
        std::cout << "Human deleted" << "\n";
    };
};

int main()
{
    std :: unique_ptr <Human> owner_1 = std :: make_unique<Human>();
    std::unique_ptr <Human> owner_2 = std::make_unique<Human>();
    owner_1->pointer_bankCell = std :: make_shared<BankCell>();
    owner_2->pointer_bankCell = owner_1->pointer_bankCell; // Ñell transfer
 
    /*                                                      
    std::unique_ptr <Human> owner_3 = std::make_unique<Human>();
    owner_3->pointer_bankCell = owner_1->pointer_bankCell;
    */
    std::cout << "end" << "\n";
    return 0;
}