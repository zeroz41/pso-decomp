#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItemLoad.h"

void TItemLoad::free_texture() { if (*(unsigned int *)&this->m_flags != 0) { ((TLobby *)(*(void* *)&this->m_flags))->close_adxf_handle(); *(int *)&this->m_flags = 0; *(int *)&this->m_next = 0; } }
