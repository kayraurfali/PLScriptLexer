flex -o Source/scanner.cpp Source/scanner.l
cmake -B build -G Ninja -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=bin
cmake --build build --config=Release -j16
cmake --install build

cd bin
./PLScriptCompiler
