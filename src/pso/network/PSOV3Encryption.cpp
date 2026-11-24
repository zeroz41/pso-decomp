#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/network/PSOV3Encryption.h"

u32 PSOV3Encryption::next() {
	if (++m_buffer_start == m_buffer_end) {
		update_stream();
	}
	return *m_buffer_start;
}

void PSOV3Encryption::update_stream() {
	u32 *ptr;
	u32 *part1;
	u32 *part2;

	part2 = m_buffer;
	m_buffer_start = m_buffer;
	ptr = m_buffer;
	part1 = &ptr[489];

	for (; part1 != m_buffer_end; *ptr++ ^= *part1++);
	for (; ptr != m_buffer_end; *ptr++ ^= *part2++);

}

void PSOV3Encryption::init(u32 seed) {
	const size_t size = (sizeof(m_buffer)/sizeof(*m_buffer))-1;
	m_buffer_end = &m_buffer[size];
	m_buffer_start = m_buffer;
	u32 value = 0;

	for (int i = 0; i <= 16; ++i, *m_buffer_start++ = value) {
		for (int j = 32; j; --j) {
			seed *= 0x5d588b65;
			value = (++seed & (1 << 31)) | (value >> 1);
		}
	}

	--m_buffer_start;

	*m_buffer_start = (*m_buffer_start << 23) ^ (m_buffer[0] >> 9) ^ m_buffer[0xf];

	for (u32 *buf_val = &m_buffer[0], *next_buf_val = &m_buffer[1], *buf = m_buffer_start++; m_buffer_start != m_buffer_end;) {
		*m_buffer_start++ = (*buf_val++ << 23) ^ (*next_buf_val++ >> 9) ^ *buf++;
	}

	update_stream();
	update_stream();
	update_stream();
	m_buffer_start = &m_buffer[size-1];
}

PSOV3Encryption::~PSOV3Encryption() {
	memset(m_buffer, 0, sizeof(m_buffer));
	m_buffer_start = nullptr;
	m_buffer_end = nullptr;
}

PSOV3Encryption::PSOV3Encryption() : PSOEncryption() {
	init(0);
}

PSOEncryption::~PSOEncryption() {
}

PSOEncryption::PSOEncryption() {
}
