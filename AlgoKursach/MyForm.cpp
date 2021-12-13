#pragma once
#include "MyForm.h"
#include "NodeHeader.h"
#include <Windows.h>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "MsgWin.h"
#include <fstream>

using namespace AlgoKursach;
using namespace std;

Node* Head;
Node* WeededN;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MyForm^ form = gcnew MyForm();

    Application::Run(form);
    /*form->button5->Click += gcnew System::EventHandler(form, &MyForm::button5_Click);
    form->button5->PerformClick();*/

    
    return 0;
}

// Загрузка из файла
void MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
    fstream file;
    file.open("file.txt");
    string data = "";
    bool IsFirstNode = true;
    Node* temp;
    Head = new Node();

    while (!file.eof()) 
    {
        Node* node = new Node();
        getline(file, data);
        string val = "";
        int numberVal = 1;
        for (int a = 0; a < data.length(); a++)
        {
            if (data[a] == '|') 
            {
                if (numberVal == 1) 
                {
                    node->aircraftNumber = stoi(val);
                    numberVal++;
                    val = "";
                }
                else if (numberVal == 2) 
                {
                    node->destinationAirport = val;
                    numberVal++;
                    val = "";
                }
                else if (numberVal == 3) 
                {
                    node->departureTime = val;
                    numberVal++;
                    val = "";
                }
                else if (numberVal == 4) 
                {
                    node->arrivalTime = val;
                    numberVal++;
                    val = "";
                }
                else if (numberVal == 5) 
                {
                    node->numberOfPlaces = stoi(val);
                    numberVal++;
                    val = "";
                }
                else if (numberVal == 6) 
                {
                    node->occupiedPlaces = stoi(val);
                    numberVal++;
                    val = "";
                }
            }
            else 
            {
                val += data[a];
            }
        }
        node->next = NULL;
        AddLast(Head, node);
    }
    file.close();
    RestartTable();
    
}
void MyForm::RestartTable()
{
    Node* tempN = Head;
    int rowCount = 0;

    nodesTable->Rows->Clear();

    while (tempN != NULL)
    {
        if (tempN->aircraftNumber == 0)
        {
            tempN = tempN->next;
            continue;
        }

        int aircraftNum;
        string destinationAiroport;
        string departureTime;
        string arrivalTime;
        int numberOfPlaces;
        int occupiedPlaces;

        aircraftNum = tempN->aircraftNumber;
        destinationAiroport = tempN->destinationAirport;
        departureTime = tempN->departureTime;
        arrivalTime = tempN->arrivalTime;
        numberOfPlaces = tempN->numberOfPlaces;
        occupiedPlaces = tempN->occupiedPlaces;

        //richTextBox1->Text += rowCount;



        nodesTable->Rows->Add();
        nodesTable->Rows[rowCount]->Cells[0]->Value = aircraftNum;
        nodesTable->Rows[rowCount]->Cells[1]->Value = gcnew System::String(destinationAiroport.c_str());
        nodesTable->Rows[rowCount]->Cells[2]->Value = gcnew System::String(departureTime.c_str());
        nodesTable->Rows[rowCount]->Cells[3]->Value = gcnew System::String(arrivalTime.c_str());
        nodesTable->Rows[rowCount]->Cells[4]->Value = numberOfPlaces;
        nodesTable->Rows[rowCount]->Cells[5]->Value = occupiedPlaces;

        tempN = tempN->next;
        rowCount++;
    }
}
// Покупка билета
// Найти билет
void MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
    Node* FindedNodes;

    String^ temp = textBox2->Text->ToString();
    string val = msclr::interop::marshal_as<std::string>(temp);
    if (val.size() == 0) {
        ShowMsg("Введите номер самолета, по которому нужно найти рейсы");
        return;
    }
    for (int a = 0; a < val.size(); a++)
    {
        if (!isdigit(val[a]))
        {
            ShowMsg("Для поиска нужно вводить число!");
            return;
        }
    }

    FindByAirNumber(Head, stoi(val), FindedNodes);
    // Теперь нужно отсеить заполненные рейсы
    Node* WeededNodes = NULL; 
    Node* tempn = FindedNodes;
    while (tempn != NULL) 
    {
        //richTextBox1->Text += (tempn->numberOfPlaces)+"  "+(tempn->occupiedPlaces) + " YOU";
        if ((tempn->numberOfPlaces - tempn->occupiedPlaces) > 0) 
        {
            Node* nNode = new Node();
            nNode->aircraftNumber = tempn->aircraftNumber;
            nNode->destinationAirport = tempn->destinationAirport;
            nNode->departureTime = tempn->departureTime;
            nNode->arrivalTime = tempn->arrivalTime;
            nNode->numberOfPlaces = tempn->numberOfPlaces;

            AddFirst(WeededNodes, nNode);
        }
        tempn = tempn->next;
    }


    if (WeededNodes == NULL) {
        ShowMsg("Все рейсы самолета с данным номером заняты.");
        return;
    }
    else
    {
        comboBox2->Items->Clear();
        WeededN = WeededNodes;
        Node* nNode = WeededNodes;
        while (nNode != NULL) 
        {
            bool itUnical = true;
            System::String^ destAir = gcnew System::String(nNode->destinationAirport.c_str());
            for (int a = 0; a < comboBox2->Items->Count; a++) {
                if (destAir == comboBox2->Items[a]->ToString()) {
                    itUnical = false;
                    break;
                }
            }
            if(itUnical == true)
                comboBox2->Items->Add(destAir);
            nNode = nNode->next;
        }
    }

 

}

