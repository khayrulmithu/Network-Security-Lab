#include <iostream>
#include <cmath>
using namespace std;

int keyMatrix[3][3];
int inverseKeyMatrix[3][3];
int messageVector[3][1];
int decipherMatrix[3][1];


void getKeyMatrix()
{
	int k = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			keyMatrix[i][j] = (key[k]) % 65;
//			k++;
//		}
//	}

    keyMatrix[0][0]=17;
    keyMatrix[0][1]=17;
    keyMatrix[0][2]=5;

    keyMatrix[1][0]=21;
    keyMatrix[1][1]=18;
    keyMatrix[1][2]=21;

    keyMatrix[2][0]=2;
    keyMatrix[2][1]=2;
    keyMatrix[2][2]=19;

}

// Function to calculate the determinant of a 3x3 matrix
int determinant(int mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// Function to calculate the multiplicative inverse of a number mod 26
int modInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            return i;
        }
    }
    return -1; // If the inverse doesn't exist
}

// Function to calculate the inverse of a 3x3 matrix mod 26
void getInverseKeyMatrix() {
    int det = determinant(keyMatrix);

    det=((det%26)+26)%26;

    //cout<< "det = "<<det<<endl;

    int detInverse = modInverse(det);
    if (detInverse == -1) {
        cerr << "Inverse does not exist. Key matrix is not invertible." << endl;
        exit(1);
    }

    // Calculate the adjugate matrix
    inverseKeyMatrix[0][0] = ((keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][1]) * detInverse) % 26;
    inverseKeyMatrix[0][1] = ((keyMatrix[0][2] * keyMatrix[2][1] - keyMatrix[0][1] * keyMatrix[2][2]) * detInverse) % 26;
    inverseKeyMatrix[0][2] = ((keyMatrix[0][1] * keyMatrix[1][2] - keyMatrix[0][2] * keyMatrix[1][1]) * detInverse) % 26;
    inverseKeyMatrix[1][0] = ((keyMatrix[1][2] * keyMatrix[2][0] - keyMatrix[1][0] * keyMatrix[2][2]) * detInverse) % 26;
    inverseKeyMatrix[1][1] = ((keyMatrix[0][0] * keyMatrix[2][2] - keyMatrix[0][2] * keyMatrix[2][0]) * detInverse) % 26;
    inverseKeyMatrix[1][2] = ((keyMatrix[0][2] * keyMatrix[1][0] - keyMatrix[0][0] * keyMatrix[1][2]) * detInverse) % 26;
    inverseKeyMatrix[2][0] = ((keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[1][1] * keyMatrix[2][0]) * detInverse) % 26;
    inverseKeyMatrix[2][1] = ((keyMatrix[0][1] * keyMatrix[2][0] - keyMatrix[0][0] * keyMatrix[2][1]) * detInverse) % 26;
    inverseKeyMatrix[2][2] = ((keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0]) * detInverse) % 26;
}

// Function to decrypt the message
void decrypt() {
    int x, i, j;
    for (i = 0; i < 1; i++) {
        for (j = 0; j < 3; j++) {
            decipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++) {
                decipherMatrix[i][j] +=
                    inverseKeyMatrix[x][j] * messageVector[i][x];
            }

            decipherMatrix[i][j] = (decipherMatrix[i][j] % 26 + 26) % 26; // Handle negative values
        }
    }
}

// Function to implement Hill Cipher decryption
void HillDecipher(string message) {
    // Get key matrix from the key string
    getKeyMatrix();

    // Get the inverse of the key matrix
    getInverseKeyMatrix();

    // Generate vector for the message
    for (int i = 0; i < 3; i++)
        messageVector[0][i] = (message[i]) % 97;

    // Following function generates the decrypted vector
    decrypt();

    string DecryptedText = "";

    // Generate the decrypted text from the decrypted vector
    for (int i = 0; i < 3; i++)
        DecryptedText += decipherMatrix[i][0] + 97;

    // Finally print the decrypted text
    cout << DecryptedText;
}

int main() {
    string st;

    cout << "Enter Your CipherText: ";
    cin >> st;

    int x = st.size();

    cout << "Decrypted Text: ";

    string st2 = "";

    for (int i = 0; i < x; i++) {

        st2 += st[i];

        if (i % 3 == 2) {
            HillDecipher(st2);
            st2 = "";
        }
    }

    return 0;
}
