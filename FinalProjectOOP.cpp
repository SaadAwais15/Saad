#include<iostream>
#include<fstream>  // input , output
#include<iomanip> // setw  
#include<sstream>  // reading line
#include<ctime>
using namespace std;
void food();
void teacher();
void mainmenu();
class uni{
		public:
			//teachers portal variables
	    string cl1;
    string cl2;
    string cl3;
    string cl4;
    string str;

    int roll;
    int num;
    int n;
    int c;
    int r;
    int size;

    float lrweigh;
    float lpweigh;
    float midweigh;
    float finalweigh;
    float CEAweigh;
    float tot;
    float marks1;
    float marks;

    string* name;
    int* rollNo;
    float* midMarks;
    float* finalMarks;
    float* CEA;
    float* labReport;
    float* totallabrep;
    float* labAssessment;
    float* totallabasses;
    int labReportCount;
    int labAssessmentCount;
    float* totalMarks;
    string* grade;
    float* percentage;
    float* GPA;
	
	//cafe variables
		int choice,i,z;
		float price;
		float gst;
		int y;
		string items[10];
		int cost[10];
		
		//transport office variables
		int n1,n2,n3,n4,n5,p1,p2,p3,p4;
	//file handling
		ifstream fin;
		ofstream fout;
	public:
		
		void exit(){ 
		system("cls");
		mainmenu();
			}
			
			int terminate(){
				return 0;
			}
};
class TeachersPortal:public uni {

public:
    TeachersPortal() {
    	
    	cout << "\n=========================================\n";
        cout << "           CLASSES NAME ENTRY\n";
        cout << "=========================================\n";

        cout << "\nEnter the Name for each Class:\n\n";
        
        
        cout << "Enter name of class 1: ";
        getline(cin, cl1);getline(cin, cl1);
        cout << "Enter name of class 2: ";
        getline(cin, cl2);
        cout << "Enter name of class 3: ";
        getline(cin, cl3);
        cout << "Enter name of class 4: ";
        getline(cin, cl4);
        
        cout << "\nClass name entry completed!\n";
        
        
        cout << "\n=========================================\n";
        cout << "           SELECTION OF CLASS\n";
        cout << "=========================================\n";

        

        cout << "\nWhich file do you want to open?" <<endl<<endl;
        cout << "PRESS 1 FOR " << cl1 << endl;
        cout << "PRESS 2 FOR " << cl2 << endl;
        cout << "PRESS 3 FOR " << cl3 << endl;
        cout << "PRESS 4 FOR " << cl4 << endl;
        cout << "\nENTER FILE NUMBER TO OPEN: ";
        cin >> num;
        cin.ignore();

        if (num == 1) {
           fout.open( "class1.csv", ios::out);
        } else if (num == 2) {
          fout.open("class2.csv", ios::out);
        } else if (num == 3) {
         fout.open("class3.csv", ios::out);
        } else if (num == 4) {
         fout.open("class4.csv", ios::out);
        }

        if (!fout.is_open()) {
            cout << "Failed to open file!" << endl;
            return;
        }

        cout << "\nEnter total number of students of class " << num << ": ";
        cin >> n;
        cin.ignore();

        size = n;
        allocateMemory_Dynamicmemoryallocation();
//        getStudentsData();
//
//        enterWeightage();
//        calculateResults();

    }

// ALLOCATING SIZE ENTERED BY USER
// DYNAMIC MEMORY ALLOCATION
    void allocateMemory_Dynamicmemoryallocation() {
        name = new string[size];
                rollNo = new int[size];
        midMarks = new float[size];
        finalMarks = new float[size];
        CEA = new float[size];
        labReport = new float[size];
        totallabrep = new float[size];
        labAssessment = new float[size];
        totallabasses = new float[size];
        totalMarks = new float[size];
        grade = new string[size];
        percentage = new float[size];
        GPA = new float[size];
    }

// DELETING MEMORY
    void deallocateMemory() {
        delete[] name;
        delete[] rollNo;
        delete[] midMarks;
        delete[] finalMarks;
        delete[] labReport;
        delete[] labAssessment;
        delete[] totalMarks;
        delete[] grade;
        delete[] percentage;
        delete[] GPA;
    }

//GETTING STUDENTS DATA
    void getStudentsData() {
    	
    	cout << "\n=========================================\n";
        cout << "          STUDENT'S DATA ENTRY\n";
        cout << "=========================================\n";

        cout << "\nEnter the details for each student:";
    	
    	
        for (int i = 0; i < size; i++) {
            cout << "\n\nEnter Name of student " << i + 1 << ": ";
            getline(cin, name[i]);

            cout << "Enter Roll No of student " << i + 1 << ": ";
            cin >> rollNo[i];
            cin.ignore();

            cout << "Enter Marks of Mid Examination of student " << i + 1 << ": ";
            cin >> midMarks[i];
            cin.ignore();

            cout << "Enter Marks of Final Examination of student " << i + 1 << ": ";
            cin >> finalMarks[i];
            cin.ignore();
            
            cout<<"Enter Complex Eng.Activity Marks of Student "<<i+1<<": ";
	            	cin>>CEA[i];
	            	cout<<endl;

	            	for(int i=0;i<=5;i++)
	            	{
	            		cout << "\nEnter Number Of LabReport";
	            	cout<<"\n\t\t\t1 for Lab Report 1...";
	            	cout<<"\n\t\t\t2 for Lab Report 2...";
	            	cout<<"\n\t\t\t3 for Lab Report 3 and so on...\n";
	            	
	            	cout<<"\nYour Choice:";
	            	cin>>i;
	            	cout<<"Enter marks:";
	            	cin>>marks;
	            		labReport[i]=marks;
	            		cin.ignore();
					}
					totallabrep[i]=labReport[0]+labReport[1]+labReport[2]+labReport[3]+labReport[4];



	            	for(int i=0;i<=5;i++)
	            	{
	            	cout<<"\nSelect Number of Lab Assesment";
	            	cout<<"\n\t\t1 for Lab Assesment 1...";
	            	cout<<"\n\t\t2 for Lab Assesment 2...";
	            	cout<<"\n\t\t3 for Lab Assesment 3 and so on...\n";
	            	
	            	cout<<"\nYour Choice:";
	            	cin>>i;
	            	cout<<"Enter marks:";
	            	cin>>marks;
	            		labAssessment[i]=marks;
	            		cin.ignore();
					}
					totallabasses[i]=labAssessment[0]+labAssessment[1]+labAssessment[2]+labAssessment[3]+labAssessment[4];


//            cout << "Enter Marks of Lab Assessment of student " << i + 1 << ": ";
//            cin >> labAssessment[i];
//            cin.ignore();

           
            fout << "Name: " <<","<<"Roll No: " << ","<<"Mid Examination: " <<","<< " Final Examination: " <<","<< "Lab Report: " <<","<< "Lab Assessment: " <<endl;
            fout <<name[i]<<","<< rollNo[i]<<","<<midMarks[i] <<"," << finalMarks[i]<<"," << totallabrep[i]<<","<<totallabasses[i] <<endl;
        }
        fout.close();
    }

