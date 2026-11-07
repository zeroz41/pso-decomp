#ifndef PSO_UI_FRONTEND_TADCHRSELMOVEPLATEGC_H
#define PSO_UI_FRONTEND_TADCHRSELMOVEPLATEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdChrSelMovePlateGC : public TObject {
public:
    virtual ~TAdChrSelMovePlateGC();
    virtual void run_task();
    virtual void render();
public:
    void clear_entries();
    void init_plate_rects();
    void draw_move_plate_quads();
};

#endif
