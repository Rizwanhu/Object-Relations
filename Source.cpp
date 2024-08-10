#include <iostream>
using namespace std;

#include "CPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "storage.h"
#include "Computer.h"

#include "company.h"
#include "employee.h"




int main() {

	CPU uni("AMD","ryzen8",8.9,6);
	RAM fInu(16,9,"ASUS");
	Motherboard nami("radeon","SSD3",4);
	vector<string> drives;
	drives.push_back("C:");
	drives.push_back("D:");
	Storage str(drives, 520);
	Computer comp(uni, fInu, str, nami);
	cout << comp << endl;



	cout << endl << endl << endl;
	cout << "----------------------------------" << endl << endl;



	Employee km("sarfraz", 23140, "Computer Science", 180000);
	cout << km << endl;




	cout << endl << endl << endl;
	cout << "----------------------------------" << endl << endl;








	return 0;
}