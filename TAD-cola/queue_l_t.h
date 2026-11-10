// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase TAD cola implementada con una lista

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}
  //Constructor de copia
  queue_l_t(const queue_l_t<T>& q) : l_(q.l_) {}
  

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;
  void Maximo(void);

  //Modis
  void MoverFinal(void);
  void Duplicar(void);
  queue_l_t<T> impar(void);
  void MayorMenor(const T&, queue_l_t<T>&, queue_l_t<T>&);
  void Rellenar(void);

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 // E/S
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const queue_l_t<T>& q) {
  q.write(os);
  return os;
}
//Mover al final de la cola los dos primeros elementos del frente en orden inverso
template<class T> void queue_l_t<T>::MoverFinal(void) {
  push(front());
  pop();
  push(front());
  pop();
}
//Duplicar todos los elementos de una cola insertando los duplicados seguidos
template<class T> void queue_l_t<T>::Duplicar(void) {
  int sz = size();
  for(int i{0}; i < sz; i++) {
    push(front());
    push(front());
    pop();
  }
}
//A partir de una cola generar otra con todos los elementos de posiciones 
//impares eliminados. Considere el elemento en el frente de la cola impar
template<class T> queue_l_t<T> queue_l_t<T>::impar(void) {
  queue_l_t<T> aux_q;
  int sz = size();
  for(int i{0}; i < sz; i++) {
    if (i % 2 != 0) {
      aux_q.push(front());
    }
    pop();
  }
  return aux_q;
}
//A partir de una cola traslade sus elementos a dos colas diferentes, 
//los que sean mayores que un valor dado a una y los restantes a otra
template<class T> void queue_l_t<T>::MayorMenor(const T& umbral, queue_l_t<T>& mayor_q, queue_l_t<T>& menor_q) {
  int sz = size();
  for(int i{0}; i < sz; i++) {
    if(front() > umbral)
      mayor_q.push(front());
    else
      menor_q.push(front());
    pop();
  }
}
//Dada una cola obtener el máximo de sus elementos en base a ir desencolando los dos primeros elementos 
//en el frente de la cola e insertar el máximo de ambos por el final sucesivamente
template<class T> void queue_l_t<T>::Maximo(void) {
  int sz = size();
  for (int i{0}; i < sz; i++) {
    T data1 = front();
    pop();
    T data2 = front();
    if (data1 > data2)
      push(data1);
    else
      push(data2);
    pop();
  }
}

//Rellenar cola
template<class T> void queue_l_t<T>::Rellenar(void) {
  for (int i = 0; i < 10; i++)
	{
		push('a' + i);
	}
}



#endif  // QUEUE_H_
