/**
 * @file      : libwebx_impl.h
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-08 16:36:36
 * @brief     :
 */
#ifndef WEBX_LIBWEBX_SRC_IMPLEMENT_LIBWEBX_IMPL_H_
#define WEBX_LIBWEBX_SRC_IMPLEMENT_LIBWEBX_IMPL_H_

#include "build/build_config.h"

#if BUILDFLAG(IS_WIN)
#include "base/win/windows_full.h"
#endif

#include "webx/include/libwebx.h"
#include "webx/libwebx/src/common/libwebx_common.h"

#include <atomic>

namespace webx {

class WebXImpl : public RefCounter<IWebX> {
 public:
  WebXImpl();
  ~WebXImpl() override;

  // IWebXBaseInterface
  const char* Unique() const override;
  bool QueryInterface(const char* unique, IWebXBaseInterface** obj) override;

  // IWebX
  bool Initialize(void* instance, WebCoreType type) override;
  void UnInitialize() override;

 private:
#if BUILDFLAG(IS_WIN)
  HINSTANCE instance_{nullptr};
#endif
  std::atomic_bool initialize_{false};
};

}  // namespace webx

#endif  // !WEBX_LIBWEBX_SRC_IMPLEMENT_LIBWEBX_IMPL_H_