SRC="src/main.cpp src/generator.cpp src/container/*.cpp"

g++ -o out ${SRC} -Isrc/ -Isrc/container
