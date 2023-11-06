#include "PersonalScheduleList.h"

PersonalScheduleList::PersonalScheduleList()
{
    head = new PersonalScheduleNode("", "", "", 0); // ����һ���յ�ͷ���
	tail = head; // ��β���ָ��ͷ���
}

void PersonalScheduleList::addPersonalSchedule(PersonalScheduleNode* s)
{
    if ((s->time != tail->time)||(s->date!=tail->date))
    {
        tail->next = s; // ���µ��ճ̽����뵽β������
        tail = s; // ����β���
        cout << "��ӳɹ���" << endl;
    }
    else
        cout << "���ʧ�ܣ���һ���ճ̵�ʱ���ǰһ���ճ̵�ʱ�䲻��һ��"<<endl;
}

void PersonalScheduleList::deletePersonalSchedule(string d, string t)
{
    bool found = false; // ����Ƿ��ҵ�Ҫɾ�����ճ�
    PersonalScheduleNode* p = head; // ����һ��ָ��pָ��ͷ���
    while (p->next != NULL) 
    { // ��p����һ����㲻Ϊ��ʱѭ��
        if (p->next->date == d && p->next->time == t) 
        { // ���p����һ���������ں�ʱ��ƥ��
            PersonalScheduleNode* q = p->next; // ����һ��ָ��qָ��p����һ�����
            p->next = q->next; // ��p����һ�����ָ��q����һ�����
            delete q; // ɾ��q��ָ��Ľ��
            found = true; // ���Ϊ�ҵ�
            cout << "ɾ���ɹ���" << endl;
            break; // ����ѭ��
        }
        p = p->next; // ����pָ����һ�����
    }
    if (!found) { // ���û���ҵ�
        cout << "û���ҵ����ճ̣�" << endl;
    }
}

void PersonalScheduleList::modifyPersonalSchedule(string d, string t, int i)
{
    bool found = false; // ����Ƿ��ҵ�Ҫ�޸ĵ��ճ�
    PersonalScheduleNode* p = head->next; // ����һ��ָ��pָ��ͷ������һ�����
    while (p != NULL) 
    { // ��p��Ϊ��ʱѭ��
        if (p->date == d && p->time == t)// ���p��ָ��Ľ������ں�ʱ��ƥ�� 
        {   
            if (i == 1)
            {
                cout << "�������޸ĺ�����ڣ�" << endl;
                string date;
                cin >> date; // �޸�����
                p->date = date;
                found = true; // ���Ϊ�ҵ�
                cout << "�޸����ڳɹ���" << endl;
                break; // ����ѭ��
            }
            else if (i == 2)
            {
                cout << "�������޸ĺ��ʱ�䣺" << endl;
                string time;
                cin >> time;
                p->time = time;
                found = true; // ���Ϊ�ҵ�
                cout << "�޸�ʱ��ɹ���" << endl;
                break; // ����ѭ��
            }
            else if (i == 3)
            {
                cout << "�������޸ĺ��������" << endl;
                cin.ignore();
                getline(cin, p->content);
                found = true; // ���Ϊ�ҵ�
                cout << "�޸������ɹ���" << endl;
                break; // ����ѭ��
            }
            else if (i == 4)
            {
                cout << "�������޸ĺ����Ҫ�ԣ�" << endl;
                int pri;
                cin >> pri;
                p->priority = pri;
                found = true; // ���Ϊ�ҵ�
                cout << "�޸���Ҫ�Գɹ���" << endl;
                break; // ����ѭ��
            }
        }
        p = p->next; // ����pָ����һ�����*/
    }
    if (!found) 
    { 
        // ���û���ҵ�
        cout << "û���ҵ����ճ̣�" << endl;
    }
}

void PersonalScheduleList::queryPersonalSchedule(string d, string t)
{
    bool found = false; // ����Ƿ��ҵ�Ҫ��ѯ���ճ�
    PersonalScheduleNode* p = head->next; // ����һ��ָ��pָ��ͷ������һ�����
    while (p != NULL) 
    { // ��p��Ϊ��ʱѭ��
        if (p->date == d && p->time == t) 
        { // ���p��ָ��Ľ������ں�ʱ��ƥ��
            cout << "��ѯ�����" << endl;
            cout << "���ڣ�" << p->date << endl;
            cout << "ʱ�䣺" << p->time << endl;
            cout << "���ݣ�" << p->content << endl;
            cout << "��Ҫ�ԣ�" << p->priority << endl;
            found = true; // ���Ϊ�ҵ�
            break; // ����ѭ��
        }
        p = p->next; // ����pָ����һ�����
    }
    if (!found) { // ���û���ҵ�
        cout << "û���ҵ����ճ̣�" << endl;
    }
}

void PersonalScheduleList::showAllPersonalSchedules()
{
    if (head->next == NULL) { // ���ͷ������һ�����Ϊ��
        cout << "û���κ��ճ̣�" << endl;
        return; // ����
    }
    cout << "�����ճ����£�" << endl;
    // �����������ں�ʱ������ʹ�ò��������㷨
    PersonalScheduleNode* sorted = new PersonalScheduleNode("", "", "", 0); // ����һ���յ������������ͷ���
    PersonalScheduleNode* p = head->next; // ����һ��ָ��pָ��ͷ������һ�����
    while (p != NULL) { // ��p��Ϊ��ʱѭ��
        PersonalScheduleNode* q = sorted; // ����һ��ָ��qָ�������������ͷ���
        while (q->next != NULL) { // ��q����һ����㲻Ϊ��ʱѭ��
            if (q->next->date > p->date || (q->next->date == p->date && q->next->time > p->time)) { // ���q����һ���������ڴ���p��ָ��Ľ������ڣ�����������ͬ����ʱ�����
                break; // ����ѭ��
            }
            q = q->next; // ����qָ����һ�����
        }
        PersonalScheduleNode* r = p->next; // ����һ��ָ��rָ��p����һ�����
        p->next = q->next; // ��p��ָ��Ľ����뵽q��ָ��Ľ�����
        q->next = p; // ����q����һ�����Ϊp��ָ��Ľ��
        p = r; // ����pָ��r��ָ��Ľ��
    }
    PersonalScheduleNode* s = sorted->next; // ����һ��ָ��sָ�������������ͷ������һ�����
    while (s != NULL)
    { // ��s��Ϊ��ʱѭ��
        cout << "���ڣ�" << s->date << endl; // �������
        cout << "ʱ�䣺" << s->time << endl; // ���ʱ��
        cout << "���ݣ�" << s->content << endl; // �������
        cout << "��Ҫ�ԣ�" << s->priority << endl; // �����Ҫ��
        cout << "-----------------" << endl; // ����ָ���
        s = s->next; // ����sָ����һ�����
    }
}

void PersonalScheduleList::clearPersonalSchdules()
{
    PersonalScheduleNode* p = this->head->next; // ����һ��ָ��pָ��ͷ������һ�����
    while (p != NULL)
    { // ��p��Ϊ��ʱѭ��
        PersonalScheduleNode* q = p->next; // ����һ��ָ��qָ��p����һ�����
        delete p; // ɾ��p��ָ��Ľ��
        p = q; // ����pָ��q��ָ��Ľ��
    }
    this->head->next = NULL; // ��ͷ������һ�������ΪNULL
    this->tail = this->head; // ��β���ָ��ͷ���
    cout << "��ճɹ���" << endl;
}

