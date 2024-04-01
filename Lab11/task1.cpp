#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student
{
    friend class StudentBST;

private:
    int id;
    string name;
    float fee;
    Student *left;
    Student *right;

public:
    Student(int id, string name, float fee, Student *left = NULL, Student *right = NULL)
    {
        this->id = id;
        this->name = name;
        this->fee = fee;
        this->left = left;
        this->right = right;
    }
};

class StudentBST
{
private:
    Student *root;

public:
    StudentBST()
    {
        root = NULL;
    }
    bool insert(int id, string name, float fee)
    {
        Student *temp = new Student(id, name, fee);
        if (!root)
        {
            root = temp;
        }
        if (id == this->root->id)
        {
            cout << "This id already exist!!\n";
        }
        else
        {
            Student *cur = root;
            Student *prev = NULL;
            while (cur != NULL)
            {
                prev = cur;
                if (cur->id == id)
                {
                    cout << "This id already exist!!\n";
                    delete temp;
                    return true;
                }
                if (id < cur->id)
                {
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                }
            }

            if (id < prev->id)
            {
                prev->left = temp;
            }
            else
            {
                prev->right = temp;
            }
            return true;
        }
    }
    void search(int id)
    {
        bool find = false;
        if (!root)
        {
            cout << "tree is empty\n";
        }
        else
        {
            Student *cur = root;
            Student *prev = NULL;

            while (cur->id != id)
            {
                if (cur->id > id)
                {
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                }
                if (cur->id == id)
                {
                    find = true;
                    cout << cur->id << " " << cur->name << " " << cur->fee << endl;
                }
            }
        }

        if (find == false)
        {
            cout << "cannot find element \n";
        }
        else
        {
            cout << "We find the student data\n";
        }
    }
    void In_order(Student *stree)
    {
        if (stree != NULL)
        {
            In_order(stree->left);
            cout << stree->id << " " << stree->name << " " << stree->fee << endl;
            In_order(stree->right);
        }
    }
    void Pre_order(Student *stree)
    {
        if (stree != NULL)
        {
            cout << stree->id << " " << stree->name << " " << stree->fee << endl;
            In_order(stree->left);
            In_order(stree->right);
        }
    }
    void Post_order(Student *stree)
    {
        if (stree != NULL)
        {
            In_order(stree->left);
            In_order(stree->right);
            cout << stree->id << " " << stree->name << " " << stree->fee << endl;
        }
    }
    void In_order()
    {
        In_order(root);
    }
    void Pre_order()
    {
        Pre_order(root);
    }
    void Post_order()
    {
        Post_order(root);
    }
    void deleteStudent(int id)
    {
        Student *cur = root;
        Student *prev = NULL;
        while (!cur)
        {
            if (cur->id > id)
            {
                cur = cur->left;
            }
        }
        if (cur->left == NULL && cur->right == NULL)
        {
            delete cur;
        }
        if (cur->right != NULL || cur->left != NULL)
        {
            if (cur->right == NULL && cur->left != NULL)
            {
                swap(cur, cur->left);
                delete cur;
            }
            else if (cur->right == NULL && cur->left != NULL)
            {
                swap(cur, cur->left);
                delete cur;
            }
        }
        if(cur->right!=NULL && cur->left!=NULL)
        {
            cur = cur->left;
        }

    }

    void destroy(Student *stree)
    {
        if (stree)
        {
            destroy(stree->left);
            destroy(stree->right);
            delete stree;
        }
    }
    ~StudentBST()
    {
        destroy(root);
    }
};

int main()
{
    ifstream imf("input (6).txt");
    int id;
    string name;
    float fee;

    StudentBST s1;
    if (!imf)
    {
        cout << "File didn't open\n";
    }
    else
    {
        while (imf >> id >> name >> fee)
        {
            // cout << id << " " << name << " " << fee << endl;
            s1.insert(id, name, fee);
        }
    }

    s1.insert(15, "Namrah", 456.872);
    // s1.insert(5,"Namrah",456.872);

    cout << "\nGet the element through searching\n";
    s1.search(5);
    imf.close();

    cout << "\n Checking inorder function\n";
    s1.In_order();
    cout << "\n Checking preorder function\n";
    s1.Pre_order();
    cout << "\n Checking Post_order function\n";
    s1.Post_order();

    s1.deleteStudent(7);
    s1.deleteStudent(12);
    return 0;
}