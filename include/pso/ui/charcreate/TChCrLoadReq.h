#ifndef PSO_UI_CHARCREATE_TCHCRLOADREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADREQ_H
#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

struct CharacterAppearanceFields;
struct CharacterClassAppearance;
struct TObjPlayer;

class TChCrLoadReq : public TObject {
public:
    TChCrLoadReq(TObject *arg1, void *arg2);
    TChCrLoadReq(TObjPlayer *player);
    virtual ~TChCrLoadReq();
    void release_load_slot();
public:
    u8 unk_1C[0x1C];
    CharacterAppearanceFields *m_38;
    u32 *m_3c;
    s32 m_40;
    s32 *m_44;
    s32 *m_48;
    void *m_4c;
    void *m_50;
    void *m_54;
    s32 *m_58;
    CharacterClassAppearance *m_5c;
    s32 state;
    s32 timer;
    s32 calc_preview_last_index(s32 display_index, s32 region_index);
    virtual void run_task();
    void close_and_destroy();
    void try_advance_state();
    void update_load_progress();
public:
    void reset_request();
    void copy(void* q);
    static void *create(void *arg0);
    s32 m_68[3];
    void *m_74[6];
    s32 m_8c;
};
LAYOUT_ASSERT(TChCrLoadReq_state_offset, offsetof(TChCrLoadReq,state)==0x60);
LAYOUT_ASSERT(TChCrLoadReq_timer_offset, offsetof(TChCrLoadReq,timer)==0x64);
LAYOUT_ASSERT(TChCrLoadReq_size, sizeof(TChCrLoadReq) == 0x90);
#endif
