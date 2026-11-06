#include "types.h"
#include "pso/system/movie/TMovie.h"

extern "C" {

int TMovie__sub_80143CC8(void);

void TMovie::flush_and_reset() { TMovie::flush_cache(); TMovie__sub_80143CC8(); }

}
