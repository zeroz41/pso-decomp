#include "types.h"
#include "pso/unk/text_802A8210.h"
#include "pso/misc/TScene_80205AE8.h"
#include "pso/misc/TScene.h"

struct Cyc_80205D24 { u16 id; u16 reserved; s16 texture; s16 index; s32 timer; };

struct Uv_80205DE4 { u16 id; };

#include "pso/misc/TSceneMaterial.h"

struct Node_80205AEC { u32 flags; void *obj; u32 tex; u16 id; u8 b; u8 c; };

struct Info_80205AEC { u8 a0; u8 a1; u8 tex; u8 b; u8 c; };

struct Def_80206058 { u16 id, texture; f32 u, v, du, dv; };

extern "C" {
u8 *construct_pvr_wave__6TSceneFPvPvPvii(void *, s32, s32, s32, s32);
u8 *__nw__7TObjectFUl(s32);
extern void **TScene__texture_wave_resource;
extern void* TScene__texture_animation_buffer;
s32 load_texture_sequence_frame(void *task, Cyc_80205D24 *c);
s32 find_uv_animation__6TSceneFPvPv(void *task, Uv_80205DE4 *uv);
extern SceneMaterialRoot* TScene__data_805D5FCC;
Info_80205AEC *find_material_entry_by_id__6TSceneFPvUs(void *, u16);
extern u32 lbl_8044A800[];
extern u8 lbl_8044A80C[];
SceneMaterialNode* resolve_indirect_node_record(void*,SceneMaterialStatic*);
SceneMaterialNode* resolve_indirect_object_record(void*,SceneMaterialAnimated*);

void TScene__sub_80205AE8(void) {  }

void TScene::init_material_nodes() {
    SceneMaterialSection *sec;
    s32 i;
    SceneMaterialStatic *st;
    s32 j;
    Node_80205AEC *node;
    Info_80205AEC *info;
    void *o;
    SceneMaterialAnimated *an;
    s32 j2;
    Node_80205AEC *node2;
    Info_80205AEC *info2;
    void *o2;
    if (TScene__data_805D5FCC != NULL) {
        for (i = 0, sec = TScene__data_805D5FCC->sections; i < TScene__data_805D5FCC->count; i++, sec++) {
            for (j = 0, st = sec->objects; j < sec->count; j++, st++) {
                if (st->flags & 0x200) {
                    node = (Node_80205AEC *)st->node;
                    if (node->obj == NULL) {
                        info = find_material_entry_by_id__6TSceneFPvUs(this, node->id);
                        if (info != NULL) {
                            o = __nw__7TObjectFUl(0x20);
                            if (o != NULL) {
                                o = fn_802A8210((u8 *)o, info->c, (u8 *)this);
                            }
                            node->obj = o;
                            node->tex = lbl_8044A800[info->tex];
                            node->b = lbl_8044A80C[info->b];
                            node->c = info->c;
                        } else {
                            node->obj = 0;
                            node->tex = 0;
                            node->b = 0;
                            node->c = 0;
                        }
                    }
                }
            }
            for (j2 = 0, an = sec->animated; j2 < sec->animatedCount; j2++, an++) {
                if (an->flags & 0x200) {
                    node2 = (Node_80205AEC *)an->node;
                    if (node2->obj == NULL) {
                        info2 = find_material_entry_by_id__6TSceneFPvUs(this, node2->id);
                        if (info2 != NULL) {
                            o2 = __nw__7TObjectFUl(0x20);
                            if (o2 != NULL) {
                                o2 = fn_802A8210((u8 *)o2, info2->c, (u8 *)this);
                            }
                            node2->obj = o2;
                            node2->tex = lbl_8044A800[info2->tex];
                            node2->b = lbl_8044A80C[info2->b];
                            node2->c = info2->c;
                        } else {
                            node2->obj = 0;
                            node2->tex = 0;
                            node2->b = 0;
                            node2->c = 0;
                        }
                    }
                }
            }
        }
    }
}

void TScene::create_texture_wave_tasks(s32 arg0) {
  s8 *new_var;
  s16 temp_r0;
  u8 *temp_r3;
  u8 *var_r31;
  var_r31 = (u8 *) (*TScene__texture_wave_resource);
  do
  {
    new_var = (s8 *) var_r31;
    temp_r3 = (u8 *) __nw__7TObjectFUl(0x38);
    if (temp_r3 != 0)
    {
      construct_pvr_wave__6TSceneFPvPvPvii(temp_r3, arg0, *((s32 *) (((s8 *) var_r31) + 4)), *((s32 *) (((s8 *) var_r31) + 8)), (s32) (*((s16 *) (((s8 *) var_r31) + 0))));
    }
    temp_r0 = *((s16 *)(new_var + 0xC));
    var_r31 += 0xC;
  }
  while (temp_r0 >= 0);
}

s32 load_texture_sequence_frame(void *task, Cyc_80205D24 *c) {
    s16 *p = (*(s16 * *)&TScene__texture_animation_buffer);
    while (p[0] != -1) {
        if (p[0] & 1) {
            p += p[1] / 2 + 2;
            continue;
        }
        if (p[0] & 2) {
            if (c->id == p[2]) {
                if (c->index >= p[3]) {
                    c->index = 0;
                }
                p += c->index * 2 + 4;
                c->texture = p[0];
                c->timer = p[1];
                return 1;
            }
            p += p[1] / 2 + 2;
            continue;
        }
        return 0;
    }
    return 0;
}

s32 find_uv_animation__6TSceneFPvPv(void *task, Uv_80205DE4 *uv) {
    s16 *p;
    s16 n = 0;
    u16 *rec = NULL;
    p = (*(s16 * *)&TScene__texture_animation_buffer);
    while (p[0] != -1) {
        if (p[0] & 1) {
            n = p[2];
            rec = (u16 *)(p + 4);
            break;
        }
        if (p[0] & 2) {
            p += p[1] / 2 + 2;
        } else {
            return 0;
        }
    }
    while (n > 0) {
        if (rec[0] == uv->id) {
            ((TScene *)uv)->copy_header_and_vec(rec);
            return 1;
        }
        rec = (u16 *)((u8 *)rec + 0x14);
        n--;
    }
    return 0;
}

void TScene::copy_header_and_vec(void* q) { *(u16 *)&this->m_name = *(u16*)((char*)q + 0x0); *(u16*)((char*)this + 0x2) = *(u16*)((char*)q + 0x2); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); }

