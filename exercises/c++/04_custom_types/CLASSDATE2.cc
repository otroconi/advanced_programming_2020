#include <iostream>


using namespace std;

enum class Month {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};

/*Defining a plus operator for the class Month*/
Month operator++(Month& m){
	m = (m == Month::dec)? Month::jan : Month(static_cast<int>(m) + 1);
	return m;
}

class Date{

	private:
		int d; //day
		Month m; //type=Month, value=month; necessary to use the value month when we define the function get_Month 
		int y; //year
	public:

		int get_Day() const {return d; }
		Month get_Month() const {return m;}
		int get_Year() const {return y;}


		Date(int day, Month month, int year): d{day},  m{month}, y{year} {}
		~Date(){}

		int add_one();
		int add_days(int n);

	friend std::ostream& operator<<(std::ostream& os, const Date& d){
	os << d.get_Day() << "/" << static_cast<int>(d.get_Month()) << "/" << d.get_Year() << " " << endl;
		return os;
	};



	friend bool operator==(const Date& lhs, const Date& rhs){
		return lhs.get_Day() == rhs.get_Day()
			&& lhs.get_Month() == rhs.get_Month()
			&& lhs.get_Year() == rhs.get_Year();
	}
	friend bool operator!=(const Date& lhs, const Date& rhs){
		return !(lhs == rhs);
	}
	friend bool operator&&(const Date& lhs, const Date& rhs);
	friend bool operator||(const Date& lhs, const Date& rhs);
};

bool is_leap(const int y){
	if (y%100 != 0 && (y%4 == 0 || y%400 == 0))
		return true;
	return false;
}

int MaxDaysMonth(Month m, int y){
	int maxdays{0};
	switch (m) {
		case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct: case Month::dec:
			maxdays = 31;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			maxdays = 30;
			break;
		case Month::feb:
			if (is_leap(y)){
				maxdays = 29;}
			else
				maxdays = 28;
			break;
		default:
			cout << "Unkown option" << endl;
			break;
	}
	return maxdays;
}

int Date::add_one(){
	int d_max = MaxDaysMonth(m,y);

	if (d > d_max && m!=Month::dec) {
		d -= d_max;
		operator++(m);}
	else if (d > d_max && m==Month::dec){
		d -= d_max;
		operator++(m);
		y +=1;}
	else if (d<d_max){
			d += 1;}
	else if (d=d_max && m!=Month::dec){
		d = 1;
		operator++(m);}	//jump to the next month using the operator++ for the class Month
	else if (d=d_max && m==Month::dec){
		d = 1;
		operator++(m);
		y += 1;}
	else 
		cout << "No possible option " << endl;

	cout << "Max days in this month is " << d_max << endl;
	cout << "the new date is " << Date{d,m,y} << endl;

}

int Date::add_days(int n){
	int n_nextyear = is_leap(y+1)?366:365;

	if (n >= 365){	
		d = n-n_nextyear+d;
		y += 1;
		add_one();}
	else{
		d = n+d-1;
		add_one();}

}

int main(){

	cout << "Month June in number is: " << static_cast<int>(Month::jun) << endl;
	cout << "Test to print a specific date 02/06/2019 " << endl;
	Date d{2,Month::jun,2019};
	cout << "Date " << d << std::endl;
	cout << "Add one day to " << d << endl;
//	d.add_one();
	d.add_days(1); //The same result as d.add_one()

	cout << "Add five days to " << d << endl;
	d.add_days(5);

	//Playing with the last day of the year//
	Date d1{31,Month::dec,2019};
//	cout << "Add five days to " << d1 << endl;
//	d1.add_days(5);

	cout << "Add 367 days to " << d1 << endl;
	d1.add_days(367);

	//Playing with December//
	Date d2{28,Month::dec,2019};
//	cout << "Add three days to " << d2 << endl;
//	d2.add_days(4);

	cout << "Add 367 days to " << d2 << endl;
	d2.add_days(367);

	//Playing with February//
	Date d3{28,Month::feb,2019};
//	cout << "Add three days to " << d3 << endl;
//	d3.add_days(4);

	cout << "Add 367 days to " << d3 << endl;
	d3.add_days(367);

	cout << "Using get_Day, get_Month and get_Year for " << d << " " << d.get_Day() << "/" << static_cast<int>(d.get_Month()) << "/" << d.get_Year() << endl;


	return 0;
}

