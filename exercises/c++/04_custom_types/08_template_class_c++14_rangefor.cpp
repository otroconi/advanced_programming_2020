#include <iostream>
#include <string>
//Improve of the vector class using c++14 features

template <typename T>
class Vector {
  T* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new T[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  std::size_t size() const { return _size; }

  auto& operator[](const std::size_t i) { return elem[i]; } //using deduced type c++14 (replacing T& --> auto&)

  // try to comment this line and recompile
  const auto& operator[](const std::size_t i) const { return elem[i]; }
};

template <typename T>
auto& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name
  pv->operator[](4) = 100'160.07; // using the single-quote character as a digit separator
  pv->operator[](2) = 1'005'006.77;

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555'005;

  std::cout << v << std::endl;

  return 0;
}
