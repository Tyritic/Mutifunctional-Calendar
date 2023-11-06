#include "PersonalScheduleList.h"

PersonalScheduleList::PersonalScheduleList()
{
    head = new PersonalScheduleNode("", "", "", 0); // 创建一个空的头结点
	tail = head; // 将尾结点指向头结点
}

void PersonalScheduleList::addPersonalSchedule(PersonalScheduleNode* s)
{
    if ((s->time != tail->time)||(s->date!=tail->date))
    {
        tail->next = s; // 将新的日程结点加入到尾结点后面
        tail = s; // 更新尾结点
        cout << "添加成功！" << endl;
    }
    else
        cout << "添加失败，后一个日程的时间和前一个日程的时间不能一样"<<endl;
}

void PersonalScheduleList::deletePersonalSchedule(string d, string t)
{
    bool found = false; // 标记是否找到要删除的日程
    PersonalScheduleNode* p = head; // 定义一个指针p指向头结点
    while (p->next != NULL) 
    { // 当p的下一个结点不为空时循环
        if (p->next->date == d && p->next->time == t) 
        { // 如果p的下一个结点的日期和时间匹配
            PersonalScheduleNode* q = p->next; // 定义一个指针q指向p的下一个结点
            p->next = q->next; // 将p的下一个结点指向q的下一个结点
            delete q; // 删除q所指向的结点
            found = true; // 标记为找到
            cout << "删除成功！" << endl;
            break; // 跳出循环
        }
        p = p->next; // 更新p指向下一个结点
    }
    if (!found) { // 如果没有找到
        cout << "没有找到该日程！" << endl;
    }
}

void PersonalScheduleList::modifyPersonalSchedule(string d, string t, int i)
{
    bool found = false; // 标记是否找到要修改的日程
    PersonalScheduleNode* p = head->next; // 定义一个指针p指向头结点的下一个结点
    while (p != NULL) 
    { // 当p不为空时循环
        if (p->date == d && p->time == t)// 如果p所指向的结点的日期和时间匹配 
        {   
            if (i == 1)
            {
                cout << "请输入修改后的日期：" << endl;
                string date;
                cin >> date; // 修改日期
                p->date = date;
                found = true; // 标记为找到
                cout << "修改日期成功！" << endl;
                break; // 跳出循环
            }
            else if (i == 2)
            {
                cout << "请输入修改后的时间：" << endl;
                string time;
                cin >> time;
                p->time = time;
                found = true; // 标记为找到
                cout << "修改时间成功！" << endl;
                break; // 跳出循环
            }
            else if (i == 3)
            {
                cout << "请输入修改后的叙述：" << endl;
                cin.ignore();
                getline(cin, p->content);
                found = true; // 标记为找到
                cout << "修改叙述成功！" << endl;
                break; // 跳出循环
            }
            else if (i == 4)
            {
                cout << "请输入修改后的重要性：" << endl;
                int pri;
                cin >> pri;
                p->priority = pri;
                found = true; // 标记为找到
                cout << "修改重要性成功！" << endl;
                break; // 跳出循环
            }
        }
        p = p->next; // 更新p指向下一个结点*/
    }
    if (!found) 
    { 
        // 如果没有找到
        cout << "没有找到该日程！" << endl;
    }
}

void PersonalScheduleList::queryPersonalSchedule(string d, string t)
{
    bool found = false; // 标记是否找到要查询的日程
    PersonalScheduleNode* p = head->next; // 定义一个指针p指向头结点的下一个结点
    while (p != NULL) 
    { // 当p不为空时循环
        if (p->date == d && p->time == t) 
        { // 如果p所指向的结点的日期和时间匹配
            cout << "查询结果：" << endl;
            cout << "日期：" << p->date << endl;
            cout << "时间：" << p->time << endl;
            cout << "内容：" << p->content << endl;
            cout << "重要性：" << p->priority << endl;
            found = true; // 标记为找到
            break; // 跳出循环
        }
        p = p->next; // 更新p指向下一个结点
    }
    if (!found) { // 如果没有找到
        cout << "没有找到该日程！" << endl;
    }
}

void PersonalScheduleList::showAllPersonalSchedules()
{
    if (head->next == NULL) { // 如果头结点的下一个结点为空
        cout << "没有任何日程！" << endl;
        return; // 返回
    }
    cout << "所有日程如下：" << endl;
    // 对链表按照日期和时间排序，使用插入排序算法
    PersonalScheduleNode* sorted = new PersonalScheduleNode("", "", "", 0); // 创建一个空的已排序链表的头结点
    PersonalScheduleNode* p = head->next; // 定义一个指针p指向头结点的下一个结点
    while (p != NULL) { // 当p不为空时循环
        PersonalScheduleNode* q = sorted; // 定义一个指针q指向已排序链表的头结点
        while (q->next != NULL) { // 当q的下一个结点不为空时循环
            if (q->next->date > p->date || (q->next->date == p->date && q->next->time > p->time)) { // 如果q的下一个结点的日期大于p所指向的结点的日期，或者日期相同但是时间大于
                break; // 跳出循环
            }
            q = q->next; // 更新q指向下一个结点
        }
        PersonalScheduleNode* r = p->next; // 定义一个指针r指向p的下一个结点
        p->next = q->next; // 将p所指向的结点插入到q所指向的结点后面
        q->next = p; // 更新q的下一个结点为p所指向的结点
        p = r; // 更新p指向r所指向的结点
    }
    PersonalScheduleNode* s = sorted->next; // 定义一个指针s指向已排序链表的头结点的下一个结点
    while (s != NULL)
    { // 当s不为空时循环
        cout << "日期：" << s->date << endl; // 输出日期
        cout << "时间：" << s->time << endl; // 输出时间
        cout << "内容：" << s->content << endl; // 输出内容
        cout << "重要性：" << s->priority << endl; // 输出重要性
        cout << "-----------------" << endl; // 输出分隔符
        s = s->next; // 更新s指向下一个结点
    }
}

void PersonalScheduleList::clearPersonalSchdules()
{
    PersonalScheduleNode* p = this->head->next; // 定义一个指针p指向头结点的下一个结点
    while (p != NULL)
    { // 当p不为空时循环
        PersonalScheduleNode* q = p->next; // 定义一个指针q指向p的下一个结点
        delete p; // 删除p所指向的结点
        p = q; // 更新p指向q所指向的结点
    }
    this->head->next = NULL; // 将头结点的下一个结点设为NULL
    this->tail = this->head; // 将尾结点指向头结点
    cout << "清空成功！" << endl;
}

