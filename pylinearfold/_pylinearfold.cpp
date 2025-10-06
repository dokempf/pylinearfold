#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <LinearFold.h>

#include <optional>
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(_pylinearfold, m)
{
  m.doc() = "Python Bindings for linearfold";

  py::class_<BeamCKYParser::DecoderResult>(m, "DecoderResult")
    .def_readonly("structure", &BeamCKYParser::DecoderResult::structure)
    .def_property_readonly("score",
                           [](BeamCKYParser::DecoderResult& self) {
                             return (double)self.score / -100.0;
                           })
    .def_readonly("num_states", &BeamCKYParser::DecoderResult::num_states)
    .def_readonly("time", &BeamCKYParser::DecoderResult::time);

  m.def(
    "fold",
    [](std::string seq,
       int beam_size,
       bool verbose,
       bool sharpturn,
       bool eval,
       std::optional<std::string> constraints,
       bool zuker,
       float delta,
       std::string shape,
       int dangles) {
      BeamCKYParser parser(beam_size,
                           !sharpturn,
                           verbose,
                           constraints.has_value(),
                           zuker,
                           delta,
                           shape,
                           false,
                           dangles);
      return parser.parse(seq, {});
    },
    py::arg("seq"),
    py::arg("beam_size") = 100,
    py::arg("verbose") = false,
    py::arg("sharpturn") = false,
    py::arg("eval") = false,
    py::arg("constraints") = std::nullopt,
    py::arg("zuker") = false,
    py::arg("delta") = 5.0,
    py::arg("shape") = "",
    py::arg("dangles") = 2);
}
