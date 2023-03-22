/*
    Introducir por teclado el tamaño del vector que sea mayor que cero y menor
    que 100. El vector tiene N temperaturas digitadas validando que sean mayores
    o iguales a cero. Calcular su media y determinar entre todas ellas cuáles
    son superiores o iguales a esa media.

*/

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cout << "Enter the size of the vector (1 to 100): ";
    std::cin >> n;
    while (n <= 0 || n > 100) {
        std::cout << "Invalid size. Enter the size again (1 to 100): ";
        std::cin >> n;
    }

    std::vector<double> temperatures(n);
    double temp;
    std::cout << "Enter " << n << " temperatures: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        while (temp < 0) {
            std::cout << "Invalid temperature. Enter temperature again: ";
            std::cin >> temp;
        }
        temperatures[i] = temp;
    }

    double mean = std::accumulate(temperatures.begin(), temperatures.end(), 0.0) / n;
    std::cout << "Mean temperature: " << mean << std::endl;

    std::cout << "Temperatures greater than or equal to mean: ";
    for (const auto& t : temperatures) {
        if (t >= mean) {
            std::cout << t << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}