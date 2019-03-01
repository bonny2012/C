//trie Tree
//Name: Xin Zheng
//Date: March 3,2017
//A simple search completion can be implemented using a Trie data structure. A Trie is similar to a tree but it can hold more information about data. For detailed explanation of Trie data structure, please see:
//https://en.wikipedia.org/wiki/Trie
//The way we implement the search completion is to use the edge to denote letters in a valid search query and use the node as the resulting complete search string. 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Node 
{
public:
    Node()
	{ key = ' '; isFull = false; }//constructor
    ~Node() {}
    char getKey() { return key; }
    void setKey(char c) { key = c; }
    bool checkIsFull() { return isFull; }
    void setIsFull() { isFull = true; }
    Node* findChild(char c);
    void appendChild(Node* child) { Children.push_back(child); }
    vector<Node*> myChildren() { return Children; }

private:
    char key;
    bool isFull;
    vector<Node*> Children;
};

Node* Node::findChild(char c)//find a letter and return the pointer 
{
      
    for ( int i = 0; i < Children.size(); i++ )
    {
        Node* tmp = Children.at(i);
        
        if ( tmp->getKey() == c )
        {
            return tmp;
        }
    }

    return NULL;
}
//Trie class starts here
class Trie {
public:
    Trie();
    ~Trie();
    void AddWord(string x);
    Node* SearchWord(string x);
    void DeleteWord(string x);
private:
    Node* root;
};

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

void Trie::AddWord(string x)//add a new word
{
    Node* current = root;
    if ( x.length() == 0 )
    {
        current->setIsFull(); // an empty word
        return;
    }

    for ( int i = 0; i < x.length(); i++ )
    {        
        Node* child = current->findChild(x[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setKey(x[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == x.length() - 1 )
            current->setIsFull();
    }
}


Node* Trie::SearchWord(string x)//search the word and return the point of the word
{
    Node* current = root;
      
        for ( int i = 0; i < x.length(); i++ )
        {
            Node* tmp = current->findChild(x[i]);
            if ( tmp == NULL )
                return NULL;
            current = tmp;
        }
        return current;
      
}

void traverse(Node *root, string current)//traverse the words with same prefix as word
{
    
     for(int i = 0 ; i < root->myChildren().size(); i++)
	 {
			 Node *child  = root->myChildren().at(i);
             
             if (child != NULL)
			 {
                if (child->checkIsFull())//when one word marked as full
				{
                   string newcur(current);
                   newcur+=child->getKey();
                   cout<<newcur<<endl;
                   traverse(child, newcur);
                } 
				else // when the letter marked not full
				{
                   string newcur(current);
                   newcur+=child->getKey();
                   cout<<newcur<<endl;
                   traverse(child, newcur);
                }
             }
     }
     
}

int main()
{
    Trie* trie = new Trie();
    ifstream file("Dictionary.txt");
   
    string str;
	while (std::getline(file, str))
    {
        trie->AddWord(str); 
    } 
	     
    string str1;
    cout<<"Please type search queries:"<<endl;
    cin>>str1;
    Node* root=trie->SearchWord(str1);
    cout<<"Your options are:"<<endl;
    traverse(root,str1);
 
}

