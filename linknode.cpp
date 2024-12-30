#include "LinkNode.h"

using namespace std;


void CourseList::insertCourse(CNODE* cNode)//¼��γ���Ϣ
{
    if (cNode == NULL)
        return;
    //����ѧ���Ƿ�Ϸ�
    if (cNode->course.credits < 0 || cNode->course.credits > 100)
    {
        delete cNode;
        cout << "ѧ�������������������ÿγ̵���Ϣ��\n";
        return;
    }
    cNode->next = NULL; // �½ڵ�� `next` ����Ϊ NULL
    if (pHead == NULL)// �������Ϊ�գ�ֱ�Ӳ���ڵ�
    {
        pHead = cNode;
    }
    else
    {
        CNODE* pTmp = pHead;
        while (pTmp->next != NULL)// ��������������һ���ڵ�
            pTmp = pTmp->next;
        pTmp->next = cNode; // ���½ڵ���뵽�����ĩβ
    }
}

/*bool StudentList::deleteStudent(string studentId)//ɾ��ѧ����Ϣ
{
    if (pHead == NULL) // �ȼ�������Ƿ�Ϊ��
        return false;   // ���Ϊ�գ�����ʧ��

    SNODE* prev = NULL;// prevָ�����ڱ��浱ǰ�ڵ��ǰһ���ڵ㣬��ʼ��ΪNULL
    SNODE* curr = pHead;// currָ���ʼ��Ϊ�����ͷ�ڵ㣬����ͷ�ڵ㿪ʼ����

    while (curr != NULL && curr->student.studentId != studentId)  // ����ָ��ѧ��ID�Ľڵ�
    {
        prev = curr;// prevָ��ǰ�ڵ�
        curr = curr->next;// currָ����һ���ڵ�
    }
    if (curr == NULL) // ���û���ҵ�ѧ��
        return false;  // ����ɾ��ʧ��
    if (prev == NULL) // ɾ������ͷ�ڵ�
    {
        pHead = curr->next;
    }
    else // ɾ�������м�ڵ�
    {
        prev->next = curr->next;
    }
    delete curr; // �ͷ��ڴ�
    return true;  // ɾ���ɹ�
}
*/
/*void StudentList::CalculateGPA(SNODE* pNode)
{
    CNODE* p = pNode->student.List;
    double totalcredits = 0;
    double creditscore = 0;
    while (p)
    {
        double w = 0.0;
        if (p->course.courseName == "�ߵ���ѧ")
        {
            w = pNode->student.mScore * (p->course.credits);
        }
        if (p->course.courseName == "Ӣ��")
        {
            w = creditscore = pNode->student.eScore * (p->course.credits);
        }
        if (p->course.courseName == "�������������")
        {
            w = creditscore = pNode->student.cScore * (p->course.credits);
        }
        totalcredits += p->course.credits;
        creditscore += w;
        p = p->next;
    }
    if (totalcredits > 0)
    {
        pNode->student.studentGpa = creditscore / totalcredits/20;
    }
    else
    {
        pNode->student.studentGpa = 0.0; // ������������û�пγ���GPA��Ϊ0
    }
}
*/

/*bool CourseList::deleteCourse(string courseName)//ɾ��ָ���γ���Ϣ
{
    if (pHead == NULL) // �ȼ�������Ƿ�Ϊ��
        return false;   // ���Ϊ�գ�����ʧ��

    CNODE* prev = NULL;// prevָ�����ڱ��浱ǰ�ڵ��ǰһ���ڵ㣬��ʼ��ΪNULL
    CNODE* curr = pHead;// currָ���ʼ��Ϊ�����ͷ�ڵ㣬����ͷ�ڵ㿪ʼ����

    while (curr != NULL && curr->course.courseName != courseName)  // ����ָ���γ����ƵĽڵ�
    {
        prev = curr;// prevָ��ǰ�ڵ�
        curr = curr->next;// currָ����һ���ڵ�
    }
    if (curr == NULL) // ���û���ҵ��γ�
        return false;  // ����ɾ��ʧ��
    if (prev == NULL) // ɾ������ͷ�ڵ�
    {
        pHead = curr->next;
    }
    else // ɾ�������м�ڵ�
    {
        prev->next = curr->next;
    }
    delete curr; // �ͷ��ڴ�
    return true;  // ɾ���ɹ�
}
*/


