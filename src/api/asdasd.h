// // not to include predefined api functions
// #define VK_NO_PROTOTYPES
// // minimize windows.h
// #define WIN32_LEAN_AND_MEAN
// #define GLFW_EXPOSE_NATIVE_WIN32
// #include "glfw3.h"
// #include "glfw3native.h"
// // VK_KHR_win32_surface extension
// #define VK_USE_PLATFORM_WIN32_KHR

// #include <vector>
// #include <windows.h>
// #include <vulkan.h>



// vulkan api function declarations
#define DECL_PROC(name) PFN_##name name

DECL_PROC(vkGetInstanceProcAddr);

DECL_PROC(vkCreateInstance);
DECL_PROC(vkEnumerateInstanceLayerProperties);
DECL_PROC(vkEnumerateInstanceExtensionProperties);

DECL_PROC(vkDestroyInstance);

DECL_PROC(vkEnumeratePhysicalDevices);
DECL_PROC(vkEnumerateDeviceExtensionProperties);
DECL_PROC(vkGetPhysicalDeviceProperties);
DECL_PROC(vkGetPhysicalDeviceFeatures);
DECL_PROC(vkGetPhysicalDeviceQueueFamilyProperties);
DECL_PROC(vkGetPhysicalDeviceMemoryProperties);
DECL_PROC(vkGetPhysicalDeviceFormatProperties);

DECL_PROC(vkGetDeviceProcAddr);
DECL_PROC(vkCreateDevice);

DECL_PROC(vkCreateDebugReportCallbackEXT);
DECL_PROC(vkDestroyDebugReportCallbackEXT);

