#include<iostream>
#include<fstream>
using namespace std;
class room_node {
public:
	int room_id;
	char type;
	float price;
	int status;
	string features;
	room_node* pnext;
};
class guest_node {
public:
	int id;
	string name;
	string password;
	guest_node* pnext;
};
class guest_list {
	guest_node* phead;
	guest_node* ptail;
public:
	guest_list() {
		phead = NULL;
		ptail = NULL;
	}
	void signup(guest_node* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			pnn->pnext = NULL;
			ptail = pnn;
		}
		ofstream write;
		write.open("guest.txt", ios::app);
		write << pnn->id << "   " << pnn->name << "   " << pnn->password << endl;
		write.close();
	}
	int login(string username, string password) {
		guest_node temp;
		ifstream read;
		read.open("guest.txt");
		while (!read.eof()) {
			read >> temp.id >> temp.name >> temp.password;
			if (temp.name == username && temp.password == password) {
				read.close();
				return 1;
			}
		}
		read.close();
		return 0;
	}
};
class room_list {
	room_node* phead;
	room_node* ptail;
public:
	room_list()
	{
		phead = NULL;
		ptail = NULL;
	}
	void attach(room_node* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			pnn->pnext = NULL;
			ptail = pnn;
		}
	}

	void Save_One_Room_To_File(room_node* pnn)
	{
		ofstream write;
		write.open("room.txt", ios::app);
		write << pnn->room_id << "   " << pnn->type << "   " << pnn->price << "   " << pnn->status << "   " << pnn->features << endl;
		write.close();

	}
	void delete_room(int id) {
		phead = NULL;
		ptail = NULL;
		ifstream readfile;
		room_node* pnn;
		readfile.open("room.txt");
		while (!readfile.eof()) {
			pnn = new room_node;
			readfile >> pnn->room_id >> pnn->type >> pnn->price >> pnn->status >> pnn->features;
			if (readfile.eof())
				break;
			if (pnn->room_id != id) {
				attach(pnn);
			}
		}
		readfile.close();
		ofstream write;
		write.open("room.txt");
		room_node* ptrav = phead;
		while (ptrav != NULL) {
			write << ptrav->room_id << "    " << ptrav->type << "    " << ptrav->price << "    " << ptrav->status << "    " << ptrav->features << endl;
			ptrav = ptrav->pnext;
		}
		write.close();

	}
	float get_price(int room_id)
	{
		ifstream readfile;
		room_node* pnn;
		readfile.open("room.txt");
		while (!readfile.eof()) {
			pnn = new room_node;
			readfile >> pnn->room_id >> pnn->type >> pnn->price >> pnn->status >> pnn->features;
			if (pnn->room_id == room_id) {
				readfile.close();
				return pnn->price;
			}
		}
		readfile.close();
		return 0.0;
	}
	bool is_Available(int room_id)
	{
		ifstream readfile;
		room_node* pnn;
		readfile.open("room.txt");
		while (!readfile.eof()) {
			pnn = new room_node;
			readfile >> pnn->room_id >> pnn->type >> pnn->price >> pnn->status >> pnn->features;
			if (pnn->room_id == room_id &&pnn->status==0) {
				readfile.close();
				return true;
			}
		}
		readfile.close();
		return false;
	}
	void Change_status_to_Unavailable(int room_id)
	{
		ifstream readfile;
		room_node* pnn;
		readfile.open("room.txt");
		while (!readfile.eof()) {
			pnn = new room_node;
			readfile >> pnn->room_id >> pnn->type >> pnn->price >> pnn->status >> pnn->features;
			if (readfile.eof())
				break;
			if (pnn->room_id == room_id) {
				pnn->status = 1;
			}
			attach(pnn);
		}
		readfile.close();

		ofstream write;
		write.open("room.txt");
		room_node* ptrav = phead;
		while (ptrav != NULL) {
			write << ptrav->room_id << "    " << ptrav->type << "    " << ptrav->price << "    " << ptrav->status << "    " << ptrav->features << endl;
			ptrav = ptrav->pnext;
		}
		write.close();
	}
	void Change_status_to_available(int room_id)
	{
		ifstream readfile;
		room_node* pnn;
		readfile.open("room.txt");
		while (!readfile.eof()) {
			pnn = new room_node;
			readfile >> pnn->room_id >> pnn->type >> pnn->price >> pnn->status >> pnn->features;
			if (readfile.eof())
				break;
			if (pnn->room_id == room_id) {
				pnn->status = 0;
			}
			attach(pnn);
		}
		readfile.close();

		ofstream write;
		write.open("room.txt");
		room_node* ptrav = phead;
		while (ptrav != NULL) {
			write << ptrav->room_id << "    " << ptrav->type << "    " << ptrav->price << "    " << ptrav->status << "    " << ptrav->features << endl;
			ptrav = ptrav->pnext;
		}
		write.close();
	}
	void update(int id, int price, int status, string features) {
		phead = NULL;
		ptail = NULL;
		ifstream readfile;
		room_node* pnn;
		readfile.open("room.txt");
		while (!readfile.eof()) {
			pnn = new room_node;
			readfile >> pnn->room_id >> pnn->type >> pnn->price >> pnn->status >> pnn->features;
			if (readfile.eof())
				break;
			if (pnn->room_id == id) {
				pnn->price = price;
				pnn->status = status;
				pnn->features = features;

			}
			attach(pnn);
		}
		readfile.close();
		ofstream write;
		write.open("room.txt");
		room_node* ptrav = phead;
		while (ptrav != NULL) {
			write << ptrav->room_id << "    " << ptrav->type << "    " << ptrav->price << "    " << ptrav->status << "    " << ptrav->features << endl;
			ptrav = ptrav->pnext;


		}
		write.close();
	}

	void display() {
		room_node temp;
		ifstream read;
		read.open("room.txt");

		while (!read.eof()) {
			read >> temp.room_id >> temp.type >> temp.price >> temp.status >> temp.features;
			if (read.eof()) {
				break;
			}
			cout << temp.room_id << "   " << temp.type << "   " << temp.price << "   " << temp.status << "   " << temp.features << endl;
		}

		read.close();
	}
	void search_for_room(char type, int price1, int price2) {
		room_node temp;
		ifstream read;
		read.open("room.txt");

		while (!read.eof()) {
			read >> temp.room_id >> temp.type >> temp.price >> temp.status >> temp.features;
			if (read.eof())
				break;
			if (temp.type == type && temp.price >= price1 && temp.price <= price2 && temp.status == 0) {
				cout << temp.room_id << "   " << temp.type << "   " << temp.price << "   " << temp.status << "   " << temp.features << endl;

			}

		}
		read.close();
	}
	int occupancy_rate() {
		room_node temp;
		ifstream read;
		read.open("room.txt");
		int ct = 0;

		while (!read.eof()) {
			read >> temp.room_id >> temp.type >> temp.price >> temp.status >> temp.features;
			if (read.eof()) {
				break;
			}
			if (temp.status == 1) {
				ct++;
			}
		}
		read.close();
		return ct;
	}
};
class booking_node {
public:
	int booking_id;
	int guest_id;
	int room_id;
	int day_date;
	int month_date;
	int checkout_day;
	int checkout_month;
	float total_cost;
	booking_node* pnext;
};
class booking_list {
	booking_node* phead;
	booking_node* ptail;
public:
	booking_list() {
		phead = NULL;
		ptail = NULL;
	}
	void attach_booking(booking_node* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			pnn->pnext = NULL;
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void save_one_Booking_To_File(booking_node* pnn)
	{
		ofstream write;
		write.open("booking.txt", ios::app);
		write << pnn->booking_id << "   " << pnn->guest_id << "   "<<pnn->room_id<<"    " << pnn->day_date << "   " << pnn->month_date << "   " << pnn->checkout_day << "   " << pnn->checkout_month << "   " << pnn->total_cost << endl;
		write.close();
	}
	void booking_Room(booking_node* pnn)
	{
		room_list room;
		if (room.is_Available(pnn->room_id) == true)
		{
			float tot = (pnn->checkout_day - pnn->day_date) * room.get_price(pnn->room_id);
			tot += (tot * 0.14f); // Calculate Total Cost With VAT
			pnn->total_cost = tot;
			save_one_Booking_To_File(pnn);
			room.Change_status_to_Unavailable(pnn->room_id);
		}
		else
		{
			cout << "THis Room Not Available Now, Sorry!" << endl;
		}
	}
	void Cancel_Booking(int Guest_ID,int room_id, int Today)
	{
		ifstream read;
		booking_node* pnn;
		room_list r;
		phead = NULL;
		ptail = NULL;
		read.open("booking.txt");
		while (!read.eof())
		{
			pnn = new booking_node;
			read >> pnn->booking_id >> pnn->guest_id>>pnn->room_id >> pnn->day_date >> pnn->month_date >> pnn->checkout_day >> pnn->checkout_month >> pnn->total_cost;
			if (read.eof())
				break;
			if (pnn->guest_id == Guest_ID && pnn->room_id == room_id && Today < pnn->day_date)
			{
				r.Change_status_to_available(pnn->room_id);
			}
			else
			{
				attach_booking(pnn);
			}
		}
		read.close();
		ofstream write;
		write.open("booking.txt");
		pnn = phead;
		while (pnn != NULL)
		{
			write << pnn->booking_id << "   " << pnn->guest_id << "   " << pnn->room_id << "    " << pnn->day_date << "   " << pnn->month_date << "   " << pnn->checkout_day << "   " << pnn->checkout_month << "   " << pnn->total_cost << endl;
			pnn = pnn->pnext;
		}
		write.close();
	}
	void View_Booking_History_For_Specific_Guest(int guest_id)
	{
		ifstream read;
		booking_node* pnn;
		read.open("booking.txt");
		while (!read.eof())
		{
			pnn = new booking_node;
			read >> pnn->booking_id >> pnn->guest_id>>pnn->room_id >> pnn->day_date >> pnn->month_date >> pnn->checkout_day >> pnn->checkout_month >> pnn->total_cost;
			if (read.eof())
				break;
			if (pnn->guest_id == guest_id )
			{
				cout << pnn->booking_id << "   " << pnn->guest_id << "   " << pnn->room_id << "    " << pnn->day_date << "   " << pnn->month_date << "   " << pnn->checkout_day << "   " << pnn->checkout_month << "   " << pnn->total_cost << endl;

			}
		}
		read.close();
	}
	void View_All_Booking()
	{
		ifstream read;
		booking_node* pnn;
		read.open("booking.txt");
		while (!read.eof())
		{
			pnn = new booking_node;
			read >> pnn->booking_id >> pnn->guest_id>>pnn->room_id >> pnn->day_date >> pnn->month_date >> pnn->checkout_day >> pnn->checkout_month  >> pnn->total_cost;
			if (read.eof())
				break;
			cout << pnn->booking_id << "   " << pnn->guest_id << "   "<< pnn->room_id << "    " << pnn->day_date << "   " << pnn->month_date << "   " << pnn->checkout_day << "   " << pnn->checkout_month << "   " << pnn->total_cost << endl;
		}
		read.close();
	}
	float Daily_Income_Report(int Day)
	{
		ifstream read;
		booking_node* pnn;
		float tot=0.0;
		read.open("booking.txt");
		while (!read.eof())
		{
			pnn = new booking_node;
			read >> pnn->booking_id >> pnn->guest_id>>pnn->room_id >> pnn->day_date >> pnn->month_date >> pnn->checkout_day >> pnn->checkout_month >> pnn->total_cost;
			if (read.eof())
				break;
			if (pnn->day_date == Day)
			{
				tot += pnn->total_cost;
			}
		}
		read.close();
		return tot;
	}
	float Monthly_Income_Report(int Month)
	{
		ifstream read;
		booking_node* pnn;
		float tot = 0.0;
		read.open("booking.txt");
		while (!read.eof())
		{
			pnn = new booking_node;
			read >> pnn->booking_id >> pnn->guest_id>>pnn->room_id >> pnn->day_date >> pnn->month_date >> pnn->checkout_day >> pnn->checkout_month >> pnn->total_cost;
			if (read.eof())
				break;
			if (pnn->month_date == Month)
			{
				tot += pnn->total_cost;
			}
		}
		read.close();
		return tot;
	}
};
class admin_node {
public:
	int id;
	string name;
	string password;
	admin_node* pnext;
};



class admin {
	admin_node* phead;
	admin_node* ptail;
public:
	admin() {
		phead = NULL;
		ptail = NULL;
	}
	void signup(admin_node* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			pnn->pnext = NULL;
			ptail->pnext = pnn;
			ptail = pnn;
		}
		
	}
	void Save_One_Admin_to_file(admin_node* pnn)
	{
		ofstream write;
		write.open("admin.txt", ios::app);
		write << pnn->id << "   " << pnn->name << "   " << pnn->password << endl;
		write.close();
	}
	int login(string username, string password) {
		admin_node temp;
		ifstream read;
		read.open("admin.txt");
		while (!read.eof()) {
			read >> temp.id >> temp.name >> temp.password;
			if (temp.name == username && temp.password == password) {
				read.close();
				return 1;
			}
		}
		read.close();
		return 0;
	}
};
void main() {
	admin_node* pnn_admin;
	guest_node* pnn_guest;
	room_node* pnn_room;
	booking_node* pnn_booking;
	admin A;
	room_list R;
	guest_list g;
	booking_list b;
	int choice = 1;
	int day;
	while (choice > 0) 
	{
		cout << "# if you are Admin press 1 " << endl;
		cout << "# 2- Guest" << endl;
		cout << "who are you ? " << endl;
		cin >>choice;
		if (choice == 1)
		{
			cout << "enter username " <<endl;
			pnn_admin = new admin_node;
			cin >> pnn_admin->name;
			cout << "enter password " << endl;
			cin >> pnn_admin->password;
			if (A.login(pnn_admin->name, pnn_admin->password) == 1) 
			{

				cout << "1.insert new room" << endl;
				cout << "2.display all rooms" << endl;
				cout << "3.Delete specific room" << endl;
				cout << "4.Update specific room" << endl;
				cout << "5.View All Booking" << endl;
				cout << "6.How Many Rooms Not Available ? " << endl;
				cout << "7.Daily Income Report" << endl;
				cout << "8.Monthly Income Report" << endl;
				cout << "Choose which operation : ";
				cin >> choice;
				if (choice == 1) {
					pnn_room = new room_node;
					cout << "room id" << endl;
					cin >> pnn_room->room_id;
					cout << "enter room type" << endl;
					cin >> pnn_room->type;
					cout << "enter room features" << endl;
					cin >> pnn_room->features;
					cout << "enter room price" << endl;
					cin >> pnn_room->price;
					cout << "Enter room status ";
					cin >> pnn_room->status;
					R.Save_One_Room_To_File(pnn_room);
				}
				else if (choice == 2) {
					R.display();
				}
				else if (choice == 3)
				{
					pnn_room = new room_node;
					cout << "room id" << endl;
					cin >> pnn_room->room_id;
					R.delete_room(pnn_room->room_id);
				}
				else if (choice == 4)
				{
					pnn_room = new room_node;
					cout << "room id" << endl;
					cin >> pnn_room->room_id;
					cout << "enter room features" << endl;
					cin >> pnn_room->features;
					cout << "enter room price" << endl;
					cin >> pnn_room->price;
					cout << "Enter room status ";
					cin >> pnn_room->status;
					R.update(pnn_room->room_id, pnn_room->price, pnn_room->status, pnn_room->features);
				}
				else if (choice == 5)
				{
					b.View_All_Booking();
				}
				else if (choice == 6)
				{
					cout << "Rooms Not Available = " << R.occupancy_rate() << endl;
				}
				else if (choice == 7)
				{

					cout << "Enter Day : ";
					cin >> day;
					b.Daily_Income_Report(day);
				}
				else if (choice == 8)
				{
					int month;
					cout << "Enter Month : ";
					cin >> month;
					b.Monthly_Income_Report(month);
				}

			}
			else
			{
				cout << "username or passwordis inncorrect!" << endl;
			}
		}
		else {
				cout << "1-Login" << endl;
				cout << "2-signup" << endl;
				cout << "pick operation ";
				cin >> choice;
				if (choice == 1)
				{
					pnn_guest = new guest_node;
					cout << "enter name" << endl;
					cin >> pnn_guest->name;
					cout << "enter passsord" << endl;
					cin >> pnn_guest->password;
					if (g.login(pnn_guest->name, pnn_guest->password) == true)
					{
						cout << "1- Filter Rooms By Type, price , status" << endl;
						cout << "2- Book Room" << endl;
						cout << "3- Cancel Booking" << endl;
						cout << "4- View My Booking History" << endl;
						cout << "Choose which operation ";
						cin >> choice;
						if (choice == 1)
						{
							pnn_room = new room_node;
							int price1, price2;
							cout << "enter room type" << endl;
							cin >> pnn_room->type;
							cout << "enter room features" << endl;
							cin >> pnn_room->features;
							cout << "enter First price " << endl;
							cin >> price1;
							cout << "enter second price " << endl;
							cin >> price2;
							cout << "Enter room status ";
							cin >> pnn_room->status;
							R.search_for_room(pnn_room->type, price1, price2);
						}
						else if (choice == 2)
						{
							pnn_booking = new booking_node;
							cout << "Enter Booking Id ";
							cin >> pnn_booking->booking_id;
							cout << "Enter Guest Id ";
							cin>>pnn_booking->guest_id; 
							cout << "Enter Room Id ";
							cin >> pnn_booking->room_id;
							cout << "Enter Check-in Day ";
							cin >> pnn_booking->day_date;
							cout << "Enter Check-out Day ";
							cin >> pnn_booking->checkout_day;
							cout << "Enter Check-in Month ";
							cin >> pnn_booking->month_date;
							cout << "Enter Check-out Month ";
							cin >> pnn_booking->checkout_month;
							b.booking_Room(pnn_booking);
						}
						else if (choice == 3)
						{
							pnn_booking = new booking_node;
							cout << "Enter Guest Id ";
							cin >> pnn_booking->guest_id;
							cout << "Enter Room Id ";
							cin >> pnn_booking->room_id;
							cout << "Enter Canceling Day ";
							cin >> day;
							b.Cancel_Booking(pnn_booking->guest_id, pnn_booking->room_id, day);
						}
						else if (choice == 4)
						{
							pnn_booking = new booking_node;
							cout << "Enter Guest Id ";
							cin >> pnn_booking->guest_id;
							b.View_Booking_History_For_Specific_Guest(pnn_booking->guest_id);
						}

					}
				}
				else
				{
					pnn_guest = new guest_node;
					cout << "enter id" << endl;
					cin >> pnn_guest->id;
					cout << "enter name" << endl;
					cin >> pnn_guest->name;
					cout << "enter passsord" << endl;
					cin >> pnn_guest->password;
					g.signup(pnn_guest);
				}

			}
		cout << "do you want to do mor operations ?" << endl;
		cin >> choice;

	}


}