SNODE* StudentList::findStudent(string sId)//����ѧ����Ϣ
{
   SNODE* curr = pHead;// ��ʼ�� curr Ϊ����ͷ�ڵ�
    while (curr != NULL)// ��������ֱ����ǰ�ڵ�Ϊ��
    {
        if (curr->student.studentId == sId) // �жϵ�ǰ�ڵ��ѧ�� ID �Ƿ�ƥ��
        {
            return curr;// ����ҵ�ƥ���ѧ�������ظ�ѧ���ĵ�ַ��ָ�룩
        }
        curr = curr->next; // ���û���ҵ����ƶ�����һ���ڵ�
    }
    return NULL;// �������������������δ�ҵ�������NULL;
}

CNODE* CourseList::findCourse(string cName)//���ҿγ���Ϣ
{
    CNODE* curr = pHead;// ��ʼ�� curr Ϊ����ͷ�ڵ�
    while (curr != NULL)// ��������ֱ����ǰ�ڵ�Ϊ��
    {
        if (curr->course.courseName == cName) // �жϵ�ǰ�ڵ�Ŀγ������Ƿ�ƥ��
        {
            return curr;// ����ҵ�ƥ��Ŀγ̣����ظÿγ̵ĵ�ַ��ָ�룩
        }
        curr = curr->next; // ���û���ҵ����ƶ�����һ���ڵ�
    }
    return NULL;// �������������������δ�ҵ�������NULL;
}

void StudentList::alterStudent(string studentId)//�޸�ѧ����Ϣ
{
    SNODE* snode = findStudent(studentId);
    if (!snode)
    {
        cout << "�޸�����Ϣ...\n";
        return;
    }
    else
    {
        int sel = 1;
        while (sel)
        {
            cout << "��������Ҫ�޸ĵĿγ�����\n";
            string cname;
            cin >> cname;
            CNODE* cnode = snode->student.cList.findCourse(cname);
            if (cnode == NULL)
            {
                cout << "������δ¼��ÿ�Ŀ�ɼ�...\n";
            }
            else
            {
                double als;
                cout << "�������޸ĺ�ĳɼ���\n";
                cin >> als;
                cnode->course.score = als;
                cout << "�ѳɹ��޸ĸÿ�Ŀ�ɼ�...\n";
            }
            snode->student.calava();
            snode->student.calgpa();
            int sig = 0;
            while (sig != 1 && sig != 2)
            {
                cout << "�����Ƿ���Ҫ�޸�������Ŀ�ɼ���\n";
                cout << "1.��Ҫ\n";
                cout << "2.�˳��޸�\n";
                cin >> sig;
                if (sig == 2)
                {
                    sel = 0;
                }
            }
        }
    }
    
}

/*void CourseList::alterCourse(string courseName)//�޸Ŀγ���Ϣ
{
    CNODE* curr = pHead;//���ҿγ̽ڵ�
    while (curr != NULL)
    {
        if (curr->course.courseName == courseName)  // �ҵ���Ӧ�Ŀγ�
        {
            // ����ҵ��γ̣��Ϳ�ʼ�޸Ŀγ���Ϣ
            // �����޸Ŀγ̳ɼ���������Ϣ
            cout << "�������µĿγ̺�:";
            string newcourseId;
            cin >> newcourseId;
            cout << "�������µĿγ�����:";
            string newcourseName;
            cin >> newcourseName;
            cout << "�������µ�ѧ��:";
            double newCredits;
            cin >> newCredits;
            if (newCredits >= 0 && newCredits <= 100)
            {
                curr->course.credits = newCredits;
            }
            else
            {
                cout << "ѧ��������Ч��\n";
                return;
            }
        }
        curr = curr->next;
    } 
}
*/



