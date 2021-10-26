#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include "ISM.h"
#include "Form2.h"


namespace Helpful_Debugger_Installer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	
	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		



		
		
	private: 
		
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FolderBrowserDialog^ ChooseInstallDirectory;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ ChooseButton;
	protected:

	protected:






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ChooseInstallDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ChooseButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(9, 525);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(327, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Install Helpful Debugger";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(323, 34);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Install Helpful Debugger";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(18, 89);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(314, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"C:\\Program Files\\Helpful_Debugger";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(14, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(265, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Choose Installation Location";
			// 
			// ChooseButton
			// 
			this->ChooseButton->BackColor = System::Drawing::SystemColors::Control;
			this->ChooseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ChooseButton->Location = System::Drawing::Point(18, 115);
			this->ChooseButton->Name = L"ChooseButton";
			this->ChooseButton->Size = System::Drawing::Size(314, 32);
			this->ChooseButton->TabIndex = 4;
			this->ChooseButton->Text = L"Choose";
			this->ChooseButton->UseVisualStyleBackColor = false;
			this->ChooseButton->Click += gcnew System::EventHandler(this, &MyForm::ChooseButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(351, 574);
			this->Controls->Add(this->ChooseButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"HDI - Main";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			
			private:  
				
			System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
				AYO NEED;
				if (NEED.ReturnInstallString() == "")
				{
					NEED.ShowBox("There is no install directory");
				}
				else
				{
					switch (NEED.CreateorVerifyInstallDic(NEED.ReturnInstallString()))
					{
					case 1:
						NEED.ShowBox("Direcotry already existed, downloading");
						switch (NEED.InstallHelpfuldebugger("https://github.com/tubaplayerdis/HelpfulDebugger/releases/download/v1.0/Helpful.Debugger.Release.v1.0.zip"))
						{
						case 0:
							NEED.ShowBox("Sucsesfully installed Helpful Debugger");
							
							break;
						case 1:
							NEED.ShowBox("the directory you specified did not exist");
							break;
						case 2:
							NEED.ShowBox("The URL test failed or failed to acces url");
							break;
						case 3:
							NEED.ShowBox("Faield to install Helpful debugger");
							break;
						}
						break;
					case 0:
						NEED.ShowBox("Created New Directory for Helpful_debugger");
						switch (NEED.InstallHelpfuldebugger("https://github.com/tubaplayerdis/HelpfulDebugger/releases/download/v1.0/Helpful.Debugger.Release.v1.0.zip"))
						{
						case 0:
							NEED.ShowBox("Sucsesfully installed Helpful Debugger");

							break;
						case 1:
							NEED.ShowBox("the directory you specified did not exist");
							break;
						case 2:
							NEED.ShowBox("The URL test failed or failed to acces url");
							break;
						case 3:
							NEED.ShowBox("Faield to install Helpful debugger: error with file");
							break;
						}
						break;
					}
				}
			}
									 

			void MarshalString(String^ s, std::string& os) {
				using namespace Runtime::InteropServices;
				const char* chars =
					(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				os = chars;
				Marshal::FreeHGlobal(IntPtr((void*)chars));
			}
				
			System::Void ChooseButton_Click(System::Object^ sender, System::EventArgs^ e) {
				
				if (ChooseInstallDirectory->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					AYO lel;
					std::string idk = "";
					String^ o = ChooseInstallDirectory->SelectedPath;
					MarshalString(o, idk);
					lel.SetInstallString(idk);
					String^ str2 = gcnew String(lel.ReturnInstallString().c_str());
					textBox1->Text = str2;
					lel.ShowBox(lel.ReturnInstallString());
				}

			}
			System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
				AYO p;				
				p.SetInstallString("C:\\Program Files\\Helpful_Debugger");
			}
	};
}
