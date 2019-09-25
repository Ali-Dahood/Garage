#include<iostream.h>
using namespace std;
enum errorcode{success,overflow,underflow,notfound};
const int maxsize=10;// Garage size 
template <class T>
class queue{// Queue Implementation based on array
	T entry[maxsize];
	int Front,Rear,Counter;
	int LinePrice;
	public:
	queue(){
		Counter=Front=0;
		Rear=maxsize-1;
	}
	bool empty(){
		return(Counter==0);
	}
	errorcode Append(T item){
		if(Counter==maxsize)
		return overflow;
		Rear=(Rear+1)%maxsize;
		entry[Rear]=item;
		Counter++;
		return success;
		
	}
	errorcode Retrive(T &item){
		if(Counter==0)
		return underflow;
		item=entry[Front];
		return success;
	}
	errorcode Serve(){
		if(empty())
		return underflow;
		Front=(Front+1)%maxsize;
		Counter--;
		return success;
		
	}
	
};// end queue
class car{// class of the car is start
	int CarID;
	int seatNo;
	double seatPrice;
	int Passengers;
	string drivername;
	double TotalMoney;
	public:
	static double c;
	friend istream & operator>>(istream &, car &);
	car(int,int,double,string);
	car();
	//car(car&);
	int GetCarID();
	int GetseatNo();
	double GetseatPrice();
	int GetPassengers();
	int GetTotal();
	string GetDrivername();
	void SetCarID(int);
	void SetseatNo(int);
	void SetseatPrice(double);
	void SetPassengers(int);
	void SetDrivername(string);
	void Addmoney();
};// end class cat
// All methods is out of the class car
car::car(){
	CarID=0;
	seatNo=0;
	seatPrice=0;
	Passengers=0;
	TotalMoney=0;
	drivername='\0';
}
/*car::car(car &obj1){// copy constructor
	cout<<"okay"<<endl;
	this->CarID=obj1.CarID;
	this->seatNo=obj1.seatNo;
	this->seatPrice=obj1.seatPrice;
	this->Passengers=obj1.Passengers;
	this->drivername=obj1.drivername;
	this->TotalMoney=obj1.TotalMoney;
}*/
car::car(int CarID,int seatNo,double seatPrice,string drivername){// constructor with parameters
	this->CarID=CarID;
	this->seatNo=seatNo;
	this->seatPrice=seatPrice;
	Passengers=0;
	this->drivername=drivername;
	TotalMoney=0;
}
int car::GetCarID(){
	return CarID;
}
int car::GetseatNo(){
	return seatNo;
}
double car::GetseatPrice(){
	return seatPrice;
}
int car::GetPassengers(){
   return Passengers;
}
string car::GetDrivername(){
	return drivername;
}
void car::SetCarID(int CarID){
	this->CarID=CarID;
}
void car::SetseatNo(int seatNo){
	this->seatNo=seatNo;
}
void car::SetseatPrice(double seatPrice){
	this->seatPrice=seatPrice;
}
void car::SetPassengers(int Passengers){
	this->Passengers=Passengers;
}
void car::SetDrivername(string drivername){
	this->drivername=drivername;
}
istream & operator>>(istream &in, car &c){//  operator for cin for car objects
	int x;
	cout<<"Enter who many seats in the car: ";
	in>>x;
	while(x<1){
		cout<<"you must enter another number ,one or more: ";
		in>>x;
	}
	c.seatNo=x;
	cout<<"Enter seatPrice for this car: ";
	double z;
	in>>z;
	while(z<1){
		cout<<"you must put the price at less 1 enter another price: ";
		in>>z;
	}
	c.seatPrice=z;
	cout<<"enter the name of the driver: ";
	in>>c.drivername;
	c.TotalMoney=0;
}// end operator
int car::GetTotal(){
	return TotalMoney;
}
void car::Addmoney(){
	TotalMoney+=Passengers*(seatPrice);
	c+=Passengers*(seatPrice);
	cout<<TotalMoney<<endl;
}
double car::c=0;//Initial value
template <typename T>
bool checkID(int,queue <T> );
bool checkPassengers(car,int);
template <typename T>
bool Insert(queue <T>&,int,car);
template <typename T>
void PrintInformation(queue <T>);
template <typename T>
void SuperDriver(queue <T>,queue <T>);//SuperDriver the one who collects the highest amount of money
template <typename T>
int Forward(queue <T>&,car&);
template <typename T>
errorcode CheckFull(queue <T>);
template <typename T>
int LastLocation(queue <T>);
template <typename T>
void TravelSwitch(queue<T>&,int);
main(){// main is start
	int pa;
	queue <car>Garage;
	queue <car>Travel;
	int choice;
	cout<<"Garage Squad\n";
	cout<<"**********\n";
	cout<<"choice 1 for add a car to the Garage:\n";
	cout<<"choice 2 for Travel time:\n";
	cout<<"choice 3 to Forward a car: \n";
	cout<<"choice 4 for insert a car at Specific location: \n";
	cout<<"choice 5 for Garage Information: \n";
	cout<<"choice 6 to know Garage Income:\n";
	cout<<"choice 7 to know the Super Driver:\n";
	cout<<"press 8 to stop the program:\n";
	cin>>choice;
	car c1;
	while(choice!=8){//while start
		switch(choice){//switch start
		case 1:{//start case 1
			if(CheckFull(Garage)!=overflow){
			cout<<"add an car to the Garage: "<<endl;
			cout<<"Enter the ID of the car:";
			int x;
			cin>>x;
			while(x<1){
				cout<<"Enter another ID up then 0: ";
				cin>>x;
			}
			while(checkID(x,Garage)==true){
				cout<<"Enter another ID this ID is already exit in the Garage: \n";
				cin>>x;
			}
			if(checkID(x,Travel)==true){
				cout<<"This ID is already used its in Travel\n";
				TravelSwitch(Travel,x);
				Travel.Retrive(c1);
				Garage.Append(c1);
				Travel.Serve();
				cout<<"I returned it to the Garage\n";
			}
			else{
				cin>>c1;
				c1.SetCarID(x);
				Garage.Append(c1);
				cout<<"The car is added to the Garage\n";
			}
			}
			else
			cout<<"The Garage is Full\n ";
			cout<<"**********\n";
			break;
		}//end case 1
		case 2:{//start case 2
			if(Garage.Retrive(c1)==success){
			    int i=false;
			    cout<<"cout enter the number of the Passangers for the travel: "<<endl;
			    	cin>>pa;
			    while(i!=true){
			    	if(pa<=0){
	    				cout<<"Connect travel car for no Passangers:\n";
			    	cout<<"Please tell me who many Passangers will travel:\n";
			    	cin>>pa;
	    			}
    				if(checkPassengers(c1,pa)==true){
    				c1.SetPassengers(pa);
    				c1.Addmoney();
    				car c2;
    				if(CheckFull(Travel)==overflow){
				    	Travel.Retrive(c2);
				    	Garage.Serve();
				    	Garage.Append(c2);
				    	Travel.Serve();
				    	Travel.Append(c1);
				    	cout<<"I Have Retrieve a car from the Travel station because its Full:\n";
				    }
				    else{
    				Travel.Append(c1);
        			Garage.Serve();
				    }
			        cout<<"I Traveled the car\n";
			        cout<<"**********\n";
			        i=true;
    			}
    			else{
			    	cout<<"This number connect be in this car this car have only: "<<c1.GetseatNo()<<" seats"<<endl;
	    				cout<<"Please tell me who many Passangers will travel:\n";
	    				cin>>pa;
	    			}
	    			
 			
			    }
    			
    			}
			    else
			cout<<"The Garage is empty\n\n";
			cout<<"**********\n";
			break;
			}//end case 2
			case 3:{//start case 3
				car c2;
				if(Forward(Garage,c2)==false)
				cout<<"The Garage is empty\n";
				else{
					int i=false;
			        cout<<"cout enter the number of the Passangers for the travel: "<<endl;
			    	cin>>pa;
			        while(i!=true){
			    	if(pa<=0){
	    				cout<<"Connect travel car for no Passangers:\n";
			    	cout<<"Please tell me who many Passangers will travel:\n";
			    	cin>>pa;
	    			}
    				if(checkPassengers(c2,pa)==true){
    				c2.SetPassengers(pa);
    				c2.Addmoney();
    				car c3;
    				if(CheckFull(Travel)==overflow){
				    	Travel.Retrive(c3);
				    	Garage.Serve();
				    	Garage.Append(c3);
				    	Travel.Serve();
				    	Travel.Append(c2);
				    	cout<<"I Have Retrieve a car from the Travel station because its Full:\n";
				    }
				    else{
    				Travel.Append(c2);
        			Garage.Serve();
				    }
			        cout<<"I Traveled the car\n";
			        cout<<"**********\n";
			        i=true;
    			}
    			else{
			    	cout<<"This number connect be in this car this car have only: "<<c2.GetseatNo()<<" seats"<<endl;
	    				cout<<"Please tell me who many Passangers will travel:\n";
	    				cin>>pa;
	    			}
	    			
 			
			    }
					
				}
				break;
			
			}//end case 3
		case 4:{//start case 4
			if(CheckFull(Garage)==overflow){
				cout<<"The Garage is Full\n";
				cout<<"**********\n";
			}
			else{
			int x;
			cout<<"Anywhere you want to put the car tell me the position: ";
			cin>>x;
			while(x>maxsize || x<1){
				cout<<"there is no position in the Garage like this: \n";
				cout<<"enter the position again: \n";
				cin>>x;
			}
			cout<<"enter an car: \n";
			cout<<"Enter the ID of the car:\n";
			int z;
			cin>>z;
			while(z<1){
				cout<<"Enter another ID up then 0: ";
				cin>>z;
			}
			while(checkID(z,Garage)==true){
				cout<<"Enter another ID this ID is already exit in the Garage: \n";
				cin>>z;
			}
			if(checkID(z,Travel)==true){
				cout<<"This ID is already used its in Travel\n";
				TravelSwitch(Travel,z);
				Travel.Retrive(c1);
				Travel.Serve();
				cout<<"I returned it to the Garage\n";
			}
			else{
				cin>>c1;
				c1.SetCarID(z);
			}
			if(CheckFull(Garage)==underflow){
					Garage.Append(c1);
				cout<<"the car is added to the first location becuse the Garage is empty\n";
			}
			else{
				int b=Insert(Garage,x,c1);
				if(b==true)
				cout<<"The car has entered the desired location: \n";
				else
				cout<<"The car has entred after the last car, because there is no cars after the Location:"
				<<LastLocation(Garage)-1<<endl;
			}
			cout<<"**********\n";
			}
			break;
		}//end case 4
			
		
	
		case 5:{//start case 5
			PrintInformation(Garage);
			break;
		}//end case 5
		case 6:{//start case 6
			cout<<"**********"<<endl;
			cout<<"The Income earned by the Garage is: "<<car::c<<endl;
			cout<<"**********"<<endl;
			break;
		}//end case 6
		case 7:{//start case 7
			SuperDriver(Garage,Travel);
			break;
		}//end case 7
	}//end siwtch
	cout<<"choice 1 for add a car to the Garage:\n";
	cout<<"choice 2 for Travel time:\n";
	cout<<"choice 3 to Forward a car: \n";
	cout<<"choice 4 for insert a car at Specific location: \n";
	cout<<"choice 5 for Garage InFormation\n";
	cout<<"choice 6 to know Garage Income:\n";
	cout<<"choice 7 to know the Super Driver:\n";
	cout<<"press 8 to stop the program:\n";
	cin>>choice;
	}//end while
	
	cout<<"See you another Day\n";
	cout<<"**********\n";
	
}// end main
template <typename T>
bool checkID(int n,queue<T> G){// check ID if exist
	car s1;
	while(!G.empty()){
		G.Retrive(s1);
		if(s1.GetCarID()==n)
		return true;
		G.Serve();
	}
	return false;
}//end CheckID
bool checkPassengers(car c,int p){// check the number of passengers
	if(c.GetseatNo()>=p )
	return true;
	return false;
}//end CheckPassengers
/*template <typename T>
bool search(queue <T>Garage,int p){
	car s;
	while(!Garage.empty()){
		Garage.Retrive(s);
		if(s.GetseatNo()>=p)
		return true;
		Garage.Serve();
	}
	return false;

}*/
template <typename T>
bool Insert(queue <T>&Garage,int z,car mazda){//To insert the car at the specific Location in the Garage
	queue <T>temp1;
	car c;
	int Counter=0;
	int j;
	while(!Garage.empty()){
		Garage.Retrive(c);
		temp1.Append(c);
		Garage.Serve();
		Counter++;
	}
	if(z<=Counter){
	for(int i=1;i<=Counter;i++){
		temp1.Retrive(c);
		if(i==z){
			Garage.Append(mazda);
		}
		Garage.Append(c);
		temp1.Serve();
	}
	return true;
	}
	else{
		for(int i=1;i<=Counter;i++){
		temp1.Retrive(c);
		Garage.Append(c);
		temp1.Serve();
	}
	Garage.Append(mazda);
	return false;
	}
	
}//end insert
template <typename T>
void PrintInformation(queue <T>Garage){// print information of the garage
	int Counter=0;
	if(Garage.empty())
	cout<<"The Garage is empty\n";
	else{
	car s;
	while(!Garage.empty()){
		Garage.Retrive(s);
		cout<<"**********"<<endl;
		cout<<"car number "<<Counter+1<<endl<<endl;
		cout<<"The ID: "<<s.GetCarID()<<endl;
		cout<<"Seat of the car: "<<s.GetseatNo()<<endl;
		cout<<"Price for each seat is : "<<s.GetseatPrice()<<endl;
		cout<<"Driver named: "<<s.GetDrivername()<<endl;
		cout<<"has income TotalMoney: "<<s.GetTotal()<<endl;
		
		Garage.Serve();
		Counter++;
	}
	}
	cout<<"**********"<<endl;
	cout<<"# of cars in the Garage is: "<<Counter<<endl;
	cout<<"**********"<<endl;
	cout<<"Total money income to the Garage is: "<<car::c<<endl;
	cout<<"**********"<<endl;
}//end PrintInformation
template <typename T>
void SuperDriver(queue <T>Garage,queue <T>Travel){//Find the Super Driver
	double count=0;
	car c;
	queue <T>temp1,temp2;
	if(Garage.empty() && Travel.empty())
	cout<<"**********\nThe Garage and Travel is empty\n**********\n";
	else{
		while(!Garage.empty()){
		Garage.Retrive(c);
		if(c.GetTotal()>count)
		count=c.GetTotal();
		temp1.Append(c);
		Garage.Serve();
	}
	while(!Travel.empty()){
		Travel.Retrive(c);
		if(c.GetTotal()>count)
		count=c.GetTotal();
		temp2.Append(c);
		Travel.Serve();
	}
	while(!temp1.empty()){
		temp1.Retrive(c);
		if(count==c.GetTotal())
		cout<<"The Super Driver name is: "<<c.GetDrivername()<<" and have income money: "<<c.GetTotal()<<endl;
		temp1.Serve();
	}
	while(!temp2.empty()){
		temp2.Retrive(c);
		if(count==c.GetTotal())
		cout<<"The Super Driver name is: "<<c.GetDrivername()<<" and have income money: "<<c.GetTotal()<<endl ;
		temp2.Serve();
		
	}
	cout<<"*********\n";
	}
	
}//end SuperDriver
template <typename T>
int Forward(queue <T>&Garage,car &c2){
	if(!Garage.empty()){
		car c1;
		queue <T>temp;
		Garage.Retrive(c2);
		while(!Garage.empty()){
			Garage.Retrive(c1);
			temp.Append(c1);
			Garage.Serve();
		}
		while(!temp.empty()){
			temp.Retrive(c1);
			Garage.Append(c1);
			temp.Serve();
		}
		return true;
	}
	return false;
	
}
template <typename T>
errorcode CheckFull(queue <T>Garage){//check the garage if is full
	if(Garage.empty())
	return underflow;
	else{
		int i=0;
		while(!Garage.empty()){
			Garage.Serve();
			i++;
		}
		if(i==maxsize)
		return overflow;
	}
	return success;
}//end CheckFull
template <typename T>
int  LastLocation(queue <T>temp1){//To know what the last location when add a new car at a specific location
	int i=0;
	while(!temp1.empty()){
		temp1.Serve();
		i++;
	}
	return i;
}//end LastLocation
template <typename T>
void TravelSwitch(queue <T>&Travel,int x){//To return the car when I call it ,
//If I enter ID and it is exist the car that have this ID will be returned
	if(!Travel.empty()){
		car c,c1;
	       queue <T>temp;
		while(!Travel.empty()){
		Travel.Retrive(c1);
		if(c1.GetCarID()!=x){
			temp.Append(c1);
		}
		else
		c=c1;
		Travel.Serve();
	}
	Travel.Append(c);
	while(!temp.empty()){
		temp.Retrive(c1);
		Travel.Append(c1);
		temp.Serve();
	}
	}
}//end TravelSwitch