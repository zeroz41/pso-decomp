#ifndef PSO_OBJECT_LOBBY_TOBJBUTTERFLYLOBBY_H
#define PSO_OBJECT_LOBBY_TOBJBUTTERFLYLOBBY_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;
struct ObjectSetData;

struct TObjButterflyLobby : public TObjBase {
    TObjButterflyLobby(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjButterflyLobby();
    u32 m_90;
    u8 unk_94[0x10];
    f32 m_a4;
    u8 unk_A8[0x4];
    f32 m_ac;
    f32 animation_frame;
    u8 unk_B4[0x4];
    f32 m_b8;
    s16 m_bc;
    s16 m_be;
    u8 m_c0;
    u8 m_c1;
    u8 m_c2;
    u8 _padC3[0x1];
    NJS_OBJECT *lobby_model;
    NJS_TEXLIST *model_textures;
    static void free_singleton_805D4E6C();
    static void alloc_scene_buffer();
    void init_params();
    virtual void render();
    void update_fade();
    virtual void run_task();
    static void destroy_instance();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjButterflyLobby_size, sizeof(TObjButterflyLobby) == 0xCC);
#endif
