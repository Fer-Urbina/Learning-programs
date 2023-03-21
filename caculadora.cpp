#include <iostream>
#include <cmath>

int main ()
{
    int opcion;
    double num1, num2;

    while (true)
    {
        std::cout << "Por favor seleccione una operacion:" << std::endl;
                std::cout << "1. Adicion \n";
                std::cout << "2. sustraccion\n";
                std::cout << "3. Multiplicacion\n";
                std::cout << "4. Division\n";
                std::cout << "5. Potencia\n";
                std::cout << "6. Raiz cuadrada\n";
                std::cout << "0. Fin\n" << std::endl;
        std::cin >> opcion;

            if (opcion == 0)
            {
                std::cout << "Adios!";
                break;
            }

            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;

            if (opcion != 6)
            {
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
            

            switch(opcion)
            {
                case 1:
                    std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
                break;

                case 2:
                    std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
                break;

                case 3:
                    std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
                break;

                case 4:
                    std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
                break;

                case 5:
                    std::cout << num1 << " ^ " << num2 << " = " << pow(num1, num2) << std::endl;
                break;
            }
        }
        else {
            std::cout << "raiz cuadrada de " << num1 << " = " << sqrt(num1) << std::endl;
        }
    }
    return 0;
}