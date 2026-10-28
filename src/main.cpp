#include <iostream>
#include <ostream>

using namespace std;

// function to get an input and validate it
bool boolinput(int &i, int min, int max) {
  cin >> i;
  if (cin.fail()) {
    cout << "you didnt input a proper number" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  } else if (max != 0 || min != 0) {
    if (i > max || i < min) {
      cout << "the number must be between " << min << " and " << max << endl;
      return false;
    }
  }
  return true;
}

void inputstring(string &s, int max) {
  getline(cin, s);
  if (s.empty()) {
    cout << "the input cant be empty" << endl;
  } else if (max > 0 && (int)s.size() > max) {
    cout << "the string cant be bigger than " << max << " chars" << endl;
  }
}

void zad1() {
  int count = 0;
  int sum = 0;
  int input;
  while (count < 7) {
    cout << "input a whole number (1 to stop): ";
    if (!boolinput(input, 0, 0)) {
      continue;
    }
    if (input == 1) {
      break;
    }
    if (input % 2 != 0) {
      sum += input;
    }
    count++;
  }
  cout << "the sum of all odd numbers inputed is: " << sum << endl;
}

void zad2() {
  int input;
  while (true) {
    cout << "input a 5 digit whole number: ";
    if (!boolinput(input, 10000, 99999)) {
      continue;
    }
    break;
  }
  string str_input = to_string(input);

  // sum of all odd digits
  int sum_odd_digits = 0;
  for (char c : str_input) {
    int digit = c - '0';
    if (digit % 2 != 0) {
      sum_odd_digits += digit;
    }
  }
  if (sum_odd_digits == 0) {
    cout << "there are no odd digits in the inputed number" << endl;
  } else {
    cout << "the sum of all odd digits in the inputed number is: "
         << sum_odd_digits << endl;
  }

  // forming a new number
  string new_number_str = {str_input[0], str_input[4], str_input[1]};
  int new_number = stoi(new_number_str);
  cout << "the new number formed by the first, fifth and second digit is: "
       << new_number << endl;

  // can the last digit be divided by 4 without an remainder
  if ((str_input[4] - '0') % 4 == 0) {
    cout << "the last digit can be divided by 4 without a remainder" << endl;
  } else {
    cout << "the last digit cannot be divided by 4 without a remainder" << endl;
  }
}

void zad3() {
  // password input
  string pass = "ai_health2025";
  while (true) {
    string input;
    cout << "input password: ";
    inputstring(input, 0);
    if (input == pass)
      break;
    else {
      cout << "wrong password try again" << endl;
    }
  }

  // health data
  int heart_rate;
  int oxygen_sat;
  int hormon_balance;

  cout << "access granted" << endl;

  // health data input
  while (true) {
    cout << "input heart rate: ";
    if (boolinput(heart_rate, 0, 100))
      break;
  }
  while (true) {
    cout << "input oxygen saturation: ";
    if (boolinput(oxygen_sat, 0, 100))
      break;
  }
  while (true) {
    cout << "input hormon balance: ";
    if (boolinput(hormon_balance, 0, 100))
      break;
  }

  int average = (heart_rate + oxygen_sat + hormon_balance) / 3.0;

  cout << "average stability: " << average << "%. ";
  if (average < 35)
    cout << "Внимание: Критични стойности! Необходима е незабавна и спешна "
            "реакция от специалист."
         << endl;
  if (average >= 35 && average <= 54)
    cout << "Високи отклонения. Потърсете допълнителна консултация." << endl;
  if (average >= 55 && average <= 74)
    cout << "Умерени отклонения. следете състоянието регулярно." << endl;
  if (average >=75) cout << "Стабилни сигнали. AI оценява състоянието като нормално." << endl;
}

int main() {
  int choice;
  while (true) {
    cout << "choose which zad to run (1, 2, 3 or 0 to exit): ";
    if (!boolinput(choice, 0, 3)) {
      continue;
    }
    if (choice == 0) {
      break;
    } else if (choice == 1) {
      zad1();
      cout << endl;
    } else if (choice == 2) {
      zad2();
      cout << endl;
    } else if (choice == 3) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      zad3();
      cout << endl;
    }
  }
  return 0;
}
