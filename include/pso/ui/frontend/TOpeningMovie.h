#ifndef PSO_UI_FRONTEND_TOPENINGMOVIE_H
#define PSO_UI_FRONTEND_TOPENINGMOVIE_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Main phase 3's task (init_movie_phase creates it): plays the opening movie of opening_movie_path_table,
// whose end callback set_movie_finished_flag lets update_movie_phase move the main loop on.
class TOpeningMovie : public TObject {
public:
    TOpeningMovie();
    virtual ~TOpeningMovie();
    virtual void render();
    virtual void run_task();
    u8 pad_1C[0x8];
};
LAYOUT_ASSERT(TOpeningMovie_size, sizeof(TOpeningMovie) == 0x24);

#endif
