#include <iostream>
#include <string>

#define N 10

using namespace std;

typedef struct
{
    string name;
    string author;
    string publish;
} Book;

class SqList
{
private:
    Book *books;
    int length;

public:
    SqList()
    {
        this->length = 0;
        this->books = new Book[N];
    }
    int insert(Book book, int position)
    {
        if (this->length >= N || position < 0 || position > this->length + 1)
            return 0;
        int l = this->length;
        if (position > 0)
            while (l >= position)
            {
                this->books[l] = this->books[l - 1];
                --l;
            }
        this->books[l] = book;
        ++this->length;
        return 1;
    }
    int remove(int position)
    {
        if (position < 1 || position > this->length)
            return 0;
        int i = position - 1;
        while (i < this->length)
        {
            this->books[i] = this->books[i + 1];
            ++i;
        }
        --this->length;
        return 1;
    }
    int locate(string name)
    {
        int position = 0;
        while (name.compare(this->books[position].name) != 0)
            ++position;
        return position + 1;
    }
    Book &find(int position)
    {
        return this->books[position - 1];
    }
    void print()
    {
        int l = 0;
        while (l < this->length)
        {
            cout << this->books[l].name << "\t";
            cout << this->books[l].author << "\t";
            cout << this->books[l].publish << endl;
            ++l;
        }
    }
    int getLength(){
        return this->length;
    }
};

int main(void)
{
    cout << "初始化顺序表" << endl;
    SqList L;
    cout << "顺序添加书籍" << endl;
    Book book;
    for (int i = 1; i < 6; i++)
    {
        book.name = "书籍" + to_string(i);
        book.author = "作者" + to_string(i);
        book.publish = "出版社" + to_string(i);
        if (!L.insert(book, 0))
            cout << "插入失败" << endl;
    }
    L.print();
    cout << "指定位置添加" << endl;
    if (!L.insert(book, 3))
        cout << "插入失败" << endl;
    L.print();
    cout << "删除第三本书籍" << endl;
    L.remove(3);
    L.print();
    cout << "根据书名查找 书籍1:  " << L.locate("书籍1") << endl;
    cout << "根据位置查找第 三 本书:  " << L.find(3).name << endl;
    cout << "顺序表的长度为:  " << L.getLength() << endl;
    return 0;
}
