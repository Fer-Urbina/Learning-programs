#include <iostream>
using namespace std;

class SalaryCalculator {
private:
  int n;
  double* salaries;
  double totalSalary;
public:
  SalaryCalculator() {
    n = 0;
    salaries = NULL;
    totalSalary = 0.0;
  }

  void getSalaryInput() {
    cout << "Enter the number of salaries: ";
    cin >> n;
    salaries = new double[n];

    for (int i = 0; i < n; i++) {
      cout << "Enter salary " << i+1 << ": ";
      cin >> salaries[i];
      totalSalary += salaries[i];
    }
  }

  void calculateIndividualSalary() {
    for (int i = 0; i < n; i++) {
      double individualSalary = salaries[i] * 0.3;
      cout << "30% of salary " << i+1 << " (" << salaries[i] << "): " << individualSalary << endl;
    }
  }

  void calculateTotalSalary() {
    double totalIndividualSalary = totalSalary * 0.3;
    cout << "30% of total salary (" << totalSalary << "): " << totalIndividualSalary << endl;
  }

  ~SalaryCalculator() {
    if (salaries != NULL) {
      delete[] salaries;
      salaries = NULL;
    }
  }
};

int main() {
  SalaryCalculator calculator;
  calculator.getSalaryInput();
  calculator.calculateIndividualSalary();
  calculator.calculateTotalSalary();

  return 0;
}
