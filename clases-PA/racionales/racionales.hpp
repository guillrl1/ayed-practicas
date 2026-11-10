// File: mat.hpp
#include <iostream>
#include <cassert>
#ifndef RACIONAL_HPP
#define RACIONAL_HPP

class Racional {
  public:
      Racional(int num, int den) : num_(num), den_(den) {
        assert(den_ != 0);
      }
      friend std::ostream& operator<<(std::ostream& os, const Racional& r) {
        os << r.num_ << "/" << r.den_;
        return os;
      }
      Racional suma (const Racional& r) {
        return Racional(num_ * r.den_ + r.num_ * den_, den_ * r.den_);
      }
      int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
      }
      void simplificar() {
        int mcd = gcd(num_, den_);
        num_ /= mcd;
        den_ /= mcd;
      }
      Racional multiplicar(const Racional& r) {
        return Racional(num_ * r.num_, den_ * r.den_);
      }
      Racional dividir(const Racional& r) {
        return Racional(num_ * r.den_, den_ * r.num_);
      }
    private:
      int num_, den_;
};

#endif
