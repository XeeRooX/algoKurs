#pragma once
#include <Windows.h>
#include <msclr\marshal_cppstd.h>

namespace AlgoKursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ nodesTable;









	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ findedNodes;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	public: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ aircraftNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ destinationAirport;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ departureTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ arrivalTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numberOfPlaces;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ occupiedPlaces;





















	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->nodesTable = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->findedNodes = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->aircraftNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->destinationAirport = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->departureTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->arrivalTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numberOfPlaces = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->occupiedPlaces = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nodesTable))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->findedNodes))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(2, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(665, 380);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->panel3);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->nodesTable);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(657, 354);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Заполнение";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(3, 322);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(648, 25);
			this->panel3->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Location = System::Drawing::Point(3, 5);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(639, 15);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Здесь происходит заполнение, сохранение, загрузка данных о рейсах. ";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(374, 21);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(135, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Загрузить данные";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// nodesTable
			// 
			this->nodesTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->nodesTable->BackgroundColor = System::Drawing::SystemColors::WindowFrame;
			this->nodesTable->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->nodesTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->nodesTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->aircraftNumber,
					this->destinationAirport, this->departureTime, this->arrivalTime, this->numberOfPlaces, this->occupiedPlaces
			});
			this->nodesTable->Location = System::Drawing::Point(6, 50);
			this->nodesTable->Name = L"nodesTable";
			this->nodesTable->Size = System::Drawing::Size(645, 266);
			this->nodesTable->TabIndex = 1;
			this->nodesTable->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(515, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Сохранить данные";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->panel1);
			this->tabPage2->Controls->Add(this->findedNodes);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(657, 354);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Поиск";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &MyForm::tabPage2_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(6, 308);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(648, 39);
			this->panel1->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Location = System::Drawing::Point(3, 5);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(639, 29);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Прежде чем что-то найти выберете признак, по которому хотите искать. Далее введит"
				L"е данные в строку поиска и нажмите \"найти\".";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// findedNodes
			// 
			this->findedNodes->AllowUserToAddRows = false;
			this->findedNodes->AllowUserToDeleteRows = false;
			this->findedNodes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->findedNodes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->findedNodes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->findedNodes->Location = System::Drawing::Point(7, 52);
			this->findedNodes->Name = L"findedNodes";
			this->findedNodes->ReadOnly = true;
			this->findedNodes->Size = System::Drawing::Size(647, 250);
			this->findedNodes->TabIndex = 5;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Номер самолета";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Свободных мест";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Аэропорт назначения";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 150;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Время вылета";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button2->Location = System::Drawing::Point(575, 18);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Найти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBox1->Location = System::Drawing::Point(283, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(286, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Искать по:";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Номеру самолета", L"Названию аэропорта назначения" });
			this->comboBox1->Location = System::Drawing::Point(71, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(205, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->panel2);
			this->tabPage3->Controls->Add(this->button4);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->comboBox3);
			this->tabPage3->Controls->Add(this->comboBox2);
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->textBox2);
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(657, 354);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Купить билет";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Click += gcnew System::EventHandler(this, &MyForm::tabPage3_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Location = System::Drawing::Point(3, 295);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(648, 52);
			this->panel2->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->Location = System::Drawing::Point(3, 5);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(639, 42);
			this->label6->TabIndex = 0;
			this->label6->Text = resources->GetString(L"label6.Text");
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button4->Location = System::Drawing::Point(406, 86);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Купить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(301, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Время вылета:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(158, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Аэропорт назначения:";
			// 
			// comboBox3
			// 
			this->comboBox3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(284, 87);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(116, 21);
			this->comboBox3->TabIndex = 4;
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(157, 87);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button3->Location = System::Drawing::Point(406, 20);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Найти";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBox2->Location = System::Drawing::Point(255, 22);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(145, 20);
			this->textBox2->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(154, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Номер самолёта:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// aircraftNumber
			// 
			this->aircraftNumber->HeaderText = L"Номер самолета";
			this->aircraftNumber->Name = L"aircraftNumber";
			// 
			// destinationAirport
			// 
			this->destinationAirport->HeaderText = L"Аэропорт назначения";
			this->destinationAirport->Name = L"destinationAirport";
			// 
			// departureTime
			// 
			dataGridViewCellStyle1->Format = L"g";
			dataGridViewCellStyle1->NullValue = nullptr;
			this->departureTime->DefaultCellStyle = dataGridViewCellStyle1;
			this->departureTime->HeaderText = L"Время вылета";
			this->departureTime->Name = L"departureTime";
			// 
			// arrivalTime
			// 
			dataGridViewCellStyle2->Format = L"g";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->arrivalTime->DefaultCellStyle = dataGridViewCellStyle2;
			this->arrivalTime->HeaderText = L"Время прибытия";
			this->arrivalTime->Name = L"arrivalTime";
			// 
			// numberOfPlaces
			// 
			this->numberOfPlaces->HeaderText = L"Всего мест";
			this->numberOfPlaces->Name = L"numberOfPlaces";
			// 
			// occupiedPlaces
			// 
			this->occupiedPlaces->HeaderText = L"Билетов продано";
			this->occupiedPlaces->Name = L"occupiedPlaces";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 385);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Справочная система аэропорта";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nodesTable))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->findedNodes))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
bool IsEmptyRow(int a) 
{
	for (int b = 0; b < nodesTable->Rows[0]->Cells->Count; b++) 
	{
		/*richTextBox1->Text += "a: "+a+"b: "+b+"\n";
		String^ temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
		std::string temp = msclr::interop::marshal_as<std::string>(temp0);*/
		if (nodesTable->Rows[a]->Cells[b]->Value != nullptr)
		{
			//richTextBox1->Text += "НЕПусто!\n";
			return false;
		}
	}
	//richTextBox1->Text += "Пусто!\n";
	return true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (nodesTable->RowCount == 0) {
		nodesTable->Rows->Add();
		return;
	}
	else 
	{
		/*for (int a = 0; a < nodesTable->Rows[nodesTable->RowCount - 1]->Cells->Count; a++) {
			if (nodesTable->Rows[nodesTable->RowCount - 1]->Cells[a]->Value == NULL ||
				nodesTable->Rows[nodesTable->RowCount - 1]->Cells[a]->Value == nullptr
				|| nodesTable->Rows[nodesTable->RowCount - 1]->Cells[a]->Value == "") {
				nodesTable->Rows[0]->Cells[0]->Value = 99;
				return;
			}
				
		}*/
		nodesTable->Rows->Add();
	}
}
void RestartTable();
void ShowMsg(std::string msg);
bool CheckCorrect(int& x, int& y, std::string& errormsg);
bool IsCorrectTime(std::string time, int a, int b);
bool IsEmptyCell(int a, int b);
bool IsUnicalNum(int i);
void FindByNumberAir(int num);
void FindByDestinationAirport(std::string name);

private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tabPage3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

public: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);

	 /*  void LoadTable() {
		   
		   button5->PerformClick();
	  }*/
private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};

}
