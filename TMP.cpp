#include <iostream>
#include <windows.h>
using namespace std;

class Arr{
private:
    int size;
public:
    int *mass;
    Arr(int s){
        int p = 0;
        size = s;
        mass = new int[size];
        while (p < size){
            mass[p] = 0;
            p++;
        }
    }
    ~Arr(){
        delete []mass;
    }
    void Create();
    void BoubbleSort();
    void SimpleSort();
    void InsertionSort();
    void Show();


};
void Arr :: Create(){
    int p = 0, n;
    cout << "Введите:";
    while (p < this->size){
        cin >> n;
        mass[p] = n;
        p++;
    }
}
void Arr :: Show(){
    int p = 0;
    while (p < this->size){
        cout << mass[p] << " ";
        p++;
    }
    cout << endl;
}
void Arr :: BoubbleSort(){
    int i = 0, j;

    while (i < size){
            j = 0;
        while (j+1 < size){
            if (mass[j] > mass[j+1])
                swap(mass[j],mass[j+1]);
            j++;
        }
        i++;
    }

}
void Arr :: SimpleSort(){
    int p = 0, i = 0, j;
    while (i < size-1)
    {
        j = i+1;
        p = i;
        while (j < size)
        {
            if (mass[p] > mass[j])
            p = j;
            j++;
        }
        if (mass[i] != mass[p])
            swap(mass[p],mass[i]);
        i++;
    }
}
void Arr :: InsertionSort(){
    int p;
    for (int i = 1, j; i < size; ++i) //цикл проходов i - номер прохода
    {
        p = mass[i];
        for (j = i - 1; j >= 0 && mass[j] > p; j--) //Поиск места элемента в готовой последовательности
            mass[j + 1] = mass[j]; //сдвигаем элемент направо, пока не дошли
        mass[j + 1] = p; // место найдено, вставить элемент
    }
}
void Test(){
    int i = 10, p;
    Arr arr1(i);
    int mass1[10] = {1, 1, 5, 75, 3, 24, 64, 1024, 54, 72};
    int mass2[10] = {1, 1, 3, 5, 24, 54, 64, 72, 75, 1024};
    for(i = 0; i < 10; i++){
        arr1.mass[i] = mass1[i];
    }
    ///BoubbleSort 1///
    cout << "Testing BoubbleSort..." << endl;
    arr1.BoubbleSort();
    for(i = 0, p = 0; i < 10; i++){
        if (arr1.mass[i] == mass2[i])
            p++;
    }
    if (p == 10){
        cout << "OK" << endl;
    }else{
        cout << "ERROR!\a" << endl;
        cout << "Expected: 1, 1, 3, 5, 24, 54, 64, 72, 75, 1024." << endl;
        cout << "Received: ";
        arr1.Show();
    }
    arr1.~Arr();

    ///SimpleSort 2///
    cout << "Testing SimpleSort..." << endl;
    i = 10;
    Arr arr2(i);
    for(i = 0; i < 10; i++){
        arr2.mass[i] = mass1[i];
    }
    arr2.SimpleSort();
    for(i = 0, p = 0; i < 10; i++){
        if (arr2.mass[i] == mass2[i])
            p++;
    }
    if (p == 10){
        cout << "OK" << endl;
    }else{
        cout << "ERROR!\a" << endl;
        cout << "Expected: 1, 1, 3, 5, 24, 54, 64, 72, 75, 1024." << endl;
        cout << "Received: ";
        arr2.Show();
    }
    arr2.~Arr();

    ///InsertionSort 2///
    cout << "Testing InsertionSort..." << endl;
    i = 10;
    Arr arr3(i);
    for(i = 0; i < 10; i++){
        arr3.mass[i] = mass1[i];
    }
    arr2.InsertionSort();
    for(i = 0, p = 0; i < 10; i++){
        if (arr3.mass[i] == mass2[i])
            p++;
    }
    if (p == 10){
        cout << "OK" << endl;
    }else{
        cout << "ERROR!\a" << endl;
        cout << "Expected: 1, 1, 3, 5, 24, 54, 64, 72, 75, 1024." << endl;
        cout << "Received: ";
        arr3.Show();
    }
    arr3.~Arr();


}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i, p;
    cout << "1 - Создать массив\n2 - Провести тест\n->";
    cin >> p;
    if (p == 2){
        Test();
    }else if (p == 1){
        system("cls");
        cout << "Сколько элементов будет содержать массив?\n->";
        cin >> i;
        Arr arr1(i);
        arr1.Create();
        arr1.Show();
        cout << "\nКакую сортировку хотите провести?\n1 - Boubble sort\n2 - Simple sort\n3 - Insertion sort\n->";
        cin >> p;
        if (p == 1){
            system("cls");
            cout << "BoubbleSort..." << endl;
            arr1.Show();
            arr1.BoubbleSort();
            arr1.Show();
        }else if (p == 2){
            system("cls");
            cout << "SimpleSort..." << endl;
            arr1.Show();
            arr1.SimpleSort();
            arr1.Show();
        }else if (p == 3){
            system("cls");
            cout << "InsertionSort..." << endl;
            arr1.Show();
            arr1.InsertionSort();
            arr1.Show();
        }else{
            cout << "Неверный ввод!";
        }
    }else{
    cout << "Неверный ввод!";
    }
    return 0;
}
