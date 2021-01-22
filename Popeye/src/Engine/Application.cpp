#include "pch.h"
#include "Application.h"

namespace Engine {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Engine::Log::Init();
		bool initialize = false;
		Engine::Renderer* renderer = new Renderer();

		initialize = renderer->init_renderer();
		if (!initialize)
		{
			delete(renderer);
			ENGINE_CORE_ERROR("Renderer Initialize fail.");
			return;
		}

		Engine::GUIManager* guiManager = new GUIManager();
		guiManager->onSet(renderer->get_window());
		
        //ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        // Main loop
        while (!renderer->poll_events())
        {
            // Start the Dear ImGui frame
			guiManager->onRun();

			renderer->run_renderer();
			guiManager->onRunDraw();
			renderer->swap_buffer();
        }

        // Cleanup
		guiManager->onClosed();
		delete guiManager;

		renderer->close_renderer();
		delete renderer;
		return;
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

}