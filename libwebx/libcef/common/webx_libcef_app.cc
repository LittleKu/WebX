/**
 * @file      : webx_libcef_app.cc
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-10 11:45:14
 * @brief     : 
 */
#include "webx/libwebx/libcef/common/webx_libcef_app.h"

namespace webx {

namespace {

// These flags must match the Chromium values.
const char kProcessType[] = "type";
const char kRendererProcess[] = "renderer";
#if defined(OS_LINUX)
const char kZygoteProcess[] = "zygote";
#endif

}  // namespace

WebXLibcefApp::WebXLibcefApp() = default;

WebXLibcefApp::~WebXLibcefApp() = default;

WebXLibcefApp::ProcessType WebXLibcefApp::GetProcessType(
    CefRefPtr<CefCommandLine> command_line) {
  if (!command_line->HasSwitch(kProcessType)) {
    return BrowserProcess;
  }

  const std::string& process_type = command_line->GetSwitchValue(kProcessType);
  if (process_type == kRendererProcess) {
    return RendererProcess;
  }
#if defined(OS_LINUX)
  else if (process_type == kZygoteProcess) {
    return ZygoteProcess;
  }
#endif

  return OtherProcess;
}

// static
void WebXLibcefApp::RegisterCustomSchemes(
    CefRawPtr<CefSchemeRegistrar> registrar) {
  /**
   * add custom scheme.
   * e.g:
   * registrar->AddCustomScheme(
   * "xxxx", CEF_SCHEME_OPTION_STANDARD | CEF_SCHEME_OPTION_CORS_ENABLED);
   */
}

void WebXLibcefApp::OnRegisterCustomSchemes(
    CefRawPtr<CefSchemeRegistrar> registrar) {
  RegisterCustomSchemes(registrar);
}

}  // namespace webx
