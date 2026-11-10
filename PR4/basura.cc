void sll_t<T>::reverse(sll_node_t<T>* p) {
  if(p->get_next() == NULL) head_ = p;
  else {
    set_next(reverse(p->get_next));
  }
}