#include "hblk_crypto.h"

/**
 * ec_create - ec_create creates a two pairs of keys with elliptic curve
 * Return: a pair of private and public key
 */
EC_KEY *ec_create(void)
{
    EC_KEY *key = EC_KEY_new_by_curve_name(EC_CURVE);

    if (!key)
        return (NULL);

    if (!EC_KEY_generate_key(key))
    {
        EC_KEY_free(key);
        return (NULL);
    }
    return (key);
}
