#include<iostream>

enum class VendingMachineStates {Idle, Select, Payment, Dispense};
enum class PaymentType {Card, Cash, UPI};
enum class CardVendor {MasterCard, VISA, Rupay};
enum class Coins {Five = 5, Ten = 10, TwentyFive = 25};
enum class Products {Chips, Soda, Chocolate, ProteinBar, Nachos};


class VendingMachine{

private:
    VendingMachineStates vm_state = VendingMachineStates::Idle;
    Products sel_prod;
    PaymentType pay_type = PaymentType::Cash;
    int sum_of_coins = 0;

// Public Functions
// SIMULATION --> USER BUTTONS TRIGGER FOLLOWING FUNCTIONS
public:

    void select(Products product){
        switch (vm_state)
        {        
        case VendingMachineStates::Idle:
            sel_prod = product;
            vm_state = VendingMachineStates::Payment;
            break;

        case VendingMachineStates::Select:
            sel_prod = product;
            vm_state = VendingMachineStates::Payment;      
            break;

        case VendingMachineStates::Dispense:
            std::cout << "Dispense Already Started" << std::endl;
            break;      

        default:
            vm_state = VendingMachineStates::Idle;
            std::cout << "Please select the Product" << std::endl;
            break;
        }
    }

    void chose_payment(PaymentType payment_type){
        if(vm_state == VendingMachineStates::Payment){
            pay_type = payment_type;
        }
        else{
            std::cout<<"Please select the prodect before payment!"<<std::endl;
        }
    }

    void enter_coin(Coins coins){
        if(pay_type == PaymentType::Cash && vm_state == VendingMachineStates::Payment){
            sum_of_coins = sum_of_coins + static_cast<int>(coins);
            std::cout<<sum_of_coins<<std::endl;
        }
        else{
            std::cout << "Something went wrong!" << std::endl;
        }
        
    }

    void tap_card(CardVendor card_vendor){
        std::cout << "Requesting Payment from " << std::endl;
        // std::cout << ge << std::endl;
    }

};

int main() {
    auto L = 5F;
    std::cout << L << std::endl;
    VendingMachine vM;
    vM.select(Products::Chips);
    vM.chose_payment(PaymentType::Cash);
    
    vM.enter_coin(Coins::Ten);
    vM.enter_coin(Coins::Ten);
    
    VendingMachine vM1;

    vM1.select(Products::Chocolate);
    vM1.chose_payment(PaymentType::Card);
    vM1.tap_card(CardVendor::MasterCard);
    




}