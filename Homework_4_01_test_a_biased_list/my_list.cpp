#include <iostream>
#include "my_list.h"

ListNode::ListNode(int value, ListNode* prev, ListNode* next)
                  : value(value), prev(prev), next(next)
{
    if (prev) prev->next = this;
    if (next) next->prev = this;
}

List::List() : m_head(new ListNode(0)), m_size(0), m_tail(new ListNode(0, m_head)) {}

List::~List()
{
    Clear();
    delete m_head;
    delete m_tail;
}

bool List::Empty() const { return m_size == 0; }
unsigned long List::Size() const { return m_size; }

void List::PushFront(int value)
{
    new ListNode(value, m_head, m_head->next);
    ++m_size;
}

void List::PushBack(int value)
{
    new ListNode(value, m_tail->prev, m_tail);
    ++m_size;
}

void List::Clear()
{
    auto current = m_head->next;
    while (current != m_tail)
    {
        current = current->next;
        delete extractPrev(current);
    }
}

ListNode* List::extractPrev(ListNode* node)
{
    auto target = node->prev;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    --m_size;
    return target;
}