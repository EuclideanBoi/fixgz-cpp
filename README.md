# fixgz-cpp
C++ implementation of fixgz, a utility for repairing corrupted gz files

# Build
It is recommended to build in 64-bit for improved memory utilization <br>
Clang++
```
clang++ main.cpp -o fixgz.exe -v --target=x86_64-w64-mingw32
```
G++
```
g++ main.cpp -o fixgz.o -m64
```

# Usage
```
./fixgz.exe inputfile.gz outputfile.gz
```
```
./fixgz.o inputfile.gz outputfile.gz
```
