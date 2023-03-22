/* En una universidad posee un grupo de 30 alumnos se desea elaborar programa que permita
conocer cuantos clasifican para la carrera de economía, administración, contabilidad e
ingeniería, las condiciones para ser seleccionado son las siguientes:

1. Economía cursando 5to semestre o superior y un promedio de 85
2. Administración cursando 6to semestre o superior y promedio mayor o igual a 88
3. Contabilidad cursando 6to semestre o superior y promedio mayor o igual a 85
4. Ingeniería cursando 6to semestre o superior promedio mayor o igual a 88 */

#include <iostream>
#include <string>

int main ()
{

const int alumnos = 10;
std::string nombres;
int semestre, economia, administracion, contabilidad, ingenieria;
double promedio = 0;

for (int i=0; i < alumnos; i++)
{
    std::cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
    std::cin >> nombres;
    std::cout << "Ingrese el promedio del estudinate " << i + 1 << ": ";
    std::cin >> promedio;
    std::cout << "Ingrese el semestre cursado del estudiante " << i + 1 << ": ";
    std::cin >> semestre;

    std::string carreras;
    if (semestre >= 5 && promedio == 85)
    {
        carreras = "Economia";
    } else if (semestre >= 6 && promedio >= 88)
    {
        carreras = "Administracion";
    } else if (semestre >= 6 && promedio >= 85)
    {
        carreras = "Contabilidad";
    } else if (semestre >= 6 && promedio >= 88)
    {
        carreras = "Ingenieria";
    }

    std::cout << "El alumno " << nombres << " cursara la carrera: " << carreras << "\n";
}

return 0;

}