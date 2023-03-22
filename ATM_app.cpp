//ATM app
//I have the task to upgrade this app by adding 2 users and
//making them able to transfer money between each of their accounts

/* #include <iostream>

void showMenu()
{
    std::cout << "**********MENU**********" << std::endl;
    std::cout << "1. Check balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "************************" << std::endl;
}

int main ()
{
    //Check balance, deposit, withdraw, show menu
    int option;
    double balance = 500;

    do {
    showMenu();
    std::cout << "Option: ";
    std::cin >> option;
    system ("cls");

    switch (option)
    {
    case 1: 
    std::cout << "Balance is: " << balance << " $" << std::endl;
        break;
    
    case 2:
    std::cout << "Deposit amount: ";
    double depositAmount;
    std::cin >> depositAmount;
    balance += depositAmount;
        break;

    case 3:
    std::cout << "Withdraw amount: ";
    double withdrawAmount;
    std::cin >> withdrawAmount;
    if (withdrawAmount <= balance)
        balance -= withdrawAmount;
    else
        std::cout << "Not enough money" << std::endl;
        break;
    }
    } while (option != 4);
    
    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>

struct MonthlyData {
    std::string month;
    int rain;
};

struct RegionData {
    std::string name;
    std::vector<MonthlyData> monthly_data;
    double average;
};

int main() {
    // Read in monthly rain data for all regions
    std::vector<RegionData> rain_data;

    // Initialize totals and averages
    RegionData central_region;
    central_region.name = "central";
    int southern_region_min = INT_MAX;
    std::string southern_region_min_month;
    int northern_region_max = INT_MIN;
    std::string northern_region_max_month;
    std::unordered_map<std::string, int> region_totals;
    std::unordered_map<std::string, double> region_averages;

    // Iterate through rain data for all regions
    for (const auto& region : rain_data) {
        int total = 0;
        for (const auto& month_data : region.monthly_data) {
            // Calculate annual average for central region
            if (region.name == "central") {
                central_region.monthly_data.push_back(month_data);
            }
            // Determine month and value with least rain in southern region
            if (region.name == "southern") {
                if (month_data.rain < southern_region_min) {
                    southern_region_min = month_data.rain;
                    southern_region_min_month = month_data.month;
                }
            }
            // Determine month and value with highest rain in northern region
            if (region.name == "northern") {
                if (month_data.rain > northern_region_max) {
                    northern_region_max = month_data.rain;
                    northern_region_max_month = month_data.month;
                }
            }
            // Calculate total rain for region
            total += month_data.rain;
        }
        // Calculate average rain for region
        region_totals[region.name] = total;
        region_averages[region.name] = total / (double)region.monthly_data.size();
    }
    central_region.average = accumulate(central_region.monthly_data.begin(),central_region.monthly_data.end(),0, [](int a, auto b){return a + b.rain;})/central_region.monthly_data.size();

    // Determine region with highest average annual rainfall
    std::string highest_average_region;
    double highest_average = INT_MIN;
    for (const auto& [region, average] : region_averages) {
        if (average > highest_average) {
            highest_average = average;
            highest_average_region = region;
        }
    }

   // Output results
    std::cout << "Annual average for central region: " << central_region.average << std::endl;
    std::cout << "Month with least rain in southern region: " << southern_region_min_month << " (" << southern_region_min << ")" << std::endl;
    std::cout << "Month with highest rain in northern region: " << northern_region_max_month << " (" << northern_region_max << ")" << std::endl;
    std::cout << "Region with highest average annual rainfall: " << highest_average_region << " (" << highest_average << ")" << std::endl;
    return 0;
}