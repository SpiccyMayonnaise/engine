#pragma once

#include "entt/entt.hpp"
#include "Scene.h"

namespace Engine {

	class Scene;

	// Holds the current scene
	class World {
	public:
		World() = default;

		// Copy and move
		World(World& other) = delete;
		World& operator==(World& other) = delete;
		World(World&& other) = delete;
		World& operator==(World&& other) = delete;

		~World() = default;


		void SwitchScene(std::unique_ptr<Scene> nextScene) {
			m_nextScene = std::move(nextScene);
		}

		void Update();


		entt::registry registry;

	private:
		std::unique_ptr<Scene> m_currentScene;
		std::unique_ptr<Scene> m_nextScene;
	};

}