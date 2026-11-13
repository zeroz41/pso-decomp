#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"

void *TObjEneRe7Berura::spawn_punch(void *arg0) {
    return new TObjEneRe7BeruraPunch((TObject *)arg0, (TObjBase *)arg0);
}
