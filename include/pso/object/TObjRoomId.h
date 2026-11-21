#ifndef PSO_OBJECT_TOBJROOMID_H
#define PSO_OBJECT_TOBJROOMID_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// A room trigger: a player inside the scale.x * 10 sphere is moved to room
// scale.y or scale.z by the side of the plane through the object with the
// facing `normal` (set param 5 turns it).
struct TObjRoomId : public TObjBase {
    TObjRoomId(TObject *parent, void *set_data);
    virtual ~TObjRoomId();
    static void *create(void *set_data);
    virtual void render();
    virtual void run_task();
    s32 is_player_in_range(u16 id, f32 range_squared);
    void draw_debug_line(s32 row, s32 column, const char *format);
    Vec normal;
};

LAYOUT_ASSERT(TObjRoomId_size, sizeof(TObjRoomId) == 0x9C);
#endif
