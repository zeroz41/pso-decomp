#ifndef PSOV3ENCRYPTIONTCP_H
#define PSOV3ENCRYPTIONTCP_H

/* PSOV3EncryptionTCP - TCP encryption wrapper.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 */

#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3Encryption.h"

class PSOV3EncryptionTCP {
public:
	PSOV3EncryptionTCP();
	~PSOV3EncryptionTCP();

	void reset(u32 seed);
	void encrypt(void *void_data, int size);
public:
	PSOV3Encryption m_encryption;
	u32 m_seed;
};

#endif
