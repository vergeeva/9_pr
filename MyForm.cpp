#include "MyForm.h"
#include "MyForm.h"
using namespace My9pr; // Èìÿ ïðîåêòà.
[STAThreadAttribute]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm()); // Èìÿ ôîðìû.
	return 0;
}