DECL_PROC(vkCreateWin32SurfaceKHR);
DECL_PROC(vkGetPhysicalDeviceSurfaceSupportKHR);
DECL_PROC(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
DECL_PROC(vkGetPhysicalDeviceSurfaceFormatsKHR);
DECL_PROC(vkGetPhysicalDeviceSurfacePresentModesKHR);
DECL_PROC(vkDestroySurfaceKHR);

DECL_PROC(vkDeviceWaitIdle);
DECL_PROC(vkDestroyDevice);

DECL_PROC(vkGetDeviceQueue);
DECL_PROC(vkQueueSubmit);
DECL_PROC(vkQueuePresentKHR);
DECL_PROC(vkQueueWaitIdle);

DECL_PROC(vkCreateSwapchainKHR);
DECL_PROC(vkGetSwapchainImagesKHR);
DECL_PROC(vkAcquireNextImageKHR);
DECL_PROC(vkDestroySwapchainKHR);

DECL_PROC(vkCreateImage);
DECL_PROC(vkDestroyImage);

DECL_PROC(vkCreateImageView);
DECL_PROC(vkDestroyImageView);

DECL_PROC(vkCreateRenderPass);
DECL_PROC(vkDestroyRenderPass);

DECL_PROC(vkCreateFramebuffer);
DECL_PROC(vkDestroyFramebuffer);

DECL_PROC(vkBeginCommandBuffer);
DECL_PROC(vkCmdPipelineBarrier);
DECL_PROC(vkCmdClearColorImage);
DECL_PROC(vkCmdBeginRenderPass);
DECL_PROC(vkCmdBindPipeline);
DECL_PROC(vkCmdBindVertexBuffers);
DECL_PROC(vkCmdBindDescriptorSets);
DECL_PROC(vkCmdDraw);
DECL_PROC(vkCmdEndRenderPass);
DECL_PROC(vkEndCommandBuffer);
DECL_PROC(vkResetCommandBuffer);

DECL_PROC(vkCreateCommandPool);
DECL_PROC(vkAllocateCommandBuffers);
DECL_PROC(vkFreeCommandBuffers);
DECL_PROC(vkDestroyCommandPool);

DECL_PROC(vkCreateSemaphore);
DECL_PROC(vkDestroySemaphore);

DECL_PROC(vkCreateFence);
DECL_PROC(vkWaitForFences);
DECL_PROC(vkResetFences);
DECL_PROC(vkDestroyFence);

DECL_PROC(vkCreateShaderModule);
DECL_PROC(vkDestroyShaderModule);

DECL_PROC(vkCreatePipelineLayout);
DECL_PROC(vkDestroyPipelineLayout);

DECL_PROC(vkCreateGraphicsPipelines);
DECL_PROC(vkDestroyPipeline);

DECL_PROC(vkCreateBuffer);
DECL_PROC(vkGetBufferMemoryRequirements);
DECL_PROC(vkGetImageMemoryRequirements);
DECL_PROC(vkDestroyBuffer);

DECL_PROC(vkAllocateMemory);
DECL_PROC(vkBindBufferMemory);
DECL_PROC(vkMapMemory);
DECL_PROC(vkFlushMappedMemoryRanges);
DECL_PROC(vkUnmapMemory);
DECL_PROC(vkFreeMemory);
DECL_PROC(vkBindImageMemory);

DECL_PROC(vkCreateDescriptorPool);
DECL_PROC(vkDestroyDescriptorPool);

DECL_PROC(vkCreateDescriptorSetLayout);
DECL_PROC(vkUpdateDescriptorSets);
DECL_PROC(vkAllocateDescriptorSets);
DECL_PROC(vkDestroyDescriptorSetLayout);

#undef DECL_PROC



namespace XGK {

  namespace VULKAN {

    #ifdef DEBUG
      #define MACRO_CREATE_DEBUG_REPORT_CALLBACKS(instance)\
        initDebugReportCallbackCIEXT(&report_error_ci);\
        report_error_ci.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT;\
        report_error_ci.pfnCallback = &reportError;\
        vkCreateDebugReportCallbackEXT(instance, &report_error_ci, nullptr, &report_error);
        // \
        // initDebugReportCallbackCIEXT(&report_info_ci);\
        // report_info_ci.pfnCallback = &reportInfo;\
        // vkCreateDebugReportCallbackEXT(instance, &report_info_ci, nullptr, &report_info);\
        // \
        // initDebugReportCallbackCIEXT(&report_warn_ci);\
        // report_warn_ci.flags = VK_DEBUG_REPORT_WARNING_BIT_EXT;\
        // report_warn_ci.pfnCallback = &reportWarn;\
        // vkCreateDebugReportCallbackEXT(instance, &report_warn_ci, nullptr, &report_warn);\
        // \
        // initDebugReportCallbackCIEXT(&report_perf_ci);\
        // report_perf_ci.flags = VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;\
        // report_perf_ci.pfnCallback = &reportPerf;\
        // vkCreateDebugReportCallbackEXT(instance, &report_perf_ci, nullptr, &report_perf);\
        // \
        // initDebugReportCallbackCIEXT(&report_debug_ci);\
        // report_debug_ci.flags = VK_DEBUG_REPORT_DEBUG_BIT_EXT;\
        // report_debug_ci.pfnCallback = &reportDebug;\
        // vkCreateDebugReportCallbackEXT(instance, &report_debug_ci, nullptr, &report_debug);

      #define MACRO_DESTROY_DEBUG_REPORT_CALLBACKS(instance)\
        vkDestroyDebugReportCallbackEXT(instance, report_error, nullptr);
        // vkDestroyDebugReportCallbackEXT(instance, report_debug, nullptr);\
        // vkDestroyDebugReportCallbackEXT(instance, report_perf, nullptr);\
        // vkDestroyDebugReportCallbackEXT(instance, report_warn, nullptr);\
        // vkDestroyDebugReportCallbackEXT(instance, report_info, nullptr);

      VkDebugReportCallbackCreateInfoEXT
        report_error_ci = { 0 };
        // report_info_ci = { 0 },
        // report_warn_ci = { 0 },
        // report_perf_ci = { 0 },
        // report_debug_ci = { 0 };

      VkDebugReportCallbackEXT
        report_error = VK_NULL_HANDLE;
        // report_info = VK_NULL_HANDLE,
        // report_warn = VK_NULL_HANDLE,
        // report_perf = VK_NULL_HANDLE,
        // report_debug = VK_NULL_HANDLE;

      #define DEBUG_REPORT_ARGS \
        VkDebugReportFlagsEXT flags,\
        VkDebugReportObjectTypeEXT objectType,\
        uint64_t object,\
        size_t location,\
        int32_t messageCode,\
        const char* pLayerPrefix,\
        const char* pMessage,\
        void* pUserData

      void initDebugReportCallbackCIEXT (VkDebugReportCallbackCreateInfoEXT* info) {

        info->sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
        info->pNext = nullptr;
        info->flags = VK_DEBUG_REPORT_INFORMATION_BIT_EXT; // VkDebugReportFlagsEXT(3), VkDebugReportFlagBitsEXT(3)
        info->pfnCallback = nullptr;
        info->pUserData = nullptr;
      };

      VkBool32 reportError(DEBUG_REPORT_ARGS) {

        printf("VALIDATION LAYER ERROR: %s\n", pMessage);

        return VK_FALSE;
      };

      // VkBool32 reportInfo(DEBUG_REPORT_ARGS) {

      //   printf("VALIDATION LAYER INFORMATION: %s\n", pMessage);

      //   return VK_FALSE;
      // };

      // VkBool32 reportWarn(DEBUG_REPORT_ARGS) {

      //   printf("VALIDATION LAYER WARNING: %s\n", pMessage);

      //   return VK_FALSE;
      // };

      // VkBool32 reportPerf(DEBUG_REPORT_ARGS) {

      //   printf("VALIDATION LAYER PERFORMANCE WARNING: %s\n", pMessage);

      //   return VK_FALSE;
      // };

      // VkBool32 reportDebug(DEBUG_REPORT_ARGS) {

      //   printf("VALIDATION LAYER DEBUG: %s\n", pMessage);

      //   return VK_FALSE;
      // };

      #undef DEBUG_REPORT_ARGS
    #endif



    // struct Context {

    //   HMODULE hmodule_api;

    //   uint32_t count;

    //   std::vector<const char*> instance_layers;
    //   std::vector<const char*> instance_extensions;
    //   VkInstance instance;

    //   VkPhysicalDevice* physical_devices;
    //   VkQueueFamilyProperties* queue_family_props;
    //   VkPhysicalDeviceMemoryProperties mem_props;
    //   std::vector<float> queue_priorities;

    //   VkSurfaceKHR surface;
    //   VkBool32 surface_support;
    //   VkSurfaceCapabilitiesKHR surface_capabilities;
    //   VkSurfaceFormatKHR* surface_formats;

    //   std::vector<const char*> device_extensions;
    //   VkDevice device;
    //   VkQueue graphics_queue;
    //   VkQueue present_queue;

    //   VkSwapchainKHR swapchain;
    //   VkImage* swapchain_images;
    //   uint32_t swapchain_image_count;
    //   VkImageView* swapchain_image_views;

    //   VkAttachmentDescription
    //     color_attachment,
    //     color_attachment_resolve;
    //   VkAttachmentReference
    //     color_attachment_reference,
    //     color_attachment_resolve_reference;
    //   VkSubpassDescription subpass;
    //   VkSubpassDependency subpass_dependency;
    //   VkAttachmentDescription render_pass_attachments[2];
    //   VkRenderPass render_pass;
    //   VkImage* images;
    //   VkDeviceMemory* image_mem;
    //   VkImageView* image_views;
    //   VkFramebuffer* framebuffers;
    //   VkImageView* framebuffer_attachments;
    //   VkMemoryRequirements mem_reqs;
    //   uint32_t mem_type_index;

    //   VkViewport viewport;
    //   VkRect2D scissor;
    //   VkPipelineColorBlendAttachmentState color_blend_attachment_state;

    //   VkPipelineVertexInputStateCreateInfo default_pipeline_vertex_input_state_ci;
    //   VkPipelineInputAssemblyStateCreateInfo default_pipeline_input_assembly_state_ci;
    //   VkPipelineTessellationStateCreateInfo default_pipeline_tesselation_state_ci;
    //   VkPipelineViewportStateCreateInfo default_pipeline_viewport_state_ci;
    //   VkPipelineRasterizationStateCreateInfo default_pipeline_rasterization_state_ci;
    //   VkPipelineMultisampleStateCreateInfo default_pipeline_multisample_state_ci;
    //   VkPipelineDepthStencilStateCreateInfo default_pipeline_depth_stencil_state_ci;
    //   VkPipelineColorBlendStateCreateInfo default_pipeline_color_blend_state_ci;
    //   VkPipelineDynamicStateCreateInfo default_pipeline_dynamic_state_ci;

    //   VkFence* fences;
    //   VkSemaphore* image_available_semaphores;
    //   VkSemaphore* render_finished_semaphores;

    //   uint32_t* image_indices;

    //   VkPresentInfoKHR* present_i;
    // };

    void loadSharedLibrary (HMODULE* hmodule_api) {

      // free previously loaded api library
      FreeLibrary(*hmodule_api);

      *hmodule_api = LoadLibrary("vulkan-1.dll");
    };

    // vulkan api function definitions
    void loadGlobalFunctions (HMODULE hmodule_api) {

      vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) GetProcAddress(hmodule_api, "vkGetInstanceProcAddr");

      #define GET_PROC_ADDR(name) name = (PFN_##name) vkGetInstanceProcAddr(nullptr, #name)

      GET_PROC_ADDR(vkCreateInstance);
      GET_PROC_ADDR(vkEnumerateInstanceLayerProperties);
      GET_PROC_ADDR(vkEnumerateInstanceExtensionProperties);

      #undef GET_PROC_ADDR
    };

    void loadInstanceFunctions (VkInstance instance) {

      #define GET_PROC_ADDR(name) name = (PFN_##name) vkGetInstanceProcAddr(instance, #name)

      GET_PROC_ADDR(vkDestroyInstance);\

      GET_PROC_ADDR(vkEnumeratePhysicalDevices);
      GET_PROC_ADDR(vkGetPhysicalDeviceProperties);
      GET_PROC_ADDR(vkGetPhysicalDeviceFeatures);
      GET_PROC_ADDR(vkGetPhysicalDeviceQueueFamilyProperties);
      GET_PROC_ADDR(vkGetPhysicalDeviceMemoryProperties);
      GET_PROC_ADDR(vkGetPhysicalDeviceFormatProperties);

      GET_PROC_ADDR(vkGetDeviceProcAddr);
      GET_PROC_ADDR(vkCreateDevice);

      GET_PROC_ADDR(vkCreateDebugReportCallbackEXT);
      GET_PROC_ADDR(vkDestroyDebugReportCallbackEXT);

      GET_PROC_ADDR(vkCreateWin32SurfaceKHR);
      GET_PROC_ADDR(vkGetPhysicalDeviceSurfaceSupportKHR);
      GET_PROC_ADDR(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
      GET_PROC_ADDR(vkGetPhysicalDeviceSurfaceFormatsKHR);
      GET_PROC_ADDR(vkGetPhysicalDeviceSurfacePresentModesKHR);
      GET_PROC_ADDR(vkDestroySurfaceKHR);

      #undef GET_PROC_ADDR
    };

    void loadDeviceFunctions (VkDevice device) {

      #define GET_PROC_ADDR(name) name = (PFN_##name) vkGetDeviceProcAddr(device, #name)

      GET_PROC_ADDR(vkDeviceWaitIdle);
      GET_PROC_ADDR(vkDestroyDevice);

      GET_PROC_ADDR(vkGetDeviceQueue);
      GET_PROC_ADDR(vkQueueSubmit);
      GET_PROC_ADDR(vkQueuePresentKHR);
      GET_PROC_ADDR(vkQueueWaitIdle);

      GET_PROC_ADDR(vkCreateSwapchainKHR);
      GET_PROC_ADDR(vkGetSwapchainImagesKHR);
      GET_PROC_ADDR(vkAcquireNextImageKHR);
      GET_PROC_ADDR(vkDestroySwapchainKHR);

      GET_PROC_ADDR(vkCreateImage);
      GET_PROC_ADDR(vkDestroyImage);

      GET_PROC_ADDR(vkCreateImageView);
      GET_PROC_ADDR(vkDestroyImageView);

      GET_PROC_ADDR(vkCreateRenderPass);
      GET_PROC_ADDR(vkDestroyRenderPass);

      GET_PROC_ADDR(vkCreateFramebuffer);
      GET_PROC_ADDR(vkDestroyFramebuffer);

      GET_PROC_ADDR(vkBeginCommandBuffer);
      GET_PROC_ADDR(vkCmdPipelineBarrier);
      GET_PROC_ADDR(vkCmdClearColorImage);
      GET_PROC_ADDR(vkCmdBeginRenderPass);
      GET_PROC_ADDR(vkCmdBindPipeline);
      GET_PROC_ADDR(vkCmdBindVertexBuffers);
      GET_PROC_ADDR(vkCmdBindDescriptorSets);
      GET_PROC_ADDR(vkCmdDraw);
      GET_PROC_ADDR(vkCmdEndRenderPass);
      GET_PROC_ADDR(vkEndCommandBuffer);
      GET_PROC_ADDR(vkResetCommandBuffer);

      GET_PROC_ADDR(vkCreateCommandPool);
      GET_PROC_ADDR(vkAllocateCommandBuffers);
      GET_PROC_ADDR(vkFreeCommandBuffers);
      GET_PROC_ADDR(vkDestroyCommandPool);

      GET_PROC_ADDR(vkCreateSemaphore);
      GET_PROC_ADDR(vkDestroySemaphore);

      GET_PROC_ADDR(vkCreateFence);
      GET_PROC_ADDR(vkWaitForFences);
      GET_PROC_ADDR(vkResetFences);
      GET_PROC_ADDR(vkDestroyFence);

      GET_PROC_ADDR(vkCreateShaderModule);
      GET_PROC_ADDR(vkDestroyShaderModule);

      GET_PROC_ADDR(vkCreatePipelineLayout);
      GET_PROC_ADDR(vkDestroyPipelineLayout);

      GET_PROC_ADDR(vkCreateGraphicsPipelines);
      GET_PROC_ADDR(vkDestroyPipeline);

      GET_PROC_ADDR(vkCreateBuffer);
      GET_PROC_ADDR(vkGetBufferMemoryRequirements);
      GET_PROC_ADDR(vkGetImageMemoryRequirements);
      GET_PROC_ADDR(vkDestroyBuffer);

      GET_PROC_ADDR(vkAllocateMemory);
      GET_PROC_ADDR(vkBindBufferMemory);
      GET_PROC_ADDR(vkMapMemory);
      GET_PROC_ADDR(vkFlushMappedMemoryRanges);
      GET_PROC_ADDR(vkUnmapMemory);
      GET_PROC_ADDR(vkFreeMemory);
      GET_PROC_ADDR(vkBindImageMemory);

      GET_PROC_ADDR(vkCreateDescriptorPool);
      GET_PROC_ADDR(vkDestroyDescriptorPool);

      GET_PROC_ADDR(vkCreateDescriptorSetLayout);
      GET_PROC_ADDR(vkUpdateDescriptorSets);
      GET_PROC_ADDR(vkAllocateDescriptorSets);
      GET_PROC_ADDR(vkDestroyDescriptorSetLayout);

      #undef GET_PROC_ADDR
    };

    void initAppI (VkApplicationInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
      info->pNext = nullptr;
      info->pApplicationName = nullptr;
      info->applicationVersion = 0;
      info->pEngineName = nullptr;
      info->engineVersion = 0;
      info->apiVersion = VK_API_VERSION_1_0;
    };

    void initInstanceCI (VkInstanceCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0;
      info->pApplicationInfo = nullptr;
      info->enabledLayerCount = 0;
      info->ppEnabledLayerNames = nullptr;
      info->enabledExtensionCount = 0;
      info->ppEnabledExtensionNames = nullptr;
    };

    void initDeviceCI (VkDeviceCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0;
      info->queueCreateInfoCount = 0;
      info->pQueueCreateInfos = nullptr; // VkDeviceQueueCreateInfo(3)
      info->enabledLayerCount = 0;
      info->ppEnabledLayerNames = nullptr;
      info->enabledExtensionCount = 0;
      info->ppEnabledExtensionNames = nullptr;
      info->pEnabledFeatures = nullptr; // VkPhysicalDeviceFeatures(3)
    };

    void initDeviceQueueCI (VkDeviceQueueCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0;
      info->queueFamilyIndex = 0;
      info->queueCount = 0;
      info->pQueuePriorities = nullptr;
    };

    void initWin32SurfaceCI (VkWin32SurfaceCreateInfoKHR* info) {

      info->sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
      info->pNext = nullptr;
      info->flags = 0;
      info->hinstance = 0;
      info->hwnd = 0;
    };

    void initSwapchainCI (VkSwapchainCreateInfoKHR* info) {

      info->sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
      info->pNext = nullptr;
      info->flags = 0; // VkSwapchainCreateFlagsKHR(3), VkSwapchainCreateFlagBitsKHR(3)
      info->surface = VK_NULL_HANDLE;
      info->minImageCount = 1;
      info->imageFormat = VK_FORMAT_B8G8R8A8_UNORM; // VkFormat(3)
      info->imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR; // VkColorSpaceKHR(3)
      info->imageExtent.width = 0;
      info->imageExtent.height = 0;
      info->imageArrayLayers = 1;
      info->imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; // VkImageUsageFlags(3), VkImageUsageFlagBits(3)
      info->imageSharingMode = VK_SHARING_MODE_EXCLUSIVE; // VkSharingMode(3)
      info->queueFamilyIndexCount = 1;
      info->pQueueFamilyIndices = nullptr;
      info->preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR; // VkSurfaceTransformFlagBitsKHR(3)
      info->compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR; // VkCompositeAlphaFlagBitsKHR(3)
      info->presentMode = VK_PRESENT_MODE_FIFO_KHR; // VkPresentModeKHR(3)
      info->clipped = VK_TRUE;
      info->oldSwapchain = VK_NULL_HANDLE;
    };

    void initImageCI (VkImageCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkImageCreateFlags(3), VkImageCreateFlagBits(3)
      info->imageType = VK_IMAGE_TYPE_2D; // VkImageType(3)
      info->format = VK_FORMAT_B8G8R8A8_UNORM; // VkFormat(3)
      info->extent.width = 0;
      info->extent.height = 0;
      info->extent.depth = 1;
      info->mipLevels = 1;
      info->arrayLayers = 1;
      info->samples = VK_SAMPLE_COUNT_1_BIT; // VkSampleCountFlagBits(3)
      info->tiling = VK_IMAGE_TILING_OPTIMAL; // VkImageTiling(3)
      info->usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; // VkImageUsageFlags(3), VkImageUsageFlagBits(3)
      info->sharingMode = VK_SHARING_MODE_EXCLUSIVE; // VkSharingMode(3)
      info->queueFamilyIndexCount = 0;
      info->pQueueFamilyIndices = nullptr;
      info->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED; // VkImageLayout(3)
    };

    void initImageViewCI (VkImageViewCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkImageViewCreateFlags(3), VkImageViewCreateFlagBits(3)
      info->image = VK_NULL_HANDLE;
      info->viewType = VK_IMAGE_VIEW_TYPE_2D; // VkImageViewType(3)
      info->format = VK_FORMAT_B8G8R8A8_UNORM; // VkFormat(3)
      info->components.r = VK_COMPONENT_SWIZZLE_IDENTITY; // VkComponentMapping(3)
      info->components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
      info->components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
      info->components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
      info->subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT; // VkImageSubresourceRange(3), VkImageAspectFlags(3), VkImageAspectFlagBits(3)
      info->subresourceRange.baseMipLevel = 0;
      info->subresourceRange.levelCount = 1;
      info->subresourceRange.baseArrayLayer = 0;
      info->subresourceRange.layerCount = 1;
    };

    void initAttachDesc (VkAttachmentDescription* desc) {

      desc->flags = 0; // VkAttachmentDescriptionFlags(3), VkAttachmentDescriptionFlagBits(3)
      desc->format = VK_FORMAT_B8G8R8A8_UNORM; // VkFormat(3)
      desc->samples = VK_SAMPLE_COUNT_1_BIT; // VkSampleCountFlagBits(3)
      desc->loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE; // VkAttachmentLoadOp(3)
      desc->storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE; // VkAttachmentStoreOp(3)
      desc->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE; // VkAttachmentLoadOp(3)
      desc->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE; // VkAttachmentStoreOp(3)
      desc->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED; // VkImageLayout(3)
      desc->finalLayout = VK_IMAGE_LAYOUT_UNDEFINED; // VkImageLayout(3)
    };

    void initAttachRef (VkAttachmentReference* ref) {

      ref->attachment = 0;
      ref->layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL; // VkImageLayout(3)
    };

    void initSubpassDesc (VkSubpassDescription* desc) {

      desc->flags = 0; // VkSubpassDescriptionFlags(3), VkSubpassDescriptionFlagBits(3)
      desc->pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS; // VkPipelineBindPoint(3)
      desc->inputAttachmentCount = 0;
      desc->pInputAttachments = nullptr; // VkAttachmentReference(3)
      desc->colorAttachmentCount = 1;
      desc->pColorAttachments = nullptr; // VkAttachmentReference(3)
      desc->pResolveAttachments = nullptr; // // VkAttachmentReference(3)
      desc->pDepthStencilAttachment = nullptr; // VkAttachmentReference(3)
      desc->preserveAttachmentCount = 0;
      desc->pPreserveAttachments = nullptr;
    };

    void initSubpassDep (VkSubpassDependency* dep) {

      dep->srcSubpass = VK_SUBPASS_EXTERNAL;
      dep->dstSubpass = 0;
      dep->srcStageMask = 0; // VkPipelineStageFlags(3), VkPipelineStageFlagBits(3)
      dep->dstStageMask = 0; // VkPipelineStageFlags(3), VkPipelineStageFlagBits(3)
      dep->srcAccessMask = 0; // VkAccessFlags(3), VkAccessFlagBits(3)
      dep->dstAccessMask = 0; // VkAccessFlags(3), VkAccessFlagBits(3)
      dep->dependencyFlags = 0; // VkDependencyFlags(3), VkDependencyFlagBits(3)
    };

    void initRenderPassCI (VkRenderPassCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
      info->pNext = 0;
      info->flags = 0; // VkRenderPassCreateFlags(3)
      info->attachmentCount = 0;
      info->pAttachments = nullptr; // VkAttachmentDescription(3)
      info->subpassCount = 0;
      info->pSubpasses = nullptr; // VkSubpassDescription(3)
      info->dependencyCount = 0;
      info->pDependencies = nullptr; // VkSubpassDependency(3)
    };

    void initFramebufferCI (VkFramebufferCreateInfo* info) {
      info->sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0;
      info->renderPass = VK_NULL_HANDLE;
      info->attachmentCount = 1;
      info->pAttachments = nullptr;
      info->width = 0;
      info->height = 0;
      info->layers = 1;
    };

    void initMemAI (VkMemoryAllocateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
      info->pNext = nullptr;
      info->allocationSize = 0;
      info->memoryTypeIndex = 0;
    };

    inline VkMemoryAllocateInfo MemAI (void) {

      VkMemoryAllocateInfo info = { 0 };

      info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
      info.pNext = nullptr;
      info.allocationSize = 0;
      info.memoryTypeIndex = 0;

      return info;
    };

    inline VkDeviceMemory allocMem (VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator = nullptr) {

      VkDeviceMemory handle = VK_NULL_HANDLE;

      vkAllocateMemory(device, pAllocateInfo, pAllocator, &handle);

      return handle;
    };

    void initDescriptorSetLayoutBinding (VkDescriptorSetLayoutBinding* binding) {

      binding->binding = 0;
      binding->descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER; // VkDescriptorType(3)
      binding->descriptorCount = 0;
      binding->stageFlags = VK_SHADER_STAGE_VERTEX_BIT; // VkShaderStageFlags(3), VkShaderStageFlagBits(3)
      binding->pImmutableSamplers = nullptr;
    };

    void initDescriptorSetLayoutCI (VkDescriptorSetLayoutCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkDescriptorSetLayoutCreateFlags(3), VkDescriptorSetLayoutCreateFlagBits(3)
      info->bindingCount = 0;
      info->pBindings = nullptr;
    };

    void initDescriptorPoolSize (VkDescriptorPoolSize* size) {

      size->type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER; // VkDescriptorType(3)
      size->descriptorCount = 0;
    };

    void initDescriptorPoolCI (VkDescriptorPoolCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkDescriptorPoolCreateFlags(3), VkDescriptorPoolCreateFlagBits(3)
      info->maxSets = 0;
      info->poolSizeCount = 0;
      info->pPoolSizes = nullptr;
    };

    void initDescriptorSetAI (VkDescriptorSetAllocateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
      info->pNext = nullptr;
      info->descriptorPool = VK_NULL_HANDLE;
      info->descriptorSetCount = 0;
      info->pSetLayouts = nullptr;
    };

    void initBufferCI (VkBufferCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkBufferCreateFlags(3), VkBufferCreateFlagBits(3)
      info->size = 0;
      info->usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT; // VkBufferUsageFlags(3), VkBufferUsageFlagBits(3)
      info->sharingMode = VK_SHARING_MODE_EXCLUSIVE; // VkSharingMode(3)
      info->queueFamilyIndexCount = 0;
      info->pQueueFamilyIndices = nullptr;
    };

    inline VkBufferCreateInfo BufCI (void) {

      VkBufferCreateInfo info = { 0 };

      info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
      info.pNext = nullptr;
      info.flags = 0; // VkBufferCreateFlags(3), VkBufferCreateFlagBits(3)
      info.size = 0;
      info.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT; // VkBufferUsageFlags(3), VkBufferUsageFlagBits(3)
      info.sharingMode = VK_SHARING_MODE_EXCLUSIVE; // VkSharingMode(3)
      info.queueFamilyIndexCount = 0;
      info.pQueueFamilyIndices = nullptr;

      return info;
    };

    inline VkBuffer createBuffer (VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator = nullptr) {

      VkBuffer handle = VK_NULL_HANDLE;

      vkCreateBuffer(device, pCreateInfo, pAllocator, &handle);

      return handle;
    };

    // void* createUniformBuffer (VkBuffer &uniform_buffer, const uint64_t size) {

    //   initBufferCI(&vk_uniform_buffer_ci);
    //   vk_uniform_buffer_ci.size = sizeof(float) * 16;
    //   vk_uniform_buffer_ci.usage = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
    //   vkCreateBuffer(vk_device, &vk_uniform_buffer_ci, nullptr, uniform_buffer);

    //   vkGetBufferMemoryRequirements(vk_device, *uniform_buffer, &vk_mem_reqs);
    //   vk_mem_type_index = getVkMemTypeIndex(&vk_mem_props, &vk_mem_reqs, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
    //   initMemoryAI(&vk_uniform_buffer_mem_ai);
    //   vk_uniform_buffer_mem_ai.allocationSize = vk_mem_reqs.size;
    //   vk_uniform_buffer_mem_ai.memoryTypeIndex = vk_mem_type_index;
    //   vkAllocateMemory(vk_device, &vk_uniform_buffer_mem_ai, nullptr, &vk_uniform_buffer_mem);
    //   vkBindBufferMemory(vk_device, *uniform_buffer, vk_uniform_buffer_mem, 0);
    //   vkMapMemory(vk_device, vk_uniform_buffer_mem, 0, size, 0, &uniform_buffer_mem_addr);

    //   return uniform_buffer_mem_addr;
    // };

    void initDescriptorBufferI (VkDescriptorBufferInfo* info) {

      info->buffer = VK_NULL_HANDLE;
      info->offset = 0;
      info->range = VK_WHOLE_SIZE;
    };

    void initWriteDescriptorSet (VkWriteDescriptorSet* write) {

      write->sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
      write->pNext = nullptr;
      write->dstSet = VK_NULL_HANDLE;
      write->dstBinding = 0;
      write->dstArrayElement = 0;
      write->descriptorCount = 0;
      write->descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER; // VkDescriptorType(3)
      write->pImageInfo = nullptr;
      write->pBufferInfo = nullptr;
      write->pTexelBufferView = nullptr;
    };

    uint32_t getMemTypeIndex (VkMemoryRequirements mem_reqs, VkMemoryPropertyFlags flags) {

      uint32_t mem_type_count = context->mem_props.memoryTypeCount;

      for (uint32_t i = 0; i < mem_type_count; i++) {

        uint32_t match = (mem_reqs.memoryTypeBits & (1 << i)) && (context->mem_props.memoryTypes[i].propertyFlags & flags);

        if (match) {

          return i;
        };
      }

      return -1;
    };

    void initShaderModuleCI (VkShaderModuleCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkShaderModuleCreateFlags(3)
      info->codeSize = 0;
      info->pCode = nullptr;
    };

    void initPplShader (VkPipelineShaderStageCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineShaderStageCreateFlags(3), VkPipelineShaderStageCreateFlagBits(3)
      info->stage = VK_SHADER_STAGE_VERTEX_BIT; // VkShaderStageFlagBits(3)
      info->module = VK_NULL_HANDLE;
      info->pName = "main";
      info->pSpecializationInfo; // VkSpecializationInfo(3)
    };

    void initVertexInputBindingDesc (VkVertexInputBindingDescription* desc) {

      desc->binding = 0;
      desc->stride = 12;
      desc->inputRate = VK_VERTEX_INPUT_RATE_VERTEX; // VkVertexInputRate(3)
    };

    void initVertexInputAttribDesc (VkVertexInputAttributeDescription* desc) {

      desc->location = 0;
      desc->binding = 0;
      desc->format = VK_FORMAT_UNDEFINED; // VkFormat(3)
      desc->offset = 0;
    };

    void initPplVertex (VkPipelineVertexInputStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineVertexInputStateCreateFlags(3)
      info->vertexBindingDescriptionCount = 0;
      info->pVertexBindingDescriptions = nullptr; // VkVertexInputBindingDescription(3)
      info->vertexAttributeDescriptionCount = 0;
      info->pVertexAttributeDescriptions = nullptr; // VkVertexInputAttributeDescription(3)
    };

    void initPplInputAsm (VkPipelineInputAssemblyStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineInputAssemblyStateCreateFlags(3)
      info->topology = VK_PRIMITIVE_TOPOLOGY_POINT_LIST; // VkPrimitiveTopology(3)
      info->primitiveRestartEnable = VK_FALSE;
    };

    void initPplTessel (VkPipelineTessellationStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0;
      info->patchControlPoints = 0;
    };

    void initPplViewport (VkPipelineViewportStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineViewportStateCreateFlags(3)
      info->viewportCount = 0;
      info->pViewports = nullptr; // VkViewport(3)
      info->scissorCount = 0;
      info->pScissors = nullptr; // VkRect2D(3)
    };

    void initPplMultisample (VkPipelineMultisampleStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineMultisampleStateCreateFlags(3)
      info->rasterizationSamples = VK_SAMPLE_COUNT_1_BIT; // VkSampleCountFlagBits(3)
      info->sampleShadingEnable = VK_FALSE;
      info->minSampleShading = 0.0f;
      info->pSampleMask = nullptr;
      info->alphaToCoverageEnable = VK_FALSE;
      info->alphaToOneEnable = VK_FALSE;
    };

    void initPplRaster (VkPipelineRasterizationStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineRasterizationStateCreateFlags(3)
      info->depthClampEnable = VK_FALSE;
      info->rasterizerDiscardEnable = VK_FALSE;
      info->polygonMode = VK_POLYGON_MODE_FILL; // VkPolygonMode(3)
      info->cullMode = VK_CULL_MODE_NONE; // VkCullModeFlags(3), VkCullModeFlagBits(3)
      info->frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE; // VkFrontFace(3)
      info->depthBiasEnable = VK_FALSE;
      info->depthBiasConstantFactor = 0.0f;
      info->depthBiasClamp = 0.0f;
      info->depthBiasSlopeFactor = 0.0f;
      info->lineWidth = 0.0f;
    };

    void initStencilOpState (VkStencilOpState* state) {

      state->failOp = VK_STENCIL_OP_KEEP; // VkStencilOp(3)
      state->passOp = VK_STENCIL_OP_KEEP; // VkStencilOp(3)
      state->depthFailOp = VK_STENCIL_OP_KEEP; // VkStencilOp(3)
      state->compareOp = VK_COMPARE_OP_NEVER; // VkCompareOp(3)
      state->compareMask = 0;
      state->writeMask = 0;
      state->reference = 0;
    };

    void initPplDepthStenc (VkPipelineDepthStencilStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineDepthStencilStateCreateFlags(3)
      info->depthTestEnable = VK_FALSE;
      info->depthWriteEnable = VK_FALSE;
      info->depthCompareOp = VK_COMPARE_OP_NEVER; // VkCompareOp(3)
      info->depthBoundsTestEnable = VK_FALSE;
      info->stencilTestEnable = VK_FALSE;
      info->front = { 0 }; // VkStencilOpState(3)
      info->back = { 0 }; // VkStencilOpState(3)
      info->minDepthBounds = 0.0f;
      info->maxDepthBounds = 0.0f;
    };

    void initPplColorBlendAttachState (VkPipelineColorBlendAttachmentState* state) {

      state->blendEnable = VK_FALSE;
      state->srcColorBlendFactor = VK_BLEND_FACTOR_ZERO; // VkBlendFactor(3)
      state->dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // VkBlendFactor(3)
      state->colorBlendOp = VK_BLEND_OP_ADD; // VkBlendOp(3)
      state->srcAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // VkBlendFactor(3)
      state->dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // VkBlendFactor(3)
      state->alphaBlendOp = VK_BLEND_OP_ADD; // VkBlendOp(3)
      state->colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT; // VkColorComponentFlags(3), VkColorComponentFlagBits(3)
    };

    void initPplColorBlend (VkPipelineColorBlendStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineColorBlendStateCreateFlags(3)
      info->logicOpEnable = VK_FALSE;
      info->logicOp = VK_LOGIC_OP_CLEAR; // VkLogicOp(3)
      info->attachmentCount = 0;
      info->pAttachments = nullptr; // VkPipelineColorBlendAttachmentState(3)
      info->blendConstants[0] = 0.0f;
      info->blendConstants[1] = 0.0f;
      info->blendConstants[2] = 0.0f;
      info->blendConstants[3] = 0.0f;
    };

    void initPplDyn (VkPipelineDynamicStateCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineDynamicStateCreateFlags(3)
      info->dynamicStateCount = 0;
      info->pDynamicStates = nullptr; // VkDynamicState(3)
    };

    void initPplLayoutCI (VkPipelineLayoutCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineLayoutCreateFlags(3)
      info->setLayoutCount = 0;
      info->pSetLayouts = nullptr;
      info->pushConstantRangeCount = 0;
      info->pPushConstantRanges = nullptr; // VkPushConstantRange(3)
    };

    // void addDescriptorBinding (
    //   std::vector<VkDescriptorSetLayout>* descr_set_layouts,
    //   VkPipelineLayoutCreateInfo* info,
    //   uint32_t binding,
    //   VkDescriptorType descriptorType,
    //   uint32_t descriptorCount,
    //   VkShaderStageFlags stageFlags,
    //   const VkSampler* pImmutableSamplers
    // ) {

    //   VkDescriptorSetLayout set_layout = VK_NULL_HANDLE;

    //   VkDescriptorSetLayoutCreateInfo set_layout_ci = { 0 };

    //   VkDescriptorSetLayoutBinding binding = { 0 };
    //   binding->binding = binding;
    //   binding->descriptorType = descriptorType;
    //   binding->descriptorCount = descriptorCount;
    //   binding->stageFlags = stageFlags;
    //   binding->pImmutableSamplers = pImmutableSamplers;

    //   initDescriptorSetLayoutCI(&set_layout_ci);
    //   set_layout_ci.bindingCount = 1;
    //   set_layout_ci.pBindings = &binding;
    //   vkCreateDescriptorSetLayout(context.device, &set_layout_ci, nullptr, set_layout);

    //   descr_set_layouts->push_back(set_layout);

    //   info->setLayoutCount++;
    //   info->pSetLayouts = setLayouts->data();
    // };

    VkDescriptorSetLayoutBinding DescrSetLayoutBinding (
      uint32_t binding_,
      VkDescriptorType descriptorType,
      uint32_t descriptorCount,
      VkShaderStageFlags stageFlags,
      const VkSampler* pImmutableSamplers
    ) {

      VkDescriptorSetLayoutBinding binding = { 0 };

      binding.binding = binding_;
      binding.descriptorType = descriptorType;
      binding.descriptorCount = descriptorCount;
      binding.stageFlags = stageFlags;
      binding.pImmutableSamplers = pImmutableSamplers;

      return binding;
    };

    VkDescriptorSetLayoutCreateInfo DescrSetLayoutCI () {

      VkDescriptorSetLayoutCreateInfo info = { 0 };

      info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
      info.pNext = nullptr;
      info.flags = 0; // VkDescriptorSetLayoutCreateFlags(3), VkDescriptorSetLayoutCreateFlagBits(3)
      info.bindingCount = 0;
      info.pBindings = nullptr;

      return info;
    };

    VkDescriptorsetLayout createDescrSetLayout (VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator) {

      VkDescriptorsetLayout layout = VK_NULL_HANDLE;

      vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, &layout);

      return layout;
    };

    VkDescriptorPoolSize getDescriptorPoolSize (
      VkDescriptorType type,
      uint32_t descriptorCount
    ) {

      VkDescriptorPoolSize size = { 0 };

      size.type = type;
      size.descriptorCount = descriptorCount;

      return size;
    };

    // void destroyDescrSetLayouts (VkPipelineLayoutCreateInfo* info) {

    //   for (uint64_t i = 0; i < descr_set_layouts.size; i++) {

    //     vkDestroyDescriptorSetLayout(context.device, info->pSetLayouts[i], nullptr);
    //   }
    // };

    void initPplCI (VkGraphicsPipelineCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkPipelineCreateFlags(3), VkPipelineCreateFlagBits(3)
      info->stageCount = 0;
      info->pStages = nullptr; // VkPipelineShaderStageCreateInfo(3)
      info->pVertexInputState = nullptr; // VkPipelineVertexInputStateCreateInfo(3)
      info->pInputAssemblyState = nullptr; // VkPipelineInputAssemblyStateCreateInfo(3)
      info->pTessellationState = nullptr; // VkPipelineTessellationStateCreateInfo(3)
      info->pViewportState = nullptr; // VkPipelineViewportStateCreateInfo(3)
      info->pRasterizationState = nullptr; // VkPipelineRasterizationStateCreateInfo(3)
      info->pMultisampleState = nullptr; // VkPipelineMultisampleStateCreateInfo(3)
      info->pDepthStencilState = nullptr; // VkPipelineDepthStencilStateCreateInfo(3)
      info->pColorBlendState = nullptr; // VkPipelineColorBlendStateCreateInfo(3)
      info->pDynamicState = nullptr; // VkPipelineDynamicStateCreateInfo(3)
      info->layout = VK_NULL_HANDLE;
      info->renderPass = VK_NULL_HANDLE;
      info->subpass = 0;
      info->basePipelineHandle = VK_NULL_HANDLE;
      info->basePipelineIndex = 0;
    };

    void initPplCI2 (Context* context, VkGraphicsPipelineCreateInfo* info) {

      // initPpl(pipeline);

      info->sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0;
      info->stageCount = 0;
      info->pStages = nullptr;
      info->pVertexInputState = &context->default_pipeline_vertex_input_state_ci;
      info->pInputAssemblyState = &context->default_pipeline_input_assembly_state_ci;
      info->pTessellationState = &context->default_pipeline_tesselation_state_ci;
      info->pViewportState = &context->default_pipeline_viewport_state_ci;
      info->pRasterizationState = &context->default_pipeline_rasterization_state_ci;
      info->pMultisampleState = &context->default_pipeline_multisample_state_ci;
      info->pDepthStencilState = &context->default_pipeline_depth_stencil_state_ci;
      info->pColorBlendState = &context->default_pipeline_color_blend_state_ci;
      info->pDynamicState = &context->default_pipeline_dynamic_state_ci;
      info->layout = VK_NULL_HANDLE;
      info->renderPass = context->render_pass;
      info->subpass = 0;
      info->basePipelineHandle = VK_NULL_HANDLE;
      info->basePipelineIndex = 0;
    };

    void initCommandPoolCI (VkCommandPoolCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkCommandPoolCreateFlags(3), VkCommandPoolCreateFlagBits(3)
      info->queueFamilyIndex = 0;
    };

    void initCommandBufferAI (VkCommandBufferAllocateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
      info->pNext = nullptr;
      info->commandPool = VK_NULL_HANDLE;
      info->level = VK_COMMAND_BUFFER_LEVEL_PRIMARY; // VkCommandBufferLevel(3)
      info->commandBufferCount = 0;
    };

    void initFenceCI (VkFenceCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkFenceCreateFlags(3), VkFenceCreateFlagBits(3)
    };

    void initSemaphoreCI (VkSemaphoreCreateInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkSemaphoreCreateFlags(3)
    };

    void initPresentI (VkPresentInfoKHR* info) {

      info->sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
      info->pNext = nullptr;
      info->waitSemaphoreCount = 0;
      info->pWaitSemaphores = nullptr;
      info->swapchainCount = 0;
      info->pSwapchains = nullptr;
      info->pImageIndices = nullptr;
      info->pResults = nullptr;
    };

    void initSubmitI (VkSubmitInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
      info->pNext = nullptr;
      info->waitSemaphoreCount = 0;
      info->pWaitSemaphores = nullptr;
      info->pWaitDstStageMask = 0; // VkPipelineStageFlags(3), VkPipelineStageFlagBits(3)
      info->commandBufferCount = 0;
      info->pCommandBuffers = nullptr;
      info->signalSemaphoreCount = 0;
      info->pSignalSemaphores = nullptr;
    };

    void initCmdBufferBI (VkCommandBufferBeginInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
      info->pNext = nullptr;
      info->flags = 0; // VkCommandBufferUsageFlags(3), VkCommandBufferUsageFlagBits(3)
      info->pInheritanceInfo = nullptr; // VkCommandBufferInheritanceInfo(3)
    };

    void initRenderPassBI (VkRenderPassBeginInfo* info) {

      info->sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
      info->pNext = nullptr;
      info->renderPass = VK_NULL_HANDLE;
      info->framebuffer = VK_NULL_HANDLE;
      info->renderArea = { { 0, 0 }, { 0, 0 } }; // VkRect2D(3)
      info->clearValueCount = 0;
      info->pClearValues = nullptr; // VkClearValue(3), VkClearColorValue(3), VkClearDepthStencilValue(3)
    };



    void destroyContext (Context* context) {

      // vkDestroyShaderModule(context->device, context->fragment_shader_module, nullptr);
      // vkDestroyShaderModule(context->device, context->vertex_shader_module, nullptr);
      // vkFreeMemory(context->device, context->vertex_buffer_mem, nullptr);
      // vkDestroyBuffer(context->device, context->vertex_buffer, nullptr);
      // vkFreeMemory(context->device, context->uniform_buffer_mem, nullptr);
      // vkDestroyBuffer(context->device, context->uniform_buffer, nullptr);
      // vkDestroyDescriptorPool(context->device, context->descriptor_pool, nullptr);
      // vkDestroyDescriptorSetLayout(context->device, context->descriptor_set_layout, nullptr);

      for (uint32_t i = 0; i < context->swapchain_image_count; i++) {

        vkDestroyFence(context->device, context->fences[i], nullptr);
        vkDestroySemaphore(context->device, context->image_available_semaphores[i], nullptr);
        vkDestroySemaphore(context->device, context->render_finished_semaphores[i], nullptr);
      }

      delete[] context->present_i;

      delete[] context->image_indices;

      delete[] context->render_finished_semaphores;
      delete[] context->image_available_semaphores;
      delete[] context->fences;

      for (uint32_t i = 0; i < context->swapchain_image_count; i++) {
        vkDestroyFramebuffer(context->device, context->framebuffers[i], nullptr);
        vkDestroyImageView(context->device, context->image_views[i], nullptr);
      
        // image 0 will be destroyed further
        if (i) {
          vkDestroyImage(context->device, context->images[i], nullptr);
          vkFreeMemory(context->device, context->image_mem[i], nullptr);
        }
      }
      
      vkDestroyImage(context->device, context->images[0], nullptr);
      vkFreeMemory(context->device, context->image_mem[0], nullptr);

      delete[] context->framebuffer_attachments;
      delete[] context->framebuffers;
      delete[] context->framebuffer_ci;
      delete[] context->image_views;
      delete[] context->image_view_ci;
      delete[] context->images;
      delete[] context->image_ci;

      vkDestroyRenderPass(context->device, context->render_pass, nullptr);

      for (uint32_t i = 0; i < context->swapchain_image_count; i++) {
        vkDestroyImageView(context->device, context->swapchain_image_views[i], nullptr);
      }

      delete[] context->swapchain_image_views;
      delete[] context->swapchain_image_view_ci;
      delete[] context->swapchain_images;
      vkDestroySwapchainKHR(context->device, context->swapchain, nullptr);
      vkDestroyDevice(context->device, nullptr);
      delete[] context->surface_formats;
      vkDestroySurfaceKHR(context->instance, context->surface, nullptr);

      delete[] context->queue_family_props;
      delete[] context->physical_devices;

      #ifdef DEBUG
        MACRO_DESTROY_DEBUG_REPORT_CALLBACKS(context->instance);
      #endif

      vkDestroyInstance(context->instance, nullptr);

      glfwDestroyWindow(window);
      glfwTerminate();

      FreeLibrary(context->hmodule_api);
    };

    void initContext (const uint32_t width, const uint32_t height, Context* context, const VkSampleCountFlagBits sample_count) {

      context->hmodule_api = 0;
      context->count = 0;

      loadSharedLibrary(&context->hmodule_api);

      loadGlobalFunctions(context->hmodule_api);

      glfwInit();
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
      window = glfwCreateWindow(width, height, "", nullptr, nullptr);

      context->instance_layers.push_back("VK_LAYER_KHRONOS_validation");

      context->instance_extensions.push_back("VK_KHR_surface");
      context->instance_extensions.push_back("VK_KHR_win32_surface");
      context->instance_extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);

      initAppI(&context->app_i);
      initInstanceCI(&context->instance_ci);
      context->instance_ci.pApplicationInfo = &context->app_i;
      context->instance_ci.enabledLayerCount = 1;
      context->instance_ci.ppEnabledLayerNames = context->instance_layers.data();
      context->instance_ci.enabledExtensionCount = 3;
      context->instance_ci.ppEnabledExtensionNames = context->instance_extensions.data();
      vkCreateInstance(&context->instance_ci, nullptr, &context->instance);

      loadInstanceFunctions(context->instance);

      #ifdef DEBUG
        MACRO_CREATE_DEBUG_REPORT_CALLBACKS(context->instance);
      #endif

      vkEnumeratePhysicalDevices(context->instance, &context->count, nullptr);
      context->physical_devices = new VkPhysicalDevice[context->count];
      vkEnumeratePhysicalDevices(context->instance, &context->count, context->physical_devices);

      // VkPhysicalDeviceProperties test = { 0 };
      // vkGetPhysicalDeviceProperties(physical_devices[0], &test);
      // std::cout << test.apiVersion << std::endl;
      // std::cout << test.driverVersion << std::endl;
      // std::cout << test.vendorID << std::endl;
      // std::cout << test.deviceID << std::endl;
      // std::cout << test.deviceType << std::endl;
      // std::cout << test.deviceName << std::endl;
      // std::cout << test.pipelineCacheUUID << std::endl;

      // int a;
      // std::cin >> a;

      vkGetPhysicalDeviceQueueFamilyProperties(context->physical_devices[0], &context->count, nullptr);
      context->queue_family_props = new VkQueueFamilyProperties[context->count];
      vkGetPhysicalDeviceQueueFamilyProperties(context->physical_devices[0], &context->count, context->queue_family_props);

      initWin32SurfaceCI(&context->win32_surface_ci);
      context->win32_surface_ci.hinstance = GetModuleHandle(nullptr);
      context->win32_surface_ci.hwnd = glfwGetWin32Window(window);
      vkCreateWin32SurfaceKHR(context->instance, &context->win32_surface_ci, nullptr, &context->surface);

      uint64_t graphics_queue_family_index = 0;
      uint64_t present_queue_family_index = 0;
      uint64_t graphics_queue_index = 0;
      uint64_t present_queue_index = 0;

      std::cout << "queue family properties count: " << context->count << std::endl;
      std::cout << std::endl << std::endl;

      for (uint64_t i = 0; i < context->count; i++) {

        std::cout << "queue family index: " << i << std::endl;
        std::cout << std::endl;
        std::cout << "graphics: " << (context->queue_family_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT || 0) << std::endl;
        std::cout << "compute: " << (context->queue_family_props[i].queueFlags & VK_QUEUE_COMPUTE_BIT || 0) << std::endl;
        std::cout << "transfer: " << (context->queue_family_props[i].queueFlags & VK_QUEUE_TRANSFER_BIT || 0) << std::endl;
        std::cout << "sparse binding: " << (context->queue_family_props[i].queueFlags & VK_QUEUE_SPARSE_BINDING_BIT || 0) << std::endl;
        std::cout << "protected: " << (context->queue_family_props[i].queueFlags & VK_QUEUE_PROTECTED_BIT || 0) << std::endl;
        std::cout << "all: " << (context->queue_family_props[i].queueFlags & VK_QUEUE_FLAG_BITS_MAX_ENUM || 0) << std::endl;
        std::cout << std::endl;
        std::cout << "queue count: " << context->queue_family_props[i].queueCount << std::endl;
        std::cout << "timestamp valid bits: " << context->queue_family_props[i].timestampValidBits << std::endl;
        // std::cout << context->queue_family_props[i].minImageTransferGranularity << std::endl;
        vkGetPhysicalDeviceSurfaceSupportKHR(context->physical_devices[0], i, context->surface, &context->surface_support);
        std::cout << "presentation support: " << context->surface_support << std::endl;
        std::cout << std::endl << std::endl;
      }

      vkGetPhysicalDeviceMemoryProperties(context->physical_devices[0], &context->mem_props);
      // vkGetPhysicalDeviceSurfaceSupportKHR(context->physical_devices[0], 0, context->surface, &context->surface_support);
      vkGetPhysicalDeviceSurfaceCapabilitiesKHR(context->physical_devices[0], context->surface, &context->surface_capabilities);

      vkGetPhysicalDeviceSurfaceFormatsKHR(context->physical_devices[0], context->surface, &context->count, nullptr);
      context->surface_formats = new VkSurfaceFormatKHR[context->count];
      vkGetPhysicalDeviceSurfaceFormatsKHR(context->physical_devices[0], context->surface, &context->count, context->surface_formats);

      context->queue_priorities.push_back(1.0f);

      initDeviceQueueCI(&context->device_queue_ci);
      context->device_queue_ci.queueCount = 1;
      context->device_queue_ci.pQueuePriorities = context->queue_priorities.data();

      context->device_extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

      initDeviceCI(&context->device_ci);
      context->device_ci.queueCreateInfoCount = 1;
      context->device_ci.pQueueCreateInfos = &context->device_queue_ci;
      context->device_ci.enabledExtensionCount = 1;
      context->device_ci.ppEnabledExtensionNames = context->device_extensions.data();
      vkCreateDevice(context->physical_devices[0], &context->device_ci, nullptr, &context->device);

      loadDeviceFunctions(context->device);

      vkGetDeviceQueue(context->device, 0, 0, &context->graphics_queue);
      vkGetDeviceQueue(context->device, 0, 0, &context->present_queue);

      initSwapchainCI(&context->swapchain_ci);
      context->swapchain_ci.surface = context->surface;
      context->swapchain_ci.minImageCount = 3;
      context->swapchain_ci.imageExtent.width = width;
      context->swapchain_ci.imageExtent.height = height;
      vkCreateSwapchainKHR(context->device, &context->swapchain_ci, nullptr, &context->swapchain);

      vkGetSwapchainImagesKHR(context->device, context->swapchain, &context->count, nullptr);
      context->swapchain_images = new VkImage[context->count];
      vkGetSwapchainImagesKHR(context->device, context->swapchain, &context->count, context->swapchain_images);

      context->swapchain_image_count = context->count;

      context->swapchain_image_view_ci = new VkImageViewCreateInfo[context->swapchain_image_count];
      context->swapchain_image_views = new VkImageView[context->swapchain_image_count];

      for (uint32_t i = 0; i < context->swapchain_image_count; i++) {
        initImageViewCI(&context->swapchain_image_view_ci[i]);
        context->swapchain_image_view_ci[i].image = context->swapchain_images[i];
        vkCreateImageView(context->device, &context->swapchain_image_view_ci[i], nullptr, &context->swapchain_image_views[i]);
      }

      initAttachDesc(&context->color_attachment);
      context->color_attachment.samples = sample_count;
      context->color_attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
      context->color_attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

      initAttachDesc(&context->color_attachment_resolve);
      context->color_attachment_resolve.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
      context->color_attachment_resolve.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

      initAttachRef(&context->color_attachment_reference);
      context->color_attachment_reference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

      initAttachRef(&context->color_attachment_resolve_reference);
      context->color_attachment_resolve_reference.attachment = 1;
      context->color_attachment_resolve_reference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

      initSubpassDesc(&context->subpass);
      context->subpass.pColorAttachments = &context->color_attachment_reference;
      context->subpass.pResolveAttachments = &context->color_attachment_resolve_reference;

      initSubpassDep(&context->subpass_dependency);
      context->subpass_dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
      context->subpass_dependency.srcAccessMask = 0;
      context->subpass_dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
      context->subpass_dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

      context->render_pass_attachments[0] = context->color_attachment;
      context->render_pass_attachments[1] = context->color_attachment_resolve;

      initRenderPassCI(&context->render_pass_ci);
      context->render_pass_ci.attachmentCount = 2;
      context->render_pass_ci.pAttachments = context->render_pass_attachments;
      context->render_pass_ci.subpassCount = 1;
      context->render_pass_ci.pSubpasses = &context->subpass;
      context->render_pass_ci.dependencyCount = 1;
      context->render_pass_ci.pDependencies = &context->subpass_dependency;
      vkCreateRenderPass(context->device, &context->render_pass_ci, nullptr, &context->render_pass);

      context->image_ci = new VkImageCreateInfo[context->swapchain_image_count];
      context->images = new VkImage[context->swapchain_image_count];
      context->image_mem = new VkDeviceMemory[context->swapchain_image_count];
      context->image_view_ci = new VkImageViewCreateInfo[context->swapchain_image_count];
      context->image_views = new VkImageView[context->swapchain_image_count];
      context->framebuffer_ci = new VkFramebufferCreateInfo[context->swapchain_image_count];
      context->framebuffers = new VkFramebuffer[context->swapchain_image_count];
      context->framebuffer_attachments = new VkImageView[context->swapchain_image_count * 2];

      initImageCI(&context->image_ci[0]);
      context->image_ci[0].extent.width = width;
      context->image_ci[0].extent.height = height;
      context->image_ci[0].usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
      context->image_ci[0].samples = sample_count; 
      vkCreateImage(context->device, &context->image_ci[0], nullptr, &context->images[0]);

      vkGetImageMemoryRequirements(context->device, context->images[0], &context->mem_reqs);
      context->mem_type_index = getMemTypeIndex(context, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
      initMemAI(&context->image_mem_ai);
      context->image_mem_ai.allocationSize = context->mem_reqs.size;
      context->image_mem_ai.memoryTypeIndex = context->mem_type_index;

      for (uint32_t i = 0; i < context->swapchain_image_count; i++) {
        // image 0 has been already created above
        if (i) {
          initImageCI(&context->image_ci[i]);
          context->image_ci[i].extent.width = width;
          context->image_ci[i].extent.height = height;
          context->image_ci[i].usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
          context->image_ci[i].samples = sample_count; 
          vkCreateImage(context->device, &context->image_ci[i], nullptr, &context->images[i]);
        }

        vkAllocateMemory(context->device, &context->image_mem_ai, nullptr, &context->image_mem[i]);
        vkBindImageMemory(context->device, context->images[i], context->image_mem[i], 0);

        initImageViewCI(&context->image_view_ci[i]);
        context->image_view_ci[i].image = context->images[i];
        vkCreateImageView(context->device, &context->image_view_ci[i], nullptr, &context->image_views[i]);

        context->framebuffer_attachments[i * 2] = context->image_views[i];
        context->framebuffer_attachments[(i * 2) + 1] = context->swapchain_image_views[i];

        initFramebufferCI(&context->framebuffer_ci[i]);
        context->framebuffer_ci[i].renderPass = context->render_pass;
        context->framebuffer_ci[i].attachmentCount = 2;
        context->framebuffer_ci[i].pAttachments = &context->framebuffer_attachments[i * 2];
        context->framebuffer_ci[i].width = width;
        context->framebuffer_ci[i].height = height;
        vkCreateFramebuffer(context->device, &context->framebuffer_ci[i], nullptr, &context->framebuffers[i]);
      }

      initPplVertex(&context->default_pipeline_vertex_input_state_ci);
      initPplInputAsm(&context->default_pipeline_input_assembly_state_ci);
      initPplTessel(&context->default_pipeline_tesselation_state_ci);
      initPplViewport(&context->default_pipeline_viewport_state_ci);
      initPplMultisample(&context->default_pipeline_multisample_state_ci);
      initPplRaster(&context->default_pipeline_rasterization_state_ci);
      initPplDepthStenc(&context->default_pipeline_depth_stencil_state_ci);
      initPplColorBlend(&context->default_pipeline_color_blend_state_ci);
      initPplDyn(&context->default_pipeline_dynamic_state_ci);

      context->viewport = { 0.0f, 0.0f, (float) width, (float) height, 0.0f, 0.0f };
      context->scissor = { { 0, 0 }, { width, height } };
      initPplColorBlendAttachState(&context->color_blend_attachment_state);

      context->default_pipeline_input_assembly_state_ci.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
      context->default_pipeline_viewport_state_ci.viewportCount = 1;
      context->default_pipeline_viewport_state_ci.pViewports = &context->viewport;
      context->default_pipeline_viewport_state_ci.scissorCount = 1;
      context->default_pipeline_viewport_state_ci.pScissors = &context->scissor;
      context->default_pipeline_multisample_state_ci.rasterizationSamples = sample_count;
      context->default_pipeline_rasterization_state_ci.lineWidth = 1.0f;
      context->default_pipeline_color_blend_state_ci.attachmentCount = 1;
      context->default_pipeline_color_blend_state_ci.pAttachments = &context->color_blend_attachment_state;

      initFenceCI(&context->fence_ci);
      context->fence_ci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
      initSemaphoreCI(&context->semaphore_ci);

      context->fences = new VkFence[context->swapchain_image_count];
      context->image_available_semaphores = new VkSemaphore[context->swapchain_image_count];
      context->render_finished_semaphores = new VkSemaphore[context->swapchain_image_count];

      context->image_indices =  new uint32_t[context->swapchain_image_count];

      context->present_i = new VkPresentInfoKHR[context->swapchain_image_count];

      for (uint32_t i = 0; i < context->swapchain_image_count; i++) {

        vkCreateFence(context->device, &context->fence_ci, nullptr, &context->fences[i]);
        vkCreateSemaphore(context->device, &context->semaphore_ci, nullptr, &context->image_available_semaphores[i]);
        vkCreateSemaphore(context->device, &context->semaphore_ci, nullptr, &context->render_finished_semaphores[i]);

        initPresentI(&context->present_i[i]);
        context->present_i[i].waitSemaphoreCount = 1;
        context->present_i[i].pWaitSemaphores = &context->render_finished_semaphores[i];
        context->present_i[i].swapchainCount = 1;
        context->present_i[i].pSwapchains = &context->swapchain;
        context->present_i[i].pImageIndices = &context->image_indices[i];
      }
    };
  };
};
