#include <iostream>
#include<string>
using namespace std;
class date
{
private:int day, month, year;
public:
	date()
	{
		day = month = year = 0;
	}
	date(int daya, int montha, int yeara)
	{
		day = daya;
		month = montha;
		year = yeara;
	}
	date(const date &d)
	{
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
	}
	void setday()
	{
		cout << "enter the day" << endl;
		cin >> day;
	}
	void setmonth()
	{
		cout << "enter the month" << endl;
		cin >> month;
	}
	void setyear()
	{
		cout << "enter the year" << endl;
		cin >> year;
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
	void print()
	{
		cout << "Date: " << day << "/" << month << "/" << year;
	}
};
class doctor
{
protected:
	int id;
	string name;
	string address;
	date t;
	int type;

public:
	doctor() :t()
	{
		id = 0;
		name = address = " ";
	}
	~doctor()
	{}
	doctor(int new_id, string new_name, string new_address, date y) :t(y)
	{
		id = new_id;
		name = new_name;
		address = new_address;
	}
	virtual int get_type() { return 0; }
	virtual void read_id()
	{
		cout << "Enter His Id:";
		cin >> id;
	}
	void setdate(date e)
	{
		t = e;
	}
	virtual void read()
	{

		cout << "Enter Name the doctor:";
		getline(cin, name);
		getline(cin, name);
		cout << "Enter His Address:";
		getline(cin, address);
		cout << "Enter His Birth Date:";
		t.setday(); t.setmonth(); t.setyear();
	}
	void set_id(int id)
	{
		this->id = id;
	}
	void set_name(string name)
	{
		this->name = name;
	}
	void set_address(string address)
	{
		this->address = address;
	}
	int get_id()
	{
		return id;
	}