void MyForm::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
    // Теперь нужно во второй комбобокс записать свободные времена(что) вылета
    comboBox3->Items->Clear();

    Node* WeededNodes = NULL;

    String^ tempname = comboBox2->Text->ToString();
    string name = msclr::interop::marshal_as<std::string>(tempname);

    FindByNameAirpot(WeededN, name, WeededNodes);
    Node* tempn = WeededNodes;
    while (tempn != NULL)
    {
        comboBox3->Items->Add(gcnew System::String(tempn->departureTime.c_str()));
        tempn = tempn->next;
    }
}
// Купить билет
void MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
    int airNumber;
    string destinationAir;
    string departureTime;

    String^ tempval = textBox2->Text->ToString();
    string val = msclr::interop::marshal_as<std::string>(tempval);
    if (val == "") {
        ShowMsg("Введите номер самолета");
        return;
    }
    airNumber = stoi(val);
    
    tempval = comboBox2->Text->ToString();
    val = msclr::interop::marshal_as<std::string>(tempval);
    if (val == "") {
        ShowMsg("Выберете аэропорт назначения");
        return;
    }
    destinationAir = val;

    tempval = comboBox3->Text->ToString();
    val = msclr::interop::marshal_as<std::string>(tempval);
    if (val == "") {
        ShowMsg("Выберете время вылета");
        return;
    }
    departureTime = val;

    Node* tempNode = Head;;
    /*FindByAirNumber(Head, airNumber, FindedNodes);
    Node* WeededNodes;
    FindByNameAirpot(FindedNodes, destinationAir, WeededNodes);*/
    while (tempNode != NULL) 
    {
        if (tempNode->aircraftNumber == airNumber &&
            tempNode->destinationAirport == destinationAir
            && tempNode->departureTime == departureTime) 
        {
            tempNode->occupiedPlaces++;
        }
        tempNode = tempNode->next;
    }

    textBox2->Text = "";
    comboBox2->Text = "";
    comboBox3->Text = "";

    comboBox2->Items->Clear();
    comboBox3->Items->Clear();

    RestartTable();
}

// Поиск

