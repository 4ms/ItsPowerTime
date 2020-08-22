import numpy
from scipy.io.wavfile import read
import data_compiler
filename = "shot-7.wav"
a = read(filename)
m = numpy.array(a[1])
data = {}
data[filename] = m

data_compiler.compile(filename, "Wav", data)

