//
// Created by valen on 11/09/2022.
//

#include "PlatformGLFW.h"

namespace Engine::Platform::GLFW {

	Core::Window& PlatformGLFW::GetWindow() {
		return m_window;
	}

	PlatformGLFW::PlatformGLFW(const Core::WindowConfig& windowConfig) {
		glfwInit();
		// Set GLFW version 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		auto windowHandle = glfwCreateWindow(windowConfig.Size.Width, windowConfig.Size.Height, windowConfig.Title.c_str(), nullptr, nullptr);

		if (windowHandle == nullptr) {
			// Failed to create window!

			glfwTerminate();

			throw std::runtime_error("Couldn't create GLFW window.");
		}

		glfwSetWindowUserPointer(windowHandle, &m_window);
		m_window.Init(windowHandle, windowConfig);
	}

}