#include "hblk_crypto.h"

/**
 * ec_verify - ec_verify verify signature of a message
 * @key: is the given key of the signature
 * @msg: is the message
 * @msglen: is the length of the message
 * @sig: is the signature
 * Return: 1 if the signature is correct, 0 otherwise.
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
              sig_t const *sig)
{
    if (!key || !msg || !sig)
        return (0);
    return (ECDSA_verify(0, msg, msglen, sig->sig,
                         sig->len, (EC_KEY *)key) == 1);
}
