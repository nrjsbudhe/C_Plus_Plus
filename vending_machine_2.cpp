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

    void setProduct(Products product){
        sel_prod = product;
    }

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

};

int main() {
    VendingMachine vM;
    vM.select(Products::Chips);
    vM.chose_payment(PaymentType::Card);
}