
//April 20, 2017
// round robin CPU scheduling
//simulate the round robin CPU scheduling with time quantum = 5ms algorithm using an input file containing jobs for CPU

#include <cstdlib>  //for call atoi 
#include <fstream>  //for class ifstream
#include <vector>   
#include <iostream>
#include <sstream> //for class stringstream

using namespace std;

class job_Information
{
	public:
		
	//constructor
	job_Information(int _jobID, int _respTime, int _duration):jobID(_jobID),respTime(_respTime),duration(_duration),
	timeLeft(_duration){}
	
	int jobID;
	int respTime;
	int duration;
	int timeLeft;	
	
};
void print(vector<job_Information> &jobs)
{
	for(int n=0;n<1000;n++)
	{
		cout<<jobs[n].jobID<<" "<<jobs[n].respTime<<" "<<jobs[n].duration<<endl;
	}
}


void scheduleRR(vector<job_Information> &jobs, const int quantum)
{
	int time=0;//total time
	int flag=1;//when there is no process remaining, flag turn to 0;

	while(flag == 1){

         //check which process just arrived

         vector<int> *process = new vector<int>;

         int remaining = 0; // check if there are remaining processes to prevent infinite loop
         
         for (int i = 0 ; i <jobs.size(); i++){

             if (jobs[i].respTime <= time && jobs[i].timeLeft > 0)
			 {

                process->push_back(i);

             }
             if (jobs[i].timeLeft > 0) 
             
			 remaining = 1; // if there are still processes with burst time greater than zero, then there are processes left to run.
          
         }         

         for (int i = 0 ; i <process->size() ; i++)
		 {

             if (jobs[process->at(i)].timeLeft >= quantum)
			 {

                 jobs[process->at(i)].timeLeft -= quantum;

                 time+=quantum;

                 cout << "job " << jobs[process->at(i)].jobID << " scheduled for " << quantum <<" seconds";
                 
				 if(jobs[process->at(i)].timeLeft==0)
				 
				 	cout<<" completed."<<endl;
				 	
				 else
				 
				 	cout<<endl;
             } 
			 else 
			 {

                 cout << "job " <<jobs[process->at(i)].jobID << " scheduled for " << jobs[process->at(i)].timeLeft <<" seconds, completed."<<endl;
            
                 time+=jobs[process->at(i)].timeLeft;

                 jobs[process->at(i)].timeLeft = 0;     
			          
             }            

         }

         if (process->size() == 0) 
		 	
			time+= quantum; //if current there is no active process, CPU goes to sleep for 2 second

         if (remaining == 0)
		 
		 	flag = 0;         
	}
	
}

int main()
{	
	vector<job_Information> jobs;

    ifstream file("job.txt");
    
    int job_id, reTime,duTime;
    string str;
    
	while (getline(file, str))//read the file line by line
    {
		stringstream ss(str);
		int temp;
        
		vector<int> result;
		
        while( ss.good() )

        {
            string substr;

            getline( ss, substr, ',' );
            
			temp=atoi(substr.c_str());//turn string to int
			
            result.push_back( temp );
        }
		
     	jobs.push_back(job_Information(result.at(0),result.at(1),result.at(2)));
			
    } 
  
    scheduleRR(jobs,5);
    
}





	


