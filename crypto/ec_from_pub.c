#include "hblk_crypto.h"

/**
 * ec_from_pub - get a key from a public key
 * @pub: is the public key
 * Return: a pointer to the ec key
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *key = NULL;
	EC_POINT *point = NULL;

	if (!pub)
		return (NULL);

	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
		return (NULL);
	point = EC_POINT_new(EC_KEY_get0_group(key));
	if (!point)
	{
		EC_KEY_free(key);
		return (NULL);
	}
	if (!EC_POINT_oct2point(EC_KEY_get0_group(key), point, pub, EC_PUB_LEN,
							NULL) ||
		!EC_KEY_set_public_key(key, point))
	{
		EC_KEY_free(key);
		EC_POINT_free(point);
		return (NULL);
	}
	EC_POINT_free(point);
	return (key);
}