    void enterWeightage() {
    	
    	 cout << "\n*****************************************\n";
        cout << "             WEIGHTAGE ENTRY\n";
        cout << "*****************************************\n\n";
    	
    	cout << "Enter the Weightage for each One:\n\n";
    	
        cout << "Enter weightage of Mid Examination (in percentage): ";
        cin >> midweigh;

        cout << "Enter weightage of Final Examination (in percentage): ";
        cin >> finalweigh;

        cout << "Enter weightage of Lab Report (in percentage): ";
        cin >> lrweigh;

        cout << "Enter weightage of Lab Assessment (in percentage): ";
        cin >> lpweigh;

        cout << "Enter weightage of CEA (in percentage): ";
        cin >> CEAweigh;
        if (midweigh+finalweigh+lrweigh+lpweigh+CEAweigh!=100){
        	cout<<"\nThe weightages do not add up to 100 try again.\n";
        enterWeightage();
		}
    }

      void calculateResults() {
    for (int i = 0; i < size; i++) {
        tot = (midMarks[i] * midweigh / 20) + (finalMarks[i] * finalweigh / 20) +
              (totallabrep[i] * lrweigh / 75) + (totallabasses[i] * lpweigh / 75) + (CEA[i] * CEAweigh / 20);
        totalMarks[i] = tot;



//            marks = tot * CEAweigh / 100;

            if (totalMarks[i] >= 85) {
                grade[i] = "A+";
                GPA[i] = 4.0;
            } else if (totalMarks[i] >= 80 && totalMarks[i] < 85) {
                grade[i] = "A";
                GPA[i] = 3.7;
            } else if (totalMarks[i] >= 75 && totalMarks[i] < 80) {
                grade[i] = "A-";
                GPA[i] = 3.3;
            } else if (totalMarks[i] >= 70 && totalMarks[i] < 75) {
                grade[i] = "B+";
                GPA[i] = 3.0;
            } else if (totalMarks[i] >= 65 && totalMarks[i] < 70) {
                grade[i] = "B";
                GPA[i] = 2.7;
            } else if (totalMarks[i] >= 60 && totalMarks[i] < 65) {
                grade[i] = "B-";
                GPA[i] = 2.3;
            } else if (totalMarks[i] >= 55 && totalMarks[i] < 60) {
                grade[i] = "C+";
                GPA[i] = 2.0;
            } else if (totalMarks[i] >= 50 && totalMarks[i] < 55) {
                grade[i] = "C";
                GPA[i] = 1.7;
            } else if (totalMarks[i] >= 45 && totalMarks[i] < 50) {
                grade[i] = "C-";
                GPA[i] = 1.3;
            } else if (totalMarks[i] >= 40 && totalMarks[i] < 45) {
                grade[i] = "D+";
                GPA[i] = 1.0;
            } else if (totalMarks[i] >= 35 && totalMarks[i] < 40) {
                grade[i] = "D";
                GPA[i] = 0.7;
            } else {
                grade[i] = "F";
                GPA[i] = 0.0;
            }

            percentage[i] = (totalMarks[i] / 100) * 100;
        }
    }

void studentsdetails()
{
	cout << "\n*****************************************\n";
        cout << "          STUDENT OPTIONAL ENTRY\n";
        cout << "*****************************************\n\n";
    	
    	cout << "Enter the Number You Want to Open:\n\n";

        cout << "Please select an option:" << endl;
        cout << "1 for Grade" << endl;
        cout << "2 for GPA" << endl;
        cout << "3 for Percentage" << endl;
        cout << "4 for Total Marks of student" << endl;
        cout << "5 for Search student by his RollNo" << endl;

        cout << "Your Choice: ";
        cin >> c;

        switch (c) {
            case 1:
                printGrades();
                break;
            case 2:
                printGPA();
                break;
            case 3:
                printPercentage();
                break;
            case 4:
                printTotalMarks();
                break;
            case 5:
                searchStudentByRollNo();
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }

        deallocateMemory();
        
    }
        
