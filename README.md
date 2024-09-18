# Hill Cipher Encryption and Decryption

## Project Overview

This project implements the Hill Cipher, a classical encryption technique using matrix multiplication for encryption and decryption of messages. It provides a server-side C++ encryption and decryption program, accessible through an Express-based web interface. Users can input a plain text message to be encrypted and provide an encrypted message for decryption through the web interface.

## Table of Contents
1. [Features](#features)
2. [Prerequisites](#prerequisites)
3. [Installation](#installation)
4. [Usage](#usage)
5. [References](#references)

## Features

- **Hill Cipher Encryption:** Encrypts a message using a 3x3 key matrix.
- **Hill Cipher Decryption:** Decrypts the encrypted message using the inverse of the key matrix.
- **Web Interface:** Users can input plain messages for encryption and encrypted messages for decryption via the web interface.
- **Express Server:** Manages encryption and decryption requests using the C++ executable for backend processing.

## Prerequisites

- **Node.js** installed.
- **g++** or any C++ compiler installed.
- A browser to interact with the web interface.

## Installation

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd <project_directory>
   ```

2. Install dependencies:
   ```bash
   npm install
   ```

3. Compile the C++ program:
   ```bash
   g++ -o a.out hill_cipher.cpp
   ```

4. Start the server:
   ```bash
   node server.js
   ```

5. Open the browser and navigate to:
   ```
   http://localhost:3000
   ```

## Usage

### Encryption

1. Enter the plain message in the "Plain Message" input field.
2. Click on the **Encrypt** button.
3. The encrypted message will be displayed on the screen.

### Decryption

1. Enter the encrypted message in the "Encrypted Message" input field.
2. Click on the **Decrypt** button.
3. The decrypted message will be displayed on the screen.

### Command Line Execution

You can also run the encryption/decryption process directly from the command line:
1. For encryption, run the C++ program and select option `1`, then input the message.
2. For decryption, select option `2` and provide the encrypted message.

## References

1. **Hill Cipher Overview:**
   - [GeeksforGeeks Hill Cipher](https://www.geeksforgeeks.org/hill-cipher/)
   
2. **Decryption Algorithm:**
   - [YouTube Decryption Tutorial](https://www.youtube.com/watch?v=JK3ur6W4rvw)
