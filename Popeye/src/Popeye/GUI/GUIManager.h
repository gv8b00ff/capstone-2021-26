#pragma once
namespace Popeye {
	class Tab
	{
	private:
	char* name;
	public:
		Tab();
		virtual ~Tab();
		void setTab(char* );
		void showTab();
		void contents();
	};

	class Property : Tab
	{

	};

	class GUIManager
	{
	private:
		ImGuiWindowFlags flags;
		ImGuiID dockspace_id;
		//ImGuiIO&
		std::vector<Tab> tabs;
	public:
		GUIManager();
		virtual ~GUIManager();
		void onSet(GLFWwindow*);
		void setTabs();
		void set_default_layout();
		void onRun();
		void onRunDraw();
		void show();
		void onClosed();
	};
}