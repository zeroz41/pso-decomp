#ifndef PSO_OBJECT_TOBJROOMID_H
#define PSO_OBJECT_TOBJROOMID_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// A room trigger: a player inside the scale.x * 10 sphere is moved to room
// scale.y or scale.z by the side of the plane through the object with the
// facing `normal` (set param 5 turns it).
struct TObjRoomId : public TObjBase {
    TObjRoomId(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjRoomId();
    static void *create(ObjectSetData *set_data);
    virtual void render();
    virtual void run_task();
    s32 is_player_in_range(u16 id, f32 range_squared);
    void draw_debug_line(s32 row, s32 column, const char *format);
    Vec normal;
};

// The kind bits (0x5000) of an entity id, 0xFFFF for none; 0 means a player.
u16 get_entity_id_kind(u16 entity_id);

LAYOUT_ASSERT(TObjRoomId_size, sizeof(TObjRoomId) == 0x9C);

BOOL is_item_light_interaction_blocked(void);
// TRUE when `object` is the room id object whose debug lines are drawn.
s32 is_current_room(void *object);

#endif
