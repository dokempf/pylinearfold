import pylinearfold


def test_pylinearfold():
    res = pylinearfold.fold("GGGGAAAACCCC")
    assert res.structure == "((((....))))"
    assert res.score == -5.4
