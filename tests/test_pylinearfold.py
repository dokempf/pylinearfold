import pylinearfold


def test_pylinearfold():
    res = pylinearfold.fold("GGGGAAAACCCC")
    assert res["structure"] == "((((....))))"
    assert res["free_energy"] == -5.4


def test_pylinearpartition():
    res = pylinearfold.partition("GGGGAAAACCCC")
    assert res["structure"] == "((((....))))"
    assert -5.6 < res["free_energy"] < -5.5
