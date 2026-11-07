#ifndef PSO_ENEMY_TNEEDLESHOOT_H
#define PSO_ENEMY_TNEEDLESHOOT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TechniqueContactBody;

struct TNeedleShoot : public TObject {
    virtual ~TNeedleShoot();
    virtual int vfunc_6();
    virtual int queue_destruction();
    virtual void vfunc_8();
    virtual void vfunc_9(void *);
    u32 m_1c;
    u8 unk_20[0x4];
    f32 m_24;
    u8 unk_28[0x4];
    f32 m_2c;
    u8 unk_30[0x4];
    u16 m_34;
    u8 _pad36[0x2];
    TechniqueContactBody *m_38;
    void* m_3c;
    u8 _pad40[0x10];
    u32 m_50;
    u32 m_54;
    u8 _pad58[0x10];
    u32 m_68;
    void* m_6c;
    u8 unk_70[0x4];
    f32 m_74;
    u8 unk_78[0x1C];
    void* m_94;
    u8 unk_98[0x4];
    f32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u32 m_a8;
    u8 _padAC[0x4];
    u32 m_b0;
    u8 _padB4[0x4];
    u32 m_b8;
    virtual void run_task();
    virtual void render();
    void update_position();
    void check_wall_hit();
    void*get_shoot_data();
};

typedef char TNeedleShoot_size[sizeof(TNeedleShoot) == 0xBC ? 1 : -1];
#endif