void MyForm::FindByNumberAir(int num) 
{
    Node* FindedNodes = NULL;
    FindByAirNumber(Head, num, FindedNodes);
    //richTextBox1->Text += "NUM: " + num + "\n";

    if (FindedNodes == NULL)
    {
        ShowMsg("Ничего не найдено.");
    }
    else 
    {
        // очистка таблицы
        while (findedNodes->Rows->Count != 0) 
        {
            findedNodes->Rows->RemoveAt(0);
        }
        Node* temp = FindedNodes;
        int a = 0;
        while (temp != NULL) 
        {
            System::String^ str = gcnew System::String(
                temp->destinationAirport.c_str());
            //richTextBox1->Text += str + "\n";
            findedNodes->Rows->Add();
            findedNodes->Rows[a]->Cells[0]->Value = temp->aircraftNumber;
            findedNodes->Rows[a]->Cells[1]->Value = (temp->numberOfPlaces - temp->occupiedPlaces);
             str = gcnew System::String(
                temp->destinationAirport.c_str());
            findedNodes->Rows[a]->Cells[2]->Value = str;
            str = gcnew System::String(
                temp->departureTime.c_str());
            findedNodes->Rows[a]->Cells[3]->Value = str;
            temp = temp->next;
            a++;
        }
    }
}
void MyForm::FindByDestinationAirport(std::string name) 
{
    Node* FindedNodes = NULL;
    FindByNameAirpot(Head, name, FindedNodes);
    if (FindedNodes == NULL)
    {
        ShowMsg("Ничего не найдено.");
    }
    else 
    {
        // очистка таблицы
        while (findedNodes->Rows->Count != 0)
        {
            findedNodes->Rows->RemoveAt(0);
        }
        Node* temp = FindedNodes;
        int a = 0;
        while (temp != NULL)
        {
            System::String^ str = gcnew System::String(
                temp->destinationAirport.c_str());
           // richTextBox1->Text += str + "\n";
            findedNodes->Rows->Add();
            findedNodes->Rows[a]->Cells[0]->Value = temp->aircraftNumber;
            findedNodes->Rows[a]->Cells[1]->Value = (temp->numberOfPlaces - temp->occupiedPlaces);
            str = gcnew System::String(
                temp->destinationAirport.c_str());
            findedNodes->Rows[a]->Cells[2]->Value = str;
            str = gcnew System::String(
                temp->departureTime.c_str());
            findedNodes->Rows[a]->Cells[3]->Value = str;
            temp = temp->next;
            a++;
        }
    }
}

void MyForm::ShowMsg(std::string msg)
{
    System::String^ msg1 = gcnew System::String(msg.c_str());
    //richTextBox1->Text += msg1 + "\n";
    MsgWin^ w = gcnew MsgWin(msg1);
   
    w->Show();
}

void MyForm::button2_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
    // Если пусто значение, то по стандарту выбрать поиск по номеру самолета
    if (comboBox1->Text->ToString() == "")
    {
        //richTextBox1->Text += "Пустой комбо! \n";
        comboBox1->Text = comboBox1->Items[0]->ToString();
    }
    // Если выбран поиск по номеру самолета
    if (comboBox1->Text->ToString() == comboBox1->Items[0]->ToString()) 
    {
        String^ temp = textBox1->Text->ToString();
        string val = msclr::interop::marshal_as<std::string>(temp);
        if (val.size() == 0) {
            ShowMsg("Введите номер самолета, по которому нужно найти рейсы");
            return;
        }
        for (int a = 0; a < val.size(); a++) 
        {
            if (!isdigit(val[a])) 
            {             
                ShowMsg("Для поиска информации о рейсе по номеру самолета нужно вводить число!");
                return;
            }           
        }
        FindByNumberAir(stoi(val));
    }
    else if (comboBox1->Text->ToString() == comboBox1->Items[1]->ToString()) 
    {
        String^ temp = textBox1->Text->ToString();
        string val = msclr::interop::marshal_as<std::string>(temp);
        if (val.size() == 0) {
            ShowMsg("Введите название аэропорта назначения, по которому нужно найти рейсы");
            return;
        }
        FindByDestinationAirport(val);
    }
}

