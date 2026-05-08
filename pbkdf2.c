#include "pbkdf2.h"
#include "sha1.h"
#include <string.h>
#include <stdlib.h>

static void hmac_sha1(const uint8_t *key, size_t key_len,
                      const uint8_t *data, size_t data_len,
                      uint8_t *digest) {
    sha1_context ctx;
    uint8_t k_ipad[64];
    uint8_t k_opad[64];
    uint8_t tk[20];

    if (key_len > 64) {
        sha1(key, key_len, tk);
        key = tk;
        key_len = 20;
    }

    memset(k_ipad, 0, 64);
    memset(k_opad, 0, 64);
    memcpy(k_ipad, key, key_len);
    memcpy(k_opad, key, key_len);

    for (int i = 0; i < 64; i++) {
        k_ipad[i] ^= 0x36;
        k_opad[i] ^= 0x5c;
    }

    sha1_init(&ctx);
    sha1_starts(&ctx);
    sha1_update(&ctx, k_ipad, 64);
    sha1_update(&ctx, data, data_len);
    sha1_finish(&ctx, digest);

    sha1_init(&ctx);
    sha1_starts(&ctx);
    sha1_update(&ctx, k_opad, 64);
    sha1_update(&ctx, digest, 20);
    sha1_finish(&ctx, digest);
    sha1_free(&ctx);
}

void pbkdf2_sha1(const uint8_t *password, size_t password_len,
                 const uint8_t *salt, size_t salt_len,
                 uint32_t iterations,
                 uint8_t *out, size_t out_len) {
    uint8_t digest[20], tmp[20];
    uint8_t *asalt = malloc(salt_len + 4);
    if (!asalt) return;
    memcpy(asalt, salt, salt_len);

    uint32_t block = 1;
    size_t offset = 0;

    while (out_len > 0) {
        asalt[salt_len + 0] = (uint8_t)(block >> 24);
        asalt[salt_len + 1] = (uint8_t)(block >> 16);
        asalt[salt_len + 2] = (uint8_t)(block >> 8);
        asalt[salt_len + 3] = (uint8_t)(block & 0xff);

        hmac_sha1(password, password_len, asalt, salt_len + 4, digest);
        memcpy(tmp, digest, 20);

        for (uint32_t i = 1; i < iterations; i++) {
            hmac_sha1(password, password_len, tmp, 20, tmp);
            for (int j = 0; j < 20; j++) digest[j] ^= tmp[j];
        }

        size_t chunk = (out_len > 20) ? 20 : out_len;
        memcpy(out + offset, digest, chunk);
        offset += chunk;
        out_len -= chunk;
        block++;
    }
    free(asalt);
}
