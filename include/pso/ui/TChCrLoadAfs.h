#ifndef PSO_UI_TCHCRLOADAFS_H
#define PSO_UI_TCHCRLOADAFS_H

#include "pso/TObject.h"
#include "types.h"
#include <stddef.h>

class TChCrLoadAfs : public TObject {
public:
    TChCrLoadAfs(TObject *arg1, void *arg2, void *arg3);
    virtual ~TChCrLoadAfs();
    void release_load_slot();
    virtual void run_task();
    void start_download();
    void poll_load();
    void sub_8028B944();
    void sub_8028B940();
    u32 load_handle;
    u32 source_20;
    u32 source_24;
    u32 buffer_address;
    s32 load_state;
    s32 state_30;
    s32 timer;

public:
    void *create(void *arg1, void *arg2);
public:
    int is_unloaded();
};

typedef char TChCrLoadAfs_size[sizeof(TChCrLoadAfs) == 0x38 ? 1 : -1];
typedef char TChCrLoadAfs_load_handle_offset[offsetof(TChCrLoadAfs, load_handle) == 0x1c ? 1 : -1];
typedef char TChCrLoadAfs_buffer_address_offset[offsetof(TChCrLoadAfs, buffer_address) == 0x28 ? 1 : -1];
typedef char TChCrLoadAfs_load_state_offset[offsetof(TChCrLoadAfs, load_state) == 0x2c ? 1 : -1];
typedef char TChCrLoadAfs_timer_offset[offsetof(TChCrLoadAfs, timer) == 0x34 ? 1 : -1];

s32 find_player_texture_name_ordinal(u8 *arg0);
extern "C" {
void sub_8028B940__12TChCrLoadAfsFv(void);
void sub_8028B944__12TChCrLoadAfsFv(void);
s32 try_begin_load__12TChCrLoadAfsFPv(void *arg0);
}

#endif
