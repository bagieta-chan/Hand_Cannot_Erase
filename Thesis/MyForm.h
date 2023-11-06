#include "MyForm1.h"



#pragma once




namespace Thesis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;
	using namespace System::Timers;

	

	ref class Myform1;

	//using namespace System::Windows::Forms::DataVisuali

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		

	public:
		MyForm(void)
		{
			InitializeComponent();			
		}


	protected:
	
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::ComboBox^ SerialBox;

	private: System::Windows::Forms::ComboBox^ BaudBox;
	private: System::Windows::Forms::ComboBox^ stopBitBox;
	private: System::Windows::Forms::ComboBox^ parityBox;
	private: System::Windows::Forms::Button^ ConnectionButton;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ send;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	
	private: System::ComponentModel::IContainer^ components;
	private: array<Int32^>^ baudRateArr;
	private: array<String^>^ stopBitsArr;
	private: array<String^>^ parityArr;
	protected: array<String^>^ fingersData;
	public:  array<Int32>^ fingers_numeric = gcnew array<Int32>(5); 
	
	
	
		/// <summary>
	 
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SerialBox = (gcnew System::Windows::Forms::ComboBox());
			this->BaudBox = (gcnew System::Windows::Forms::ComboBox());
			this->ConnectionButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->send = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->stopBitBox = (gcnew System::Windows::Forms::ComboBox());
			this->parityBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
	
			//
			// arrays for comboBoxes 	
			// 	
			 this->baudRateArr = gcnew array<Int32^>{9600, 19200, 38400, 57600, 115200};
			 this->stopBitsArr = gcnew array<String^>{"1", "1.5", "2"};
			 this->parityArr = gcnew array<String^>{"none", "even", "odd"};
			 this->fingersData = gcnew array<String^>(5);


			
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 115200;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Serial Port";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(12, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Baud Rate";
			
			// 
			// SerialBox
			// 
			this->SerialBox->FormattingEnabled = true;
			this->SerialBox->Location = System::Drawing::Point(124, 10);
			this->SerialBox->Name = L"SerialBox";
			this->SerialBox->Size = System::Drawing::Size(121, 21);
			this->SerialBox->TabIndex = 2;
			// 
			// BaudBox
			// 
			this->BaudBox->FormattingEnabled = true;
			this->BaudBox->Location = System::Drawing::Point(124, 50);
			this->BaudBox->Name = L"BaudBox";
			this->BaudBox->Size = System::Drawing::Size(121, 21);
			this->BaudBox->TabIndex = 3;
			// 
			// ConnectionButton
			// 
			this->ConnectionButton->BackColor = System::Drawing::Color::DarkGray;
			this->ConnectionButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ConnectionButton->Location = System::Drawing::Point(124, 180);
			this->ConnectionButton->Name = L"ConnectionButton";
			this->ConnectionButton->Size = System::Drawing::Size(121, 39);
			this->ConnectionButton->TabIndex = 4;
			this->ConnectionButton->Text = L"Connect";
			this->ConnectionButton->UseVisualStyleBackColor = false;
			this->ConnectionButton->Click += gcnew System::EventHandler(this, &MyForm::ConnectionButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(270, 9);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(500, 440);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(270, 455);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 6;
			// 
			// send
			// 
			this->send->Location = System::Drawing::Point(376, 455);
			this->send->Name = L"send";
			this->send->Size = System::Drawing::Size(75, 20);
			this->send->TabIndex = 7;
			this->send->Text = L"button1";
			this->send->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(12, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 24);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Parity";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(12, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 24);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Stop Bits";
			// 
			// stopBitBox
			// 
			this->stopBitBox->FormattingEnabled = true;
			this->stopBitBox->Location = System::Drawing::Point(124, 90);
			this->stopBitBox->Name = L"stopBitBox";
			this->stopBitBox->Size = System::Drawing::Size(121, 21);
			this->stopBitBox->TabIndex = 10;
			
			// 
			// parityBox
			// 
			this->parityBox->FormattingEnabled = true;
			this->parityBox->Location = System::Drawing::Point(124, 130);
			this->parityBox->Name = L"parityBox";
			this->parityBox->Size = System::Drawing::Size(121, 21);
			this->parityBox->TabIndex = 11;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(794, 552);
			this->Controls->Add(this->stopBitBox);
			this->Controls->Add(this->parityBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->send);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ConnectionButton);
			this->Controls->Add(this->BaudBox);
			this->Controls->Add(this->SerialBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"HandSerial";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
			
		}
