#include "types.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/memory.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/network/TLobby.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/window/TWindowLockOn.h"

StripUvRef *plist_strip_write_ptr;
s16 *plist_strip_uv_write_ptr;
s32 plist_texture_matches_filter;

void StripBufferPair::collect_model_strips_by_texture(NJS_OBJECT *node, s32 texture_filter) {
    do {
        NJS_CNK_MODEL *model = node->chunk_model;
        if (model != NULL && model->polygon_list != NULL) {
            collect_plist_strips_by_texture(model->polygon_list, texture_filter);
        }
        if (node->child != 0) {
            collect_model_strips_by_texture(node->child, texture_filter);
        }
        node = node->sibling;
    } while (node != 0);
}

void StripBufferPair::collect_plist_strips_by_texture(s16 *plist, s32 texture_filter) {
    s16 c;
    s16 type;
    u32 n;
    u32 i;
    s16 len;
    s32 k;
    while ((c = *plist++) != 0xFF) {
        if ((c & 0xFF) < 8) {
            continue;
        }
        type = c & 0xFF;
        if (type < 0x10) {
            if ((*plist++ & 0x1FFF) == texture_filter) {
                plist_texture_matches_filter = 1;
            } else {
                plist_texture_matches_filter = 0;
            }
        } else if (type < 0x40) {
            s32 skip = *(u16 *) plist;
            plist++;
            plist += skip;
        } else {
            s32 skip = *(u16 *) plist;
            plist++;
            if (plist_texture_matches_filter != 0 && type == 0x41) {
                plist_strip_write_ptr->strip = plist;
                plist_strip_write_ptr->uv = plist_strip_uv_write_ptr;
                plist_strip_write_ptr++;
                n = *plist++ & 0x3FFF;
                for (i = 0; i < n; i++) {
                    len = *plist++;
                    if (len < 0) {
                        len = -len;
                    }
                    for (k = 0; k < len; k++) {
                        *plist_strip_uv_write_ptr++ = plist[1];
                        *plist_strip_uv_write_ptr++ = plist[2];
                        plist += 3;
                    }
                }
            } else {
                plist += skip;
            }
        }
    }
}

void StripBufferPair::count_model_strips_by_texture(NJS_OBJECT *node, s32 texture_filter) {
    do {
        NJS_CNK_MODEL *model = node->chunk_model;
        if (model != NULL && model->polygon_list != NULL) {
            count_plist_strips_by_texture(model->polygon_list, texture_filter);
        }
        if (node->child != 0) {
            count_model_strips_by_texture(node->child, texture_filter);
        }
        node = node->sibling;
    } while (node != 0);
}

void StripBufferPair::count_plist_strips_by_texture(s16 *plist, s32 texture_filter) {
    s16 c;
    s32 skip;
    u32 n;
    u32 i;
    s16 len;
    while ((c = *plist++) != 0xFF) {
        if ((c & 0xFF) < 8) {
            continue;
        }
        c = c & 0xFF;
        if (c < 0x10) {
            if ((*plist++ & 0x1FFF) == texture_filter) {
                plist_texture_matches_filter = 1;
            } else {
                plist_texture_matches_filter = 0;
            }
        } else if (c < 0x40) {
            skip = *(u16 *) plist;
            plist++;
            plist += skip;
        } else {
            s32 size = *(u16 *) plist;
            plist++;
            if (plist_texture_matches_filter != 0 && c == 0x41) {
                strip_count++;
                n = *plist++ & 0x3FFF;
                for (i = 0; i < n; i++) {
                    len = *plist++;
                    if (len < 0) {
                        len = -len;
                    }
                    uv_count += len;
                    plist += len * 3;
                }
            } else {
                plist += size;
            }
        }
    }
}

void StripBufferPair::scroll_uvs(s16 scroll_u, s16 scroll_v) {
    s32 i;
    s16 *strip;
    s16 *uv;
    u32 n;
    u32 j;
    s32 len;
    s32 k;
    scroll_u %= 256;
    scroll_v %= 256;
    for (i = 0; i < strip_count; i++) {
        strip = strips[i].strip;
        uv = strips[i].uv;
        n = *strip++ & 0x3FFF;
        for (j = 0; j < n; j++) {
            len = *strip++;
            if (len < 0) {
                len = -len;
            }
            for (k = 0; k < len; k++) {
                strip[1] = uv[0] + scroll_u;
                strip[2] = uv[1] + scroll_v;
                uv += 2;
                strip += 3;
            }
        }
    }
}

StripBufferPair::~StripBufferPair() {
    delete[] uvs;
    uvs = NULL;
    delete[] strips;
    strips = NULL;
}

extern "C" {

StripBufferPair::StripBufferPair(NJS_OBJECT *model, s32 texture_filter) {
    strip_count = 0;
    uv_count = 0;
    plist_texture_matches_filter = 0;
    count_model_strips_by_texture(model, texture_filter);
    strips = new StripUvRef[strip_count];
    uvs = new s16[uv_count * 2];
    plist_strip_write_ptr = strips;
    plist_strip_uv_write_ptr = uvs;
    plist_texture_matches_filter = 0;
    collect_model_strips_by_texture(model, texture_filter);
}
void TObjEnemy::clear_lobby_object_state() {
    EnemyStateRecord record;
    if (this->exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.damage = 0;
        this->exchange_object_state(&record, 0);
    }
}

}
