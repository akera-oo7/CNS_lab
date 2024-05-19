#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 26
char encryptChar(char plain, char *key) {
    if (plain >= 'A' && plain <= 'Z') {
        return key[plain - 'A'];
    } else if (plain >= 'a' && plain <= 'z') {
        return key[plain - 'a'] + ('a' - 'A');
    } else {
        return plain; 
    }
}
char decryptChar(char cipher, char *key) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (cipher == key[i]) {
            return 'A' + i; 
        } else if (cipher == (key[i] + ('a' - 'A'))) {
            return 'a' + i; 
        }
    }
    return cipher;
}
void encryptMessage(char *plaintext, char *key) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = encryptChar(plaintext[i], key);
    }
}
void decryptMessage(char *ciphertext, char *key) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = decryptChar(ciphertext[i], key);
    }
}
int main() {
    char plaintext[100]; 
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    char ciphertext[strlen(plaintext) + 1];
    encryptMessage(plaintext, key);
    printf("Encrypted message: %s\n", plaintext);
    strcpy(ciphertext, plaintext); 
    decryptMessage(ciphertext, key);
    printf("Decrypted message: %s\n", ciphertext);
    return 0;
}
