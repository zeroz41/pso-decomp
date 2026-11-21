#include "pso/network/FloorEventCommand.h"
#include "pso/render/NinjaUtil.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/collision/TObjEvtCollision.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on


extern "C" {
const char *TObjEvtCollision__class_name = "TObjEvtCollision";
u8 *__ct__16TObjEvtCollisionFll(TObjEvtCollision *arg0, s32 arg1, s32 arg2);
extern s32 local_client_id;
void *TObjEvtCollision__create(void *arg0);
void *get_player_by_client_id(s32 i);

s32 TObjEvtCollision::is_any_player_in_range(f32 farg0) {
    s32 i;
    TObjPlayer *player;
    TObjPlayer *local_player;

    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i += 1) {
            player = static_cast<TObjPlayer *>(get_player_by_client_id(i));
            if ((player != NULL) && (xyz_distance_squared(&player->position, &position) < farg0)) {
                return 1;
            }
        }
        goto block_10;
    }
    local_player = static_cast<TObjPlayer *>(get_player_by_client_id(local_client_id));
    if ((local_player != NULL) && (xyz_distance_squared(&local_player->position, &position) < farg0)) {
        return 1;
    }
block_10:
    return 0;
}


void *TObjEvtCollision__create(void *arg0) {
    void *o = TObject::operator new(0xB8);
    if (o != NULL) {
        o = __ct__16TObjEvtCollisionFll((TObjEvtCollision *)((u8 *)o), (saddr)tl_05, (saddr)arg0);
    }
    return o;
}

void TObjEvtCollision::render() {  }

void TObjEvtCollision::run_task() {
    G_FloorEvent_6x67 pkt;
    if (--countdown <= 0) {
        if (is_any_player_in_range(trigger_radius * trigger_radius) == 1) {
            pkt.init();
            pkt.header.client_id = entity_id;
            pkt.floor = get_current_floor();
            pkt.event_id = set_params[0];
            pkt.sender_client_id = local_client_id;
            pkt.send();
            set_event_source_flag(8);
            queue_destruction();
        }
    }
}

}
TObjEvtCollision::~TObjEvtCollision() {

}

TObjEvtCollision::TObjEvtCollision(saddr arg1, saddr arg2) : TObjCollidable((TObject *)arg1) {
    this->m_name = TObjEvtCollision__class_name;
    ((TObjEvtCollision *)(this))->apply_object_set_data((void *)arg2);
    trigger_radius = scale.x;
    this->m_b0 = (s32) this->set_params[0];
    countdown = 3;
    this->disallow_rendering();
}

