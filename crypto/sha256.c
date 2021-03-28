#include "hblk_crypto.h"

/**
 * sha256 - sha256 computes the hash of a sequence of bytes
 * @s: is the sequence of hash to be hashed
 * @len: is the number of bytes to hash in s
 * @digest: is the result buffer
 * Return: the result digest or null on failure
 */
uint8_t *sha256(int8_t const *s, size_t len,
				uint8_t digest[SHA256_DIGEST_LENGTH])
{
	if (!s || !digest)
		return (NULL);

	return (SHA256((const unsigned char *)s, len, digest));
}
