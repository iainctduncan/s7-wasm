# s7-wasm

This is a work in progress that will become a minimal example of using s7 Scheme with web assembly.

Status:
* evaluating scheme from JS and showing results works
* error output is not yet captured and displayed (though it shows in the console)

# Building :
You will need s7 and emscripten installed.

Build s7 to wasm:
emcc -c s7.c -o s7.wasm

Build the app:
emcc simple.c s7.wasm --js-library mergeinto.js -o simple.js -L. -I. -ldl -lm -s EXPORTED_RUNTIME_METHODS=['ccall','UTF8ToString']

Serve it up:
python -m http.server

View:
open localhost:8080/host.html

