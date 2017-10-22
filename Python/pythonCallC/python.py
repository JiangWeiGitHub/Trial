import ctypes

so = ctypes.CDLL("./libtestc.so");
so.printHello();