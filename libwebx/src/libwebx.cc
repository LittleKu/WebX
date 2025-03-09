/**
 * @file      : libwebx.cc
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-08 15:42:26
 * @brief     : 
 */
#include "webx/include/libwebx.h"
#include "webx/libwebx/src/implement/libwebx_impl.h"

#include <mutex>

static std::once_flag create_webx;
IWebX* webx_impl = nullptr;

WEBX_LIBWEBX_API bool CreateWebX(IWebX** webx) {
  if (!webx)
    return false;

  std::call_once(create_webx, [] { webx_impl = new webx::WebXImpl(); });
  webx_impl->AddRef();
  *webx = webx_impl;
  return true;
}
