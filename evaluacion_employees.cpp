/* En una determinada empresa, sus empleados son evaluados al final de cada año. Los puntos
que pueden obtener en la evaluación comienzan en 0.0 y pueden ir aumentando,
traduciéndose en mejores beneficios. Los puntos que pueden conseguir los empleados
pueden ser 0.0, 0.4, 0.6 o más, pero no valores intermedios entre las cifras mencionadas. A
continuación se muestra una tabla con los niveles correspondientes a cada puntuación. La
cantidad de dinero conseguida en cada nivel es de 1.400 multiplicada por la puntuación del
nivel.

Nivel Puntuación
Inaceptable 0.0
Aceptable 0.4
Meritorio 0.6 o más

Escribir un programa que lea la puntuación y el nombre de 10 empleados e indique su
nivel de rendimiento, así como la cantidad de dinero que recibirá el empleado, además el
monto total que debe pagar la empresa por después de la evaluación. */

#include <iostream>
#include <string>
#include <iomanip>


int main() {
  // Declare variables
  const int num_employees = 10;
  const int base_pay = 1400;
  std::string name;
  double score, total_pay = 0;

  // Read in scores and names of 10 employees
  for (int i = 0; i < num_employees; i++) {
    std::cout << "Enter name of employee " << i + 1 << ": ";
    std::cin >> name;
    std::cout << "Enter score of employee " << i + 1 << ": ";
    std::cin >> score;

    // Determine level of performance and pay for this employee
    std::string level;
    int pay;
    if (score == 0.0) {
      level = "Unacceptable";
      pay = 0;
    } else if (score == 0.4) {
      level = "Acceptable";
      pay = base_pay * score;
    } else if (score >= 0.6) {
      level = "Meritorious";
      pay = base_pay * score;
    }

    // Print results for this employee
    std::cout << "Employee " << name << " is " << level << " and will receive $" << pay << std::endl;

    // Add pay for this employee to total pay
    total_pay += pay;
  }

  // Print total pay for all employees
  std::cout << "Total pay for all employees is $" << total_pay << std::endl;

  return 0;
}