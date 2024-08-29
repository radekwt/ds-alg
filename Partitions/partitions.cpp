#include <iostream>
using namespace std;
int resultNumber;


void printFinalTable(int** finalTab) {
        for (int i = resultNumber - 1; i >= 0; i--) {
                for (int j = 0; finalTab[i][j] != NULL; j++) {
                        if (j != 0)
                                cout << "+" << finalTab[i][j];
                        else
                                cout << finalTab[i][j];
                }
                cout << endl;
        }
}
void moveToFinalTable(int* result, int size, int** finalTab) {
        for (int i = 0; i < size; ++i)
        {
                finalTab[resultNumber][i] = result[i];
        }
        resultNumber++;
}
void findNumbers(int size, int sum, int primeTable[], int* partionTable, int number, int maxNIndex, int lastPrime, int** finalTab)
{
        if (number == sum) {
                bool isSorted = false;
                if (partionTable[0] == primeTable[maxNIndex]) {
                        isSorted = true;
                }
                if (isSorted) {
                        moveToFinalTable(partionTable, size, finalTab);
                }
                return;
        }
        else if (number < sum) {
                return;
        }
        else {
                for (int i = maxNIndex; i >= 0; --i)
                {
                        if (lastPrime >= primeTable[i]) {
                                partionTable[size] = primeTable[i];
                                lastPrime = primeTable[i];
                                findNumbers(size + 1, sum + primeTable[i], primeTable, partionTable, number, maxNIndex, lastPrime, finalTab);
                        }

                }
        }
}
int findPrimes(int *tab,int maxPrime) {
        int k = 0;
        for (int i = 2; i <= maxPrime; i++) {
                bool isPrime = true;
                for (int j = 2; j < maxPrime; j++) {
                        if (i % j == 0 && i != j) {
                                isPrime = false;
                                break;
                        }
                }
                if (isPrime) {
                        tab[k] = i;
                        k++;
                }
        }
        return k;
}
void partition(int number, int maxPrime)
{
        int primeIndex = -1;
        int *primeTable = new int[maxPrime];
        int primeSize = findPrimes(primeTable, maxPrime);
        for (int i = 0; i < primeSize ; i++) {
                if (maxPrime == primeTable[i]) {
                        primeIndex = i;
                }
        }
        if (primeIndex == -1) {
                delete[] primeTable;
                return;
        }
        resultNumber = 0;
        int* result = new int[number];
        int** resultTable = new int* [2 * number];
        for (int i = 0; i < 2 * number; ++i) {
                resultTable[i] = new int[number + 1];
                for (int j = 0; j < number + 1; j++) {
                        resultTable[i][j] = NULL;
                }
        }
        findNumbers(0, 0, primeTable, result, number, primeIndex, primeTable[primeIndex], resultTable);
        printFinalTable(resultTable);
        delete[] result;
        delete[] resultTable;
        delete[] primeTable;
}
int main()
{
        int number, maxPrime, howMany;
        cin >> howMany;
        for (int i = 0; i < howMany; i++) {
                cin >> number;
                cin >> maxPrime;
                partition(number, maxPrime);
        }




        return 0;
}
