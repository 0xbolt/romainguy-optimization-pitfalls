import numpy as np
import pyperf

def np_sum():
    np.sum(np.arange(int(1e6)))

def py_sum():
    sum(range(int(1e6)))

runner = pyperf.Runner()
runner.bench_func('vanilla', py_sum)
runner.bench_func('numpy', np_sum)
