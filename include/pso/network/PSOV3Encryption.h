#ifndef PSOV3ENCRYPTION_H
#define PSOV3ENCRYPTION_H

/* PSOV3Encryption - PSO V3 stream cipher.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 */

#include "types.h"
#include <string.h>
#include "pso/macros.h"

class PSOEncryption {
public:
	PSOEncryption();
	virtual void update_stream() = 0;
	virtual ~PSOEncryption();
	virtual void init(u32 seed) = 0;
	virtual u32 next() = 0;
};

class PSOV3Encryption : public PSOEncryption {
public:
	PSOV3Encryption();
	virtual void update_stream();
	virtual ~PSOV3Encryption();
	virtual void init(u32 seed);
	virtual u32 next();
public:
	u32 m_buffer[522];
	u32 *m_buffer_start;
	u32 *m_buffer_end;
};

#endif
