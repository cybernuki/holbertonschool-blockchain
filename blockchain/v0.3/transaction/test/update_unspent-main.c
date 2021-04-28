#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "blockchain.h"

void _blockchain_print_brief(blockchain_t const *blockchain);
void _print_hex_buffer(uint8_t const *buf, size_t len);

/**
 * _print_unspent - Print an unspent transaction output
 *
 * @unspent: Pointer to the unspent transaction output to print
 * @idx:     Unused
 * @indent:  Indentation
 *
 * Return: 0
 */
static int _print_unspent(unspent_tx_out_t const *unspent, unsigned int idx,
                          char const *indent)
{
    printf("%s{\n", indent);

    printf("%s\tblock_hash: ", indent);
    _print_hex_buffer(unspent->block_hash, SHA256_DIGEST_LENGTH);
    printf("\n");

    printf("%s\ttx_id: ", indent);
    _print_hex_buffer(unspent->tx_id, SHA256_DIGEST_LENGTH);
    printf("\n");

    printf("%s\tamount: %u\n", indent, unspent->out.amount);

    printf("%s\tpub: ", indent);
    _print_hex_buffer(unspent->out.pub, EC_PUB_LEN);
    printf("\n");

    printf("%s}\n", indent);

    (void)idx;
    return (0);
}
