#pragma once
#include "MainForm.h"
#include "ISM.h"

namespace TubaDLLInjector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditorForm
	/// </summary>
	public ref class EditorForm : public System::Windows::Forms::Form
	{
	public:
		EditorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	protected:

	private:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(276, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Thank you for installing Helpful Debugger";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(186, 527);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(153, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(11, 527);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Close and launch ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EditorForm::button2_Click);
			// 
			// EditorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(351, 574);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"EditorForm";
			this->Text = L"HDI - Done";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
