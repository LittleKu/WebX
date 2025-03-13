/**
 * @file      : webx_libcef_renderer_app.cc
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-10 20:55:14
 * @brief     : 
 */
#include "webx/libwebx/libcef/webx_helper/app/webx_libcef_renderer_app.h"

namespace webx {

WebXLibcefRendererApp::WebXLibcefRendererApp() = default;

WebXLibcefRendererApp::~WebXLibcefRendererApp() = default;

CefRefPtr<CefRenderProcessHandler>
WebXLibcefRendererApp::GetRenderProcessHandler() {
  return this;
}

void WebXLibcefRendererApp::OnWebKitInitialized() {}

void WebXLibcefRendererApp::OnBrowserCreated(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefDictionaryValue> extra_info) {}

void WebXLibcefRendererApp::OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) {}

CefRefPtr<CefLoadHandler> WebXLibcefRendererApp::GetLoadHandler() {
  return CefRefPtr<CefLoadHandler>();
}

void WebXLibcefRendererApp::OnContextCreated(CefRefPtr<CefBrowser> browser,
                                             CefRefPtr<CefFrame> frame,
                                             CefRefPtr<CefV8Context> context) {}

void WebXLibcefRendererApp::OnContextReleased(CefRefPtr<CefBrowser> browser,
                                              CefRefPtr<CefFrame> frame,
                                              CefRefPtr<CefV8Context> context) {
}

void WebXLibcefRendererApp::OnUncaughtException(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefV8Context> context,
    CefRefPtr<CefV8Exception> exception,
    CefRefPtr<CefV8StackTrace> stackTrace) {}

void WebXLibcefRendererApp::OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
                                                 CefRefPtr<CefFrame> frame,
                                                 CefRefPtr<CefDOMNode> node) {}

bool WebXLibcefRendererApp::OnProcessMessageReceived(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message) {
  return false;
}

}  // namespace webx
