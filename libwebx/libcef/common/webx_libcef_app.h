/**
 * @file      : webx_libcef_app.h
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-10 11:44:22
 * @brief     : 
 */
#ifndef WEBX_LIBWEBX_LIBCEF_COMMON_WEBX_LIBCEF_APP_H_
#define WEBX_LIBWEBX_LIBCEF_COMMON_WEBX_LIBCEF_APP_H_

#include "webx/libcef/include/cef_app.h"

namespace webx {

class WebXLibcefApp : public CefApp {
 public:
  WebXLibcefApp();
  ~WebXLibcefApp() override;

  enum ProcessType {
    BrowserProcess,
    RendererProcess,
    ZygoteProcess,
    OtherProcess,
  };

  static ProcessType GetProcessType(CefRefPtr<CefCommandLine> command_line);

 private:
  static void RegisterCustomSchemes(CefRawPtr<CefSchemeRegistrar> registrar);

 private:
  void OnRegisterCustomSchemes(
      CefRawPtr<CefSchemeRegistrar> registrar) override;

  DISALLOW_COPY_AND_ASSIGN(WebXLibcefApp);
};

}  // namespace webx
#endif // !WEBX_LIBWEBX_LIBCEF_COMMON_WEBX_LIBCEF_APP_H_