	string get_name()
	{
		return name;
	}
	string get_address()
	{
		return address;
	}
	int get_year()
	{
		return t.getyear();
	}
	int get_month()
	{
		return t.getmonth();
	}
	int get_day()
	{
		return t.getday();
	}
	virtual void print()
	{
		cout << "Id:" << id;
		cout << "\tName:" << name;
		cout << "\tAddressd:" << address;
		cout << "\tBirth:" << t.getday() << "/" << t.getmonth() << "/" << t.getyear() << endl;
	}
};
class doctor_in : public doctor
{
private:
	int rev_part;
	double salary;
	int years_on;
public:
	doctor_in() :
		doctor()
	{
		rev_part = years_on = 1;
		salary = 10000.0;
	}
	~doctor_in()
	{}
	doctor_in(int new_id, string new_name, string new_address, date h, int rev, int years, double sala) :
		doctor(new_id, new_name, new_address, h)
	{
		rev_part = rev;
		years_on = years;
		salary = sala;
	}
	doctor_in(const doctor_in & in) :doctor(in)
	{
		this->rev_part = in.rev_part;
		this->years_on = in.years_on;
		this->salary = in.salary;
	}
	void set_sala(double x)
	{
		salary = x;
	}
	double set_salary()
	{
		double bouns;
		double temp;
		if (years_on % 2 == 0)
		{
			bouns = years_on / 2;
		}
		else
			bouns = (years_on - 1) / 2;
		temp = salary * (bouns*0.1);
		salary = salary + temp;
		return salary;
	}
	void readname()
	{
		doctor::read();
		doctor::read_id();
	}
	void set_part(int x)
	{
		rev_part = x;
	}
	void readin()
	{
		system("cls");
	rept:
		cout << "enter (1) for Department of Ambulance\nenter (2) for Department of ophthalmology\nenter (3) for Department of chest\nenter (4) for General Surgery" << endl;
		cout << "enter (5) for Internal Clinics\nenter (6) for Ophthalmology clinics\nenter (7) for Digestive clinics" << endl;
		cout << "Enter Rev. Part:";
		cin >> rev_part;
		if (rev_part > 7)
			goto rept;
		system("cls");
		cout << "Enter years Of work:";
		cin >> years_on;
		cout << "Enter His Bais Salary:";
		cin >> salary;
		system("cls");
	}
	void print() override
	{
		cout << "*********************" << endl;
		doctor::print();
		cout << "Rev Part:" << rev_part << "\t Salary:" << set_salary() << "\t Installed Doctor." << endl;
	}
	int get_type()
	{
		return 1;
	}
};
class doctor_tr : public doctor
{
private:
	date y;
	double salary;
	date r;
public:
	doctor_tr() :r(), y()
	{
		salary = 10000.0;
	}
	~doctor_tr()
	{}
	doctor_tr(int new_id, string new_name, string new_address, date u, date o, date s) :
		doctor(new_id, new_name, new_address, o)
	{
		y = u;
		r = s;
	}
	doctor_tr(const doctor_tr & tr) :doctor(tr)
	{
		this->salary = tr.salary;
		this->r = tr.r;
		this->y = tr.y;
	}
	double set_salary()
	{
		int years = 2017 - y.getyear();
		if (years <= 1)
		{
			salary = 10000.0*0.5;
		}
		else
		{
			salary = 10000.0*0.75;
		}
		return salary;
	}
	int get_type()
	{
		return 2;

	}
	void read_id()
	{
		doctor::read_id();
	}
	void readtry()
	{
		doctor::read();
		cout << "Enter the date of start trining:";
		y.setday(); y.setmonth(); y.setyear();
		cout << "Enter the date of End trining:";
		r.setday(); r.setmonth(); r.setyear();
		system("cls");
	}
	int get_dayw()
	{
		return r.getday();
	}
	int get_monthw()
	{
		return r.getmonth();
	}
	int get_yearw()
	{
		return y.getyear();
	}
	date get_date()
	{
		return r;
	}
	double get_salary()
	{
		return salary;
	}
	void print() override
	{
		cout << "*********************" << endl;
		doctor::print();
		cout << "Salary:" << set_salary();
	}
};
class patient
{
protected:
	int id;
	string name;
	string address;
	int day, month, year;
public:
	patient()
	{
		id = day = month = year = 0;
		name = address = " ";
	}
	~patient() {}
	patient(int new_id, string new_name, string new_address, int d, int m, int y) {
		id = new_id;
		name = new_name;
		address = new_address;
		year = y;
		month = m;
		day = d;
	}
	patient(const patient &n) {
		id = n.id;
		name = n.name;
		day = n.day;
		month = n.month;
		year = n.year;
		address = n.address;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	void set_name(string name)
	{
		this->name = name;
	}
	void set_address(string address)
	{
		this->address = address;
	}
	void set_birth(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	int get_id()
	{
		return id;
	}
	string get_name()
	{
		return name;
	}
	string get_address()
	{
		return address;
	}
	int get_year()
	{
		return year;
	}
	int get_month()
	{
		return month;
	}
	int get_day()
	{
		return day;
	}
	virtual void read()
	{

		cout << "Enter Name Of The Patient:";
		getline(cin, name);
		getline(cin, name);
		cout << "Enter His Address:";
		getline(cin, address);
		cout << "Enter His Id:";
		cin >> id;
		cout << "Enter His Birth Date:";
		cin >> day;
		cin >> month;
		cin >> year;
	}
	virtual void print()
	{
		cout << "*********************" << endl;
		cout << "Id:" << id;
		cout << "\tName:" << name;
		cout << "\tAddressd:" << address;
		cout << "\tBirth:" << day << "/" << month << "/" << year << endl;
	}
	virtual void set_grad(char e) = 0;
	virtual void read_ex_rec() = 0;
	virtual void read_in_rec() = 0;
	virtual void print_rec() = 0;
	virtual int get_rev_part() = 0;
};
class treatment
{
protected:
	int num_treat;
	double cost;
	int day, month, year;
public:
	treatment()
	{
		num_treat = day = month = year = 0;
		cost = 1000.00;
	}
	~treatment()
	{}
	treatment(int num_treat, double cost, int day, int month, int year)
	{
		this->num_treat = num_treat;
		this->cost = cost;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	treatment(const treatment &tr) {
		num_treat = tr.num_treat;
		day = tr.day;
		month = tr.month;
		year = tr.year;
		cost = tr.cost;
	}
	void set_num_treat(int num_treat)
	{
		this->num_treat = num_treat;
	}
	void set_cost(double cost)
	{
		this->cost = cost;
	}
	void set_date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	int get_num_treat()
	{
		return num_treat;
	}
	double get_cost()
	{
		return cost;
	}
	int get_year()
	{
		return year;
	}
	int get_month()
	{
		return month;
	}
	int get_day()
	{
		return day;
	}
	void read()
	{
		cout << "Enter The Id Of this Treatment:";
		cin >> num_treat;
		cout << "Enter The Cost:";
		cin >> cost;
		cout << "Enter The Date :";
		cin >> day >> month >> year;
	}
	virtual void print()
	{
		cout << "\nTreatment Number: " << num_treat << "\t Cost Of Treatment:" << cost;
		cout << "\t\tDate Of Treatment:" << day << "/" << month << "/" << year << endl;
	}
};
class doctor_co : public doctor
{
private:
	double salary;
	date p;
	treatment t[10];
	int num;
public:
	doctor_co() :p(),
		doctor()
	{
		salary = 0.0;
		num = 0;
		t;
	}
	doctor_co(const doctor_co & co) :doctor(co)
	{
		this->salary = co.salary;
		this->num = co.num;
		this->t[num] = co.t[num];
		this->p = co.p;
	}
	~doctor_co()
	{}
	doctor_co(int new_i, string new_name, string new_address, date k, date g) :p(g),
		doctor(new_i, new_name, new_address, k)
	{
		int x;

		for (int i = 0; i < num; i++)
		{
			cin >> x;
			t[i].set_cost(x);
		}
		for (int i = 0; i < num; i++)
		{
			salary += t[i].get_cost()*0.5;
		}
		p = g;
	}
	void read()
	{
		int x;
		doctor::read_id();
		doctor::read();
		cout << "Enter the number of the treatments:";
		cin >> num;
		cout << "Enter The Costs Of the treatments:" << endl;
		for (int i = 0; i < num; i++)
		{
			cout << "Enter The Cost Of the (" << i << ") treatment: ";
			cin >> x;
			t[i].set_cost(x);
		}
		cout << "Enter The date of Contract:";
		p.setday(); p.setmonth(); p.setyear();
		system("cls");
	}
	int get_type()
	{
		return 3;
	}

	void print() override
	{
		cout << "*********************" << endl;
		doctor::print();
		cout << "\tsalary of doctor:" << set_salary() << "\tDate Of contract:" << p.getday() << "/" << p.getmonth() << "/" << p.getyear() << endl;
	}
	double set_salary()
	{
		for (int i = 0; i < num; i++)
		{
			salary += t[i].get_cost()*0.5;
		}
		return salary;
	}
};
struct node
{
	doctor *doc;
	node * next;
	node()
	{
		doc = NULL;
		next = NULL;
	}
	node(doctor_in *ptr)
	{
		doc = ptr;
		next = NULL;
	}
	node(doctor_tr *ptr1)
	{
		doc = ptr1;
		next = NULL;
	}
	node(doctor_co *ptr2)
	{
		doc = ptr2;
		next = NULL;
	}
};
class mylist
{
private:
	node *head;
public:

	mylist()
	{
		head = NULL;
	}
	void insert(node *dd)
	{
		node *temp;
		temp = new node;
		temp->doc = dd->doc;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
		}
		else {
			if (temp->doc->get_id() <= head->doc->get_id()) {
				temp->next = head;
				head = temp;
			}
			else {
				node *cur = head;
				node *prev = NULL;

				while (cur != NULL && cur->doc->get_id() < temp->doc->get_id()) {
					prev = cur;
					cur = cur->next;
				}

				temp->next = cur;
				prev->next = temp;
			}
		}



	}
	void print()
	{
		node *temp;
		temp = head;
		int n = 0;
		if (temp == NULL)
		{
			cout << "\nthe list empty" << endl;
			return;
		}

		while (temp != NULL) {
			temp->doc->print();
			temp = temp->next;
		}
	}
	int del(int value)
	{
		node *temp = new node;
		node *prev, *curr;
		if (value == head->doc->get_id())
		{
			temp = head;
			head = head->next;
			delete temp;
			return value;
		}
		else
		{
			prev = head;
			curr = head->next;
			while (curr != NULL && curr->doc->get_id() != value)
			{
				prev = curr;
				curr = curr->next;
				cout << "There is no doctor with this id..." << endl;
			}
			if (curr != NULL)
			{
				temp = curr;
				prev->next = curr->next;
				delete temp;
				return  value;
			}
		}
		return 0;
	}
	~mylist()
	{
		node *ptr;;

		for (ptr = head; head; ptr = head)
		{
			head = head->next;
			delete ptr;
		}
	}
	void search(int searchNum)
	{
		node* searchnumber = nullptr;
		node *current = head;
		node *temp = NULL;

		while (current != NULL && current->doc->get_type() != searchNum)
		{
			temp = current;
			current = current->next;

			if (current != NULL && current->doc->get_type() == 3)
			{

				searchnumber = current;

				current->doc->print();
				current = current->next;
			}
		}
	}
	node* search_doctor(int searchNum)
	{
		node* searchnumber = nullptr;
		node *current = head;
		node *temp = NULL;

		while (current != NULL && current->doc->get_id() != searchNum)
		{
			temp = current;
			current = current->next;
		}
		if (current != NULL)
		{
			searchnumber = current;
			return current;
		}
		else
			return NULL;
	}
};
mylist doctors;
class internal_treatment :public treatment
{
private:
	int rev_part;
	mylist li;
	int day, month, year;
public:
	internal_treatment()
	{
		rev_part = day = month = year = 0;
	}
	internal_treatment(int id, double cost, int d1, int m1, int y1, int rev, int d, int m, int y) :treatment(id, cost, d1, m1, y1)
	{
		rev_part = rev;
		day = d;
		month = m;
		year = y;
	}
	internal_treatment(const internal_treatment & in_tr) :treatment(in_tr)
	{
		this->rev_part = in_tr.rev_part;
		this->day = in_tr.day;
		this->month = in_tr.month;
		this->year = in_tr.year;
		this->rev_part = in_tr.rev_part;
		this->li = in_tr.li;
	}
	void read()
	{
		int x;
		int num;
		node n;
		treatment::read();
	ret:
		cout << "enter (1) for Department of Ambulance\nenter (2) for Department of ophthalmology\nenter (3) for Department of chest\nenter (4) for General Surgery" << endl;
		cout << "Enter Rev Part:";
		cin >> rev_part;
		if (rev_part > 4)
			goto ret;
		cout << "Enter The Date Of Exit:";
		cin >> day >> month >> year;
		cout << "Enter The Number Of the doctors:" << endl;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "The ID Of the doctor to add him:";
			cin >> x;
			node* n = doctors.search_doctor(x);
			node* nn = new node;
			if (n) {
				*nn = *n;
				li.insert(nn);
			}
			else {
				cout << "doctor not found" << endl;
			}

		}
		system("pause");
		system("cls");
	}
	void print()
	{
		treatment::print();
		cout << "Rev. Part:" << rev_part;
		cout << "\tDate Of Exit :" << day << "/" << month << "/" << year << endl;
		cout << "The List Of The Supervisor Doctors: " << endl;
		li.print();
	}
	int get_rev()
	{
		return rev_part;
	}
	~internal_treatment()
	{

	}
};
class external_treatment : public treatment
{
private:
	int id_clinic;
	int id_doctor;
	mylist li1;
public:
	external_treatment() :
		treatment()
	{
		id_clinic = id_doctor = 0;
	}
	external_treatment(int id, double cost, int d1, int m1, int y1, int cli, int do1) :treatment(id, cost, d1, m1, y1)
	{
		id_clinic = cli;
		id_doctor = do1;
	}
	external_treatment(const external_treatment & ex_tr) :treatment(ex_tr)
	{
		this->id_clinic = ex_tr.id_clinic;
		this->id_doctor = ex_tr.id_doctor;
		this->li1 = ex_tr.li1;
	}
	int get_rev_part()
	{
		return 0;
	}
	void read()
	{
		int x;
		treatment::read();
	rept:
		cout << "enter (5) for Internal Clinics\nenter (6) for Ophthalmology clinics\nenter (7) for Digestive clinics" << endl;
		cout << "Enter Id Of Clinic:";
		cin >> id_clinic;
		if (id_clinic > 7 || id_clinic < 5)
			goto rept;
		cout << "The ID Of the doctor to add him:";
		cin >> x;
		node* n = doctors.search_doctor(x);
		node* nn = new node;
		if (n) {
			*nn = *n;
			li1.insert(nn);
		}
		else {
			cout << "doctor not found" << endl;
		}
		system("cls");
	}
	void print()
	{
		treatment::print();
		cout << "Id Of Clinic:" << id_clinic << endl;
		li1.print();
		cout << endl;
	}

};
struct node_treat
{
	treatment *treat;
	node_treat * next;
	node_treat()
	{
		treat = NULL;
		next = NULL;
	}
	node_treat(internal_treatment *ptr)
	{
		treat = ptr;
		next = NULL;
	}
	node_treat(external_treatment *ptr1)
	{
		treat = ptr1;
		next = NULL;
	}
};
class mylist_treat
{
private:
	node_treat *first;
public:
	mylist_treat()
	{
		first = NULL;
	}
	void insert_treat(node_treat *pp)
	{
		node_treat* tmp = first;
		node_treat* n = new node_treat;
		n->treat = new treatment;
		n->treat = pp->treat;
		n->next = NULL;
		if (first == NULL) {
			first = n;
		}
		else {
			n->next = first;
			first = n;
		}
	}
	void print_treat()
	{
		node_treat *tmp;
		tmp = first;
		int n = 0;
		if (tmp == NULL)
		{
			cout << "the list empty" << endl;
			return;
		}

		while (tmp != NULL) {
			tmp->treat->print();
			tmp = tmp->next;
		}
	}
	node_treat* search_treat(int searchNum)
	{
		node_treat* searchnumber = nullptr;
		node_treat *current = first;
		node_treat *temp = NULL;

		while (current != NULL && current->treat->get_num_treat() != searchNum)
		{
			temp = current;
			current = current->next;
		}
		if (current != NULL)
		{
			searchnumber = current;
			return current;
		}
		else
			return NULL;
	}
	/*~mylist_pa()
	{
	node_pa *ptr;;

	for (ptr = first; first; ptr = first)
	{
	first = first->next;
	delete ptr;
	}
	}*/
};
mylist_treat  exter_treat_ex_pa;
class internal_pa :public patient
{
private:
	char ex;
	mylist_treat exter;
	mylist_treat inter;
	int rev;
public:
	internal_pa() :
		patient()
	{
		ex = ' ';
		rev = 0;
	}
	internal_pa(const internal_pa & in) :patient(in)
	{
		this->ex = in.ex;
		this->exter = in.exter;
		this->inter = in.inter;
		this->rev = in.rev;
	}
	internal_pa(mylist_treat t1, mylist_treat t2, int o, int i, string na, string a, int d1, int m2, int y1, char c) :patient(i, na, a, d1, m2, y1) {
		c = ex = ' ';
		exter = t1;
		inter = t2;
		rev = o;
	}
	void set_grad(char e)
	{
		ex = e;
	}
	void read_ex_rec()
	{
		external_treatment * ext = new external_treatment;
		ext->read();
		node_treat *n = new node_treat;
		n->treat = new external_treatment;
		n->treat = ext;
		node_treat *add, *add2;
		add = exter.search_treat(ext->get_num_treat());
		add2 = inter.search_treat(ext->get_num_treat());
		if (add != NULL || add2 != NULL)
			cout << "This Treat Already Found" << endl;
		else
			exter.insert_treat(n);
	}
	void read_in_rec()
	{
		internal_treatment* in_tr = new internal_treatment;
		in_tr->read();
		rev = in_tr->get_rev();
		node_treat* n = new node_treat;
		n->treat = new internal_treatment;
		n->treat = in_tr;
		node_treat *add, *add2;
		add = exter.search_treat(in_tr->get_num_treat());
		add2 = inter.search_treat(in_tr->get_num_treat());
		if (add != NULL || add2 != NULL)
		{
			cout << "This Treat Already Found" << endl;
		}
		else
		{
			inter.insert_treat(n);
		}
	}
	int get_rev_part()
	{
		return rev;
	}
	void read()
	{
		patient::read();
		cout << "Enter (Y) If He Exit And (N) If not:";
		cin >> ex;
		if (ex != 'y')
		{
			ex = 'n';
		}
		system("cls");
	}
	void print()
	{
		patient::print();
		cout << "The List Of External Treatment:" << endl;
		exter.print_treat();
		cout << "The List Of Internal Treatment:" << endl;
		inter.print_treat();
		if (ex == 'y')
			cout << "\nHe/She Exit";
		else
			cout << "\nStill in the hospital" << endl;
		cout << "===================================================================" << endl;
	}

