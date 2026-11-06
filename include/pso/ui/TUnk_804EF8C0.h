#ifndef PSO_UI_TUNK_804EF8C0_H
#define PSO_UI_TUNK_804EF8C0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EF8C0 : public TObject {
public:
    virtual ~TUnk_804EF8C0();
    void *construct();
    void alloc_download_buffer();
    void clear_buffer();
    void free_buffer();
    virtual void run_task();
    u8 unk_1C[0x28];
};
typedef char TUnk_804EF8C0_size[sizeof(TUnk_804EF8C0) == 0x44 ? 1 : -1];

#endif
