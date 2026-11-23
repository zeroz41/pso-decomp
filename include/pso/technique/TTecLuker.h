#ifndef PSO_TECHNIQUE_TTECLUKER_H
#define PSO_TECHNIQUE_TTECLUKER_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

class TUnk_804C4450;
class TUnk_804CC9D4;
class TUnk_804CCA0C;

// The telepipe technique: places a pipe (field + visual) near its caster and, once a player
// selects it, warps everyone back to the city. Field names below are inferred from use.
struct TTecLuker : public TTecCircle {
    TTecLuker(saddr source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecLuker();
    virtual void vfunc_6(void *);
    virtual void run_task();
    TUnk_804C4450 *placement;  // the placement search a local caster starts for the pipe
    TUnk_804CC9D4 *field;  // the selectable field at pipe_pos
    s16 floor;  // get_current_floor() when cast
    u16 traveller;  // the client the pipe belongs to (local_client_id or the caster)
    TUnk_804CCA0C *visual;
    Vec pipe_pos;
    s32 phase;  // 0 placing, 1 open, 2 warping, 3 warp, 4 done
    s32 warp_frames;  // frames spent in phase 2
    static void apply_all_players();
    static void create_for_player(int arg0, saddr arg1);
    void init_fields(s16 name);
    void send_telepipe_packet();
    void create(void *pos, void *target, void *level);
    void setup_telepipe_field();
    void send_swapped_telepipe_packet();
    void byteswap_telepipe_packet();
    void set_state(s32 v);
    static s32 is_parents_unqueued(uaddr object);
};

LAYOUT_ASSERT(TTecLuker_size, sizeof(TTecLuker) == 0x110);

void create_quest_telepipe_for_client(u16 client);
#endif
