// AUTOR: Guillermo López Concepción
// FECHA: 08/02/2024
// EMAIL: alu0101620459@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// pauta de la Guía de estilo de google: comentarios multilinea usando /* */

#include "rational_t.hpp"

/**
 * @brief Constructor de la clase rational_t.
 * 
 * @param n Numerador.
 * @param d Denominador.
 */
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}
//ERRONEA
// pauta de estilo [87]: 3 líneas de separación entre métodos
// pauta de estilo [88]: 2 líneas de separación entre métodos

/**
 * @brief Obtiene el numerador.
 * 
 * @return int Numerador.
 */
int 
rational_t::get_num() const
{
  return num_;
}

/**
 * @brief Obtiene el denominador.
 * 
 * @return int Denominador.
 */
int 
rational_t::get_den() const
{
  return den_;
}

/**
 * @brief Establece el numerador.
 * 
 * @param n Nuevo numerador.
 */
void 
rational_t::set_num(const int n)
{
  num_ = n;
}

/**
 * @brief Establece el denominador.
 * 
 * @param d Nuevo denominador.
 */
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}

/**
 * @brief Calcula el valor decimal del número racional.
 * 
 * @return double Valor decimal.
 */
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}

// comparaciones

/**
 * @brief Compara si dos números racionales son iguales.
 * 
 * @param r Número racional a comparar.
 * @param precision Precisión para la comparación.
 * @return true Si los números racionales son iguales.
 * @return false Si los números racionales no son iguales.
 */
bool rational_t::is_equal(const rational_t& r, const double precision) const {
  return fabs(value() - r.value()) < precision;
}

/**
 * @brief Compara si un número racional es mayor que otro.
 * 
 * @param r Número racional a comparar.
 * @param precision Precisión para la comparación.
 * @return true Si el número racional es mayor.
 * @return false Si el número racional no es mayor.
 */
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return value() - r.value() < precision;
}

/**
 * @brief Compara si un número racional es menor que otro.
 * 
 * @param r Número racional a comparar.
 * @param precision Precisión para la comparación.
 * @return true Si el número racional es menor.
 * @return false Si el número racional no es menor.
 */
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.value() - value() < precision;
}

/**
 * @brief Comprueba si un número racional es cero.
 * 
 * @param precision Precisión para la comparación.
 * @return true Si el número racional es cero.
 * @return false Si el número racional no es cero.
 */
bool rational_t::is_zero(const rational_t&, const double precision) const {
  return fabs(value()) < precision;
}

// operaciones

/**
 * @brief Realiza la suma de dos números racionales.
 * 
 * @param r Número racional a sumar.
 * @return rational_t Resultado de la suma.
 */
rational_t rational_t::add(const rational_t& r) {
  double num = num_ * r.den_ + den_ * r.num_;
  double den = den_ * r.den_;
  return rational_t(num, den);
}

/**
 * @brief Realiza la resta de dos números racionales.
 * 
 * @param r Número racional a restar.
 * @return rational_t Resultado de la resta.
 */
rational_t rational_t::substract(const rational_t& r) {
  double num = num_ * r.den_ - den_ * r.num_;
  double den = den_ * r.den_;
  return rational_t(num, den);
}

/**
 * @brief Realiza la multiplicación de dos números racionales.
 * 
 * @param r Número racional a multiplicar.
 * @return rational_t Resultado de la multiplicación.
 */
rational_t rational_t::multiply(const rational_t& r) {
  double num = num_ * r.num_;
  double den = den_ * r.den_;
  return rational_t(num, den);
}

/**
 * @brief Realiza la división de dos números racionales.
 * 
 * @param r Número racional a dividir.
 * @return rational_t Resultado de la división.
 */
rational_t rational_t::divide(const rational_t& r) {
  double num = num_ * r.den_;
  double den = den_ * r.num_;
  return rational_t(num, den);
}
//Modificacion
/**
 * @brief Realiza la raiz del denominador de un numero racional dado.
 * 
 * @return Stream de salida
 */
void rational_t::square_root() {
  double square_root = get_num() / sqrt(get_den());
  cout << get_num() << "/√" << get_den() << "=" << square_root << endl;
}
// E/S

/**
 * @brief Escribe el número racional en la salida estándar.
 * 
 * @param os Stream de salida.
 */
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

/**
 * @brief Lee el número racional desde la entrada estándar.
 * 
 * @param is Stream de entrada.
 */
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
