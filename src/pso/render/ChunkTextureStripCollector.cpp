#include "types.h"
#include "pso/render/ChunkTextureStripCollector.h"
struct Model_800F5A50 { void *vlist; void *plist; };

struct Node_800F5A50 {
    u32 evalflags;
    Model_800F5A50 *model;
    f32 pos[3];
    s32 ang[3];
    f32 scl[3];
    Node_800F5A50 *child;
    Node_800F5A50 *sibling;
};

struct Count_800F5AC8 { s32 verts; s32 strips; };

struct StripRef_800F591C { s16 *strip; s16 *uv; };

extern "C" {
void count_model_strips_by_texture(void *ctx, Node_800F5A50 *node, void *arg);
void collect_model_strips_by_texture(void *ctx, Node_800F5A50 *node, void *arg);
extern s32 plist_texture_matches_filter;
extern StripRef_800F591C *plist_strip_write_ptr;
extern s16 *plist_strip_uv_write_ptr;

void collect_model_strips_by_texture(void *ctx, Node_800F5A50 *node, void *arg) {
    do {
        if (node->model != 0 && node->model->plist != 0) {
            ((void (*)(void *, void *, void *))collect_plist_strips_by_texture)(ctx, node->model->plist, arg);
        }
        if (node->child != 0) {
            collect_model_strips_by_texture(ctx, node->child, arg);
        }
        node = node->sibling;
    } while (node != 0);
}
}

void collect_plist_strips_by_texture(void *ctx, s16 *p, s32 tex) {
    s16 c;
    s16 type;
    u32 n;
    u32 i;
    s16 len;
    s32 k;
    while ((c = *p++) != 0xFF) {
        if ((c & 0xFF) < 8) {
            continue;
        }
        type = c & 0xFF;
        if (type < 0x10) {
            if ((*p++ & 0x1FFF) == tex) {
                plist_texture_matches_filter = 1;
            } else {
                plist_texture_matches_filter = 0;
            }
        } else if (type < 0x40) {
            s32 skip = *(u16 *) p;
            p++;
            p += skip;
        } else {
            s32 skip = *(u16 *) p;
            p++;
            if (plist_texture_matches_filter != 0 && type == 0x41) {
                plist_strip_write_ptr->strip = p;
                plist_strip_write_ptr->uv = plist_strip_uv_write_ptr;
                plist_strip_write_ptr++;
                n = *p++ & 0x3FFF;
                for (i = 0; i < n; i++) {
                    len = *p++;
                    if (len < 0) {
                        len = -len;
                    }
                    for (k = 0; k < len; k++) {
                        *plist_strip_uv_write_ptr++ = p[1];
                        *plist_strip_uv_write_ptr++ = p[2];
                        p += 3;
                    }
                }
            } else {
                p += skip;
            }
        }
    }
}

void count_model_strips_by_texture(void *ctx, Node_800F5A50 *node, void *arg) {
    do {
        if (node->model != 0 && node->model->plist != 0) {
            count_plist_strips_by_texture(ctx, node->model->plist, arg);
        }
        if (node->child != 0) {
            count_model_strips_by_texture(ctx, node->child, arg);
        }
        node = node->sibling;
    } while (node != 0);
}
void count_plist_strips_by_texture(void *ctx, void *plist, void *arg) {
    Count_800F5AC8 *cnt = (Count_800F5AC8 *) ctx;
    s16 *p = (s16 *) plist;
    s16 c;
    s32 skip;
    u32 n;
    u32 i;
    s16 len;
    while ((c = *p++) != 0xFF) {
        if ((c & 0xFF) < 8) {
            continue;
        }
        c = c & 0xFF;
        if (c < 0x10) {
            if ((*p++ & 0x1FFF) == (s32) arg) {
                plist_texture_matches_filter = 1;
            } else {
                plist_texture_matches_filter = 0;
            }
        } else if (c < 0x40) {
            skip = *(u16 *) p;
            p++;
            p += skip;
        } else {
            s32 size = *(u16 *) p;
            p++;
            if (plist_texture_matches_filter != 0 && c == 0x41) {
                cnt->strips++;
                n = *p++ & 0x3FFF;
                for (i = 0; i < n; i++) {
                    len = *p++;
                    if (len < 0) {
                        len = -len;
                    }
                    cnt->verts += len;
                    p += len * 3;
                }
            } else {
                p += size;
            }
        }
    }
}
