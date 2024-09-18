#include <iostream>
#include <cctype>
#include <math.h>
using namespace std;

// run using:
// node server.js

/*Base code for hill encryption*/
/*https://www.geeksforgeeks.org/hill-cipher/*/

/*Source for decryption*/
/*https://www.youtube.com/watch?v=JK3ur6W4rvw*/

int determinant(int keyMatrix[][3], int n)
{
    int det = 0;
    if (n == 2)
    {
        return (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[1][0] * keyMatrix[0][1]);
    }
    else
    {
        int temp[3][3];
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                    {
                        continue;
                    }
                    temp[subi][subj] = keyMatrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (keyMatrix[0][x] * pow(-1, x) * determinant(temp, n - 1));
        }
    }
    return det;
}

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // Inverse doesn't exist
}

void getCofactor(int keyMatrix[][3], int temp[][3], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = keyMatrix[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void adjoint(int keyMatrix[][3], int adj[][3])
{
    if (3 == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            getCofactor(keyMatrix, temp, i, j, 3);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, 2));
        }
    }
}

bool inverse(int keyMatrix[][3], int inverseMatrix[][3])
{
    int det = determinant(keyMatrix, 3);
    det = (det % 26 + 26) % 26; // Ensure positive modulo

    int inverseDet = modInverse(det, 26);
    if (inverseDet == -1)
    {
        cout << "Inverse doesn't exist for the given key matrix." << endl;
        return false;
    }

    int adj[3][3];
    adjoint(keyMatrix, adj);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inverseMatrix[i][j] = ((adj[i][j] % 26) * inverseDet) % 26;

    return true;
}

string decrypt(int cipherMatrix[][1], int keyMatrix[][3], int decryptedMessage[][1])
{
    string decryptedText; // Variable to hold decrypted text

    int inverseKeyMatrix[3][3];
    if (!inverse(keyMatrix, inverseKeyMatrix))
        return decryptedText; // Return empty string if inverse doesn't exist

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            decryptedMessage[i][j] = 0;
            for (int x = 0; x < 3; x++)
            {
                decryptedMessage[i][j] += inverseKeyMatrix[i][x] * cipherMatrix[x][j];
            }
            decryptedMessage[i][j] = (decryptedMessage[i][j] % 26 + 26) % 26;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        decryptedText += char((decryptedMessage[i][0] + 26) % 26 + 'A');
    }

    return decryptedText;
}

void getKeyMatrix(string key, int keyMatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1])
{
    int x, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;
            for (x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

string HillCipher(string message, string key)
{
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[3][1];

    for (int i = 0; i < 3; i++)
    {
        messageVector[i][0] = (message[i]) % 65;
    }

    int resultMatrix[3][1];

    encrypt(resultMatrix, keyMatrix, messageVector);

    string resultText;

    cout << resultText << endl;

    for (int i = 0; i < 3; i++)
    {
        resultText += resultMatrix[i][0] + 65;
    }

    return resultText;
}

int main()
{

    int keyMatrix[3][3];
    int input = 0;
    string message;
    string key = "GYBNQKURP";

    cin >> input;
    cout << endl;
    cin >> message;

    for (char &c : message)
    {
        c = toupper(c);
    }

    if (input == 1)
        HillCipher(message, key);
    else if (input == 2)
    {

        int k = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                keyMatrix[i][j] = (key[k] - 'A') % 26;
                k++;
            }
        }

        int encryptedVector[3][1];
        for (int i = 0; i < 3; i++)
        {
            encryptedVector[i][0] = (message[i] - 'A') % 26;
        }

        int decryptedMessage[3][1];

        decrypt(encryptedVector, keyMatrix, decryptedMessage);

        string decryptedText = "";
        for (int i = 0; i < 3; i++)
        {
            decryptedText += char((decryptedMessage[i][0] + 26) % 26 + 'A');

            cout << decryptedText << endl;
        }
    }
