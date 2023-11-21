#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char getIPClass(const string& ipAddress) {
    istringstream iss(ipAddress);
    int firstOctet;
    char dot;

    // Extract the first octet
    iss >> firstOctet >> dot;

    if (firstOctet >= 1 && firstOctet <= 126) {
        return 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 'D';
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        return 'E';
    } else {
        return 'U'; // U for Unknown/Invalid
    }
}

int main() {
    string ipAddress;

    cout << "Enter an IPv4 address: ";
    cin >> ipAddress;

    char ipClass = getIPClass(ipAddress);

    if (ipClass == 'U') {
        cout << "Invalid IPv4 address.\n";
    } else {
        cout << "The class of the given IPv4 address is: " << ipClass << endl;
    }

    return 0;
}