    void displayResults() {
        cout << "\n\n*******************************************\n";
        cout << "************ STUDENT'S RESULTS ************\n";
        cout << "*******************************************\n";

        for (int i = 0; i < size; i++) {
            cout << "Name: " << name[i] << endl;
            cout << "Roll No: " << rollNo[i] << endl;
            cout << "Total Marks: " << totalMarks[i] << endl;
            cout << "Grade: " << grade[i] << endl;
            cout << "Percentage: " << percentage[i] << "%" << endl;
            cout << "GPA: " << GPA[i] << endl;
            cout << "-------------------------------------------\n";
        }
    }
    
    
    void printGrades()
    {
    	cout << "\n*************GRADE OF STUDENTs*************\n\n";
    	for (int i=0;i<size;i++)
  								{

    	
  									cout<<"Grade of student "<<i+1<<" with RollNo "<<rollNo[i]<<" is:"<<grade[i]<<endl;
								  }
	}
	
	void printGPA()
	{
			cout << "\n*************GPA OF STUDENTs*************\n\n";
		for(int i=0;i<size;i++)
                            {
                            
                            	cout<<"GPA of student "<<i+1<<" with RollNo "<<rollNo[i]<<" is:"<<GPA[i]<<endl;
							}
	}
	
	void printPercentage()
	{
		cout << "\n*************PERCENTAGE OF STUDENTs*************\n\n";
		 for(int i=0;i<size;i++)
                            {
                            	
                            	cout<<"Percentage of student "<<i+1<<" with RollNo "<<rollNo[i]<<" is:"<<percentage[i]<<endl;
							}
	}
	
	void printTotalMarks()
	{
		cout << "\n*************STUDENTS TOTAL MARKS*************\n\n";
							float totalm[size];
	for(int i=0;i<size;i++)
			{
	totalm[i]=totallabasses[i]+totallabrep[i]+midMarks[i]+finalMarks[i]+CEA[i];
		cout<<"Total Marks of Student "<<i+1<<" is:"<<totalm[i]<<endl;
	        }
	}
	
	void searchStudentByRollNo() 
    {
    	cout << "\n*************SEARCHING STUDENT BY ROLLNO*************\n\n";
	                 		cout<<"ENTER ROLL NO OF STUDENT YOU WANT DETAILS :";
		cin>>r;
		
		cout<<left<<setw(30)<<"NAME"<<setw(15)<<"ROLLNO"<<setw(15)<<"PERFORMANCE"<<setw(15)<<"REPORTS"
		<<setw(15)<<"MID TERM"<<setw(15)<<"FINAL TERM"<<setw(15)<<"PROJECT"<<"GRADE"<<endl;
		
		
		for(int i=0;i<size;i++)
		{
			if(r==rollNo[i])
			{
				
				cout<<left<<setw(30)<<name[i]<<setw(15)<<rollNo[i]<<setw(15)<<totallabrep[i]<<setw(15)<<totallabasses[i]<<setw(15)<<midMarks[i]
				<<setw(15)<<finalMarks[i]<<setw(15)<<CEA[i]<<setw(15)<<grade[i]<<GPA[i]<<endl;
}} }};

class cafe:public uni{
	
