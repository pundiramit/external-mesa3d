
/* Copyright © 2015-2021 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/* This file generated from vk_entrypoints_gen.py, don't edit directly. */

#include "vk_common_entrypoints.h"

/* Weak aliases for all potential implementations. These will resolve to
 * NULL if they're not defined, which lets the resolve_entrypoint() function
 * either pick the correct entry point.
 */




#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateInstance_Weak=vk_common_CreateInstance_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateInstance=vk_common_CreateInstance_Weak")
    VkResult (*vk_common_CreateInstance_Null)(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) = 0;
    VkResult vk_common_CreateInstance_Weak(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyInstance_Weak=vk_common_DestroyInstance_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyInstance=vk_common_DestroyInstance_Weak")
    void (*vk_common_DestroyInstance_Null)(VkInstance instance, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyInstance_Weak(VkInstance instance, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDevices_Weak=vk_common_EnumeratePhysicalDevices_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDevices=vk_common_EnumeratePhysicalDevices_Weak")
    VkResult (*vk_common_EnumeratePhysicalDevices_Null)(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) = 0;
    VkResult vk_common_EnumeratePhysicalDevices_Weak(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetInstanceProcAddr_Weak=vk_common_GetInstanceProcAddr_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetInstanceProcAddr=vk_common_GetInstanceProcAddr_Weak")
    PFN_vkVoidFunction (*vk_common_GetInstanceProcAddr_Null)(VkInstance instance, const char* pName) = 0;
    PFN_vkVoidFunction vk_common_GetInstanceProcAddr_Weak(VkInstance instance, const char* pName);
#else
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vk_common_GetInstanceProcAddr(VkInstance instance, const char* pName) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumerateInstanceVersion_Weak=vk_common_EnumerateInstanceVersion_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumerateInstanceVersion=vk_common_EnumerateInstanceVersion_Weak")
    VkResult (*vk_common_EnumerateInstanceVersion_Null)(uint32_t* pApiVersion) = 0;
    VkResult vk_common_EnumerateInstanceVersion_Weak(uint32_t* pApiVersion);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumerateInstanceVersion(uint32_t* pApiVersion) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumerateInstanceLayerProperties_Weak=vk_common_EnumerateInstanceLayerProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumerateInstanceLayerProperties=vk_common_EnumerateInstanceLayerProperties_Weak")
    VkResult (*vk_common_EnumerateInstanceLayerProperties_Null)(uint32_t* pPropertyCount, VkLayerProperties* pProperties) = 0;
    VkResult vk_common_EnumerateInstanceLayerProperties_Weak(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumerateInstanceExtensionProperties_Weak=vk_common_EnumerateInstanceExtensionProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumerateInstanceExtensionProperties=vk_common_EnumerateInstanceExtensionProperties_Weak")
    VkResult (*vk_common_EnumerateInstanceExtensionProperties_Null)(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) = 0;
    VkResult vk_common_EnumerateInstanceExtensionProperties_Weak(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateAndroidSurfaceKHR_Weak=vk_common_CreateAndroidSurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateAndroidSurfaceKHR=vk_common_CreateAndroidSurfaceKHR_Weak")
    VkResult (*vk_common_CreateAndroidSurfaceKHR_Null)(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateAndroidSurfaceKHR_Weak(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDisplayPlaneSurfaceKHR_Weak=vk_common_CreateDisplayPlaneSurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDisplayPlaneSurfaceKHR=vk_common_CreateDisplayPlaneSurfaceKHR_Weak")
    VkResult (*vk_common_CreateDisplayPlaneSurfaceKHR_Null)(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateDisplayPlaneSurfaceKHR_Weak(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroySurfaceKHR_Weak=vk_common_DestroySurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroySurfaceKHR=vk_common_DestroySurfaceKHR_Weak")
    void (*vk_common_DestroySurfaceKHR_Null)(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroySurfaceKHR_Weak(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_VI_NN
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateViSurfaceNN_Weak=vk_common_CreateViSurfaceNN_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateViSurfaceNN=vk_common_CreateViSurfaceNN_Weak")
    VkResult (*vk_common_CreateViSurfaceNN_Null)(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateViSurfaceNN_Weak(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_VI_NN
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateWaylandSurfaceKHR_Weak=vk_common_CreateWaylandSurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateWaylandSurfaceKHR=vk_common_CreateWaylandSurfaceKHR_Weak")
    VkResult (*vk_common_CreateWaylandSurfaceKHR_Null)(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateWaylandSurfaceKHR_Weak(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateWin32SurfaceKHR_Weak=vk_common_CreateWin32SurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateWin32SurfaceKHR=vk_common_CreateWin32SurfaceKHR_Weak")
    VkResult (*vk_common_CreateWin32SurfaceKHR_Null)(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateWin32SurfaceKHR_Weak(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateXlibSurfaceKHR_Weak=vk_common_CreateXlibSurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateXlibSurfaceKHR=vk_common_CreateXlibSurfaceKHR_Weak")
    VkResult (*vk_common_CreateXlibSurfaceKHR_Null)(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateXlibSurfaceKHR_Weak(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateXcbSurfaceKHR_Weak=vk_common_CreateXcbSurfaceKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateXcbSurfaceKHR=vk_common_CreateXcbSurfaceKHR_Weak")
    VkResult (*vk_common_CreateXcbSurfaceKHR_Null)(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateXcbSurfaceKHR_Weak(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDirectFBSurfaceEXT_Weak=vk_common_CreateDirectFBSurfaceEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDirectFBSurfaceEXT=vk_common_CreateDirectFBSurfaceEXT_Weak")
    VkResult (*vk_common_CreateDirectFBSurfaceEXT_Null)(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateDirectFBSurfaceEXT_Weak(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_FUCHSIA
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateImagePipeSurfaceFUCHSIA_Weak=vk_common_CreateImagePipeSurfaceFUCHSIA_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateImagePipeSurfaceFUCHSIA=vk_common_CreateImagePipeSurfaceFUCHSIA_Weak")
    VkResult (*vk_common_CreateImagePipeSurfaceFUCHSIA_Null)(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateImagePipeSurfaceFUCHSIA_Weak(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_GGP
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateStreamDescriptorSurfaceGGP_Weak=vk_common_CreateStreamDescriptorSurfaceGGP_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateStreamDescriptorSurfaceGGP=vk_common_CreateStreamDescriptorSurfaceGGP_Weak")
    VkResult (*vk_common_CreateStreamDescriptorSurfaceGGP_Null)(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateStreamDescriptorSurfaceGGP_Weak(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_GGP
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDebugReportCallbackEXT_Weak=vk_common_CreateDebugReportCallbackEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDebugReportCallbackEXT=vk_common_CreateDebugReportCallbackEXT_Weak")
    VkResult (*vk_common_CreateDebugReportCallbackEXT_Null)(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) = 0;
    VkResult vk_common_CreateDebugReportCallbackEXT_Weak(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDebugReportCallbackEXT_Weak=vk_common_DestroyDebugReportCallbackEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDebugReportCallbackEXT=vk_common_DestroyDebugReportCallbackEXT_Weak")
    void (*vk_common_DestroyDebugReportCallbackEXT_Null)(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDebugReportCallbackEXT_Weak(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DebugReportMessageEXT_Weak=vk_common_DebugReportMessageEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DebugReportMessageEXT=vk_common_DebugReportMessageEXT_Weak")
    void (*vk_common_DebugReportMessageEXT_Null)(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) = 0;
    void vk_common_DebugReportMessageEXT_Weak(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDeviceGroups_Weak=vk_common_EnumeratePhysicalDeviceGroups_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDeviceGroups=vk_common_EnumeratePhysicalDeviceGroups_Weak")
    VkResult (*vk_common_EnumeratePhysicalDeviceGroups_Null)(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) = 0;
    VkResult vk_common_EnumeratePhysicalDeviceGroups_Weak(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDeviceGroupsKHR_Weak=vk_common_EnumeratePhysicalDeviceGroupsKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDeviceGroupsKHR=vk_common_EnumeratePhysicalDeviceGroupsKHR_Weak")
    VkResult (*vk_common_EnumeratePhysicalDeviceGroupsKHR_Null)(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) = 0;
    VkResult vk_common_EnumeratePhysicalDeviceGroupsKHR_Weak(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_IOS_MVK
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateIOSSurfaceMVK_Weak=vk_common_CreateIOSSurfaceMVK_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateIOSSurfaceMVK=vk_common_CreateIOSSurfaceMVK_Weak")
    VkResult (*vk_common_CreateIOSSurfaceMVK_Null)(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateIOSSurfaceMVK_Weak(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateMacOSSurfaceMVK_Weak=vk_common_CreateMacOSSurfaceMVK_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateMacOSSurfaceMVK=vk_common_CreateMacOSSurfaceMVK_Weak")
    VkResult (*vk_common_CreateMacOSSurfaceMVK_Null)(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateMacOSSurfaceMVK_Weak(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateMetalSurfaceEXT_Weak=vk_common_CreateMetalSurfaceEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateMetalSurfaceEXT=vk_common_CreateMetalSurfaceEXT_Weak")
    VkResult (*vk_common_CreateMetalSurfaceEXT_Null)(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateMetalSurfaceEXT_Weak(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_METAL_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDebugUtilsMessengerEXT_Weak=vk_common_CreateDebugUtilsMessengerEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDebugUtilsMessengerEXT=vk_common_CreateDebugUtilsMessengerEXT_Weak")
    VkResult (*vk_common_CreateDebugUtilsMessengerEXT_Null)(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) = 0;
    VkResult vk_common_CreateDebugUtilsMessengerEXT_Weak(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDebugUtilsMessengerEXT_Weak=vk_common_DestroyDebugUtilsMessengerEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDebugUtilsMessengerEXT=vk_common_DestroyDebugUtilsMessengerEXT_Weak")
    void (*vk_common_DestroyDebugUtilsMessengerEXT_Null)(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDebugUtilsMessengerEXT_Weak(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SubmitDebugUtilsMessageEXT_Weak=vk_common_SubmitDebugUtilsMessageEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_SubmitDebugUtilsMessageEXT=vk_common_SubmitDebugUtilsMessageEXT_Weak")
    void (*vk_common_SubmitDebugUtilsMessageEXT_Null)(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) = 0;
    void vk_common_SubmitDebugUtilsMessageEXT_Weak(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_SubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateHeadlessSurfaceEXT_Weak=vk_common_CreateHeadlessSurfaceEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateHeadlessSurfaceEXT=vk_common_CreateHeadlessSurfaceEXT_Weak")
    VkResult (*vk_common_CreateHeadlessSurfaceEXT_Null)(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) = 0;
    VkResult vk_common_CreateHeadlessSurfaceEXT_Weak(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) __attribute__ ((weak));
#endif

const struct vk_instance_entrypoint_table vk_common_instance_entrypoints = {
    .CreateInstance = vk_common_CreateInstance,
    .DestroyInstance = vk_common_DestroyInstance,
    .EnumeratePhysicalDevices = vk_common_EnumeratePhysicalDevices,
    .GetInstanceProcAddr = vk_common_GetInstanceProcAddr,
    .EnumerateInstanceVersion = vk_common_EnumerateInstanceVersion,
    .EnumerateInstanceLayerProperties = vk_common_EnumerateInstanceLayerProperties,
    .EnumerateInstanceExtensionProperties = vk_common_EnumerateInstanceExtensionProperties,
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .CreateAndroidSurfaceKHR = vk_common_CreateAndroidSurfaceKHR,
#endif // VK_USE_PLATFORM_ANDROID_KHR
    .CreateDisplayPlaneSurfaceKHR = vk_common_CreateDisplayPlaneSurfaceKHR,
    .DestroySurfaceKHR = vk_common_DestroySurfaceKHR,
#ifdef VK_USE_PLATFORM_VI_NN
    .CreateViSurfaceNN = vk_common_CreateViSurfaceNN,
#endif // VK_USE_PLATFORM_VI_NN
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    .CreateWaylandSurfaceKHR = vk_common_CreateWaylandSurfaceKHR,
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .CreateWin32SurfaceKHR = vk_common_CreateWin32SurfaceKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    .CreateXlibSurfaceKHR = vk_common_CreateXlibSurfaceKHR,
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    .CreateXcbSurfaceKHR = vk_common_CreateXcbSurfaceKHR,
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    .CreateDirectFBSurfaceEXT = vk_common_CreateDirectFBSurfaceEXT,
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_FUCHSIA
    .CreateImagePipeSurfaceFUCHSIA = vk_common_CreateImagePipeSurfaceFUCHSIA,
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_GGP
    .CreateStreamDescriptorSurfaceGGP = vk_common_CreateStreamDescriptorSurfaceGGP,
#endif // VK_USE_PLATFORM_GGP
    .CreateDebugReportCallbackEXT = vk_common_CreateDebugReportCallbackEXT,
    .DestroyDebugReportCallbackEXT = vk_common_DestroyDebugReportCallbackEXT,
    .DebugReportMessageEXT = vk_common_DebugReportMessageEXT,
    .EnumeratePhysicalDeviceGroups = vk_common_EnumeratePhysicalDeviceGroups,
    .EnumeratePhysicalDeviceGroupsKHR = vk_common_EnumeratePhysicalDeviceGroupsKHR,
#ifdef VK_USE_PLATFORM_IOS_MVK
    .CreateIOSSurfaceMVK = vk_common_CreateIOSSurfaceMVK,
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
    .CreateMacOSSurfaceMVK = vk_common_CreateMacOSSurfaceMVK,
#endif // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
    .CreateMetalSurfaceEXT = vk_common_CreateMetalSurfaceEXT,
#endif // VK_USE_PLATFORM_METAL_EXT
    .CreateDebugUtilsMessengerEXT = vk_common_CreateDebugUtilsMessengerEXT,
    .DestroyDebugUtilsMessengerEXT = vk_common_DestroyDebugUtilsMessengerEXT,
    .SubmitDebugUtilsMessageEXT = vk_common_SubmitDebugUtilsMessageEXT,
    .CreateHeadlessSurfaceEXT = vk_common_CreateHeadlessSurfaceEXT,
};


#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceProperties_Weak=vk_common_GetPhysicalDeviceProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceProperties=vk_common_GetPhysicalDeviceProperties_Weak")
    void (*vk_common_GetPhysicalDeviceProperties_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) = 0;
    void vk_common_GetPhysicalDeviceProperties_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyProperties_Weak=vk_common_GetPhysicalDeviceQueueFamilyProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyProperties=vk_common_GetPhysicalDeviceQueueFamilyProperties_Weak")
    void (*vk_common_GetPhysicalDeviceQueueFamilyProperties_Null)(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) = 0;
    void vk_common_GetPhysicalDeviceQueueFamilyProperties_Weak(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMemoryProperties_Weak=vk_common_GetPhysicalDeviceMemoryProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMemoryProperties=vk_common_GetPhysicalDeviceMemoryProperties_Weak")
    void (*vk_common_GetPhysicalDeviceMemoryProperties_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) = 0;
    void vk_common_GetPhysicalDeviceMemoryProperties_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFeatures_Weak=vk_common_GetPhysicalDeviceFeatures_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFeatures=vk_common_GetPhysicalDeviceFeatures_Weak")
    void (*vk_common_GetPhysicalDeviceFeatures_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) = 0;
    void vk_common_GetPhysicalDeviceFeatures_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFormatProperties_Weak=vk_common_GetPhysicalDeviceFormatProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFormatProperties=vk_common_GetPhysicalDeviceFormatProperties_Weak")
    void (*vk_common_GetPhysicalDeviceFormatProperties_Null)(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) = 0;
    void vk_common_GetPhysicalDeviceFormatProperties_Weak(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceImageFormatProperties_Weak=vk_common_GetPhysicalDeviceImageFormatProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceImageFormatProperties=vk_common_GetPhysicalDeviceImageFormatProperties_Weak")
    VkResult (*vk_common_GetPhysicalDeviceImageFormatProperties_Null)(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceImageFormatProperties_Weak(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDevice_Weak=vk_common_CreateDevice_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDevice=vk_common_CreateDevice_Weak")
    VkResult (*vk_common_CreateDevice_Null)(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) = 0;
    VkResult vk_common_CreateDevice_Weak(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumerateDeviceLayerProperties_Weak=vk_common_EnumerateDeviceLayerProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumerateDeviceLayerProperties=vk_common_EnumerateDeviceLayerProperties_Weak")
    VkResult (*vk_common_EnumerateDeviceLayerProperties_Null)(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) = 0;
    VkResult vk_common_EnumerateDeviceLayerProperties_Weak(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumerateDeviceExtensionProperties_Weak=vk_common_EnumerateDeviceExtensionProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumerateDeviceExtensionProperties=vk_common_EnumerateDeviceExtensionProperties_Weak")
    VkResult (*vk_common_EnumerateDeviceExtensionProperties_Null)(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) = 0;
    VkResult vk_common_EnumerateDeviceExtensionProperties_Weak(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSparseImageFormatProperties_Weak=vk_common_GetPhysicalDeviceSparseImageFormatProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSparseImageFormatProperties=vk_common_GetPhysicalDeviceSparseImageFormatProperties_Weak")
    void (*vk_common_GetPhysicalDeviceSparseImageFormatProperties_Null)(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) = 0;
    void vk_common_GetPhysicalDeviceSparseImageFormatProperties_Weak(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayPropertiesKHR_Weak=vk_common_GetPhysicalDeviceDisplayPropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayPropertiesKHR=vk_common_GetPhysicalDeviceDisplayPropertiesKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceDisplayPropertiesKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceDisplayPropertiesKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR_Weak=vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR=vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayPlaneSupportedDisplaysKHR_Weak=vk_common_GetDisplayPlaneSupportedDisplaysKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayPlaneSupportedDisplaysKHR=vk_common_GetDisplayPlaneSupportedDisplaysKHR_Weak")
    VkResult (*vk_common_GetDisplayPlaneSupportedDisplaysKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) = 0;
    VkResult vk_common_GetDisplayPlaneSupportedDisplaysKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayModePropertiesKHR_Weak=vk_common_GetDisplayModePropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayModePropertiesKHR=vk_common_GetDisplayModePropertiesKHR_Weak")
    VkResult (*vk_common_GetDisplayModePropertiesKHR_Null)(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) = 0;
    VkResult vk_common_GetDisplayModePropertiesKHR_Weak(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDisplayModeKHR_Weak=vk_common_CreateDisplayModeKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDisplayModeKHR=vk_common_CreateDisplayModeKHR_Weak")
    VkResult (*vk_common_CreateDisplayModeKHR_Null)(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) = 0;
    VkResult vk_common_CreateDisplayModeKHR_Weak(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayPlaneCapabilitiesKHR_Weak=vk_common_GetDisplayPlaneCapabilitiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayPlaneCapabilitiesKHR=vk_common_GetDisplayPlaneCapabilitiesKHR_Weak")
    VkResult (*vk_common_GetDisplayPlaneCapabilitiesKHR_Null)(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) = 0;
    VkResult vk_common_GetDisplayPlaneCapabilitiesKHR_Weak(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceSupportKHR_Weak=vk_common_GetPhysicalDeviceSurfaceSupportKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceSupportKHR=vk_common_GetPhysicalDeviceSurfaceSupportKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfaceSupportKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfaceSupportKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR_Weak=vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR=vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR_Null)(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR_Weak(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceFormatsKHR_Weak=vk_common_GetPhysicalDeviceSurfaceFormatsKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceFormatsKHR=vk_common_GetPhysicalDeviceSurfaceFormatsKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfaceFormatsKHR_Null)(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfaceFormatsKHR_Weak(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfacePresentModesKHR_Weak=vk_common_GetPhysicalDeviceSurfacePresentModesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfacePresentModesKHR=vk_common_GetPhysicalDeviceSurfacePresentModesKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfacePresentModesKHR_Null)(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfacePresentModesKHR_Weak(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR_Weak=vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR=vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR_Weak")
    VkBool32 (*vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) = 0;
    VkBool32 vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display);
#else
    VKAPI_ATTR VkBool32 VKAPI_CALL vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceWin32PresentationSupportKHR_Weak=vk_common_GetPhysicalDeviceWin32PresentationSupportKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceWin32PresentationSupportKHR=vk_common_GetPhysicalDeviceWin32PresentationSupportKHR_Weak")
    VkBool32 (*vk_common_GetPhysicalDeviceWin32PresentationSupportKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) = 0;
    VkBool32 vk_common_GetPhysicalDeviceWin32PresentationSupportKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
#else
    VKAPI_ATTR VkBool32 VKAPI_CALL vk_common_GetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceXlibPresentationSupportKHR_Weak=vk_common_GetPhysicalDeviceXlibPresentationSupportKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceXlibPresentationSupportKHR=vk_common_GetPhysicalDeviceXlibPresentationSupportKHR_Weak")
    VkBool32 (*vk_common_GetPhysicalDeviceXlibPresentationSupportKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) = 0;
    VkBool32 vk_common_GetPhysicalDeviceXlibPresentationSupportKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);
#else
    VKAPI_ATTR VkBool32 VKAPI_CALL vk_common_GetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceXcbPresentationSupportKHR_Weak=vk_common_GetPhysicalDeviceXcbPresentationSupportKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceXcbPresentationSupportKHR=vk_common_GetPhysicalDeviceXcbPresentationSupportKHR_Weak")
    VkBool32 (*vk_common_GetPhysicalDeviceXcbPresentationSupportKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) = 0;
    VkBool32 vk_common_GetPhysicalDeviceXcbPresentationSupportKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
#else
    VKAPI_ATTR VkBool32 VKAPI_CALL vk_common_GetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT_Weak=vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT=vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT_Weak")
    VkBool32 (*vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) = 0;
    VkBool32 vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb);
#else
    VKAPI_ATTR VkBool32 VKAPI_CALL vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV_Weak=vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV=vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV_Weak")
    VkResult (*vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV_Null)(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV_Weak(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFeatures2_Weak=vk_common_GetPhysicalDeviceFeatures2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFeatures2=vk_common_GetPhysicalDeviceFeatures2_Weak")
    void (*vk_common_GetPhysicalDeviceFeatures2_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) = 0;
    void vk_common_GetPhysicalDeviceFeatures2_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFeatures2KHR_Weak=vk_common_GetPhysicalDeviceFeatures2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFeatures2KHR=vk_common_GetPhysicalDeviceFeatures2KHR_Weak")
    void (*vk_common_GetPhysicalDeviceFeatures2KHR_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) = 0;
    void vk_common_GetPhysicalDeviceFeatures2KHR_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceProperties2_Weak=vk_common_GetPhysicalDeviceProperties2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceProperties2=vk_common_GetPhysicalDeviceProperties2_Weak")
    void (*vk_common_GetPhysicalDeviceProperties2_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) = 0;
    void vk_common_GetPhysicalDeviceProperties2_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceProperties2KHR_Weak=vk_common_GetPhysicalDeviceProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceProperties2KHR=vk_common_GetPhysicalDeviceProperties2KHR_Weak")
    void (*vk_common_GetPhysicalDeviceProperties2KHR_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) = 0;
    void vk_common_GetPhysicalDeviceProperties2KHR_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFormatProperties2_Weak=vk_common_GetPhysicalDeviceFormatProperties2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFormatProperties2=vk_common_GetPhysicalDeviceFormatProperties2_Weak")
    void (*vk_common_GetPhysicalDeviceFormatProperties2_Null)(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) = 0;
    void vk_common_GetPhysicalDeviceFormatProperties2_Weak(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFormatProperties2KHR_Weak=vk_common_GetPhysicalDeviceFormatProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFormatProperties2KHR=vk_common_GetPhysicalDeviceFormatProperties2KHR_Weak")
    void (*vk_common_GetPhysicalDeviceFormatProperties2KHR_Null)(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) = 0;
    void vk_common_GetPhysicalDeviceFormatProperties2KHR_Weak(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceImageFormatProperties2_Weak=vk_common_GetPhysicalDeviceImageFormatProperties2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceImageFormatProperties2=vk_common_GetPhysicalDeviceImageFormatProperties2_Weak")
    VkResult (*vk_common_GetPhysicalDeviceImageFormatProperties2_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceImageFormatProperties2_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceImageFormatProperties2KHR_Weak=vk_common_GetPhysicalDeviceImageFormatProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceImageFormatProperties2KHR=vk_common_GetPhysicalDeviceImageFormatProperties2KHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceImageFormatProperties2KHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceImageFormatProperties2KHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyProperties2_Weak=vk_common_GetPhysicalDeviceQueueFamilyProperties2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyProperties2=vk_common_GetPhysicalDeviceQueueFamilyProperties2_Weak")
    void (*vk_common_GetPhysicalDeviceQueueFamilyProperties2_Null)(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) = 0;
    void vk_common_GetPhysicalDeviceQueueFamilyProperties2_Weak(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR_Weak=vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR=vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR_Weak")
    void (*vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR_Null)(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) = 0;
    void vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR_Weak(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMemoryProperties2_Weak=vk_common_GetPhysicalDeviceMemoryProperties2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMemoryProperties2=vk_common_GetPhysicalDeviceMemoryProperties2_Weak")
    void (*vk_common_GetPhysicalDeviceMemoryProperties2_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) = 0;
    void vk_common_GetPhysicalDeviceMemoryProperties2_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMemoryProperties2KHR_Weak=vk_common_GetPhysicalDeviceMemoryProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMemoryProperties2KHR=vk_common_GetPhysicalDeviceMemoryProperties2KHR_Weak")
    void (*vk_common_GetPhysicalDeviceMemoryProperties2KHR_Null)(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) = 0;
    void vk_common_GetPhysicalDeviceMemoryProperties2KHR_Weak(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSparseImageFormatProperties2_Weak=vk_common_GetPhysicalDeviceSparseImageFormatProperties2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSparseImageFormatProperties2=vk_common_GetPhysicalDeviceSparseImageFormatProperties2_Weak")
    void (*vk_common_GetPhysicalDeviceSparseImageFormatProperties2_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) = 0;
    void vk_common_GetPhysicalDeviceSparseImageFormatProperties2_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR_Weak=vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR=vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR_Weak")
    void (*vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) = 0;
    void vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalBufferProperties_Weak=vk_common_GetPhysicalDeviceExternalBufferProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalBufferProperties=vk_common_GetPhysicalDeviceExternalBufferProperties_Weak")
    void (*vk_common_GetPhysicalDeviceExternalBufferProperties_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) = 0;
    void vk_common_GetPhysicalDeviceExternalBufferProperties_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR_Weak=vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR=vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR_Weak")
    void (*vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) = 0;
    void vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalSemaphoreProperties_Weak=vk_common_GetPhysicalDeviceExternalSemaphoreProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalSemaphoreProperties=vk_common_GetPhysicalDeviceExternalSemaphoreProperties_Weak")
    void (*vk_common_GetPhysicalDeviceExternalSemaphoreProperties_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) = 0;
    void vk_common_GetPhysicalDeviceExternalSemaphoreProperties_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR_Weak=vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR=vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR_Weak")
    void (*vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) = 0;
    void vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalFenceProperties_Weak=vk_common_GetPhysicalDeviceExternalFenceProperties_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalFenceProperties=vk_common_GetPhysicalDeviceExternalFenceProperties_Weak")
    void (*vk_common_GetPhysicalDeviceExternalFenceProperties_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) = 0;
    void vk_common_GetPhysicalDeviceExternalFenceProperties_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalFencePropertiesKHR_Weak=vk_common_GetPhysicalDeviceExternalFencePropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceExternalFencePropertiesKHR=vk_common_GetPhysicalDeviceExternalFencePropertiesKHR_Weak")
    void (*vk_common_GetPhysicalDeviceExternalFencePropertiesKHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) = 0;
    void vk_common_GetPhysicalDeviceExternalFencePropertiesKHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ReleaseDisplayEXT_Weak=vk_common_ReleaseDisplayEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_ReleaseDisplayEXT=vk_common_ReleaseDisplayEXT_Weak")
    VkResult (*vk_common_ReleaseDisplayEXT_Null)(VkPhysicalDevice physicalDevice, VkDisplayKHR display) = 0;
    VkResult vk_common_ReleaseDisplayEXT_Weak(VkPhysicalDevice physicalDevice, VkDisplayKHR display);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireXlibDisplayEXT_Weak=vk_common_AcquireXlibDisplayEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireXlibDisplayEXT=vk_common_AcquireXlibDisplayEXT_Weak")
    VkResult (*vk_common_AcquireXlibDisplayEXT_Null)(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) = 0;
    VkResult vk_common_AcquireXlibDisplayEXT_Weak(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRandROutputDisplayEXT_Weak=vk_common_GetRandROutputDisplayEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRandROutputDisplayEXT=vk_common_GetRandROutputDisplayEXT_Weak")
    VkResult (*vk_common_GetRandROutputDisplayEXT_Null)(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) = 0;
    VkResult vk_common_GetRandROutputDisplayEXT_Weak(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireWinrtDisplayNV_Weak=vk_common_AcquireWinrtDisplayNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireWinrtDisplayNV=vk_common_AcquireWinrtDisplayNV_Weak")
    VkResult (*vk_common_AcquireWinrtDisplayNV_Null)(VkPhysicalDevice physicalDevice, VkDisplayKHR display) = 0;
    VkResult vk_common_AcquireWinrtDisplayNV_Weak(VkPhysicalDevice physicalDevice, VkDisplayKHR display);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetWinrtDisplayNV_Weak=vk_common_GetWinrtDisplayNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetWinrtDisplayNV=vk_common_GetWinrtDisplayNV_Weak")
    VkResult (*vk_common_GetWinrtDisplayNV_Null)(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) = 0;
    VkResult vk_common_GetWinrtDisplayNV_Weak(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT_Weak=vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT=vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT_Null)(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT_Weak(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDevicePresentRectanglesKHR_Weak=vk_common_GetPhysicalDevicePresentRectanglesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDevicePresentRectanglesKHR=vk_common_GetPhysicalDevicePresentRectanglesKHR_Weak")
    VkResult (*vk_common_GetPhysicalDevicePresentRectanglesKHR_Null)(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) = 0;
    VkResult vk_common_GetPhysicalDevicePresentRectanglesKHR_Weak(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMultisamplePropertiesEXT_Weak=vk_common_GetPhysicalDeviceMultisamplePropertiesEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceMultisamplePropertiesEXT=vk_common_GetPhysicalDeviceMultisamplePropertiesEXT_Weak")
    void (*vk_common_GetPhysicalDeviceMultisamplePropertiesEXT_Null)(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) = 0;
    void vk_common_GetPhysicalDeviceMultisamplePropertiesEXT_Weak(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR_Weak=vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR=vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceFormats2KHR_Weak=vk_common_GetPhysicalDeviceSurfaceFormats2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfaceFormats2KHR=vk_common_GetPhysicalDeviceSurfaceFormats2KHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfaceFormats2KHR_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfaceFormats2KHR_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayProperties2KHR_Weak=vk_common_GetPhysicalDeviceDisplayProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayProperties2KHR=vk_common_GetPhysicalDeviceDisplayProperties2KHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceDisplayProperties2KHR_Null)(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceDisplayProperties2KHR_Weak(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR_Weak=vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR=vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR_Null)(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR_Weak(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayModeProperties2KHR_Weak=vk_common_GetDisplayModeProperties2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayModeProperties2KHR=vk_common_GetDisplayModeProperties2KHR_Weak")
    VkResult (*vk_common_GetDisplayModeProperties2KHR_Null)(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) = 0;
    VkResult vk_common_GetDisplayModeProperties2KHR_Weak(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayPlaneCapabilities2KHR_Weak=vk_common_GetDisplayPlaneCapabilities2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDisplayPlaneCapabilities2KHR=vk_common_GetDisplayPlaneCapabilities2KHR_Weak")
    VkResult (*vk_common_GetDisplayPlaneCapabilities2KHR_Null)(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) = 0;
    VkResult vk_common_GetDisplayPlaneCapabilities2KHR_Weak(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT_Weak=vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT=vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT_Weak")
    VkResult (*vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT_Null)(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains) = 0;
    VkResult vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT_Weak(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV_Weak=vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV=vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV_Weak")
    VkResult (*vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV_Null)(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV_Weak(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfacePresentModes2EXT_Weak=vk_common_GetPhysicalDeviceSurfacePresentModes2EXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSurfacePresentModes2EXT=vk_common_GetPhysicalDeviceSurfacePresentModes2EXT_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSurfacePresentModes2EXT_Null)(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) = 0;
    VkResult vk_common_GetPhysicalDeviceSurfacePresentModes2EXT_Weak(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_Weak=vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR=vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_Weak")
    VkResult (*vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) = 0;
    VkResult vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_Weak=vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR=vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_Weak")
    void (*vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_Null)(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) = 0;
    void vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_Weak(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_Weak=vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV=vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_Weak")
    VkResult (*vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_Null)(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) = 0;
    VkResult vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_Weak(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceToolPropertiesEXT_Weak=vk_common_GetPhysicalDeviceToolPropertiesEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceToolPropertiesEXT=vk_common_GetPhysicalDeviceToolPropertiesEXT_Weak")
    VkResult (*vk_common_GetPhysicalDeviceToolPropertiesEXT_Null)(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties) = 0;
    VkResult vk_common_GetPhysicalDeviceToolPropertiesEXT_Weak(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFragmentShadingRatesKHR_Weak=vk_common_GetPhysicalDeviceFragmentShadingRatesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPhysicalDeviceFragmentShadingRatesKHR=vk_common_GetPhysicalDeviceFragmentShadingRatesKHR_Weak")
    VkResult (*vk_common_GetPhysicalDeviceFragmentShadingRatesKHR_Null)(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) = 0;
    VkResult vk_common_GetPhysicalDeviceFragmentShadingRatesKHR_Weak(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) __attribute__ ((weak));
#endif

const struct vk_physical_device_entrypoint_table vk_common_physical_device_entrypoints = {
    .GetPhysicalDeviceProperties = vk_common_GetPhysicalDeviceProperties,
    .GetPhysicalDeviceQueueFamilyProperties = vk_common_GetPhysicalDeviceQueueFamilyProperties,
    .GetPhysicalDeviceMemoryProperties = vk_common_GetPhysicalDeviceMemoryProperties,
    .GetPhysicalDeviceFeatures = vk_common_GetPhysicalDeviceFeatures,
    .GetPhysicalDeviceFormatProperties = vk_common_GetPhysicalDeviceFormatProperties,
    .GetPhysicalDeviceImageFormatProperties = vk_common_GetPhysicalDeviceImageFormatProperties,
    .CreateDevice = vk_common_CreateDevice,
    .EnumerateDeviceLayerProperties = vk_common_EnumerateDeviceLayerProperties,
    .EnumerateDeviceExtensionProperties = vk_common_EnumerateDeviceExtensionProperties,
    .GetPhysicalDeviceSparseImageFormatProperties = vk_common_GetPhysicalDeviceSparseImageFormatProperties,
    .GetPhysicalDeviceDisplayPropertiesKHR = vk_common_GetPhysicalDeviceDisplayPropertiesKHR,
    .GetPhysicalDeviceDisplayPlanePropertiesKHR = vk_common_GetPhysicalDeviceDisplayPlanePropertiesKHR,
    .GetDisplayPlaneSupportedDisplaysKHR = vk_common_GetDisplayPlaneSupportedDisplaysKHR,
    .GetDisplayModePropertiesKHR = vk_common_GetDisplayModePropertiesKHR,
    .CreateDisplayModeKHR = vk_common_CreateDisplayModeKHR,
    .GetDisplayPlaneCapabilitiesKHR = vk_common_GetDisplayPlaneCapabilitiesKHR,
    .GetPhysicalDeviceSurfaceSupportKHR = vk_common_GetPhysicalDeviceSurfaceSupportKHR,
    .GetPhysicalDeviceSurfaceCapabilitiesKHR = vk_common_GetPhysicalDeviceSurfaceCapabilitiesKHR,
    .GetPhysicalDeviceSurfaceFormatsKHR = vk_common_GetPhysicalDeviceSurfaceFormatsKHR,
    .GetPhysicalDeviceSurfacePresentModesKHR = vk_common_GetPhysicalDeviceSurfacePresentModesKHR,
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    .GetPhysicalDeviceWaylandPresentationSupportKHR = vk_common_GetPhysicalDeviceWaylandPresentationSupportKHR,
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetPhysicalDeviceWin32PresentationSupportKHR = vk_common_GetPhysicalDeviceWin32PresentationSupportKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    .GetPhysicalDeviceXlibPresentationSupportKHR = vk_common_GetPhysicalDeviceXlibPresentationSupportKHR,
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    .GetPhysicalDeviceXcbPresentationSupportKHR = vk_common_GetPhysicalDeviceXcbPresentationSupportKHR,
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    .GetPhysicalDeviceDirectFBPresentationSupportEXT = vk_common_GetPhysicalDeviceDirectFBPresentationSupportEXT,
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
    .GetPhysicalDeviceExternalImageFormatPropertiesNV = vk_common_GetPhysicalDeviceExternalImageFormatPropertiesNV,
    .GetPhysicalDeviceFeatures2 = vk_common_GetPhysicalDeviceFeatures2,
    .GetPhysicalDeviceFeatures2KHR = vk_common_GetPhysicalDeviceFeatures2KHR,
    .GetPhysicalDeviceProperties2 = vk_common_GetPhysicalDeviceProperties2,
    .GetPhysicalDeviceProperties2KHR = vk_common_GetPhysicalDeviceProperties2KHR,
    .GetPhysicalDeviceFormatProperties2 = vk_common_GetPhysicalDeviceFormatProperties2,
    .GetPhysicalDeviceFormatProperties2KHR = vk_common_GetPhysicalDeviceFormatProperties2KHR,
    .GetPhysicalDeviceImageFormatProperties2 = vk_common_GetPhysicalDeviceImageFormatProperties2,
    .GetPhysicalDeviceImageFormatProperties2KHR = vk_common_GetPhysicalDeviceImageFormatProperties2KHR,
    .GetPhysicalDeviceQueueFamilyProperties2 = vk_common_GetPhysicalDeviceQueueFamilyProperties2,
    .GetPhysicalDeviceQueueFamilyProperties2KHR = vk_common_GetPhysicalDeviceQueueFamilyProperties2KHR,
    .GetPhysicalDeviceMemoryProperties2 = vk_common_GetPhysicalDeviceMemoryProperties2,
    .GetPhysicalDeviceMemoryProperties2KHR = vk_common_GetPhysicalDeviceMemoryProperties2KHR,
    .GetPhysicalDeviceSparseImageFormatProperties2 = vk_common_GetPhysicalDeviceSparseImageFormatProperties2,
    .GetPhysicalDeviceSparseImageFormatProperties2KHR = vk_common_GetPhysicalDeviceSparseImageFormatProperties2KHR,
    .GetPhysicalDeviceExternalBufferProperties = vk_common_GetPhysicalDeviceExternalBufferProperties,
    .GetPhysicalDeviceExternalBufferPropertiesKHR = vk_common_GetPhysicalDeviceExternalBufferPropertiesKHR,
    .GetPhysicalDeviceExternalSemaphoreProperties = vk_common_GetPhysicalDeviceExternalSemaphoreProperties,
    .GetPhysicalDeviceExternalSemaphorePropertiesKHR = vk_common_GetPhysicalDeviceExternalSemaphorePropertiesKHR,
    .GetPhysicalDeviceExternalFenceProperties = vk_common_GetPhysicalDeviceExternalFenceProperties,
    .GetPhysicalDeviceExternalFencePropertiesKHR = vk_common_GetPhysicalDeviceExternalFencePropertiesKHR,
    .ReleaseDisplayEXT = vk_common_ReleaseDisplayEXT,
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    .AcquireXlibDisplayEXT = vk_common_AcquireXlibDisplayEXT,
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    .GetRandROutputDisplayEXT = vk_common_GetRandROutputDisplayEXT,
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .AcquireWinrtDisplayNV = vk_common_AcquireWinrtDisplayNV,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetWinrtDisplayNV = vk_common_GetWinrtDisplayNV,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .GetPhysicalDeviceSurfaceCapabilities2EXT = vk_common_GetPhysicalDeviceSurfaceCapabilities2EXT,
    .GetPhysicalDevicePresentRectanglesKHR = vk_common_GetPhysicalDevicePresentRectanglesKHR,
    .GetPhysicalDeviceMultisamplePropertiesEXT = vk_common_GetPhysicalDeviceMultisamplePropertiesEXT,
    .GetPhysicalDeviceSurfaceCapabilities2KHR = vk_common_GetPhysicalDeviceSurfaceCapabilities2KHR,
    .GetPhysicalDeviceSurfaceFormats2KHR = vk_common_GetPhysicalDeviceSurfaceFormats2KHR,
    .GetPhysicalDeviceDisplayProperties2KHR = vk_common_GetPhysicalDeviceDisplayProperties2KHR,
    .GetPhysicalDeviceDisplayPlaneProperties2KHR = vk_common_GetPhysicalDeviceDisplayPlaneProperties2KHR,
    .GetDisplayModeProperties2KHR = vk_common_GetDisplayModeProperties2KHR,
    .GetDisplayPlaneCapabilities2KHR = vk_common_GetDisplayPlaneCapabilities2KHR,
    .GetPhysicalDeviceCalibrateableTimeDomainsEXT = vk_common_GetPhysicalDeviceCalibrateableTimeDomainsEXT,
    .GetPhysicalDeviceCooperativeMatrixPropertiesNV = vk_common_GetPhysicalDeviceCooperativeMatrixPropertiesNV,
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetPhysicalDeviceSurfacePresentModes2EXT = vk_common_GetPhysicalDeviceSurfacePresentModes2EXT,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = vk_common_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR,
    .GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = vk_common_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR,
    .GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = vk_common_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV,
    .GetPhysicalDeviceToolPropertiesEXT = vk_common_GetPhysicalDeviceToolPropertiesEXT,
    .GetPhysicalDeviceFragmentShadingRatesKHR = vk_common_GetPhysicalDeviceFragmentShadingRatesKHR,
};


#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceProcAddr_Weak=vk_common_GetDeviceProcAddr_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceProcAddr=vk_common_GetDeviceProcAddr_Weak")
    PFN_vkVoidFunction (*vk_common_GetDeviceProcAddr_Null)(VkDevice device, const char* pName) = 0;
    PFN_vkVoidFunction vk_common_GetDeviceProcAddr_Weak(VkDevice device, const char* pName);
#else
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vk_common_GetDeviceProcAddr(VkDevice device, const char* pName) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDevice_Weak=vk_common_DestroyDevice_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDevice=vk_common_DestroyDevice_Weak")
    void (*vk_common_DestroyDevice_Null)(VkDevice device, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDevice_Weak(VkDevice device, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceQueue_Weak=vk_common_GetDeviceQueue_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceQueue=vk_common_GetDeviceQueue_Weak")
    void (*vk_common_GetDeviceQueue_Null)(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) = 0;
    void vk_common_GetDeviceQueue_Weak(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueSubmit_Weak=vk_common_QueueSubmit_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueSubmit=vk_common_QueueSubmit_Weak")
    VkResult (*vk_common_QueueSubmit_Null)(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) = 0;
    VkResult vk_common_QueueSubmit_Weak(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueWaitIdle_Weak=vk_common_QueueWaitIdle_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueWaitIdle=vk_common_QueueWaitIdle_Weak")
    VkResult (*vk_common_QueueWaitIdle_Null)(VkQueue queue) = 0;
    VkResult vk_common_QueueWaitIdle_Weak(VkQueue queue);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_QueueWaitIdle(VkQueue queue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DeviceWaitIdle_Weak=vk_common_DeviceWaitIdle_Null")
    #pragma comment(linker, "/alternatename:vk_common_DeviceWaitIdle=vk_common_DeviceWaitIdle_Weak")
    VkResult (*vk_common_DeviceWaitIdle_Null)(VkDevice device) = 0;
    VkResult vk_common_DeviceWaitIdle_Weak(VkDevice device);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_DeviceWaitIdle(VkDevice device) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AllocateMemory_Weak=vk_common_AllocateMemory_Null")
    #pragma comment(linker, "/alternatename:vk_common_AllocateMemory=vk_common_AllocateMemory_Weak")
    VkResult (*vk_common_AllocateMemory_Null)(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) = 0;
    VkResult vk_common_AllocateMemory_Weak(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_FreeMemory_Weak=vk_common_FreeMemory_Null")
    #pragma comment(linker, "/alternatename:vk_common_FreeMemory=vk_common_FreeMemory_Weak")
    void (*vk_common_FreeMemory_Null)(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_FreeMemory_Weak(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_MapMemory_Weak=vk_common_MapMemory_Null")
    #pragma comment(linker, "/alternatename:vk_common_MapMemory=vk_common_MapMemory_Weak")
    VkResult (*vk_common_MapMemory_Null)(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) = 0;
    VkResult vk_common_MapMemory_Weak(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_UnmapMemory_Weak=vk_common_UnmapMemory_Null")
    #pragma comment(linker, "/alternatename:vk_common_UnmapMemory=vk_common_UnmapMemory_Weak")
    void (*vk_common_UnmapMemory_Null)(VkDevice device, VkDeviceMemory memory) = 0;
    void vk_common_UnmapMemory_Weak(VkDevice device, VkDeviceMemory memory);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_UnmapMemory(VkDevice device, VkDeviceMemory memory) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_FlushMappedMemoryRanges_Weak=vk_common_FlushMappedMemoryRanges_Null")
    #pragma comment(linker, "/alternatename:vk_common_FlushMappedMemoryRanges=vk_common_FlushMappedMemoryRanges_Weak")
    VkResult (*vk_common_FlushMappedMemoryRanges_Null)(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) = 0;
    VkResult vk_common_FlushMappedMemoryRanges_Weak(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_InvalidateMappedMemoryRanges_Weak=vk_common_InvalidateMappedMemoryRanges_Null")
    #pragma comment(linker, "/alternatename:vk_common_InvalidateMappedMemoryRanges=vk_common_InvalidateMappedMemoryRanges_Weak")
    VkResult (*vk_common_InvalidateMappedMemoryRanges_Null)(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) = 0;
    VkResult vk_common_InvalidateMappedMemoryRanges_Weak(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceMemoryCommitment_Weak=vk_common_GetDeviceMemoryCommitment_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceMemoryCommitment=vk_common_GetDeviceMemoryCommitment_Weak")
    void (*vk_common_GetDeviceMemoryCommitment_Null)(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) = 0;
    void vk_common_GetDeviceMemoryCommitment_Weak(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferMemoryRequirements_Weak=vk_common_GetBufferMemoryRequirements_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferMemoryRequirements=vk_common_GetBufferMemoryRequirements_Weak")
    void (*vk_common_GetBufferMemoryRequirements_Null)(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) = 0;
    void vk_common_GetBufferMemoryRequirements_Weak(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindBufferMemory_Weak=vk_common_BindBufferMemory_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindBufferMemory=vk_common_BindBufferMemory_Weak")
    VkResult (*vk_common_BindBufferMemory_Null)(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) = 0;
    VkResult vk_common_BindBufferMemory_Weak(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageMemoryRequirements_Weak=vk_common_GetImageMemoryRequirements_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageMemoryRequirements=vk_common_GetImageMemoryRequirements_Weak")
    void (*vk_common_GetImageMemoryRequirements_Null)(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) = 0;
    void vk_common_GetImageMemoryRequirements_Weak(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindImageMemory_Weak=vk_common_BindImageMemory_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindImageMemory=vk_common_BindImageMemory_Weak")
    VkResult (*vk_common_BindImageMemory_Null)(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) = 0;
    VkResult vk_common_BindImageMemory_Weak(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageSparseMemoryRequirements_Weak=vk_common_GetImageSparseMemoryRequirements_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageSparseMemoryRequirements=vk_common_GetImageSparseMemoryRequirements_Weak")
    void (*vk_common_GetImageSparseMemoryRequirements_Null)(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) = 0;
    void vk_common_GetImageSparseMemoryRequirements_Weak(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueBindSparse_Weak=vk_common_QueueBindSparse_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueBindSparse=vk_common_QueueBindSparse_Weak")
    VkResult (*vk_common_QueueBindSparse_Null)(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) = 0;
    VkResult vk_common_QueueBindSparse_Weak(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateFence_Weak=vk_common_CreateFence_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateFence=vk_common_CreateFence_Weak")
    VkResult (*vk_common_CreateFence_Null)(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) = 0;
    VkResult vk_common_CreateFence_Weak(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyFence_Weak=vk_common_DestroyFence_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyFence=vk_common_DestroyFence_Weak")
    void (*vk_common_DestroyFence_Null)(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyFence_Weak(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetFences_Weak=vk_common_ResetFences_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetFences=vk_common_ResetFences_Weak")
    VkResult (*vk_common_ResetFences_Null)(VkDevice device, uint32_t fenceCount, const VkFence* pFences) = 0;
    VkResult vk_common_ResetFences_Weak(VkDevice device, uint32_t fenceCount, const VkFence* pFences);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetFenceStatus_Weak=vk_common_GetFenceStatus_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetFenceStatus=vk_common_GetFenceStatus_Weak")
    VkResult (*vk_common_GetFenceStatus_Null)(VkDevice device, VkFence fence) = 0;
    VkResult vk_common_GetFenceStatus_Weak(VkDevice device, VkFence fence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetFenceStatus(VkDevice device, VkFence fence) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_WaitForFences_Weak=vk_common_WaitForFences_Null")
    #pragma comment(linker, "/alternatename:vk_common_WaitForFences=vk_common_WaitForFences_Weak")
    VkResult (*vk_common_WaitForFences_Null)(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) = 0;
    VkResult vk_common_WaitForFences_Weak(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateSemaphore_Weak=vk_common_CreateSemaphore_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateSemaphore=vk_common_CreateSemaphore_Weak")
    VkResult (*vk_common_CreateSemaphore_Null)(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) = 0;
    VkResult vk_common_CreateSemaphore_Weak(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroySemaphore_Weak=vk_common_DestroySemaphore_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroySemaphore=vk_common_DestroySemaphore_Weak")
    void (*vk_common_DestroySemaphore_Null)(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroySemaphore_Weak(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateEvent_Weak=vk_common_CreateEvent_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateEvent=vk_common_CreateEvent_Weak")
    VkResult (*vk_common_CreateEvent_Null)(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) = 0;
    VkResult vk_common_CreateEvent_Weak(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyEvent_Weak=vk_common_DestroyEvent_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyEvent=vk_common_DestroyEvent_Weak")
    void (*vk_common_DestroyEvent_Null)(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyEvent_Weak(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetEventStatus_Weak=vk_common_GetEventStatus_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetEventStatus=vk_common_GetEventStatus_Weak")
    VkResult (*vk_common_GetEventStatus_Null)(VkDevice device, VkEvent event) = 0;
    VkResult vk_common_GetEventStatus_Weak(VkDevice device, VkEvent event);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetEventStatus(VkDevice device, VkEvent event) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SetEvent_Weak=vk_common_SetEvent_Null")
    #pragma comment(linker, "/alternatename:vk_common_SetEvent=vk_common_SetEvent_Weak")
    VkResult (*vk_common_SetEvent_Null)(VkDevice device, VkEvent event) = 0;
    VkResult vk_common_SetEvent_Weak(VkDevice device, VkEvent event);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_SetEvent(VkDevice device, VkEvent event) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetEvent_Weak=vk_common_ResetEvent_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetEvent=vk_common_ResetEvent_Weak")
    VkResult (*vk_common_ResetEvent_Null)(VkDevice device, VkEvent event) = 0;
    VkResult vk_common_ResetEvent_Weak(VkDevice device, VkEvent event);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ResetEvent(VkDevice device, VkEvent event) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateQueryPool_Weak=vk_common_CreateQueryPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateQueryPool=vk_common_CreateQueryPool_Weak")
    VkResult (*vk_common_CreateQueryPool_Null)(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) = 0;
    VkResult vk_common_CreateQueryPool_Weak(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyQueryPool_Weak=vk_common_DestroyQueryPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyQueryPool=vk_common_DestroyQueryPool_Weak")
    void (*vk_common_DestroyQueryPool_Null)(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyQueryPool_Weak(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetQueryPoolResults_Weak=vk_common_GetQueryPoolResults_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetQueryPoolResults=vk_common_GetQueryPoolResults_Weak")
    VkResult (*vk_common_GetQueryPoolResults_Null)(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) = 0;
    VkResult vk_common_GetQueryPoolResults_Weak(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetQueryPool_Weak=vk_common_ResetQueryPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetQueryPool=vk_common_ResetQueryPool_Weak")
    void (*vk_common_ResetQueryPool_Null)(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) = 0;
    void vk_common_ResetQueryPool_Weak(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetQueryPoolEXT_Weak=vk_common_ResetQueryPoolEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetQueryPoolEXT=vk_common_ResetQueryPoolEXT_Weak")
    void (*vk_common_ResetQueryPoolEXT_Null)(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) = 0;
    void vk_common_ResetQueryPoolEXT_Weak(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_ResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateBuffer_Weak=vk_common_CreateBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateBuffer=vk_common_CreateBuffer_Weak")
    VkResult (*vk_common_CreateBuffer_Null)(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) = 0;
    VkResult vk_common_CreateBuffer_Weak(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyBuffer_Weak=vk_common_DestroyBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyBuffer=vk_common_DestroyBuffer_Weak")
    void (*vk_common_DestroyBuffer_Null)(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyBuffer_Weak(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateBufferView_Weak=vk_common_CreateBufferView_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateBufferView=vk_common_CreateBufferView_Weak")
    VkResult (*vk_common_CreateBufferView_Null)(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) = 0;
    VkResult vk_common_CreateBufferView_Weak(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyBufferView_Weak=vk_common_DestroyBufferView_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyBufferView=vk_common_DestroyBufferView_Weak")
    void (*vk_common_DestroyBufferView_Null)(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyBufferView_Weak(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateImage_Weak=vk_common_CreateImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateImage=vk_common_CreateImage_Weak")
    VkResult (*vk_common_CreateImage_Null)(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) = 0;
    VkResult vk_common_CreateImage_Weak(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyImage_Weak=vk_common_DestroyImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyImage=vk_common_DestroyImage_Weak")
    void (*vk_common_DestroyImage_Null)(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyImage_Weak(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageSubresourceLayout_Weak=vk_common_GetImageSubresourceLayout_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageSubresourceLayout=vk_common_GetImageSubresourceLayout_Weak")
    void (*vk_common_GetImageSubresourceLayout_Null)(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) = 0;
    void vk_common_GetImageSubresourceLayout_Weak(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateImageView_Weak=vk_common_CreateImageView_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateImageView=vk_common_CreateImageView_Weak")
    VkResult (*vk_common_CreateImageView_Null)(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) = 0;
    VkResult vk_common_CreateImageView_Weak(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyImageView_Weak=vk_common_DestroyImageView_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyImageView=vk_common_DestroyImageView_Weak")
    void (*vk_common_DestroyImageView_Null)(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyImageView_Weak(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateShaderModule_Weak=vk_common_CreateShaderModule_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateShaderModule=vk_common_CreateShaderModule_Weak")
    VkResult (*vk_common_CreateShaderModule_Null)(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) = 0;
    VkResult vk_common_CreateShaderModule_Weak(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyShaderModule_Weak=vk_common_DestroyShaderModule_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyShaderModule=vk_common_DestroyShaderModule_Weak")
    void (*vk_common_DestroyShaderModule_Null)(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyShaderModule_Weak(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreatePipelineCache_Weak=vk_common_CreatePipelineCache_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreatePipelineCache=vk_common_CreatePipelineCache_Weak")
    VkResult (*vk_common_CreatePipelineCache_Null)(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) = 0;
    VkResult vk_common_CreatePipelineCache_Weak(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyPipelineCache_Weak=vk_common_DestroyPipelineCache_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyPipelineCache=vk_common_DestroyPipelineCache_Weak")
    void (*vk_common_DestroyPipelineCache_Null)(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyPipelineCache_Weak(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineCacheData_Weak=vk_common_GetPipelineCacheData_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineCacheData=vk_common_GetPipelineCacheData_Weak")
    VkResult (*vk_common_GetPipelineCacheData_Null)(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) = 0;
    VkResult vk_common_GetPipelineCacheData_Weak(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_MergePipelineCaches_Weak=vk_common_MergePipelineCaches_Null")
    #pragma comment(linker, "/alternatename:vk_common_MergePipelineCaches=vk_common_MergePipelineCaches_Weak")
    VkResult (*vk_common_MergePipelineCaches_Null)(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) = 0;
    VkResult vk_common_MergePipelineCaches_Weak(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_MergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateGraphicsPipelines_Weak=vk_common_CreateGraphicsPipelines_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateGraphicsPipelines=vk_common_CreateGraphicsPipelines_Weak")
    VkResult (*vk_common_CreateGraphicsPipelines_Null)(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) = 0;
    VkResult vk_common_CreateGraphicsPipelines_Weak(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateComputePipelines_Weak=vk_common_CreateComputePipelines_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateComputePipelines=vk_common_CreateComputePipelines_Weak")
    VkResult (*vk_common_CreateComputePipelines_Null)(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) = 0;
    VkResult vk_common_CreateComputePipelines_Weak(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyPipeline_Weak=vk_common_DestroyPipeline_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyPipeline=vk_common_DestroyPipeline_Weak")
    void (*vk_common_DestroyPipeline_Null)(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyPipeline_Weak(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreatePipelineLayout_Weak=vk_common_CreatePipelineLayout_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreatePipelineLayout=vk_common_CreatePipelineLayout_Weak")
    VkResult (*vk_common_CreatePipelineLayout_Null)(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) = 0;
    VkResult vk_common_CreatePipelineLayout_Weak(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyPipelineLayout_Weak=vk_common_DestroyPipelineLayout_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyPipelineLayout=vk_common_DestroyPipelineLayout_Weak")
    void (*vk_common_DestroyPipelineLayout_Null)(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyPipelineLayout_Weak(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateSampler_Weak=vk_common_CreateSampler_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateSampler=vk_common_CreateSampler_Weak")
    VkResult (*vk_common_CreateSampler_Null)(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) = 0;
    VkResult vk_common_CreateSampler_Weak(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroySampler_Weak=vk_common_DestroySampler_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroySampler=vk_common_DestroySampler_Weak")
    void (*vk_common_DestroySampler_Null)(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroySampler_Weak(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorSetLayout_Weak=vk_common_CreateDescriptorSetLayout_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorSetLayout=vk_common_CreateDescriptorSetLayout_Weak")
    VkResult (*vk_common_CreateDescriptorSetLayout_Null)(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) = 0;
    VkResult vk_common_CreateDescriptorSetLayout_Weak(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorSetLayout_Weak=vk_common_DestroyDescriptorSetLayout_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorSetLayout=vk_common_DestroyDescriptorSetLayout_Weak")
    void (*vk_common_DestroyDescriptorSetLayout_Null)(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDescriptorSetLayout_Weak(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorPool_Weak=vk_common_CreateDescriptorPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorPool=vk_common_CreateDescriptorPool_Weak")
    VkResult (*vk_common_CreateDescriptorPool_Null)(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) = 0;
    VkResult vk_common_CreateDescriptorPool_Weak(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorPool_Weak=vk_common_DestroyDescriptorPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorPool=vk_common_DestroyDescriptorPool_Weak")
    void (*vk_common_DestroyDescriptorPool_Null)(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDescriptorPool_Weak(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetDescriptorPool_Weak=vk_common_ResetDescriptorPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetDescriptorPool=vk_common_ResetDescriptorPool_Weak")
    VkResult (*vk_common_ResetDescriptorPool_Null)(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) = 0;
    VkResult vk_common_ResetDescriptorPool_Weak(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AllocateDescriptorSets_Weak=vk_common_AllocateDescriptorSets_Null")
    #pragma comment(linker, "/alternatename:vk_common_AllocateDescriptorSets=vk_common_AllocateDescriptorSets_Weak")
    VkResult (*vk_common_AllocateDescriptorSets_Null)(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) = 0;
    VkResult vk_common_AllocateDescriptorSets_Weak(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_FreeDescriptorSets_Weak=vk_common_FreeDescriptorSets_Null")
    #pragma comment(linker, "/alternatename:vk_common_FreeDescriptorSets=vk_common_FreeDescriptorSets_Weak")
    VkResult (*vk_common_FreeDescriptorSets_Null)(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) = 0;
    VkResult vk_common_FreeDescriptorSets_Weak(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_UpdateDescriptorSets_Weak=vk_common_UpdateDescriptorSets_Null")
    #pragma comment(linker, "/alternatename:vk_common_UpdateDescriptorSets=vk_common_UpdateDescriptorSets_Weak")
    void (*vk_common_UpdateDescriptorSets_Null)(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) = 0;
    void vk_common_UpdateDescriptorSets_Weak(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateFramebuffer_Weak=vk_common_CreateFramebuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateFramebuffer=vk_common_CreateFramebuffer_Weak")
    VkResult (*vk_common_CreateFramebuffer_Null)(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) = 0;
    VkResult vk_common_CreateFramebuffer_Weak(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyFramebuffer_Weak=vk_common_DestroyFramebuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyFramebuffer=vk_common_DestroyFramebuffer_Weak")
    void (*vk_common_DestroyFramebuffer_Null)(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyFramebuffer_Weak(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateRenderPass_Weak=vk_common_CreateRenderPass_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateRenderPass=vk_common_CreateRenderPass_Weak")
    VkResult (*vk_common_CreateRenderPass_Null)(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) = 0;
    VkResult vk_common_CreateRenderPass_Weak(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyRenderPass_Weak=vk_common_DestroyRenderPass_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyRenderPass=vk_common_DestroyRenderPass_Weak")
    void (*vk_common_DestroyRenderPass_Null)(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyRenderPass_Weak(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRenderAreaGranularity_Weak=vk_common_GetRenderAreaGranularity_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRenderAreaGranularity=vk_common_GetRenderAreaGranularity_Weak")
    void (*vk_common_GetRenderAreaGranularity_Null)(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) = 0;
    void vk_common_GetRenderAreaGranularity_Weak(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateCommandPool_Weak=vk_common_CreateCommandPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateCommandPool=vk_common_CreateCommandPool_Weak")
    VkResult (*vk_common_CreateCommandPool_Null)(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) = 0;
    VkResult vk_common_CreateCommandPool_Weak(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyCommandPool_Weak=vk_common_DestroyCommandPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyCommandPool=vk_common_DestroyCommandPool_Weak")
    void (*vk_common_DestroyCommandPool_Null)(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyCommandPool_Weak(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetCommandPool_Weak=vk_common_ResetCommandPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetCommandPool=vk_common_ResetCommandPool_Weak")
    VkResult (*vk_common_ResetCommandPool_Null)(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) = 0;
    VkResult vk_common_ResetCommandPool_Weak(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AllocateCommandBuffers_Weak=vk_common_AllocateCommandBuffers_Null")
    #pragma comment(linker, "/alternatename:vk_common_AllocateCommandBuffers=vk_common_AllocateCommandBuffers_Weak")
    VkResult (*vk_common_AllocateCommandBuffers_Null)(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) = 0;
    VkResult vk_common_AllocateCommandBuffers_Weak(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_FreeCommandBuffers_Weak=vk_common_FreeCommandBuffers_Null")
    #pragma comment(linker, "/alternatename:vk_common_FreeCommandBuffers=vk_common_FreeCommandBuffers_Weak")
    void (*vk_common_FreeCommandBuffers_Null)(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) = 0;
    void vk_common_FreeCommandBuffers_Weak(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BeginCommandBuffer_Weak=vk_common_BeginCommandBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_BeginCommandBuffer=vk_common_BeginCommandBuffer_Weak")
    VkResult (*vk_common_BeginCommandBuffer_Null)(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) = 0;
    VkResult vk_common_BeginCommandBuffer_Weak(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_EndCommandBuffer_Weak=vk_common_EndCommandBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_EndCommandBuffer=vk_common_EndCommandBuffer_Weak")
    VkResult (*vk_common_EndCommandBuffer_Null)(VkCommandBuffer commandBuffer) = 0;
    VkResult vk_common_EndCommandBuffer_Weak(VkCommandBuffer commandBuffer);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_EndCommandBuffer(VkCommandBuffer commandBuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ResetCommandBuffer_Weak=vk_common_ResetCommandBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_ResetCommandBuffer=vk_common_ResetCommandBuffer_Weak")
    VkResult (*vk_common_ResetCommandBuffer_Null)(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) = 0;
    VkResult vk_common_ResetCommandBuffer_Weak(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindPipeline_Weak=vk_common_CmdBindPipeline_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindPipeline=vk_common_CmdBindPipeline_Weak")
    void (*vk_common_CmdBindPipeline_Null)(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) = 0;
    void vk_common_CmdBindPipeline_Weak(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewport_Weak=vk_common_CmdSetViewport_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewport=vk_common_CmdSetViewport_Weak")
    void (*vk_common_CmdSetViewport_Null)(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) = 0;
    void vk_common_CmdSetViewport_Weak(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetScissor_Weak=vk_common_CmdSetScissor_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetScissor=vk_common_CmdSetScissor_Weak")
    void (*vk_common_CmdSetScissor_Null)(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) = 0;
    void vk_common_CmdSetScissor_Weak(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetLineWidth_Weak=vk_common_CmdSetLineWidth_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetLineWidth=vk_common_CmdSetLineWidth_Weak")
    void (*vk_common_CmdSetLineWidth_Null)(VkCommandBuffer commandBuffer, float lineWidth) = 0;
    void vk_common_CmdSetLineWidth_Weak(VkCommandBuffer commandBuffer, float lineWidth);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthBias_Weak=vk_common_CmdSetDepthBias_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthBias=vk_common_CmdSetDepthBias_Weak")
    void (*vk_common_CmdSetDepthBias_Null)(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) = 0;
    void vk_common_CmdSetDepthBias_Weak(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetBlendConstants_Weak=vk_common_CmdSetBlendConstants_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetBlendConstants=vk_common_CmdSetBlendConstants_Weak")
    void (*vk_common_CmdSetBlendConstants_Null)(VkCommandBuffer commandBuffer, const float blendConstants[4]) = 0;
    void vk_common_CmdSetBlendConstants_Weak(VkCommandBuffer commandBuffer, const float blendConstants[4]);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthBounds_Weak=vk_common_CmdSetDepthBounds_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthBounds=vk_common_CmdSetDepthBounds_Weak")
    void (*vk_common_CmdSetDepthBounds_Null)(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) = 0;
    void vk_common_CmdSetDepthBounds_Weak(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilCompareMask_Weak=vk_common_CmdSetStencilCompareMask_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilCompareMask=vk_common_CmdSetStencilCompareMask_Weak")
    void (*vk_common_CmdSetStencilCompareMask_Null)(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) = 0;
    void vk_common_CmdSetStencilCompareMask_Weak(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilWriteMask_Weak=vk_common_CmdSetStencilWriteMask_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilWriteMask=vk_common_CmdSetStencilWriteMask_Weak")
    void (*vk_common_CmdSetStencilWriteMask_Null)(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) = 0;
    void vk_common_CmdSetStencilWriteMask_Weak(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilReference_Weak=vk_common_CmdSetStencilReference_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilReference=vk_common_CmdSetStencilReference_Weak")
    void (*vk_common_CmdSetStencilReference_Null)(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) = 0;
    void vk_common_CmdSetStencilReference_Weak(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindDescriptorSets_Weak=vk_common_CmdBindDescriptorSets_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindDescriptorSets=vk_common_CmdBindDescriptorSets_Weak")
    void (*vk_common_CmdBindDescriptorSets_Null)(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) = 0;
    void vk_common_CmdBindDescriptorSets_Weak(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindIndexBuffer_Weak=vk_common_CmdBindIndexBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindIndexBuffer=vk_common_CmdBindIndexBuffer_Weak")
    void (*vk_common_CmdBindIndexBuffer_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) = 0;
    void vk_common_CmdBindIndexBuffer_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindVertexBuffers_Weak=vk_common_CmdBindVertexBuffers_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindVertexBuffers=vk_common_CmdBindVertexBuffers_Weak")
    void (*vk_common_CmdBindVertexBuffers_Null)(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) = 0;
    void vk_common_CmdBindVertexBuffers_Weak(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDraw_Weak=vk_common_CmdDraw_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDraw=vk_common_CmdDraw_Weak")
    void (*vk_common_CmdDraw_Null)(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) = 0;
    void vk_common_CmdDraw_Weak(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexed_Weak=vk_common_CmdDrawIndexed_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexed=vk_common_CmdDrawIndexed_Weak")
    void (*vk_common_CmdDrawIndexed_Null)(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) = 0;
    void vk_common_CmdDrawIndexed_Weak(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirect_Weak=vk_common_CmdDrawIndirect_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirect=vk_common_CmdDrawIndirect_Weak")
    void (*vk_common_CmdDrawIndirect_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndirect_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirect_Weak=vk_common_CmdDrawIndexedIndirect_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirect=vk_common_CmdDrawIndexedIndirect_Weak")
    void (*vk_common_CmdDrawIndexedIndirect_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndexedIndirect_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatch_Weak=vk_common_CmdDispatch_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatch=vk_common_CmdDispatch_Weak")
    void (*vk_common_CmdDispatch_Null)(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) = 0;
    void vk_common_CmdDispatch_Weak(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatchIndirect_Weak=vk_common_CmdDispatchIndirect_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatchIndirect=vk_common_CmdDispatchIndirect_Weak")
    void (*vk_common_CmdDispatchIndirect_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) = 0;
    void vk_common_CmdDispatchIndirect_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBuffer_Weak=vk_common_CmdCopyBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBuffer=vk_common_CmdCopyBuffer_Weak")
    void (*vk_common_CmdCopyBuffer_Null)(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) = 0;
    void vk_common_CmdCopyBuffer_Weak(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImage_Weak=vk_common_CmdCopyImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImage=vk_common_CmdCopyImage_Weak")
    void (*vk_common_CmdCopyImage_Null)(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) = 0;
    void vk_common_CmdCopyImage_Weak(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBlitImage_Weak=vk_common_CmdBlitImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBlitImage=vk_common_CmdBlitImage_Weak")
    void (*vk_common_CmdBlitImage_Null)(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) = 0;
    void vk_common_CmdBlitImage_Weak(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBufferToImage_Weak=vk_common_CmdCopyBufferToImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBufferToImage=vk_common_CmdCopyBufferToImage_Weak")
    void (*vk_common_CmdCopyBufferToImage_Null)(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) = 0;
    void vk_common_CmdCopyBufferToImage_Weak(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImageToBuffer_Weak=vk_common_CmdCopyImageToBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImageToBuffer=vk_common_CmdCopyImageToBuffer_Weak")
    void (*vk_common_CmdCopyImageToBuffer_Null)(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) = 0;
    void vk_common_CmdCopyImageToBuffer_Weak(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdUpdateBuffer_Weak=vk_common_CmdUpdateBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdUpdateBuffer=vk_common_CmdUpdateBuffer_Weak")
    void (*vk_common_CmdUpdateBuffer_Null)(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) = 0;
    void vk_common_CmdUpdateBuffer_Weak(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdFillBuffer_Weak=vk_common_CmdFillBuffer_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdFillBuffer=vk_common_CmdFillBuffer_Weak")
    void (*vk_common_CmdFillBuffer_Null)(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) = 0;
    void vk_common_CmdFillBuffer_Weak(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdClearColorImage_Weak=vk_common_CmdClearColorImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdClearColorImage=vk_common_CmdClearColorImage_Weak")
    void (*vk_common_CmdClearColorImage_Null)(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) = 0;
    void vk_common_CmdClearColorImage_Weak(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdClearDepthStencilImage_Weak=vk_common_CmdClearDepthStencilImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdClearDepthStencilImage=vk_common_CmdClearDepthStencilImage_Weak")
    void (*vk_common_CmdClearDepthStencilImage_Null)(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) = 0;
    void vk_common_CmdClearDepthStencilImage_Weak(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdClearAttachments_Weak=vk_common_CmdClearAttachments_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdClearAttachments=vk_common_CmdClearAttachments_Weak")
    void (*vk_common_CmdClearAttachments_Null)(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) = 0;
    void vk_common_CmdClearAttachments_Weak(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdResolveImage_Weak=vk_common_CmdResolveImage_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdResolveImage=vk_common_CmdResolveImage_Weak")
    void (*vk_common_CmdResolveImage_Null)(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) = 0;
    void vk_common_CmdResolveImage_Weak(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetEvent_Weak=vk_common_CmdSetEvent_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetEvent=vk_common_CmdSetEvent_Weak")
    void (*vk_common_CmdSetEvent_Null)(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) = 0;
    void vk_common_CmdSetEvent_Weak(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdResetEvent_Weak=vk_common_CmdResetEvent_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdResetEvent=vk_common_CmdResetEvent_Weak")
    void (*vk_common_CmdResetEvent_Null)(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) = 0;
    void vk_common_CmdResetEvent_Weak(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdWaitEvents_Weak=vk_common_CmdWaitEvents_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdWaitEvents=vk_common_CmdWaitEvents_Weak")
    void (*vk_common_CmdWaitEvents_Null)(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) = 0;
    void vk_common_CmdWaitEvents_Weak(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdPipelineBarrier_Weak=vk_common_CmdPipelineBarrier_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdPipelineBarrier=vk_common_CmdPipelineBarrier_Weak")
    void (*vk_common_CmdPipelineBarrier_Null)(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) = 0;
    void vk_common_CmdPipelineBarrier_Weak(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginQuery_Weak=vk_common_CmdBeginQuery_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginQuery=vk_common_CmdBeginQuery_Weak")
    void (*vk_common_CmdBeginQuery_Null)(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) = 0;
    void vk_common_CmdBeginQuery_Weak(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndQuery_Weak=vk_common_CmdEndQuery_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndQuery=vk_common_CmdEndQuery_Weak")
    void (*vk_common_CmdEndQuery_Null)(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) = 0;
    void vk_common_CmdEndQuery_Weak(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginConditionalRenderingEXT_Weak=vk_common_CmdBeginConditionalRenderingEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginConditionalRenderingEXT=vk_common_CmdBeginConditionalRenderingEXT_Weak")
    void (*vk_common_CmdBeginConditionalRenderingEXT_Null)(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) = 0;
    void vk_common_CmdBeginConditionalRenderingEXT_Weak(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndConditionalRenderingEXT_Weak=vk_common_CmdEndConditionalRenderingEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndConditionalRenderingEXT=vk_common_CmdEndConditionalRenderingEXT_Weak")
    void (*vk_common_CmdEndConditionalRenderingEXT_Null)(VkCommandBuffer commandBuffer) = 0;
    void vk_common_CmdEndConditionalRenderingEXT_Weak(VkCommandBuffer commandBuffer);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdResetQueryPool_Weak=vk_common_CmdResetQueryPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdResetQueryPool=vk_common_CmdResetQueryPool_Weak")
    void (*vk_common_CmdResetQueryPool_Null)(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) = 0;
    void vk_common_CmdResetQueryPool_Weak(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteTimestamp_Weak=vk_common_CmdWriteTimestamp_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteTimestamp=vk_common_CmdWriteTimestamp_Weak")
    void (*vk_common_CmdWriteTimestamp_Null)(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) = 0;
    void vk_common_CmdWriteTimestamp_Weak(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyQueryPoolResults_Weak=vk_common_CmdCopyQueryPoolResults_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyQueryPoolResults=vk_common_CmdCopyQueryPoolResults_Weak")
    void (*vk_common_CmdCopyQueryPoolResults_Null)(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) = 0;
    void vk_common_CmdCopyQueryPoolResults_Weak(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdPushConstants_Weak=vk_common_CmdPushConstants_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdPushConstants=vk_common_CmdPushConstants_Weak")
    void (*vk_common_CmdPushConstants_Null)(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) = 0;
    void vk_common_CmdPushConstants_Weak(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginRenderPass_Weak=vk_common_CmdBeginRenderPass_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginRenderPass=vk_common_CmdBeginRenderPass_Weak")
    void (*vk_common_CmdBeginRenderPass_Null)(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) = 0;
    void vk_common_CmdBeginRenderPass_Weak(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdNextSubpass_Weak=vk_common_CmdNextSubpass_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdNextSubpass=vk_common_CmdNextSubpass_Weak")
    void (*vk_common_CmdNextSubpass_Null)(VkCommandBuffer commandBuffer, VkSubpassContents contents) = 0;
    void vk_common_CmdNextSubpass_Weak(VkCommandBuffer commandBuffer, VkSubpassContents contents);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndRenderPass_Weak=vk_common_CmdEndRenderPass_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndRenderPass=vk_common_CmdEndRenderPass_Weak")
    void (*vk_common_CmdEndRenderPass_Null)(VkCommandBuffer commandBuffer) = 0;
    void vk_common_CmdEndRenderPass_Weak(VkCommandBuffer commandBuffer);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndRenderPass(VkCommandBuffer commandBuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdExecuteCommands_Weak=vk_common_CmdExecuteCommands_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdExecuteCommands=vk_common_CmdExecuteCommands_Weak")
    void (*vk_common_CmdExecuteCommands_Null)(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) = 0;
    void vk_common_CmdExecuteCommands_Weak(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateSharedSwapchainsKHR_Weak=vk_common_CreateSharedSwapchainsKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateSharedSwapchainsKHR=vk_common_CreateSharedSwapchainsKHR_Weak")
    VkResult (*vk_common_CreateSharedSwapchainsKHR_Null)(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) = 0;
    VkResult vk_common_CreateSharedSwapchainsKHR_Weak(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateSwapchainKHR_Weak=vk_common_CreateSwapchainKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateSwapchainKHR=vk_common_CreateSwapchainKHR_Weak")
    VkResult (*vk_common_CreateSwapchainKHR_Null)(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) = 0;
    VkResult vk_common_CreateSwapchainKHR_Weak(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroySwapchainKHR_Weak=vk_common_DestroySwapchainKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroySwapchainKHR=vk_common_DestroySwapchainKHR_Weak")
    void (*vk_common_DestroySwapchainKHR_Null)(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroySwapchainKHR_Weak(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainImagesKHR_Weak=vk_common_GetSwapchainImagesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainImagesKHR=vk_common_GetSwapchainImagesKHR_Weak")
    VkResult (*vk_common_GetSwapchainImagesKHR_Null)(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) = 0;
    VkResult vk_common_GetSwapchainImagesKHR_Weak(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireNextImageKHR_Weak=vk_common_AcquireNextImageKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireNextImageKHR=vk_common_AcquireNextImageKHR_Weak")
    VkResult (*vk_common_AcquireNextImageKHR_Null)(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) = 0;
    VkResult vk_common_AcquireNextImageKHR_Weak(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueuePresentKHR_Weak=vk_common_QueuePresentKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueuePresentKHR=vk_common_QueuePresentKHR_Weak")
    VkResult (*vk_common_QueuePresentKHR_Null)(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) = 0;
    VkResult vk_common_QueuePresentKHR_Weak(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DebugMarkerSetObjectNameEXT_Weak=vk_common_DebugMarkerSetObjectNameEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DebugMarkerSetObjectNameEXT=vk_common_DebugMarkerSetObjectNameEXT_Weak")
    VkResult (*vk_common_DebugMarkerSetObjectNameEXT_Null)(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) = 0;
    VkResult vk_common_DebugMarkerSetObjectNameEXT_Weak(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_DebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DebugMarkerSetObjectTagEXT_Weak=vk_common_DebugMarkerSetObjectTagEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DebugMarkerSetObjectTagEXT=vk_common_DebugMarkerSetObjectTagEXT_Weak")
    VkResult (*vk_common_DebugMarkerSetObjectTagEXT_Null)(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) = 0;
    VkResult vk_common_DebugMarkerSetObjectTagEXT_Weak(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_DebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDebugMarkerBeginEXT_Weak=vk_common_CmdDebugMarkerBeginEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDebugMarkerBeginEXT=vk_common_CmdDebugMarkerBeginEXT_Weak")
    void (*vk_common_CmdDebugMarkerBeginEXT_Null)(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) = 0;
    void vk_common_CmdDebugMarkerBeginEXT_Weak(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDebugMarkerEndEXT_Weak=vk_common_CmdDebugMarkerEndEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDebugMarkerEndEXT=vk_common_CmdDebugMarkerEndEXT_Weak")
    void (*vk_common_CmdDebugMarkerEndEXT_Null)(VkCommandBuffer commandBuffer) = 0;
    void vk_common_CmdDebugMarkerEndEXT_Weak(VkCommandBuffer commandBuffer);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDebugMarkerInsertEXT_Weak=vk_common_CmdDebugMarkerInsertEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDebugMarkerInsertEXT=vk_common_CmdDebugMarkerInsertEXT_Weak")
    void (*vk_common_CmdDebugMarkerInsertEXT_Null)(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) = 0;
    void vk_common_CmdDebugMarkerInsertEXT_Weak(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryWin32HandleNV_Weak=vk_common_GetMemoryWin32HandleNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryWin32HandleNV=vk_common_GetMemoryWin32HandleNV_Weak")
    VkResult (*vk_common_GetMemoryWin32HandleNV_Null)(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) = 0;
    VkResult vk_common_GetMemoryWin32HandleNV_Weak(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdExecuteGeneratedCommandsNV_Weak=vk_common_CmdExecuteGeneratedCommandsNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdExecuteGeneratedCommandsNV=vk_common_CmdExecuteGeneratedCommandsNV_Weak")
    void (*vk_common_CmdExecuteGeneratedCommandsNV_Null)(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) = 0;
    void vk_common_CmdExecuteGeneratedCommandsNV_Weak(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdPreprocessGeneratedCommandsNV_Weak=vk_common_CmdPreprocessGeneratedCommandsNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdPreprocessGeneratedCommandsNV=vk_common_CmdPreprocessGeneratedCommandsNV_Weak")
    void (*vk_common_CmdPreprocessGeneratedCommandsNV_Null)(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) = 0;
    void vk_common_CmdPreprocessGeneratedCommandsNV_Weak(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindPipelineShaderGroupNV_Weak=vk_common_CmdBindPipelineShaderGroupNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindPipelineShaderGroupNV=vk_common_CmdBindPipelineShaderGroupNV_Weak")
    void (*vk_common_CmdBindPipelineShaderGroupNV_Null)(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) = 0;
    void vk_common_CmdBindPipelineShaderGroupNV_Weak(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetGeneratedCommandsMemoryRequirementsNV_Weak=vk_common_GetGeneratedCommandsMemoryRequirementsNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetGeneratedCommandsMemoryRequirementsNV=vk_common_GetGeneratedCommandsMemoryRequirementsNV_Weak")
    void (*vk_common_GetGeneratedCommandsMemoryRequirementsNV_Null)(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) = 0;
    void vk_common_GetGeneratedCommandsMemoryRequirementsNV_Weak(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateIndirectCommandsLayoutNV_Weak=vk_common_CreateIndirectCommandsLayoutNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateIndirectCommandsLayoutNV=vk_common_CreateIndirectCommandsLayoutNV_Weak")
    VkResult (*vk_common_CreateIndirectCommandsLayoutNV_Null)(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) = 0;
    VkResult vk_common_CreateIndirectCommandsLayoutNV_Weak(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyIndirectCommandsLayoutNV_Weak=vk_common_DestroyIndirectCommandsLayoutNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyIndirectCommandsLayoutNV=vk_common_DestroyIndirectCommandsLayoutNV_Weak")
    void (*vk_common_DestroyIndirectCommandsLayoutNV_Null)(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyIndirectCommandsLayoutNV_Weak(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdPushDescriptorSetKHR_Weak=vk_common_CmdPushDescriptorSetKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdPushDescriptorSetKHR=vk_common_CmdPushDescriptorSetKHR_Weak")
    void (*vk_common_CmdPushDescriptorSetKHR_Null)(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) = 0;
    void vk_common_CmdPushDescriptorSetKHR_Weak(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_TrimCommandPool_Weak=vk_common_TrimCommandPool_Null")
    #pragma comment(linker, "/alternatename:vk_common_TrimCommandPool=vk_common_TrimCommandPool_Weak")
    void (*vk_common_TrimCommandPool_Null)(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) = 0;
    void vk_common_TrimCommandPool_Weak(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_TrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_TrimCommandPoolKHR_Weak=vk_common_TrimCommandPoolKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_TrimCommandPoolKHR=vk_common_TrimCommandPoolKHR_Weak")
    void (*vk_common_TrimCommandPoolKHR_Null)(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) = 0;
    void vk_common_TrimCommandPoolKHR_Weak(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_TrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryWin32HandleKHR_Weak=vk_common_GetMemoryWin32HandleKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryWin32HandleKHR=vk_common_GetMemoryWin32HandleKHR_Weak")
    VkResult (*vk_common_GetMemoryWin32HandleKHR_Null)(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) = 0;
    VkResult vk_common_GetMemoryWin32HandleKHR_Weak(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryWin32HandlePropertiesKHR_Weak=vk_common_GetMemoryWin32HandlePropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryWin32HandlePropertiesKHR=vk_common_GetMemoryWin32HandlePropertiesKHR_Weak")
    VkResult (*vk_common_GetMemoryWin32HandlePropertiesKHR_Null)(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) = 0;
    VkResult vk_common_GetMemoryWin32HandlePropertiesKHR_Weak(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryFdKHR_Weak=vk_common_GetMemoryFdKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryFdKHR=vk_common_GetMemoryFdKHR_Weak")
    VkResult (*vk_common_GetMemoryFdKHR_Null)(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) = 0;
    VkResult vk_common_GetMemoryFdKHR_Weak(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryFdPropertiesKHR_Weak=vk_common_GetMemoryFdPropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryFdPropertiesKHR=vk_common_GetMemoryFdPropertiesKHR_Weak")
    VkResult (*vk_common_GetMemoryFdPropertiesKHR_Null)(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) = 0;
    VkResult vk_common_GetMemoryFdPropertiesKHR_Weak(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreWin32HandleKHR_Weak=vk_common_GetSemaphoreWin32HandleKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreWin32HandleKHR=vk_common_GetSemaphoreWin32HandleKHR_Weak")
    VkResult (*vk_common_GetSemaphoreWin32HandleKHR_Null)(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) = 0;
    VkResult vk_common_GetSemaphoreWin32HandleKHR_Weak(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ImportSemaphoreWin32HandleKHR_Weak=vk_common_ImportSemaphoreWin32HandleKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_ImportSemaphoreWin32HandleKHR=vk_common_ImportSemaphoreWin32HandleKHR_Weak")
    VkResult (*vk_common_ImportSemaphoreWin32HandleKHR_Null)(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) = 0;
    VkResult vk_common_ImportSemaphoreWin32HandleKHR_Weak(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreFdKHR_Weak=vk_common_GetSemaphoreFdKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreFdKHR=vk_common_GetSemaphoreFdKHR_Weak")
    VkResult (*vk_common_GetSemaphoreFdKHR_Null)(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) = 0;
    VkResult vk_common_GetSemaphoreFdKHR_Weak(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ImportSemaphoreFdKHR_Weak=vk_common_ImportSemaphoreFdKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_ImportSemaphoreFdKHR=vk_common_ImportSemaphoreFdKHR_Weak")
    VkResult (*vk_common_ImportSemaphoreFdKHR_Null)(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) = 0;
    VkResult vk_common_ImportSemaphoreFdKHR_Weak(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetFenceWin32HandleKHR_Weak=vk_common_GetFenceWin32HandleKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetFenceWin32HandleKHR=vk_common_GetFenceWin32HandleKHR_Weak")
    VkResult (*vk_common_GetFenceWin32HandleKHR_Null)(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) = 0;
    VkResult vk_common_GetFenceWin32HandleKHR_Weak(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ImportFenceWin32HandleKHR_Weak=vk_common_ImportFenceWin32HandleKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_ImportFenceWin32HandleKHR=vk_common_ImportFenceWin32HandleKHR_Weak")
    VkResult (*vk_common_ImportFenceWin32HandleKHR_Null)(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) = 0;
    VkResult vk_common_ImportFenceWin32HandleKHR_Weak(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetFenceFdKHR_Weak=vk_common_GetFenceFdKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetFenceFdKHR=vk_common_GetFenceFdKHR_Weak")
    VkResult (*vk_common_GetFenceFdKHR_Null)(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) = 0;
    VkResult vk_common_GetFenceFdKHR_Weak(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ImportFenceFdKHR_Weak=vk_common_ImportFenceFdKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_ImportFenceFdKHR=vk_common_ImportFenceFdKHR_Weak")
    VkResult (*vk_common_ImportFenceFdKHR_Null)(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) = 0;
    VkResult vk_common_ImportFenceFdKHR_Weak(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DisplayPowerControlEXT_Weak=vk_common_DisplayPowerControlEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DisplayPowerControlEXT=vk_common_DisplayPowerControlEXT_Weak")
    VkResult (*vk_common_DisplayPowerControlEXT_Null)(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) = 0;
    VkResult vk_common_DisplayPowerControlEXT_Weak(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_RegisterDeviceEventEXT_Weak=vk_common_RegisterDeviceEventEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_RegisterDeviceEventEXT=vk_common_RegisterDeviceEventEXT_Weak")
    VkResult (*vk_common_RegisterDeviceEventEXT_Null)(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) = 0;
    VkResult vk_common_RegisterDeviceEventEXT_Weak(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_RegisterDisplayEventEXT_Weak=vk_common_RegisterDisplayEventEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_RegisterDisplayEventEXT=vk_common_RegisterDisplayEventEXT_Weak")
    VkResult (*vk_common_RegisterDisplayEventEXT_Null)(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) = 0;
    VkResult vk_common_RegisterDisplayEventEXT_Weak(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainCounterEXT_Weak=vk_common_GetSwapchainCounterEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainCounterEXT=vk_common_GetSwapchainCounterEXT_Weak")
    VkResult (*vk_common_GetSwapchainCounterEXT_Null)(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) = 0;
    VkResult vk_common_GetSwapchainCounterEXT_Weak(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupPeerMemoryFeatures_Weak=vk_common_GetDeviceGroupPeerMemoryFeatures_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupPeerMemoryFeatures=vk_common_GetDeviceGroupPeerMemoryFeatures_Weak")
    void (*vk_common_GetDeviceGroupPeerMemoryFeatures_Null)(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) = 0;
    void vk_common_GetDeviceGroupPeerMemoryFeatures_Weak(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupPeerMemoryFeaturesKHR_Weak=vk_common_GetDeviceGroupPeerMemoryFeaturesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupPeerMemoryFeaturesKHR=vk_common_GetDeviceGroupPeerMemoryFeaturesKHR_Weak")
    void (*vk_common_GetDeviceGroupPeerMemoryFeaturesKHR_Null)(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) = 0;
    void vk_common_GetDeviceGroupPeerMemoryFeaturesKHR_Weak(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindBufferMemory2_Weak=vk_common_BindBufferMemory2_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindBufferMemory2=vk_common_BindBufferMemory2_Weak")
    VkResult (*vk_common_BindBufferMemory2_Null)(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) = 0;
    VkResult vk_common_BindBufferMemory2_Weak(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindBufferMemory2KHR_Weak=vk_common_BindBufferMemory2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindBufferMemory2KHR=vk_common_BindBufferMemory2KHR_Weak")
    VkResult (*vk_common_BindBufferMemory2KHR_Null)(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) = 0;
    VkResult vk_common_BindBufferMemory2KHR_Weak(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindImageMemory2_Weak=vk_common_BindImageMemory2_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindImageMemory2=vk_common_BindImageMemory2_Weak")
    VkResult (*vk_common_BindImageMemory2_Null)(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) = 0;
    VkResult vk_common_BindImageMemory2_Weak(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindImageMemory2KHR_Weak=vk_common_BindImageMemory2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindImageMemory2KHR=vk_common_BindImageMemory2KHR_Weak")
    VkResult (*vk_common_BindImageMemory2KHR_Null)(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) = 0;
    VkResult vk_common_BindImageMemory2KHR_Weak(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDeviceMask_Weak=vk_common_CmdSetDeviceMask_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDeviceMask=vk_common_CmdSetDeviceMask_Weak")
    void (*vk_common_CmdSetDeviceMask_Null)(VkCommandBuffer commandBuffer, uint32_t deviceMask) = 0;
    void vk_common_CmdSetDeviceMask_Weak(VkCommandBuffer commandBuffer, uint32_t deviceMask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDeviceMaskKHR_Weak=vk_common_CmdSetDeviceMaskKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDeviceMaskKHR=vk_common_CmdSetDeviceMaskKHR_Weak")
    void (*vk_common_CmdSetDeviceMaskKHR_Null)(VkCommandBuffer commandBuffer, uint32_t deviceMask) = 0;
    void vk_common_CmdSetDeviceMaskKHR_Weak(VkCommandBuffer commandBuffer, uint32_t deviceMask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupPresentCapabilitiesKHR_Weak=vk_common_GetDeviceGroupPresentCapabilitiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupPresentCapabilitiesKHR=vk_common_GetDeviceGroupPresentCapabilitiesKHR_Weak")
    VkResult (*vk_common_GetDeviceGroupPresentCapabilitiesKHR_Null)(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) = 0;
    VkResult vk_common_GetDeviceGroupPresentCapabilitiesKHR_Weak(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupSurfacePresentModesKHR_Weak=vk_common_GetDeviceGroupSurfacePresentModesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupSurfacePresentModesKHR=vk_common_GetDeviceGroupSurfacePresentModesKHR_Weak")
    VkResult (*vk_common_GetDeviceGroupSurfacePresentModesKHR_Null)(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) = 0;
    VkResult vk_common_GetDeviceGroupSurfacePresentModesKHR_Weak(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireNextImage2KHR_Weak=vk_common_AcquireNextImage2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireNextImage2KHR=vk_common_AcquireNextImage2KHR_Weak")
    VkResult (*vk_common_AcquireNextImage2KHR_Null)(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) = 0;
    VkResult vk_common_AcquireNextImage2KHR_Weak(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatchBase_Weak=vk_common_CmdDispatchBase_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatchBase=vk_common_CmdDispatchBase_Weak")
    void (*vk_common_CmdDispatchBase_Null)(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) = 0;
    void vk_common_CmdDispatchBase_Weak(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatchBaseKHR_Weak=vk_common_CmdDispatchBaseKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDispatchBaseKHR=vk_common_CmdDispatchBaseKHR_Weak")
    void (*vk_common_CmdDispatchBaseKHR_Null)(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) = 0;
    void vk_common_CmdDispatchBaseKHR_Weak(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorUpdateTemplate_Weak=vk_common_CreateDescriptorUpdateTemplate_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorUpdateTemplate=vk_common_CreateDescriptorUpdateTemplate_Weak")
    VkResult (*vk_common_CreateDescriptorUpdateTemplate_Null)(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) = 0;
    VkResult vk_common_CreateDescriptorUpdateTemplate_Weak(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorUpdateTemplateKHR_Weak=vk_common_CreateDescriptorUpdateTemplateKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDescriptorUpdateTemplateKHR=vk_common_CreateDescriptorUpdateTemplateKHR_Weak")
    VkResult (*vk_common_CreateDescriptorUpdateTemplateKHR_Null)(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) = 0;
    VkResult vk_common_CreateDescriptorUpdateTemplateKHR_Weak(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorUpdateTemplate_Weak=vk_common_DestroyDescriptorUpdateTemplate_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorUpdateTemplate=vk_common_DestroyDescriptorUpdateTemplate_Weak")
    void (*vk_common_DestroyDescriptorUpdateTemplate_Null)(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDescriptorUpdateTemplate_Weak(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorUpdateTemplateKHR_Weak=vk_common_DestroyDescriptorUpdateTemplateKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDescriptorUpdateTemplateKHR=vk_common_DestroyDescriptorUpdateTemplateKHR_Weak")
    void (*vk_common_DestroyDescriptorUpdateTemplateKHR_Null)(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDescriptorUpdateTemplateKHR_Weak(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_UpdateDescriptorSetWithTemplate_Weak=vk_common_UpdateDescriptorSetWithTemplate_Null")
    #pragma comment(linker, "/alternatename:vk_common_UpdateDescriptorSetWithTemplate=vk_common_UpdateDescriptorSetWithTemplate_Weak")
    void (*vk_common_UpdateDescriptorSetWithTemplate_Null)(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) = 0;
    void vk_common_UpdateDescriptorSetWithTemplate_Weak(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_UpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_UpdateDescriptorSetWithTemplateKHR_Weak=vk_common_UpdateDescriptorSetWithTemplateKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_UpdateDescriptorSetWithTemplateKHR=vk_common_UpdateDescriptorSetWithTemplateKHR_Weak")
    void (*vk_common_UpdateDescriptorSetWithTemplateKHR_Null)(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) = 0;
    void vk_common_UpdateDescriptorSetWithTemplateKHR_Weak(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_UpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdPushDescriptorSetWithTemplateKHR_Weak=vk_common_CmdPushDescriptorSetWithTemplateKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdPushDescriptorSetWithTemplateKHR=vk_common_CmdPushDescriptorSetWithTemplateKHR_Weak")
    void (*vk_common_CmdPushDescriptorSetWithTemplateKHR_Null)(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) = 0;
    void vk_common_CmdPushDescriptorSetWithTemplateKHR_Weak(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SetHdrMetadataEXT_Weak=vk_common_SetHdrMetadataEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_SetHdrMetadataEXT=vk_common_SetHdrMetadataEXT_Weak")
    void (*vk_common_SetHdrMetadataEXT_Null)(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) = 0;
    void vk_common_SetHdrMetadataEXT_Weak(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainStatusKHR_Weak=vk_common_GetSwapchainStatusKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainStatusKHR=vk_common_GetSwapchainStatusKHR_Weak")
    VkResult (*vk_common_GetSwapchainStatusKHR_Null)(VkDevice device, VkSwapchainKHR swapchain) = 0;
    VkResult vk_common_GetSwapchainStatusKHR_Weak(VkDevice device, VkSwapchainKHR swapchain);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRefreshCycleDurationGOOGLE_Weak=vk_common_GetRefreshCycleDurationGOOGLE_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRefreshCycleDurationGOOGLE=vk_common_GetRefreshCycleDurationGOOGLE_Weak")
    VkResult (*vk_common_GetRefreshCycleDurationGOOGLE_Null)(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) = 0;
    VkResult vk_common_GetRefreshCycleDurationGOOGLE_Weak(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPastPresentationTimingGOOGLE_Weak=vk_common_GetPastPresentationTimingGOOGLE_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPastPresentationTimingGOOGLE=vk_common_GetPastPresentationTimingGOOGLE_Weak")
    VkResult (*vk_common_GetPastPresentationTimingGOOGLE_Null)(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) = 0;
    VkResult vk_common_GetPastPresentationTimingGOOGLE_Weak(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewportWScalingNV_Weak=vk_common_CmdSetViewportWScalingNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewportWScalingNV=vk_common_CmdSetViewportWScalingNV_Weak")
    void (*vk_common_CmdSetViewportWScalingNV_Null)(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) = 0;
    void vk_common_CmdSetViewportWScalingNV_Weak(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDiscardRectangleEXT_Weak=vk_common_CmdSetDiscardRectangleEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDiscardRectangleEXT=vk_common_CmdSetDiscardRectangleEXT_Weak")
    void (*vk_common_CmdSetDiscardRectangleEXT_Null)(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) = 0;
    void vk_common_CmdSetDiscardRectangleEXT_Weak(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetSampleLocationsEXT_Weak=vk_common_CmdSetSampleLocationsEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetSampleLocationsEXT=vk_common_CmdSetSampleLocationsEXT_Weak")
    void (*vk_common_CmdSetSampleLocationsEXT_Null)(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) = 0;
    void vk_common_CmdSetSampleLocationsEXT_Weak(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferMemoryRequirements2_Weak=vk_common_GetBufferMemoryRequirements2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferMemoryRequirements2=vk_common_GetBufferMemoryRequirements2_Weak")
    void (*vk_common_GetBufferMemoryRequirements2_Null)(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) = 0;
    void vk_common_GetBufferMemoryRequirements2_Weak(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferMemoryRequirements2KHR_Weak=vk_common_GetBufferMemoryRequirements2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferMemoryRequirements2KHR=vk_common_GetBufferMemoryRequirements2KHR_Weak")
    void (*vk_common_GetBufferMemoryRequirements2KHR_Null)(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) = 0;
    void vk_common_GetBufferMemoryRequirements2KHR_Weak(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageMemoryRequirements2_Weak=vk_common_GetImageMemoryRequirements2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageMemoryRequirements2=vk_common_GetImageMemoryRequirements2_Weak")
    void (*vk_common_GetImageMemoryRequirements2_Null)(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) = 0;
    void vk_common_GetImageMemoryRequirements2_Weak(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageMemoryRequirements2KHR_Weak=vk_common_GetImageMemoryRequirements2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageMemoryRequirements2KHR=vk_common_GetImageMemoryRequirements2KHR_Weak")
    void (*vk_common_GetImageMemoryRequirements2KHR_Null)(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) = 0;
    void vk_common_GetImageMemoryRequirements2KHR_Weak(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageSparseMemoryRequirements2_Weak=vk_common_GetImageSparseMemoryRequirements2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageSparseMemoryRequirements2=vk_common_GetImageSparseMemoryRequirements2_Weak")
    void (*vk_common_GetImageSparseMemoryRequirements2_Null)(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) = 0;
    void vk_common_GetImageSparseMemoryRequirements2_Weak(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageSparseMemoryRequirements2KHR_Weak=vk_common_GetImageSparseMemoryRequirements2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageSparseMemoryRequirements2KHR=vk_common_GetImageSparseMemoryRequirements2KHR_Weak")
    void (*vk_common_GetImageSparseMemoryRequirements2KHR_Null)(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) = 0;
    void vk_common_GetImageSparseMemoryRequirements2KHR_Weak(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateSamplerYcbcrConversion_Weak=vk_common_CreateSamplerYcbcrConversion_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateSamplerYcbcrConversion=vk_common_CreateSamplerYcbcrConversion_Weak")
    VkResult (*vk_common_CreateSamplerYcbcrConversion_Null)(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) = 0;
    VkResult vk_common_CreateSamplerYcbcrConversion_Weak(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateSamplerYcbcrConversionKHR_Weak=vk_common_CreateSamplerYcbcrConversionKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateSamplerYcbcrConversionKHR=vk_common_CreateSamplerYcbcrConversionKHR_Weak")
    VkResult (*vk_common_CreateSamplerYcbcrConversionKHR_Null)(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) = 0;
    VkResult vk_common_CreateSamplerYcbcrConversionKHR_Weak(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroySamplerYcbcrConversion_Weak=vk_common_DestroySamplerYcbcrConversion_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroySamplerYcbcrConversion=vk_common_DestroySamplerYcbcrConversion_Weak")
    void (*vk_common_DestroySamplerYcbcrConversion_Null)(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroySamplerYcbcrConversion_Weak(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroySamplerYcbcrConversionKHR_Weak=vk_common_DestroySamplerYcbcrConversionKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroySamplerYcbcrConversionKHR=vk_common_DestroySamplerYcbcrConversionKHR_Weak")
    void (*vk_common_DestroySamplerYcbcrConversionKHR_Null)(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroySamplerYcbcrConversionKHR_Weak(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceQueue2_Weak=vk_common_GetDeviceQueue2_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceQueue2=vk_common_GetDeviceQueue2_Weak")
    void (*vk_common_GetDeviceQueue2_Null)(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) = 0;
    void vk_common_GetDeviceQueue2_Weak(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateValidationCacheEXT_Weak=vk_common_CreateValidationCacheEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateValidationCacheEXT=vk_common_CreateValidationCacheEXT_Weak")
    VkResult (*vk_common_CreateValidationCacheEXT_Null)(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) = 0;
    VkResult vk_common_CreateValidationCacheEXT_Weak(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyValidationCacheEXT_Weak=vk_common_DestroyValidationCacheEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyValidationCacheEXT=vk_common_DestroyValidationCacheEXT_Weak")
    void (*vk_common_DestroyValidationCacheEXT_Null)(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyValidationCacheEXT_Weak(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetValidationCacheDataEXT_Weak=vk_common_GetValidationCacheDataEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetValidationCacheDataEXT=vk_common_GetValidationCacheDataEXT_Weak")
    VkResult (*vk_common_GetValidationCacheDataEXT_Null)(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) = 0;
    VkResult vk_common_GetValidationCacheDataEXT_Weak(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_MergeValidationCachesEXT_Weak=vk_common_MergeValidationCachesEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_MergeValidationCachesEXT=vk_common_MergeValidationCachesEXT_Weak")
    VkResult (*vk_common_MergeValidationCachesEXT_Null)(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) = 0;
    VkResult vk_common_MergeValidationCachesEXT_Weak(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_MergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDescriptorSetLayoutSupport_Weak=vk_common_GetDescriptorSetLayoutSupport_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDescriptorSetLayoutSupport=vk_common_GetDescriptorSetLayoutSupport_Weak")
    void (*vk_common_GetDescriptorSetLayoutSupport_Null)(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) = 0;
    void vk_common_GetDescriptorSetLayoutSupport_Weak(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDescriptorSetLayoutSupportKHR_Weak=vk_common_GetDescriptorSetLayoutSupportKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDescriptorSetLayoutSupportKHR=vk_common_GetDescriptorSetLayoutSupportKHR_Weak")
    void (*vk_common_GetDescriptorSetLayoutSupportKHR_Null)(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) = 0;
    void vk_common_GetDescriptorSetLayoutSupportKHR_Weak(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainGrallocUsageANDROID_Weak=vk_common_GetSwapchainGrallocUsageANDROID_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainGrallocUsageANDROID=vk_common_GetSwapchainGrallocUsageANDROID_Weak")
    VkResult (*vk_common_GetSwapchainGrallocUsageANDROID_Null)(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) = 0;
    VkResult vk_common_GetSwapchainGrallocUsageANDROID_Weak(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSwapchainGrallocUsageANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainGrallocUsage2ANDROID_Weak=vk_common_GetSwapchainGrallocUsage2ANDROID_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSwapchainGrallocUsage2ANDROID=vk_common_GetSwapchainGrallocUsage2ANDROID_Weak")
    VkResult (*vk_common_GetSwapchainGrallocUsage2ANDROID_Null)(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) = 0;
    VkResult vk_common_GetSwapchainGrallocUsage2ANDROID_Weak(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSwapchainGrallocUsage2ANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireImageANDROID_Weak=vk_common_AcquireImageANDROID_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireImageANDROID=vk_common_AcquireImageANDROID_Weak")
    VkResult (*vk_common_AcquireImageANDROID_Null)(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) = 0;
    VkResult vk_common_AcquireImageANDROID_Weak(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireImageANDROID(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueSignalReleaseImageANDROID_Weak=vk_common_QueueSignalReleaseImageANDROID_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueSignalReleaseImageANDROID=vk_common_QueueSignalReleaseImageANDROID_Weak")
    VkResult (*vk_common_QueueSignalReleaseImageANDROID_Null)(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) = 0;
    VkResult vk_common_QueueSignalReleaseImageANDROID_Weak(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_QueueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetShaderInfoAMD_Weak=vk_common_GetShaderInfoAMD_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetShaderInfoAMD=vk_common_GetShaderInfoAMD_Weak")
    VkResult (*vk_common_GetShaderInfoAMD_Null)(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) = 0;
    VkResult vk_common_GetShaderInfoAMD_Weak(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SetLocalDimmingAMD_Weak=vk_common_SetLocalDimmingAMD_Null")
    #pragma comment(linker, "/alternatename:vk_common_SetLocalDimmingAMD=vk_common_SetLocalDimmingAMD_Weak")
    void (*vk_common_SetLocalDimmingAMD_Null)(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) = 0;
    void vk_common_SetLocalDimmingAMD_Weak(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_SetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetCalibratedTimestampsEXT_Weak=vk_common_GetCalibratedTimestampsEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetCalibratedTimestampsEXT=vk_common_GetCalibratedTimestampsEXT_Weak")
    VkResult (*vk_common_GetCalibratedTimestampsEXT_Null)(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) = 0;
    VkResult vk_common_GetCalibratedTimestampsEXT_Weak(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SetDebugUtilsObjectNameEXT_Weak=vk_common_SetDebugUtilsObjectNameEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_SetDebugUtilsObjectNameEXT=vk_common_SetDebugUtilsObjectNameEXT_Weak")
    VkResult (*vk_common_SetDebugUtilsObjectNameEXT_Null)(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) = 0;
    VkResult vk_common_SetDebugUtilsObjectNameEXT_Weak(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SetDebugUtilsObjectTagEXT_Weak=vk_common_SetDebugUtilsObjectTagEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_SetDebugUtilsObjectTagEXT=vk_common_SetDebugUtilsObjectTagEXT_Weak")
    VkResult (*vk_common_SetDebugUtilsObjectTagEXT_Null)(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) = 0;
    VkResult vk_common_SetDebugUtilsObjectTagEXT_Weak(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueBeginDebugUtilsLabelEXT_Weak=vk_common_QueueBeginDebugUtilsLabelEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueBeginDebugUtilsLabelEXT=vk_common_QueueBeginDebugUtilsLabelEXT_Weak")
    void (*vk_common_QueueBeginDebugUtilsLabelEXT_Null)(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) = 0;
    void vk_common_QueueBeginDebugUtilsLabelEXT_Weak(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueEndDebugUtilsLabelEXT_Weak=vk_common_QueueEndDebugUtilsLabelEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueEndDebugUtilsLabelEXT=vk_common_QueueEndDebugUtilsLabelEXT_Weak")
    void (*vk_common_QueueEndDebugUtilsLabelEXT_Null)(VkQueue queue) = 0;
    void vk_common_QueueEndDebugUtilsLabelEXT_Weak(VkQueue queue);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_QueueEndDebugUtilsLabelEXT(VkQueue queue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueInsertDebugUtilsLabelEXT_Weak=vk_common_QueueInsertDebugUtilsLabelEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueInsertDebugUtilsLabelEXT=vk_common_QueueInsertDebugUtilsLabelEXT_Weak")
    void (*vk_common_QueueInsertDebugUtilsLabelEXT_Null)(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) = 0;
    void vk_common_QueueInsertDebugUtilsLabelEXT_Weak(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginDebugUtilsLabelEXT_Weak=vk_common_CmdBeginDebugUtilsLabelEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginDebugUtilsLabelEXT=vk_common_CmdBeginDebugUtilsLabelEXT_Weak")
    void (*vk_common_CmdBeginDebugUtilsLabelEXT_Null)(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) = 0;
    void vk_common_CmdBeginDebugUtilsLabelEXT_Weak(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndDebugUtilsLabelEXT_Weak=vk_common_CmdEndDebugUtilsLabelEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndDebugUtilsLabelEXT=vk_common_CmdEndDebugUtilsLabelEXT_Weak")
    void (*vk_common_CmdEndDebugUtilsLabelEXT_Null)(VkCommandBuffer commandBuffer) = 0;
    void vk_common_CmdEndDebugUtilsLabelEXT_Weak(VkCommandBuffer commandBuffer);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdInsertDebugUtilsLabelEXT_Weak=vk_common_CmdInsertDebugUtilsLabelEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdInsertDebugUtilsLabelEXT=vk_common_CmdInsertDebugUtilsLabelEXT_Weak")
    void (*vk_common_CmdInsertDebugUtilsLabelEXT_Null)(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) = 0;
    void vk_common_CmdInsertDebugUtilsLabelEXT_Weak(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryHostPointerPropertiesEXT_Weak=vk_common_GetMemoryHostPointerPropertiesEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryHostPointerPropertiesEXT=vk_common_GetMemoryHostPointerPropertiesEXT_Weak")
    VkResult (*vk_common_GetMemoryHostPointerPropertiesEXT_Null)(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) = 0;
    VkResult vk_common_GetMemoryHostPointerPropertiesEXT_Weak(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteBufferMarkerAMD_Weak=vk_common_CmdWriteBufferMarkerAMD_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteBufferMarkerAMD=vk_common_CmdWriteBufferMarkerAMD_Weak")
    void (*vk_common_CmdWriteBufferMarkerAMD_Null)(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) = 0;
    void vk_common_CmdWriteBufferMarkerAMD_Weak(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateRenderPass2_Weak=vk_common_CreateRenderPass2_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateRenderPass2=vk_common_CreateRenderPass2_Weak")
    VkResult (*vk_common_CreateRenderPass2_Null)(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) = 0;
    VkResult vk_common_CreateRenderPass2_Weak(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateRenderPass2KHR_Weak=vk_common_CreateRenderPass2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateRenderPass2KHR=vk_common_CreateRenderPass2KHR_Weak")
    VkResult (*vk_common_CreateRenderPass2KHR_Null)(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) = 0;
    VkResult vk_common_CreateRenderPass2KHR_Weak(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginRenderPass2_Weak=vk_common_CmdBeginRenderPass2_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginRenderPass2=vk_common_CmdBeginRenderPass2_Weak")
    void (*vk_common_CmdBeginRenderPass2_Null)(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) = 0;
    void vk_common_CmdBeginRenderPass2_Weak(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginRenderPass2KHR_Weak=vk_common_CmdBeginRenderPass2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginRenderPass2KHR=vk_common_CmdBeginRenderPass2KHR_Weak")
    void (*vk_common_CmdBeginRenderPass2KHR_Null)(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) = 0;
    void vk_common_CmdBeginRenderPass2KHR_Weak(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdNextSubpass2_Weak=vk_common_CmdNextSubpass2_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdNextSubpass2=vk_common_CmdNextSubpass2_Weak")
    void (*vk_common_CmdNextSubpass2_Null)(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) = 0;
    void vk_common_CmdNextSubpass2_Weak(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdNextSubpass2KHR_Weak=vk_common_CmdNextSubpass2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdNextSubpass2KHR=vk_common_CmdNextSubpass2KHR_Weak")
    void (*vk_common_CmdNextSubpass2KHR_Null)(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) = 0;
    void vk_common_CmdNextSubpass2KHR_Weak(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndRenderPass2_Weak=vk_common_CmdEndRenderPass2_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndRenderPass2=vk_common_CmdEndRenderPass2_Weak")
    void (*vk_common_CmdEndRenderPass2_Null)(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) = 0;
    void vk_common_CmdEndRenderPass2_Weak(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndRenderPass2KHR_Weak=vk_common_CmdEndRenderPass2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndRenderPass2KHR=vk_common_CmdEndRenderPass2KHR_Weak")
    void (*vk_common_CmdEndRenderPass2KHR_Null)(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) = 0;
    void vk_common_CmdEndRenderPass2KHR_Weak(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreCounterValue_Weak=vk_common_GetSemaphoreCounterValue_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreCounterValue=vk_common_GetSemaphoreCounterValue_Weak")
    VkResult (*vk_common_GetSemaphoreCounterValue_Null)(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) = 0;
    VkResult vk_common_GetSemaphoreCounterValue_Weak(VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreCounterValueKHR_Weak=vk_common_GetSemaphoreCounterValueKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetSemaphoreCounterValueKHR=vk_common_GetSemaphoreCounterValueKHR_Weak")
    VkResult (*vk_common_GetSemaphoreCounterValueKHR_Null)(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) = 0;
    VkResult vk_common_GetSemaphoreCounterValueKHR_Weak(VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_WaitSemaphores_Weak=vk_common_WaitSemaphores_Null")
    #pragma comment(linker, "/alternatename:vk_common_WaitSemaphores=vk_common_WaitSemaphores_Weak")
    VkResult (*vk_common_WaitSemaphores_Null)(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) = 0;
    VkResult vk_common_WaitSemaphores_Weak(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_WaitSemaphoresKHR_Weak=vk_common_WaitSemaphoresKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_WaitSemaphoresKHR=vk_common_WaitSemaphoresKHR_Weak")
    VkResult (*vk_common_WaitSemaphoresKHR_Null)(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) = 0;
    VkResult vk_common_WaitSemaphoresKHR_Weak(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_WaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SignalSemaphore_Weak=vk_common_SignalSemaphore_Null")
    #pragma comment(linker, "/alternatename:vk_common_SignalSemaphore=vk_common_SignalSemaphore_Weak")
    VkResult (*vk_common_SignalSemaphore_Null)(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) = 0;
    VkResult vk_common_SignalSemaphore_Weak(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SignalSemaphoreKHR_Weak=vk_common_SignalSemaphoreKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_SignalSemaphoreKHR=vk_common_SignalSemaphoreKHR_Weak")
    VkResult (*vk_common_SignalSemaphoreKHR_Null)(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) = 0;
    VkResult vk_common_SignalSemaphoreKHR_Weak(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_SignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetAndroidHardwareBufferPropertiesANDROID_Weak=vk_common_GetAndroidHardwareBufferPropertiesANDROID_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetAndroidHardwareBufferPropertiesANDROID=vk_common_GetAndroidHardwareBufferPropertiesANDROID_Weak")
    VkResult (*vk_common_GetAndroidHardwareBufferPropertiesANDROID_Null)(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) = 0;
    VkResult vk_common_GetAndroidHardwareBufferPropertiesANDROID_Weak(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryAndroidHardwareBufferANDROID_Weak=vk_common_GetMemoryAndroidHardwareBufferANDROID_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetMemoryAndroidHardwareBufferANDROID=vk_common_GetMemoryAndroidHardwareBufferANDROID_Weak")
    VkResult (*vk_common_GetMemoryAndroidHardwareBufferANDROID_Null)(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) = 0;
    VkResult vk_common_GetMemoryAndroidHardwareBufferANDROID_Weak(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectCount_Weak=vk_common_CmdDrawIndirectCount_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectCount=vk_common_CmdDrawIndirectCount_Weak")
    void (*vk_common_CmdDrawIndirectCount_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndirectCount_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectCountKHR_Weak=vk_common_CmdDrawIndirectCountKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectCountKHR=vk_common_CmdDrawIndirectCountKHR_Weak")
    void (*vk_common_CmdDrawIndirectCountKHR_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndirectCountKHR_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectCountAMD_Weak=vk_common_CmdDrawIndirectCountAMD_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectCountAMD=vk_common_CmdDrawIndirectCountAMD_Weak")
    void (*vk_common_CmdDrawIndirectCountAMD_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndirectCountAMD_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirectCount_Weak=vk_common_CmdDrawIndexedIndirectCount_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirectCount=vk_common_CmdDrawIndexedIndirectCount_Weak")
    void (*vk_common_CmdDrawIndexedIndirectCount_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndexedIndirectCount_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirectCountKHR_Weak=vk_common_CmdDrawIndexedIndirectCountKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirectCountKHR=vk_common_CmdDrawIndexedIndirectCountKHR_Weak")
    void (*vk_common_CmdDrawIndexedIndirectCountKHR_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndexedIndirectCountKHR_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirectCountAMD_Weak=vk_common_CmdDrawIndexedIndirectCountAMD_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndexedIndirectCountAMD=vk_common_CmdDrawIndexedIndirectCountAMD_Weak")
    void (*vk_common_CmdDrawIndexedIndirectCountAMD_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawIndexedIndirectCountAMD_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetCheckpointNV_Weak=vk_common_CmdSetCheckpointNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetCheckpointNV=vk_common_CmdSetCheckpointNV_Weak")
    void (*vk_common_CmdSetCheckpointNV_Null)(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) = 0;
    void vk_common_CmdSetCheckpointNV_Weak(VkCommandBuffer commandBuffer, const void* pCheckpointMarker);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetQueueCheckpointDataNV_Weak=vk_common_GetQueueCheckpointDataNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetQueueCheckpointDataNV=vk_common_GetQueueCheckpointDataNV_Weak")
    void (*vk_common_GetQueueCheckpointDataNV_Null)(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) = 0;
    void vk_common_GetQueueCheckpointDataNV_Weak(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindTransformFeedbackBuffersEXT_Weak=vk_common_CmdBindTransformFeedbackBuffersEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindTransformFeedbackBuffersEXT=vk_common_CmdBindTransformFeedbackBuffersEXT_Weak")
    void (*vk_common_CmdBindTransformFeedbackBuffersEXT_Null)(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) = 0;
    void vk_common_CmdBindTransformFeedbackBuffersEXT_Weak(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginTransformFeedbackEXT_Weak=vk_common_CmdBeginTransformFeedbackEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginTransformFeedbackEXT=vk_common_CmdBeginTransformFeedbackEXT_Weak")
    void (*vk_common_CmdBeginTransformFeedbackEXT_Null)(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) = 0;
    void vk_common_CmdBeginTransformFeedbackEXT_Weak(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndTransformFeedbackEXT_Weak=vk_common_CmdEndTransformFeedbackEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndTransformFeedbackEXT=vk_common_CmdEndTransformFeedbackEXT_Weak")
    void (*vk_common_CmdEndTransformFeedbackEXT_Null)(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) = 0;
    void vk_common_CmdEndTransformFeedbackEXT_Weak(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginQueryIndexedEXT_Weak=vk_common_CmdBeginQueryIndexedEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBeginQueryIndexedEXT=vk_common_CmdBeginQueryIndexedEXT_Weak")
    void (*vk_common_CmdBeginQueryIndexedEXT_Null)(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) = 0;
    void vk_common_CmdBeginQueryIndexedEXT_Weak(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdEndQueryIndexedEXT_Weak=vk_common_CmdEndQueryIndexedEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdEndQueryIndexedEXT=vk_common_CmdEndQueryIndexedEXT_Weak")
    void (*vk_common_CmdEndQueryIndexedEXT_Null)(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) = 0;
    void vk_common_CmdEndQueryIndexedEXT_Weak(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectByteCountEXT_Weak=vk_common_CmdDrawIndirectByteCountEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawIndirectByteCountEXT=vk_common_CmdDrawIndirectByteCountEXT_Weak")
    void (*vk_common_CmdDrawIndirectByteCountEXT_Null)(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) = 0;
    void vk_common_CmdDrawIndirectByteCountEXT_Weak(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetExclusiveScissorNV_Weak=vk_common_CmdSetExclusiveScissorNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetExclusiveScissorNV=vk_common_CmdSetExclusiveScissorNV_Weak")
    void (*vk_common_CmdSetExclusiveScissorNV_Null)(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) = 0;
    void vk_common_CmdSetExclusiveScissorNV_Weak(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindShadingRateImageNV_Weak=vk_common_CmdBindShadingRateImageNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindShadingRateImageNV=vk_common_CmdBindShadingRateImageNV_Weak")
    void (*vk_common_CmdBindShadingRateImageNV_Null)(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) = 0;
    void vk_common_CmdBindShadingRateImageNV_Weak(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewportShadingRatePaletteNV_Weak=vk_common_CmdSetViewportShadingRatePaletteNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewportShadingRatePaletteNV=vk_common_CmdSetViewportShadingRatePaletteNV_Weak")
    void (*vk_common_CmdSetViewportShadingRatePaletteNV_Null)(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) = 0;
    void vk_common_CmdSetViewportShadingRatePaletteNV_Weak(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetCoarseSampleOrderNV_Weak=vk_common_CmdSetCoarseSampleOrderNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetCoarseSampleOrderNV=vk_common_CmdSetCoarseSampleOrderNV_Weak")
    void (*vk_common_CmdSetCoarseSampleOrderNV_Null)(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) = 0;
    void vk_common_CmdSetCoarseSampleOrderNV_Weak(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawMeshTasksNV_Weak=vk_common_CmdDrawMeshTasksNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawMeshTasksNV=vk_common_CmdDrawMeshTasksNV_Weak")
    void (*vk_common_CmdDrawMeshTasksNV_Null)(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) = 0;
    void vk_common_CmdDrawMeshTasksNV_Weak(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawMeshTasksIndirectNV_Weak=vk_common_CmdDrawMeshTasksIndirectNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawMeshTasksIndirectNV=vk_common_CmdDrawMeshTasksIndirectNV_Weak")
    void (*vk_common_CmdDrawMeshTasksIndirectNV_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawMeshTasksIndirectNV_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawMeshTasksIndirectCountNV_Weak=vk_common_CmdDrawMeshTasksIndirectCountNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdDrawMeshTasksIndirectCountNV=vk_common_CmdDrawMeshTasksIndirectCountNV_Weak")
    void (*vk_common_CmdDrawMeshTasksIndirectCountNV_Null)(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) = 0;
    void vk_common_CmdDrawMeshTasksIndirectCountNV_Weak(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CompileDeferredNV_Weak=vk_common_CompileDeferredNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CompileDeferredNV=vk_common_CompileDeferredNV_Weak")
    VkResult (*vk_common_CompileDeferredNV_Null)(VkDevice device, VkPipeline pipeline, uint32_t shader) = 0;
    VkResult vk_common_CompileDeferredNV_Weak(VkDevice device, VkPipeline pipeline, uint32_t shader);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateAccelerationStructureNV_Weak=vk_common_CreateAccelerationStructureNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateAccelerationStructureNV=vk_common_CreateAccelerationStructureNV_Weak")
    VkResult (*vk_common_CreateAccelerationStructureNV_Null)(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) = 0;
    VkResult vk_common_CreateAccelerationStructureNV_Weak(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyAccelerationStructureKHR_Weak=vk_common_DestroyAccelerationStructureKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyAccelerationStructureKHR=vk_common_DestroyAccelerationStructureKHR_Weak")
    void (*vk_common_DestroyAccelerationStructureKHR_Null)(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyAccelerationStructureKHR_Weak(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyAccelerationStructureNV_Weak=vk_common_DestroyAccelerationStructureNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyAccelerationStructureNV=vk_common_DestroyAccelerationStructureNV_Weak")
    void (*vk_common_DestroyAccelerationStructureNV_Null)(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyAccelerationStructureNV_Weak(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureMemoryRequirementsNV_Weak=vk_common_GetAccelerationStructureMemoryRequirementsNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureMemoryRequirementsNV=vk_common_GetAccelerationStructureMemoryRequirementsNV_Weak")
    void (*vk_common_GetAccelerationStructureMemoryRequirementsNV_Null)(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) = 0;
    void vk_common_GetAccelerationStructureMemoryRequirementsNV_Weak(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BindAccelerationStructureMemoryNV_Weak=vk_common_BindAccelerationStructureMemoryNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_BindAccelerationStructureMemoryNV=vk_common_BindAccelerationStructureMemoryNV_Weak")
    VkResult (*vk_common_BindAccelerationStructureMemoryNV_Null)(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) = 0;
    VkResult vk_common_BindAccelerationStructureMemoryNV_Weak(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyAccelerationStructureNV_Weak=vk_common_CmdCopyAccelerationStructureNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyAccelerationStructureNV=vk_common_CmdCopyAccelerationStructureNV_Weak")
    void (*vk_common_CmdCopyAccelerationStructureNV_Null)(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) = 0;
    void vk_common_CmdCopyAccelerationStructureNV_Weak(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyAccelerationStructureKHR_Weak=vk_common_CmdCopyAccelerationStructureKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyAccelerationStructureKHR=vk_common_CmdCopyAccelerationStructureKHR_Weak")
    void (*vk_common_CmdCopyAccelerationStructureKHR_Null)(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) = 0;
    void vk_common_CmdCopyAccelerationStructureKHR_Weak(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CopyAccelerationStructureKHR_Weak=vk_common_CopyAccelerationStructureKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CopyAccelerationStructureKHR=vk_common_CopyAccelerationStructureKHR_Weak")
    VkResult (*vk_common_CopyAccelerationStructureKHR_Null)(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) = 0;
    VkResult vk_common_CopyAccelerationStructureKHR_Weak(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyAccelerationStructureToMemoryKHR_Weak=vk_common_CmdCopyAccelerationStructureToMemoryKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyAccelerationStructureToMemoryKHR=vk_common_CmdCopyAccelerationStructureToMemoryKHR_Weak")
    void (*vk_common_CmdCopyAccelerationStructureToMemoryKHR_Null)(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) = 0;
    void vk_common_CmdCopyAccelerationStructureToMemoryKHR_Weak(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CopyAccelerationStructureToMemoryKHR_Weak=vk_common_CopyAccelerationStructureToMemoryKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CopyAccelerationStructureToMemoryKHR=vk_common_CopyAccelerationStructureToMemoryKHR_Weak")
    VkResult (*vk_common_CopyAccelerationStructureToMemoryKHR_Null)(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) = 0;
    VkResult vk_common_CopyAccelerationStructureToMemoryKHR_Weak(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyMemoryToAccelerationStructureKHR_Weak=vk_common_CmdCopyMemoryToAccelerationStructureKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyMemoryToAccelerationStructureKHR=vk_common_CmdCopyMemoryToAccelerationStructureKHR_Weak")
    void (*vk_common_CmdCopyMemoryToAccelerationStructureKHR_Null)(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) = 0;
    void vk_common_CmdCopyMemoryToAccelerationStructureKHR_Weak(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CopyMemoryToAccelerationStructureKHR_Weak=vk_common_CopyMemoryToAccelerationStructureKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CopyMemoryToAccelerationStructureKHR=vk_common_CopyMemoryToAccelerationStructureKHR_Weak")
    VkResult (*vk_common_CopyMemoryToAccelerationStructureKHR_Null)(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) = 0;
    VkResult vk_common_CopyMemoryToAccelerationStructureKHR_Weak(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteAccelerationStructuresPropertiesKHR_Weak=vk_common_CmdWriteAccelerationStructuresPropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteAccelerationStructuresPropertiesKHR=vk_common_CmdWriteAccelerationStructuresPropertiesKHR_Weak")
    void (*vk_common_CmdWriteAccelerationStructuresPropertiesKHR_Null)(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) = 0;
    void vk_common_CmdWriteAccelerationStructuresPropertiesKHR_Weak(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteAccelerationStructuresPropertiesNV_Weak=vk_common_CmdWriteAccelerationStructuresPropertiesNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdWriteAccelerationStructuresPropertiesNV=vk_common_CmdWriteAccelerationStructuresPropertiesNV_Weak")
    void (*vk_common_CmdWriteAccelerationStructuresPropertiesNV_Null)(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) = 0;
    void vk_common_CmdWriteAccelerationStructuresPropertiesNV_Weak(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBuildAccelerationStructureNV_Weak=vk_common_CmdBuildAccelerationStructureNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBuildAccelerationStructureNV=vk_common_CmdBuildAccelerationStructureNV_Weak")
    void (*vk_common_CmdBuildAccelerationStructureNV_Null)(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) = 0;
    void vk_common_CmdBuildAccelerationStructureNV_Weak(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_WriteAccelerationStructuresPropertiesKHR_Weak=vk_common_WriteAccelerationStructuresPropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_WriteAccelerationStructuresPropertiesKHR=vk_common_WriteAccelerationStructuresPropertiesKHR_Weak")
    VkResult (*vk_common_WriteAccelerationStructuresPropertiesKHR_Null)(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride) = 0;
    VkResult vk_common_WriteAccelerationStructuresPropertiesKHR_Weak(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_WriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdTraceRaysKHR_Weak=vk_common_CmdTraceRaysKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdTraceRaysKHR=vk_common_CmdTraceRaysKHR_Weak")
    void (*vk_common_CmdTraceRaysKHR_Null)(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) = 0;
    void vk_common_CmdTraceRaysKHR_Weak(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdTraceRaysNV_Weak=vk_common_CmdTraceRaysNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdTraceRaysNV=vk_common_CmdTraceRaysNV_Weak")
    void (*vk_common_CmdTraceRaysNV_Null)(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) = 0;
    void vk_common_CmdTraceRaysNV_Weak(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingShaderGroupHandlesKHR_Weak=vk_common_GetRayTracingShaderGroupHandlesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingShaderGroupHandlesKHR=vk_common_GetRayTracingShaderGroupHandlesKHR_Weak")
    VkResult (*vk_common_GetRayTracingShaderGroupHandlesKHR_Null)(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) = 0;
    VkResult vk_common_GetRayTracingShaderGroupHandlesKHR_Weak(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingShaderGroupHandlesNV_Weak=vk_common_GetRayTracingShaderGroupHandlesNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingShaderGroupHandlesNV=vk_common_GetRayTracingShaderGroupHandlesNV_Weak")
    VkResult (*vk_common_GetRayTracingShaderGroupHandlesNV_Null)(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) = 0;
    VkResult vk_common_GetRayTracingShaderGroupHandlesNV_Weak(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR_Weak=vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR=vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR_Weak")
    VkResult (*vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR_Null)(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) = 0;
    VkResult vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR_Weak(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureHandleNV_Weak=vk_common_GetAccelerationStructureHandleNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureHandleNV=vk_common_GetAccelerationStructureHandleNV_Weak")
    VkResult (*vk_common_GetAccelerationStructureHandleNV_Null)(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) = 0;
    VkResult vk_common_GetAccelerationStructureHandleNV_Weak(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateRayTracingPipelinesNV_Weak=vk_common_CreateRayTracingPipelinesNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateRayTracingPipelinesNV=vk_common_CreateRayTracingPipelinesNV_Weak")
    VkResult (*vk_common_CreateRayTracingPipelinesNV_Null)(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) = 0;
    VkResult vk_common_CreateRayTracingPipelinesNV_Weak(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateRayTracingPipelinesKHR_Weak=vk_common_CreateRayTracingPipelinesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateRayTracingPipelinesKHR=vk_common_CreateRayTracingPipelinesKHR_Weak")
    VkResult (*vk_common_CreateRayTracingPipelinesKHR_Null)(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) = 0;
    VkResult vk_common_CreateRayTracingPipelinesKHR_Weak(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdTraceRaysIndirectKHR_Weak=vk_common_CmdTraceRaysIndirectKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdTraceRaysIndirectKHR=vk_common_CmdTraceRaysIndirectKHR_Weak")
    void (*vk_common_CmdTraceRaysIndirectKHR_Null)(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) = 0;
    void vk_common_CmdTraceRaysIndirectKHR_Weak(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceAccelerationStructureCompatibilityKHR_Weak=vk_common_GetDeviceAccelerationStructureCompatibilityKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceAccelerationStructureCompatibilityKHR=vk_common_GetDeviceAccelerationStructureCompatibilityKHR_Weak")
    void (*vk_common_GetDeviceAccelerationStructureCompatibilityKHR_Null)(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) = 0;
    void vk_common_GetDeviceAccelerationStructureCompatibilityKHR_Weak(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingShaderGroupStackSizeKHR_Weak=vk_common_GetRayTracingShaderGroupStackSizeKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetRayTracingShaderGroupStackSizeKHR=vk_common_GetRayTracingShaderGroupStackSizeKHR_Weak")
    VkDeviceSize (*vk_common_GetRayTracingShaderGroupStackSizeKHR_Null)(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) = 0;
    VkDeviceSize vk_common_GetRayTracingShaderGroupStackSizeKHR_Weak(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
#else
    VKAPI_ATTR VkDeviceSize VKAPI_CALL vk_common_GetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetRayTracingPipelineStackSizeKHR_Weak=vk_common_CmdSetRayTracingPipelineStackSizeKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetRayTracingPipelineStackSizeKHR=vk_common_CmdSetRayTracingPipelineStackSizeKHR_Weak")
    void (*vk_common_CmdSetRayTracingPipelineStackSizeKHR_Null)(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) = 0;
    void vk_common_CmdSetRayTracingPipelineStackSizeKHR_Weak(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageViewHandleNVX_Weak=vk_common_GetImageViewHandleNVX_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageViewHandleNVX=vk_common_GetImageViewHandleNVX_Weak")
    uint32_t (*vk_common_GetImageViewHandleNVX_Null)(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) = 0;
    uint32_t vk_common_GetImageViewHandleNVX_Weak(VkDevice device, const VkImageViewHandleInfoNVX* pInfo);
#else
    VKAPI_ATTR uint32_t VKAPI_CALL vk_common_GetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageViewAddressNVX_Weak=vk_common_GetImageViewAddressNVX_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageViewAddressNVX=vk_common_GetImageViewAddressNVX_Weak")
    VkResult (*vk_common_GetImageViewAddressNVX_Null)(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) = 0;
    VkResult vk_common_GetImageViewAddressNVX_Weak(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) __attribute__ ((weak));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupSurfacePresentModes2EXT_Weak=vk_common_GetDeviceGroupSurfacePresentModes2EXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceGroupSurfacePresentModes2EXT=vk_common_GetDeviceGroupSurfacePresentModes2EXT_Weak")
    VkResult (*vk_common_GetDeviceGroupSurfacePresentModes2EXT_Null)(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) = 0;
    VkResult vk_common_GetDeviceGroupSurfacePresentModes2EXT_Weak(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireFullScreenExclusiveModeEXT_Weak=vk_common_AcquireFullScreenExclusiveModeEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireFullScreenExclusiveModeEXT=vk_common_AcquireFullScreenExclusiveModeEXT_Weak")
    VkResult (*vk_common_AcquireFullScreenExclusiveModeEXT_Null)(VkDevice device, VkSwapchainKHR swapchain) = 0;
    VkResult vk_common_AcquireFullScreenExclusiveModeEXT_Weak(VkDevice device, VkSwapchainKHR swapchain);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ReleaseFullScreenExclusiveModeEXT_Weak=vk_common_ReleaseFullScreenExclusiveModeEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_ReleaseFullScreenExclusiveModeEXT=vk_common_ReleaseFullScreenExclusiveModeEXT_Weak")
    VkResult (*vk_common_ReleaseFullScreenExclusiveModeEXT_Null)(VkDevice device, VkSwapchainKHR swapchain) = 0;
    VkResult vk_common_ReleaseFullScreenExclusiveModeEXT_Weak(VkDevice device, VkSwapchainKHR swapchain);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) __attribute__ ((weak));
#endif
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquireProfilingLockKHR_Weak=vk_common_AcquireProfilingLockKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquireProfilingLockKHR=vk_common_AcquireProfilingLockKHR_Weak")
    VkResult (*vk_common_AcquireProfilingLockKHR_Null)(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) = 0;
    VkResult vk_common_AcquireProfilingLockKHR_Weak(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ReleaseProfilingLockKHR_Weak=vk_common_ReleaseProfilingLockKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_ReleaseProfilingLockKHR=vk_common_ReleaseProfilingLockKHR_Weak")
    void (*vk_common_ReleaseProfilingLockKHR_Null)(VkDevice device) = 0;
    void vk_common_ReleaseProfilingLockKHR_Weak(VkDevice device);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_ReleaseProfilingLockKHR(VkDevice device) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetImageDrmFormatModifierPropertiesEXT_Weak=vk_common_GetImageDrmFormatModifierPropertiesEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetImageDrmFormatModifierPropertiesEXT=vk_common_GetImageDrmFormatModifierPropertiesEXT_Weak")
    VkResult (*vk_common_GetImageDrmFormatModifierPropertiesEXT_Null)(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) = 0;
    VkResult vk_common_GetImageDrmFormatModifierPropertiesEXT_Weak(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferOpaqueCaptureAddress_Weak=vk_common_GetBufferOpaqueCaptureAddress_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferOpaqueCaptureAddress=vk_common_GetBufferOpaqueCaptureAddress_Weak")
    uint64_t (*vk_common_GetBufferOpaqueCaptureAddress_Null)(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) = 0;
    uint64_t vk_common_GetBufferOpaqueCaptureAddress_Weak(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
#else
    VKAPI_ATTR uint64_t VKAPI_CALL vk_common_GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferOpaqueCaptureAddressKHR_Weak=vk_common_GetBufferOpaqueCaptureAddressKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferOpaqueCaptureAddressKHR=vk_common_GetBufferOpaqueCaptureAddressKHR_Weak")
    uint64_t (*vk_common_GetBufferOpaqueCaptureAddressKHR_Null)(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) = 0;
    uint64_t vk_common_GetBufferOpaqueCaptureAddressKHR_Weak(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
#else
    VKAPI_ATTR uint64_t VKAPI_CALL vk_common_GetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferDeviceAddress_Weak=vk_common_GetBufferDeviceAddress_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferDeviceAddress=vk_common_GetBufferDeviceAddress_Weak")
    VkDeviceAddress (*vk_common_GetBufferDeviceAddress_Null)(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) = 0;
    VkDeviceAddress vk_common_GetBufferDeviceAddress_Weak(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
#else
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL vk_common_GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferDeviceAddressKHR_Weak=vk_common_GetBufferDeviceAddressKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferDeviceAddressKHR=vk_common_GetBufferDeviceAddressKHR_Weak")
    VkDeviceAddress (*vk_common_GetBufferDeviceAddressKHR_Null)(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) = 0;
    VkDeviceAddress vk_common_GetBufferDeviceAddressKHR_Weak(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
#else
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL vk_common_GetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetBufferDeviceAddressEXT_Weak=vk_common_GetBufferDeviceAddressEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetBufferDeviceAddressEXT=vk_common_GetBufferDeviceAddressEXT_Weak")
    VkDeviceAddress (*vk_common_GetBufferDeviceAddressEXT_Null)(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) = 0;
    VkDeviceAddress vk_common_GetBufferDeviceAddressEXT_Weak(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
#else
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL vk_common_GetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_InitializePerformanceApiINTEL_Weak=vk_common_InitializePerformanceApiINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_InitializePerformanceApiINTEL=vk_common_InitializePerformanceApiINTEL_Weak")
    VkResult (*vk_common_InitializePerformanceApiINTEL_Null)(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) = 0;
    VkResult vk_common_InitializePerformanceApiINTEL_Weak(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_InitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_UninitializePerformanceApiINTEL_Weak=vk_common_UninitializePerformanceApiINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_UninitializePerformanceApiINTEL=vk_common_UninitializePerformanceApiINTEL_Weak")
    void (*vk_common_UninitializePerformanceApiINTEL_Null)(VkDevice device) = 0;
    void vk_common_UninitializePerformanceApiINTEL_Weak(VkDevice device);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_UninitializePerformanceApiINTEL(VkDevice device) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPerformanceMarkerINTEL_Weak=vk_common_CmdSetPerformanceMarkerINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPerformanceMarkerINTEL=vk_common_CmdSetPerformanceMarkerINTEL_Weak")
    VkResult (*vk_common_CmdSetPerformanceMarkerINTEL_Null)(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) = 0;
    VkResult vk_common_CmdSetPerformanceMarkerINTEL_Weak(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPerformanceStreamMarkerINTEL_Weak=vk_common_CmdSetPerformanceStreamMarkerINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPerformanceStreamMarkerINTEL=vk_common_CmdSetPerformanceStreamMarkerINTEL_Weak")
    VkResult (*vk_common_CmdSetPerformanceStreamMarkerINTEL_Null)(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) = 0;
    VkResult vk_common_CmdSetPerformanceStreamMarkerINTEL_Weak(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPerformanceOverrideINTEL_Weak=vk_common_CmdSetPerformanceOverrideINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPerformanceOverrideINTEL=vk_common_CmdSetPerformanceOverrideINTEL_Weak")
    VkResult (*vk_common_CmdSetPerformanceOverrideINTEL_Null)(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) = 0;
    VkResult vk_common_CmdSetPerformanceOverrideINTEL_Weak(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_AcquirePerformanceConfigurationINTEL_Weak=vk_common_AcquirePerformanceConfigurationINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_AcquirePerformanceConfigurationINTEL=vk_common_AcquirePerformanceConfigurationINTEL_Weak")
    VkResult (*vk_common_AcquirePerformanceConfigurationINTEL_Null)(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) = 0;
    VkResult vk_common_AcquirePerformanceConfigurationINTEL_Weak(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_AcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_ReleasePerformanceConfigurationINTEL_Weak=vk_common_ReleasePerformanceConfigurationINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_ReleasePerformanceConfigurationINTEL=vk_common_ReleasePerformanceConfigurationINTEL_Weak")
    VkResult (*vk_common_ReleasePerformanceConfigurationINTEL_Null)(VkDevice device, VkPerformanceConfigurationINTEL configuration) = 0;
    VkResult vk_common_ReleasePerformanceConfigurationINTEL_Weak(VkDevice device, VkPerformanceConfigurationINTEL configuration);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_ReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_QueueSetPerformanceConfigurationINTEL_Weak=vk_common_QueueSetPerformanceConfigurationINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_QueueSetPerformanceConfigurationINTEL=vk_common_QueueSetPerformanceConfigurationINTEL_Weak")
    VkResult (*vk_common_QueueSetPerformanceConfigurationINTEL_Null)(VkQueue queue, VkPerformanceConfigurationINTEL configuration) = 0;
    VkResult vk_common_QueueSetPerformanceConfigurationINTEL_Weak(VkQueue queue, VkPerformanceConfigurationINTEL configuration);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_QueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPerformanceParameterINTEL_Weak=vk_common_GetPerformanceParameterINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPerformanceParameterINTEL=vk_common_GetPerformanceParameterINTEL_Weak")
    VkResult (*vk_common_GetPerformanceParameterINTEL_Null)(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) = 0;
    VkResult vk_common_GetPerformanceParameterINTEL_Weak(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceMemoryOpaqueCaptureAddress_Weak=vk_common_GetDeviceMemoryOpaqueCaptureAddress_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceMemoryOpaqueCaptureAddress=vk_common_GetDeviceMemoryOpaqueCaptureAddress_Weak")
    uint64_t (*vk_common_GetDeviceMemoryOpaqueCaptureAddress_Null)(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) = 0;
    uint64_t vk_common_GetDeviceMemoryOpaqueCaptureAddress_Weak(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
#else
    VKAPI_ATTR uint64_t VKAPI_CALL vk_common_GetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR_Weak=vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR=vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR_Weak")
    uint64_t (*vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR_Null)(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) = 0;
    uint64_t vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR_Weak(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
#else
    VKAPI_ATTR uint64_t VKAPI_CALL vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineExecutablePropertiesKHR_Weak=vk_common_GetPipelineExecutablePropertiesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineExecutablePropertiesKHR=vk_common_GetPipelineExecutablePropertiesKHR_Weak")
    VkResult (*vk_common_GetPipelineExecutablePropertiesKHR_Null)(VkDevice                        device, const VkPipelineInfoKHR*        pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) = 0;
    VkResult vk_common_GetPipelineExecutablePropertiesKHR_Weak(VkDevice                        device, const VkPipelineInfoKHR*        pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPipelineExecutablePropertiesKHR(VkDevice                        device, const VkPipelineInfoKHR*        pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineExecutableStatisticsKHR_Weak=vk_common_GetPipelineExecutableStatisticsKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineExecutableStatisticsKHR=vk_common_GetPipelineExecutableStatisticsKHR_Weak")
    VkResult (*vk_common_GetPipelineExecutableStatisticsKHR_Null)(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) = 0;
    VkResult vk_common_GetPipelineExecutableStatisticsKHR_Weak(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPipelineExecutableStatisticsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineExecutableInternalRepresentationsKHR_Weak=vk_common_GetPipelineExecutableInternalRepresentationsKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPipelineExecutableInternalRepresentationsKHR=vk_common_GetPipelineExecutableInternalRepresentationsKHR_Weak")
    VkResult (*vk_common_GetPipelineExecutableInternalRepresentationsKHR_Null)(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) = 0;
    VkResult vk_common_GetPipelineExecutableInternalRepresentationsKHR_Weak(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetPipelineExecutableInternalRepresentationsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetLineStippleEXT_Weak=vk_common_CmdSetLineStippleEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetLineStippleEXT=vk_common_CmdSetLineStippleEXT_Weak")
    void (*vk_common_CmdSetLineStippleEXT_Null)(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) = 0;
    void vk_common_CmdSetLineStippleEXT_Weak(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateAccelerationStructureKHR_Weak=vk_common_CreateAccelerationStructureKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateAccelerationStructureKHR=vk_common_CreateAccelerationStructureKHR_Weak")
    VkResult (*vk_common_CreateAccelerationStructureKHR_Null)(VkDevice                                           device, const VkAccelerationStructureCreateInfoKHR*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkAccelerationStructureKHR*                        pAccelerationStructure) = 0;
    VkResult vk_common_CreateAccelerationStructureKHR_Weak(VkDevice                                           device, const VkAccelerationStructureCreateInfoKHR*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkAccelerationStructureKHR*                        pAccelerationStructure);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateAccelerationStructureKHR(VkDevice                                           device, const VkAccelerationStructureCreateInfoKHR*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkAccelerationStructureKHR*                        pAccelerationStructure) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBuildAccelerationStructuresKHR_Weak=vk_common_CmdBuildAccelerationStructuresKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBuildAccelerationStructuresKHR=vk_common_CmdBuildAccelerationStructuresKHR_Weak")
    void (*vk_common_CmdBuildAccelerationStructuresKHR_Null)(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) = 0;
    void vk_common_CmdBuildAccelerationStructuresKHR_Weak(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBuildAccelerationStructuresKHR(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBuildAccelerationStructuresIndirectKHR_Weak=vk_common_CmdBuildAccelerationStructuresIndirectKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBuildAccelerationStructuresIndirectKHR=vk_common_CmdBuildAccelerationStructuresIndirectKHR_Weak")
    void (*vk_common_CmdBuildAccelerationStructuresIndirectKHR_Null)(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts) = 0;
    void vk_common_CmdBuildAccelerationStructuresIndirectKHR_Weak(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_BuildAccelerationStructuresKHR_Weak=vk_common_BuildAccelerationStructuresKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_BuildAccelerationStructuresKHR=vk_common_BuildAccelerationStructuresKHR_Weak")
    VkResult (*vk_common_BuildAccelerationStructuresKHR_Null)(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) = 0;
    VkResult vk_common_BuildAccelerationStructuresKHR_Weak(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_BuildAccelerationStructuresKHR(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureDeviceAddressKHR_Weak=vk_common_GetAccelerationStructureDeviceAddressKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureDeviceAddressKHR=vk_common_GetAccelerationStructureDeviceAddressKHR_Weak")
    VkDeviceAddress (*vk_common_GetAccelerationStructureDeviceAddressKHR_Null)(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) = 0;
    VkDeviceAddress vk_common_GetAccelerationStructureDeviceAddressKHR_Weak(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);
#else
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL vk_common_GetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDeferredOperationKHR_Weak=vk_common_CreateDeferredOperationKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDeferredOperationKHR=vk_common_CreateDeferredOperationKHR_Weak")
    VkResult (*vk_common_CreateDeferredOperationKHR_Null)(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) = 0;
    VkResult vk_common_CreateDeferredOperationKHR_Weak(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyDeferredOperationKHR_Weak=vk_common_DestroyDeferredOperationKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyDeferredOperationKHR=vk_common_DestroyDeferredOperationKHR_Weak")
    void (*vk_common_DestroyDeferredOperationKHR_Null)(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyDeferredOperationKHR_Weak(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeferredOperationMaxConcurrencyKHR_Weak=vk_common_GetDeferredOperationMaxConcurrencyKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeferredOperationMaxConcurrencyKHR=vk_common_GetDeferredOperationMaxConcurrencyKHR_Weak")
    uint32_t (*vk_common_GetDeferredOperationMaxConcurrencyKHR_Null)(VkDevice device, VkDeferredOperationKHR operation) = 0;
    uint32_t vk_common_GetDeferredOperationMaxConcurrencyKHR_Weak(VkDevice device, VkDeferredOperationKHR operation);
#else
    VKAPI_ATTR uint32_t VKAPI_CALL vk_common_GetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetDeferredOperationResultKHR_Weak=vk_common_GetDeferredOperationResultKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetDeferredOperationResultKHR=vk_common_GetDeferredOperationResultKHR_Weak")
    VkResult (*vk_common_GetDeferredOperationResultKHR_Null)(VkDevice device, VkDeferredOperationKHR operation) = 0;
    VkResult vk_common_GetDeferredOperationResultKHR_Weak(VkDevice device, VkDeferredOperationKHR operation);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_GetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DeferredOperationJoinKHR_Weak=vk_common_DeferredOperationJoinKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_DeferredOperationJoinKHR=vk_common_DeferredOperationJoinKHR_Weak")
    VkResult (*vk_common_DeferredOperationJoinKHR_Null)(VkDevice device, VkDeferredOperationKHR operation) = 0;
    VkResult vk_common_DeferredOperationJoinKHR_Weak(VkDevice device, VkDeferredOperationKHR operation);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_DeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetCullModeEXT_Weak=vk_common_CmdSetCullModeEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetCullModeEXT=vk_common_CmdSetCullModeEXT_Weak")
    void (*vk_common_CmdSetCullModeEXT_Null)(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) = 0;
    void vk_common_CmdSetCullModeEXT_Weak(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetFrontFaceEXT_Weak=vk_common_CmdSetFrontFaceEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetFrontFaceEXT=vk_common_CmdSetFrontFaceEXT_Weak")
    void (*vk_common_CmdSetFrontFaceEXT_Null)(VkCommandBuffer commandBuffer, VkFrontFace frontFace) = 0;
    void vk_common_CmdSetFrontFaceEXT_Weak(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPrimitiveTopologyEXT_Weak=vk_common_CmdSetPrimitiveTopologyEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetPrimitiveTopologyEXT=vk_common_CmdSetPrimitiveTopologyEXT_Weak")
    void (*vk_common_CmdSetPrimitiveTopologyEXT_Null)(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) = 0;
    void vk_common_CmdSetPrimitiveTopologyEXT_Weak(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewportWithCountEXT_Weak=vk_common_CmdSetViewportWithCountEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetViewportWithCountEXT=vk_common_CmdSetViewportWithCountEXT_Weak")
    void (*vk_common_CmdSetViewportWithCountEXT_Null)(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) = 0;
    void vk_common_CmdSetViewportWithCountEXT_Weak(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetScissorWithCountEXT_Weak=vk_common_CmdSetScissorWithCountEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetScissorWithCountEXT=vk_common_CmdSetScissorWithCountEXT_Weak")
    void (*vk_common_CmdSetScissorWithCountEXT_Null)(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) = 0;
    void vk_common_CmdSetScissorWithCountEXT_Weak(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBindVertexBuffers2EXT_Weak=vk_common_CmdBindVertexBuffers2EXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBindVertexBuffers2EXT=vk_common_CmdBindVertexBuffers2EXT_Weak")
    void (*vk_common_CmdBindVertexBuffers2EXT_Null)(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) = 0;
    void vk_common_CmdBindVertexBuffers2EXT_Weak(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthTestEnableEXT_Weak=vk_common_CmdSetDepthTestEnableEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthTestEnableEXT=vk_common_CmdSetDepthTestEnableEXT_Weak")
    void (*vk_common_CmdSetDepthTestEnableEXT_Null)(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) = 0;
    void vk_common_CmdSetDepthTestEnableEXT_Weak(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthWriteEnableEXT_Weak=vk_common_CmdSetDepthWriteEnableEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthWriteEnableEXT=vk_common_CmdSetDepthWriteEnableEXT_Weak")
    void (*vk_common_CmdSetDepthWriteEnableEXT_Null)(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) = 0;
    void vk_common_CmdSetDepthWriteEnableEXT_Weak(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthCompareOpEXT_Weak=vk_common_CmdSetDepthCompareOpEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthCompareOpEXT=vk_common_CmdSetDepthCompareOpEXT_Weak")
    void (*vk_common_CmdSetDepthCompareOpEXT_Null)(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) = 0;
    void vk_common_CmdSetDepthCompareOpEXT_Weak(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthBoundsTestEnableEXT_Weak=vk_common_CmdSetDepthBoundsTestEnableEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetDepthBoundsTestEnableEXT=vk_common_CmdSetDepthBoundsTestEnableEXT_Weak")
    void (*vk_common_CmdSetDepthBoundsTestEnableEXT_Null)(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) = 0;
    void vk_common_CmdSetDepthBoundsTestEnableEXT_Weak(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilTestEnableEXT_Weak=vk_common_CmdSetStencilTestEnableEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilTestEnableEXT=vk_common_CmdSetStencilTestEnableEXT_Weak")
    void (*vk_common_CmdSetStencilTestEnableEXT_Null)(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) = 0;
    void vk_common_CmdSetStencilTestEnableEXT_Weak(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilOpEXT_Weak=vk_common_CmdSetStencilOpEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetStencilOpEXT=vk_common_CmdSetStencilOpEXT_Weak")
    void (*vk_common_CmdSetStencilOpEXT_Null)(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) = 0;
    void vk_common_CmdSetStencilOpEXT_Weak(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreatePrivateDataSlotEXT_Weak=vk_common_CreatePrivateDataSlotEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreatePrivateDataSlotEXT=vk_common_CreatePrivateDataSlotEXT_Weak")
    VkResult (*vk_common_CreatePrivateDataSlotEXT_Null)(VkDevice device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlotEXT* pPrivateDataSlot) = 0;
    VkResult vk_common_CreatePrivateDataSlotEXT_Weak(VkDevice device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlotEXT* pPrivateDataSlot);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlotEXT* pPrivateDataSlot) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_DestroyPrivateDataSlotEXT_Weak=vk_common_DestroyPrivateDataSlotEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_DestroyPrivateDataSlotEXT=vk_common_DestroyPrivateDataSlotEXT_Weak")
    void (*vk_common_DestroyPrivateDataSlotEXT_Null)(VkDevice device, VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks* pAllocator) = 0;
    void vk_common_DestroyPrivateDataSlotEXT_Weak(VkDevice device, VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks* pAllocator);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_DestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks* pAllocator) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_SetPrivateDataEXT_Weak=vk_common_SetPrivateDataEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_SetPrivateDataEXT=vk_common_SetPrivateDataEXT_Weak")
    VkResult (*vk_common_SetPrivateDataEXT_Null)(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data) = 0;
    VkResult vk_common_SetPrivateDataEXT_Weak(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_SetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetPrivateDataEXT_Weak=vk_common_GetPrivateDataEXT_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetPrivateDataEXT=vk_common_GetPrivateDataEXT_Weak")
    void (*vk_common_GetPrivateDataEXT_Null)(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t* pData) = 0;
    void vk_common_GetPrivateDataEXT_Weak(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t* pData);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t* pData) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBuffer2KHR_Weak=vk_common_CmdCopyBuffer2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBuffer2KHR=vk_common_CmdCopyBuffer2KHR_Weak")
    void (*vk_common_CmdCopyBuffer2KHR_Null)(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo) = 0;
    void vk_common_CmdCopyBuffer2KHR_Weak(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImage2KHR_Weak=vk_common_CmdCopyImage2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImage2KHR=vk_common_CmdCopyImage2KHR_Weak")
    void (*vk_common_CmdCopyImage2KHR_Null)(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo) = 0;
    void vk_common_CmdCopyImage2KHR_Weak(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdBlitImage2KHR_Weak=vk_common_CmdBlitImage2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdBlitImage2KHR=vk_common_CmdBlitImage2KHR_Weak")
    void (*vk_common_CmdBlitImage2KHR_Null)(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo) = 0;
    void vk_common_CmdBlitImage2KHR_Weak(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBufferToImage2KHR_Weak=vk_common_CmdCopyBufferToImage2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyBufferToImage2KHR=vk_common_CmdCopyBufferToImage2KHR_Weak")
    void (*vk_common_CmdCopyBufferToImage2KHR_Null)(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo) = 0;
    void vk_common_CmdCopyBufferToImage2KHR_Weak(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImageToBuffer2KHR_Weak=vk_common_CmdCopyImageToBuffer2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdCopyImageToBuffer2KHR=vk_common_CmdCopyImageToBuffer2KHR_Weak")
    void (*vk_common_CmdCopyImageToBuffer2KHR_Null)(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo) = 0;
    void vk_common_CmdCopyImageToBuffer2KHR_Weak(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdResolveImage2KHR_Weak=vk_common_CmdResolveImage2KHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdResolveImage2KHR=vk_common_CmdResolveImage2KHR_Weak")
    void (*vk_common_CmdResolveImage2KHR_Null)(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo) = 0;
    void vk_common_CmdResolveImage2KHR_Weak(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetFragmentShadingRateKHR_Weak=vk_common_CmdSetFragmentShadingRateKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetFragmentShadingRateKHR=vk_common_CmdSetFragmentShadingRateKHR_Weak")
    void (*vk_common_CmdSetFragmentShadingRateKHR_Null)(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) = 0;
    void vk_common_CmdSetFragmentShadingRateKHR_Weak(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetFragmentShadingRateKHR(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CmdSetFragmentShadingRateEnumNV_Weak=vk_common_CmdSetFragmentShadingRateEnumNV_Null")
    #pragma comment(linker, "/alternatename:vk_common_CmdSetFragmentShadingRateEnumNV=vk_common_CmdSetFragmentShadingRateEnumNV_Weak")
    void (*vk_common_CmdSetFragmentShadingRateEnumNV_Null)(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) = 0;
    void vk_common_CmdSetFragmentShadingRateEnumNV_Weak(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_CmdSetFragmentShadingRateEnumNV(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureBuildSizesKHR_Weak=vk_common_GetAccelerationStructureBuildSizesKHR_Null")
    #pragma comment(linker, "/alternatename:vk_common_GetAccelerationStructureBuildSizesKHR=vk_common_GetAccelerationStructureBuildSizesKHR_Weak")
    void (*vk_common_GetAccelerationStructureBuildSizesKHR_Null)(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkAccelerationStructureBuildGeometryInfoKHR*  pBuildInfo, const uint32_t*  pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR*           pSizeInfo) = 0;
    void vk_common_GetAccelerationStructureBuildSizesKHR_Weak(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkAccelerationStructureBuildGeometryInfoKHR*  pBuildInfo, const uint32_t*  pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR*           pSizeInfo);
#else
    VKAPI_ATTR void VKAPI_CALL vk_common_GetAccelerationStructureBuildSizesKHR(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkAccelerationStructureBuildGeometryInfoKHR*  pBuildInfo, const uint32_t*  pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR*           pSizeInfo) __attribute__ ((weak));
#endif
#ifdef _MSC_VER
    #pragma comment(linker, "/alternatename:vk_common_CreateDmaBufImageINTEL_Weak=vk_common_CreateDmaBufImageINTEL_Null")
    #pragma comment(linker, "/alternatename:vk_common_CreateDmaBufImageINTEL=vk_common_CreateDmaBufImageINTEL_Weak")
    VkResult (*vk_common_CreateDmaBufImageINTEL_Null)(VkDevice device, const VkDmaBufImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMem, VkImage* pImage) = 0;
    VkResult vk_common_CreateDmaBufImageINTEL_Weak(VkDevice device, const VkDmaBufImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMem, VkImage* pImage);
#else
    VKAPI_ATTR VkResult VKAPI_CALL vk_common_CreateDmaBufImageINTEL(VkDevice device, const VkDmaBufImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMem, VkImage* pImage) __attribute__ ((weak));
#endif

const struct vk_device_entrypoint_table vk_common_device_entrypoints = {
    .GetDeviceProcAddr = vk_common_GetDeviceProcAddr,
    .DestroyDevice = vk_common_DestroyDevice,
    .GetDeviceQueue = vk_common_GetDeviceQueue,
    .QueueSubmit = vk_common_QueueSubmit,
    .QueueWaitIdle = vk_common_QueueWaitIdle,
    .DeviceWaitIdle = vk_common_DeviceWaitIdle,
    .AllocateMemory = vk_common_AllocateMemory,
    .FreeMemory = vk_common_FreeMemory,
    .MapMemory = vk_common_MapMemory,
    .UnmapMemory = vk_common_UnmapMemory,
    .FlushMappedMemoryRanges = vk_common_FlushMappedMemoryRanges,
    .InvalidateMappedMemoryRanges = vk_common_InvalidateMappedMemoryRanges,
    .GetDeviceMemoryCommitment = vk_common_GetDeviceMemoryCommitment,
    .GetBufferMemoryRequirements = vk_common_GetBufferMemoryRequirements,
    .BindBufferMemory = vk_common_BindBufferMemory,
    .GetImageMemoryRequirements = vk_common_GetImageMemoryRequirements,
    .BindImageMemory = vk_common_BindImageMemory,
    .GetImageSparseMemoryRequirements = vk_common_GetImageSparseMemoryRequirements,
    .QueueBindSparse = vk_common_QueueBindSparse,
    .CreateFence = vk_common_CreateFence,
    .DestroyFence = vk_common_DestroyFence,
    .ResetFences = vk_common_ResetFences,
    .GetFenceStatus = vk_common_GetFenceStatus,
    .WaitForFences = vk_common_WaitForFences,
    .CreateSemaphore = vk_common_CreateSemaphore,
    .DestroySemaphore = vk_common_DestroySemaphore,
    .CreateEvent = vk_common_CreateEvent,
    .DestroyEvent = vk_common_DestroyEvent,
    .GetEventStatus = vk_common_GetEventStatus,
    .SetEvent = vk_common_SetEvent,
    .ResetEvent = vk_common_ResetEvent,
    .CreateQueryPool = vk_common_CreateQueryPool,
    .DestroyQueryPool = vk_common_DestroyQueryPool,
    .GetQueryPoolResults = vk_common_GetQueryPoolResults,
    .ResetQueryPool = vk_common_ResetQueryPool,
    .ResetQueryPoolEXT = vk_common_ResetQueryPoolEXT,
    .CreateBuffer = vk_common_CreateBuffer,
    .DestroyBuffer = vk_common_DestroyBuffer,
    .CreateBufferView = vk_common_CreateBufferView,
    .DestroyBufferView = vk_common_DestroyBufferView,
    .CreateImage = vk_common_CreateImage,
    .DestroyImage = vk_common_DestroyImage,
    .GetImageSubresourceLayout = vk_common_GetImageSubresourceLayout,
    .CreateImageView = vk_common_CreateImageView,
    .DestroyImageView = vk_common_DestroyImageView,
    .CreateShaderModule = vk_common_CreateShaderModule,
    .DestroyShaderModule = vk_common_DestroyShaderModule,
    .CreatePipelineCache = vk_common_CreatePipelineCache,
    .DestroyPipelineCache = vk_common_DestroyPipelineCache,
    .GetPipelineCacheData = vk_common_GetPipelineCacheData,
    .MergePipelineCaches = vk_common_MergePipelineCaches,
    .CreateGraphicsPipelines = vk_common_CreateGraphicsPipelines,
    .CreateComputePipelines = vk_common_CreateComputePipelines,
    .DestroyPipeline = vk_common_DestroyPipeline,
    .CreatePipelineLayout = vk_common_CreatePipelineLayout,
    .DestroyPipelineLayout = vk_common_DestroyPipelineLayout,
    .CreateSampler = vk_common_CreateSampler,
    .DestroySampler = vk_common_DestroySampler,
    .CreateDescriptorSetLayout = vk_common_CreateDescriptorSetLayout,
    .DestroyDescriptorSetLayout = vk_common_DestroyDescriptorSetLayout,
    .CreateDescriptorPool = vk_common_CreateDescriptorPool,
    .DestroyDescriptorPool = vk_common_DestroyDescriptorPool,
    .ResetDescriptorPool = vk_common_ResetDescriptorPool,
    .AllocateDescriptorSets = vk_common_AllocateDescriptorSets,
    .FreeDescriptorSets = vk_common_FreeDescriptorSets,
    .UpdateDescriptorSets = vk_common_UpdateDescriptorSets,
    .CreateFramebuffer = vk_common_CreateFramebuffer,
    .DestroyFramebuffer = vk_common_DestroyFramebuffer,
    .CreateRenderPass = vk_common_CreateRenderPass,
    .DestroyRenderPass = vk_common_DestroyRenderPass,
    .GetRenderAreaGranularity = vk_common_GetRenderAreaGranularity,
    .CreateCommandPool = vk_common_CreateCommandPool,
    .DestroyCommandPool = vk_common_DestroyCommandPool,
    .ResetCommandPool = vk_common_ResetCommandPool,
    .AllocateCommandBuffers = vk_common_AllocateCommandBuffers,
    .FreeCommandBuffers = vk_common_FreeCommandBuffers,
    .BeginCommandBuffer = vk_common_BeginCommandBuffer,
    .EndCommandBuffer = vk_common_EndCommandBuffer,
    .ResetCommandBuffer = vk_common_ResetCommandBuffer,
    .CmdBindPipeline = vk_common_CmdBindPipeline,
    .CmdSetViewport = vk_common_CmdSetViewport,
    .CmdSetScissor = vk_common_CmdSetScissor,
    .CmdSetLineWidth = vk_common_CmdSetLineWidth,
    .CmdSetDepthBias = vk_common_CmdSetDepthBias,
    .CmdSetBlendConstants = vk_common_CmdSetBlendConstants,
    .CmdSetDepthBounds = vk_common_CmdSetDepthBounds,
    .CmdSetStencilCompareMask = vk_common_CmdSetStencilCompareMask,
    .CmdSetStencilWriteMask = vk_common_CmdSetStencilWriteMask,
    .CmdSetStencilReference = vk_common_CmdSetStencilReference,
    .CmdBindDescriptorSets = vk_common_CmdBindDescriptorSets,
    .CmdBindIndexBuffer = vk_common_CmdBindIndexBuffer,
    .CmdBindVertexBuffers = vk_common_CmdBindVertexBuffers,
    .CmdDraw = vk_common_CmdDraw,
    .CmdDrawIndexed = vk_common_CmdDrawIndexed,
    .CmdDrawIndirect = vk_common_CmdDrawIndirect,
    .CmdDrawIndexedIndirect = vk_common_CmdDrawIndexedIndirect,
    .CmdDispatch = vk_common_CmdDispatch,
    .CmdDispatchIndirect = vk_common_CmdDispatchIndirect,
    .CmdCopyBuffer = vk_common_CmdCopyBuffer,
    .CmdCopyImage = vk_common_CmdCopyImage,
    .CmdBlitImage = vk_common_CmdBlitImage,
    .CmdCopyBufferToImage = vk_common_CmdCopyBufferToImage,
    .CmdCopyImageToBuffer = vk_common_CmdCopyImageToBuffer,
    .CmdUpdateBuffer = vk_common_CmdUpdateBuffer,
    .CmdFillBuffer = vk_common_CmdFillBuffer,
    .CmdClearColorImage = vk_common_CmdClearColorImage,
    .CmdClearDepthStencilImage = vk_common_CmdClearDepthStencilImage,
    .CmdClearAttachments = vk_common_CmdClearAttachments,
    .CmdResolveImage = vk_common_CmdResolveImage,
    .CmdSetEvent = vk_common_CmdSetEvent,
    .CmdResetEvent = vk_common_CmdResetEvent,
    .CmdWaitEvents = vk_common_CmdWaitEvents,
    .CmdPipelineBarrier = vk_common_CmdPipelineBarrier,
    .CmdBeginQuery = vk_common_CmdBeginQuery,
    .CmdEndQuery = vk_common_CmdEndQuery,
    .CmdBeginConditionalRenderingEXT = vk_common_CmdBeginConditionalRenderingEXT,
    .CmdEndConditionalRenderingEXT = vk_common_CmdEndConditionalRenderingEXT,
    .CmdResetQueryPool = vk_common_CmdResetQueryPool,
    .CmdWriteTimestamp = vk_common_CmdWriteTimestamp,
    .CmdCopyQueryPoolResults = vk_common_CmdCopyQueryPoolResults,
    .CmdPushConstants = vk_common_CmdPushConstants,
    .CmdBeginRenderPass = vk_common_CmdBeginRenderPass,
    .CmdNextSubpass = vk_common_CmdNextSubpass,
    .CmdEndRenderPass = vk_common_CmdEndRenderPass,
    .CmdExecuteCommands = vk_common_CmdExecuteCommands,
    .CreateSharedSwapchainsKHR = vk_common_CreateSharedSwapchainsKHR,
    .CreateSwapchainKHR = vk_common_CreateSwapchainKHR,
    .DestroySwapchainKHR = vk_common_DestroySwapchainKHR,
    .GetSwapchainImagesKHR = vk_common_GetSwapchainImagesKHR,
    .AcquireNextImageKHR = vk_common_AcquireNextImageKHR,
    .QueuePresentKHR = vk_common_QueuePresentKHR,
    .DebugMarkerSetObjectNameEXT = vk_common_DebugMarkerSetObjectNameEXT,
    .DebugMarkerSetObjectTagEXT = vk_common_DebugMarkerSetObjectTagEXT,
    .CmdDebugMarkerBeginEXT = vk_common_CmdDebugMarkerBeginEXT,
    .CmdDebugMarkerEndEXT = vk_common_CmdDebugMarkerEndEXT,
    .CmdDebugMarkerInsertEXT = vk_common_CmdDebugMarkerInsertEXT,
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetMemoryWin32HandleNV = vk_common_GetMemoryWin32HandleNV,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .CmdExecuteGeneratedCommandsNV = vk_common_CmdExecuteGeneratedCommandsNV,
    .CmdPreprocessGeneratedCommandsNV = vk_common_CmdPreprocessGeneratedCommandsNV,
    .CmdBindPipelineShaderGroupNV = vk_common_CmdBindPipelineShaderGroupNV,
    .GetGeneratedCommandsMemoryRequirementsNV = vk_common_GetGeneratedCommandsMemoryRequirementsNV,
    .CreateIndirectCommandsLayoutNV = vk_common_CreateIndirectCommandsLayoutNV,
    .DestroyIndirectCommandsLayoutNV = vk_common_DestroyIndirectCommandsLayoutNV,
    .CmdPushDescriptorSetKHR = vk_common_CmdPushDescriptorSetKHR,
    .TrimCommandPool = vk_common_TrimCommandPool,
    .TrimCommandPoolKHR = vk_common_TrimCommandPoolKHR,
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetMemoryWin32HandleKHR = vk_common_GetMemoryWin32HandleKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetMemoryWin32HandlePropertiesKHR = vk_common_GetMemoryWin32HandlePropertiesKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .GetMemoryFdKHR = vk_common_GetMemoryFdKHR,
    .GetMemoryFdPropertiesKHR = vk_common_GetMemoryFdPropertiesKHR,
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetSemaphoreWin32HandleKHR = vk_common_GetSemaphoreWin32HandleKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .ImportSemaphoreWin32HandleKHR = vk_common_ImportSemaphoreWin32HandleKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .GetSemaphoreFdKHR = vk_common_GetSemaphoreFdKHR,
    .ImportSemaphoreFdKHR = vk_common_ImportSemaphoreFdKHR,
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetFenceWin32HandleKHR = vk_common_GetFenceWin32HandleKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .ImportFenceWin32HandleKHR = vk_common_ImportFenceWin32HandleKHR,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .GetFenceFdKHR = vk_common_GetFenceFdKHR,
    .ImportFenceFdKHR = vk_common_ImportFenceFdKHR,
    .DisplayPowerControlEXT = vk_common_DisplayPowerControlEXT,
    .RegisterDeviceEventEXT = vk_common_RegisterDeviceEventEXT,
    .RegisterDisplayEventEXT = vk_common_RegisterDisplayEventEXT,
    .GetSwapchainCounterEXT = vk_common_GetSwapchainCounterEXT,
    .GetDeviceGroupPeerMemoryFeatures = vk_common_GetDeviceGroupPeerMemoryFeatures,
    .GetDeviceGroupPeerMemoryFeaturesKHR = vk_common_GetDeviceGroupPeerMemoryFeaturesKHR,
    .BindBufferMemory2 = vk_common_BindBufferMemory2,
    .BindBufferMemory2KHR = vk_common_BindBufferMemory2KHR,
    .BindImageMemory2 = vk_common_BindImageMemory2,
    .BindImageMemory2KHR = vk_common_BindImageMemory2KHR,
    .CmdSetDeviceMask = vk_common_CmdSetDeviceMask,
    .CmdSetDeviceMaskKHR = vk_common_CmdSetDeviceMaskKHR,
    .GetDeviceGroupPresentCapabilitiesKHR = vk_common_GetDeviceGroupPresentCapabilitiesKHR,
    .GetDeviceGroupSurfacePresentModesKHR = vk_common_GetDeviceGroupSurfacePresentModesKHR,
    .AcquireNextImage2KHR = vk_common_AcquireNextImage2KHR,
    .CmdDispatchBase = vk_common_CmdDispatchBase,
    .CmdDispatchBaseKHR = vk_common_CmdDispatchBaseKHR,
    .CreateDescriptorUpdateTemplate = vk_common_CreateDescriptorUpdateTemplate,
    .CreateDescriptorUpdateTemplateKHR = vk_common_CreateDescriptorUpdateTemplateKHR,
    .DestroyDescriptorUpdateTemplate = vk_common_DestroyDescriptorUpdateTemplate,
    .DestroyDescriptorUpdateTemplateKHR = vk_common_DestroyDescriptorUpdateTemplateKHR,
    .UpdateDescriptorSetWithTemplate = vk_common_UpdateDescriptorSetWithTemplate,
    .UpdateDescriptorSetWithTemplateKHR = vk_common_UpdateDescriptorSetWithTemplateKHR,
    .CmdPushDescriptorSetWithTemplateKHR = vk_common_CmdPushDescriptorSetWithTemplateKHR,
    .SetHdrMetadataEXT = vk_common_SetHdrMetadataEXT,
    .GetSwapchainStatusKHR = vk_common_GetSwapchainStatusKHR,
    .GetRefreshCycleDurationGOOGLE = vk_common_GetRefreshCycleDurationGOOGLE,
    .GetPastPresentationTimingGOOGLE = vk_common_GetPastPresentationTimingGOOGLE,
    .CmdSetViewportWScalingNV = vk_common_CmdSetViewportWScalingNV,
    .CmdSetDiscardRectangleEXT = vk_common_CmdSetDiscardRectangleEXT,
    .CmdSetSampleLocationsEXT = vk_common_CmdSetSampleLocationsEXT,
    .GetBufferMemoryRequirements2 = vk_common_GetBufferMemoryRequirements2,
    .GetBufferMemoryRequirements2KHR = vk_common_GetBufferMemoryRequirements2KHR,
    .GetImageMemoryRequirements2 = vk_common_GetImageMemoryRequirements2,
    .GetImageMemoryRequirements2KHR = vk_common_GetImageMemoryRequirements2KHR,
    .GetImageSparseMemoryRequirements2 = vk_common_GetImageSparseMemoryRequirements2,
    .GetImageSparseMemoryRequirements2KHR = vk_common_GetImageSparseMemoryRequirements2KHR,
    .CreateSamplerYcbcrConversion = vk_common_CreateSamplerYcbcrConversion,
    .CreateSamplerYcbcrConversionKHR = vk_common_CreateSamplerYcbcrConversionKHR,
    .DestroySamplerYcbcrConversion = vk_common_DestroySamplerYcbcrConversion,
    .DestroySamplerYcbcrConversionKHR = vk_common_DestroySamplerYcbcrConversionKHR,
    .GetDeviceQueue2 = vk_common_GetDeviceQueue2,
    .CreateValidationCacheEXT = vk_common_CreateValidationCacheEXT,
    .DestroyValidationCacheEXT = vk_common_DestroyValidationCacheEXT,
    .GetValidationCacheDataEXT = vk_common_GetValidationCacheDataEXT,
    .MergeValidationCachesEXT = vk_common_MergeValidationCachesEXT,
    .GetDescriptorSetLayoutSupport = vk_common_GetDescriptorSetLayoutSupport,
    .GetDescriptorSetLayoutSupportKHR = vk_common_GetDescriptorSetLayoutSupportKHR,
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .GetSwapchainGrallocUsageANDROID = vk_common_GetSwapchainGrallocUsageANDROID,
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .GetSwapchainGrallocUsage2ANDROID = vk_common_GetSwapchainGrallocUsage2ANDROID,
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .AcquireImageANDROID = vk_common_AcquireImageANDROID,
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .QueueSignalReleaseImageANDROID = vk_common_QueueSignalReleaseImageANDROID,
#endif // VK_USE_PLATFORM_ANDROID_KHR
    .GetShaderInfoAMD = vk_common_GetShaderInfoAMD,
    .SetLocalDimmingAMD = vk_common_SetLocalDimmingAMD,
    .GetCalibratedTimestampsEXT = vk_common_GetCalibratedTimestampsEXT,
    .SetDebugUtilsObjectNameEXT = vk_common_SetDebugUtilsObjectNameEXT,
    .SetDebugUtilsObjectTagEXT = vk_common_SetDebugUtilsObjectTagEXT,
    .QueueBeginDebugUtilsLabelEXT = vk_common_QueueBeginDebugUtilsLabelEXT,
    .QueueEndDebugUtilsLabelEXT = vk_common_QueueEndDebugUtilsLabelEXT,
    .QueueInsertDebugUtilsLabelEXT = vk_common_QueueInsertDebugUtilsLabelEXT,
    .CmdBeginDebugUtilsLabelEXT = vk_common_CmdBeginDebugUtilsLabelEXT,
    .CmdEndDebugUtilsLabelEXT = vk_common_CmdEndDebugUtilsLabelEXT,
    .CmdInsertDebugUtilsLabelEXT = vk_common_CmdInsertDebugUtilsLabelEXT,
    .GetMemoryHostPointerPropertiesEXT = vk_common_GetMemoryHostPointerPropertiesEXT,
    .CmdWriteBufferMarkerAMD = vk_common_CmdWriteBufferMarkerAMD,
    .CreateRenderPass2 = vk_common_CreateRenderPass2,
    .CreateRenderPass2KHR = vk_common_CreateRenderPass2KHR,
    .CmdBeginRenderPass2 = vk_common_CmdBeginRenderPass2,
    .CmdBeginRenderPass2KHR = vk_common_CmdBeginRenderPass2KHR,
    .CmdNextSubpass2 = vk_common_CmdNextSubpass2,
    .CmdNextSubpass2KHR = vk_common_CmdNextSubpass2KHR,
    .CmdEndRenderPass2 = vk_common_CmdEndRenderPass2,
    .CmdEndRenderPass2KHR = vk_common_CmdEndRenderPass2KHR,
    .GetSemaphoreCounterValue = vk_common_GetSemaphoreCounterValue,
    .GetSemaphoreCounterValueKHR = vk_common_GetSemaphoreCounterValueKHR,
    .WaitSemaphores = vk_common_WaitSemaphores,
    .WaitSemaphoresKHR = vk_common_WaitSemaphoresKHR,
    .SignalSemaphore = vk_common_SignalSemaphore,
    .SignalSemaphoreKHR = vk_common_SignalSemaphoreKHR,
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .GetAndroidHardwareBufferPropertiesANDROID = vk_common_GetAndroidHardwareBufferPropertiesANDROID,
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    .GetMemoryAndroidHardwareBufferANDROID = vk_common_GetMemoryAndroidHardwareBufferANDROID,
#endif // VK_USE_PLATFORM_ANDROID_KHR
    .CmdDrawIndirectCount = vk_common_CmdDrawIndirectCount,
    .CmdDrawIndirectCountKHR = vk_common_CmdDrawIndirectCountKHR,
    .CmdDrawIndirectCountAMD = vk_common_CmdDrawIndirectCountAMD,
    .CmdDrawIndexedIndirectCount = vk_common_CmdDrawIndexedIndirectCount,
    .CmdDrawIndexedIndirectCountKHR = vk_common_CmdDrawIndexedIndirectCountKHR,
    .CmdDrawIndexedIndirectCountAMD = vk_common_CmdDrawIndexedIndirectCountAMD,
    .CmdSetCheckpointNV = vk_common_CmdSetCheckpointNV,
    .GetQueueCheckpointDataNV = vk_common_GetQueueCheckpointDataNV,
    .CmdBindTransformFeedbackBuffersEXT = vk_common_CmdBindTransformFeedbackBuffersEXT,
    .CmdBeginTransformFeedbackEXT = vk_common_CmdBeginTransformFeedbackEXT,
    .CmdEndTransformFeedbackEXT = vk_common_CmdEndTransformFeedbackEXT,
    .CmdBeginQueryIndexedEXT = vk_common_CmdBeginQueryIndexedEXT,
    .CmdEndQueryIndexedEXT = vk_common_CmdEndQueryIndexedEXT,
    .CmdDrawIndirectByteCountEXT = vk_common_CmdDrawIndirectByteCountEXT,
    .CmdSetExclusiveScissorNV = vk_common_CmdSetExclusiveScissorNV,
    .CmdBindShadingRateImageNV = vk_common_CmdBindShadingRateImageNV,
    .CmdSetViewportShadingRatePaletteNV = vk_common_CmdSetViewportShadingRatePaletteNV,
    .CmdSetCoarseSampleOrderNV = vk_common_CmdSetCoarseSampleOrderNV,
    .CmdDrawMeshTasksNV = vk_common_CmdDrawMeshTasksNV,
    .CmdDrawMeshTasksIndirectNV = vk_common_CmdDrawMeshTasksIndirectNV,
    .CmdDrawMeshTasksIndirectCountNV = vk_common_CmdDrawMeshTasksIndirectCountNV,
    .CompileDeferredNV = vk_common_CompileDeferredNV,
    .CreateAccelerationStructureNV = vk_common_CreateAccelerationStructureNV,
    .DestroyAccelerationStructureKHR = vk_common_DestroyAccelerationStructureKHR,
    .DestroyAccelerationStructureNV = vk_common_DestroyAccelerationStructureNV,
    .GetAccelerationStructureMemoryRequirementsNV = vk_common_GetAccelerationStructureMemoryRequirementsNV,
    .BindAccelerationStructureMemoryNV = vk_common_BindAccelerationStructureMemoryNV,
    .CmdCopyAccelerationStructureNV = vk_common_CmdCopyAccelerationStructureNV,
    .CmdCopyAccelerationStructureKHR = vk_common_CmdCopyAccelerationStructureKHR,
    .CopyAccelerationStructureKHR = vk_common_CopyAccelerationStructureKHR,
    .CmdCopyAccelerationStructureToMemoryKHR = vk_common_CmdCopyAccelerationStructureToMemoryKHR,
    .CopyAccelerationStructureToMemoryKHR = vk_common_CopyAccelerationStructureToMemoryKHR,
    .CmdCopyMemoryToAccelerationStructureKHR = vk_common_CmdCopyMemoryToAccelerationStructureKHR,
    .CopyMemoryToAccelerationStructureKHR = vk_common_CopyMemoryToAccelerationStructureKHR,
    .CmdWriteAccelerationStructuresPropertiesKHR = vk_common_CmdWriteAccelerationStructuresPropertiesKHR,
    .CmdWriteAccelerationStructuresPropertiesNV = vk_common_CmdWriteAccelerationStructuresPropertiesNV,
    .CmdBuildAccelerationStructureNV = vk_common_CmdBuildAccelerationStructureNV,
    .WriteAccelerationStructuresPropertiesKHR = vk_common_WriteAccelerationStructuresPropertiesKHR,
    .CmdTraceRaysKHR = vk_common_CmdTraceRaysKHR,
    .CmdTraceRaysNV = vk_common_CmdTraceRaysNV,
    .GetRayTracingShaderGroupHandlesKHR = vk_common_GetRayTracingShaderGroupHandlesKHR,
    .GetRayTracingShaderGroupHandlesNV = vk_common_GetRayTracingShaderGroupHandlesNV,
    .GetRayTracingCaptureReplayShaderGroupHandlesKHR = vk_common_GetRayTracingCaptureReplayShaderGroupHandlesKHR,
    .GetAccelerationStructureHandleNV = vk_common_GetAccelerationStructureHandleNV,
    .CreateRayTracingPipelinesNV = vk_common_CreateRayTracingPipelinesNV,
    .CreateRayTracingPipelinesKHR = vk_common_CreateRayTracingPipelinesKHR,
    .CmdTraceRaysIndirectKHR = vk_common_CmdTraceRaysIndirectKHR,
    .GetDeviceAccelerationStructureCompatibilityKHR = vk_common_GetDeviceAccelerationStructureCompatibilityKHR,
    .GetRayTracingShaderGroupStackSizeKHR = vk_common_GetRayTracingShaderGroupStackSizeKHR,
    .CmdSetRayTracingPipelineStackSizeKHR = vk_common_CmdSetRayTracingPipelineStackSizeKHR,
    .GetImageViewHandleNVX = vk_common_GetImageViewHandleNVX,
    .GetImageViewAddressNVX = vk_common_GetImageViewAddressNVX,
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .GetDeviceGroupSurfacePresentModes2EXT = vk_common_GetDeviceGroupSurfacePresentModes2EXT,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .AcquireFullScreenExclusiveModeEXT = vk_common_AcquireFullScreenExclusiveModeEXT,
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    .ReleaseFullScreenExclusiveModeEXT = vk_common_ReleaseFullScreenExclusiveModeEXT,
#endif // VK_USE_PLATFORM_WIN32_KHR
    .AcquireProfilingLockKHR = vk_common_AcquireProfilingLockKHR,
    .ReleaseProfilingLockKHR = vk_common_ReleaseProfilingLockKHR,
    .GetImageDrmFormatModifierPropertiesEXT = vk_common_GetImageDrmFormatModifierPropertiesEXT,
    .GetBufferOpaqueCaptureAddress = vk_common_GetBufferOpaqueCaptureAddress,
    .GetBufferOpaqueCaptureAddressKHR = vk_common_GetBufferOpaqueCaptureAddressKHR,
    .GetBufferDeviceAddress = vk_common_GetBufferDeviceAddress,
    .GetBufferDeviceAddressKHR = vk_common_GetBufferDeviceAddressKHR,
    .GetBufferDeviceAddressEXT = vk_common_GetBufferDeviceAddressEXT,
    .InitializePerformanceApiINTEL = vk_common_InitializePerformanceApiINTEL,
    .UninitializePerformanceApiINTEL = vk_common_UninitializePerformanceApiINTEL,
    .CmdSetPerformanceMarkerINTEL = vk_common_CmdSetPerformanceMarkerINTEL,
    .CmdSetPerformanceStreamMarkerINTEL = vk_common_CmdSetPerformanceStreamMarkerINTEL,
    .CmdSetPerformanceOverrideINTEL = vk_common_CmdSetPerformanceOverrideINTEL,
    .AcquirePerformanceConfigurationINTEL = vk_common_AcquirePerformanceConfigurationINTEL,
    .ReleasePerformanceConfigurationINTEL = vk_common_ReleasePerformanceConfigurationINTEL,
    .QueueSetPerformanceConfigurationINTEL = vk_common_QueueSetPerformanceConfigurationINTEL,
    .GetPerformanceParameterINTEL = vk_common_GetPerformanceParameterINTEL,
    .GetDeviceMemoryOpaqueCaptureAddress = vk_common_GetDeviceMemoryOpaqueCaptureAddress,
    .GetDeviceMemoryOpaqueCaptureAddressKHR = vk_common_GetDeviceMemoryOpaqueCaptureAddressKHR,
    .GetPipelineExecutablePropertiesKHR = vk_common_GetPipelineExecutablePropertiesKHR,
    .GetPipelineExecutableStatisticsKHR = vk_common_GetPipelineExecutableStatisticsKHR,
    .GetPipelineExecutableInternalRepresentationsKHR = vk_common_GetPipelineExecutableInternalRepresentationsKHR,
    .CmdSetLineStippleEXT = vk_common_CmdSetLineStippleEXT,
    .CreateAccelerationStructureKHR = vk_common_CreateAccelerationStructureKHR,
    .CmdBuildAccelerationStructuresKHR = vk_common_CmdBuildAccelerationStructuresKHR,
    .CmdBuildAccelerationStructuresIndirectKHR = vk_common_CmdBuildAccelerationStructuresIndirectKHR,
    .BuildAccelerationStructuresKHR = vk_common_BuildAccelerationStructuresKHR,
    .GetAccelerationStructureDeviceAddressKHR = vk_common_GetAccelerationStructureDeviceAddressKHR,
    .CreateDeferredOperationKHR = vk_common_CreateDeferredOperationKHR,
    .DestroyDeferredOperationKHR = vk_common_DestroyDeferredOperationKHR,
    .GetDeferredOperationMaxConcurrencyKHR = vk_common_GetDeferredOperationMaxConcurrencyKHR,
    .GetDeferredOperationResultKHR = vk_common_GetDeferredOperationResultKHR,
    .DeferredOperationJoinKHR = vk_common_DeferredOperationJoinKHR,
    .CmdSetCullModeEXT = vk_common_CmdSetCullModeEXT,
    .CmdSetFrontFaceEXT = vk_common_CmdSetFrontFaceEXT,
    .CmdSetPrimitiveTopologyEXT = vk_common_CmdSetPrimitiveTopologyEXT,
    .CmdSetViewportWithCountEXT = vk_common_CmdSetViewportWithCountEXT,
    .CmdSetScissorWithCountEXT = vk_common_CmdSetScissorWithCountEXT,
    .CmdBindVertexBuffers2EXT = vk_common_CmdBindVertexBuffers2EXT,
    .CmdSetDepthTestEnableEXT = vk_common_CmdSetDepthTestEnableEXT,
    .CmdSetDepthWriteEnableEXT = vk_common_CmdSetDepthWriteEnableEXT,
    .CmdSetDepthCompareOpEXT = vk_common_CmdSetDepthCompareOpEXT,
    .CmdSetDepthBoundsTestEnableEXT = vk_common_CmdSetDepthBoundsTestEnableEXT,
    .CmdSetStencilTestEnableEXT = vk_common_CmdSetStencilTestEnableEXT,
    .CmdSetStencilOpEXT = vk_common_CmdSetStencilOpEXT,
    .CreatePrivateDataSlotEXT = vk_common_CreatePrivateDataSlotEXT,
    .DestroyPrivateDataSlotEXT = vk_common_DestroyPrivateDataSlotEXT,
    .SetPrivateDataEXT = vk_common_SetPrivateDataEXT,
    .GetPrivateDataEXT = vk_common_GetPrivateDataEXT,
    .CmdCopyBuffer2KHR = vk_common_CmdCopyBuffer2KHR,
    .CmdCopyImage2KHR = vk_common_CmdCopyImage2KHR,
    .CmdBlitImage2KHR = vk_common_CmdBlitImage2KHR,
    .CmdCopyBufferToImage2KHR = vk_common_CmdCopyBufferToImage2KHR,
    .CmdCopyImageToBuffer2KHR = vk_common_CmdCopyImageToBuffer2KHR,
    .CmdResolveImage2KHR = vk_common_CmdResolveImage2KHR,
    .CmdSetFragmentShadingRateKHR = vk_common_CmdSetFragmentShadingRateKHR,
    .CmdSetFragmentShadingRateEnumNV = vk_common_CmdSetFragmentShadingRateEnumNV,
    .GetAccelerationStructureBuildSizesKHR = vk_common_GetAccelerationStructureBuildSizesKHR,
    .CreateDmaBufImageINTEL = vk_common_CreateDmaBufImageINTEL,
};

