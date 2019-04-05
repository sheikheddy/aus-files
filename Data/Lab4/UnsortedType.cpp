#include"Book.cpp"
#define ItemType Book


class  UnsortedType	// declares a class data type
{						
public : 			//  8 public member functions

	UnsortedType ( ) ;
	UnsortedType ( const UnsortedType & l ) ;
	~UnsortedType();
	bool	IsFull ( )  const ;              
	int	LengthIs ( )  const ;  // returns length of list
	void    RetrieveItem (const ItemType&  item, bool&  found ) ;
	void    InsertItem (ItemType  item ) ; 	
	void    DeleteItem (ItemType  item ) ; 	
	void    ResetList ( );
	void    GetNextItem (ItemType &  item ) ; 	 
	void    Split ( UnsortedType &A,  UnsortedType &B , string publisher);
	void   	Order ( UnsortedType &A);
private :				//  3 private data members

	int 		length ;           
	ItemType	info[MAX_ITEMS] ;          
	int		currentPos ;
} ;

UnsortedType::UnsortedType(){
	currentPos = length = 0;

}

UnsortedType::~UnsortedType(){

}


UnsortedType::UnsortedType(const UnsortedType & l){
	length = l.length;
	currentPos = l.currentPos;

	for(int i = 0; i < length; ++i){
		info[i] = l.info[i];
	}
}


void  UnsortedType::Split ( UnsortedType &A,  UnsortedType &B , string publisher){	
	A.ResetList(); B.ResetList();

	for(int i = 0; i< currentPos; ++i){

		if(publisher == info[i].getPublisher()){
				A.InsertItem(info[i]);
		}else{
				B.InsertItem(info[i]);
		}
	}

}

void  UnsortedType::Order ( UnsortedType &A){
	A.ResetList();

	for(int i = 0; i < length; ++i){
		if(info[i].getNumCopies() < 10){
			A.InsertItem(info[i]);
		}
	}

}

bool UnsortedType::IsFull() const{return length == MAX_ITEMS;}
int UnsortedType::LengthIs() const{return length;}
void UnsortedType::RetrieveItem(const ItemType & item, bool& found){
	found = false;
	for(int i = 0; i <= currentPos; ++i){
		if(info[i].ComparedTo(item) == EQUAL){
			found = true;
			break;
		}
	}
}
void UnsortedType::InsertItem(ItemType item){
	if(!IsFull()){
		info[currentPos++] = item;
		if(currentPos > length){
			length++;
		}
	}else{
		cout << "List is full! \n";
	}
}
void UnsortedType::DeleteItem(ItemType item){
	bool exists;
	RetrieveItem(item, exists);
	if(exists){
		for(int i = 0; i < length; ++i){
			if(info[i].ComparedTo(item) == EQUAL){
				info[i] = info[length - 1];
				break;
			}
		}
		length--;
		currentPos--;
	}
}

void UnsortedType::ResetList(){
	currentPos = 0;
}

void UnsortedType::GetNextItem(ItemType & item){
	if(!IsFull()){
		item = info[currentPos];
		currentPos++;
	}
}

void printLib(const UnsortedType& lib){
	ItemType item;
	UnsortedType p(lib);
	p.ResetList();
	
	int i = 0;
	while(i < p.LengthIs()){
		p.GetNextItem(item);
		cout << item << endl;
		i++;
	}
}