#pragma endregion	


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		//downloading ports data that the system has
		array<Object^>^ port = SerialPort::GetPortNames();
		SerialBox->Items->AddRange(port);
		SerialBox->SelectedIndex = 0;

		BaudBox->Items->AddRange(this->baudRateArr);
		stopBitBox->Items->AddRange(this->stopBitsArr);
		parityBox->Items->AddRange(this->parityArr);

		//Initialselection of frame data
		BaudBox->SelectedIndex = 0;
		stopBitBox->SelectedIndex = 0;
		parityBox->SelectedIndex = 0;
	}

	private: System::Void ConnectionButton_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			if (ConnectionButton->Text == "Connect") {				
				textBox1->Clear();
				textBox1->AppendText("Connecting ");
				System::Threading::Thread::Sleep(1000);
				if (serialPort1->IsOpen) {
					serialPort1->Close();
				}
				textBox1->Clear();
				textBox1->AppendText("Connected! ");
				SerialInit();
				System::Threading::Thread::Sleep(500);
				textBox1->Clear();
				openNewWindow();
				serialPort1->PortName = SerialBox->Text;
					
				serialPort1->Open();
				ConnectionButton->Text = "Disconnect";
					
			}
			else if (ConnectionButton->Text == "Disconnect")
			{
				serialPort1->Close();
				ConnectionButton->Text = "Connect";
			}
		}
		catch (...) {
			textBox1->Clear();
			MessageBox::Show("An error occured");
		}
	}
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {

		String^ dataRead = serialPort1->ReadLine();

		String^ currentNumber = "";

		for (int i = 0; i < dataRead->Length; i++) {
			Char c  = dataRead[i];
			if (Char::IsDigit(c)) {
				currentNumber += c;  // Append the digit character
			}
			else {
				if (c != 0)
				{
					if (c == 'T') {
						fingers_numeric[0] = Convert::ToInt32(currentNumber);
						this->fingersData[0] = currentNumber;
					}
					else if (c == 'I') {
						fingers_numeric[1] = Convert::ToInt32(currentNumber);
						this->fingersData[1] = currentNumber;
					}
					else if (c == 'M') {
						fingers_numeric[2] = Convert::ToInt32(currentNumber);
						this->fingersData[2] = currentNumber;
					}
					else if (c == 'R') {
						fingers_numeric[3] = Convert::ToInt32(currentNumber);
						this->fingersData[3] = currentNumber;
					}
					else if (c == 'P') {
						fingers_numeric[4] = Convert::ToInt32(currentNumber);
						this->fingersData[4] = currentNumber;
						
					}
					currentNumber = " ";
				}
			}
		}
		if (currentNumber != "") {}
		for (int i = 0; i < 5; i++)
		{
			if (fingersData[i] == nullptr)
			{
				return;
			}
		}
		for (int i = 0; i<5 ; i++)
		{
			if (fingersData[i] != nullptr)
			{
				this->textBox1->AppendText(fingersData[i] + " ");
			}
		}
		this->textBox1->AppendText("\r\n");

	}

	System::Void AcquireMeasureData(array<String^>^ data, String^ dataToExtract){
		String^ dataRead = serialPort1->ReadLine();


	}

	 System::Void openNewWindow()
	 {
		 if (!MyForm1::openedGraph)
		 {
			 MyForm1::openedGraph = true;
			 MyForm1^ graph = gcnew MyForm1();
			 graph->TopMost;
			 graph->Show();
		 }
		 
	 } 

	 System::Void SerialInit()
	 {
		 serialPort1->BaudRate = Int32::Parse(BaudBox->Text);
		 if (stopBitBox->Text == stopBitsArr[0]) { serialPort1->StopBits = StopBits::One; }
		 else if (stopBitBox->Text == stopBitsArr[1]) { serialPort1->StopBits = StopBits::OnePointFive; }
		 else if (stopBitBox->Text == stopBitsArr[2]) { serialPort1->StopBits = StopBits::Two; }

		 if (parityBox->Text == parityArr[0]) { serialPort1->Parity = Parity::None; }
		 else if (parityBox->Text == parityArr[1]) { serialPort1->Parity = Parity::Even; }
		 else if (parityBox->Text == parityArr[2]) { serialPort1->Parity = Parity::Odd; }

		 serialPort1->BaudRate = Int32::Parse(BaudBox->Text);
		 

	 }


};
}
