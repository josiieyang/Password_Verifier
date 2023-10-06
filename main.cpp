#include <iostream>

using namespace std;

int main() {
    string password;
    bool isStrongPassword = false;
    int charNeeded;
    cout << "A strong password contains at least 8 characters, "
            "a capital letter, a number, and a punctuation mark." << endl;
    cout << "Enter your password: ";


    while (!isStrongPassword) {
        cin >> password;
        int length = password.length();

        bool hasEnoughChar = false;
        bool hasCapLetter = false;
        bool hasDigit = false;
        bool hasPunctuation = false;

        // Check how many characters there are in the password
        if (length >= 8) {
            hasEnoughChar = true;
        } else {
            charNeeded = 8 - length;
        }

        // Check if the password includes
        for (int i = 0; i < length; i++) {
            if (static_cast<int>(password[i]) >= 65 && static_cast<int>(password[i]) <= 90) {
                hasCapLetter = true;
            }
            if (static_cast<int>(password[i]) >= 48 && static_cast<int>(password[i]) <= 57) {
                hasDigit = true;
            }
            if (static_cast<int>(password[i]) >= 33 && static_cast<int>(password[i]) <= 47) {
                hasPunctuation = true;
            }
        }

        if (hasEnoughChar && hasCapLetter && hasDigit && hasPunctuation) {
            isStrongPassword = true;
        } else {
            cout << "Your password must include:" << endl;
            if (!hasEnoughChar) {
                cout << " - At least " << charNeeded << " more character(s)" << endl;
            }
            if (!hasCapLetter) {
                cout << " - At least 1 capital letter" << endl;
            }
            if (!hasDigit) {
                cout << " - At least 1 number" << endl;
            }
            if (!hasPunctuation) {
                cout << " - At least 1 punctuation mark" << endl;
            }
            cout << "\nPlease enter a new password: ";
        }
    }

    cout << "Strong password!" << endl;

    return 0;
}
