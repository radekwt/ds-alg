#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSecondNumberBigger(string number, string isBiggerNumber)
{
    if (number.length() < isBiggerNumber.length()) {
        return true;
    }
    if (number.length() > isBiggerNumber.length()) {
        return false;
    }
    for (size_t i = 0; i < number.length(); i++) {
        if (number[i] < isBiggerNumber[i]) {
            return true;
        }
        else if (number[i] > isBiggerNumber[i]) {
            return false;
        }
    }
            return false;
}

void shellSort(vector<string>& A,int n){
    for (int k = n / 2; k >= 1; k = (k / 2)) {
        for (int i = k; i < n;i++) {
            string x = A[i];
            int j = i;
            while (j >= k && isSecondNumberBigger(x, A[j - k])) {
                A[j] = A[j - k];
                j = j - k;
            }
            A[j] = x;
        }
    }
}

void printArray(vector<string> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    vector<string> el;
    int numberofEl;
    cin >> numberofEl;
    string input;
    for (int i = 0; i < numberofEl; i++) {
        cin >> input;
        el.push_back(input);
    }
    shellSort(el, el.size());
    printArray(el, numberofEl);

    return 0;
}
