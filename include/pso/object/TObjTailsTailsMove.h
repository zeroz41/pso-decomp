#ifndef PSO_OBJECT_TOBJTAILSTAILSMOVE_H
#define PSO_OBJECT_TOBJTAILSTAILSMOVE_H

#include "pso/system/task/TObject.h"

class TObjPlayer;

class TObjTailsTailsMove : public TObject {
public:
    TObjTailsTailsMove(TObjPlayer *player);
    virtual ~TObjTailsTailsMove();
    virtual void run_task();

    void find_vertex_list();
    void advance_phase();
    void transform_vertex_list();
    s32 interpolate_along_curve(f32 *vertex);
    static TObjTailsTailsMove *create(TObjPlayer *player);

    TObjPlayer *m_player;
    u32 *m_vertices;
    s32 m_state;
    s32 m_phase;
};

#endif
