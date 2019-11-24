// replace all int types to smaller (if possible) suitable int types

// not to include predefined api functions
#define VK_NO_PROTOTYPES
// minimize windows.h
#define WIN32_LEAN_AND_MEAN
#define GLFW_EXPOSE_NATIVE_WIN32
#include "glfw3.h"
#include "glfw3native.h"
// VK_KHR_win32_surface extension
#define VK_USE_PLATFORM_WIN32_KHR

#include <windows.h>
#include <vulkan.h>



// vulkan api function declarations
#define DEF_PROC(name) PFN_##name name

DEF_PROC(vkGetInstanceProcAddr);

DEF_PROC(vkCreateInstance);
DEF_PROC(vkEnumerateInstanceLayerProperties);
DEF_PROC(vkEnumerateInstanceExtensionProperties);

DEF_PROC(vkDestroyInstance);

DEF_PROC(vkEnumeratePhysicalDevices);
DEF_PROC(vkEnumerateDeviceExtensionProperties);
DEF_PROC(vkGetPhysicalDeviceProperties);
DEF_PROC(vkGetPhysicalDeviceFeatures);
DEF_PROC(vkGetPhysicalDeviceQueueFamilyProperties);
DEF_PROC(vkGetPhysicalDeviceMemoryProperties);

DEF_PROC(vkGetDeviceProcAddr);
DEF_PROC(vkCreateDevice);

DEF_PROC(vkCreateDebugReportCallbackEXT);
DEF_PROC(vkDestroyDebugReportCallbackEXT);

DEF_PROC(vkCreateWin32SurfaceKHR);
DEF_PROC(vkGetPhysicalDeviceSurfaceSupportKHR);
DEF_PROC(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
DEF_PROC(vkGetPhysicalDeviceSurfaceFormatsKHR);
DEF_PROC(vkGetPhysicalDeviceSurfacePresentModesKHR);
DEF_PROC(vkDestroySurfaceKHR);

DEF_PROC(vkDeviceWaitIdle);
DEF_PROC(vkDestroyDevice);

DEF_PROC(vkGetDeviceQueue);
DEF_PROC(vkQueueSubmit);
DEF_PROC(vkQueuePresentKHR);
DEF_PROC(vkQueueWaitIdle);

DEF_PROC(vkCreateSwapchainKHR);
DEF_PROC(vkGetSwapchainImagesKHR);
DEF_PROC(vkAcquireNextImageKHR);
DEF_PROC(vkDestroySwapchainKHR);

DEF_PROC(vkCreateImage);
DEF_PROC(vkDestroyImage);

DEF_PROC(vkCreateImageView);
DEF_PROC(vkDestroyImageView);

DEF_PROC(vkCreateRenderPass);
DEF_PROC(vkDestroyRenderPass);

DEF_PROC(vkCreateFramebuffer);
DEF_PROC(vkDestroyFramebuffer);

DEF_PROC(vkBeginCommandBuffer);
DEF_PROC(vkCmdPipelineBarrier);
DEF_PROC(vkCmdClearColorImage);
DEF_PROC(vkCmdBeginRenderPass);
DEF_PROC(vkCmdBindPipeline);
DEF_PROC(vkCmdBindVertexBuffers);
DEF_PROC(vkCmdBindDescriptorSets);
DEF_PROC(vkCmdDraw);
DEF_PROC(vkCmdEndRenderPass);
DEF_PROC(vkEndCommandBuffer);
DEF_PROC(vkResetCommandBuffer);

DEF_PROC(vkCreateCommandPool);
DEF_PROC(vkAllocateCommandBuffers);
DEF_PROC(vkDestroyCommandPool);

DEF_PROC(vkCreateSemaphore);
DEF_PROC(vkDestroySemaphore);

DEF_PROC(vkCreateFence);
DEF_PROC(vkWaitForFences);
DEF_PROC(vkResetFences);
DEF_PROC(vkDestroyFence);

DEF_PROC(vkCreateShaderModule);
DEF_PROC(vkDestroyShaderModule);

DEF_PROC(vkCreatePipelineLayout);
DEF_PROC(vkDestroyPipelineLayout);

DEF_PROC(vkCreateGraphicsPipelines);
DEF_PROC(vkDestroyPipeline);

DEF_PROC(vkCreateBuffer);
DEF_PROC(vkGetBufferMemoryRequirements);
DEF_PROC(vkGetImageMemoryRequirements);
DEF_PROC(vkDestroyBuffer);

DEF_PROC(vkAllocateMemory);
DEF_PROC(vkBindBufferMemory);
DEF_PROC(vkMapMemory);
DEF_PROC(vkFlushMappedMemoryRanges);
DEF_PROC(vkUnmapMemory);
DEF_PROC(vkFreeMemory);
DEF_PROC(vkBindImageMemory);

DEF_PROC(vkCreateDescriptorPool);
DEF_PROC(vkDestroyDescriptorPool);

DEF_PROC(vkCreateDescriptorSetLayout);
DEF_PROC(vkUpdateDescriptorSets);
DEF_PROC(vkAllocateDescriptorSets);
DEF_PROC(vkDestroyDescriptorSetLayout);

#undef DEF_PROC

void loadVk (HMODULE* hmodule_api) {
  // free previously loaded api library
  FreeLibrary(*hmodule_api);

  *hmodule_api = LoadLibrary("vulkan-1.dll");
};

// vulkan api function definitions
void defineVkGlobalFunctions (HMODULE hmodule_api) {
  vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) GetProcAddress(hmodule_api, "vkGetInstanceProcAddr");

  #define GET_PROC_ADDR(name) name = (PFN_##name) vkGetInstanceProcAddr(nullptr, #name)

  GET_PROC_ADDR(vkCreateInstance);
  GET_PROC_ADDR(vkEnumerateInstanceLayerProperties);
  GET_PROC_ADDR(vkEnumerateInstanceExtensionProperties);

  #undef GET_PROC_ADDR
};

