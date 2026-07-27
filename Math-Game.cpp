
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
enum   enopertiontype { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };
enum  enlevel { Easy = 1, med = 2, hard = 3, mix = 4 };
struct  Questionseries {

    int  num1 = 0; 
    int num2 = 0; 
    enopertiontype  OperationType;
    enlevel   QuestionLevel;
    int  CorrectAnswer = 0;
    int  PlayerAnswer = 0;
    bool  isright = false;

};
struct  Quiz
{
    Questionseries      listqoution[100];  
    short  numberofQuestions = 0;
    enlevel level; 
    enopertiontype  optype;  
    int  rightanswer = 0; 
    int  wronganswer = 0; 
    bool ispass = false; 

};
int  readhowmanyQuestions()
{
    short   num = 0;
    do
    {

        cout << "How  Many Questions do  you  want  to answer       ";
        cin >> num;

    } while (num < 1 || num > 10); 
    return   num;


}
enlevel  Readquestionslevel()
{
    int  type = 0;
    do
    {
        cout << "place  enter questions level [1] Easy  ,  [2] Med   , [3]  hard , [4] Mix";

        cin >> type;


    } while (type <1 || type > 4); 
    return (enlevel)type;

}
enopertiontype Readoptype()
{
    int   num = 0;
    do
    {

        cout << "place enter   opertions type   [1] Add  ,   [2]  Sub , [3]  Mul  ,  [4]   Div   ,    [5 ] Mix";
        cin >> num;

    } while (num < 1 || num >  5);
    return (enopertiontype)num;

}
int randomnumber(int from, int to)
{

    int randnum = rand() % (to - from + 1) + from;


    return randnum;


}
enopertiontype  typeop()
{
    int  op ; 
    op = randomnumber(1, 4);  
    return (enopertiontype)op;  
   

}
int  caclut(int  num1, int  num2, enopertiontype  optype)
{
    switch (optype)
    {
    case  enopertiontype ::Add : 
        return num1 + num2;  
    case  enopertiontype ::Sub  : 
        return  num1 - num2;  

    case enopertiontype ::Mul  :  
        return  num1 * num2;  

    case enopertiontype ::Div  : 
        return num1 / num2;  
    default :
        return num1 + num2; 

}



}
Questionseries  GenerateQuizQuestions(enlevel  level, enopertiontype  optype)
{
    Questionseries qoution;
    if (level == enlevel::mix)
    {
          level = (enlevel)  randomnumber(1, 3);
    }
    if  (optype == enopertiontype::Mix)
    {


           optype = typeop();

    }


    qoution.OperationType = optype;
    switch (level)
    {
    case enlevel ::Easy :
        qoution.num1 = randomnumber(1, 10); 
        qoution.num2 = randomnumber(1, 10);
        qoution.CorrectAnswer = caclut(qoution.num1, qoution.num2, optype);
        qoution.QuestionLevel = level;
        return   qoution;   
    case  enlevel::med :
        qoution.num1 = randomnumber(10, 50);
        qoution.num2 = randomnumber(10, 50);
        qoution.CorrectAnswer = caclut(qoution.num1, qoution.num2, optype);
        qoution.QuestionLevel = level;

        return   qoution;
    case enlevel ::hard  : 
        qoution.num1 = randomnumber(50, 100);
        qoution.num2 = randomnumber(50, 100);
        qoution.CorrectAnswer = caclut(qoution.num1, qoution.num2, optype);
        qoution.QuestionLevel = level;

        return   qoution;

    }
    return  qoution;  


}
string  transfertypetotext(enopertiontype   type)
{

    switch (type)
    {
    case  enopertiontype  ::Add  :
        return  "+"; 
    case  enopertiontype ::Sub  : 
        return  "-"; 
    case enopertiontype ::Mul : 
        return "* "; 
    case  enopertiontype ::Div  : 
        return   "/ ";  
    default :
        return "+"; 

    }


}
void  printgame(Quiz   infoo   ,  int round )
{
    cout <<  endl      <<  "question [" << round+1  << "/" << infoo.numberofQuestions << endl;
    cout << infoo.listqoution[round].num1 << transfertypetotext ( infoo.listqoution[round].OperationType) <<
        infoo.listqoution[round].num2 << endl; 
    cout << "-----------------------------------" << endl;




}
int  answeruser()
{
    int   num = 0;
    cin >> num; 
    return   num;  


}
void setscreen(bool isright)
{

    if (isright)
    {
        system("color 2F");

    }
    else
    {
        system("color 4F");

    }






}
void  currtuseranswer(Quiz &user   , int round )
{
    if (user.listqoution[round].CorrectAnswer != user.listqoution[round].PlayerAnswer)
    {
        user.listqoution[round].isright = false; 
        user.wronganswer++;
        cout << "worng  answer" << endl;
        cout << "the  right  answer   is" << user.listqoution[round].CorrectAnswer << endl;

    }
    else
    {
        user.listqoution[round].isright = true;
        user.rightanswer++;
        cout << "right answer" << endl;




    }




    setscreen(user.listqoution[round].isright); 





}
void AskAndCorrectQuestionListAnswers(Quiz& infoo)
{
    for (int round = 0; round < infoo.numberofQuestions; round++)
    {
        printgame(infoo, round); 
        infoo.listqoution[round].PlayerAnswer = answeruser();
        currtuseranswer(infoo, round);  






    }
    infoo.ispass = (infoo.rightanswer >= infoo.wronganswer); 

}
string  passorfail(bool infoo)
{
    if (infoo)
    {
        return "pass   :-) ";
    }
    else
    {
        return  "fail   :-(";
    }





}
void  GenerateQuizzQuestions(Quiz  & infoo)
{

    for (int round = 0; round < infoo.numberofQuestions; round++)
    {

        infoo.listqoution[round] = GenerateQuizQuestions(infoo.level, infoo.optype);  

}



}

