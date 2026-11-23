#ifndef PSO_OBJECT_TOBJLOBBYPIGEON_H
#define PSO_OBJECT_TOBJLOBBYPIGEON_H
#include "types.h"
#include "pso/object/TObjPathObj.h"

class TObjLobbyPigeon : public TObjPathObj {
public:
    TObjLobbyPigeon(TObject *parent, void *set_data);
    static void *create(void *set_data);
    virtual ~TObjLobbyPigeon();
    s32 initialize_lobby_pigeon_path();
    s32 advance_lobby_pigeon_path();
    void update_lobby_pigeon_visibility();
    void select_lobby_pigeon_model();
    virtual void vfunc_14();
    virtual void vfunc_13();
    u8 unk_98[0x8];
    s32 m_a0;
    u8 unk_A4[0x4];
    s32 m_a8; // 0xA8
    u8 unk_AC[0x4];
    s32 m_b0; // 0xB0
    u8 unk_B4[0x14];
    s32 m_c8; // 0xC8
    u8 unk_CC[0x4];
    s32 m_d0; // 0xD0
    u8 unk_D4[0x4];
    s32 m_d8; // 0xD8
    u8 unk_DC[0x4];
};
LAYOUT_ASSERT(TObjLobbyPigeon_size, sizeof(TObjLobbyPigeon) == 0xE0);

#endif
