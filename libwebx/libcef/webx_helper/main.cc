/**
 * @file      : main.cc
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-10 11:33:20
 * @brief     : 
 */
#include "webx/libcef/include/base/cef_build.h"
#include "webx/libwebx/libcef/webx_helper/app/webx_libcef_other_app.h"
#include "webx/libwebx/libcef/webx_helper/app/webx_libcef_renderer_app.h"

namespace {

const char kType[] = R"(type)";
const char kRenderer[] = R"(renderer)";

}  // namespace

#if defined(OS_WIN)
int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, LPTSTR, int) {
  CefRefPtr<CefCommandLine> cmd = CefCommandLine::CreateCommandLine();
  cmd->InitFromString(::GetCommandLineW());
  CefMainArgs main_args(instance);
#else
int main(int argc, char* argv[]) {
  CefRefPtr<CefCommandLine> cmd = CefCommandLine::CreateCommandLine();
  cmd->InitFromArgv(argc, argv);
  CefMainArgs main_args(argc, argv);
#endif

  DCHECK(cmd->HasSwitch(kType)) << "Missing --" << kType << " switch.";

  CefRefPtr<CefApp> app = nullptr;
  CefString type = cmd->GetSwitchValue(kType);
  if (type == kRenderer) {
    app = new webx::WebXLibcefRendererApp();
  } else {
    app = new webx::WebXLibcefOtherApp();
  }

  return CefExecuteProcess(main_args, app, nullptr);
}