void StudentList::InsertsortStudentsByGpa(SNODE* pNode) //���ռ���ߵͲ��루2��
{
    // ��� 1���������Ϊ�գ��� pNode ��Ϊͷ�ڵ�
    if (pHead == NULL) 
    {
        pHead = pNode;
        pNode->next = NULL;  // ȷ���½ڵ�� next ָ��Ϊ NULL
        return;
    }

    // ��� 2����� pNode �� GPA С��ͷ�ڵ�� GPA���� pNode ���뵽ͷ��
    if (pNode->student.studentGpa > pHead->student.studentGpa)
    {
        pNode->next = pHead;
        pHead = pNode;  // pNode ��Ϊ�µ�ͷ�ڵ�
        return;
    }
     // ��� 3����ͷ�ڵ�֮����� pNode
    SNODE* n1 = pHead;
    SNODE* n2 = pHead->next;
    // ���������ҵ����ʵĲ���λ��
    while (n2 != NULL && n2->student.studentGpa > pNode->student.studentGpa)
    {
        n1 = n2;
        n2 = n2->next;
    }
    // ���� pNode��λ���� n1 �� n2 ֮��
    n1->next = pNode;
    pNode->next = n2;
}
void StudentList::sortStudentsByGpa()//����������3��
{
    SNODE* opHead = pHead;
    SNODE* pNode;
    pHead = NULL;
    while (opHead)
    {
        pNode = opHead;
        opHead = opHead->next;
        InsertsortStudentsByGpa(pNode);
    }
}
void StudentList::outputbyGpa()//���������������4������1��2��3��4��һ�����ͳ�Ƴɼ����㲢����������
{
    SNODE* pTmp = pHead;
    if (pTmp != NULL)
    {
        cout << "ѧ��" << "\t" << "����" << "\t" << "����" << "\n";
    }
    while (pTmp != NULL)
    {
        cout << pTmp->student.studentId << "\t" << pTmp->student.studentName << "\t" << pTmp->student.studentGpa << endl;
        pTmp = pTmp->next;
    }
}

//ͳ��ָ���γ̵ĳɼ���������������״��
//ͳ��ָ���γ̵ĳɼ���������������״��
void StudentList::outputbyScore(string cname)
{
    int a1, a2, a3, a4, a5;
    for (SNODE* pTmp = pHead; pTmp != NULL; pTmp = pTmp->next)
    {
        double a;
        a = pTmp->student.cList.findCourse(cname)->course.score;
        if (a >= 90 && a < 100)a1++;
        else if (a >= 80 && a < 90)a2++;
        else if (a >= 70 && a < 80)a3++;
        else if (a >= 60 && a < 70)a4++;
        else a5++;
    }
    cout << "----" << cname << "�ķ�����----";
    cout << "\t90-100\t" << a1 << "��\n";
    cout << "\t80-90\t" << a2 << "��\n";
    cout << "\t70-80\t" << a3 << "��\n";
    cout << "\t60-70\t" << a4 << "��\n";
    cout << "\t60����\t" << a5 << "��\n";
}

/*void StudentList::saveFile(const char* file)
{
    ofstream outFile(file); // ���ļ�����׷��
    if (!outFile)
    {
        cout << "�޷����ļ����б��棡\n";
        return;
    }
    // ����������ѧ����Ϣд���ļ�
    SNODE* pTmp = pHead;

    if (pTmp)
    {
        cout << "ѧ��\t����\t�ߵ���ѧ\tӢ��\t�������������\tƽ����\t����\n";
    }

    while (pTmp != NULL)
    {
        outFile << pTmp->student.studentId << '\t' << pTmp->student.studentName << '\t'
            << pTmp->student.mScore << '\t' << pTmp->student.eScore << '\t'
            << pTmp->student.cScore << pTmp->student.studentGpa << endl;
        pTmp = pTmp->next;
    }
    outFile.close(); // �ر��ļ�
}
*/
/*void CourseList::saveFile(const char* filename)
{
    ofstream outFile(filename); // ���ļ�����׷��
    if (!outFile) {
        cout << "�޷����ļ����б��棡\n";
        return;
    }
    // �����������γ���Ϣд���ļ�
    CNODE* pTmp = pHead;

    if (pTmp)
    {
        outFile << "�γ̺�\t�γ���\tѧ��";
    }
    while (pTmp != NULL) {
        outFile << pTmp->course.courseName << '\t' << pTmp->course.credits << endl;
        pTmp = pTmp->next;
    }
    outFile.close(); // �ر��ļ�
}

void StudentList::clearStudentList()
{
    SNODE* pTmp = NULL;
    while (pHead)
    {
        pTmp = pHead;
        pHead = pHead->next;
        delete pTmp;
    }
    pHead = NULL;
}
*/
/* CourseList::clearCourseList()
{
    CNODE* pTmp = NULL;
    while (pHead)
    {
        pTmp = pHead;
        pHead = pHead->next;
        delete pTmp;
    }
    pHead = NULL;
}
*/

/*void StudentList::load(const char* file)
{
    ifstream in(file);
    if (!in) 
    {
        cout << "�޷����ļ���";
        return;
    }
    string studentId, studentName;
    int m, e, c, a, s;

    in >> studentId;
    in >> studentName;
    in >> m;
    in >> e;
    in >> c;
    in >> a;
    in >> s;
    in.close();
}
*/

