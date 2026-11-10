// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      // poner código
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      // poner código
      operate_(c);
    }
  }
  // poner código
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  int result;
  // poner código
  std::cout << "   Sacamos de la pila un operando: ";
  int digit1 = stack_.top();
  int digit2{0};
  stack_.pop();
  std::cout << digit1 << std::endl;
  
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
  // poner código
  std::cout << "   Sacamos de la pila otro operando: ";
  digit2 = stack_.top();
  stack_.pop();
  std::cout << digit2 << std::endl;
  }
  switch (c) {
    case '+':
      // poner código
      result = digit2 + digit1;
      break;
    // poner código resto de operadores
    case '-':
      // poner código
      result = digit2 - digit1;
      break;
    case '*':
      // poner código
      result = digit2 * digit1;
      break;
    case '/':
      // poner código
      result = digit2 / digit1;
      break;
    case '^':
      // poner código
      result = pow(digit2, digit1);
      break;
    case 'r':
      // poner código
      result = sqrt(digit1);
      break;
    case 'l':
      // poner código
      result = log2(digit1);
      break;
    case 'c':
      // poner código
      result = digit1 * digit1;
      break;
  }

  // poner código
  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
  stack_.push(result);
}

 
#endif  // RPNT_H_
