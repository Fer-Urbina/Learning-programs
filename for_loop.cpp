//Getting the sum and average of grades

/* #include <iostream>

int main ()
{
    int grade, sum = 0;

    for (int i = 0; i < 3; i++)
    {
        do
        {
            std::cout << "Enter grade " << i + 1 << ": "; 
            std::cin >> grade;
        } while (grade < 1 || grade > 5);
        sum += grade;
    }

    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Average grade = " << (float)sum / 3.0 << std::endl;

    return 0;
} */

#include <iostream>

int main() {
    int n;
    double totalAmount = 0;
    std::cout << "Enter the number of amounts: ";
    std::cin >> n;

    double amounts[n], thirtyPercent[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Enter amount " << i+1 << ": ";
        std::cin >> amounts[i];
        thirtyPercent[i] = 0.3 * amounts[i];
        totalAmount += amounts[i];
    }

    double thirtyPercentOfTotal = 0.3 * totalAmount;
    std::cout << "30% of the total amounts entered is: " << thirtyPercentOfTotal << std::endl;

    std::cout << "30% of each amount entered is: ";
    for (int i = 0; i < n; i++) {
        std::cout << thirtyPercent[i] << " \n";
    }
    std::cout << std::endl;

    return 0;
}
