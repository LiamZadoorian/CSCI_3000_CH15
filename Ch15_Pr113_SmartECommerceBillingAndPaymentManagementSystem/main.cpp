#include <iostream>
#include <string>
using namespace std;

class BillCalculator {
    public:
        int calcBill(int price, int shipp){
            return price + shipp;
        }
    
        double calcBill(double price, double tax){
            return price + (price * tax);
        }
    
        double calcBill(double price, double tax, double dis){
            return (price + (price * tax)) - dis;
        }
};

class Payment {
    protected:
        string name;
        double amount;
        string trans_id;
    public:
        void setPaymentDetails(string n, double a, string t){
            name = n;
            amount = a;
            trans_id = t;
        }
    
        void display(){
            cout << "----- PAYMENT DETAILS -----\n";
            cout << "Customer Name: " << name;
            cout << "\nTransaction ID: " << trans_id;
            cout << "\nAmount: " << amount << endl;
        }
        
        virtual void pay() = 0;
};

class UPI : public Payment{
    private:
        string id;
    
    public:
        void setUPIDetails(string i){
            id = i;
        }
    
        void pay(){
            cout << "Payment Method: UPI\n"
            << "UPI ID: " << id
            << "\nUPI payment successful\n";
        }
};

class Card : public Payment{
    private:
        string bank;
    
    public:
        void setCardDetails(string b){
            bank = b;
        }
    
        void pay(){
            cout << "Payment Method: Card\n"
            << "Bank Name: " << bank
            << "\nCard payment successful\n";
        }
};

class Wallet : public Payment{
    private:
        string name;
    
    public:
        void setWalletDetails(string n){
            name = n;
        }
    
        void pay(){
            cout << "Payment Method: Wallet\n"
            << "Wallet Name: " << name
            << "\nWallet payment successful\n";
        }
};


int main(int argc, const char * argv[]) {
    
    BillCalculator bill;
    
    string cus_name;
    int price;
    int shipp;
    double tax;
    double dis;
    string id;
    string bank;
    string wallet;
    
    cout << "Enter Customer Name: ";
    getline(cin, cus_name);
    
    cout << "Enter Product Price: ";
    cin >> price;
    
    cout << "Enter Shipping Charge: ";
    cin >> shipp;
    
    cout << "Enter Tax Rate: ";
    cin >> tax;
    
    cout << "Enter Discount: ";
    cin >> dis;
    
    cin.ignore();
    
    cout << "Enter UPI ID: ";
    getline(cin, id);
    
    cout << "Enter Bank Name: ";
    getline(cin, bank);
    
    cout << "Enter Wallet Name: ";
    getline(cin, wallet);
    
    int total_with_shipping = bill.calcBill(price, shipp);
    double total_with_tax = bill.calcBill((double)price, tax);
    double final_total = bill.calcBill((double)price, tax, dis);
    
    cout << "\n----- BILL DETAILS -----"
         << "\nCustomer Name: " << cus_name
        << "\nTotal using product price and shipping: "
        << total_with_shipping
        << "\nTotal using price and tax: " << total_with_tax
        << "\nTotal using product price, tax, and discount: "
    << final_total << endl << endl;
    
    Payment *payment_pointer;

    UPI upi_object;
    Card card_object;
    Wallet wallet_object;

    upi_object.setPaymentDetails(cus_name, final_total, "TXN1001");
    upi_object.setUPIDetails(id);

    card_object.setPaymentDetails(cus_name, final_total, "TXN1002");
    card_object.setCardDetails(bank);

    wallet_object.setPaymentDetails(cus_name, final_total, "TXN1003");
    wallet_object.setWalletDetails(wallet);

    payment_pointer = &upi_object;
    payment_pointer->display();
    payment_pointer->pay();

    cout << endl;

    payment_pointer = &card_object;
    payment_pointer->display();
    payment_pointer->pay();

    cout << endl;

    payment_pointer = &wallet_object;
    payment_pointer->display();
    payment_pointer->pay();
    
    return 0;
}