	public:
		cafe(){
			cout<<"~WELCOME TO THE CAFETARIA~\n\n";
			choice=0;
			price=0;
			i=0;
			z=0;
			y=10;
			gst=0.04;
		}~cafe(){}
string Day() {
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    switch (currentDate->tm_wday) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "";}}
            
            				            void monday(){ do{
            	cout<<Day()<<"'s Menu\n";
            	cout<<"1.Chicken Strips"<<setw(20)<<"Rs 300"<<setw(20)<<"\n2.Buffalo wings"<<setw(18)<<"Rs 250"<<setw(20)<<"\n3.Mint Margarita"<<setw(20)<<"Rs 120"<<setw(20);
				cout<<setw(20)<<"\n4.Fries"<<setw(16)<<"Rs 60\n";
            	cout<<"Enter the corresponding number of the item you would like to order: ";
            		do {
				cin>>choice;
				if(choice<1||choice>4)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>4);
            	if (choice==1){
            		cout<<"Chicken stripes added to cart\n";
            		price=price+300;
					items[i]="Chicken stripes";
					cost[i]=300;
					i++;}
            	else if(choice==2){
            		cout<<"Buffalo wings added to cart\n";
            		price=price+250;
					items[i]="Buffalo wings";
					cost[i]=250;
					i++;}
				else if(choice==3){
					cout<<"Mint Margarita added to cart\n";
					price=price+120;
					items[i]="Mint Margarita";
					cost[i]=120;
					i++;
				}		
				else if(choice==4){
					cout<<"Fries added to cart\n";
					price=price+60;
				items[i]="Fries";
				cost[i]=60;
				i++;}
				cout<<"Enter 5 to add more items to your order or enter anyother number to go to order confirmation:";
				cin>>choice;			}while (choice==5);
				system("cls");
			    cout<<"Your Order:"<<endl;
				for(int x=0;x<i;x++)
				{ cout<<x+1<<" "<<items[x]<<setw(10)<<"Rs"<<cost[x]<<endl;	}
				cout<<"Press 1 to confirm order\nPress 2 to add more items\nPress 3 to remove items: ";
					do {
				cin>>choice;
				if(choice<1||choice>3)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>3);
				if (choice==1)
				{showbill();	}	
				else if (choice==2)
				{ monday();}
				else if (choice==3)
				{ cout<<"Enter the corresponding number from the bill of the item you want to remove: ";
				cin>>z;
				cout<<items[z-1]<<" has been removed.\n";
				y=z-1;
				price=price-cost[z-1];
				showbill();}}
				
								           
										    void tuesday(){ do{
            	cout<<Day()<<"'s Menu\n";
            	cout<<"1.Qorma"<<setw(20)<<"Rs 300"<<setw(20)<<"\n2.Mixed Vegitables"<<setw(18)<<"Rs 250"<<setw(20)<<"\n3.Daal"<<setw(20)<<"Rs 120"<<setw(20);
				cout<<setw(20)<<"\n4.Naan"<<setw(16)<<"Rs 60\n";
            	cout<<"Enter the corresponding number of the item you would like to order: ";
            		do {
				cin>>choice;
				if(choice<1||choice>4)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>4);
            	if (choice==1){
            		cout<<"Qorma added to cart\n";
            		price=price+300;
					items[i]="Qorma";
					cost[i]=300;
					i++;}
            	else if(choice==2){
            		cout<<"Mixed Vegitables added to cart\n";
            		price=price+250;
					items[i]="Mixed Vegitables";
					cost[i]=250;
					i++;}
				else if(choice==3){
					cout<<"Daal added to cart\n";
					price=price+120;
					items[i]="Daal";
					cost[i]=120;
					i++;
				}		
				else if(choice==4){
					cout<<"Naan added to cart\n";
					price=price+60;
				items[i]="Naan";
				cost[i]=60;
				i++;}
				cout<<"Enter 5 to add more items to your order or enter anyother number to go to order confirmation:";
				cin>>choice;			}while (choice==5);
				system("cls");
			    cout<<"Your Order:"<<endl;
				for(int x=0;x<i;x++)
				{ cout<<x+1<<" "<<items[x]<<setw(10)<<"Rs"<<cost[x]<<endl;	}
				cout<<"Press 1 to confirm order\nPress 2 to add more items\nPress 3 to remove items: ";
					do {
				cin>>choice;
				if(choice<1||choice>3)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>3);
				if (choice==1)
				{showbill();	}	
				else if (choice==2)
				{ tuesday();}
				else if (choice==3)
				{ cout<<"Enter the corresponding number from the bill of the item you want to remove: ";
				cin>>z;
				cout<<items[z-1]<<" has been removed.\n";
				y=z-1;
				price=price-cost[z-1];
				showbill();}}
				
								            void wednesday(){ do{
            	cout<<Day()<<"'s Menu\n";
            	cout<<"1.Beef Doner"<<setw(20)<<"Rs 300"<<setw(20)<<"\n2.Shawarma"<<setw(18)<<"Rs 250"<<setw(20)<<"\n3.1L Pepsi"<<setw(20)<<"Rs 120"<<setw(20);
				cout<<setw(20)<<"\n4.500ml Pepsi"<<setw(16)<<"Rs 60\n";
            	cout<<"Enter the corresponding number of the item you would like to order: ";
            		do {
				cin>>choice;
				if(choice<1||choice>4)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>4);
            	if (choice==1){
            		cout<<"Beef Doner added to cart\n";
            		price=price+300;
					items[i]="Beef Doner";
					cost[i]=300;
					i++;}
            	else if(choice==2){
            		cout<<"Shawarma added to cart\n";
            		price=price+250;
					items[i]="Shawarma";
					cost[i]=250;
					i++;}
				else if(choice==3){
					cout<<"1L Pepsi added to cart\n";
					price=price+120;
					items[i]="1L Pepsi";
					cost[i]=120;
					i++;
				}		
				else if(choice==4){
					cout<<"500ml Pepsi added to cart\n";
					price=price+60;
				items[i]="500ml Pepsi";
				cost[i]=60;
				i++;}
				cout<<"Enter 5 to add more items to your order or enter anyother number to go to order confirmation:";
				cin>>choice;			}while (choice==5);
				system("cls");
			    cout<<"Your Order:"<<endl;
				for(int x=0;x<i;x++)
				{ cout<<x+1<<" "<<items[x]<<setw(10)<<"Rs"<<cost[x]<<endl;	}
				cout<<"Press 1 to confirm order\nPress 2 to add more items\nPress 3 to remove items: ";
					do {
				cin>>choice;
				if(choice<1||choice>3)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>3);
				if (choice==1)
				{showbill();	}	
				else if (choice==2)
				{ wednesday();}
				else if (choice==3)
				{ cout<<"Enter the corresponding number from the bill of the item you want to remove: ";
				cin>>z;
				cout<<items[z-1]<<" has been removed.\n";
				y=z-1;
				price=price-cost[z-1];
				showbill();}}
				
				
			
				            void thursday(){ do{
            	cout<<Day()<<"'s Menu\n";
            	cout<<"1.Pizza"<<setw(20)<<"Rs 300"<<setw(20)<<"\n2.Biryani"<<setw(18)<<"Rs 250"<<setw(20)<<"\n3.Shake"<<setw(20)<<"Rs 120"<<setw(20);
				cout<<setw(20)<<"\n4.Ice cream"<<setw(16)<<"Rs 60\n";
            	cout<<"Enter the corresponding number of the item you would like to order: ";
            		do {
				cin>>choice;
				if(choice<1||choice>4)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>4);
            	if (choice==1){
            		cout<<"Pizza added to cart\n";
            		price=price+300;
					items[i]="Pizza";
					cost[i]=300;
					i++;}
            	else if(choice==2){
            		cout<<"Biryani added to cart\n";
            		price=price+250;
					items[i]="Biryani";
					cost[i]=250;
					i++;}
				else if(choice==3){
					cout<<"Shake added to cart\n";
					price=price+120;
					items[i]="Shake";
					cost[i]=120;
					i++;
				}		
				else if(choice==4){
					cout<<"Ice cream added to cart\n";
					price=price+60;
				items[i]="Ice Cream";
				cost[i]=60;
				i++;}
				cout<<"Enter 5 to add more items to your order or enter anyother number to go to order confirmation:";
				cin>>choice;			}while (choice==5);
				system("cls");
			    cout<<"Your Order:"<<endl;
				for(int x=0;x<i;x++)
				{ cout<<x+1<<" "<<items[x]<<setw(10)<<"Rs"<<cost[x]<<endl;	}
				cout<<"Press 1 to confirm order\nPress 2 to add more items\nPress 3 to remove items: ";
					do {
				cin>>choice;
				if(choice<1||choice>3)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>3);
				if (choice==1)
				{showbill();	}	
				else if (choice==2)
				{ thursday();}
				else if (choice==3)
				{ cout<<"Enter the corresponding number from the bill of the item you want to remove: ";
				cin>>z;
				cout<<items[z-1]<<" has been removed.\n";
				y=z-1;
				price=price-cost[z-1];
				showbill();}}
		
		
						            void friday(){ do{
            	cout<<Day()<<"'s Menu\n";
            	cout<<"1.Haleem"<<setw(20)<<"Rs 300"<<setw(20)<<"\n2.Fried meat"<<setw(18)<<"Rs 250"<<setw(20)<<"\n3.Daal Chawal"<<setw(20)<<"Rs 120"<<setw(20);
				cout<<setw(20)<<"\n4.Lemonade"<<setw(16)<<"Rs 60\n";
            	cout<<"Enter the corresponding number of the item you would like to order: ";
            	do {
				cin>>choice;
				if(choice<1||choice>4)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>4);
            	if (choice==1){
            		cout<<"Haleem added to cart\n";
            		price=price+300;
					items[i]="Haleem";
					cost[i]=300;
					i++;}
            	else if(choice==2){
            		cout<<"Fried meat added to cart\n";
            		price=price+250;
					items[i]="Fried meat";
					cost[i]=250;
					i++;}
				else if(choice==3){
					cout<<"Daal Chawal added to cart\n";
					price=price+120;
					items[i]="Daal Chawal";
					cost[i]=120;
					i++;
				}		
				else if(choice==4){
					cout<<"Lemonade added to cart\n";
					price=price+60;
				items[i]="Lemonade";
				cost[i]=60;
				i++;}
				cout<<"Enter 5 to add more items to your order or enter anyother number to go to order confirmation:";
				cin>>choice;			}while (choice==5);
				system("cls");
			    cout<<"Your Order:"<<endl;
				for(int x=0;x<i;x++)
				{ cout<<x+1<<" "<<items[x]<<setw(10)<<"Rs"<<cost[x]<<endl;	}
				cout<<"Press 1 to confirm order\nPress 2 to add more items\nPress 3 to remove items: ";
					do {
				cin>>choice;
				if(choice<1||choice>3)
				{cout<<"Invalid entry try again: ";
				}
				}while(choice<1||choice>3);
				if (choice==1)
				{showbill();	}	
				else if (choice==2)
				{ friday();}
				else if (choice==3)
				{ cout<<"Enter the corresponding number from the bill of the item you want to remove: ";
				cin>>z;
				cout<<items[z-1]<<" has been removed.\n";
				y=z-1;
				price=price-cost[z-1];
				showbill();}}
		
		
						void showbill(){
						ofstream	out("BILL.txt");
					cout<<endl<<"\tBill"<<endl;
					out<<endl<<"\tBill"<<endl;
						for(int x=0;x<i;x++)
				{ 
				if (x!=y){
				cout<<items[x]<<setw(20)<<"Rs"<<cost[x]<<endl;
				out<<items[x]<<setw(20)<<"Rs"<<cost[x]<<endl;}}
				cout<<endl<<"Price=\tRs"<<price<<endl;
				out<<endl<<"Price=\tRs"<<price<<endl;
				price=price+price*gst;
				cout<<"Gst=4%\tTotal: Rs"<<price<<endl;
				cout<<endl<<"Collect your order from the counter.\nTHANK YOU";
					out<<"Gst=4%\tTotal: Rs"<<price<<endl;
				out<<endl<<"Collect your order from the counter.\nTHANK YOU";}};
				
