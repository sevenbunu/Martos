#include <string.h>
#include <stdbool.h>

extern void add_task(void (*setup_fn)(), void (*loop_fn)(), bool (*stop_condition_fn)());
extern void start_task_manager();
extern void init_system();

int counter = 0;

void setup_fn() {
}

void loop_fn() {
    counter++;
}

bool stop_condition_fn() {
    if (counter == 50) {
        return true;
    }

    return false;
}

int main( void ) {
    init_system();
    add_task(setup_fn, loop_fn, stop_condition_fn);
    start_task_manager();

    // (Should never be reached)
    return 0;
}

// Application entry point / startup logic.
void __attribute__( ( noreturn ) ) call_start_cpu0() {

    // Done, branch to main
    main();
    // (Should never be reached)
    while( 1 ) {}
}
