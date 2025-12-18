#include <iostream>
#include <string>
#include <vector>

using namespace std;

string generateKey(string str, string key) {
    int x = str.size();
    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encryptText(string str, string key) {
    string cipher_text;
    for (int i = 0; i < str.size(); i++) {
        char x = (str[i] + key[i]) % 26;
        x += 'A';
        cipher_text.push_back(x);
    }
    return cipher_text;
}

string decryptText(string cipher_text, string key) {
    string orig_text;
    for (int i = 0; i < cipher_text.size(); i++) {
        char x = (cipher_text[i] - key[i] + 26) % 26;
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

int main() {
    string str, keyword;
    int choice;

    cout << "--- Vigenere Cipher Tool ---" << endl;
    cout << "1. Encrypt a message" << endl;
    cout << "2. Decrypt a message" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    cout << "Enter the message (UPPERCASE ONLY, NO SPACES): ";
    cin >> str;
    cout << "Enter the keyword (UPPERCASE ONLY): ";
    cin >> keyword;

    string key = generateKey(str, keyword);

    if (choice == 1) {
        string encrypted = encryptText(str, key);
        cout << "\nCiphertext: " << encrypted << endl;
    } 
    else if (choice == 2) {
        string decrypted = decryptText(str, key);
        cout << "\nOriginal Text: " << decrypted << endl;
    } 
    else {
        cout << "Invalid choice. Bye." << endl;
    }

    return 0;
}