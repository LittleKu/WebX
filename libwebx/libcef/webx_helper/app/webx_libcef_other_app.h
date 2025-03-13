/**
 * @file      : webx_libcef_other_app.h
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-10 20:54:06
 * @brief     : 
 */
#ifndef WEBX_LIBWEBX_LIBCEF_WEBX_HELPER_APP_WEBX_LIBCEF_OTHER_APP_H_
#define WEBX_LIBWEBX_LIBCEF_WEBX_HELPER_APP_WEBX_LIBCEF_OTHER_APP_H_

#include "webx/libwebx/libcef/common/webx_libcef_app.h"

namespace webx {

class WebXLibcefOtherApp : public WebXLibcefApp {
 public:
  WebXLibcefOtherApp();
  ~WebXLibcefOtherApp() override;

 private:
  IMPLEMENT_REFCOUNTING(WebXLibcefOtherApp);
  DISALLOW_COPY_AND_ASSIGN(WebXLibcefOtherApp);
};

}  // namespace webx

#endif  // !WEBX_LIBWEBX_LIBCEF_WEBX_HELPER_APP_WEBX_LIBCEF_OTHER_APP_H_