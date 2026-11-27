#include "pso/network/FloorEventCommand.h"
#include "pso/render/NinjaUtil.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/collision/TObjEvtCollision.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"

#pragma readonly_strings on


extern "C" {
const char *evt_collision_class_name = "TObjEvtCollision";

s32 TObjEvtCollision::is_any_player_in_range(f32 range_sq) {
    s32 i;
    TObjPlayer *player;
    TObjPlayer *local_player;

    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i += 1) {
            player = static_cast<TObjPlayer *>(get_player_by_client_id(i));
            if ((player != NULL) && (xyz_distance_squared(&player->position, &position) < range_sq)) {
                return 1;
            }
        }
    } else {
        local_player = static_cast<TObjPlayer *>(get_player_by_client_id(local_client_id));
        if ((local_player != NULL) && (xyz_distance_squared(&local_player->position, &position) < range_sq)) {
            return 1;
        }
    }
    return 0;
}


void *TObjEvtCollision::create(void *set_data) {
    return new TObjEvtCollision(tl_05, set_data);
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

TObjEvtCollision::TObjEvtCollision(TObject *parent, void *set_data) : TObjCollidable(parent) {
    m_name = evt_collision_class_name;
    apply_object_set_data(set_data);
    trigger_radius = scale.x;
    event_id = (s32)set_params[0];
    countdown = 3;
    disallow_rendering();
}

