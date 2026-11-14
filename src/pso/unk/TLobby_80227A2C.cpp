#include "types.h"

extern "C" {
int free__6TLobbyFPv(void* p);
int TLobby__sub_80227A4C(void* p);
void TLobby__sub_80227A6C(void);
int TLobby__sub_80227A70(void* p);
void TLobby__sub_80227A90(void);
void __sinit_TLobby_80227A2C_cpp(void);
void TLobby__sub_8022804C(void);
int xfree__FPv(void*);
int xmalloc__FUl(void*);

int free__6TLobbyFPv(void* p) { return xfree__FPv(p); }
int TLobby__sub_80227A4C(void* p) { return xmalloc__FUl(p); }
void TLobby__sub_80227A6C(void) {  }
int TLobby__sub_80227A70(void* p) { return ((int (*)(void*))TLobby__sub_8022804C)(p); }
void TLobby__sub_80227A90(void) {  }

    int lbl_805D3710 = -140;
    extern int lbl_805D6314;
void __sinit_TLobby_80227A2C_cpp(void) { lbl_805D6314 = lbl_805D3710; }
}

__declspec(section ".ctors") static void *const __sinit_TLobby_80227A2C_cpp_ref = (void *)__sinit_TLobby_80227A2C_cpp;
