#include "unordered_list.h"


// ---------------------ARRAYLIST---------------------
UnorderedArrayList::UnorderedArrayList(int max_len): capacity(max_len), size(0), buf(new string[max_len]), UnorderedList("UAL"){}

int UnorderedArrayList::find_index(const string & word){
    for (int i=0; i<size; ++i){
        if (buf[i]==word){
            return i;
        }
    }
    return -1;
}

void UnorderedArrayList::copy_up(int index){
    --size;
    for (int i=index; i < size; ++i)
        buf[i] = buf[i+1];
}

void UnorderedArrayList::insert(const string & word){
    buf[size++] = word;
}

bool UnorderedArrayList::find(const string & word){
    for (int i=0; i<size; ++i){
        if (buf[i]==word){
            return true;
        }
    }
    return false;
}

void UnorderedArrayList::remove(const string & word){
    for (int i=0; i<size; ++i){
        if (buf[i] == word){
            copy_up(i);
            break;
        }
    }
}

bool UnorderedArrayList::is_empty(){
    return (size==0);
}

bool UnorderedArrayList::is_full(){
    return (size==capacity);
}

void UnorderedArrayList::print(ostream & out){
    for (int i=0; i<size; ++i)
        out << buf[i];
}

UnorderedArrayList::~UnorderedArrayList(){
    delete[] buf;
}

// ---------------------LISTNODE---------------------
void ListNode::print(ostream & out, ListNode * L){
    for (ListNode * ptr = L; ptr!=nullptr; ptr=ptr->next){
        out << ptr->data;
    }
}

ListNode * ListNode::find(const string & word, ListNode * L){
    if (L==nullptr){
        return nullptr;
    }
    for (ListNode * ptr = L; ptr!=nullptr; ptr=ptr->next){
        if (ptr->data == word){
            return ptr;
        }
    }
    return nullptr;
}

void ListNode::delete_list(ListNode * L){
    
    while (L!=nullptr){
        ListNode *temp = L;
        L = L->next;
        delete temp;
    }
}

void ListNode::remove(const string & word, ListNode * & L){}


// ---------------------LINKEDLIST---------------------
UnorderedLinkedList::UnorderedLinkedList(): UnorderedList("ULL"), head(nullptr){}

void UnorderedLinkedList::insert(const string &word){
    if (is_empty()){
        head = new ListNode(word, nullptr);
    } else {
        head = new ListNode(word, head->next);
    }
}

bool UnorderedLinkedList::find(const string & word){
    return ListNode::find(word, head);
}

void UnorderedLinkedList::remove(const string & word){
    ListNode * prev = nullptr;
    for (ListNode * ptr = head; ptr!=nullptr; ptr=ptr->next){
        if (ptr->data == word){
            if (prev==nullptr){
                head = ptr->next;
                delete ptr;
            } else{
                prev->next = ptr->next;
                delete ptr;
            }
            break;
        }
        prev = ptr;
    }
}

bool UnorderedLinkedList::is_empty(){
    return (head==nullptr);
}

bool UnorderedLinkedList::is_full(){
    return false;
}

void UnorderedLinkedList::print(ostream & out){
    ListNode::print(out, head);
}

UnorderedLinkedList::~UnorderedLinkedList(){
    ListNode::delete_list(head);
    head = nullptr;
}

ostream & operator << (ostream & out, UnorderedList & L){
    out << L.name;
    return out;
}


