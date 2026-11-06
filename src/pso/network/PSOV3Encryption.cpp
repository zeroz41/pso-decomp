#include <global_types.h>
#include "pso/boss/goldragon/TBoss8Dragon_8036AEF8.h"
#include "pso/network/PSOV3Encryption_8036AE2C.h"
#include <string.h>
#include "pso/macros.h"
#include "types.h"

struct PSOEncryption_shape {
	virtual void update_stream() = 0;
	virtual void dtor_slot() = 0;
	virtual void init(u32 seed) = 0;
	virtual u32 next() = 0;
};
struct PSOV3Encryption_layout : PSOEncryption_shape {
	u32 m_buffer[522];
	u32 *m_buffer_start;
	u32 *m_buffer_end;
};
#define PSOV3_UPDATE_STREAM(self) (self)->update_stream()

extern "C" {
u32 next__15PSOV3EncryptionFv(PSOV3Encryption_layout *self);
void update_stream__15PSOV3EncryptionFv(PSOV3Encryption_layout *self);
void init__15PSOV3EncryptionFUl(PSOV3Encryption_layout *self, u32 seed);

u32 next__15PSOV3EncryptionFv(PSOV3Encryption_layout *self) {
	if (++self->m_buffer_start == self->m_buffer_end) {
		PSOV3_UPDATE_STREAM(self);
	}
	return *self->m_buffer_start;
}

void update_stream__15PSOV3EncryptionFv(PSOV3Encryption_layout *self) {
	u32 *ptr;
	u32 *part1;
	u32 *part2;

	part2 = self->m_buffer;
	self->m_buffer_start = self->m_buffer;
	ptr = self->m_buffer;
	part1 = &ptr[489];

	for (; part1 != self->m_buffer_end; *ptr++ ^= *part1++);
	for (; ptr != self->m_buffer_end; *ptr++ ^= *part2++);

}

void init__15PSOV3EncryptionFUl(PSOV3Encryption_layout *self, u32 seed) {
	const size_t size = (sizeof(self->m_buffer)/sizeof(*self->m_buffer))-1;
	self->m_buffer_end = &self->m_buffer[size];
	self->m_buffer_start = self->m_buffer;
	u32 value = 0;

	for (int i = 0; i <= 16; ++i, *self->m_buffer_start++ = value) {
		for (int j = 32; j; --j) {
			seed *= 0x5d588b65;
			value = (++seed & (1 << 31)) | (value >> 1);
		}
	}

	--self->m_buffer_start;

	*self->m_buffer_start = (*self->m_buffer_start << 23) ^ (self->m_buffer[0] >> 9) ^ self->m_buffer[0xf];

	for (u32 *buf_val = &self->m_buffer[0], *next_buf_val = &self->m_buffer[1], *buf = self->m_buffer_start++; self->m_buffer_start != self->m_buffer_end;) {
		*self->m_buffer_start++ = (*buf_val++ << 23) ^ (*next_buf_val++ >> 9) ^ *buf++;
	}

	PSOV3_UPDATE_STREAM(self);
	PSOV3_UPDATE_STREAM(self);
	PSOV3_UPDATE_STREAM(self);
	self->m_buffer_start = &self->m_buffer[size-1];
}

void *lbl_804F3610[6] = {
	0,
	0,
	0,
	(void *)TBoss8Dragon__sub_8036AEF8,
	0,
	0,
};
void *lbl_804F3628[6] = {
	0,
	0,
	(void *)update_stream__15PSOV3EncryptionFv,
	(void *)__dt__15PSOV3EncryptionFv,
	(void *)init__15PSOV3EncryptionFUl,
	(void *)next__15PSOV3EncryptionFv,
};
}
