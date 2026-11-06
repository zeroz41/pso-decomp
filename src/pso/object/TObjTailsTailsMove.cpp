#pragma readonly_strings on
#include "pso/object/TObjTailsTailsMove.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
const char *TObjTailsTailsMove_name = "TObjTailsTailsMove";
f32 sin_table_lookup(s32);
}

#pragma push
#pragma fp_contract on
s32 TObjTailsTailsMove::interpolate_along_curve(f32 *vertex) {
    f32 z;
    f32 distance;
    f32 fraction;
    z = vertex[2];
    if ((z < -8.0f) || (z > -1.0f)) {
        return 0;
    }
    distance = z - -1.0f;
    fraction = distance / -7.0f;
    vertex[0] = (0.25f * fraction) * sin_table_lookup(m_phase + (s32) (-16384.0f * fraction)) + vertex[0];
    return 1;
}
#pragma pop

void TObjTailsTailsMove::transform_vertex_list() {
    f32 v[3];
    s32 stride;
    u32 *p;
    s32 i;
    s32 n;
    s32 kind;
    i = 0;
    p = m_vertices;
    do {
        switch ((u8)p[0]) {
        case 0x29:
            kind = 3;
            break;
        case 0x2C:
            kind = 4;
            break;
        default:
            kind = -1;
            break;
        }
        if (kind < 0) {
            return;
        }
        n = p[1] >> 16;
        stride = (kind + 3) * 4;
        p += 2;
        while (n > 0) {
            v[0] = bits_to_f32(p[0]);
            v[1] = bits_to_f32(p[1]);
            v[2] = bits_to_f32(p[2]);
            if (interpolate_along_curve(v) != 0) {
                p[0] = f32_bits(v[0]);
                p[1] = f32_bits(v[1]);
                p[2] = f32_bits(v[2]);
            }
            p = (u32 *)((u8 *)p + stride);
            n--;
        }
        i++;
    } while (i < 1000);
}

void TObjTailsTailsMove::advance_phase() {
    transform_vertex_list();
    m_phase += 0x444;
}

void TObjTailsTailsMove::find_vertex_list() {
    if (m_player->m_cfc != 0) return;
    NJS_OBJECT *root = (NJS_OBJECT *)m_player->model;
    if (root == NULL) return;
    NJS_OBJECT *child = root->child;
    if (child == NULL) return;
    NJS_OBJECT *tail = child->child;
    if (tail == NULL) return;
    NJS_CNK_MODEL *model = (NJS_CNK_MODEL *)tail->model;
    if (model == NULL || model->vertex_list == NULL) return;
    m_vertices = (u32 *)model->vertex_list;
    m_state = 1;
}

void TObjTailsTailsMove::run_task() {
    switch (m_state) {
    case 0:
        find_vertex_list();
        return;
    case 1:
        advance_phase();
        return;
    }
}

TObjTailsTailsMove::~TObjTailsTailsMove() {}

TObjTailsTailsMove::TObjTailsTailsMove(TObjPlayer *player) : TObject(player) {
    m_name = TObjTailsTailsMove_name;
    m_player = player;
    m_state = 0;
}

TObjTailsTailsMove *TObjTailsTailsMove::create(TObjPlayer *player) {
    return new TObjTailsTailsMove(player);
}
