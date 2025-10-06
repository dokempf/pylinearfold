#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <LinearPartition.h>

namespace py = pybind11;

PYBIND11_MODULE(_pylinearpartition, m)
{
  m.doc() = "Python Bindings for linearpartition";
  m.def(
    "partition",
    [](std::string seq int beam_size, bool verbose, bool sharpturn) {
      BeamCKYParser parser(beam_size, !sharpturn, verbose);
      return parser.parse(seq);
    },
    py::arg("seq"));
}
