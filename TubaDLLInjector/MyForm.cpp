#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Helpful_Debugger_Installer::MyForm form;
    Application::Run(% form);
}
