/**
 * @file      : libwebx_impl.cc
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-08 16:37:03
 * @brief     : 
 */
#include "webx/libwebx/src/implement/libwebx_impl.h"

#include <string>


namespace webx {

namespace {

const char kWebXUnique[] = R"(WebX)";

}

WebXImpl::WebXImpl() = default;

WebXImpl::~WebXImpl() = default;

const char* WebXImpl::Unique() const {
  return kWebXUnique;
}

bool WebXImpl::QueryInterface(const char* unique, IWebXBaseInterface** obj) {
  if (!unique || !obj) {
    return false;
  }
  if (std::char_traits<char>::compare(
          unique, Unique(), std::char_traits<char>::length(Unique())) == 0) {
    AddRef();
    *obj = this;
    return true;
  }

  if (!initialize_)
    return false;

  // TODO other interface
  return false;
}

bool WebXImpl::Initialize(void* instance, WebCoreType type) {
  if (initialize_)
    return true;

#if BUILDFLAG(IS_WIN)
  instance_ = reinterpret_cast<HINSTANCE>(instance);
#endif

  initialize_ = true;
  return true;
}

void WebXImpl::UnInitialize() {
  if (!initialize_)
    return;

  initialize_ = false;
}

}  // namespace webx
