#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#include "CDA.cpp"

template <typename Elmtype>
bool checkarray(CDA<Elmtype> a, vector<Elmtype> b)
{
	for (int i = 0; i < a.Length(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

void foo(CDA<int> X)
{
	for (int i = 0; i < X.Length() / 2; i++)
		X[i] = X[X.Length() / 2 + i];
	cout << "checkpoint 13 passed:" << boolalpha << checkarray(X, vector<int>{5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0, 5}) << " X => 5 4 3 2 1 0 5 4 3 2 1 0 5" << endl;
	// X => "5 4 3 2 1 0 5 4 3 2 1 0 5"	
	//for (int i = 0; i < x.Length(); i++) cout << x[i] << " ";  cout << endl;
}

int main()
{
	CDA<int> C(10); // changed to int instead of float
	for (int i = 0; i < C.Length(); i++) C[i] = i;
	//CHECKPOINT 1
	//for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	cout << "checkpoint 1 passed:" << boolalpha << checkarray(C, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) << " C => 0 1 2 3 4 5 6 7 8 9" << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.DelFront();
	//CHECKPOINT 2
	//for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	cout << "checkpoint 2 passed:" << boolalpha << checkarray(C, vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}) << " C => 1 2 3 4 5 6 7 8 9" << endl;
	// C => "1 2 3 4 5 6 7 8 9"
	C.DelEnd();
	//CHECKPOINT 3
	//for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	cout << "checkpoint 3 passed:" << boolalpha << checkarray(C, vector<int>{1, 2, 3, 4, 5, 6, 7, 8}) << " C => 1 2 3 4 5 6 7 8" << endl;
	// C => "1 2 3 4 5 6 7 8"
	C.AddEnd(100);
	//CHECKPOINT 4
	//for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	cout << "checkpoint 4 passed:" << boolalpha << checkarray(C, vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 100}) << " C => 1 2 3 4 5 6 7 8 100" << endl;
	// C => "1 2 3 4 5 6 7 8 100"
	C.AddEnd(101);
	C.Reverse();
	//CHECKPOINT 5
	//for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	cout << "checkpoint 5 passed:" << boolalpha << checkarray(C, vector<int>{101, 100, 8, 7, 6, 5, 4, 3, 2, 1}) << " C => 101 100 8 7 6 5 4 3 2 1" << endl;
	// C => "101 100 8 7 6 5 4 3 2 1"
	C.DelEnd();
	C.DelEnd();
	C.AddFront(-100);
	C.AddFront(-200);
	//CHECKPOINT 6
	//for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	cout << "checkpoint 6 passed:" << boolalpha << checkarray(C, vector<int>{-200, -100, 101, 100, 8, 7, 6, 5, 4, 3}) << " C => -200 -100 101 100 8 7 6 5 4 3" << 
		endl; // C => "-200 -100 101 100 8 7 6 5 4 3"

	CDA<int> A, B;
	for (int i = 0; i < 10; i++) A.AddEnd(i);
	B = A;
	A.AddEnd(15);
	A.AddEnd(19);
	//CHECKPOINT 7
	cout << "checkpoint 7 passed:" << boolalpha << checkarray(A, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19}) << " A => 0 1 2 3 4 5 6 7 8 9 15 19" <<
		endl; // A => "0 1 2 3 4 5 6 7 8 9 15 19" 
	//CHECKPOINT 7.1
	//cout << "Select is " << A.Select(3) << endl;
	cout << "checkpoint 7.1 passed:" << boolalpha << (checkarray(A, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19})
		&& A.Select(3) == 2) << " A => 0 1 2 3 4 5 6 7 8 9 15 19 Select => 2" << endl; // A => "0 1 2 3 4 5 6 7 8 9 15 19" Select => 2
	//CHECKPOINT 7.2
	//cout << "Select is " << A.Search(5) << endl;
	cout << "checkpoint 7.2 passed:" << boolalpha << (checkarray(A, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19})
		&& A.Search(5) == 5) << " A => 0 1 2 3 4 5 6 7 8 9 15 19 Search => 5" << endl; // A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 5
	//CHECKPOINT 7.3
	//cout << "Select is " << A.BinSearch(12) << endl;
	cout << "checkpoint 7.3 passed:" << boolalpha << (checkarray(A, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19})
		&& A.BinSearch(12) == -11) << " A => 0 1 2 3 4 5 6 7 8 9 15 19 Search => -11" << endl; // A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => -11
	//CHECKPOINT 8 
	A.AddFront(10);
	cout << "checkpoint 8 passed:" << boolalpha << checkarray(A, vector<int>{10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19}) << " A => 10 0 1 2 3 4 5 6 7 8 9 15 19"
		<< endl; // A => "10 0 1 2 3 4 5 6 7 8 9 15 19"
	//CHECKPOINT 8.1
	//cout << "Select is " << A.Select(3) << endl;
	cout << "checkpoint 8.1 passed:" << boolalpha << (checkarray(A, vector<int>{
		                                                             10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19
	                                                             }) && A.Select(3) == 2) << " A => 10 0 1 2 3 4 5 6 7 8 9 15 19 Select => 2" << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9 15 19" Select => 2
	//CHECKPOINT 8.2
	//cout << "Select is " << A.Search(5) << endl;
	cout << "checkpoint 8.1 passed:" << boolalpha << (checkarray(A, vector<int>{
		                                                             10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 19
	                                                             }) && A.Search(5) == 6) << " A => 10 0 1 2 3 4 5 6 7 8 9 15 19 Search => 6" << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9 15 19" Search => 6
	A.Sort();
	//CHECKPOINT 9
	cout << "checkpoint 9 passed:" << boolalpha << checkarray(A, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 19}) << " A => 0 1 2 3 4 5 6 7 8 9 10 15 19"
		<< endl; // A => "0 1 2 3 4 5 6 7 8 9 10 15 19"
	A.AddEnd(11);
	A.AddFront(1);
	A.AddFront(2);
	A.AddFront(3);
	//CHECKPOINT 10 
	//cout << "Capacity is " << A.Capacity() << endl;
	cout << "checkpoint 10 passed:" << boolalpha << (checkarray(A, vector<int>{
		                                                            3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 19,
		                                                            11
	                                                            }) && A.Capacity() == 32) << " A => 3 2 1 0 1 2 3 4 5 6 7 8 9 10 15 19 11 Capacity => 32" << endl;
	// A => "3 2 1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  Capacity => 32
	A.DelFront();
	A.DelFront();
	A.Reverse();
	A.DelEnd();
	//CHECKPOINT 11 
	cout << "checkpoint 11 passed:" << boolalpha << checkarray(A, vector<int>{
		                                                           11, 19, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
	                                                           }) << " A => 11 19 15 10 9 8 7 6 5 4 3 2 1 0" << endl; // A => "11 19 15 10 9 8 7 6 5 4 3 2 1 0"
	A.DelFront();
	A.DelFront();
	A.AddEnd(5);
	//CHECKPOINT 12
	cout << "checkpoint 12 passed:" << boolalpha << checkarray(A, vector<int>{15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 5}) << "  A => 15 10 9 8 7 6 5 4 3 2 1 0 5"
		<< endl; // A => "15 10 9 8 7 6 5 4 3 2 1 0 5"
	//for (int i = 0; i < A.Length(); i++) cout << A[i] << " ";  cout << endl;

	foo(A);
	//CHECKPOINT 14 
	//for (int i = 0; i < A.Length(); i++) cout << A[i] << " ";  cout << endl;
	cout << "checkpoint 14 passed:" << boolalpha << checkarray(A, vector<int>{15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 5}) << " A => 15 10 9 8 7 6 5 4 3 2 1 0 5"
		<< endl; // A => "15 10 9 8 7 6 5 4 3 2 1 0 5"
	//CHECKPOINT 15
	//for (int i = 0; i < B.Length(); i++) cout << B[i] << " ";  cout << endl;
	cout << "checkpoint 15 passed:" << boolalpha << checkarray(B, vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) << " B => 0 1 2 3 4 5 6 7 8 9" << endl;
	// B => "0 1 2 3 4 5 6 7 8 9"
}
