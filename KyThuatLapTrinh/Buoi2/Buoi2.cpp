#include <iostream>
#include <string>
using namespace std;

struct Person {
    int id;
    string name;

    friend ostream& operator <<(ostream& os, const Person& p) {
        os << "\t Id: " << p.id << endl;
        os << "\t Name: " << p.name << endl;
        return os;
    }

    friend istream& operator >> (istream& in, Person& p) {
        cout << "Input person information: " << endl;
        cout << "\t Id: ";
        in >> p.id;
        in.ignore();
        cout << "\t Name: ";
        getline(in, p.name);
        return in;
    }
};

struct Node {
    Person data;
    Node* next;
};

struct LinkedList {
    Node* head;

    void Show() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        Node* item = head;
        while (item != NULL) {
            cout << item->data;
            item = item->next;
        }
    }

    void Add(Person x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    bool Remove(int id) {
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            if (curr->data.id == id) {
                if (prev == NULL)
                    head = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    
    bool Find(string name) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->data.name == name) {
                cout << "Found:\n" << curr->data;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

int main()
{
    LinkedList list = { NULL };

    do {
        system("cls");
        cout << "--- HUMAN RESOURCE --------" << endl;
        cout << "1. View person list" << endl;
        cout << "2. Add a person" << endl;
        cout << "3. Remove a person" << endl;
        cout << "4. Find a person" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Your command: ";

        int cmd;
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            list.Show();
            break;

        case 2: {
            Person p;
            cin >> p;
            list.Add(p);
            break;
        }

        case 3: {
            int id;
            cout << "Input ID to remove: ";
            cin >> id;

            if (list.Remove(id))
                cout << "Removed successfully\n";
            else
                cout << "ID not found\n";

            break;
        }

        case 4: {
            string name;
            cin.ignore();
            cout << "Input Name to find: ";
            getline(cin, name);

            if (!list.Find(name))
                cout << "Person isn't existed\n";

            break;
        }

        case 0:
            return 0;

        default:
            cout << "Your command isn't found. Try again..." << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();

    } while (true);

    return 0;
}