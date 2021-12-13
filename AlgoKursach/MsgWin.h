#pragma once
#include <string>
namespace AlgoKursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MsgWin
	/// </summary>
	public ref class MsgWin : public System::Windows::Forms::Form
	{
	public:
		MsgWin(std::string msg, int a, int b)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			label1->Text = gcnew System::String(msg.c_str());
			label1->Text += "\n����� ������: " + (a+1) + ", ����� �������: " + (b+1);
		}
		MsgWin(System::String^ msg) 
		{
			InitializeComponent();
			label1->Text = msg;
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MsgWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"asdasdsadasdsadsadadssadsa";
			// 
			// MsgWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(666, 57);
			this->Controls->Add(this->label1);
			this->Name = L"MsgWin";
			this->Text = L"���������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
