#pragma once
#include <openssl/evp.h>

namespace nkg::resource_traits::openssl {

    struct evp_cipher_ctx {
        using handle_t = EVP_CIPHER_CTX*;

        static constexpr handle_t invalid_value = nullptr;

        [[nodiscard]]
        static bool is_valid(const handle_t& handle) noexcept {
            return handle != invalid_value;
        }

        static void release(const handle_t& handle) noexcept {
            EVP_CIPHER_CTX_free(handle);
        }
    };

}