void defineVkInstanceFunctions (VkInstance instance) {
  #define GET_PROC_ADDR(name) name = (PFN_##name) vkGetInstanceProcAddr(instance, #name)

  GET_PROC_ADDR(vkDestroyInstance);\

  GET_PROC_ADDR(vkEnumeratePhysicalDevices);
  GET_PROC_ADDR(vkGetPhysicalDeviceProperties);
  GET_PROC_ADDR(vkGetPhysicalDeviceFeatures);
  GET_PROC_ADDR(vkGetPhysicalDeviceQueueFamilyProperties);
  GET_PROC_ADDR(vkGetPhysicalDeviceMemoryProperties);

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

void defineVkDeviceFunctions (VkDevice device) {
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

static inline void initVkAppI (VkApplicationInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  info->pNext = nullptr;
  info->pApplicationName = nullptr;
  info->applicationVersion = 0;
  info->pEngineName = nullptr;
  info->engineVersion = 0;
  info->apiVersion = VK_API_VERSION_1_0;
};

static inline void initVkInstanceCI (VkInstanceCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0;
  info->pApplicationInfo = nullptr;
  info->enabledLayerCount = 0;
  info->ppEnabledLayerNames = nullptr;
  info->enabledExtensionCount = 0;
  info->ppEnabledExtensionNames = nullptr;
};

static inline void initVkDeviceCI (VkDeviceCreateInfo* info) {
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

static inline void initVkDeviceQueueCI (VkDeviceQueueCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0;
  info->queueFamilyIndex = 0;
  info->queueCount = 0;
  info->pQueuePriorities = nullptr;
};

static inline void initVkWin32SurfaceCI (VkWin32SurfaceCreateInfoKHR* info) {
  info->sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
  info->pNext = nullptr;
  info->flags = 0;
  info->hinstance = 0;
  info->hwnd = 0;
};

static inline void initVkSwapchainCI (VkSwapchainCreateInfoKHR* info) {
  info->sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
  info->pNext = nullptr;
  info->flags = 0; // VkSwapchainCreateFlagsKHR(3), VkSwapchainCreateFlagBitsKHR(3)
  info->surface = VK_nullptr_HANDLE;
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
  info->oldSwapchain = VK_nullptr_HANDLE;
};

static inline void initVkImageCI (VkImageCreateInfo* info) {
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
  info->samples = VK_SAMPLE_COUNT_4_BIT; // VkSampleCountFlagBits(3)
  info->tiling = VK_IMAGE_TILING_OPTIMAL; // VkImageTiling(3)
  info->usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; // VkImageUsageFlags(3), VkImageUsageFlagBits(3)
  info->sharingMode = VK_SHARING_MODE_EXCLUSIVE; // VkSharingMode(3)
  info->queueFamilyIndexCount = 0;
  info->pQueueFamilyIndices = nullptr;
  info->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED; // VkImageLayout(3)
};

static inline void initVkImageViewCI (VkImageViewCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0; // VkImageViewCreateFlags(3), VkImageViewCreateFlagBits(3)
  info->image = VK_nullptr_HANDLE;
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

static inline void initVkAttachDesc (VkAttachmentDescription* desc) {
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

static inline void initVkAttachRef (VkAttachmentReference* ref) {
  ref->attachment = 0;
  ref->layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL; // VkImageLayout(3)
};

static inline void initVkSubpassDesc (VkSubpassDescription* desc) {
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

static inline void initVkSubpassDep (VkSubpassDependency* dep) {
  dep->srcSubpass = VK_SUBPASS_EXTERNAL;
  dep->dstSubpass = 0;
  dep->srcStageMask = 0; // VkPipelineStageFlags(3), VkPipelineStageFlagBits(3)
  dep->dstStageMask = 0; // VkPipelineStageFlags(3), VkPipelineStageFlagBits(3)
  dep->srcAccessMask = 0; // VkAccessFlags(3), VkAccessFlagBits(3)
  dep->dstAccessMask = 0; // VkAccessFlags(3), VkAccessFlagBits(3)
  dep->dependencyFlags = 0; // VkDependencyFlags(3), VkDependencyFlagBits(3)
};

static inline void initVkRenderPassCI (VkRenderPassCreateInfo* info) {
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

static inline void initVkFramebufferCI (VkFramebufferCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0;
  info->renderPass = VK_nullptr_HANDLE;
  info->attachmentCount = 1;
  info->pAttachments = nullptr;
  info->width = 0;
  info->height = 0;
  info->layers = 1;
};

static inline void initVkMemoryAI (VkMemoryAllocateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
  info->pNext = nullptr;
  info->allocationSize = 0;
  info->memoryTypeIndex = 0;
};

static inline void initVkDescriptorSetLayoutBinding (VkDescriptorSetLayoutBinding* binding) {
  binding->binding = 0;
  binding->descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER; // VkDescriptorType(3)
  binding->descriptorCount = 0;
  binding->stageFlags = VK_SHADER_STAGE_VERTEX_BIT; // VkShaderStageFlags(3), VkShaderStageFlagBits(3)
  binding->pImmutableSamplers = nullptr;
};

static inline void initVkDescriptorSetLayoutCI (VkDescriptorSetLayoutCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0; // VkDescriptorSetLayoutCreateFlags(3), VkDescriptorSetLayoutCreateFlagBits(3)
  info->bindingCount = 0;
  info->pBindings = nullptr;
};

static inline void initVkDescriptorPoolSize (VkDescriptorPoolSize* size) {
  size->type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER; // VkDescriptorType(3)
  size->descriptorCount = 0;
};

static inline void initVkDescriptorPoolCI (VkDescriptorPoolCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0; // VkDescriptorPoolCreateFlags(3), VkDescriptorPoolCreateFlagBits(3)
  info->maxSets = 0;
  info->poolSizeCount = 0;
  info->pPoolSizes = nullptr;
};

static inline void initVkDescriptorSetAI (VkDescriptorSetAllocateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
  info->pNext = nullptr;
  info->descriptorPool = VK_nullptr_HANDLE;
  info->descriptorSetCount = 0;
  info->pSetLayouts = nullptr;
};

static inline void initVkBufferCI (VkBufferCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0; // VkBufferCreateFlags(3), VkBufferCreateFlagBits(3)
  info->size = 0;
  info->usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT; // VkBufferUsageFlags(3), VkBufferUsageFlagBits(3)
  info->sharingMode = VK_SHARING_MODE_EXCLUSIVE; // VkSharingMode(3)
  info->queueFamilyIndexCount = 0;
  info->pQueueFamilyIndices = nullptr;
};

static inline void initVkDescriptorBufferI (VkDescriptorBufferInfo* info) {
  info->buffer = VK_nullptr_HANDLE;
  info->offset = 0;
  info->range = VK_WHOLE_SIZE;
};

static inline void initVkWriteDescriptorSet (VkWriteDescriptorSet* write) {
  write->sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
  write->pNext = nullptr;
  write->dstSet = VK_nullptr_HANDLE;
  write->dstBinding = 0;
  write->dstArrayElement = 0;
  write->descriptorCount = 0;
  write->descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER; // VkDescriptorType(3)
  write->pImageInfo = nullptr;
  write->pBufferInfo = nullptr;
  write->pTexelBufferView = nullptr;
};

static inline void initVkShaderModuleCI (VkShaderModuleCreateInfo* info) {
  info->sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  info->pNext = nullptr;
  info->flags = 0; // VkShaderModuleCreateFlags(3)
  info->codeSize = 0;
  info->pCode = nullptr;
};



int getVkMemTypeIndex (VkPhysicalDeviceMemoryProperties* mem_props, VkMemoryRequirements* mem_reqs, VkMemoryPropertyFlags flags) {
  unsigned int mem_type_count = mem_props->memoryTypeCount;

  for(unsigned int i = 0; i < mem_type_count; i++) {
    unsigned int match = (mem_reqs->memoryTypeBits & (1 << i)) && (mem_props->memoryTypes[i].propertyFlags & flags);

    if (match) {
      return i;
    };
  }

  return -1;
};

#ifdef DEBUG
  #define XGK_ENGINE_CREATE_VK_DEBUG_REPORT_CALLBACKS(instance)\
    initVkDebugReportCallbackCIEXT(&vk_report_info_ci);\
    vk_report_info_ci.pfnCallback = &reportVkInfo;\
    vkCreateDebugReportCallbackEXT(instance, &vk_report_info_ci, nullptr, &vk_report_info);\
    \
    initVkDebugReportCallbackCIEXT(&vk_report_warn_ci);\
    vk_report_warn_ci.flags = VK_DEBUG_REPORT_WARNING_BIT_EXT;\
    vk_report_warn_ci.pfnCallback = &reportVkWarn;\
    vkCreateDebugReportCallbackEXT(instance, &vk_report_warn_ci, nullptr, &vk_report_warn);\
    \
    initVkDebugReportCallbackCIEXT(&vk_report_perf_ci);\
    vk_report_perf_ci.flags = VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;\
    vk_report_perf_ci.pfnCallback = &reportVkPerf;\
    vkCreateDebugReportCallbackEXT(instance, &vk_report_perf_ci, nullptr, &vk_report_perf);\
    \
    initVkDebugReportCallbackCIEXT(&vk_report_error_ci);\
    vk_report_error_ci.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT;\
    vk_report_error_ci.pfnCallback = &reportVkError;\
    vkCreateDebugReportCallbackEXT(instance, &vk_report_error_ci, nullptr, &vk_report_error);\
    \
    initVkDebugReportCallbackCIEXT(&vk_report_debug_ci);\
    vk_report_debug_ci.flags = VK_DEBUG_REPORT_DEBUG_BIT_EXT;\
    vk_report_debug_ci.pfnCallback = &reportVkDebug;\
    vkCreateDebugReportCallbackEXT(instance, &vk_report_debug_ci, nullptr, &vk_report_debug);

  #define XGK_ENGINE_DESTROY_VK_DEBUG_REPORT_CALLBACKS(instance)\
    vkDestroyDebugReportCallbackEXT(instance, vk_report_debug, nullptr);\
    vkDestroyDebugReportCallbackEXT(instance, vk_report_error, nullptr);\
    vkDestroyDebugReportCallbackEXT(instance, vk_report_perf, nullptr);\
    vkDestroyDebugReportCallbackEXT(instance, vk_report_warn, nullptr);\
    vkDestroyDebugReportCallbackEXT(instance, vk_report_info, nullptr);

  VkDebugReportCallbackCreateInfoEXT
    vk_report_info_ci = { 0 },
    vk_report_warn_ci = { 0 },
    vk_report_perf_ci = { 0 },
    vk_report_error_ci = { 0 },
    vk_report_debug_ci = { 0 };

  VkDebugReportCallbackEXT
    vk_report_info = VK_nullptr_HANDLE,
    vk_report_warn = VK_nullptr_HANDLE,
    vk_report_perf = VK_nullptr_HANDLE,
    vk_report_error = VK_nullptr_HANDLE,
    vk_report_debug = VK_nullptr_HANDLE;

  #define DEBUG_REPORT_ARGS \
    VkDebugReportFlagsEXT flags,\
    VkDebugReportObjectTypeEXT objectType,\
    uint64_t object,\
    size_t location,\
    int32_t messageCode,\
    const char* pLayerPrefix,\
    const char* pMessage,\
    void* pUserData

  static inline void initVkDebugReportCallbackCIEXT (VkDebugReportCallbackCreateInfoEXT* info) {
    info->sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    info->pNext = nullptr;
    info->flags = VK_DEBUG_REPORT_INFORMATION_BIT_EXT; // VkDebugReportFlagsEXT(3), VkDebugReportFlagBitsEXT(3)
    info->pfnCallback = nullptr;
    info->pUserData = nullptr;
  };

  static inline VkBool32 reportVkInfo(DEBUG_REPORT_ARGS) {
    printf("VALIDATION LAYER INFORMATION: %s\n", pMessage);
    return VK_FALSE;
  };

  static inline VkBool32 reportVkWarn(DEBUG_REPORT_ARGS) {
    printf("VALIDATION LAYER WARNING: %s\n", pMessage);
    return VK_FALSE;
  };

  static inline VkBool32 reportVkPerf(DEBUG_REPORT_ARGS) {
    printf("VALIDATION LAYER PERFORMANCE WARNING: %s\n", pMessage);
    return VK_FALSE;
  };

  static inline VkBool32 reportVkError(DEBUG_REPORT_ARGS) {
    printf("VALIDATION LAYER ERROR: %s\n", pMessage);
    return VK_FALSE;
  };

  static inline VkBool32 reportVkDebug(DEBUG_REPORT_ARGS) {
    printf("VALIDATION LAYER DEBUG: %s\n", pMessage);
    return VK_FALSE;
  };

  #undef DEBUG_REPORT_ARGS
#endif