class buss:public uni{
	private:
	
		public:
			buss(){
				n1=0;
				n2=0;
				n3=0;
				p1=0;
				p2=0;
				p3=0;
				p4=0;
			}
			buss(int i,int j,int k,int l){
				p1=i;
				p2=j;
				p3=k;
				p4=l;
			}

		void op1(){
			char ch;
			do{
			cout<<"Bus No.       Route             departure       Arrival        Seats availible"<<endl;
			cout<<"            -----             ---------       --------         ---------------"<<endl<<endl<<endl;
			cout<<"1.            I-8                7:45            8:00                 3"<<endl<<endl;
			cout<<"2.            Bahria town        6:45            8:00                None"<<endl<<endl;
			cout<<"3.            Pwd                7:00            8:00                 6"<<endl<<endl;
			cout<<"4.            f-8                7:15            8:00                 5"<<endl<<endl;	
			cout<<endl<<"Enter B to go back:- ";
			cin>>ch;
			if(ch!='B')
			{
				cout<<endl<<"Invalid entry try again..."<<endl;
			}
			}
			while(ch!='B');
			{
				lol();
			}
		}
		void res1(){char a;
			do{
				
								cout<<"Your reservations: "<<endl;
			cout<<"Bus No.       Route             departure       Arrival        Seats availible"<<endl;
			cout<<"            -----             ---------       --------         ---------------"<<endl<<endl<<endl;
			cout<<"1.            I-8                7:45            8:00                3"<<endl<<endl;
			cout<<"Number of seats booked:- "<<n3;
												if(n3==1)
					{
							cout<<endl<<"Price for this route per sem:- "<<p1;}
							else if(n3==2)
					{
							cout<<endl<<"Price for this route per sem:- "<<p1*2;}
											else		if(n3==3)
					{
							cout<<endl<<"Price for this route per sem:- "<<p1*3;}
			cout<<endl<<"Enter B to go back:- ";
			cin>>a;
			if(a!='B'){
				cout<<endl<<"Invalid entry try again: "<<endl;
			}}
			while(a!='B');
			{
				lol();
			}
		}
		void res2(){
			char f;
				do{
								cout<<"Your reservations: "<<endl;
			cout<<"Bus No.       Route             departure       Arrival        Seats availible"<<endl;
			cout<<"            -----             ---------       --------         ---------------"<<endl<<endl<<endl;
			cout<<"2.            Bahria town        6:45            8:00                None"<<endl<<endl;
						cout<<"Price for this route per sem:- "<<p2;
						cout<<endl<<"Enter B to go back:- ";
			cin>>f;
			if(f!='B'){
				cout<<endl<<"Invalid entry try again: "<<endl;
			}}
			while(f!='B');
			{
				lol();
			}
		}
		void res3(){
			char e;
		do{ cout<<"Your reservations: "<<endl;
			cout<<"Bus No.       Route             departure       Arrival        Seats availible"<<endl;
			cout<<"            -----             ---------       --------         ---------------"<<endl<<endl<<endl;
			cout<<"3.            Pwd                7:00            8:00                 6"<<endl<<endl;
						cout<<"Number of seats booked:- "<<n4;
												if(n4==1)
					{
							cout<<endl<<"Price for this route per sem:- "<<p3;}
							else if(n4==2)
					{
							cout<<endl<<"Price for this route per sem:- "<<p3*2;}
											else		if(n4==3)
					{
							cout<<endl<<"Price for this route per sem:- "<<p3*3;}
												else	if(n4==4)
					{
							cout<<endl<<"Price for this route per sem:- "<<p3*4;}
												else	if(n4==5)
					{
							cout<<endl<<"Price for this route per sem:- "<<p3*5;}
							else	if(n4==6)
					{
							cout<<endl<<"Price for this route per sem:- "<<p3*6;}
						cout<<endl<<"Enter B to go back:- ";
			cin>>e;
			if(e!='B'){
				cout<<"Invalid entry try again: ";
			}}
			while(e!='B');
			{
				lol();
			}			
		}
		void res4(){
			char d;
		do{cout<<"Your reservations: "<<endl;
			cout<<"Bus No.       Route             departure       Arrival        Seats availible"<<endl;
			cout<<"            -----             ---------       --------         ---------------"<<endl<<endl<<endl;
			cout<<"4.            f-8                7:15            8:00                 5"<<endl<<endl;
						cout<<"Number of seats booked:- "<<n5;
						if(n5==1)
					{
							cout<<endl<<"Price for this route per sem:- "<<p4;}
							else if(n5==2)
					{
							cout<<endl<<"Price for this route per sem:- "<<p4*2;}
											else		if(n5==3)
					{
							cout<<endl<<"Price for this route per sem:- "<<p4*3;}
												else	if(n5==4)
					{
							cout<<endl<<"Price for this route per sem:- "<<p4*4;}
												else	if(n5==5)
					{
							cout<<endl<<"Price for this route per sem:- "<<p4*5;}
						cout<<endl<<"Enter B to go back:- ";
			cin>>d;
			if(d!='B'){
				cout<<endl<<"Invalid entry try again: "<<endl;
			}}
			while(d!='B');
			{
				lol();
			}			
		}
		void op2(){char g;
			cout<<"Bus No.       Route             departure       Arrival        Seats availible"<<endl;
			cout<<"            -----             ---------       --------         ---------------"<<endl<<endl<<endl;
			cout<<"1.            I-8                7:45            8:00                 3"<<endl<<endl;
			cout<<"2.            Bahria town        6:45            8:00                None"<<endl<<endl;
			cout<<"3.            Pwd                7:00            8:00                 6"<<endl<<endl;
			cout<<"4.            f-8                7:15            8:00                 5"<<endl<<endl;
			do{
			do{
				cout<<endl<<"Enter bus no. to select your route: ";
			    cin>>n2;
			    if(n2<1 || n2>4)
			    {
			    	cout<<endl<<"Invalid entry try again..."<<endl;
				}
				else if(n2==2){
					cout<<endl<<"Seats not avalible for this route please choose some other route:- "<<endl;
				}}
				while(n2<1 || n2>4 || n2==2);
				{
					if(n2==1)
					{
						do{ cout<<"Number of seats you want to book: ";
						cin>>n3;
						if(n3<1 || n3>3)
						{ cout<<"Invalid number of seats try again... ";
						}
						}
						while(n3<1 || n3>3);{
						
                    res1();}
					}

					else if(n2==3){
												do{ cout<<"Number of seats you want to book: ";
						cin>>n4;
						if(n4<1 || n4>6)
						{ cout<<"Invalid number of seats try again... ";
						}
						}
						while(n4<1 || n4>6);{
						
                    res3();}
					}
					else if(n2==4){
												do{ cout<<"Number of seats you want to book: ";
						cin>>n3;
						if(n5<1 || n5>5)
						{ cout<<"Invalid number of seats try again... ";
						}
						}
						while(n5<1 || n5>5);{
						
                    res4();}
					}
				}
							cin>>g;
			if(g!='B'){
				cout<<endl<<"Invalid entry try again: "<<endl;
			}}
			while(g!='B');
			{
				lol();
			}
		
		}
	
				
			
		
		void opt3(){
			char c;
		do{
			cout<<"Your last reservation: "<<endl;
			if(n2==1)
			{
				res1();
			}
					else if(n2==3){
						res3();
					}
					else if(n3==4){
						res4();
					}
								cout<<endl<<"Enter B to go back:- ";
			cin>>c;
			if(c!='B'){
				cout<<"Invalid entry try again: "<<endl;
			}}
			while(c!='B');
			{
				lol();
			}
		}
		void opt4(){
			char b;
		do{
			cout<<"Busses availible: "<<endl;
			cout<<"Bus No.       Route             departure       Arrival"<<endl;
			cout<<"            -----             ---------       --------"<<endl<<endl<<endl;
			cout<<"1.            I-8                7:45            8:00"<<endl<<endl;
			cout<<"3.            Pwd                7:00            8:00"<<endl<<endl;
			cout<<"4.            f-8                7:15            8:00"<<endl<<endl;	
						cout<<endl<<"Enter B to go back:- ";
			cin>>b;
			if(b!='B'){
				cout<<"Invalid entry try again: "<<endl;
			}}
			while(b!='B');
			{
				lol();
			}		
		}
					void lol(){
			
					cout<<"***BUS RESERVATION SYSTEM***"<<endl<<endl;
				cout<<"   1.Add new buss number"<<endl;
				cout<<"   2.Reservations"<<endl;
				cout<<"   3.Show reservations"<<endl;
				cout<<"   4.Busses availibe"<<endl;
				cout<<"   5.Exit"<<endl;
				do{
					cin>>n1;
					if(n1<1 || n1>5)
					{cout<<"invalid entry try again..."<<endl;
					}
				}
				while(n1<1 ||n1>5);
			{
					if(n1==1)
				{
					op1();
				}
				else if(n1==2)
				{
					op2();
				}
				else if(n1==3)
				{
					opt3();
				}
				else if(n1==4)
				{
					opt4();
				}
				else if(n1==5)
				{
					exit();
				}
			
		}}};
				



