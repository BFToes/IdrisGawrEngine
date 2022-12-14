#pragma once
#include "GawrVK.h"
#include "Context.h"
#include <vector>

namespace Gawr::Core {
	class Window : Context {
		struct Callback {
			static void glfwError(int, const char* msg);
			static void glfwResize(VK_PTR(GLFWwindow*), int, int);
			// needs more call to attach to the glfw stuff backs
		};

	public:
		Window(const char* title, uint32_t width, uint32_t height, bool resizing = false);
			
		~Window();

		bool closed();

		uint32_t get_width() const;

		uint32_t get_height() const;

	private:
		void createWindow(uint32_t width, uint32_t height, const char* title, bool resizing);

		void createSurface();

		void createRenderpass();

		void createSwapchain();

		void createImages();

		void updateSwapchain();

		bool								m_resized;

		VK_PTR(GLFWwindow*)					m_window;
		VK_PTR(VkSurfaceKHR)				m_surface;
		VK_ENUM(VkFormat)					m_format;

		// swapchain
		VK_PTR(VkSwapchainKHR)				m_swapchain;
		VK_PTR(VkRenderPass)				m_renderPass;
			
		struct SwapchainImage {
			VK_PTR(VkImage)					m_image;
			VK_PTR(VkImageView)				m_view;
			VK_PTR(VkFramebuffer)			m_framebuffer;
		};
		std::vector<SwapchainImage>			m_swapchainImages;
	};
}