	void print_rec()
	{
		cout << "The List Of External Treatment:" << endl;
		inter.print_treat();
		cout << "*********************************************************************";
		cout << " The List Of Internal Treatment:" << endl;
		exter.print_treat();
	}
};
class external_pa :public patient
{
protected:
	char accept;
	mylist_treat exter1;
	external_treatment ex_tr;
	void set_grad(char x) {};
public:
	external_pa() :
		patient()
	{
		accept = ' ';
	}
	external_pa(const external_pa & ex) :patient(ex)
	{
		this->accept = ex.accept;
		this->ex_tr = ex.ex_tr;
		this->exter1 = ex.exter1;
	}
	external_pa(mylist_treat t, int i, string na, string a, int d1, int m2, int y1, char c) :
		patient(i, na, a, d1, m2, y1)
	{
		c = accept = ' ';
		exter1 = t;
	}
	void read()
	{
		patient::read();
		node_treat *pp = new node_treat;
		pp->treat = &ex_tr;
		node_treat *add;
		ex_tr.read();
		node_treat n;
		n.treat = new external_treatment;
		*n.treat = ex_tr;
		node_treat *add1;
		external_treatment *ptr = new external_treatment(ex_tr);
		n.treat = ptr;
		add1 = exter1.search_treat(ex_tr.get_num_treat());
		if (add1 != NULL)
		{
			cout << "This Treat Already Found" << endl;
		}
		else
		{
			exter1.insert_treat(&n);
		}
		cout << "Enter (Y) If He Exit And (N) If not:";
		cin >> accept;
	}
	void read_ex_rec()
	{

		ex_tr.read();
		node_treat n;
		n.treat = new external_treatment;
		*n.treat = ex_tr;
		node_treat *add;
		external_treatment *ptr = new external_treatment(ex_tr);
		n.treat = ptr;
		add = exter1.search_treat(ex_tr.get_num_treat());
		if (add != NULL)
		{
			cout << "This Treat Already Found" << endl;
		}
		else
		{
			exter1.insert_treat(&n);
		}
	}
	void print()
	{
		patient::print();
		cout << " The List Of Internal Treatment:" << endl;
		exter1.print_treat();
		if (accept == 'y')
			cout << "\nHe/She Exit";
		else
			cout << "\nStill in the hospital\n";
		cout << "===================================================================" << endl;
	}
	void print_rec()
	{
		cout << " The List Of Internal Treatment:" << endl;
		exter1.print_treat();

	}
	void read_in_rec()
	{
		cout << "External Patient Have Not Internal Treatments Record.." << endl;
	}
	int get_rev_part()
	{
		return-1;
	}
};
struct node_pa
{
	patient *pa;
	node_pa * next;
	node_pa()
	{
		pa = NULL;
		next = NULL;
	}
	node_pa(internal_pa *ptr)
	{
		pa = ptr;
		next = NULL;
	}
	node_pa(external_pa *ptr1)
	{
		pa = ptr1;
		next = NULL;
	}
};
int num_patient = 0;
class mylist_pa
{
private:
	node_pa *first;
public:
	mylist_pa()
	{
		first = NULL;
	}
	void insert_pa(node_pa *pp)
	{
		node_pa *tmp;
		tmp = new node_pa;
		tmp->pa = pp->pa;
		tmp->next = NULL;

		if (first == NULL) {
			first = tmp;
		}
		else {
			if (tmp->pa->get_id() <= first->pa->get_id()) {
				tmp->next = first;
				first = tmp;
			}
			else {
				node_pa *cur = first;
				node_pa *prev = NULL;

				while (cur != NULL && cur->pa->get_id() < tmp->pa->get_id()) {
					prev = cur;
					cur = cur->next;
				}

				tmp->next = cur;
				prev->next = tmp;
			}
		}
	}
	void print_pa()
	{
		node_pa *tmp;
		tmp = first;
		int n = 0;
		if (tmp == NULL)
		{
			cout << "the list empty" << endl;
			return;
		}

		while (tmp != NULL) {
			tmp->pa->print();
			tmp = tmp->next;
		}
	}
	int del_pa(int value)
	{
		node_pa *tmp = new node_pa;
		node_pa *prev, *curr;
		if (value == first->pa->get_id())
		{
			tmp = first;
			first = first->next;
			delete tmp;
			return value;
		}
		else
		{
			prev = first;
			curr = first->next;
			while (curr != NULL && curr->pa->get_id() != value)
			{
				prev = curr;
				curr = curr->next;
				cout << "There is no patient with this id..." << endl;
			}
			if (curr != NULL)
			{
				tmp = curr;
				prev->next = curr->next;
				delete tmp;
				return  value;
			}
		}
		return 0;
	}
	node_pa *search(int searchNum)
	{
		node_pa* searchnumber = nullptr;
		node_pa *current = first;
		node_pa *temp = NULL;

		while (current != NULL && current->pa->get_id() != searchNum)
		{
			temp = current;
			current = current->next;
		}
		if (current != NULL)
		{
			searchnumber = current;
			cout << " FAUND :\n";
			return current;
		}
		else
			cout << "NOT FAUND" << endl;
		return NULL;
	}
	void search_date(int day, int month, int year, int day2, int month2, int year2)
	{
		node_pa *current = first;
		node_pa *temp = NULL;
		while (current != NULL)
		{
			if (year > current->pa->get_year() > year2 || month > current->pa->get_month() > month2 || day > current->pa->get_day() > day2)
			{
				temp = current;
				current = current->next;
			}
			if (year <= current->pa->get_year() <= year2 && month <= current->pa->get_month() <= month2 &&day <= current->pa->get_day() <= day2)
			{
				current->pa->print();
				num_patient++;
				current = current->next;
			}
		}
		if (current == NULL)
		{
			cout << "There is no patient during this period" << endl;
			return;
		}
	}
	void search_Num(int day, int month, int year, int day2, int month2, int year2, int part)
	{
		node_pa *current = first;
		node_pa *temp = NULL;
		num_patient = 0;
		if (current != NULL)
		{
			while (current != NULL && year >= current->pa->get_year() >= year2 || month >= current->pa->get_month() >= month2 || day >= current->pa->get_day() >= day2 || part != current->pa->get_rev_part())
			{
				temp = current;
				current = current->next;
			}

			while (current != NULL && year <= current->pa->get_year() <= year2 && month <= current->pa->get_month() <= month2 &&day <= current->pa->get_day() <= day2)
			{
				num_patient++;

				current = current->next;
			}
			cout << "Number Of Patient In This Pireod: " << num_patient << endl;
		}
		else
		{
			cout << "There is no patient during this period in this section" << endl;
			return;
		}
	}
	~mylist_pa()
	{
		node_pa *ptr;;

		for (ptr = first; first; ptr = first)
		{
			first = first->next;
			delete ptr;
		}
	}
};
mylist_pa patients;
struct nodedoctortry {
	doctor_tr be;
	nodedoctortry *next;

};
class list_doctor_try {
private:
	nodedoctortry *head;
public:
	list_doctor_try()
	{
		head = NULL;
	}
	void insert(doctor_tr dd)
	{
		nodedoctortry *temp;
		temp = new nodedoctortry;
		temp->be = dd;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		}
		else {
			if (temp->be.get_id() <= head->be.get_id()) {
				temp->next = head;
				head = temp;
			}
			else {
				nodedoctortry *cur = head;
				nodedoctortry *prev = NULL;
				while (cur != NULL && cur->be.get_id()< temp->be.get_id()) {
					prev = cur;
					cur = cur->next;
				}
				temp->next = cur;
				prev->next = temp;
			}
		}
	}
	nodedoctortry* search_doctor(int searchNum)
	{
		nodedoctortry* searchnumber = nullptr;
		nodedoctortry *current = head;
		nodedoctortry *temp = NULL;

		while (current != NULL && current->be.get_id() != searchNum)
		{
			temp = current;
			current = current->next;
		}
		if (current != NULL)
		{
			searchnumber = current;
			return current;
		}
		else
			return NULL;
	}
	int del(int value)
	{
		nodedoctortry *temp = new nodedoctortry;
		nodedoctortry *prev, *curr;
		if (value == head->be.get_id())
		{
			temp = head;
			head = head->next;
			delete temp;
			return value;
		}
		else
		{
			prev = head;
			curr = head->next;
			while (curr != NULL && curr->be.get_id() != value)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				temp = curr;
				prev->next = curr->next;
				delete temp;
				return  value;
			}
		}
		return 0;
	}
};
int main()
{
	int choise1; int choise2 = 0;
	doctor_in in;
	doctor_co co;
	doctor_tr tr;
	internal_pa in_pa;
	external_pa ex_pa;
	list_doctor_try sd;
st:
	while (true)
	{
		system("color 6");
		cout << "MENU" << endl;
		cout << "Press (1)  To add new Doctor" << endl;
		cout << "Press (2)  To add new patient" << endl;
		cout << "Press (3)  To Print Linked List Contain All Doctors In The Hospital..." << endl;
		cout << "Press (4)  To Print Linked List Contain All Patient In The Hospital And  Clinices..." << endl;
		cout << "Press (5)  To Delete A Doctor Record Using His ID" << endl;
		cout << "Press (6)  To Delete A Patient Record Using His ID" << endl;
		cout << "Press (7)  To Graduate A Patient From The Hospital" << endl;
		cout << "Press (8)  To Show All Treatment Of Any Patient Using His ID.." << endl;
		cout << "Press (9)  To Add New Treatment Record To A Patient Using His ID .." << endl;
		cout << "Press (10) To Print All Contracting Doctors .." << endl;
		cout << "Press (11) To Print All Patients During A Certain Period .." << endl;
		cout << "Press (12) To Print Number Of Patients In A Particular Section .." << endl;
		cout << "Press (13) To Exit" << endl;
		cout << "enter your choice:";
		cin >> choise1;
		system("cls");
		switch (choise1)
		{
		case 1:
		{
		start:
			cout << "Press (1) to add Permanent Doctor" << endl;
			cout << "Press (2) to add Training Doctor" << endl;
			cout << "Press (3) to add Contracting Doctor" << endl;
			cout << "enter your choice:";

			cin >> choise2;
			system("cls");
			switch (choise2)
			{
			case 1:
			{
				in.readname();
				in.readin();
				node n;
				n.doc = new doctor_in;
				*n.doc = in;
				node *add;
				doctor_in* ptr = new doctor_in(in);
				n.doc = ptr;
				add = doctors.search_doctor(in.get_id());
				if (add != NULL)
				{
					cout << "This Doctor Already Found" << endl;
				}
				else
				{
					doctors.insert(&n);
				}

				break;
			}
			case 2:
			{
				cout << "enter id doctor" << endl;
				int e;
				cin >> e;
				node *addt;
				nodedoctortry *ads;
				ads = sd.search_doctor(e);
				addt = doctors.search_doctor(e);
				if (addt != NULL)
				{
					int ac, ae, aw;
					cout << "enter currtual date" << endl;
					cin >> ac;
					int i = 0;
					i = ac - ads->be.get_yearw();
					if (i >= 3)
					{
						doctors.del(e);
						in.readin();
						in.set_name(ads->be.get_name());
						in.set_address(ads->be.get_address());
						in.set_id(ads->be.get_id());
						in.setdate(ads->be.get_date());
						node o;
						o.doc = new doctor_in;
						*o.doc = in;
						o.next = nullptr;
						doctors.insert(&o);
						cout << "This Doctor Already Found but comblet tranbort" << endl;
					}
				}
				else {
					tr.set_id(e);
					tr.readtry();
					sd.insert(tr);
					node f;
					f.doc = new doctor_tr;
					*f.doc = tr;
					f.next = nullptr;
					doctors.insert(&f);

				}
				break;
			}
			case 3:
			{
				co.read();
				node n;
				n.doc = new doctor_co;
				*n.doc = co;
				node *add;
				doctor_co* ptr = new doctor_co(co);
				n.doc = ptr;
				add = doctors.search_doctor(co.get_id());
				if (add != NULL)
				{
					cout << "This Doctor Already Found" << endl;
				}
				else
				{
					doctors.insert(&n);
				}
				break;
			}
			default:
			{
				cout << " You Have Entered An Invalid Value";
				goto start;
			}
			}
			break;
		}
		case 2:
		{
			cout << "Press (1) to add Patient In Hospital" << endl;
			cout << "Press (2) to add Patient In Clinic External" << endl;
			cout << "enter your choice:";
			cin >> choise2;
			system("cls");
			switch (choise2)
			{
			case 1:
			{
				in_pa.read();
				in_pa.read_in_rec();
				in_pa.read_ex_rec();
				node_pa n;
				n.pa = new internal_pa;
				*n.pa = in_pa;
				node_pa *add;
				internal_pa* ptr = new internal_pa(in_pa);
				n.pa = ptr;
				add = patients.search(in_pa.get_id());
				if (add != NULL)
				{
					cout << "This patient Already Found" << endl;
				}
				else
				{
					patients.insert_pa(&n);
				}
				break;
			}
			case 2:
			{
				ex_pa.read();
				node_pa n;
				n.pa = new external_pa;
				*n.pa = ex_pa;
				node_pa *add;
				external_pa* ptr = new external_pa(ex_pa);
				n.pa = ptr;
				add = patients.search(ex_pa.get_id());
				if (add != NULL)
				{
					cout << "This patient Already Found" << endl;
				}
				else
				{
					patients.insert_pa(&n);
				}
				break;
			}
			}
		}
		case 3:
		{
			doctors.print();
			break;
		}
		case 4:
		{
			patients.print_pa();
			break;
		}
		case 5:
		{
			int id;
			cout << "Enter The ID Of The Doctor To Delete Him :";
			cin >> id;
			doctors.del(id);
			break;
		}
		case 6:
		{
			int id;
			cout << "Enter The ID Of The Patient To Delete Him :";
			cin >> id;
			patients.del_pa(id);
			break;
		}
		case 7:
		{
			int id;
			cout << "Enter The ID Of The Patient To Graduate Him:" << endl;
			cin >> id;
			node_pa *n;
			n = patients.search(id);
			if (n != NULL)
			{
				n->pa->set_grad('y');
			}
			else
			{
				cout << "There is no patient with this id.." << endl;
			}
			break;
		}
		case 8:
		{

			int id;
			cout << "Enter The ID Of The Patient To Find Him:" << endl;
			cin >> id;
			node_pa *n;
			n = patients.search(id);
			n->pa->print_rec();
			break;
		}
		case 9:
		{
			int id, choi;
			cout << "Enter The ID Of The Patient To Add Treatment To Him:" << endl;
			cin >> id;
			node_pa *n;
			n = patients.search(id);
		rep:
			cout << "Press (1) To Add Internal Treatment To his Record \nPress (2) To Add External Treatment To His Record:" << endl;
			cin >> choi;
			if (choi == 1)
				n->pa->read_in_rec();
			else if (choi == 2)
				n->pa->read_ex_rec();
			else goto rep;
			break;
		}
		case 10:
		{
			doctors.search(3);
			break;
		}
		case 11:
		{
			int year1, month1, day1;
			int year2, month2, day2;
			cout << "Enter The First Date :";
			cin >> day1 >> month1 >> year1;
			cout << "Enter The Second Date :";
			cin >> day2 >> month2 >> year2;
			node_pa *n;
			patients.search_date(year1, month1, day1, year2, month2, day2);
			break;
		}
		case 12:
		{
			int rev;
		repd:
			cout << "enter (1) for Department of Ambulance\nenter (2) for Department of ophthalmology\nenter (3) for Department of chest\nenter (4) for General Surgery" << endl;
			cout << "Enter Rev Part:";
			cin >> rev;
			if (rev > 4)
				goto repd;
			int year1, month1, day1;
			int year2, month2, day2;
			cout << "Enter The First Date :";
			cin >> day1 >> month1 >> year1;
			cout << "Enter The Second Date :";
			cin >> day2 >> month2 >> year2;
			node_pa *n;
			patients.search_Num(year1, month1, day1, year2, month2, day2, rev);
			break;
		}
		case 13:
		{
			exit(-1);
		}
		default:
		{
			cout << "ERROR" << endl;
			goto st;
		}
		}
	}
	system("PAUSE");
}