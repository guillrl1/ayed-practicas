// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_stack.cc -o main_stack
// EJECUCIÓN: ./main_stack

#include <iostream>

#include "stack_v_t.h"
#include "stack_l_t.h"

using namespace std;

int main(void) {
  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 10; i++) {
    pila_vector.push('a' + i);
    pila_vector.write();
    cout << endl;
  }
  cout << endl;

  while (!pila_vector.empty()) {
    pila_vector.pop();
    pila_vector.write();
    cout << endl;
  }


  stack_l_t<char> pila_lista;
  cout << "********** PILA LISTA **********" << endl;
  for (int i = 0; i < 10; i++) {
    pila_lista.push('a' + i);
    pila_lista.write();
    cout << endl;
  }
  cout << endl;

  while (!pila_lista.empty()) {
    pila_lista.pop();
    pila_lista.write();
    cout << endl;
  }

  //Modificacion
  //Intercambiar el orden de los dos primeros elementos en el top de la pila
  char char1 = pila_lista.top();
  pila_lista.pop();
  char char2 = pila_lista.top();
  pila_lista.pop();
  pila_lista.push(char1);
  pila_lista.push(char2);

  //A partir de una pila generar otra con los elementos en orden inverso, dejando la pila original vacía
  stack_l_t<char> pila_lista_inversa;
  while(!pila_lista.empty()){
    pila_lista_inversa.push(pila_lista.top());
    pila_lista.pop();
  }
  //Eliminar todos los elementos de posiciones impares de una pila, apoyándose en otra pila para ello. 
  //Considere el elemento en el fondo de la pila impar
  stack_l_t<char> pila_lista_par;
  int i{0};
  while(!pila_lista.empty()) {
    if (i % 2 == 0) {
      pila_lista_par.push(pila_lista.top());
    }
    pila_lista.pop();
    i++;
  }
	//A partir de una pila traslade sus elementos a dos pilas diferentes, los que sean mayores que un 
  //valor dado a una y los restantes a otra, dejando los elementos en las nuevas pilas en orden inverso al original
  cout << "Me quiero suicidar, dime un dia: " << endl;
  char umbral;
  cin >> umbral;
  stack_v_t<char> pila_vector_mayores;
  stack_v_t<char> pila_vector_menores;
  while(!pila_vector.empty()) {
    if (umbral > pila_vector.top()) 
      pila_vector_menores.push(pila_vector.top());
    else 
      pila_vector_mayores.push(pila_vector.top());
    pila_vector.pop();
  }
  
  //Dada una pila obtener el máximo de sus elementos en base a ir desapilando los dos primeros elementos 
  //en el top de la pila y reemplazarlos por el máximo de ambos sucesivamente
  

  return 0;
}
