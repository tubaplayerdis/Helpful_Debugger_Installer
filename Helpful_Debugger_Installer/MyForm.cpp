#include "MainForm.h"
#include "Form2.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Helpful_Debugger_Installer::MyForm form;
    Application::Run(% form);
}






