/* #include <iostream>
#include <string>

const int MONTHS = 12;
const int REGIONS = 3;
const std::string MONTH_NAMES[REGIONS] = {"NORTH", "CENTER", "SOUTH"};

struct Region {
    std::string name;
    double rainfall[MONTHS];
    double annual_rainfall;
};

int main() {
    // Define an array of structs to store the rainfall data for each region
    Region regions[REGIONS] = {{"NORTH", {0}, 0}, {"CENTER", {0}, 0}, {"SOUTH", {0}, 0}};

    // Input the monthly rainfall for each region
    for (int i = 0; i < REGIONS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            std::cout << "Enter the rainfall for " << regions[i].name << " region, " << MONTH_NAMES[j] << ": ";
            std::cin >> regions[i].rainfall[j];
            regions[i].annual_rainfall += regions[i].rainfall[j];
        }
    }

    // 1. The annual average of the central region
    double annual_average_central_region = regions[1].annual_rainfall / MONTHS;
    std::cout << "The annual average of the central region is: " << annual_average_central_region << std::endl;
    
    // 2. The month and average with less rain in the southern region
    double min_rainfall_south = regions[2].rainfall[0];
    int min_rainfall_month_south = 1;
    for (int i = 1; i < MONTHS; i++) {
        if (regions[2].rainfall[i] < min_rainfall_south) {
            min_rainfall_south = regions[2].rainfall[i];
            min_rainfall_month_south = i + 1;
        }
    }
    std::cout << "The month with least rain in southern region is " << MONTH_NAMES[min_rainfall_month_south-1] << " with average: " << min_rainfall_south << std::endl;

    // 3. The month and average with the highest rainfall in the northern region
    double max_rainfall_north = regions[0].rainfall[0];
    int max_rainfall_month_north = 1;
    for (int i = 1; i < MONTHS; i++) {
        if (regions[0].rainfall[i] > max_rainfall_north) {
            max_rainfall_north = regions[0].rainfall[i];
            max_rainfall_month_north = i + 1;
        }
    }
    std::cout << "The month with highest rain in northern region is " << MONTH_NAMES[max_rainfall_month_north-1] << " with average: " << max_rainfall_north << std::endl;

    // 4. The region with the highest annual rainfall
    int max_rainfall_region = 0;
    double max_annual_rainfall = regions[0].annual_rainfall;
    for (int i = 1; i < REGIONS; i++) {
        if (regions[i].annual_rainfall > max_annual_rainfall) {
            max_annual_rainfall = regions[i].annual_rainfall;
            max_rainfall_region = i;
        }
    }
    std::cout << "The region with the highest annual rainfall is: " << regions[max_rainfall_region].name << " with total rainfall: " << max_annual_rainfall << std::endl;
    return 0;
} */


/*
    En un centro meteorologico se llevan los promedios mensuales de las lluvias caidas en las principales
    regiones del pais. Existen 3 regiones importantes. NORTE, CENTRO y SUR. Escriba un algoritmo para calcular lo siguiente:

    � El promedio anual de la region central.
    � El mes y promedio con menor lluvia en la regi�n sur.
    � El mes y promedio con mayor lluvia en la regi�n norte.
    � La region con mayor lluvia anual.
*/

#include <iostream>
#include <string>

const int MONTHS = 12;
const int REGIONS = 3;
const std::string REGION_NAMES[REGIONS] = {"NORTH", "CENTER", "SOUTH"};
const std::string MONTH_NAMES[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    // 2D array to store the monthly rainfall for each region
    double rainfall[REGIONS][MONTHS];

    // Input the monthly rainfall for each region
    for (int i = 0; i < REGIONS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            std::cout << "Enter the rainfall for " << REGION_NAMES[i] << " region, " << MONTH_NAMES[j] << ": ";
            std::cin >> rainfall[i][j];
        }
    }

    // 1. The annual average of the central region
    double annual_average_central_region = 0.0;
    for (int i = 0; i < MONTHS; i++) {
        annual_average_central_region += rainfall[1][i];
    }
    annual_average_central_region /= MONTHS;
    std::cout << "The annual average of the central region is: " << annual_average_central_region << std::endl;

    // 2. The month and average with less rain in the southern region
    double min_rainfall_south = rainfall[2][0];
    int min_rainfall_month_south = 1;
    for (int i = 1; i < MONTHS; i++) {
        if (rainfall[2][i] < min_rainfall_south) {
            min_rainfall_south = rainfall[2][i];
            min_rainfall_month_south = i + 1;
        }
    }
    std::cout << "The month with least rain in southern region is " << MONTH_NAMES[min_rainfall_month_south-1] << " with average: " << min_rainfall_south << std::endl;

    // 3. The month and average with the highest rainfall in the northern region
    double max_rainfall_north = rainfall[0][0];
    int max_rainfall_month_north = 1;
    for (int i = 1; i < MONTHS; i++) {
        if (rainfall[0][i] > max_rainfall_north) {
            max_rainfall_north = rainfall[0][i];
            max_rainfall_month_north = i + 1;
        }
    }
    std::cout << "The month with highest rain in northern region is " << MONTH_NAMES[max_rainfall_month_north-1] << " with average: " << max_rainfall_north << std::endl;

    // 4. The region with the highest annual rainfall

    double annual_rainfall[REGIONS] = {0,0,0};
    for (int i = 0; i < REGIONS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            annual_rainfall[i] += rainfall[i][j];
        }
    }
    double max_annual_rainfall = annual_rainfall[0];
    int max_rainfall_region = 0;
    for (int i = 1; i < REGIONS; i++) {
        if (annual_rainfall[i] > max_annual_rainfall) {
            max_annual_rainfall = annual_rainfall[i];
            max_rainfall_region = i;
        }
    }
    std::cout << "The region with the highest annual rainfall is: " << REGION_NAMES[max_rainfall_region] << " with total rainfall: " << max_annual_rainfall << std::endl;
    return 0;
}
