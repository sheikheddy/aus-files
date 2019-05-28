

#include<iostream>
using namespace std;
#define ItemType Student

struct NodeType{

	ItemType info; 
	NodeType* next = nullptr;

}; 




class  UnsortedType
{
public : 
		                                //  LINKED LIST IMPLEMENTATION
UnsortedType ( ) ;
void   MakeEmpty ( ) ;
bool   IsFull ( )  const ;
bool 	IsEmpty() const;
int	Length ( )  const ;
void   RetrieveItem ( ItemType&  item, bool&  found ) const;
void   InsertItem ( ItemType  item ) ;
void   DeleteItem ( ItemType  item ) ;
void   ResetList ( );
void   GetNextItem ( ItemType&  item ) ;
friend UnsortedType operator &(const UnsortedType &list1, const UnsortedType &list2);
friend UnsortedType operator|(const UnsortedType &list1, const UnsortedType &list2);
~UnsortedType ( ) ; //one of the three safety functions
UnsortedType(const UnsortedType& original);
UnsortedType& operator=(const UnsortedType& original);
private :
NodeType*  listData; //this is the "head" of the list
int     	length; //there is absolutely no need for this, but whatever
NodeType*  currentPos;
};

UnsortedType::UnsortedType ( ) {
	length  =  0 ;
	listData = nullptr; //prefer nullptr over null in newer code
	currentPos = new NodeType;
}

UnsortedType& UnsortedType::operator=(const UnsortedType& original){
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


UnsortedType::UnsortedType(const UnsortedType& original){	    
	    listData = nullptr;
	    length = 0;
	    NodeType*  tmp = original.listData;
	    currentPos = new NodeType;

	    while(tmp){
		InsertItem(tmp->info);
		tmp = tmp->next;
	}
}


//I'm not just setting listData to null
//because otherwise the nodes don't get freed
void  UnsortedType::MakeEmpty ( ) {
	if(!IsEmpty()){
		while(listData){
		DeleteItem(listData->info);
		}
		delete currentPos;
	}

}

bool   UnsortedType::IsFull ( )  const {
	NodeType* location;
	try{
	location = new NodeType;
	delete location;
	return false;
	}catch(std::bad_alloc exception){
		return true;
	}

}
bool UnsortedType::IsEmpty() const{return listData == nullptr;}
int	UnsortedType::Length ( )  const {
	return length;
}
void   UnsortedType::RetrieveItem ( ItemType&  item, bool&  found ) const{
NodeType* location = listData ;
	found = false ;
	while (location  &&  !found ){  
		if ( item  == location->info ){                // operator==
		found = true;				 // match found
		item  = location->info;
	   }
	   else				         // advance pointer  
		 location = location->next;   
 }     

}
void   UnsortedType::InsertItem ( ItemType  item ){
	if(!IsFull()){
	NodeType*  location ;
 	// obtain and fill a node
        location = new  NodeType;
	location->info = item ;
	location->next = listData;
	listData = location ;
	length++;
	}
}

void   UnsortedType::DeleteItem ( ItemType  item ){
	if(IsEmpty()){return;}

	NodeType*  location = listData;
	NodeType* tmp = new NodeType;
	
 	 // locate node to be deleted       
	if (item == listData -> info){
		tmp = listData;
		listData = listData ->next;
	}
 	else{
	    while (location->next && !(item == (location -> next)->info))
		location = location -> next;
	    // delete node at location -> next
	     tmp = location -> next;
     	     location -> next = (location -> next) -> next;
 	}
	delete tmp;
	length--;

}

void   UnsortedType::ResetList ( ){
	
	if(listData){ //prevent dereferencing of null pointer
	currentPos->next = listData;
	currentPos->info = listData->info;
	}

}

void   UnsortedType::GetNextItem ( ItemType&  item ){
	if(currentPos){ //prevent dereferencing of null pointer
		item = currentPos->info;
		currentPos = currentPos->next;
	}else{
		currentPos = listData;
		currentPos->next = listData->next;
		currentPos->info = listData->info;
		item = currentPos->info;
	}

}
UnsortedType::~UnsortedType ( ){
	MakeEmpty();
} //one of the three safety functions
UnsortedType operator &(const UnsortedType &list1, const UnsortedType &list2){
	UnsortedType intersection;
	
	ItemType item;
	bool found; //no need to set to false cause RetrieveItem does it for us
	int size = list1.Length() < list2.Length() ? list1.Length() : list2.Length();
	NodeType* shorter = size == list1.Length() ? list1.listData : list2.listData;
	const UnsortedType* longer = size == list1.Length() ? &list2 : &list1; //preserve constness
  	//I don't like doing it this way tbh but I've been deducted points for "inefficiency" before
	
	for(int i = 0; i < size; ++i){

			item = shorter->info;
			shorter = shorter->next;
			longer->RetrieveItem(item, found);

		if(found){
			intersection.RetrieveItem(item, found);
			if(!found){
				intersection.InsertItem(item);
			}
		}
	}

	return intersection;
}
UnsortedType operator|(const UnsortedType &list1, const UnsortedType &list2){
	UnsortedType result(list1);
	
	NodeType* tmp = list2.listData;
	ItemType item;
	bool found;

	for(int i = 0; i < list2.Length(); ++i){
		item = tmp->info;
		tmp = tmp->next;
		result.RetrieveItem(item, found);
		if(!found){result.InsertItem(item);}
	}

	

	return result;
}

/*
const int MAX = 50;


int main(){
	//union and intersection of multiples of 3 and multiples of 5 till MAX
	
	UnsortedType multiplesOf3;
	
	for(int i = 3; i < MAX; i+=3){
		multiplesOf3.InsertItem(i);
	}

	UnsortedType multiplesOf5;
	for(int i = 5; i < MAX; i+=5){
		multiplesOf5.InsertItem(i);
	}

	ItemType item;

	UnsortedType intersection = multiplesOf3 & multiplesOf5;
	cout << "Intersection of multiples of 3 and 5 (i.e, multiples of 15 are:)" << endl;
	for(int i = 0; i < intersection.Length(); ++i){
		intersection.GetNextItem(item);
		cout << item << endl;
	}

	UnsortedType result = multiplesOf3 | multiplesOf5;
	cout << "Union of multiples of 3 and 5 are: " << endl;
	for(int i = 0; i < result.Length(); ++i){
		result.GetNextItem(item);
		cout << item << " ";
	}

	return 0;

}
*/
