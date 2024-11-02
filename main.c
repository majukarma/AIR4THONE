#include "interpreter.h"

int main() {
    Interpreter interpreter;
    init_interpret(&interpreter);
    repl(&interpreter);
    return 0;
}
