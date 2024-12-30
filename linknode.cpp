#include "LinkNode.h"

using namespace std;


void CourseList::insertCourse(CNODE* cNode)//录入课程信息
{
    if (cNode == NULL)
        return;
    //检验学分是否合法
    if (cNode->course.credits < 0 || cNode->course.credits > 100)
    {
        delete cNode;
        cout << "学分输入错误，请重新输入该课程的信息！\n";
        return;
    }
    cNode->next = NULL; // 新节点的 `next` 设置为 NULL
    if (pHead == NULL)// 如果链表为空，直接插入节点
    {
        pHead = cNode;
    }
    else
    {
        CNODE* pTmp = pHead;
        while (pTmp->next != NULL)// 遍历到链表的最后一个节点
            pTmp = pTmp->next;
        pTmp->next = cNode; // 将新节点插入到链表的末尾
    }
}

/*bool StudentList::deleteStudent(string studentId)//删除学生信息
{
    if (pHead == NULL) // 先检查链表是否为空
        return false;   // 如果为空，返回失败

    SNODE* prev = NULL;// prev指针用于保存当前节点的前一个节点，初始化为NULL
    SNODE* curr = pHead;// curr指针初始化为链表的头节点，即从头节点开始查找

    while (curr != NULL && curr->student.studentId != studentId)  // 查找指定学生ID的节点
    {
        prev = curr;// prev指向当前节点
        curr = curr->next;// curr指向下一个节点
    }
    if (curr == NULL) // 如果没有找到学生
        return false;  // 返回删除失败
    if (prev == NULL) // 删除的是头节点
    {
        pHead = curr->next;
    }
    else // 删除的是中间节点
    {
        prev->next = curr->next;
    }
    delete curr; // 释放内存
    return true;  // 删除成功
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
        if (p->course.courseName == "高等数学")
        {
            w = pNode->student.mScore * (p->course.credits);
        }
        if (p->course.courseName == "英语")
        {
            w = creditscore = pNode->student.eScore * (p->course.credits);
        }
        if (p->course.courseName == "面向对象程序设计")
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
        pNode->student.studentGpa = 0.0; // 避免除零错误，若没有课程则GPA设为0
    }
}
*/

/*bool CourseList::deleteCourse(string courseName)//删除指定课程信息
{
    if (pHead == NULL) // 先检查链表是否为空
        return false;   // 如果为空，返回失败

    CNODE* prev = NULL;// prev指针用于保存当前节点的前一个节点，初始化为NULL
    CNODE* curr = pHead;// curr指针初始化为链表的头节点，即从头节点开始查找

    while (curr != NULL && curr->course.courseName != courseName)  // 查找指定课程名称的节点
    {
        prev = curr;// prev指向当前节点
        curr = curr->next;// curr指向下一个节点
    }
    if (curr == NULL) // 如果没有找到课程
        return false;  // 返回删除失败
    if (prev == NULL) // 删除的是头节点
    {
        pHead = curr->next;
    }
    else // 删除的是中间节点
    {
        prev->next = curr->next;
    }
    delete curr; // 释放内存
    return true;  // 删除成功
}
*/


SNODE* StudentList::findStudent(string sId)//查找学生信息
{
   SNODE* curr = pHead;// 初始化 curr 为链表头节点
    while (curr != NULL)// 遍历链表，直到当前节点为空
    {
        if (curr->student.studentId == sId) // 判断当前节点的学生 ID 是否匹配
        {
            return curr;// 如果找到匹配的学生，返回该学生的地址（指针）
        }
        curr = curr->next; // 如果没有找到，移动到下一个节点
    }
    return NULL;// 如果遍历完整个链表仍未找到，返回NULL;
}

CNODE* CourseList::findCourse(string cName)//查找课程信息
{
    CNODE* curr = pHead;// 初始化 curr 为链表头节点
    while (curr != NULL)// 遍历链表，直到当前节点为空
    {
        if (curr->course.courseName == cName) // 判断当前节点的课程名称是否匹配
        {
            return curr;// 如果找到匹配的课程，返回该课程的地址（指针）
        }
        curr = curr->next; // 如果没有找到，移动到下一个节点
    }
    return NULL;// 如果遍历完整个链表仍未找到，返回NULL;
}

void StudentList::alterStudent(string studentId)//修改学生信息
{
    SNODE* snode = findStudent(studentId);
    if (!snode)
    {
        cout << "无该生信息...\n";
        return;
    }
    else
    {
        int sel = 1;
        while (sel)
        {
            cout << "请输入需要修改的课程名：\n";
            string cname;
            cin >> cname;
            CNODE* cnode = snode->student.cList.findCourse(cname);
            if (cnode == NULL)
            {
                cout << "该生尚未录入该科目成绩...\n";
            }
            else
            {
                double als;
                cout << "请输入修改后的成绩：\n";
                cin >> als;
                cnode->course.score = als;
                cout << "已成功修改该科目成绩...\n";
            }
            snode->student.calava();
            snode->student.calgpa();
            int sig = 0;
            while (sig != 1 && sig != 2)
            {
                cout << "请问是否需要修改其他科目成绩？\n";
                cout << "1.需要\n";
                cout << "2.退出修改\n";
                cin >> sig;
                if (sig == 2)
                {
                    sel = 0;
                }
            }
        }
    }
    
}