string    totextlevel(enlevel level)
{
    string  arri[4] = { "Easy", "Med", "Hard", "Mix" };
    return arri[level - 1]; 






}
string  totextoptype(enopertiontype  type)
{
    string arri[5] = { "Add"  ,  "Sub"  , "Mul"  , "Div"  , "Mix" }; 
    return arri[type - 1];  







}
void  printfainalresult(Quiz  &infoo)
{

    cout <<     endl       <<  "---------------------------------- -" << endl;
    cout << "final result   " <<      passorfail(infoo.ispass) << endl;  
    cout << "---------------------------------- -" << endl;
    cout << "Number  of   Questions   :" << infoo.numberofQuestions << endl;
    cout << "Questions   Level        :" << totextlevel(infoo.level) << endl; 
    cout << "Optype                   :" << totextoptype(infoo.optype) << endl;  
    cout << "Number   Of Right  Answer :" << infoo.rightanswer << endl;  
    cout << "Number  Of Worng Answer  :" << infoo.wronganswer << endl;  








}
void    playmathgame()
{
    Quiz enQuiz; 
    enQuiz.numberofQuestions = readhowmanyQuestions();
    enQuiz.level = Readquestionslevel();
    enQuiz.optype = Readoptype();
    GenerateQuizzQuestions(enQuiz);
    AskAndCorrectQuestionListAnswers(enQuiz);
    printfainalresult(enQuiz);  

}
void  restscreen()
{
    system("cls");
    system("color 07");



}

void   startgame()
{
    string  playgame = "Y";  
    do
    {
        restscreen();  
        playmathgame();  
        cout << endl << "Do you want to  play agin  ?   Y/N";   
        cin >> playgame;  







    } while (playgame == "Y" || playgame == "y");  








}
int main()
{
    srand((unsigned)time(NULL));
    startgame();
}

