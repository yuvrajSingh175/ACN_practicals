#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int main() {
    int choice;
    string input;

    cout << "Choose an option:\n";
    cout << "1. Binary to Dotted Decimal\n";
    cout << "2. Dotted Decimal to Binary\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter binary IP address: ";
            cin >> input;
            
            // Convert binary to dotted decimal
            {
                bitset<32> bits(input);
                cout << "Dotted Decimal IP: "
                    << (bits >> 24).to_ulong() << '.'
                    << ((bits >> 16) & bitset<32>(0xFF)).to_ulong() << '.'
                    << ((bits >> 8) & bitset<32>(0xFF)).to_ulong() << '.'
                    << (bits & bitset<32>(0xFF)).to_ulong() << endl;
            }
            break;

        case 2:
            cout << "Enter Dotted Decimal IP address: ";
            cin >> input;

            // Convert dotted decimal to binary
            {
                istringstream iss(input);
                int a, b, c, d;
                char dot;
                iss >> a >> dot >> b >> dot >> c >> dot >> d;

                bitset<32> binaryIP((static_cast<unsigned long>(a) << 24) | 
                                    (static_cast<unsigned long>(b) << 16) | 
                                    (static_cast<unsigned long>(c) << 8) | 
                                    static_cast<unsigned long>(d));

                cout << "Binary IP: " << binaryIP.to_string() << endl;
            }
            break;

        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
