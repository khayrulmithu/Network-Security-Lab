// C++ code to implement Hill Cipher
#include <iostream>
using namespace std;

int keyMatrix[3][3];
int messageVector[3][1];
int cipherMatrix[3][1];

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

// Following function encrypts the message
void encrypt()
{
	int x, i, j;
	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cipherMatrix[i][j] = 0;

			for (x = 0; x < 3; x++)
			{
				cipherMatrix[i][j] +=
					keyMatrix[x][j] * messageVector[i][x];
			}

			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

// Function to implement Hill Cipher
void HillCipher(string message)
{
	// Get key matrix from the key string
	getKeyMatrix();

	// Generate vector for the message
	for (int i = 0; i < 3; i++)
		messageVector[0][i] = (message[i]) % 97;


	// Following function generates
	// the encrypted vector
	encrypt();

	string CipherText="";

	// Generate the encrypted text from
	// the encrypted vector
	for (int i = 0; i < 3; i++)
		CipherText += cipherMatrix[i][0] + 97;

	// Finally print the ciphertext
	cout<< CipherText;
}


int main()
{
	string st;

	cout<< "Enter Your PlainText: ";
    cin>>st;

    int x=st.size();

    if(x%3!=0){

        for(int i=0; i<(3-x%3); i++){

            st+='x';
        }

        x+=(3-x%3);
    }

    cout<<st<<endl;

    cout << "Ciphertext: ";

    string st2="";

    for(int i=0; i<x; i++){

        st2+=st[i];

        if(i%3==2){
            HillCipher(st2);
            st2="";
        }
    }



	return 0;
}

