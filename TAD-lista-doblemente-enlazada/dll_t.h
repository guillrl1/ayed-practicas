// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>


#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void); 

  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);

  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);

  dll_node_t<T>* erase(dll_node_t<T>*);

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

  //Modificacion
  void insert_after(dll_node_t<T>*, dll_node_t<T>*);
  void swap_last(void);
  void duplicate(void);
  void erase_odd(void);
  void move_even(dll_t<T>&);

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


// destructor
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

// operaciones
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

// E/S
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

//Insertar un nodo despues de otro pasado por parametro
template <class T> void dll_t<T>::insert_after(dll_node_t<T>* nodo, dll_node_t<T>* nodo2) {
  assert(nodo != NULL);
  assert(nodo2 != NULL);

  nodo2->set_next(nodo->get_next());
  nodo2->set_prev(nodo);
  nodo->set_next(nodo2);
  if (nodo2->get_next() != NULL)
    nodo2->get_next()->set_prev(nodo2);
  else
    tail_ = nodo2;
  sz_++;
}
template <class T> void dll_t<T>::swap_last(void) {
  assert(!empty());
  assert(get_head() -> get_next() != NULL);
  dll_node_t<T>* aux = get_head();
  dll_node_t<T>* aux2 = get_head() -> get_next();
  while (aux2 -> get_next() != NULL) {
    aux = aux -> get_next();
    aux2 = aux2 -> get_next();
  }
  aux -> set_next(NULL);
  aux2 -> set_next(get_head());
  aux2 -> set_prev(NULL);
  get_head() -> set_prev(aux2);
  get_tail() -> set_next(aux);
  aux -> set_prev(get_tail());
  head_ = aux2;
  tail_ = aux;
}
//Duplicar todos los elementos de una lista insertando todas las copias seguidas al final de la lista original
template <class T> void dll_t<T>::duplicate(void) {
  dll_node_t<T>* aux = get_head();
  while (aux != NULL) {
    dll_node_t<T>* nodo = new dll_node_t<T>(aux -> get_data());
    push_back(nodo);
    aux = aux -> get_next();
  }
}
//Eliminar y liberar todos los elementos de posiciones impares de una lista
template <class T> void dll_t<T>::erase_odd(void) {
  dll_node_t<T>* aux = get_head();
  while (aux != NULL) {
    dll_node_t<T>* nodo = aux;
    aux = aux -> get_next();
    erase(nodo);
  }
}
//Eliminar los nodos de posiciones pares de una lista trasladándolos en el mismo orden a una nueva lista
template <class T> void dll_t<T>::move_even(dll_t<T>& lista) {
  dll_node_t<T>* aux = get_head();
  while (aux != NULL) {
    dll_node_t<T>* nodo = aux;
    aux = aux -> get_next();
    if (aux != NULL) {
      dll_node_t<T>* nodo2 = erase(nodo);
      lista.push_back(nodo2);
      aux = aux -> get_next();
    }
  }
}
#endif  // DLLT_H_