// Ввод заполнение и сохранение в файл
void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
    string errormsg;
    int a, b;
    if (!CheckCorrect(a, b, errormsg)) {
        MsgWin^ w = gcnew MsgWin(errormsg, a,b);
        w->Show();
    }
    else {
     // Формирование односвязного списка
        // Обновление башки
        Head = new Node();
        for (int a = 0; a < nodesTable->Rows->Count; a++) 
        {
            int aircraftNum;
            string destinationAiroport;
            string departureTime;
            string arrivalTime;
            int numberOfPlaces;
            int occupiedPlaces;

            if (IsEmptyRow(a)) continue;
            
            String^ temp = nodesTable->Rows[a]->Cells[0]->Value->ToString();
            string val = msclr::interop::marshal_as<std::string>(temp);
            aircraftNum = stoi(val);
            
            temp = nodesTable->Rows[a]->Cells[1]->Value->ToString();
            val = msclr::interop::marshal_as<std::string>(temp);
            destinationAiroport = val;

            temp = nodesTable->Rows[a]->Cells[2]->Value->ToString();
            val = msclr::interop::marshal_as<std::string>(temp);
            departureTime = val;

            temp = nodesTable->Rows[a]->Cells[3]->Value->ToString();
            val = msclr::interop::marshal_as<std::string>(temp);
            arrivalTime = val;

            temp = nodesTable->Rows[a]->Cells[4]->Value->ToString();
            val = msclr::interop::marshal_as<std::string>(temp);
            numberOfPlaces = stoi(val);

            temp = nodesTable->Rows[a]->Cells[5]->Value->ToString();
            val = msclr::interop::marshal_as<std::string>(temp);
            occupiedPlaces = stoi(val);

            Node* newNode = new Node();
            newNode->aircraftNumber = aircraftNum;
            newNode->destinationAirport = destinationAiroport;
            newNode->departureTime = departureTime;
            newNode->arrivalTime = arrivalTime;
            newNode->numberOfPlaces = numberOfPlaces;
            newNode->occupiedPlaces = occupiedPlaces;

            
            AddLast(Head, newNode);
        }

        string data = "";
        Node* tempN = Head;

        while (tempN!=NULL) 
        {
            if (tempN->aircraftNumber == 0) 
            {
                tempN = tempN->next;
                continue;
            }
            int aircraftNum;
            string destinationAiroport;
            string departureTime;
            string arrivalTime;
            int numberOfPlaces;
            int occupiedPlaces;

            aircraftNum = tempN->aircraftNumber;
            destinationAiroport = tempN->destinationAirport;
            departureTime = tempN->departureTime;
            arrivalTime = tempN->arrivalTime;
            numberOfPlaces = tempN->numberOfPlaces;
            occupiedPlaces = tempN->occupiedPlaces;

            string stick = "|";
            data += to_string(aircraftNum).c_str() + stick + destinationAiroport + stick
                + departureTime + stick + arrivalTime + stick + to_string(numberOfPlaces).c_str()
                +stick+to_string(occupiedPlaces).c_str()+ stick + "\n";

            tempN = tempN->next;
        }
        //;rlgkjerlgjertpligjutpgoerutgpoeirtug';oertiugiurygelifufhyeriujghertligiuhertligguherlgkuehtgilerytgoiuerytogiurtyogertuhygikertuygeilrurhgeoritugherlitgherlighyertiugherlogtiyhytgvlertygiuddfhgliergfh;ergrheroihgeoiuuioeygoiywgioyweroiyiweffihyowefegvkierhflgerhglkergtlkejrhblehrgblkhergb
       // richTextBox1->Text = gcnew System::String(data.c_str());
        ofstream file;
        file.open("file.txt");
        file << data;
        file.close();
        // Вывод всех нодов в richTextBox
        //Node* temp = Head;
        //while (temp != NULL) {
        //    richTextBox1->Text += temp->aircraftNumber + "\n";
        //    temp = temp->next;
        //}
    }
}
bool MyForm::IsCorrectTime(string time, int a, int b) 
{
    if (isdigit(time[0]) && isdigit(time[1]) && time[2] == ':' &&
        isdigit(time[3]) && isdigit(time[4]) && time[5] == ' '&&
        isdigit(time[6])&& isdigit(time[7])&& time[8] == '.'&&
        isdigit(time[9]) && isdigit(time[10]) && time[11] == '.'&&
        isdigit(time[12]) && isdigit(time[13])&& isdigit(time[14]) && isdigit(time[15]) &&
        time.size() == 16)
    {
        // Проверка на нормальное время
        if ((time[0] == '2' && (time[1] >= '0' && time[1] <= '3')
            || ((time[0] >= '0' && time[0] <= '1') && (time[1] >= '0' && time[1] <= '9'))) &&
            (time[3] >= '0' && time[3] <= '5') && (time[4] >= '0' && time[4] <= '9')) 
        {
          
            return true;
        }
       
    }       
    else
        return false;
}
bool MyForm::IsUnicalNum(int i) 
{
    String^ temp0 = nodesTable->Rows[i]->Cells[0]->Value->ToString();
    string numi = msclr::interop::marshal_as<std::string>(temp0);
   
    for (int a = 0; a < nodesTable->Rows->Count; a++) 
    {
        if (IsEmptyCell(a, 0)) continue;
        //richTextBox1->Text += "\n" + a + " PUTINNNNN \n";
        String^ temp = nodesTable->Rows[a]->Cells[0]->Value->ToString();
        string numa = msclr::interop::marshal_as<std::string>(temp);
        if (a != i && numa == numi)
        {
            if (nodesTable->Rows[i]->Cells[2]->Value->ToString() == nodesTable->Rows[a]->Cells[2]->Value->ToString() ||
                nodesTable->Rows[i]->Cells[3]->Value->ToString() == nodesTable->Rows[a]->Cells[3]->Value->ToString())
            {
                //richTextBox1->Text += "\n a:" + a + " i:" + i + " \n";
                return false;
            }
        }
    }
    return true;
    //nodesTable->
}
bool MyForm::CheckCorrect(int& x, int& y, std::string& errormsg) 
{
    int c = nodesTable->Rows->Count;
    for (int a = 0; a < c; a++)
    {
       // richTextBox1->Text += "AAAAA: " + a + "\n"+ nodesTable->Rows->Count+"<<<<";
        if (IsEmptyRow(a)) 
        {
            continue;
        }
        for (int b = 0; b < nodesTable->Columns->Count; b++) 
        {
           // richTextBox1->Text += b + "\n" + " "+nodesTable->Columns->Count;
            // Также нужно все проверить на пустые ячейки
            switch (b)
            {
                //Номер самолета
            case 0:
            {
                if (IsEmptyCell(a, b)) 
                {
                    errormsg = "Ячейка пуста!";
                    x = a;
                    y = b;
                    return false;
                }
                String^ temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
                string temp = msclr::interop::marshal_as<std::string>(temp0);
                for (int i = 0; i < temp.length(); i++)
                {
                    if (!isdigit(temp[i])) {
                       // richTextBox1->Text += temp[i]+ " \n";
                        errormsg = "Номер самолета может быть только числом";
                        x = a;
                        y = b;
                        return false;
                    }
                        
                }
                // Проверка номера на уникальность
                // Нифига лн не должен быть уникальным
                if (!IsUnicalNum(a)) {
                    errormsg = "Время отправки/посадки не может повторятся у одного и того же самолета.";
                    x = a;
                    y = 3;
                    return false;
                }
                break;
            }
            case 1:
            {
                if (IsEmptyCell(a, b))
                {
                    errormsg = "Ячейка пуста!";
                    x = a;
                    y = b;
                    return false;
                }
                break;
            }
            // Время вылета
            case 2: 
            {
                if (IsEmptyCell(a, b))
                {
                    errormsg = "Ячейка пуста!";
                    x = a;
                    y = b;
                    return false;
                }
                String^ temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
                string time = msclr::interop::marshal_as<std::string>(temp0);
                if (!IsCorrectTime(time, a, b)) 
                {
                    //richTextBox1->Text += "Неправильно введено время" + "\n";
                    errormsg = "Неправильно введено время! Время указывается в формате: ЧЧ:ММ.";
                    x = a;
                    y = b;
                    return false;
                }
                break;
            }
            // Ориентированное время прибытия
            case 3:
            {
                if (IsEmptyCell(a, b))
                {
                    errormsg = "Ячейка пуста!";
                    x = a;
                    y = b;
                    return false;
                }
                String^ temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
                string time = msclr::interop::marshal_as<std::string>(temp0);
                if (!IsCorrectTime(time, a, b))
                {
                    //richTextBox1->Text += "Неправильно введено время" + "\n";
                    errormsg = "Неправильно введено время! Время указывается в формате: ЧЧ:ММ.";
                    x = a;
                    y = b;
                    return false;
                }
                break;
            }
            // Общее число мест
            case 4:
            {
                if (IsEmptyCell(a, b))
                {
                    errormsg = "Ячейка пуста!";
                    x = a;
                    y = b;
                    return false;
                }
                String^ temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
                string temp = msclr::interop::marshal_as<std::string>(temp0);

                if (temp.length() <= 3)
                {
                    for (int a = 0; a < temp.length(); a++) {
                        if (!isdigit(temp[a]))
                        {
                            errormsg = "Неправильно указано общее колличество мест рейса. Количество должно быть указано числом, максимум трёхзначным.";
                            x = a;
                            y = b;
                            return false;
                        }
                    }
                }
                else
                {
                    errormsg = "Неправильно указано общее колличество мест рейса. Количество должно быть указано числом, максимум трёхзначным.";
                    x = a;
                    y = b;
                    return false;
                }

                b = 5;
                /// ///// /// /// /// /// 
                //richTextBox1->Text += "asdsadsadsad \n";
                if (IsEmptyCell(a, b))
                {
                    errormsg = "Ячейка пуста!";
                    x = a;
                    y = b;
                    return false;
                }
                 temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
                 temp = msclr::interop::marshal_as<std::string>(temp0);

                if (temp.length() <= 3)
                {
                    for (int a = 0; a < temp.length(); a++) {
                        if (!isdigit(temp[a]))
                        {
                            errormsg = "Неправильно указано колличество купленных мест. Количество должно быть указано числом, максимум трёхзначным.";
                            x = a;
                            y = b;
                            return false;
                        }
                    }
                }
                else
                {
                    errormsg = "Неправильно указано колличество купленных мест. Количество должно быть указано числом, максимум трёхзначным.";
                    x = a;
                    y = b;
                    return false;
                }

                String^ temp1 = nodesTable->Rows[a]->Cells[b - 1]->Value->ToString();
                string buyPlaces = msclr::interop::marshal_as<std::string>(temp1);
                // Наоборот temp - buyPlaces
                //richTextBox1->Text += "я тут!! \n";
                if (stoi(temp) > stoi(buyPlaces))
                {
                    errormsg = "Колличество купленных мест должно быть меньше или равно количеству мест всего.";
                    x = a;
                    y = b;
                    return false;
                }
                //richTextBox1->Text += "я тут2!! \n";
                //richTextBox1->Text += "-> " + stoi(temp) + " " + stoi(buyPlaces);
                //

                break;
                //return true;
                //break;
            }
      
           
            default:
                break;
            }
        }
       
    }
    return true;
}
bool MyForm::IsEmptyCell(int a, int b) 
{
    

    if (nodesTable->Rows[a]->Cells[b]->Value == nullptr ||
        nodesTable->Rows[a]->Cells[b]->Value == NULL)
        return true;
    else
    {
        String^ temp0 = nodesTable->Rows[a]->Cells[b]->Value->ToString();
        string val = msclr::interop::marshal_as<std::string>(temp0);
        if (val.size() == 0)
            return true;
        return false;
    }
    
}