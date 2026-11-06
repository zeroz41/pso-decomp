#ifndef PSO_SYSTEM_TMCFORMATSEQUENCE_H
#define PSO_SYSTEM_TMCFORMATSEQUENCE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TMCFormatSequence : public TObject {
public:
    u8 unk_1C[0x4];
    u32 m_20;
    s32 m_24;
    u8 unk_28[0x4];
    u32 m_2c;
    u8 unk_30[0x4];
    unsigned int m_34;
 void* m_38;
public:
    TMCFormatSequence(TObject *arg1, void *arg2);
    virtual ~TMCFormatSequence();
    virtual void run_task();
public:
    void close_window();
    void show_message(s32 arg1, s32 arg2);
    void check_memcard_load_result();
    void process_format_result();
    void open_windows();
};

#endif
