/* compile with 'emcc -o test.wasm test.c'

webassembly functions can only receive integers as parameters or return integer values.

My approach is to instanciate the web assembly module, call malloc from within
the webassembly, then create a Javascript "typed array" view of the webassembly module's
heap with the values returned. 

Something like this:

var jsVariable;
var bufferSize = 20;

WebAssembly.instantiate([Javascript uint8 array of the binary .wasm file's contents]).then(wasm => {
  var jsVariable = new Float32Array(
    wasm.instance.exports.memory.buffer,
    wasm.instance.exports.getBufferAddress(bufferSize),
    bufferSize
  );
})

*/

#include <stdlib.h>   /* malloc, free */
#include <emscripten/em_macros.h>   /* EMSCRIPTEN_KEEPALIVE */
#include <wasi/api.h>   /* __wasi_exitcode_t */

int EMSCRIPTEN_KEEPALIVE getBufferAddress(int size) {
  return (int)(malloc(size * sizeof(float)));
}

int main(void) {} /*
  emscripten's runtime will automatically call main when the webassembly
  module is first instantiated. If you want to call webassembly code at a later
  time you have to create a different function annotated with EMSCRIPTEN_KEEPALIVE
*/
void __wasi_proc_exit(__wasi_exitcode_t rval) {}  /* to support WASI containers I believe you'll minimally need to define this function */
