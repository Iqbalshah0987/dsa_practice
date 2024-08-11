#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Declare an array of size 50
    int n=50;
    int arr[n];

    // Seed the random number generator with the current time
    srand(time(0));

    // Fill the array with random values
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random values between 0 and 99
    }

    // Print the array to verify the random values
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
