#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerFootStamp.h"
#include "types.h"
#include <stdlib.h>
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/map/CsnQuery.h"
#include "pso/map/FloorArea.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8DE0.h"
#include "pso/unk/text_803D8F74.h"

TPlayerFootStamp::~TPlayerFootStamp() {}

// Per player class (in the order of the switch below): the footprint's
// length, width and offset along the facing, before the height scaling.
const Vec lbl_804707F8[12] = {
    { 1.0f, 1.0f, 1.0f }, { 0.8f, 0.9f, 1.0f }, { 1.1f, 1.1f, 1.0f }, { 0.8f, 0.6f, 1.0f },
    { 1.0f, 1.0f, 1.0f }, { 0.8f, 0.9f, 1.0f }, { 1.7f, 1.7f, 1.0f }, { 0.9f, 0.6f, 1.0f },
    { 1.0f, 1.0f, 1.0f }, { 0.8f, 0.9f, 1.0f }, { 0.8f, 0.9f, 1.0f }, { 0.9f, 0.9f, 1.0f },
};

// Per player class: the TObjPlayer::m_d48 value the sizes above are for and
// how much the footprint grows per unit above it.
struct FootStampHeightScale {
    f32 base;
    f32 rate;
};

const FootStampHeightScale lbl_80470888[12] = {
    { 17.5f, 0.04f }, { 16.0f, 0.05f }, { 19.75f, 0.057f }, { 15.5f, 0.04f },
    { 18.0f, 0.05f }, { 16.25f, 0.049f }, { 19.0f, 0.05f }, { 16.75f, 0.045f },
    { 17.65f, 0.035f }, { 16.0f, 0.067f }, { 18.25f, 0.057f }, { 15.75f, 0.057f },
};

const char *TPlayerFootStamp::class_name = "TPlayerFootStamp";

