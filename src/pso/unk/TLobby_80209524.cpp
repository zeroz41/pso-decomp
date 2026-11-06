#include "types.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"

extern "C" {

void mem_free(void *p);

void *TLobby::free_boss4rock(s16 arg1) {
    if (this != NULL) {
        mem_free((void *)(*(s32 *)&this->m_flags));
        ::operator delete(*(void * *)&this->m_name);
        *(s32 *)&this->m_prev = 0;
        *(s32 *)&this->m_next = 0;
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

}
