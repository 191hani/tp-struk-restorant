#include <iostream>
#include <iomanip>
using namespace std;

class StrukMarugame {
private:
    string noStruk, tanggal, kasir, tujuan;
    string payment;

    int jumlahItem;

    string namaMenu[100];
    int qty[100];
    int harga[100];

    int totalFood = 0;
    int totalBeverage = 0;
    int grandTotal = 0;
    int pb1 = 0;

public:

    void input() {

        cout << "No Struk            : ";
        cin >> noStruk;

        cin.ignore();

        cout << "Tanggal             : ";
        getline(cin, tanggal);

        cout << "Kasir               : ";
        getline(cin, kasir);

        cout << "Purpose             : ";
        getline(cin, tujuan);

        cout << "Metode Pembayaran   : ";
        getline(cin, payment);

        cout << "Jumlah Item         : ";
        cin >> jumlahItem;

        for(int i=0;i<jumlahItem;i++){

            cin.ignore();

            cout << "\nItem ke-" << i+1 << endl;

            cout << "Nama Menu : ";
            getline(cin,namaMenu[i]);

            cout << "Qty       : ";
            cin >> qty[i];

            cout << "Harga     : ";
            cin >> harga[i];

            int subtotal = qty[i] * harga[i];

            grandTotal += subtotal;

            // Jika mengandung nama minuman
            if(namaMenu[i].find("Ocha") != string::npos ||
               namaMenu[i].find("Tea") != string::npos ||
               namaMenu[i].find("Coke") != string::npos ||
               namaMenu[i].find("Coffee") != string::npos)
            {
                totalBeverage += subtotal;
            }
            else
            {
                totalFood += subtotal;
            }
        }

        // PB1 10% sudah termasuk harga
        pb1 = grandTotal * 10 / 110;
    }

    void output(){

        cout << "\n==================================================\n";
        cout << "                 MARUGAME UDON\n";
        cout << "          JAPANESE NOODLES & TEMPURA\n\n";

        cout << "                 PLAZA AMBARUKMO\n";
        cout << "Jl. Laksda Adisucipto No.3, Ambarkumo,\n";
        cout << "Caturtunggal, Kec. Depok,\n";
        cout << "Kabupaten Sleman, DIY 55281\n";
        cout << "==================================================\n";

        cout << "No       : " << noStruk << endl;
        cout << "Date     : " << tanggal << endl;
        cout << "Purpose  : " << tujuan << endl;
        cout << "Cashier  : " << kasir << endl;

        cout << "--------------------------------------------------\n";

        for(int i=0;i<jumlahItem;i++){

            cout << namaMenu[i] << endl;

            cout << qty[i]
                 << "x @" << harga[i]
                 << " = "
                 << qty[i]*harga[i]
                 << endl;
        }

        cout << "--------------------------------------------------\n";

        cout << "Total Food      : " << totalFood << endl;
        cout << "Total Beverage  : " << totalBeverage << endl;

        cout << "\n" << jumlahItem << " items\n";

        cout << "\nGrand Total     : " << grandTotal << endl;

        // menyesuaikan metode pembayaran
        cout << payment << " : " << grandTotal << endl;

        cout << "\nPrice inclusive of PB1 : "
             << pb1 << endl;

        cout << "--------------------------------------------------\n";

        cout << "Collect PoinMU and redeem vouchers for FREE\n";
        cout << "products.\n";
        cout << "Download Marugame Udon App now!\n\n";

        cout << "ARIGATOU GOZAIMASU\n";
        cout << "The Prices are Inclusive Tax\n";
    }
};

int main(){

    StrukMarugame s;

    s.input();
    s.output();

    return 0;
}
