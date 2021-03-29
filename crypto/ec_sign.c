#include "hblk_crypto.h"

/**
 * ec_sign - ec_sign signs a given set of bytes, using a given EC_KEY private
 * key
 * @key: points to the EC_KEY structure containing the private key to be used
 *       to perform the signature
 * @msg: points to the msglen characters to be signed
 * @msglen: length of the msg
 * @sig: holds the address at which to store the signature
 * Return: a pointer to the signature buffer upon success (sig->sig)
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
				 sig_t *sig)
{
	unsigned int len;

	if (!key || !msg || !sig)
		return (NULL);
	len = sig->len;
	if (ECDSA_sign(0, msg, msglen, sig->sig, &len,
				   (EC_KEY *)key) != 1)
		return (NULL);
	sig->len = len;
	return (sig->sig);
}
