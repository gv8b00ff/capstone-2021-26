#pragma once
namespace Popeye {
	class RenderingSystem
	{
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
	public:
		void OnEdit();
		void Init();
		void OnUpdate();
		void OnExit();
	};
}

