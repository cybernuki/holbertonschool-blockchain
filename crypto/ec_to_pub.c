#include "hblk_crypto.h"

/**
 * ec_to_pub - ec_to_pub converts an EC key to a public key
 * @key: is a pointer to the EC_KEY structure to retrieve the public key from.
 * @pub: is the address at which to store the extracted public key
 * Return: return a pointer to pub
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_GROUP *group = NULL;
	const EC_POINT *point = NULL;

	if (!key || !pub)
		return (NULL);
	point = EC_KEY_get0_public_key(key);
	if (!point)
		return (NULL);
	group = EC_KEY_get0_group(key);
	if (!group)
		return (NULL);
	if (!EC_POINT_point2oct(group, point, POINT_CONVERSION_UNCOMPRESSED,
							pub, EC_PUB_LEN, NULL))
		return (NULL);
	return (pub);
}
