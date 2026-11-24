#ifndef PSO_SYSTEM_MOVIE_TENDINGMOVIE_H
#define PSO_SYSTEM_MOVIE_TENDINGMOVIE_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TMovie;

// Plays ending_normal.sfd (start_ending_sequence creates it); finish_movie then moves the main loop on.
class TEndingMovie : public TObject {
public:
    TEndingMovie();
    virtual ~TEndingMovie();
    virtual void render();
    virtual void run_task();
    // The movie's end callback: destroys the movie and requests main phase 2, or queues 2 and requests 0x12
    // when ending_movie_active_flag is clear.
    static void finish_movie(TMovie *movie);
};
LAYOUT_ASSERT(TEndingMovie_size, sizeof(TEndingMovie) == 0x1C);

#endif