/*void CourseList::alterCourse(string courseName)//修改课程信息
{
    CNODE* curr = pHead;//查找课程节点
    while (curr != NULL)
    {
        if (curr->course.courseName == courseName)  // 找到对应的课程
        {
            // 如果找到课程，就开始修改课程信息
            // 可以修改课程成绩或其他信息
            cout << "请输入新的课程号:";
            string newcourseId;
            cin >> newcourseId;
            cout << "请输入新的课程名称:";
            string newcourseName;
            cin >> newcourseName;
            cout << "请输入新的学分:";
            double newCredits;
            cin >> newCredits;
            if (newCredits >= 0 && newCredits <= 100)
            {
                curr->course.credits = newCredits;
            }
            else
            {
                cout << "学分输入无效！\n";
                return;
            }
        }
        curr = curr->next;
    } 
}
*/



void StudentList::InsertsortStudentsByGpa(SNODE* pNode) //按照绩点高低插入（2）
{
    // 情况 1：如果链表为空，将 pNode 作为头节点
    if (pHead == NULL) 
    {
        pHead = pNode;
        pNode->next = NULL;  // 确保新节点的 next 指针为 NULL
        return;
    }

    // 情况 2：如果 pNode 的 GPA 小于头节点的 GPA，将 pNode 插入到头部
    if (pNode->student.studentGpa > pHead->student.studentGpa)
    {
        pNode->next = pHead;
        pHead = pNode;  // pNode 成为新的头节点
        return;
    }
     // 情况 3：在头节点之后插入 pNode
    SNODE* n1 = pHead;
    SNODE* n2 = pHead->next;
    // 遍历链表，找到合适的插入位置
    while (n2 != NULL && n2->student.studentGpa > pNode->student.studentGpa)
    {
        n1 = n2;
        n2 = n2->next;
    }
    // 插入 pNode，位置在 n1 和 n2 之间
    n1->next = pNode;
    pNode->next = n2;
}
void StudentList::sortStudentsByGpa()//按绩点排序（3）
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
void StudentList::outputbyGpa()//按绩点排序输出（4）【（1、2、3、4）一起才能统计成绩绩点并按绩点排序】
{
    SNODE* pTmp = pHead;
    if (pTmp != NULL)
    {
        cout << "学号" << "\t" << "姓名" << "\t" << "绩点" << "\n";
    }
    while (pTmp != NULL)
    {
        cout << pTmp->student.studentId << "\t" << pTmp->student.studentName << "\t" << pTmp->student.studentGpa << endl;
        pTmp = pTmp->next;
    }
}

//统计指定课程的成绩及排名、分数段状况
//统计指定课程的成绩及排名、分数段状况
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
    cout << "----" << cname << "的分数段----";
    cout << "\t90-100\t" << a1 << "人\n";
    cout << "\t80-90\t" << a2 << "人\n";
    cout << "\t70-80\t" << a3 << "人\n";
    cout << "\t60-70\t" << a4 << "人\n";
    cout << "\t60以下\t" << a5 << "人\n";
}

/*void StudentList::saveFile(const char* file)
{
    ofstream outFile(file); // 打开文件进行追加
    if (!outFile)
    {
        cout << "无法打开文件进行保存！\n";
        return;
    }
    // 遍历链表，将学生信息写入文件
    SNODE* pTmp = pHead;

    if (pTmp)
    {
        cout << "学号\t姓名\t高等数学\t英语\t面向对象程序设计\t平均分\t绩点\n";
    }

    while (pTmp != NULL)
    {
        outFile << pTmp->student.studentId << '\t' << pTmp->student.studentName << '\t'
            << pTmp->student.mScore << '\t' << pTmp->student.eScore << '\t'
            << pTmp->student.cScore << pTmp->student.studentGpa << endl;
        pTmp = pTmp->next;
    }
    outFile.close(); // 关闭文件
}
*/
/*void CourseList::saveFile(const char* filename)
{
    ofstream outFile(filename); // 打开文件进行追加
    if (!outFile) {
        cout << "无法打开文件进行保存！\n";
        return;
    }
    // 遍历链表，将课程信息写入文件
    CNODE* pTmp = pHead;

    if (pTmp)
    {
        outFile << "课程号\t课程名\t学分";
    }
    while (pTmp != NULL) {
        outFile << pTmp->course.courseName << '\t' << pTmp->course.credits << endl;
        pTmp = pTmp->next;
    }
    outFile.close(); // 关闭文件
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
        cout << "无法打开文件！";
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

