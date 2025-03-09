/**
 * @file      : libwebx.h
 * @author    : LittleKu<kklvzl@gmail.com>
 * @date      : 2025-03-08 15:36:16
 * @brief     :
 */
#ifndef WEBX_INCLUDE_LIBWEBX_H_
#define WEBX_INCLUDE_LIBWEBX_H_

#if defined(_WIN32)

#if defined(WEBX_LIBWEBX_EXPORTS)
#define WEBX_LIBWEBX_API __declspec(dllexport)
#else
#define WEBX_LIBWEBX_API __declspec(dllimport)
#endif

#else

#if defined(WEBX_LIBWEBX_EXPORTS)
#define WEBX_LIBWEBX_API __attribute__((visibility("default")))
#else
#define WEBX_LIBWEBX_API
#endif

#endif

class IWebXRefCounter {
 public:
  /**
   * @brief  引用计数加一
   */
  virtual void AddRef() = 0;

  /**
   * @brief 释放一个引用计数
   *
   * @return true 引用计数为0并且释放对象内存, 否则引用计数减一并返回 false
   */
  virtual bool Release() = 0;
};

class IWebXBaseInterface : public IWebXRefCounter {
 public:
  /**
   * @brief 对象的唯一标识, 用于查询获取某个对象
   *
   * @return
   */
  virtual const char* Unique() const = 0;

  /**
   * @brief 查询接口对象
   *
   * @param unique 查询目标对象的唯一标识
   * @param obj 返回查询到的对象指针
   * @return true 表示成功, false 表示失败
   */
  virtual bool QueryInterface(const char* unique, IWebXBaseInterface** obj) = 0;
};

enum class WebCoreType {
  Cef,
};

class IWebX : public IWebXBaseInterface {
 public:
  /**
   * @brief 初始化
   *
   * @param instance 进程实例
   * @param type 内核类型
   * @return true 表示成功, false 表示失败
   */
  virtual bool Initialize(void* instance, WebCoreType type) = 0;

  /**
   * @brief 反初始化
   *
   */
  virtual void UnInitialize() = 0;
};

extern "C" {
/**
 * @brief 创建一个 WebX 对象
 *
 * @param webx 返回创建的 WebX 对象指针
 * @return true 表示成功, false 表示失败
 */
WEBX_LIBWEBX_API bool CreateWebX(IWebX** webx);
}

#endif  // !WEBX_INCLUDE_LIBWEBX_H_