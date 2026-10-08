Configure build
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

build
cmake --build build

run
./build/
