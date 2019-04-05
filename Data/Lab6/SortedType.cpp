#include"StudentType.cpp"
enum  ERROR_CODE { SUCCESS, FAIL, UNDERFLOW, OVERFLOW, NOT_FOUND } ; //I hate ERROR_CODE


struct NodeType{
	StudentType info;
	NodeType* next;
};
class  SortedType		// declares a class data type
{						
public : 			//  8 public member functions
	SortedType ( );
	SortedType(const SortedType& original);
	SortedType& operator=(const SortedType& original);
	~SortedType( );
	void MakeEmpty ( );
	bool IsEmpty() const; //I hate ThisNamingConvention
	bool	    IsFull ( )  const ;              
	int	    LengthIs ( )  const ;  // returns length of list
	ERROR_CODE    RetrieveItem ( StudentType&  item, bool&  found ) ; //This is just stupid
	ERROR_CODE    InsertItem ( StudentType  item ) ; 	
	ERROR_CODE    DeleteItem ( StudentType  item ) ; 	
	void    ResetList ( );
	ERROR_CODE   GetNextItem ( StudentType&  item ) ; 	 
private :				//  3 private data members
	int 		length ;           
	NodeType*	listData ;          
	NodeType*	currentPos ;
} ;

SortedType::SortedType ( ){
length  =  0 ;
	listData = nullptr; //prefer nullptr over null in newer code
	currentPos = new NodeType;
	//I want to use smart pointers but am afraid I'll get penalized :(
}
SortedType::~SortedType(){
	MakeEmpty();
}

bool SortedType::IsEmpty() const {return listData == nullptr;}

SortedType& SortedType::operator=(const SortedType& original){
	if(this->listData != original.listData){
	    MakeEmpty();
	    listData = nullptr;
	    length = 0;
	    currentPos = new NodeType;
	    NodeType*  tmp = original.listData;

	    while(tmp){
		InsertItem(tmp->info);
		tmp = tmp->next;
	}

	}

	return *this;
}

SortedType::SortedType(const SortedType& original){
 listData = nullptr;
	    length = 0;
	    NodeType*  tmp = original.listData;
	    currentPos = new NodeType;

	    while(tmp){
		InsertItem(tmp->info);
		tmp = tmp->next;
	}

}
void SortedType::MakeEmpty ( ){
if(!IsEmpty()){
		while(listData){
		DeleteItem(listData->info);
		}
		delete currentPos;
	}
}
bool	    SortedType::IsFull ( )  const {
	NodeType* location;
	try{
	location = new NodeType;
	delete location;
	return false;
	}catch(std::bad_alloc exception){
		return true;
	}
}            
int	    SortedType::LengthIs ( )  const {return length;}  // returns length of list
ERROR_CODE    SortedType::RetrieveItem ( StudentType&  item, bool&  found ) {
	//Normally I would take advantage of the fact that the list is sorted and do a binary search. However, you can't index into arbitrary elements in lists. Sooooo, here's linear search.	

NodeType* location = listData ;
	found = false ;
	while (location  &&  !found ){  
		if (item.ComparedTo(location->info) == EQUAL){
		found = true;				 // match found
		item  = location->info;
	   }
	   else				         // advance pointer  
		 location = location->next;   
 }     


return NOT_FOUND;
}
ERROR_CODE    SortedType::InsertItem ( StudentType  item ) {
	if(IsFull()){return OVERFLOW;}

	NodeType* location = listData;
 NodeType* predLoc = nullptr;
 NodeType* newNode;
    //find insertion point.
 while (location && item.ComparedTo(location->info) == GREATER) {
       predLoc = location;
       location = location->next;	
}
// create a node
newNode = new NodeType;
newNode -> info = item;
// insert node into list:

if (predLoc == nullptr){
        listData = newNode;
}
 else {
predLoc -> next = newNode;
}
 newNode -> next=location;
 length++;

return SUCCESS;
}
	
ERROR_CODE    SortedType::DeleteItem ( StudentType  item ) {
	if(IsEmpty()){return UNDERFLOW;}

NodeType*  location = listData;
	NodeType* tmp;
 	 // locate node to be deleted
       if (item.ComparedTo(listData -> info) == EQUAL){
		tmp = listData;
		listData = listData ->next;
	}


 	else {
	    while ((item.ComparedTo((location -> next)->info)) != EQUAL)
		location = location -> next;
	    // delete node at location -> next
	    tmp = location -> next;
     	     location -> next = (location -> next) -> next;
 	}
	if(tmp){
	delete tmp;
	return SUCCESS;
	}else{
	return NOT_FOUND;
	}
	length--;

} 	
void    SortedType::ResetList ( ){
if(listData){ //prevent dereferencing of null pointer
	currentPos->next = listData->next;
	currentPos->info = listData->info;
	}

}
ERROR_CODE   SortedType::GetNextItem ( StudentType&  item ){
	if(currentPos){ //prevent dereferencing of null pointer
		item = currentPos->info;
		currentPos = currentPos->next;
	return SUCCESS;
	}else{
		return FAIL;
	}
} 	 
 

int main(){
	SortedType a;
	ifstream in("student.txt");
	if(in.is_open()){
		string i, f, l, g;
		while(in >> i >> f >> l >> g){
			StudentType s;
			s.Initialize(stoi(i),f,l,g);
			a.InsertItem(s);
		}
	}else{
		cerr << "Failed to open file" << endl;
		exit(1);
	}

	cout << "Student details: \n ID \t Name \t\t Grade \n __ \t ____\t\t_____\n";
	StudentType b;
	a.ResetList();

	while(a.GetNextItem(b) != FAIL){
		if(b.getGrade() == "A"){
			b.Print(); cout << endl;
		}
	}

	in.close();
	return 0;
}
