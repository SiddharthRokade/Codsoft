#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  
   srand(time(0));

   int randomNumber = rand() % 100 + 1;
   int guess;

   cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;

   do {
       cout << "Enter your guess: ";
       cin >> guess;

       if (guess > randomNumber) {
           cout << "Too high! Guess again." << endl;
       } else if (guess < randomNumber) {
           cout << "Too low! Guess again." << endl;
       } else {
           cout << "Congratulations! You guessed the number!" << endl;
       }
   } while (guess != randomNumber);

   return 0;
}
