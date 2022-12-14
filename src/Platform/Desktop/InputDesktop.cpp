#include "InputDesktop.h"
#include "WindowDesktop.h"
#include "Core/Application.h"


namespace Engine {
	InputDesktop::InputDesktop(GLFWwindow* windowHandle) : m_windowHandle(windowHandle) {
		double x, y;
		glfwGetCursorPos(m_windowHandle, &x, &y);
		glm::vec2 pos{x, y};

		m_mousePosition = pos;

		// Cursor lock
		glfwSetInputMode(m_windowHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}


	bool InputDesktop::GetKey(Keycode keycode) {
		return glfwGetKey(m_windowHandle, keycode) == GLFW_PRESS;
	}

	bool InputDesktop::GetMouseButton(Mousecode mousecode) {
		return glfwGetMouseButton(m_windowHandle, mousecode) == GLFW_PRESS;
	}

	void InputDesktop::Update() {
		double x, y;
		glfwGetCursorPos(m_windowHandle, &x, &y);

		glm::vec2 pos{x, y};

		m_mouseDelta = pos - m_mousePosition;
		m_mousePosition = pos;
	}
};