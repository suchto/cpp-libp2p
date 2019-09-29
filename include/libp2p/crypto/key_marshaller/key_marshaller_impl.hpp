/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_CRYPTO_MARSHALER_KEY_MARSHALER_IMPL_HPP
#define LIBP2P_CRYPTO_MARSHALER_KEY_MARSHALER_IMPL_HPP

#include <libp2p/crypto/error.hpp>
#include <libp2p/crypto/key.hpp>
#include <libp2p/crypto/key_marshaller.hpp>
#include <libp2p/crypto/key_validator.hpp>

namespace libp2p::crypto::marshaller {
  class KeyMarshallerImpl : public KeyMarshaller {
   public:
    explicit KeyMarshallerImpl(
        std::shared_ptr<validator::KeyValidator> key_validator);

    ~KeyMarshallerImpl() override = default;

    outcome::result<KeyMarshaller::ByteArray> marshal(
        const PublicKey &key) const override;

    outcome::result<KeyMarshaller::ByteArray> marshal(
        const PrivateKey &key) const override;

    outcome::result<PublicKey> unmarshalPublicKey(
        const KeyMarshaller::ByteArray &key_bytes) const override;

    outcome::result<PrivateKey> unmarshalPrivateKey(
        const KeyMarshaller::ByteArray &key_bytes) const override;

   private:
    std::shared_ptr<validator::KeyValidator> key_validator_;
  };
}  // namespace libp2p::crypto::marshaller

#endif  // LIBP2P_CRYPTO_MARSHALER_KEY_MARSHALER_IMPL_HPP