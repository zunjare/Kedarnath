//									-------------------------	MCQ BASED QUIZ GAME -------------------------------
#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include <chrono>     

using namespace std;

int Guess;
int Total=0;

class Question
{
	protected: 
		string QText;
		string option1;
		string option2;
		string option3;
		string option4;
		int correct_ans;
		int score;
		
	public:
			
			void addQ(); 
			void play(); 
			
};

void Question :: addQ()
{
	cout<<"--------------------------------------"<<endl;
	cout<<"Enter Your Question : ";
	getline(cin>>ws, QText); 
	cout<<"option1 : ";
	getline(cin>>ws, option1);
	cout<<"option2 : ";
	getline(cin>>ws, option2);
	cout<<"option3 : ";
	getline(cin>>ws, option3);
	cout<<"option4 : ";
	getline(cin>>ws, option4);
	cout<<"correct Answer  (1-4) :";
	cin>>correct_ans;
}

void Question::	play() 
{
	cout<<"--------------------------------------"<<endl;
	cout<<QText<<endl;
	cout<<"1. "<<option1<<endl;
	cout<<"2. "<<option2<<endl;
	cout<<"3. "<<option3<<endl;
	cout<<"4. "<<option4<<endl;
	
	cout<<"Enter Your Answer (1-4) : ";
	cin>>Guess;
	
	if(Guess==correct_ans)
	{
		cout<<endl;
		cout<<"Correct Answer."<<endl;
		Total = Total+10;
		cout<<endl;
	}else
	{
		cout<<"Wrong Answer!"<<endl;
		cout<<"Correct Answer : "<<correct_ans<<endl;
	}
	
	
}
int main()
{
	vector<Question> QList; 
	char more;

	start:
	system("cls");
	int choice;
        cout << "\t=======================================\n";
        cout << "\t============== Quiz Game ==============\n";
        cout << "\t=======================================\n";
        cout << "\t 1. Add Question.\n";
        cout << "\t 2. Play Quiz.\n";
        cout << "\t 3. Exit.\n";
        cout << "\tPlease Enter choice: ";
        cin >> choice;
        
        switch(choice)
        {
        	case 1:
        		{
        			
        			do{
        				Question q1;
        				q1.addQ();
        				QList.push_back(q1);
        				cout<<"Add More ? (y/n) : ";
        				cin>>more;
					}while(more=='y' || more=='Y');
        			goto start;
					 
				}
        		
        		break;
        		
        	case 2:
        		{
        			if(QList.empty()){
        				cout<<"No Quetions Added..! "<<endl;
        			
					}
					else
					{
						
						auto start_time = chrono::steady_clock::now(); 
						auto end_time = start_time + chrono::minutes(5);
						
						for(int i=0; i<QList.size(); i++)
        				{
        					if(chrono::steady_clock::now()>= end_time)
							{
								cout<<"---------------------------------------------"<<endl;
								cout<<"Time's Up! Quiz finished...!'"<<endl;					
								cout<<"---------------------------------------------"<<endl;	
								break;	
							}
							
        					QList[i].play();
						}
						
						cout<<"--------------------------------------"<<endl;
						cout<<"Total Score : "<<Total<<" Out Of ("<<(QList.size()*10)<<")"<<endl;
        				if(Total>=((QList.size()*10)/2))
        				{
        					cout<<"Congrats :) You Won..."<<endl;
						}else
						{
							cout<<"You Failed!"<<endl;
							cout<<"oops Try Agrain"<<endl;
						}
						cout<<"--------------------------------------"<<endl;	
					}
        			
					getch();
					goto start;
				}
    
        		break;
        		
        	case 3:
        		exit(0);
        		
        	defualt:
        		cout<<"Invalid Choice !"<<endl;
		}
}