void TScene__sub_80205ECC(void) {
    s32 i;
    s32 j;
    SceneMaterialUv *uv;
    s32 k;
    SceneMaterialUv *uv2;
    if (TScene__data_805D5FCC != NULL) {
        for (i = 0; i < TScene__data_805D5FCC->count; i++) {
            SceneMaterialSection *sections = TScene__data_805D5FCC->sections;
            for (j = 0; j < sections[i].count; j++) {
                if (sections[i].objects[j].flags & 0x20) {
                    uv = sections[i].objects[j].uv;
                    if (uv->buffer != NULL) {
                        ((TScene *)uv->buffer)->destroy_buffers(1);
                        uv->buffer = NULL;
                    }
                }
            }
            for (k = 0; k < sections[i].animatedCount; k++) {
                if (sections[i].animated[k].flags & 0x20) {
                    uv2 = sections[i].animated[k].uv;
                    if (uv2->buffer != NULL) {
                        ((TScene *)uv2->buffer)->destroy_buffers(1);
                        uv2->buffer = NULL;
                    }
                }
            }
        }
    }
}

void TScene__sub_80205FD0(void) {  }

}

void TScene::initialize_fmt2_materials() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    void *task = this;
    SceneMaterialAnimated *anim;
    s32 j;
    if (!TScene__texture_animation_buffer || !TScene__data_805D5FCC) return;
    room = TScene__data_805D5FCC->sections;
    for (section = 0; section < TScene__data_805D5FCC->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20) {
                SceneMaterialUv *uv = object->uv;
                if (uv->buffer) continue;
                Def_80206058 def;
                def.id = uv->id;
                if (find_uv_animation__6TSceneFPvPv(task, (Uv_80205DE4 *)&def) == 1) {
                    uv->id = def.id; uv->texture = def.texture;
                    uv->u = def.u; uv->v = def.v; uv->du = def.du; uv->dv = def.dv;
                    SceneMaterialNode *node = resolve_indirect_node_record(task, object);
                    void *buffer = ::operator new(20);
                    if (buffer) buffer = ((TScene *)buffer)->init_buffers((s32)node, uv->texture);
                    uv->buffer = buffer;
                } else {
                    object->flags &= ~0x20;
                }
            }
            if ((object->flags & 0x40) && !load_texture_sequence_frame(task, (Cyc_80205D24 *)object->cycle)) object->flags &= ~0x40;
        }
        anim = room->animated;
        for (j = 0; j < room->animatedCount; j++, anim++) {
            if (anim->flags & 0x20) {
                SceneMaterialUv *uv2 = anim->uv;
                if (uv2->buffer) continue;
                Def_80206058 def2;
                def2.id = uv2->id;
                if (find_uv_animation__6TSceneFPvPv(task, (Uv_80205DE4 *)&def2) == 1) {
                    uv2->id = def2.id; uv2->texture = def2.texture;
                    uv2->u = def2.u; uv2->v = def2.v; uv2->du = def2.du; uv2->dv = def2.dv;
                    SceneMaterialNode *node2 = resolve_indirect_object_record(task, anim);
                    void *buffer2 = ::operator new(20);
                    if (buffer2) buffer2 = ((TScene *)buffer2)->init_buffers((s32)node2, uv2->texture);
                    uv2->buffer = buffer2;
                } else {
                    anim->flags &= ~0x20;
                }
            }
            if ((anim->flags & 0x40) && !load_texture_sequence_frame(task, (Cyc_80205D24 *)anim->cycle)) anim->flags &= ~0x40;
        }
    }
}

void TScene::initialize_fmt1_materials() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    s32 j;
    if (!TScene__texture_animation_buffer || !TScene__data_805D5FCC) return;
    room = TScene__data_805D5FCC->sections;
    for (section = 0; section < TScene__data_805D5FCC->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if ((object->flags & 0x20) && !find_uv_animation__6TSceneFPvPv(this, (Uv_80205DE4 *)object->uv)) object->flags &= ~0x20;
            if ((object->flags & 0x40) && !load_texture_sequence_frame(this, (Cyc_80205D24 *)object->cycle)) object->flags &= ~0x40;
        }
        anim = room->animated;
        for (j = 0; j < room->animatedCount; j++, anim++) {
            if ((anim->flags & 0x20) && !find_uv_animation__6TSceneFPvPv(this, (Uv_80205DE4 *)anim->uv)) anim->flags &= ~0x20;
            if ((anim->flags & 0x40) && !load_texture_sequence_frame(this, (Cyc_80205D24 *)anim->cycle)) anim->flags &= ~0x40;
        }
    }
}
