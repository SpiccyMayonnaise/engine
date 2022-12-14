#pragma once

#include "entt/entt.hpp"
#include "Scene.h"
#include "ECS/Components.h"

namespace Engine {

	class Application;
	class Scene;

	// Holds the current scene
	class World {
	public:
		World() = delete;
		explicit World(Application& application);

		// Copy and move
		World(World& other) = delete;
		World& operator==(World& other) = delete;
		World(World&& other) = delete;
		World& operator==(World&& other) = delete;

		~World() = default;


		Application& GetApplication() {return m_application;}

		void SwitchScene(std::unique_ptr<Scene> nextScene) {
			m_nextScene = std::move(nextScene);
		}

		void Update();

		void OnViewportResize(uint32_t width, uint32_t height);

		float GetDeltaTime() const {return m_deltaTime;}


		entt::registry registry;

	private:
		void OnCameraAdded(entt::registry& registry, entt::entity entity);


		Application& m_application;

		std::unique_ptr<Scene> m_currentScene;
		std::unique_ptr<Scene> m_nextScene;

		uint32_t m_viewportWidth = 0;
		uint32_t m_viewportHeight = 0;

		double m_lastUpdateTime;
		double m_deltaTime = 0;
	};

}