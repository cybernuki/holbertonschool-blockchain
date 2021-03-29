#include "hblk_crypto.h"

/**
 * ec_load - ec_load loads a ec_key from a file
 * @folder: is the name of the folder
 * Return: a loaded EC_KEY or null on failure
 */
EC_KEY *ec_load(char const *folder)
{
	FILE *fp = NULL;
	char path[128] = {0};
	EC_KEY *key = NULL;

	if (!folder)
		return (0);

	sprintf(path, "%s/" PUB_FILENAME, folder);
	fp = fopen(path, "r");
	if (!fp)
	{
		EC_KEY_free(key);
		return (0);
	}
	if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
	{
		EC_KEY_free(key);
		fclose(fp);
		return (0);
	}
	fclose(fp);

	sprintf(path, "%s/" PRI_FILENAME, folder);
	fp = fopen(path, "r");
	if (!fp)
		return (0);
	if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	return (key);
}
