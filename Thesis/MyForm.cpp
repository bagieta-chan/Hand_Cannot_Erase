#include "MyForm.h"

using namespace System;
using namespace Thesis;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {

	
	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);


	Application::Run(gcnew MyForm());

}
