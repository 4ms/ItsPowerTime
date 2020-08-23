import sys
import numpy
from scipy.io.wavfile import read
import data_compiler

def make_c_header(filename):
    a = read(filename)
    m = numpy.array(a[1])
    data = {}
    arrayname = filename[:-4]
    data[arrayname] = m
    data_compiler.compile(arrayname, "Wav", data)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        filename = sys.argv[1]
        print("Using input file: "+filename)
        make_c_header(filename)
    else:
        print("Give the name of a .wav file")

