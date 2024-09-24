#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
//
//vector<string>taskRoom(vector<string>& tasks) {
//    for (short room = 0; room < tasks.size(); room++) {
//        cout << room;
//    }
//
//    return tasks;
//}
//
//vector<string> deleting_the_last_case(vector<string>& tasks) {
//    string nameFaile = "tasks.txt";
//    ifstream file(nameFaile);
//
//    tasks.erase(remove_if(tasks.begin(), tasks.end(), [](const string& task) {
//        return task.empty();
//        }), tasks.end());
//    file.close();
//
//    return tasks;
//{
//
//vector<string> deleting_the_last_case(vector<string>& tasks) {
//    string nameFaile = "tasks.txt";
//    ofstream file(nameFaile);
//    tasks.pop_back();
//    file.close();
//
//    return tasks;
//}

vector<string> caseDeletion(vector<string> &tasks) {
    system("cls");
    string nameFile = "tasks.txt";
    //ofstream file(nameFile);
    /*ofstream file(nameFile, ios::out | ios::app | ios::binary);*/
    ifstream file(nameFile, ios::in | ios::binary);
    char choise;
    cout << "Beta! все дела удаляются!" << endl;
    cout << "1 - удалить все" << endl;
    cout << "2 - удалить выбранное дело" << endl;
    cout << "3 - удалить последние дело" << endl;

    cin >> choise;
    switch (choise)
    {
    case '1':
        tasks.clear();
        file.clear();
        file.close();
        cout << "все дела удалены!" << endl;
        break;
    case '2':
        if (tasks.empty()) {
            cout << "Список дел пуст." << endl;
        }
        else {
           cout << "Введите номер дела которое хотите удалить:" << endl;
            int room = -1;
            for (const auto& task : tasks) {
                ++room;
               cout << room << "- " << task << endl;
            }
            
            int deleteTask;
            cout << "номер дела для удаления: ";
            cin >> deleteTask;
            tasks.erase(tasks.begin() +deleteTask);
        }   
        file.close();
        break;
    case '3':
        //deleting_the_last_case(tasks);
        tasks.erase(remove_if(tasks.begin(), tasks.end(), [](const string& task) {
            return task.empty();
            }), tasks.end());

        tasks.pop_back();
        file.close();
        //cout << "";
        break;
    default:
        cout << "Неверный выбор. Пожалуйста, выберите от 1 до 3." << endl;
       /* cout << "введите чтобы продолжить: ";
        cin >> enter;*/
    }
 
    return tasks;
}

vector<string> loadFromFile() {
    setlocale(LC_ALL, "Rus");
    vector<string> tasks;
    string nameFile = "tasks.txt";
    //ifstream file(nameFaile);
    //ifstream file(nameFile, ios::out | ios::app | ios::binary);
    ifstream file(nameFile, ios::in | ios::binary);
    if (file.is_open()) {
        string task;
        while (getline(file, task)) {
            tasks.push_back(task);
        }
        file.close();
        cout << "The to-do list is loaded from a file." << endl;
    }
    else {
        cout << "File not found. A new file has been created." << endl;
    }

    return tasks;
}

void printTasks(vector<string>& tasks) {
    system("cls");
    if (tasks.empty()) {
        cout << "Список дел пуст." << endl;
    }
    else {
        cout << "Список дел на сегодня:" << endl;
        for (const auto& task : tasks) {
            cout << "- " << task << endl;
        }
    }
}

void saveToFile(vector<string>& tasks) {
    string nameFile = "tasks.txt";
    //ofstream file(nameFile);
    //ofstream file(nameFile, ios::out | ios::app | ios::binary);
    ofstream file(nameFile, ios::in | ios::binary);

    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task << endl;
        }
        file.close();
        cout << "To-do list loaded from file!" << endl;
    }
    else {
        cout << "\aError when trying to open the file!" << endl;
    }
}

int main() {

    setlocale(LC_ALL, "Rus");
    vector<string> tasks = loadFromFile();

    char choice, enter;
    while (true) {
        cout << endl << "(Beta-Version) Меню:" << endl;
        cout << "1. Добавить дело в список" << endl;
        cout << "2. Посмотреть список дел" << endl;
        cout << "3. удалить дело(afoot)" << endl;
        cout << "4. Выйти" << endl;

        cout << "Выберите действие (1-3): ";
        cin >> choice;

        switch (choice) {
        case '1': {
            system("cls");
            cin.ignore();
            string newTask;
            cout << "Русский язык не работает!" << endl;
            cout << "Введите новое дело: ";
            getline(cin, newTask);
            tasks.push_back(newTask);
            saveToFile(tasks);
            break;
        }
        case '2':
            printTasks(tasks);
            cout << "введите чтобы продолжить: ";
            cin >> enter;
            break;
        case '3':
            caseDeletion(tasks);
            cout << "введите чтобы продолжить: ";
            cin >> enter;
            break;
        case '4':
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите от 1 до 3." << endl;
            cout << "введите чтобы продолжить: ";
            cin >> enter;
        }
        system("cls");
    }

    return 0;
}
