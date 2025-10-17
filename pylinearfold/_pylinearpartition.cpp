#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <LinearPartition.h>

namespace py = pybind11;

PYBIND11_MODULE(_pylinearpartition, m)
{
  m.doc() = "Python Bindings for linearpartition";

  m.def(
    "partition",
    [](std::string seq, int beam_size, bool verbose, bool sharpturn) {
      BeamCKYParser parser(
        beam_size, !sharpturn, verbose, "", "", false, 0.0, "", true);
      double free_energy = parser.parse(seq);

      using namespace pybind11::literals;
      return py::dict("structure"_a = parser.exported_structure,
                      "free_energy"_a = free_energy,
                      "probabilities"_a = parser.Pij);
    },
    py::arg("seq"),
    py::arg("beamsize") = 100,
    py::arg("verbose") = false,
    py::arg("sharpturn") = false);
}
