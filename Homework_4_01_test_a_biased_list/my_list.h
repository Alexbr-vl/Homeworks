#pragma once

struct ListNode
{
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr);
    
    int value;
    ListNode* prev;
    ListNode* next;
};

class List
{
public:
    List();
    virtual ~List();

    bool Empty() const;
    unsigned long Size() const;
    void PushFront(int value);
    void PushBack(int value);
    void Clear();

private:
    ListNode* extractPrev(ListNode* node);

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};