int main()
{

	// PROGRAM TO EXECUTE TEACHERS PORTAL
	cout<<"\n\n\t\t\t\t\t* ^ * ^ * ^ * ^ * ^ * ^ * ^ * ^ FINAL PROJECT * ^ * ^  * ^ * ^ * ^ * ^ * ^ * ^\n\n";
	mainmenu();

	return 0;
}

void food(){    		cafe cfe;
		 if (cfe.Day()=="Monday"){
		cfe.monday();	}
			else if (cfe.Day()=="Tuesday"){
		cfe.tuesday();	}
			else if (cfe.Day()=="Wednesday"){
		cfe.wednesday();	}
			else if (cfe.Day()=="Thursday"){
		cfe.thursday();	}
			else if (cfe.Day()=="Friday"){
		cfe.friday();	}
			else if (cfe.Day()=="Saturday"){
		cout<<"The cafe is closed on the weekend."<<endl;}
	else if (cfe.Day()=="Sunday"){
		cout<<"The cafe is closed on the weekend."<<endl;}
		char b;
		cout<<"\nEnter b to go back or anything else go to main menu:";
		cin>>b;
		if(b=='b'||b=='B')
		{system("cls");
		food();}
	else{ 
	uni x;
	x.exit();}	
}
void teacher(){    char choice;
	cout<<"\n\n\t\t\t\t       * ^ * ^ * ^ * ^ * ^ * ^ * ^ * ^ TEACHERS PORTAL * ^ * ^  * ^ * ^ * ^ * ^ * ^ * ^\n\n";
	
	
        TeachersPortal tp;

        tp.getStudentsData();
        tp.enterWeightage();
        tp.calculateResults();
        tp.studentsdetails();
        tp.displayResults();

         cout << "Do you want to start again? (Y/N): ";
        cin >> choice;
        cin.ignore();
        if(choice=='N'||choice=='n'){
        	uni x;
        	x.exit();	}
        	else if(choice=='y'||choice=='Y'){
        tp.deallocateMemory();
		teacher();}
}
void mainmenu(){
			int i;
			cout<<"Enter\n1 for teachers portal\n2 for cafe\n3 for transport office\n4 to terminate program:\n";
			cin>>i;
		
	if(i==1){
		teacher();
}
   
    else if(i==2){
    	food();
	}
		
	else if(i==3){
			buss ob1(30000,25000,20000,27000);
	ob1.lol();	}
	else if(i==4){
		uni x;
		x.terminate();
	}
	else 
	{ cout<<"Invalid response try again\n";
	mainmenu();	}
}
