#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace pylinearfold {

PYBIND11_MODULE(_pylinearfold, m)
{
  m.doc() = "Python Bindings for pylinearfold";
}

} // namespace pylinearfold
