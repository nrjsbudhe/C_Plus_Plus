#include<iostream>
using namespace std;

enum class VendingMachineStates {Idle, Selection, Payment, Dispense};
enum class Coins {Five = 5, Ten = 10, TwentyFive = 25};
enum class Products {Chips, Soda, Chocolate, ProteinBar, Nachos};

class VendingMachine {
private:
    VendingMachineStates m_currState = VendingMachineStates::Idle;
    int m_coinsTotal = 0;
    int m_productCost = 50;
public:
    void GetCurrentState() {
        switch (m_currState) {
            case VendingMachineStates::Idle:
                cout << "Idle" << endl;
                break;

            case VendingMachineStates::Selection:
                cout << "Selection" << endl;
                break;

            case VendingMachineStates::Payment:
                cout << "Payment" << endl;
                break;

            case VendingMachineStates::Dispense:
                cout << "Dispense" << endl;
                break;
        }
    }
    void Insert(Coins coin) {
        
        switch (m_currState) {
            case VendingMachineStates::Idle:
                m_currState = VendingMachineStates::Payment;
                GetCurrentState();

            case VendingMachineStates::Payment:
                AddCoins(coin);
                break;
            
            default:
                cout << "Vending machine not ready to accept payment" << endl;
                break;
        }
    }
    void Cancel() {
        cout << "Transaction cancelled, returning to idle state" << endl;
        m_currState = VendingMachineStates::Idle;

        if(m_coinsTotal)
            cout << "Inserted coins returned, Coins total = 0" << endl;

        m_coinsTotal = 0;
    }
    void Selection(Products product) {
        switch (m_currState)
        {
        case VendingMachineStates::Payment:
            CheckTotal();
            break;
        default:
            cout << "No coins inserted. Insert coins to begin" << endl;
            break;
        }
    }
    void Dispense() {
        switch (m_currState)
        {
        case VendingMachineStates::Selection:
            DispenseProduct();
            break;
        
        case VendingMachineStates::Idle:
            cout << "No coins inserted. Insert coins to begin" << endl;
            break;

        default:
            cout << "Cannot dispense product" << endl;  
            break;
        }
    }
private:
    void AddCoins(Coins coin) {
        m_coinsTotal += static_cast<int>(coin);
        cout << "Coins total: " << m_coinsTotal << endl;
    }
    void CheckTotal() {
        if(m_coinsTotal > 50) {
            ReturnChange();
            m_currState = VendingMachineStates::Selection;
        }

        else if (m_coinsTotal == 50) m_currState = VendingMachineStates::Selection;
        else cout << "Not enough money to buy products. Insert atleast 50 cents" << endl;
    }
    void ReturnChange() {
        cout << "Returning change of " << m_coinsTotal - m_productCost << endl;
    }
    void DispenseProduct() {
        m_currState = VendingMachineStates::Dispense;
        cout << "Dispensing product. Enjoy your snack!" << endl;
    }
};

int main() {
    VendingMachine vM;
    vM.Insert(Coins::Five);
    vM.Insert(Coins::Ten);
    vM.Insert(Coins::TwentyFive);
    vM.Insert(Coins::TwentyFive);

    vM.Selection(Products::Chips);
    vM.Dispense();
}