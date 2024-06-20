#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Структура для хранения информации о фильме
struct Film
{
    string title;
    string director;
    string genre;
    double rating;
    double price;
};

// Функция для добавления фильма
void addFilm(Film*& films, int& size, const Film& newFilm)
{
    // Создаем новый массив большего размера
    Film* newFilms = new Film[size + 1];

    // Копируем старые элементы в новый массив
    for (int i = 0; i < size; ++i)
    {
        newFilms[i] = films[i];
    }

    // Добавляем новый фильм в конец массива
    newFilms[size] = newFilm;

    // Удаляем старый массив
    delete[] films;

    // Обновляем указатель и размер
    films = newFilms;
    ++size;
}

// Функция для ввода данных о фильме
Film inputFilm()
{
    Film film;
    cout << "Введите название фильма: ";
    getline(std::cin, film.title);
    cout << "Введите режиссера: ";
    getline(cin, film.director);
    cout << "Введите жанр: ";
    getline(std::cin, film.genre);
    cout << "Введите рейтинг: ";
    cin >> film.rating;
    cout << "Введите цену: ";
    cin >> film.price;
    cin.ignore();  // Игнорируем оставшийся символ новой строки
    return film;
}

// Функция для вывода информации о фильмах
void printFilms(const Film* films, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Фильм #" << i + 1 << endl;
        cout << "Название: " << films[i].title << endl;
        cout << "Режиссер: " << films[i].director << std::endl;
        cout << "Жанр: " << films[i].genre << endl;
        cout << "Рйтинг: " << films[i].rating << endl;
        cout << "Цена: " << films[i].price << endl;
        cout << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Film* films = nullptr;  // Изначально массив пуст
    int size = 0;  // Размер массива

    char choice;
    do
    {
        cout << "Вы хотите добавить новый фильм? (y/n): ";
        cin >> choice;
        cin.ignore();  // Игнорируем оставшийся символ новой строки

        if (choice == 'y' || choice == 'Y')
        {
            Film newFilm = inputFilm();
            addFilm(films, size, newFilm);
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\nСписок фильмов:\n";
    printFilms(films, size);

    // Очистка памяти
    delete[] films;

    return 0;
}