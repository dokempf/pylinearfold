import pylinearfold


def test_pylinearfold():
    res = pylinearfold.fold("GGGGAAAACCCC")
    assert res["structure"] == "((((....))))"
    assert res["free_energy"] == -5.4


def test_pylinearpartition():
    res = pylinearfold.partition("GGGGAAAACCCC")
    assert res["structure"] == "((((....))))"
    assert -5.6 < res["free_energy"] < -5.5

    # Probability matrix should only show high probabilities
    # for 1-12, 2-11, 3-10, 4-9 pairs
    for i in range(1, 13):
        for j in range(1, 13):
            if i >= j:
                continue
            mask = (res["probabilities"]["i"] == i) & (res["probabilities"]["j"] == j)
            filtered = res["probabilities"][mask]

            if i + j == 13 and i < 5:
                assert filtered.size == 1
                assert filtered["prob"][0] > 0.8
            else:
                assert filtered.size == 0 or filtered["prob"][0] < 0.2
