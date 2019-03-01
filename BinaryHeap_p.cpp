//BinaryHeap Example
//无法在建时直接加入n 个条木 
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class UnderflowException
{
};

template <typename Comparable>
class BinaryHeap
{
	public:	
		explicit BinaryHeap(int capacity=100):array(capacity+1),currentSize(0)
		{
			
		}
		
		explicit BinaryHeap(const vector<Comparable> & items):array(items.size()+10),currentSize(items.size())
		{
			for(int i=0;i<items.size();i++)
				array[i+1]=items[i];
			buildHeap();
		}
		void insert(const Comparable & x)
		{
			if(currentSize==array.size()-1)
				array.resize(array.size()*2);
			
			int hole=++currentSize;
			
			for(;hole>1 && x<array[hole/2];hole/=2)
			{
				array[hole]=array[hole/2];
			}
			array[hole]=x;			
		}
		
		void deleteMin()
		{
			if(isEmpty())
				throw UnderflowException();
				
			array[1]=array[currentSize--];
			percolateDown(1);			
			
		}
		
		void deleteMin(Comparable & minItem)
		{
			if(isEmpty())
				throw UnderflowException();
				
			minItem=array[1];
			array[1]=array[currentSize--];
			percolateDown(1);
		}
		bool isEmpty() const
		{
			return currentSize==0;
		}
		
		void printHeap()
		{
			cout<<"[";
			for(unsigned i=0;i<=currentSize;i++)
			{
				cout<<array[i]<<",";
			}
			cout<<"]"<<endl;
			
		}
		void makeEmpty()
		{
			currentSize=0;
		}
		Comparable & findMin()const
		{
			return array[1];
		}
	private:
		vector<Comparable> array;
		unsigned currentSize;
		
		void buildHeap()
		{
			for(int i=currentSize/2;i>0;i--)
				percolateDown(i);
		}
		
		void percolateDown(unsigned hole)
		{
			unsigned child;
			Comparable tmp=array[hole];//temp keep the last item 
			
			for( ; 2*hole<=currentSize;hole=child)//compare parent(hole) with child and child+1
			{
				child=hole*2;
				if( child!=currentSize && array[child+1]<array[child])
					child++;//compare child and child +1 
					
				if(array[child]<tmp)
					array[hole]=array[child]; //move the smallest item to hole
				else
					break;					
				
			}
			array[hole]=tmp;//after compare put the orgin item in hole to the right location
		}
		
	
};
int main()
{
	BinaryHeap<string> H(4);
	H.insert("Smith");
	H.printHeap();
	H.insert("John");
	H.printHeap();
	H.insert("Mary");
	H.printHeap();
	H.insert("Mark");
	H.printHeap();
	
	H.deleteMin();
	H.printHeap();
	
	/*vector<string> myName;
	
	myName[0] = "Banjanovic";
	myName[1] = "Buckley";
	myName[2] = "Callahan";
	myName[3] = "DeWilligen";
	myName[4] = "Fischbeck";
	myName[5] = "Fleischmann";
	myName[6] = "Heichelbech"; 
	
	BinaryHeap<string> Name(myName);*/
}
