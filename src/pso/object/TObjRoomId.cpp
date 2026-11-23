#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/render_util.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/TObjRoomId.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"


// The class name, then the direction run_task rotates by the object's yaw into normal, the plane
// normal its vec3_dot side test uses (room_id_base_normal is an inferred name).
const char *TObjRoomId__name = "TObjRoomId";
static const Vec room_id_base_normal = {0.0f, 0.0f, -1.0f};

extern "C" {
u16 TObjRoomId__sub_801A1DB8(u16 x);
}

s32 TObjRoomId::is_player_in_range(u16 id, f32 range_squared) {
    TObjPlayer *p = get_player_by_client_id(id);
    if (p == 0) {
        return 0;
    }
    return horizontal_distance_squared(&p->position, &position) < range_squared;
}

// The trigger sphere is scale.x * 10 around the object; normal is the facing
// run_task turns by the yaw (set param 5).
#pragma push
#pragma fp_contract on
void TObjRoomId::render() {
    if (TObjPlayer::check_demo_mode() != 0) {
        NJS_ARGB c1 = { 0.5f, 1.0f, 1.0f, 0.0f };
        NJS_ARGB c2 = { 0.5f, 0.0f, 1.0f, 1.0f };
        Vec end;
        debug_draw_sphere(&position, &c2, 2.0f * (10.0f * scale.x));
        debug_draw_uniform_scaled(&position, &c1, 10.0f * scale.x);
        end.x = 10.0f * normal.x + position.x;
        end.y = 10.0f * normal.y + position.y;
        end.z = 10.0f * normal.z + position.z;
        debug_draw_line(&position, &end, 0xFFFF0000, 0xFFFF0000);
        debug_draw_sphere(&end, &c2, 2.0f);
        draw_debug_line(0x13, 0x1C, "<- SCL_TAMA");
        draw_debug_line(0x13, 0x1D, "<- + NUMBER");
        draw_debug_line(0x13, 0x1E, "<- - NUMBER");
        draw_debug_line(0x13, 0x22, "<- - 10000 : BLOCK ID ");
    }
}
extern u8 identity_matrix[];
void set_player_room_control_flag(TObjPlayer *player);
#pragma pop

#pragma push
#pragma fp_contract on
void TObjRoomId::run_task() {
    TObjRoomId *o = this;
    Vec v = room_id_base_normal;
    Vec d;
    s32 absent;
    f32 r;

    absent = 1;
    if (TObjPlayer::check_demo_mode() == 0) {
        for (s32 i = 0; i < 4; i++) {
            if (get_player_by_client_id(i) != NULL) {
                r = 10.0f * o->scale.x + 30.0f;
                if (o->is_player_in_range(i, r * r) != 0) {
                    absent = 0;
                }
            }
        }
    }
    if (TObjPlayer::check_demo_mode() == 0 && absent != 0) {
        return;
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, o->set_params[1]);
    matrix_mult_vec(0, &v, &o->normal);
    pop_matrices(1);
    for (s32 i = 0; i < 4; i++) {
        TObjPlayer *p = get_player_by_client_id(i);
        if (p == NULL) {
            continue;
        }
        r = 10.0f * o->scale.x;
        if (o->is_player_in_range(i, r * r) == 0) {
            continue;
        }
        d.x = p->position.x - o->position.x;
        d.y = 0.0f;
        d.z = p->position.z - o->position.z;
        if (vec3_dot(&d, &o->normal) > 0.0f) {
            if (o->set_params[2] == 0x10000) {
                p->room = (s16)o->scale.y;
                set_player_room_control_flag(p);
            } else {
                p->set_room((s16)o->scale.y);
            }
        } else {
            if (o->set_params[2] == 0x10000) {
                p->room = (s16)o->scale.z;
                set_player_room_control_flag(p);
            } else {
                p->set_room((s16)o->scale.z);
            }
        }
    }
}
#pragma pop

TObjRoomId::~TObjRoomId() {}


TObjRoomId::TObjRoomId(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjRoomId__name;
    apply_object_set_data(set_data);
    normal.x = 0.0f;
    normal.y = 0.0f;
    normal.z = 0.0f;
}

void *TObjRoomId::create(void *set_data) {
    return new TObjRoomId(tl_05, set_data);
}

void set_player_room_control_flag(TObjPlayer *player) {
    player->set_state_flags(0x02000000);
}

extern s32 local_client_id;

u16 TObjRoomId__sub_801A1DB8(u16 x) {
    u16 r;
    if (x == 0xFFFF) {
        r = 0xFFFF;
    } else {
        r = x & 0x5000;
    }
    return r;
}

s32 TObjPlayer::sub_801A1DDC() {
    if (is_split_screen() != 0) {
        return (u8)(1U);
    }
    return (u8)((u8) (this->entity_id == local_client_id));
}
