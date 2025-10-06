import pylinearfold


def test_pylinearfold():
    res = pylinearfold.fold("GGGGAAAACCCC")
    assert res.structure == "((((....))))"
    assert res.score == -5.4


def test_pylinearpartition():
    res = pylinearfold.fold("GGGGAAAACCCC")
    assert res < 1.0
