/**
 * @file      : libwebx_common.h
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-08 16:07:51
 * @brief     :
 */
#ifndef WEBX_LIBWEBX_SRC_COMMON_LIBWEBX_COMMON_H_
#define WEBX_LIBWEBX_SRC_COMMON_LIBWEBX_COMMON_H_

#include "webx/libwebx/include/libwebx.h"

#include <atomic>

namespace webx {

template <typename T>
concept HasRefCount = requires(T t) {
  t.AddRef();
  t.Release();
};

template <typename Interface>
concept IsBaseOfIWebXRefCounter =
    std::is_base_of<IWebXRefCounter, Interface>::value;

template <typename Interface>
  requires IsBaseOfIWebXRefCounter<Interface>
class RefCounter : public Interface {
 public:
  RefCounter() = default;
  virtual ~RefCounter() = default;

  void AddRef() override { ref_count_.fetch_add(1, std::memory_order_relaxed); }

  bool Release() override {
    if (ref_count_.fetch_sub(1, std::memory_order_acq_rel) == 1) {
      delete this;
      return true;
    }
    return false;
  }

 protected:
  std::atomic_int ref_count_{0};
};

}  // namespace webx

#endif  // !WEBX_LIBWEBX_SRC_COMMON_LIBWEBX_COMMON_H_