TPlayerFootStamp::TPlayerFootStamp(TObjPlayer *player, s32 side) : TObject(tl_07) {
    f32 scale;
    f32 length;
    f32 width;
    f32 offset;
    s32 *rotation;
    CsnHit *ground;
    s16 angle;
    Vec dir[2];
    s32 yaw;
    s32 pitch;
    f32 fx, fy, fz;
    f32 ux, uy, uz;

    m_name = class_name;
    switch (get_current_floor_area()) {
    case AREA_SEASIDE:
        color = 0xFF402A20;
        break;
    case AREA_SEABED_UPPER:
        color = 0xFF001923;
        break;
    case AREA_SEABED_LOWER:
        color = 0xFF050300;
        break;
    default:
        color = 0xFF282828;
        break;
    }
    this->side = side;

    if (get_entity_id(player) < 4) {
        switch (player->get_class_index()) {
        case 1:
            sub_802B0204(0);
            scale = lbl_80470888[1].rate * (player->m_d48 - lbl_80470888[1].base) + 1.0f;
            length = lbl_804707F8[1].x * scale;
            width = lbl_804707F8[1].y * scale;
            offset = lbl_804707F8[1].z * scale;
            break;
        case 2:
            sub_802B0204(1);
            scale = lbl_80470888[2].rate * (player->m_d48 - lbl_80470888[2].base) + 1.0f;
            length = lbl_804707F8[2].x * scale;
            width = lbl_804707F8[2].y * scale;
            offset = lbl_804707F8[2].z * scale;
            break;
        case 9:
            sub_802B0204(1);
            scale = lbl_80470888[3].rate * (player->m_d48 - lbl_80470888[3].base) + 1.0f;
            length = lbl_804707F8[3].x * scale;
            width = lbl_804707F8[3].y * scale;
            offset = lbl_804707F8[3].z * scale;
            break;
        case 3:
            sub_802B0204(0);
            scale = lbl_80470888[4].rate * (player->m_d48 - lbl_80470888[4].base) + 1.0f;
            length = lbl_804707F8[4].x * scale;
            width = lbl_804707F8[4].y * scale;
            offset = lbl_804707F8[4].z * scale;
            break;
        case 11:
            sub_802B0204(0);
            scale = lbl_80470888[5].rate * (player->m_d48 - lbl_80470888[5].base) + 1.0f;
            length = lbl_804707F8[5].x * scale;
            width = lbl_804707F8[5].y * scale;
            offset = lbl_804707F8[5].z * scale;
            break;
        case 4:
            sub_802B0204(1);
            scale = lbl_80470888[6].rate * (player->m_d48 - lbl_80470888[6].base) + 1.0f;
            length = lbl_804707F8[6].x * scale;
            width = lbl_804707F8[6].y * scale;
            offset = lbl_804707F8[6].z * scale;
            break;
        case 5:
            sub_802B0204(1);
            scale = lbl_80470888[7].rate * (player->m_d48 - lbl_80470888[7].base) + 1.0f;
            length = lbl_804707F8[7].x * scale;
            width = lbl_804707F8[7].y * scale;
            offset = lbl_804707F8[7].z * scale;
            break;
        case 10:
            sub_802B0204(0);
            scale = lbl_80470888[8].rate * (player->m_d48 - lbl_80470888[8].base) + 1.0f;
            length = lbl_804707F8[8].x * scale;
            width = lbl_804707F8[8].y * scale;
            offset = lbl_804707F8[8].z * scale;
            break;
        case 6:
            sub_802B0204(0);
            scale = lbl_80470888[9].rate * (player->m_d48 - lbl_80470888[9].base) + 1.0f;
            length = lbl_804707F8[9].x * scale;
            width = lbl_804707F8[9].y * scale;
            offset = lbl_804707F8[9].z * scale;
            break;
        case 7:
            sub_802B0204(0);
            scale = lbl_80470888[10].rate * (player->m_d48 - lbl_80470888[10].base) + 1.0f;
            length = lbl_804707F8[10].x * scale;
            width = lbl_804707F8[10].y * scale;
            offset = lbl_804707F8[10].z * scale;
            break;
        case 8:
            sub_802B0204(0);
            scale = lbl_80470888[11].rate * (player->m_d48 - lbl_80470888[11].base) + 1.0f;
            length = lbl_804707F8[11].x * scale;
            width = lbl_804707F8[11].y * scale;
            offset = lbl_804707F8[11].z * scale;
            break;
        case 0:
        default:
            sub_802B0204(0);
            scale = lbl_80470888[0].rate * (player->m_d48 - lbl_80470888[0].base) + 1.0f;
            length = lbl_804707F8[0].x * scale;
            width = lbl_804707F8[0].y * scale;
            offset = lbl_804707F8[0].z * scale;
            break;
        }

        verts[0].u = 0.0f;
        verts[0].v = 0.0f;
        verts[0].color = color;
        verts[1].u = 0.0f;
        verts[1].v = 1.0f;
        verts[1].color = color;
        verts[2].u = 1.0f;
        verts[2].v = 0.0f;
        verts[2].color = color;
        verts[3].u = 1.0f;
        verts[3].v = 1.0f;
        verts[3].color = color;

        // TBoss4DarkFalz::get_hit_data returns &rotation_x of any TObjBase.
        rotation = (s32 *)((TBoss4DarkFalz *)player)->get_hit_data();
        VecCopy(&position, (Vec *)player->get_position_ptr());
        position.y += 5.0f;
        ground = (CsnHit *)csnVecterUnder((s32)&position, 0x16EF);
        if (ground == NULL) {
            queue_destruction();
            return;
        }
        angle = rotation[1];
        VecCopy(&position, &ground->contact->point);
        position.y += 0.5f * ((1.0f / 32768.0f) * rand()) + 0.5f;
        if (this->side != 0) {
            if (this->side == 1) {
                angle += 0x8000;
            } else {
                queue_destruction();
                return;
            }
        }
        position.x += offset * cos_table_lookup(angle);
        position.z -= offset * sin_table_lookup(angle);

        dir[0].x = 0.0f;
        dir[0].y = 0.0f;
        dir[0].z = 1.0f;
        dir[1].x = 0.0f;
        dir[1].y = 1.0f;
        dir[1].z = 0.0f;
        direction_to_rotation_yx((u8 *)&ground->contact->normal, &yaw, &pitch);
        if (pitch < 0x2000 || pitch > 0x6000) {
            queue_destruction();
            return;
        }
        push_matrix();
        set_matrix_identity(NULL);
        rotate_matrix_y(NULL, rotation[1]);
        rotate_matrix_z(NULL, pitch);
        fn_803D8DE0(0, dir, dir, 2);
        pop_matrix();

        width *= 2.0f;
        length *= 2.0f;
        fx = dir[0].x;
        fy = dir[0].y;
        fz = dir[0].z;
        ux = dir[1].x;
        uy = dir[1].y;
        uz = dir[1].z;
        corners[0].x = fx * length + ux * width;
        corners[0].y = uy * width + fy * length;
        corners[0].z = uz * width + fz * length;
        corners[1].x = ux * width - fx * length;
        corners[1].y = uy * width - fy * length;
        corners[1].z = uz * width - fz * length;
        corners[2].x = -ux * width + fx * length;
        corners[2].y = -uy * width + fy * length;
        corners[2].z = -uz * width + fz * length;
        corners[3].x = -ux * width - fx * length;
        corners[3].y = -uy * width - fy * length;
        corners[3].z = -uz * width - fz * length;
        timer = 150;
    } else {
        queue_destruction();
        return;
    }
}

void *TPlayerFootStamp::create(void *player, void *side) {
    return new TPlayerFootStamp((TObjPlayer *)player, (s32)side);
}

extern u32 player_footstamp_texture_gvm_handle;

void TPlayerFootStamp::free_instance() {
    if ((u32) player_footstamp_texture_gvm_handle != 0U) {
        release_texture_list((GinjaTextureList *)player_footstamp_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(player_footstamp_texture_gvm_handle);
        player_footstamp_texture_gvm_handle = 0U;
    }
}
