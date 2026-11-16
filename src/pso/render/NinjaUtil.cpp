#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80011014.h"

static u8 texlist_null_name[0x20];

void clear_texlist_names(NJS_TEXLIST *texlist) {
    u32 i;
    for (i = 0; i < texlist->nbTexture; i++) {
        texlist->textures[i].filename = texlist_null_name;
    }
}

f32 vec_set_length(Vec *v, f32 length) {
    f32 squared = vec_squared_length(v);
    if (squared > 1e-05f) {
        f32 current = newton_sqrtf(squared);
        f32 scale = length / current;
        v->x *= scale;
        v->y *= scale;
        v->z *= scale;
        return current;
    }
    return 0.0f;
}

f32 vec_xz_distance(Vec *a, Vec *b) {
    f32 dx = a->x - b->x;
    f32 dz = a->z - b->z;
    return newton_sqrtf(dx * dx + dz * dz);
}

f32 xz_distance_squared(const Vec *a, const Vec *b) {
    f32 dx = a->x - b->x;
    f32 dz = a->z - b->z;
    return dx * dx + dz * dz;
}

f32 xyz_distance_squared(const Vec *a, const Vec *b) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;
    return dz * dz + (dx * dx + dy * dy);
}

static s32 model_node_search_index;
static s32 model_node_search_target;
static NJS_OBJECT *model_node_search_result;
static s32 object_node_search_index;
static s32 object_node_search_target;
static NJS_OBJECT *object_node_search_result;

static void find_object_node_walk(NJS_OBJECT *node) {
    if (object_node_search_index == object_node_search_target) {
        object_node_search_result = node;
    }
    object_node_search_index++;
    if (object_node_search_result == NULL) {
        if (node->child != NULL) {
            find_object_node_walk(node->child);
        }
        if (node->sibling != NULL) {
            find_object_node_walk(node->sibling);
        }
    }
}

NJS_OBJECT *find_object_node(NJS_OBJECT *root, s32 index) {
    if (root == NULL) {
        return NULL;
    }
    object_node_search_target = index;
    object_node_search_index = 0;
    object_node_search_result = NULL;
    find_object_node_walk(root);
    return object_node_search_result;
}

static void find_model_node_walk(NJS_OBJECT *node) {
    if (model_node_search_index == model_node_search_target) {
        model_node_search_result = node;
    }
    model_node_search_index++;
    if (model_node_search_result == NULL) {
        if (node->child != NULL) {
            find_model_node_walk(node->child);
        }
        if (node->sibling != NULL) {
            find_model_node_walk(node->sibling);
        }
    }
}

s32 find_model_node(u32 root, s32 index) {
    NJS_OBJECT *node = (NJS_OBJECT *)root;
    if (node == NULL) {
        return NULL;
    }
    model_node_search_target = index;
    model_node_search_index = 0;
    model_node_search_result = NULL;
    find_model_node_walk(node);
    return (s32)model_node_search_result;
}

void debug_printf_nop(const char *format, ...) {}
