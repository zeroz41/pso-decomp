#ifndef PSO_TECHNIQUE_TTECLUKER_H
#define PSO_TECHNIQUE_TTECLUKER_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

class PositionPlacementQueue;
class TTelepipeSelectField;
class TTelepipeEffect;

// The telepipe technique: places a pipe (field + visual) near its caster and, once a player
// selects it, warps everyone back to the city. Field names below are inferred from use.
struct TTecLuker : public TTecCircle {
    TTecLuker(saddr source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecLuker();
    virtual void apply_to_target(TObjChara *);
    virtual void run_task();
    PositionPlacementQueue *placement;  // the placement search a local caster starts for the pipe
    TTelepipeSelectField *field;  // the selectable field at pipe_pos
    s16 floor;  // get_current_floor() when cast
    u16 traveller;  // the client the pipe belongs to (local_client_id or the caster)
    TTelepipeEffect *visual;
    Vec pipe_pos;
    s32 phase;  // 0 placing, 1 open, 2 warping, 3 warp, 4 done
    s32 warp_frames;  // frames spent in phase 2
    static void apply_all_players();
    static void create_for_player(int client, saddr pos);
    void create(void *pos, void *target, void *level);
    void setup_telepipe_field();
    void set_state(s32 v);
    static s32 is_parents_unqueued(uaddr object);
};

LAYOUT_ASSERT(TTecLuker_size, sizeof(TTecLuker) == 0x110);

void create_quest_telepipe_for_client(u16 client);
struct G_SetTelepipeState_6x68;

void handle_6x68_set_telepipe_state(G_SetTelepipeState_6x68 *command);

#endif
