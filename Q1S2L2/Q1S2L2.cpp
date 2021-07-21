#include <iostream>
#include <locale>

using namespace std;

enum sex { MAN, WOMAN };

class Person {
protected:
    string name;
    int age;
    int weight;
    sex sx;
public:
    Person() : Person("", 0, 0, MAN) {
    }
    Person(string nm, int ag, int wt, sex sx_tmp) : name(nm), age(ag), weight(wt), sx(sx_tmp) {
    }
    Person& setName(string nm) {
        name = nm;
        return *this;
    }
    Person& setAge(int ag) {
        age = ag;
        return *this;
    }
    Person& setWeight(int wt) {
        weight = wt;
        return *this;
    }
    Person& setSex(sex sx) {
        this->sx = sx;
        return *this;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    int getWeight() const {
        return weight;
    }
    sex getSex() const {
        return sx;
    }
};

class Student : public Person {
private:
    int year;
    static int count;
public:
    Student() : Student("", 0, 0, MAN, 0) {
    }
    Student(string nm, int ag, int wt, sex sx, int yr) : year(yr), Person(nm, ag, wt, sx) {
        count++;
        cout << "Новый студент, экзмепляров класса: " << count << endl << "Имя: " << name << endl << "Возраст: " << age << endl << "Вес: " << weight << endl << "Пол: " << sx << endl << "Год обучения: " << year << endl << endl;
    }
    ~Student() {
        count--;
        cout << "Экземпляров класса Student: " << count << endl;
    }
    Student& setYear(int yr) {
        year = yr;
        return *this;
    }
    Student& toNextYear(int yr) {
        year++;
        return *this;
    }
    static int getCount() {
        return count;
    }
};

class Fruit {
protected:
    string name;
    string color;
public:
    Fruit() : Fruit("", "") {
    }
    Fruit(string nm, string clr) : name(nm), color(clr) {

    }
    Fruit& setName(string nm) {
        name = nm;
    }
    Fruit& setColor(string clr) {
        color = clr;
    }
    string getName() const {
        return name;
    }
    string getColor() const {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple() : Apple("") {
    }
    Apple(string clr) : Fruit("apple", clr) {
    }
};

class Banana : public Fruit {
public:
    Banana() : Fruit("banana", "yellow") {
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple("green") {
        name = "Granny Smith " + name;
    }
};

int Student::count = 0;

int main()
{
    setlocale(LC_ALL, "RUS");


    // № 1:
    cout << "Задание 1: " << endl;
    Student* e = new Student("Иван", 19, 65, MAN, 2);
    Student* f = new Student("Николай", 22, 74, MAN, 4);
    Student* g = new Student("Женя", 20, 58, WOMAN, 3);

    delete e;
    delete f;
    delete g;
    cout << endl << endl << endl;

    // № 2:
    cout << "Задание 2: " << endl;
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    /* № 3
        Как вариант:
        Первый класс - Class Card - класс, хранящий поля масти и достоинства.
        Следующий класс - Class Shoes. Хранит поле с массивом (Card Deck[n]) карт. Имеет метод взятия верхней карты (метод возвращает верхнюю карту и она исчезает из массива)
        Следующий класс - Class Hand. Хранит массив карт (Card hnd[m]). Имеет методы пересчета количества очков и помещение в руку карты.
        Следующий класс - Class Game. Имеет поле с массивом рук (Hand hnds[l]). Один из методов бегает по массиву рук, пока идет игра. При этом выполняются методы взятия карты из шуза, помещение карты в руку и
        пересчет очков.
        Вот примерная структура проекта
    */
    return 0;
}