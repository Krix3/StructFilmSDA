#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ��������� ��� �������� ���������� � ������
struct Film
{
    string title;
    string director;
    string genre;
    double rating;
    double price;
};

// ������� ��� ���������� ������
void addFilm(Film*& films, int& size, const Film& newFilm)
{
    // ������� ����� ������ �������� �������
    Film* newFilms = new Film[size + 1];

    // �������� ������ �������� � ����� ������
    for (int i = 0; i < size; ++i)
    {
        newFilms[i] = films[i];
    }

    // ��������� ����� ����� � ����� �������
    newFilms[size] = newFilm;

    // ������� ������ ������
    delete[] films;

    // ��������� ��������� � ������
    films = newFilms;
    ++size;
}

// ������� ��� ����� ������ � ������
Film inputFilm()
{
    Film film;
    cout << "������� �������� ������: ";
    getline(std::cin, film.title);
    cout << "������� ���������: ";
    getline(cin, film.director);
    cout << "������� ����: ";
    getline(std::cin, film.genre);
    cout << "������� �������: ";
    cin >> film.rating;
    cout << "������� ����: ";
    cin >> film.price;
    cin.ignore();  // ���������� ���������� ������ ����� ������
    return film;
}

// ������� ��� ������ ���������� � �������
void printFilms(const Film* films, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "����� #" << i + 1 << endl;
        cout << "��������: " << films[i].title << endl;
        cout << "��������: " << films[i].director << std::endl;
        cout << "����: " << films[i].genre << endl;
        cout << "������: " << films[i].rating << endl;
        cout << "����: " << films[i].price << endl;
        cout << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Film* films = nullptr;  // ���������� ������ ����
    int size = 0;  // ������ �������

    char choice;
    do
    {
        cout << "�� ������ �������� ����� �����? (y/n): ";
        cin >> choice;
        cin.ignore();  // ���������� ���������� ������ ����� ������

        if (choice == 'y' || choice == 'Y')
        {
            Film newFilm = inputFilm();
            addFilm(films, size, newFilm);
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\n������ �������:\n";
    printFilms(films, size);

    // ������� ������
    delete[] films;

    return 0;
}