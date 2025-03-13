/**
 * @file      : webx_libcef_renderer_app.h
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-10 20:54:51
 * @brief     :
 */
#ifndef WEBX_LIBWEBX_LIBCEF_WEBX_HELPER_APP_WEBX_LIBCEF_RENDERER_APP_H_
#define WEBX_LIBWEBX_LIBCEF_WEBX_HELPER_APP_WEBX_LIBCEF_RENDERER_APP_H_

#include "webx/libwebx/libcef/common/webx_libcef_app.h"

namespace webx {

class WebXLibcefRendererApp : public WebXLibcefApp,
                              public CefRenderProcessHandler {
 public:
  WebXLibcefRendererApp();
  ~WebXLibcefRendererApp() override;

 private:
  CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;

  // CefRenderProcessHandler methods:
  void OnWebKitInitialized() override;
  void OnBrowserCreated(CefRefPtr<CefBrowser> browser,
                        CefRefPtr<CefDictionaryValue> extra_info) override;
  void OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) override;
  CefRefPtr<CefLoadHandler> GetLoadHandler() override;
  void OnContextCreated(CefRefPtr<CefBrowser> browser,
                        CefRefPtr<CefFrame> frame,
                        CefRefPtr<CefV8Context> context) override;
  void OnContextReleased(CefRefPtr<CefBrowser> browser,
                         CefRefPtr<CefFrame> frame,
                         CefRefPtr<CefV8Context> context) override;
  void OnUncaughtException(CefRefPtr<CefBrowser> browser,
                           CefRefPtr<CefFrame> frame,
                           CefRefPtr<CefV8Context> context,
                           CefRefPtr<CefV8Exception> exception,
                           CefRefPtr<CefV8StackTrace> stackTrace) override;
  void OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
                            CefRefPtr<CefFrame> frame,
                            CefRefPtr<CefDOMNode> node) override;
  bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
                                CefRefPtr<CefFrame> frame,
                                CefProcessId source_process,
                                CefRefPtr<CefProcessMessage> message) override;

 private:
  IMPLEMENT_REFCOUNTING(WebXLibcefRendererApp);
  DISALLOW_COPY_AND_ASSIGN(WebXLibcefRendererApp);
};

}  // namespace webx

#endif  // !WEBX_LIBWEBX_LIBCEF_WEBX_HELPER_APP_WEBX_LIBCEF_RENDERER_APP_H_