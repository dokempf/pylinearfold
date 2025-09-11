#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pylinearfold/pylinearfold.hpp"

namespace py = pybind11;

namespace pylinearfold {

PYBIND11_MODULE(_pylinearfold, m)
{
  m.doc() = "Python Bindings for pylinearfold";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace pylinearfold
