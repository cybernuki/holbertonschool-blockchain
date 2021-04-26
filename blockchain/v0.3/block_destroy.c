#include "blockchain.h"

/**
 * block_destroy - block_destroy frees a block
 * @block: pointer to block
 */
void block_destroy(block_t *block)
{
    free(block);
}
