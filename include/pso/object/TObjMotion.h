#ifndef PSO_OBJECT_TOBJMOTION_H
#define PSO_OBJECT_TOBJMOTION_H
#include "pso/TObject.h"
#include <stddef.h>
class TUnk_804B9870 : public TObject {
public:
    TUnk_804B9870(TObject *parent);
    virtual ~TUnk_804B9870();
    virtual void vfunc_6(s16 *, s32);
    virtual void apply_object_set_data(void *);
    virtual void reset_motion_fields();
    virtual void*vfunc_9();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual s16 classify_actor_view_detail(f32, f32, f32);
    virtual int vfunc_12();
    void obj_clearFlags30(u32);
    s16 get_stat_by_key_state();
    s32 mask_object_set_row_flags(s32);
    s32 set_event_source_flag(s32);
    void set_entity_id(u16 id);
    int set_position_from(void *pos);
    u16 m_1c;
    s16 m_1e;
    u8 m_20;
    u8 unk_21[0x1];
    u8 m_22;
    u8 unk_23[0x1];
    s32 texture_id;
    union {
        void* m_28;
        s16 group_ids[2];
    };
    union {
        void * m_2c;
        s16 group_index;
    };
    u32 actorFlags;
    void* model;
    f32 position[3];
    u32 m_44;
    u32 m_48;
    void* m_4c;
    void* m_50;
    f32 m_54;
    void* m_58;
    s32 m_5c;
    s32 rotation_y;
    s32 rotation_z;
    f32 scale;
    f32 target_scale;
    u32 m_70;
    void* m_74;
    u32 m_78;
    void* m_7c;
    void * m_80;
    s32 m_84;
    u8 * m_88;
    u32 m_8c;
};
// The derived destructors still written out by hand call the base ones by
// their symbols.
extern "C" void *__dt__13TUnk_804B9870Fv(void *, s16);
extern "C" void *__dt__13TUnk_804AF8A0Fv(void *, s16);

// One collision sphere of an actor (TUnk_804AF8A0::m_a4 points at the actor's
// array of them); init_collision_body_parts copies a static table of these.
struct CollisionBody {
    f32 offset[3];
    f32 radius;
    u8 pad_10[0x8];
    u32 flags;
    u8 pad_1c[0x10];
};

class TUnk_804AF8A0 : public TUnk_804B9870 {
public:
    TUnk_804AF8A0(TObject *parent);
    virtual ~TUnk_804AF8A0();
    virtual void reset_motion_fields();
    void*find_actor_body_contact(u8*, f32);
    void set_indexed_flags(s32, s32);
    void clear_player_status_flag(s32, u32);
    s32 obj_testFlags30(u32);
    s32 access_object_saved_state(void *, s16);
    void sub_80156A68();
    void*initialize_linked_object_reference(void*);
    void clear_obj_links();
    u32 check_actor_body_contact(void *, f32);
    void mark_enemy_body_contacts();
    void refresh_collision_body_centers();
    u16 unregister_object_by_id();
    void send_object_state_update(void *);
    virtual void vfunc_13(s32);
    s32 set_flag8();
    s32 has_interactor();
    void set_shadow_flag();
    void clear_shadow_flag();
    u32 m_90;
    u16 m_94;
    u8 unk_96[0x2];
    void* m_98;
    void *m_9c;
    u32 m_a0;
    CollisionBody *m_a4;
    s32 body_count;
};
// One entry of TObjMotion::action_table.
struct TObjMotionAction {
    s16 mode;
    s16 next;
    s32 motion;
    f32 speed;
    u32 flags;
};

class TObjMotion : public TUnk_804AF8A0 {
public:
    virtual ~TObjMotion();
    void draw();
    virtual void reset_motion_fields();
    void set_animation(s16);
    void set_field_d8(s32);
    void set_field_dc(s32);
    void*get_anim_entry(int);
    u8 sub_80143960(s32);
    s32 get_anim_entry_value(s16);
    void update_animation_frame(s32);
    s32 get_item_ptr(s32);
    void sub_800E2DE4(s32);
    void set_motion_interpolation_flag();
    void set_field_b8(s16);
    u32 unknownAC;
    u32 animationFlags;
    u32 m_b4;
    s16 m_b8;
    short m_ba;
    u32 m_bc;
    f32 m_c0;
    union {
        u8 unk_C4[0x4];
        f32 anim_end_frame;
    };
    f32 m_c8;
    u8 unk_CC[0x4];
    f32 m_d0;
    u8 unk_D4[0x4];
    void* action_table;
    void* motion_list;
    void* motion_buffer;
    u8 unk_E4[0x3];
    u8 m_e7;
    u8 unk_E8[0x4];
    s32 m_ec;
    u8 unk_F0[0x4];
    void * m_f4;
    u32 unknownF8;
};
typedef char TUnk_804B9870Size[sizeof(TUnk_804B9870)==0x90?1:-1];
typedef char TUnk_804AF8A0Size[sizeof(TUnk_804AF8A0)==0xAC?1:-1];
typedef char CollisionBodySize[sizeof(CollisionBody)==0x2C?1:-1];
typedef char TObjMotionSize[sizeof(TObjMotion)==0xFC?1:-1];
typedef char WorldActorModelOffset[offsetof(TUnk_804B9870,model)==0x34?1:-1];
typedef char MotionActionsOffset[offsetof(TObjMotion,action_table)==0xD8?1:-1];
typedef char MotionListOffset[offsetof(TObjMotion,motion_list)==0xDC?1:-1];
typedef char MotionBufferOffset[offsetof(TObjMotion,motion_buffer)==0xE0?1:-1];
#endif
