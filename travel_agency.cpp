/*
    Una agencia de viajes necesita saber cuanto es el monto que
    ha recaudado despues de vender 30 boletos, sabiendo que el precio de un pasaje
    de ida y vuelta por avión, esta determinado por la distancia a recorrer, el
    número de días de estancia y sabiendo que si la distancia es superior a 1.000
    km, y el número de días de estancia es superior a 7, la línea aérea le hace un
    descuento del 30%. El precio por kilómetro es de 72.50. 
*/

/* #include <iostream>
#include <string>
#include <unordered_map>

int main() {
  // Read in monthly rain data for all regions
  std::unordered_map<std::string, std::unordered_map<std::string, int>> rain_data;

  // Initialize totals and averages
  int central_region_total = 0;
  int southern_region_min = INT_MAX;
  std::string southern_region_min_month;
  int northern_region_max = INT_MIN;
  std::string northern_region_max_month;
  std::unordered_map<std::string, int> region_totals;
  std::unordered_map<std::string, double> region_averages;

  // Iterate through rain data for all regions
  for (const auto& [region, data] : rain_data) {
    int total = 0;
    for (const auto& [month, rain] : data) {
      // Calculate annual average for central region
      if (region == "central") {
        central_region_total += rain;
      }
      // Determine month and value with least rain in southern region
      if (region == "southern") {
        if (rain < southern_region_min) {
          southern_region_min = rain;
          southern_region_min_month = month;
        }
      }
      // Determine month and value with highest rain in northern region
      if (region == "northern") {
        if (rain > northern_region_max) {
          northern_region_max = rain;
          northern_region_max_month = month;
        }
      }
      // Calculate total rain for region
      total += rain;
    }
    // Calculate average rain for region
    region_totals[region] = total;
    region_averages[region] = total / (double)data.size();
  }

  // Determine region with highest average annual rainfall
  std::string highest_average_region;
  double highest_average = INT_MIN;
  for (const auto& [region, average] : region_averages) {
    if (average > highest_average) {
      highest_average = average;
      highest_average_region = region;
    }
  }

  std::cout << "Central region annual average: " << central_region_total / (double)rain_data["central"].size() << std::endl;
  std::cout << "Southern region month with least rain: " << southern_region_min_month << " (" << southern_region_min << ")" << std::endl;
  std::cout << "Northern region month with highest rain: " << northern_region_max_month << " (" << northern_region_max << ")" << std::endl;
  std::cout << "Region with highest average annual rainfall: " << highest_average_region << " (" << highest_average << ")" << std::endl;

  return 0;

//This program reads in the monthly rain data for all regions using a nested unordered map, 
//where the outer map is keyed by region
}
*/



/*
  En un centro meteorologico se llevan los promedios mensuales de las lluvias caidas en las principales
  regiones del pais. Existen 3 regiones importantes. NORTE, CENTRO y SUR. Escriba un algoritmo para calcular lo siguiente:

    1. El promedio anual de la region central.
    2. El mes y promedio con menor lluvia en la region sur.
    3. El mes y promedio con mayor lluvia en la region norte.
    4. La region con mayor lluvia anual.
*/

#include <iostream>
#include <string>
#include <iomanip>

struct centro_meteorologico
{
  float promedio_lluvias[12];
  std::string central, sur, norte;
  std::string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio",
                          "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
};

int main ()
{
    centro_meteorologico datos[12];
    double promedio_anual = 0;
    double promedio_menor_lluvia = 0;
    double promedio_mayor_lluvia = 0;
    double region_mayor_lluvia = 0;

    for (int i = 0; i < 12; i++)
    {
      std::cout << "Ingrese el promedio del mes # " << i + 1 << " de la region central: ";
      std::cin >> datos->central;
      std::cout << "Ingrese el promedio de mes # " << i + 1 << "de la region sur: ";
      std::cin >> datos->sur;
      std::cout << "Ingrese el promedio de mes # " << i + 1 << "de la region norte: ";
      std::cin >> datos->norte;

      datos->central = i / 12;
      datos->sur = i / 12;
      datos->norte = i / 12;
    }


}

