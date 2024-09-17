# Cipher

This C++ program implements the Hill cipher encryption and decryption algorithm. It allows for encoding and decoding messages using a key matrix. The Hill cipher is a polygraphic substitution cipher based on linear algebra.

### Description:
- **Encryption**: 
  - The `HillCipher` function encrypts a message using a 3x3 key matrix. The message is transformed into a numerical vector, multiplied by the key matrix, and converted back to characters.
- **Decryption**: 
  - The `decrypt` function decrypts an encrypted message by computing the inverse of the key matrix, then applying it to the encrypted message matrix.
- **Matrix Operations**:
  - **Determinant Calculation**: `determinant` function calculates the determinant of a matrix, which is necessary for finding the matrix's inverse.
  - **Adjoint and Inverse**: `adjoint` and `inverse` functions compute the adjoint and modular inverse of the key matrix, respectively.
  - **Matrix Multiplication**: `encrypt` function performs matrix multiplication to obtain the ciphertext.
- **Utility Functions**:
  - `getKeyMatrix` converts a key string into a 3x3 integer matrix.
  - `modInverse` finds the modular inverse of a number.
  - `getCofactor` helps in finding the cofactor of a matrix element.

The main function:
- Takes user input to choose between encryption and decryption.
- Processes the input message and key matrix.
- Calls appropriate functions to encrypt or decrypt the message based on the user’s choice.

This program demonstrates key operations in Hill cipher encryption and decryption, including matrix manipulation and modular arithmetic.
