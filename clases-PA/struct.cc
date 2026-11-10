#include <vector>
#include <string>
#include <iostream> 

struct Equipo {
  std::string equipo;
  int partidosJugados;
  int partidosGanados;
  int partidosEmpatados;
};
struct Clasificacion : Equipo {
  int calcularPuntos() {
    return partidosGanados * 3 + partidosEmpatados;
  }
};

int main() {
  struct Equipo Liga[22];
  for (int i{0} ; i < 22 ; i++) {
    Clasificacion::calcularPuntos;
  
  }
}
